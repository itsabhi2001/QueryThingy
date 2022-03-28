using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cstring> 
#include "hashTable.hpp"
#include "Utility.hpp"

hashTable::hashTable(){}

void hashTable::hashInsert(hash_table_entry ** input, hash_table_entry entry){
    string socString;
    socString[0] = entry.SOC_code[0];
    socString[1] = entry.SOC_code[1];
    for (int i = 2; i < 6; i++){
        socString[i] = entry.SOC_code[i+1];
    }
    int socCode = stoi(socString);
    int i = NUM_OCC * 3;
    while(!(isPrime(i))){
        i++;
    }

    int p = socCode % i;
    input[p] = &entry;
}
bool hashTable::isPrime(int n)
{
    if (n <= 1){
        return false;
    }
    if (n <= 3){
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6){
        if (n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}