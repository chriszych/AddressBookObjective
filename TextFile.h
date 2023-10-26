#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <fstream>

using namespace std;

class TextFile {

private:

    const string TEXT_FILE;

protected:

    bool isFileEmpty(fstream &textFile);

public:

    TextFile(string fileName) : TEXT_FILE(fileName) {};

    string getTextFile();
};
#endif
