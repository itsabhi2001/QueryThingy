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
    void Utility::buildArray(earnings * data){
        ifstream input_file;
        input_file.open("Earnings-1960-2019.csv");//open file
        for(int i = 0; i < 8; i++){//buffer first 8 lines
            string buffer;
            getline(input_file, buffer);
        }
        
        string line,temp;
        for(int index = 0; index < 60; index++)
        {//iterate through earnings array
            string imput;//i know i misspelled this
            string element;
            std::stringstream ss;
            getline(input_file,imput);
            ss << imput;
            for(int i = 0; i < 9; i++)
            {
                if(ss.peek() == '"')
                {//look for quotes
                    ss >> std::quoted(element);
                    string comma;
                    getline(ss, comma, ',');
                }
                else
                {
                    getline(ss, element, ',');
                }
                if(element == "N")
                {
                        element = "-1";
                }
                
                switch (i) 
                {//each fill in data values at each index
                    case 0:
                        data[index].year = stoi(element);
                        break;
                    case 1:
                        for (int i = 0, len = element.size(); i < len; i++)
                        {
                            if (ispunct(element[i]))//check for commas and remove them
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
                            if (ispunct(element[i]))//check for commas and remove them
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
                            if (ispunct(element[i]))//check for commas and remove them
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
                            if (ispunct(element[i]))//check for commas and remove them
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
                            if (ispunct(element[i]))//check for commas and remove them
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
                        //check for commas and remove them
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
                        //check for commas and remove them
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
                            if (ispunct(element[i]))//look for commas and execute them
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
    }
    void Utility::OccupationToSOC(string filename, SOC * data){
        ifstream input_file;
        input_file.open(filename);
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
    }
