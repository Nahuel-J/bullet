#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
using namespace std;

static bool s_finished = false; // cortar el timerGame
static int s_time = 10; // preferencias. Dificultad del temporizador.
static string compareName; // palabra random generada.

void timerGame();
void startRunner();
void abstractTyping(string *);

//temporizador.
void timerGame(){
  //manejo de error al setear el timer.
  if(s_time < 20){
    s_time = 9;
  }
  while (!s_finished){
    cout<<s_time<<"s";
    this_thread::__sleep_for(1s,0ns);
    s_time--;   
  }
}

void startRunner(){
  string type;
  //palabra random.
  cout<<"Inserte el nombre a continuacion: "<<compareName<<endl;
  abstractTyping(&type);
  if(type == compareName){
    s_finished = true;
    // setear cambios al ganar usuario.
  }else{
    s_finished = true;
    // setear cambios al ganar usuario.
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
