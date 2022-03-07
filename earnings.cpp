using namespace std;
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>  
#include "maxHeap.hpp"



int main(int argc, char *argv[]){

    std::cout << "Fuck you Gradescope!";
    string fileName = "Occupation-Dist-All-" + (string)argv[1] + ".csv";
    ifstream input_file;
    input_file.open("Earnings-1960-2019.csv");
    earnings *data = (earnings*)malloc(60*sizeof(earnings));
    for(int i = 0; i < 8; i++){
        string buffer;
        getline(input_file, buffer);
    }
    int index = 0;
    string line,temp;
    for(int index = 0; index < 60; index++){
        string imput;
        string element;
        std::stringstream ss;
        getline(input_file,imput);
        ss << imput;
        for(int i = 0; i < 9; i++){
            if(ss.peek() == '"'){
                ss >> std::quoted(element);
                string comma;
                getline(ss, comma, ',');
            }
            else{
                getline(ss, element, ',');
            }
            if(element == "N"){
                    element = "-1";
            }
            
            switch (i) {
                    case 0:
                        data[index].year = stoi(element);
                        break;
                    case 1:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].male_total = stoi(element);
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
                        data[index].male_earnings = stoi(element);
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
                        data[index].male_earnings = stoi(element);
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
                        data[index].male_earnings_moe = stoi(element);
                        break;
                    case 5:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].female_total = stoi(element);
                        break;
                    case 6:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].female_with_earnings = stoi(element);
                        break;
                    case 7:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].female_earnings = stoi(element);
                        break;
                    case 8:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))
                            {
                                element.erase(i--, 1);
                                len = element.size();
                            }
                        }
                        data[index].female_earnings_moe = stoi(element);
                        break;
                }
                
                
           
        }
        
    
        //std::cout << index << "\t" << "|" << data[index].year << "|" << "\t" << "|" << data[index].male_earnings << "|" << "\t" << "|" << data[index].female_earnings << "|" << "\n";
    }
    int yearPassed = stoi((string)argv[1]);
    
    int q;
    std::cin >> q;
    string query;
    string find;
    for(int i = 0; i < q; i++){
        cin >> find >> query;
        if(query == "max"){
            string modifier;
            int n;
            cin >> modifier >> n;
            maxHeap mh;
            mh.findMax(fileName, modifier, n, yearPassed);
            
        }
        if(query == "ratio"){
            if(i > 0){
                std::cout << endl;
            }
            int year1, year2;
            cin >> year1 >> year2;
            std::cout << "Query: find ratio " << year1 << " " << year2 << "\n\n";
            std::cout << "The female-to-male earnings ratio for " << year1 << "-" << year2 <<":\n";
            for(int i = (2019-year1); i >= (2019-year2); i--){
                double male = (double)data[i].male_earnings;
                double female = (double)data[i].female_earnings;
                double percentage = (female/male)*100 - 0.05;
                std::cout << "\t" << (2019 - i) << ": ";
                std::cout << std::setprecision(1) << std::fixed;
                std::cout << percentage;
                std::cout << "%\n";
            }
            
            

        }
        
    }

    return 0;
}