#include <iostream>
#include <windows.h>
#include "Labs.h"

using namespace std;



int main()
{
    Labs engine = Labs();
    int input = 1;
    while (input) {
        system("cls");
        cout << "Choice labs: 1,2,3,4,5,6,7,8" << endl << "input:";
        cin >> input;
        switch (input)
        {
        case 1:
            engine.First();
            break;
        case 2:
            engine.Second();
            break;
        case 3:
            engine.Thirdy();
            break;
        case 4:
            engine.Forth();
            break;
        case 5:
            engine.Fifth();
            break;
        case 6:
            engine.Sixth();
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            break;
        }
        cout << "Enter digite to continue: ";
        int temp;
        cin >> temp;
    }
    return 0;
}