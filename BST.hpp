using namespace std;

#include <iostream>
#include <fstream>
#include <string>  
#ifndef DEFNS
#define DEFNS
#include "defns.h"
#endif

class BST
{
    public:
        BST();
        void buildBST(string filename, bst * root, hash_table_entry ** hashTable);
        void inOrderTrav(bst ** root, string start, string end);
        void printBT(const std::string& prefix, bst ** root, bool isLeft);
        

    private:
        
        
        void insertBST(bst ** root, bst * node);
};