//
// Created by Rako on 2/02/2024.
//

#include "ArchiveUtility.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <utime.h>
#include <sys/stat.h>
#include <algorithm>

using namespace std;

void ArchiveUtility::archiveFiles(const vector <string> &filenames, const string &archiveName) {
	ofstream archiveFile(archiveName, ios::binary);
	if (!archiveFile) {
		cerr << "Error: Could not open archive file for writing: " << archiveName << endl;
		return;
	}

	for (const auto &filename: filenames) {
		ifstream inputFile(filename, ios::binary);
		if (!inputFile) {
			cerr << "Error: Could not read file: " << filename << endl;
			continue;
		}

		inputFile.seekg(0, ios::end);
		unsigned int filesize = inputFile.tellg();
		inputFile.seekg(0, ios::beg);

		struct stat fileStat;
		if (stat(filename.c_str(), &fileStat) != 0) {
			cerr << "Error: Could not get file info: " << filename << endl;
			inputFile.close();
			continue;
		}

		FileMetadata metadata;
		strncpy(metadata.filename, filename.c_str(), sizeof(metadata.filename) - 1);
		metadata.filename[sizeof(metadata.filename) - 1] = '\0';
		metadata.filesize = filesize;
		metadata.permissions = fileStat.st_mode;
		metadata.last_modified = fileStat.st_mtime;

		archiveFile.write(reinterpret_cast<const char *>(&metadata), sizeof(metadata));

		char buffer[1024];
		while (!inputFile.eof()) {
			inputFile.read(buffer, sizeof(buffer));
			archiveFile.write(buffer, inputFile.gcount());
		}
		cout << "Archiving " << filename << " (size " << metadata.filesize << " bytes)" << endl;

		inputFile.close();
	}

	archiveFile.close();
}

void ArchiveUtility::extractFiles(const string &archiveName) {
	ifstream archiveFile(archiveName, ios::binary);
	if (!archiveFile) {
		cerr << "Error: Could not open archive file for reading: " << archiveName << endl;
		return;
	}

	while (archiveFile.peek() != EOF) {
		FileMetadata metadata;
		archiveFile.read(reinterpret_cast<char *>(&metadata), sizeof(metadata));
		if (archiveFile.eof()) {
			break;
		}

		ofstream outputFile(metadata.filename, ios::binary);
		if (!outputFile) {
			cerr << "Error: Could not create file: " << metadata.filename << endl;
			archiveFile.seekg(metadata.filesize, ios::cur);
			continue;
		}

		char buffer[1024];
		unsigned int remaining = metadata.filesize;
		while (remaining > 0) {
			unsigned int toRead = std::min(static_cast<size_t>(remaining), sizeof(buffer));
			archiveFile.read(buffer, toRead);
			outputFile.write(buffer, toRead);
			remaining -= toRead;
		}

		outputFile.close();

		cout << "Extracting " << metadata.filename << " (size " << metadata.filesize << " bytes)" << endl;

		struct utimbuf new_times;
		new_times.actime = metadata.last_modified;
		new_times.modtime = metadata.last_modified;
		utime(metadata.filename, &new_times);

		chmod(metadata.filename, metadata.permissions);
	}

	archiveFile.close();
}
