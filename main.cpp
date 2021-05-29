#include <iostream>
#include <pthread.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "timer.cpp"
using namespace std;
void stop();
//testing
int main(){
    cout<<"Listo para comenzar? Presiona enter..."<<endl;
    cin.get();
    pthread_t temporizate;
    pthread_create(&temporizate,NULL,time,NULL);
    stop();
    pthread_join(temporizate,NULL);
    return 0;
}

//funcion de prueba.
void stop(){
    string randomName;
    const string compareName = "alejo";
    gotoxy(1,14);
    cout<<"Inserte el nombre a continuacion: "<<compareName<<endl;
    cin>>randomName;
    if(randomName == compareName){
      s_finished = true;
      cout<<"Finished, winner";
    }else{
      cout<<"GAME OVER";
    };
}