using namespace std;

#include <iostream>
#include <fstream>
#include <string>  
#ifndef DEFNS
#define DEFNS
#include "defns.h"
#endif


class Utility{
    public:
        Utility();
        string addCommas(int input);
        void buildArray(earnings *data);
        void OccupationToSOC(string filename, SOC * data);
        
        
};