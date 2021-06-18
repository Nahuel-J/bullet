#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
#include "../../lib/esconu.h"
using namespace std;

static bool s_finished = false; // cortar el timerGame
static int s_time = 10; // preferencias. Dificultad del temporizador.
static char compareName; // palabra random generada.

void timerGame();
void stop();
void abstractTyping(string *);

//temporizador.
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

void stop(){
  string type;
  //palabra random.
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

//procedimiento que oculta lo que el usuario tipea.
void abstractTyping(string *type){
  HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
  DWORD mode = 0;
  GetConsoleMode(hStdin, &mode);
  SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
  cin>>*type;
}

//trabajar esta funcion con ejemplos como el abecedario usando caracteres.
string randomWords(char word){
  srand(time(NULL));
  for (int i = 0; i < s_time; i++){
    word = 1+rand()%;
  }
  
}