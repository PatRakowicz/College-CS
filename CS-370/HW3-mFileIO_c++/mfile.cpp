//
// Created by Rako on 1/27/24.
//

#include "mfile.h"

mFILE *mfopen(const char *fileName, const char *mode) {
    mFILE *fptr = new mFILE;
    if (strcmp(mode, "r") == 0) {
        fptr->fd = open(fileName, O_RDONLY);
        fptr->mode = 'r';
    } else if (strcmp(mode, "w") == 0) {
        fptr->fd = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        fptr->mode = 'w';
    } else if (strcmp(mode, "a") == 0) {
        fptr->fd = open(fileName, O_WRONLY | O_CREAT | O_APPEND, 0644);
        fptr->mode = 'a';
    } else {
        delete fptr;
        return NULL;
    }

    if (fptr->fd == -1) {
        delete fptr;
        return NULL;
    }

    return fptr;
}

int mfread(void *ptr, size_t size, size_t nitems, mFILE *fptr) {
    if (fptr->mode != 'r') {
        return -1;
    }

    return read(fptr->fd, ptr, size * nitems);
}

int mfwrite(void *ptr, size_t size, size_t nitems, mFILE *fptr) {
    if (fptr->mode != 'w' && fptr->mode != 'a') {
        return -1;
    }

    return write(fptr->fd, ptr, size * nitems);
}

int mfclose(mFILE *fptr) {
    int status = close(fptr->fd);
    delete fptr;
    return status;
}

