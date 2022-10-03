/***************************************
Student Name: Eray Sahin
Student E-mail: esahin2@myseneca.ca
Student ID: 156387201
Date: 09/15/2022
I have done all the coding by myselfand only copied the code that
my professor provided to complete my workshops and assignments.
**************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "File.h"
#include "ShoppingRec.h"

// set to false when compling on Linux
const bool APP_OS_WINDOWS = true;

using namespace std;


namespace sdds
{

    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
    FILE* sfptr = nullptr;

    bool openFileForRead() {
        sfptr = fopen(SHOPPING_DATA_FILE, "r");
        return sfptr != NULL;
    }

    bool openFileForOverwrite() {
        sfptr = fopen(SHOPPING_DATA_FILE, "w");
        return sfptr != NULL;
    }

    void closeFile() {
        if (sfptr) fclose(sfptr);
    }

    bool freadShoppingRec(ShoppingRec* rec) {
        int flag = 0;
        bool success = fscanf(sfptr, "%[^,],%d,%d\n",
            rec->m_title, &rec->m_quantity, &flag) == 3;
        rec->m_bought = !!flag;
        return success;
    }

    void fwriteShoppintRec(const ShoppingRec* rec) {
        fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
    }

    namespace sdds {
        FILE* sfptr = nullptr;
        const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
        bool openFileForRead() {
            sfptr = fopen(SHOPPING_DATA_FILE, "r");
            return sfptr != NULL;
        }

        bool openFileForOverwrite() {
            sfptr = fopen(SHOPPING_DATA_FILE, "w");
            return sfptr != NULL;
        }

        void closeFile() {
            if (sfptr) fclose(sfptr);
        }

        bool freadShoppingRec(ShoppingRec* rec) {
            int flag = 0;
            bool success = fscanf(sfptr, "%[^,],%d,%d\n",
                rec->m_title, &rec->m_quantity, &flag) == 3;
            rec->m_bought = !!flag;
            return success;
        }

        void fwriteShoppintRec(const ShoppingRec* rec) {
            fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
        }

    }
}
