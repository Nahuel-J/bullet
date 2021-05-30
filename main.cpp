#include <iostream>
#include <thread>
#include <string>
#include "actions.cpp"
using namespace std;

//testing
int main(){
    cout<<"Listo para comenzar? Presiona enter..."<<endl;
    thread first(timerGame);
    cin.get();
    system("cls");
    stop();
    first.join();
    return 0;
}


