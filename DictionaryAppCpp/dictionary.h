/*Student Name : Eray Sahin
Student ID: 156387201
Student E-mail Address: esahin2@myseneca.ca
Date: 09-18-2022
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_DICTIONARY_H 
#define SDDS_DICTIONARY_H
namespace sdds
{
    struct word
    {
        char word[64];
        char wordDef[8][1000];
        char wordType[8][20];
        int noOfDef;
    };

    struct dictionary
    { 
        word wordList[100];
        int noOfWords;   
    };

    void SearchWord(const char* word);

    int LoadDictionary(const char* filename);

    void SaveDictionary(const char* filename);

    void NewWord(const char* word, const char* type, const char* definition);

    int UpdateDefinition(const char* word, const char* type, const char* definition);
}
#endif