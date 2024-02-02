//
// Created by Rako on 2/01/2024.
//

#ifndef HW4_MTAR_FILEMETADATA_H
#define HW4_MTAR_FILEMETADATA_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct FileMetadata {
	char filename[100];    // Filename: Assumed max length is 100 characters
	unsigned int filesize; // Size of the file
	mode_t permissions;    // File permissions
	time_t last_modified;  // Last modified timestamp

	// Default constructor
	FileMetadata() : filesize(0), permissions(0), last_modified(0) {
		filename[0] = '\0'; // Ensure filename is initially empty
	}
};

#endif //HW4_MTAR_FILEMETADATA_H
