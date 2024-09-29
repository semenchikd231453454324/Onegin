//#include <TXLib.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "sort.h"
#include "DataStruct.h"

int sort(TextInfo *FileData)
{
    assert(FileData);

    char* TemporaryCellForStoringPointer = 0;
    int SwapCounter = 0;

    for(int i = 0; i < FileData->LinesCounter; i++)
    {
        for(int j = 0; j < (FileData->LinesCounter - 1); j++)
        {
            SwapCounter = 0;

            switch (strcmp(FileData->LinesPointers[j], FileData->LinesPointers[j + 1]) )
            {
            case 1:
                TemporaryCellForStoringPointer = FileData->LinesPointers[j];
                FileData->LinesPointers[j] = FileData->LinesPointers[j + 1];
                FileData->LinesPointers[j + 1] = TemporaryCellForStoringPointer;
                SwapCounter++;
                break;
            
            default:
                break;
            }
        }

        if(!SwapCounter)
        {
            return 0;
        }
    }
}