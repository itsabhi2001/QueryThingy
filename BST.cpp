using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cstring> 
#include "BST.hpp"
#include "Utility.hpp"

BST::BST(){}
int left = 0;
int right = 0;
void BST::buildBST(string filename, bst * root, hash_table_entry ** hashTable){
    
    Utility ut;
    SOC *data = (SOC*)malloc(NUM_OCC*sizeof(SOC));
    ut.OccupationToSOC(filename, data);
    bst * node = new bst();
    node->soc = data[0];
    //std::cerr << node->soc.occupation << endl;
    insertBST(&root, node);
    int count = 0;
    for(int i = 1; i < NUM_OCC; i++)
    {
        //std::cout << data[i].SOC_code << endl;
        bst * node1 = new bst();
        node1->soc = data[i];
        //std::cerr << node1.soc.occupation << endl;
        insertBST(&root,node1);
        count++;
    }
    
    //printBT("",&root,false);

}

void BST::printBT(const std::string& prefix, bst ** root, bool isLeft)
{
    if( *root != nullptr )
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__" );

        // print the value of the node
        std::cout << ((*root)->soc.occupation) << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), &((*root)->left), true);
        printBT( prefix + (isLeft ? "|   " : "    "), &((*root)->right), false);

    }
}

void BST::insertBST(bst ** root, bst * node){
        if(*root == nullptr){
            (*root) = node;

            

            return;   
        }
        //std::cerr << (*root)->soc.occupation << endl;
        //std::cerr << (*node).soc.occupation << endl;
        if(strcmp(node->soc.occupation, (*root)->soc.occupation) < 0){
            //std::cerr << node->soc.occupation << endl;
            insertBST(&((*root)->left), node);
        }
        else{
            insertBST(&((*root)->right), node);
        }
    
}

void BST::inOrderTrav(bst ** root, string start, string end)
{
        Utility utility;
        std::cout << "hi" << endl;
        //std::cout << (strcmp( start.c_str(), (*root)->soc.occupation)) << endl;
        if(*root == nullptr) {
            return;
        }
        
        inOrderTrav(&((*root)->left), start, end);
        if  ((strcmp( start.c_str(), (*root)->soc.occupation)) < 0){
            if (((strcmp( end.c_str(), (*root)->soc.occupation)) > 0)){
                std::cout << (*root)->soc.occupation << endl;
            }
        }
        inOrderTrav(&((*root)->right), start, end);
}