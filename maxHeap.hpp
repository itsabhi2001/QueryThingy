using namespace std;

#include <iostream>
#include <fstream>
#include <string>  
#include "defns.h" 

class maxHeap
{
    public:
        maxHeap();
        void findMax(string filename, string modifier, int n, int year);

    private:
        void deleteRoot(SOC * arr, int& n, int modifier);
        void buildHeap(SOC * arr, int n, int modifier);
        void heapify(SOC * arr , int n, int i, int modifier);
};