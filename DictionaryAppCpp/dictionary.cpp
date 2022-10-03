/*Student Name : Eray Sahin
Student ID: 156387201
Student E-mail Address: esahin2@myseneca.ca
Date: 09-18-2022
I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "word.h"
#include "dictionary.h"

using namespace std;

namespace sdds
{
	//use fgets
	char newline = '\n';
	char* nl = &newline;
	//putchar***
	dictionary newDictionary;

	int LoadDictionary(const char* filename)
	{
		dictionary dic = { 0 , 0 };
		int defCounter;
		int wordCounter = 0;
		FILE* dictionaryFile = NULL;
		dictionaryFile = fopen(filename, "r");
		char getWord[64];
		char getDef[1000];
		if (dictionaryFile != NULL)
		{
			while (fgets(getWord, 64, dictionaryFile) != NULL)
			{
				int i = 0;
				int wordFound = 0;
				int defFound = 0;
				defCounter = 0;
				while (wordFound == 0)
				{
					if (getWord[i] == newline)
					{
						wordFound = 1;
						getWord[i] = '\0';
					}
					i++;
				}
				strcpy(dic.wordList[wordCounter].word, getWord);
				i = 0;
				do
				{
					int eof = 0; 
					char definition[64] = { 0 };
					char definition2[64] = { 0 };
					if (fgets(getDef, 1000, dictionaryFile) == NULL)
					{
						eof = 1;
					}
					if (getDef[0] == '\n' || eof == 1)
					{
						defFound = 1;
					}
					else
					{
						defCounter++;
						char* REPLACE = strchr(getDef, ':');
						strcpy(dic.wordList[wordCounter].wordDef[defCounter],
							(REPLACE + 2));
						strncpy(definition, getDef,
							int(REPLACE - getDef));
						int a = 0;
						int flag = 0;						
						int b = 0;
						do
						{
							if (definition[a] != '\t')
							{
								definition2[b] = definition[a];
								b++;
							}
							a++;
							if (definition[a] == '\0')
							{
								flag = 1;
							}
						} while (flag == 0);
						strcpy(dic.wordList[wordCounter].wordType[defCounter], definition2);
					}
				} while (defFound == 0);
				dic.wordList[wordCounter].noOfDef = defCounter;
				dic.noOfWords = wordCounter;
				wordCounter++;
			}
			fclose(dictionaryFile);
			newDictionary = dic;
			return 0;
		}
		newDictionary = dic;
		return 1;
	}
	void SearchWord(const char* word)
	{
		int isSearching = 0;
		int i = 0;
		do
		{
			if (strcmp(newDictionary.wordList[i].word, word) == 0)
			{
				cout << "FOUND: [" << word << "] has [" <<
					newDictionary.wordList[i].noOfDef << "] definitions:\n";
				int count = 1;
				for (int a = 1; a <= newDictionary.wordList[i].noOfDef; a++)
				{
					cout << count << ". {" << newDictionary.wordList[i].wordType[a]
						<< "} " << newDictionary.wordList[i].wordDef[a];
					count++;
				}
				isSearching = 1;
			}
			else if (i == newDictionary.noOfWords)
			{
				cout << "NOT FOUND: word [" << word << "] is not in the dictionary.\n";
				isSearching = 1;
			}
			i++;
		} while (isSearching == 0);
	}
	void SaveDictionary(const char* filename)
	{
		FILE* dictionaryFile = NULL;
		dictionaryFile = fopen(filename, "w");
		int totalWords = newDictionary.noOfWords;
		int totalDef;
		for (int i = 0; i < totalWords; i++)
		{
			fputs(newDictionary.wordList[i].word,
				dictionaryFile);
			fputc('\n', dictionaryFile);
			totalDef = newDictionary.wordList[i].noOfDef;
			for (int a = 1; a <= totalDef; a++)
			{
				fputc('\t', dictionaryFile);
				fputs(newDictionary.wordList[i].wordType[a],
					dictionaryFile);

				fputc(':', dictionaryFile);
				fputc(' ', dictionaryFile);
				

				fputs(newDictionary.wordList[i].wordDef[a],
					dictionaryFile);
			}


			fputc('\n', dictionaryFile);
		}
		fclose(dictionaryFile);
	}
	void NewWord(const char* word, const char* type, const char* definition)
	{
		int isSearching = 0;
		int i = 0;
		int pos;
		do
		{
			if (strcmp(newDictionary.wordList[i].word, word) == 0)
			{
				newDictionary.wordList[i].noOfDef++;
				pos = newDictionary.wordList[i].noOfDef;
				strcpy(newDictionary.wordList[i].wordType[pos],
					type);
				strcpy(newDictionary.wordList[i].wordDef[pos],
					definition);
				strcat(newDictionary.wordList[i].wordDef[pos],
					nl);
				isSearching = 1;
			}
			if (i == newDictionary.noOfWords)
			{
				i++;
				newDictionary.noOfWords++;
				newDictionary.wordList[i].noOfDef = 1;
				strcpy(newDictionary.wordList[i].word,
					word);
				strcpy(newDictionary.wordList[i].wordType[1],
					type);
				strcpy(newDictionary.wordList[i].wordDef[1],
					definition);
				strcat(newDictionary.wordList[i].wordDef[1],
					nl);
				isSearching = 1;
			}
			i++;
		} while (isSearching == 0);
	}
	int UpdateDefinition(const char* word, const char* type, const char* definition)
	{
		int isSearching = 0;
		int i = 0;
		int a = 1;
		do
		{
			if (i == newDictionary.noOfWords)
			{
				isSearching = 1;
			}
			if (strcmp(newDictionary.wordList[i].word, word) == 0)
			{
				if (newDictionary.wordList[i].noOfDef > a)
				{
					cout << "The word [" << word << "] has multiple definitions:\n";
					int count = 1;
					for (int b = 1; b <= newDictionary.wordList[i].noOfDef; b++)
					{
						cout << count << ". {" <<
						newDictionary.wordList[i].wordType[b] << "} " <<
						newDictionary.wordList[i].wordDef[b];
						count++;
					}
					int input;
					cout << "Which one to update? ";
					cin >> input;
					strcpy(newDictionary.wordList[i].wordType[input],
						type);
					strcpy(newDictionary.wordList[i].wordDef[input],
						definition);
					strcat(newDictionary.wordList[i].wordDef[input],
						nl);
				}
				isSearching = 1;
			}
			i++;
		} while (isSearching == 0);
		return 0;
	}
}