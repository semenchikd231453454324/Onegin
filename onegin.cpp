//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>
#include "DataStruct.h"



int main()
{
    FILE *MoyText = fopen("MoyText.txt", "r");
    assert(MoyText);

    size_t FileSize;
    struct stat FileInf = {};

    TextInfo *LinesNumber;

    LinesNumber->LinesCounter = 0;

    printf("%d", LinesNumber);
   
    stat("MoyText.txt", &FileInf);

    FileSize = FileInf.st_size;    

    char* TextData = (char*) calloc(FileSize, sizeof(char));
    
    fread(TextData, sizeof(char), FileSize, MoyText);

    int LinesCounter = 0;

    for(size_t i = 0; i < FileSize; i++)                //TODO 1.Буфер, массив указателей, файл сайз, кол во строк в структуру, в структуру просто хуйнуть указатель на буфер, filesize узнаем freadom и тоже его в структуру
                                                        //TODO 2.Разбить на инпут и аутпут
                                                        //TODO 3.Все ифы на каллоки
                                                        //TODO 4.Скрипт сборки
                                                        //TODO 5.
    {
        if(TextData[i] == '\n')
        {
            LinesCounter++;
        }
    }

    //printf("%d", LinesCounter);

    int* LineLengths = (int*) calloc(LinesCounter, sizeof(int));

    int LineNum = 0, CurrentLineSize = 0;

    for(size_t i = 0; i < FileSize-1; i++)
    {
        CurrentLineSize = 0;
        //printf("HUI");
        while(TextData[i] != '\n' && TextData[i])
        {
            i++;
            CurrentLineSize++;
        }

        LineLengths[LineNum] = CurrentLineSize;
        LineNum++;
    }
    
    

    //for(int i = 0; i < LinesCounter; i++)
    //{
    //     printf("%d\n", LineLengths[i]);                //TODO 1. Массивы буфер + указатели  каллоки в мэйн + количсетво строк(мб в инпуте мб в отдельной функции)
    //}                                                   //TODO 2. Cравнить строки через strcmp(библиотека string.h), сделав свою функцию my_strcmp, в которой будет strcmp, чтоб потом заменять было легч. strcmp -1 0 1. менять указатели строк. поочередно пробежаться пузыртком(пояснения в телефоне). передать указатели
                                                        //TODO 3. Сделать вывод(%s принимает указатель на строчку и выводит строку целиком)
    
    /*char** LinesPointers = (char**) calloc (LinesCounter, sizeof(char*));

    char* PointerSum = TextData;
    for(int i = 0; i < LinesCounter; i++)
    {
        LinesPointers[i] = PointerSum;
        PointerSum = PointerSum + LineLengths[i];
    }
    */
    //sort(TextData, LinesPointers, LinesCounter);


//printf("%d\n", TextData[5]);
//printf("%d\n", TextData[6]);          
//printf("%d", TextData[7]);

//for(size_t i = 0; i < FileSize; i++)
//{
//    printf("%c", TextData[i]);
//}
//printf("%d", FileSize);

}

/*long size_onegin(FILE* MoyText)
{
    if (!MoyText)
    {
        return -1;
    }
    fseek(MoyText, 0, SEEK_END);
    long size_oneg = ftell(MoyText);
    fseek(MoyText, 0, SEEK_SET);
    return size_oneg;
}
*/

