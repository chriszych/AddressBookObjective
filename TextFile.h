#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <fstream>

using namespace std;

class TextFile {

protected:

    const string TEXT_FILE;

    bool isFileEmpty(fstream &textFile);

public:

    TextFile(string fileName) : TEXT_FILE(fileName) {};
};

#endif
