#include "myfstream.h"

int main() {
    string ofileStr, ifileStr;
    myfstream ifile, ofile;
    char data[50];
    int inNumber = 0;

    cout << "Please enter input file name:";
    cin >> ifileStr;
    cout << "Please enter output file name:";
    cin >> ofileStr;
    ifileStr += ".txt";
    ofileStr += ".txt";

    char ofileName[ofileStr.length()];
    strcpy(ofileName, ofileStr.c_str());
    char ifileName[ifileStr.length()];
    strcpy(ifileName, ifileStr.c_str());

    ifile.openfile(ifileName);
    ofile.openfile(ofileName);

    ifile.readfile(data, 15);
    data[15] = ' ';
    //ifile >> data;
    ofile << data;

    ifile.closefile();
    ofile.closefile();

    return 0;
}
