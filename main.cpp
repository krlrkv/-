#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct ElectricKettle { //��������� ��� �������� �������������� �������
    string brand; //�����-�������������
    int power;
    string serialNumber; //�������� �����
};

int findMostPowerfulKettle(const vector <ElectricKettle>& kettles){ //������� ������������ ������ ������ ������� �������
    int maxIndex = 0;
    for (int i = 1; i < kettles.size(); i++){
        if (kettles[i].power > kettles[maxIndex].power){
            maxIndex = i; //��������� ������, ���� ����� ����� ������ ������
        }
    }
    return maxIndex;
}
int main(){  //������� ������������ ������ ��������
    setlocale (LC_ALL, "Russian");
    ifstream inputFile("kettles.txt");
    vector <ElectricKettle> kettles;
    ElectricKettle kettle;

    while (inputFile >> kettle.brand >> kettle.power >> kettle.serialNumber){
       kettles.push_back(kettle);
    }
    inputFile.close();
    cout << "�����\t\t��������\t�������� �����" << endl;

    for (const auto& k: kettles){
       cout << k.brand << "\t\t" << k.power << "\t\t" << k.serialNumber << endl; // ������� ������ ������ ������� �������
    }
    int mostPowerfulIndex = findMostPowerfulKettle(kettles);
    cout << "����� ������ ������: " << kettles[mostPowerfulIndex].serialNumber;

    stringstream ss;
    for (const auto& k : kettles){
        ss << "�����" << k.brand << endl;
        ss << "��������" << k.power << endl;
        ss << "�������� �����" << k.serialNumber << endl;
        ss << endl;
    }
    ofstream outputFile ("kettles_output.bin", ios::binary);
    const string& data = ss.str();
    outputFile.write (data.c_str(), data.size());
    outputFile.close();
    return 0;
}
