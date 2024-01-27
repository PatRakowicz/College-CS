#include "mfile.h"
#include <string.h>
#include <stdio.h>

int main() {
    // Test mfopen, mfwrite, mfclose
    mFILE *fptr = mfopen("test.txt", "w");
    if (fptr) {
        char *text = "Hello, world!";
        mfwrite(text, 1, strlen(text), fptr);
        mfclose(fptr);
    }

    // Test mfopen, mfread, mfclose
    fptr = mfopen("test.txt", "r");
    if (fptr) {
        char buffer[100];
        int bytes_read = mfread(buffer, 1, sizeof(buffer), fptr);
        if (bytes_read > 0) {
            write(1, buffer, bytes_read); // Write to stdout
        }
        mfclose(fptr);
    }

    // Test appending
    fptr = mfopen("test.txt", "a");
    if (fptr) {
        char *text = "\nAppend this!";
        mfwrite(text, 1, strlen(text), fptr);
        mfclose(fptr);
    }

    return 0;
}