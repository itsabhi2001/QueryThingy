using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>  
#include "maxHeap.hpp"
#include "Utility.hpp"
#include "BST.hpp"
#include "hashTable.hpp"




int main(int argc, char *argv[])
{
    Utility utility;
    hashTable hashTab;
    BST searchTree;
    string fileName = "Occupation-Dist-All-" + (string)argv[1] + ".csv";//create filename from cmd line
    
    
    earnings *data = (earnings*)malloc(60*sizeof(earnings));
    
    int hashSize = NUM_OCC * 3;
    while(!(hashTab.isPrime(hashSize))){
        hashSize++;
    }
    hash_table_entry ** hashTable = (hash_table_entry**)malloc(hashSize);
    

    utility.buildArray(data);
    
    bst * root = nullptr;
    
    searchTree.buildBST(fileName, root, hashTable);
    
    //searchTree.printBT("",&root,false);

    //std::cout << root->soc.SOC_code << " " << root->left->soc.SOC_code << " " << root->right->soc.SOC_code << "\n";

    
    //std::cout << index << "\t" << "|" << data[index].year << "|" << "\t" << "|" << data[index].male_earnings << "|" << "\t" << "|" << data[index].female_earnings << "|" << "\n";
    
    int yearPassed =stoi((string)argv[1]);//tkae cmd line for the year being used
    
    int q;
    std::cin >> q;//# of queries
    string query;
    string command;
    for(int i = 0; i < q; i++)
    {//iterate through queries
        cin >> command >> query;
        if(query == "max")
        {//maxHeap
            string modifier;
            int n;
            cin >> modifier >> n;
            maxHeap mh;
            mh.findMax(fileName, modifier, n, yearPassed);
            
        }
        else if(query == "ratio")
        {//ratio
            if(i > 0)
            {
                std::cout << endl;//if first query dont add \n, else do add \n
            }
            int year1, year2;
            cin >> year1 >> year2;
           
            std::cout << "Query: find ratio " << year1 << " " << year2 << "\n\n";
            std::cout << "The female-to-male earnings ratio for " << year1 << "-" << year2 <<":\n";
            
            for(int i = (2019-year1); i >= (2019-year2); i--)
            {
                double male = (double)data[i].male_earnings;//convert to double
                double female = (double)data[i].female_earnings;
                double percentage = (female/male)*100 - 0.05;//round down percentage
                std::cout << "\t" << (2019 - i) << ": ";
                std::cout << std::setprecision(1) << std::fixed;//1 decimal pt
                std::cout << percentage;
                std::cout << "%\n";
            }
            
            

        }
        else if(query =="occupation"){
            if(command == "find"){

            }
            else if(command == "range"){
                string start, end;
                cin >> start >> end;
                std::cout << "Query: range occupation " << start << " " << end << "\n\n";
                std::cout << "The occupations in the range " << start << " to " << end <<":\n";
                start = start.substr(1,2);
                end = end.substr(1,2);
                searchTree.inOrderTrav(&root, start, end);
            }
            else{
                std::cout << "Query failed.\n";
            }
        }
        else{
            std::cout << "Query failed.\n";
        }
        
    }
    return 0;
}       