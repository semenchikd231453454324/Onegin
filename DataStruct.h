#ifndef DataStruct_H
#define DataStruct_H

#include <stdlib.h>

struct TextInfo
{
    char* TextData;
    char** LinesPointers;
    size_t LinesCounter;
    size_t TextFileSize;
};

#endif