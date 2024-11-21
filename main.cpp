#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct ElectricKettle { //Структура для описания электрического чайника
    string brand; //Фирма-производитель
    int power;
    string serialNumber; //Серийный номер
};

int findMostPowerfulKettle(const vector <ElectricKettle>& kettles){ //Функция возвращающая индекс самого мощного чайника
    int maxIndex = 0;
    for (int i = 1; i < kettles.size(); i++){
        if (kettles[i].power > kettles[maxIndex].power){
            maxIndex = i; //Обновляем индекс, если нашли более мощный чайник
        }
    }
    return maxIndex;
}
int main(){  //создаем динамический массив структур
    setlocale (LC_ALL, "Russian");
    ifstream inputFile("kettles.txt");
    vector <ElectricKettle> kettles;
    ElectricKettle kettle;

    while (inputFile >> kettle.brand >> kettle.power >> kettle.serialNumber){
       kettles.push_back(kettle);
    }
    inputFile.close();
    cout << "Фирма\t\tМощность\tСерийный номер" << endl;

    for (const auto& k: kettles){
       cout << k.brand << "\t\t" << k.power << "\t\t" << k.serialNumber << endl; // Находим индекс самого мощного чайника
    }
    int mostPowerfulIndex = findMostPowerfulKettle(kettles);
    cout << "Самый мощный чайник: " << kettles[mostPowerfulIndex].serialNumber << endl;

    stringstream ss;
    for (const auto& k : kettles){
        ss << "Фирма" << k.brand << endl;
        ss << "Мощность" << k.power << endl;
        ss << "Серийный номер" << k.serialNumber << endl;
        ss << endl;
    }
    ofstream outputFile ("kettles_output.bin", ios::binary);
    const string& data = ss.str();
    outputFile.write (data.c_str(), data.size());
    outputFile.close();
    return 0;
}
