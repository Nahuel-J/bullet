#include <iostream>
#include <pthread.h>
#include <windows.h>
#include <string>
using namespace std;

static bool s_finish = false;
void *time(void *arg);
void *stop(void *arg);

//testing
int main(int argc, char const *argv[]){
    pthread_t hilo1;
    pthread_t hilo2;
    pthread_create(&hilo1,NULL,time,NULL);
    pthread_create(&hilo2,NULL,stop,NULL);
    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);
    return 0;
}
//funcion de tiempo
void *time(void *arg){
    int cont = 100;
    while (!s_finish){
      cout<<"Tu tiempo es de: "<<cont<<" segundos"<<endl;
      cont--;   
      Sleep(1000);
    }
}
//funcion de prueba.
void *stop(void *arg){
    string randomName;
    const string compareName = "alejo";
    cout<<"Inserte el nombre a continuacion: "<<compareName<<endl;
    cin>>randomName;
    if(randomName == compareName){
      cout<<"Finished, winner";
      s_finish = true;
    }else{
      cout<<"GAME OVER";
    };
}