//
// Created by Rako on 2/03/2024.
//

#include <iostream>
#include <vector>
#include "FileMetadata.h"
#include "ArchiveUtility.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << "Usage: " << argv[0] << " -a|-x archive.mtar [file1 file2 ...]" << endl;
		return 1;
	}

	string option = argv[1];
	string archiveName = argv[2];
	ArchiveUtility utility;

	if (option == "-a") {
		if (argc < 4) {
			cerr << "Usage: " << argv[0] << " -a archive.mtar file1 [file2 ...]" << endl;
			return 1;
		}
		vector<string> filenames(argv + 3, argv + argc);
		utility.archiveFiles(filenames, archiveName);
	} else if (option == "-x") {
		if (argc != 3) {
			cerr << "Usage: " << argv[0] << " -x archive.mtar" << endl;
			return 1;
		}
		utility.extractFiles(archiveName);
	} else {
		cerr << "Invalid option: " << option << endl;
		cerr << "Usage: " << argv[0] << " -a|-x archive.mtar [file1 file2 ...]" << endl;
		return 1;
	}

	return 0;
}
