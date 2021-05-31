#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

static bool s_finished = false; //variable estatica encargada de cortar el timerGame
static int s_time = 0; // variable estatica encargada del

void timerGame(){
  //manejo de error al setear el timer.
  system("");
  if(s_time < 20){
    s_time = 9;
  }
  while (!s_finished){
    cout<<s_time<<"s";
    this_thread::__sleep_for(1s,0ns);
    CoordenadaXY(0,5);
    s_time--;   
  }
}

//CAMBIAR NOMBRE DE STOP, NO CUMPLE CON UNA DESCRIPCION CERTERA.
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