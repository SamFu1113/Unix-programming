#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
using namespace std;

class myfstream {
   public:
    size_t fileID;
    void openfile(const char* filename);
    void closefile();
    void readfile(char* str, size_t strsize);
    void writefile(const char* str, size_t strsize);
    istream& operator>>(char* str);
    ostream& operator<<(char* str);
};
