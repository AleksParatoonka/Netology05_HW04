// N05_HW04_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>


class Adress {

private:

    std::string city;
    std::string street;
    int building;
    int room;

public:
    Adress(std::string city, std::string street, int building, int room) {
        this->city = city;
        this->street = street;
        this->building = building;
        this->room = room;
    }
    
    std::string output_line() {
      std::string s = city +", " + street + ", " + std::to_string(building) + ", " + std::to_string(room);
      return s;
    }

};
int main()
{

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int size;
    std::ifstream fin("in.txt"); // пытаемся открыть файл  
    std::ofstream fout("out.txt"); // пытаемся открыть файл  
    if (!fin.is_open())
    {
        std::cout << "Error opening file!\n";
        return 1;
    }
    if (!fout.is_open())
    {
        std::cout << "Не получилось открыть файл out.txt" << std::endl;
    }

    std::string s;
    std::string s1, s2, s3;

    fin >> s;
    size = std::stoi(s);
    std::cout << s << std::endl;
	fout << size << std::endl;

    for (int i = 0; i < size; i++)
    {
        fin >> s;
        //std::cout << s << std::endl;
        fin >> s1;
        //std::cout << s1 << std::endl;
        fin >> s2;
        //std::cout << s2 << std::endl;
        fin >> s3;
        //std::cout << s3 << std::endl;

        Adress adress(s, s1, std::stoi(s2), std::stoi(s3));

        std::cout << adress.output_line() << std::endl;
        fout << adress.output_line() << std::endl;
    }

    fin.close();
    fout.close();
}

