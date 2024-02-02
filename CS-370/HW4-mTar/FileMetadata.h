//
// Created by Rako on 2/01/2024.
//

#ifndef HW4_MTAR_FILEMETADATA_H
#define HW4_MTAR_FILEMETADATA_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct FileMetadata {
	char filename[100];
	unsigned int filesize;
	mode_t permissions;
	time_t last_modified;

	// Default constructor
	FileMetadata() : filesize(0), permissions(0), last_modified(0) {
		filename[0] = '\0';
	}
};

#endif //HW4_MTAR_FILEMETADATA_H
