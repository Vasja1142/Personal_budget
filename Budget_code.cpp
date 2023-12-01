﻿#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
using namespace std;

//В программе создаётся файл, в который записываются данные, затем он сохраняется.
//Также данные выводятся на экран. Если файл не создан, он создаётся автоматически.

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251); // Возможность для ввода текста на русском
    SetConsoleOutputCP(1251);
    cout << "Введите полностью потраченную сумму" << endl;
    float fullsumm;
    cin >> fullsumm;
    ofstream dataFile("DataFile", ios::app); // создание файла для хранения данных
    cout << "На все расходы поочерёдно вводите тип затраты (продукты, штрафы или др.),затем потраченную на это сумму" << endl;
    cout << "Для завершеня программы введите '0 0'" << endl;
    while (true) {
        string type;
        float summa;
        cin >> type >> summa;
        if (type == "0" || summa == 0) break;
        cout << type << " " << "=" << " " << (summa / fullsumm * 100) << "%" << endl;
        if (dataFile.is_open())
            dataFile << type << summa / fullsumm * 100 << endl;  // Запись в файл данных о покупке с процентами
    }
    if (dataFile.is_open()) {
        dataFile.close();
    }
    return 0;
}
}