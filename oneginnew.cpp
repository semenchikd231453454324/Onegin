#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "DataStruct.h"
#include "Input.h"
#include "output.h"
#include "sort.h"

#define TEXT_NAME "sdcsc sdc"

// TODO rename to main.cpp

int main()
{
    FILE *MoyText = fopen("MoyText.txt", "r");  // FIXME make define with text filename 
    if (!MoyText)
    {
        printf("pointer moytext failure");
        return 1;
    }

    struct stat FileInf = {};
    stat("MoyText.txt", &FileInf);
    
    struct TextInfo FileData = {};
    FileData.TextFileSize = FileInf.st_size;

    input(&FileData, MoyText);

    sort(&FileData);

    output(&FileData);

    // TODO fclose

}