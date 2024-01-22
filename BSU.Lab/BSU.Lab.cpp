#include <iostream>
#include <windows.h>
#include "Labs.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Labs engine = Labs();
    int input = 1;
    while (input) {
        system("cls");
        cout << "Выберите лаборторную работу: 1,2,3,4,5,6,7,8" << endl << "Ввод:";
        cin >> input;
        switch (input)
        {
        case 1:
            engine.First();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
        }
        cout << "Введите число для продолжения: ";
        int temp;
        cin >> temp;
    }

    
    return 0;
}