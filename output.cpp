//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>
#include "DataStruct.h"
#include "output.h"

int output(TextInfo *FileData)
{
    assert(FileData);

    for(size_t CurrentLineNumber = 0; CurrentLineNumber < FileData->LinesCounter; CurrentLineNumber++)
    {
        printf("%s", FileData->LinesPointers[CurrentLineNumber]);
        printf("\n");
    }

    return 0;
}