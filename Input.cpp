//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "DataStruct.h"
#include "Input.h"


int input(TextInfo *FileData, FILE *Moytext)
{   
    assert(FileData);
    assert(Moytext);

    FileData->TextData = (char*) calloc(FileData->TextFileSize, sizeof(char));
    if (!FileData->TextData)
    {
        printf("pointer textdata failure");
        return 1;
    }

    size_t freadReturnValue = fread(FileData->TextData, sizeof(char), FileData->TextFileSize, Moytext);

    for(size_t i = 0; i < FileData->TextFileSize; i++)                
    {
        if(FileData->TextData[i] == '\n')
        {
            FileData->LinesCounter++;
        }
    }
                                                                                 //I know that the check for the match of the value fread and TextFileSize should be before reading the number of lines, but because of the \r in Windows it has to be done after
    if (FileData->TextFileSize != (freadReturnValue + FileData->LinesCounter))   //  + (FileData->LinesCounter) because of \r
    {
        printf("FileData->TextFileSize = %lu \n", FileData->TextFileSize);
        printf("freadReturnValue = %lu \n", (freadReturnValue + FileData->LinesCounter));         
        printf("fread value != TextFileSize");
        return 1;
    }

    FileData->LinesPointers = (char**) calloc(FileData->LinesCounter, sizeof(char*));
    if (!FileData->LinesPointers)
    {
        printf("pointer linespointers failure");
        return 1;
    }

    char* CurrentLinePointer = FileData->TextData;
    int CurrentTextDataNum = 0, CurrentElemInLineNumber = 0;

    for(size_t i = 0; i < FileData->LinesCounter; i++)                
    {   

        FileData->LinesPointers[i] = CurrentLinePointer;

        CurrentElemInLineNumber = 0;

        while(FileData->TextData[CurrentTextDataNum] != '\n' && FileData->TextData[CurrentTextDataNum])
        {
            CurrentTextDataNum++;
            CurrentElemInLineNumber++;

        }

        FileData->TextData[CurrentTextDataNum] = '\0';

        CurrentElemInLineNumber++;
        CurrentTextDataNum++;
        CurrentLinePointer = CurrentLinePointer + CurrentElemInLineNumber;       //BUG прибавляется вместе с предыдущим
        //printf("%d\n", CurrentNum);
    }

    return 0;
}