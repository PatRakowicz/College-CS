//
// Created by Rako on 1/27/24.
//

#ifndef HW3_MFILEIO_C_MFILE_H
#define HW3_MFILEIO_C_MFILE_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

typedef struct {
    int fd;
    char mode;
} mFILE;

mFILE *mfopen(const char *fileName, const char *mode);
int mfread(void *ptr, size_t size, size_t nitems, mFILE *fptr);
int mfwrite(void *ptr, size_t size, size_t nitems, mFILE *fptr);
int mfclose(mFILE *fptr);

#endif //HW3_MFILEIO_C_MFILE_H
