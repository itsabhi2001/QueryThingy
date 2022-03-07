using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cstring> 
#include "Utility.hpp"
#include <locale>


    Utility::Utility(){}

    string Utility::addCommas(int input){
        string s = std::to_string(input);
        int n = s.length() - 3;
        int end = (input >= 0) ? 0 : 1;
        while (n > end) {
            s.insert(n, ",");
            n -= 3;
        }
        return s;
    }
