// N05_HW04_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    Adress() {
        city = "Неизвестно";
        street = "Неизвестно";
        building = 1;
        room = 1;
    }
    Adress(std::string city, std::string street, int building, int room) {
        this->city = city;
        this->street = street;
        this->building = building;
        this->room = room;
    }

    std::string output_line() {
        std::string s = city + ", " + street + ", " + std::to_string(building) + ", " + std::to_string(room);
        return s;
    }

    // геттер

    std::string get_priv_city() { return city; }
    std::string get_priv_street() { return street; }
    int get_priv_building() { return building; }
    int get_priv_room() { return room; }

};
void sort(Adress* addresses, int size) {
    bool numb_swap;
    do {
        numb_swap = 0;
        for (int i = 1; i < size; i++) {
            //std::cout << addresses[i - 1].get_priv_city() << std::endl;
            //std::cout << addresses[i].get_priv_city() << std::endl;
            if (addresses[i - 1].get_priv_city().compare(addresses[i].get_priv_city()) > 0) {
                Adress tmp = addresses[i - 1];
                addresses[i - 1] = addresses[i];
                addresses[i] = tmp;
                numb_swap = 1;
            }
            if (addresses[i - 1].get_priv_city().compare(addresses[i].get_priv_city()) == 0 && addresses[i - 1].get_priv_street().compare(addresses[i].get_priv_street()) > 0) {
                Adress tmp = addresses[i - 1];
                addresses[i - 1] = addresses[i];
                addresses[i] = tmp;
                numb_swap = 1;
            }
            if (addresses[i - 1].get_priv_city().compare(addresses[i].get_priv_city()) == 0 && addresses[i - 1].get_priv_street().compare(addresses[i].get_priv_street()) == 0 && addresses[i - 1].get_priv_building() > addresses[i].get_priv_building()) {
                Adress tmp = addresses[i - 1];
                addresses[i - 1] = addresses[i];
                addresses[i] = tmp;
                numb_swap = 1;
            }
            if (addresses[i - 1].get_priv_city().compare(addresses[i].get_priv_city()) == 0 && addresses[i - 1].get_priv_street().compare(addresses[i].get_priv_street()) == 0 && addresses[i - 1].get_priv_building() == addresses[i].get_priv_building() && addresses[i - 1].get_priv_room() > addresses[i].get_priv_room()) {
                Adress tmp = addresses[i - 1];
                addresses[i - 1] = addresses[i];
                addresses[i] = tmp;
                numb_swap = 1;
            }
        }
    } while (numb_swap);

}
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
    std::cout << size << std::endl;
    fout << size << std::endl;
    //std::string* array = new std::string[size];
    Adress* addresses = new Adress[size];
    //Adress* addresses[size];

    for (int i = 0; i < size; i++)
    {
        fin >> s;
        fin >> s1;
        fin >> s2;
        fin >> s3;
        addresses[i] = Adress(s, s1, std::stoi(s2), std::stoi(s3));

    }
    fin.close();

    sort(addresses, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << addresses[i].output_line() << std::endl;
        fout << addresses[i].output_line() << std::endl;
    }
    fout.close();
    delete[] addresses;
}