using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <cstring> 
#include "maxHeap.hpp"
#include "Utility.hpp"

    maxHeap::maxHeap(){}


    void maxHeap::findMax(string filename, string modifier, int n, int year)
    {
        
        ifstream input_file;
        input_file.open(filename);
        SOC *data = (SOC*)malloc(NUM_OCC*sizeof(SOC));
        for(int i = 0; i < 5; i++)
        {
            string buffer;
            getline(input_file, buffer);
        }


        int index = 0;
        string line,temp;
        while(!input_file.eof())
        {
            string imput;
            string element;
            std::stringstream ss;
            getline(input_file,imput);
            ss << imput;
            for(int i = 0; i < 5; i++){
                if(ss.peek() == '"')
                {
                    ss >> std::quoted(element);
                    string comma;
                    getline(ss, comma, ',');
                }
                else
                {
                    getline(ss, element, ',');
                }
                
                switch (i) {
                    case 0:
                        strcpy(data[index].occupation, element.c_str());
                        break;
                    case 1:
                        strcpy(data[index].SOC_code, element.c_str());
                        break;
                    case 2:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].total = stoi(element);
                        break;
                    case 3:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].female = stoi(element);
                        break;
                    case 4:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].male = stoi(element);
                        break;
                }
            }
            
            index++;
            
        }
        
        int size = NUM_OCC;
        Utility ut;
        if(modifier == "total"){

            std::cout << "\n" << "Query: find max total " << n << "\n\n";
            std::cout << "Top " << n << " occupations in " << year << " for total workers:\n";

            buildHeap(data, NUM_OCC, 0);
            for(int i = 0; i < n; i++){
                std::cout << "\t" << data[0].occupation << ": " << ut.addCommas(data[0].total) << "\n";
                deleteRoot(data, size, 0);
            }
        }
        if(modifier == "female"){

            std::cout << "\n" << "Query: find max women " << n << "\n\n";
            std::cout << "Top " << n << " occupations in " << year << " for female workers:\n";

            buildHeap(data, NUM_OCC, 1);
            for(int i = 0; i < n; i++){
                std::cout << "\t" << data[0].occupation << ": " << ut.addCommas(data[0].female) << "\n";
                deleteRoot(data, size, 1);
            }
        }
        if(modifier == "male"){

            std::cout << "\n" << "Query: find max men " << n << "\n\n";
            std::cout << "Top " << n << " occupations in " << year << " for male workers:\n";

            buildHeap(data, NUM_OCC, 2);
            for(int i = 0; i < n; i++){
                std::cout << "\t" << data[0].occupation << ": " << ut.addCommas(data[0].male) << "\n";
                deleteRoot(data, size, 2);
            }
        }
        
        
        
    }
    
        
    void maxHeap::deleteRoot(SOC * arr, int& n, int modifier)
    {    
        SOC lastData = arr[n - 1];   
        arr[0] = lastData;    
        n = n - 1;
        heapify(arr, n, 0, modifier);
    }
    
 


    
    void maxHeap::heapify(SOC * arr , int n, int i, int modifier)
    {
        int largest = i; 
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 
        if(modifier == 0){
            
            if (l < n && arr[l].total > arr[largest].total)
                largest = l;
        
            
            if (r < n && arr[r].total > arr[largest].total)
                largest = r;
        
            
            if (largest != i) {
                swap(arr[i], arr[largest]);
        
                
                heapify(arr, n, largest, 0);
            }
        }
        if(modifier == 1){
            if (l < n && arr[l].female > arr[largest].female)
                largest = l;
        
            
            if (r < n && arr[r].female > arr[largest].female)
                largest = r;
        
           
            if (largest != i) {
                swap(arr[i], arr[largest]);
        
                
                heapify(arr, n, largest, 1);
            }
        }
        if(modifier == 2){
            if (l < n && arr[l].male > arr[largest].male)
                largest = l;
        
            
            if (r < n && arr[r].male > arr[largest].male)
                largest = r;
        
            
            if (largest != i) {
                swap(arr[i], arr[largest]);
        
                
                heapify(arr, n, largest, 2);
            }
        }
    }
    

 

    void maxHeap::buildHeap(SOC * arr, int n, int modifier)
    {
        int startIdx = (n / 2) - 1;
        for (int i = startIdx; i >= 0; i--) {
            heapify(arr, n, i, modifier);
        }
    }