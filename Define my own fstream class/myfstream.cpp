#include "myfstream.h"

void myfstream::openfile(const char* filename) {
    this->fileID = open(filename, O_RDWR | O_CREAT, S_IRWXU);
}

void myfstream::closefile() {
    close(this->fileID);
}

void myfstream::readfile(char* str, size_t strsize) {
    read(this->fileID, str, strsize);
    str += '\0';
}

void myfstream::writefile(const char* str, size_t strsize) {
    write(this->fileID, str, strsize);
}

istream& myfstream::operator>>(char* str) {
    for (int n = 0; *(str + n) != '\0'; n++)
        read(this->fileID, str + n, 1);
}

ostream& myfstream::operator<<(char* str) {
    for (int n = 0; *(str + n) != '\0'; n++)
        write(this->fileID, str + n, 1);
}
