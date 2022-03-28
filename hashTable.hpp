using namespace std;

#include <iostream>
#include <fstream>
#include <string>  
#ifndef DEFNS
#define DEFNS
#include "defns.h"
#endif

class hashTable
{
    public:
        hashTable();
        void hashInsert(hash_table_entry ** input, hash_table_entry entry);
        bool isPrime(int n);
};