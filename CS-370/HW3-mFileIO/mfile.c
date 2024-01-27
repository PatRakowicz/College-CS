#include "mfile.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

mFILE *mfopen(const char *fileName, const char *mode) {
	mFILE *fptr = (mFILE *) malloc(sizeof(mFILE));
	if (!fptr) return NULL;

	int flags = 0;
	// Set flags based on mode
	if (strcmp(mode, "r") == 0) flags = O_RDONLY;
	else if (strcmp(mode, "w") == 0) flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (strcmp(mode, "a") == 0) flags = O_WRONLY | O_CREAT | O_APPEND;
	else {
		free(fptr);
		return NULL;
	}

	int fd = open(fileName, flags, 0644);
	if (fd == -1) {
		free(fptr);
		return NULL;
	}

	fptr->fd = fd;
	fptr->mode = mode[0];
	return fptr;
}

int mfread(void *ptr, size_t size, size_t nitems, mFILE *fptr) {
	if (!fptr || fptr->mode == 'w' || fptr->mode == 'a') {
		return -1; // Error: file is not open for reading
	}

	ssize_t bytesRead = read(fptr->fd, ptr, size * nitems);
	return bytesRead > 0 ? bytesRead / size : -1;
}

int mfwrite(void *ptr, size_t size, size_t nitems, mFILE *fptr) {
	if (!fptr || fptr->mode == 'r') {
		return -1; // Error: file is not open for writing
	}

	ssize_t bytesWritten = write(fptr->fd, ptr, size * nitems);
	return bytesWritten > 0 ? bytesWritten / size : -1;
}

int mfclose(mFILE *fptr) {
	if (!fptr) return -1;
	int status = close(fptr->fd);
	free(fptr);
	return status;
}