#include <cstdio>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h> // Обязательно для SetConsoleCP() и SetConsoleOutputCP()
#include <locale.h>
using namespace std;

int str(string st1)
{
    int summ = 0, count = 0;
    char s[2];
    string str = "бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";
    for (int i = 0; i < st1.length(); i++) {
        bool pch = str.find(st1[i]);
        if (pch) {
            summ++;
        }
    }
    return summ;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, n = 0, k = 0, summ = 0, count = 0;
    char fileNameIN[10], fileNameOut[10], answer[2];
    char lineIn[255];
    setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
    string buff; // буфер промежуточного хранения считываемого из файла текста
    cout << "Введите имя входного файла: ";
    cin >> fileNameIN;
    cout << "Введите имя результирующего файла: ";
    cin >> fileNameOut;
    cout << "Введите нижнюю границу N: ";
    cin >> n;
    cout << "Введите верхнюю границу K: ";
    cin >> k;
    strcat_s(fileNameIN, ".txt");
    strcat_s(fileNameOut, ".txt");
    ifstream fin(fileNameIN);
    ofstream fout(fileNameOut);
    count = 0;
    if (fin.is_open()) { // если файл открыт
        while (fin)
        {
            fin.getline(lineIn, 255); // считали строку из файла
            fin >> buff;
            count++;
            if (count >= n && count <= k) {
                summ += str(lineIn);
                fout << lineIn;
                fout << "\n";
            }
        }
    }
    cout << "Число согласных букв: " << summ;
    fout.close(); // закрываем файл
    fin.close(); // закрываем файл
    return 0;
}

