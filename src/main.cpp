#include <iostream>
#include <thread>
#include <string>
#include "./controllers/stats.cpp"
#include "./controllers/actions.cpp"
using namespace std;

//testing
int main(){
    cout<<"Listo para comenzar? Presiona enter..."<<endl;
    cin.get();
    //se crea el segundo hilo utilizando el procedimiento timer.
    thread first(timerGame);
    //procedimiento corriendo en el hilo principal
    startRunner();
    //une los hilos una vez termina su ejecución.
    first.join();
    return 0;
}


