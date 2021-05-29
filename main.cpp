#include <iostream>
#include <thread>
#include <string>
#include "actions.cpp"
using namespace std;

//testing
int main(){
    cout<<"Listo para comenzar? Presiona enter..."<<endl;
    cin.get();
    thread first(timerGame);
    thread second(stop);
    first.join();
    second.join();
    return 0;
}