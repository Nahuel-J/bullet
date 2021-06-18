#include <iostream>
#include <thread>
#include <string>
#include <windows.h>
#include <unistd.h>
#include "./controllers/stats.cpp"
#include "./controllers/actions.cpp"
#include "./layout/menu.cpp"

using namespace std;

bool start;

int main(){
    int press;
    string usuario;
    int score;
    //--- MENU ----//
    loader();
	cancion_1();
    menu_principal();
    //--- Inicio ----//
    cout<<"Listo para comenzar? Ingresa tus datos."<<endl;
    cout<<"Presiona cualquier tecla. Para volver inserte 0"<<endl;
    cin>>press;
    if(press == 0){
        start = false;
    }else{
        cin.get();
        cout<<"Nombre: "<<"\t";
        cin>>usuario;
        setName(usuario);
        cin.get();
        //----Play----//
        while(start){
            //se crea el segundo hilo utilizando el procedimiento timer.
            thread first(startRunner);
            //procedimiento corriendo en el hilo principal
            timerGame();
            //une los hilos una vez termina su ejecución.
            first.join();
        }
    }
    return 0;
}


