#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

main(){
    string move = " ";
    int cont = 0;
    string skeleton[4];
    bool finish = false;
    skeleton[1] = '-';
    skeleton[2] = '|';
    skeleton[3] = '-';

    do{
        int press;
        cin>>press;
        system("cls");
        if(press == 1){
            move = move + " ";
            skeleton[0] = move;
            cout<<"******************** SCORE: "<<cont<<" *****************"<<endl;
            cout<<"************************************************ | - |"<<endl;
            cout<<skeleton[0]<<skeleton[1]<<skeleton[2]<<skeleton[3]<<endl;
            cout<<"************************************************ | - |"<<endl;
            cout<<skeleton[0]<<skeleton[1]<<skeleton[2]<<skeleton[3]<<endl;
            cout<<"************************************************ | - |"<<endl;
            cont = cont + 1;
            if(cont == 49){
                cout<<"|||| -> MISION COMPLETADA <- ||||"<<endl;
                finish = true;
            }
        }else{
            finish = true;
        }
        
    } while (!finish);
                                                                 
    
}