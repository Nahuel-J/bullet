#include <iostream>
#include <windows.h>
using namespace std;
static bool s_finished = false;

void *time(void *arg);
void *time(void *arg){
    int cont = 100;
    while (!s_finished){
      cout<<cont<<"s"<<endl;
      cont--;   
      Sleep(1000);
    }
}