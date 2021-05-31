
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }
 

int main(){
	
	gotoxy (35,5);
	cout<<" BARRA DE CARGA "<<endl;
	
	gotoxy (35,10);
	cout<<" CARGANDO..."<<endl;
	
	for (int i=5;i<70;i++){
		system("color 1e");
		system("color 2d");
		system("color 3c");
		gotoxy (i,13);
		cout<<"#";
		gotoxy (i,14);
		cout<<"#";
		
		for (int j=1;j<60;j++){
			for (int k=1;k<60;k++){
				gotoxy(k,24);
			}
		}
	}
	return 0;
}
