#ifndef MFILE_H
#define MFILE_H

#include <stddef.h> // for size_t

typedef struct {
    int fd;         // File descriptor
    char mode;      // Mode in which the file was opened ('r', 'w', 'a')
} mFILE;

mFILE *mfopen(const char *fileName, const char *mode);
int mfread(void *ptr, size_t size, size_t nitems, mFILE *fptr);
int mfwrite(void *ptr, size_t size, size_t nitems, mFILE *fptr);
int mfclose(mFILE *fptr);

#endif