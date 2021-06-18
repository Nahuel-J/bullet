#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

string stateWord[13];
void randomWords();

void randomWords(){
    ifstream file;
    file.open("Words",ios::in); //abre el archivo.
    
    //maneja el error si el file no existe.
    if(file.fail()){
        cout<<"[model]: Error al leer los datos de Words";
    }
    
    int cont = 0;
    while (!file.eof()){
        if(!file.eof()){
            file>>stateWord[cont]; //extrae las palabras valiendose del espacio
            cont++;
        }
    }
}