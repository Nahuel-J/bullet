#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void time(int seconds){
    while (true){
        Sleep(1000); // 1 segundo.
        seconds--;
        system("cls");
        cout<<"Segundos: "<<seconds;
    }
}