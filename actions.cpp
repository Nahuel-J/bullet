#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include "lib/esconu.h"
using namespace std;

static bool s_finished = false;

void timerGame();
void stop();
void abstractTyping(string *);

void timerGame(){
  int cont = 100;
  while (!s_finished){
    cout<<cont<<"s";
    this_thread::__sleep_for(1s,0ns);
    CoordenadaXY(0,0);
    cont--;   
  }
}

void stop(){
    string type;
    const string compareName = "alejo";
    cout<<"Inserte el nombre a continuacion: "<<compareName<<endl;
    abstractTyping(&type);
    if(type == compareName){
      s_finished = true;
      cout<<"Finished, winner";
    }else{
      s_finished = true;
      cout<<"GAME OVER";
    };
}

void abstractTyping(string *type){
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
  DWORD mode = 0;
  GetConsoleMode(hStdin, &mode);
  SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
  cin>>*type;
}