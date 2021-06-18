// Se usa la funci�n getch implementada mediante la API de Windows
// Solo las teclas i k para arrib y abajo
 
#include <iostream>
#include <windows.h>
#include <unistd.h>
#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13

using namespace std;
 
 
int menu(const char titulo[], const char *opciones[], int n);
void menu_principal();
void menu_partida();
void menu_puntos();
void menu_dificultad();
void cancion_1();
void loader();
void write();
 
 
 
int main(){
   //chequear errores
   loader();
	cancion_1();
   menu_principal();
   return 0;
}

char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
 
   // Desactivamos escritura en terminal
   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
 
   ReadConsoleA (ih, &c, 1, &contador, NULL);
 
   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }
 
   SetConsoleMode (ih, modo); // Devolvemos control normal
 
   return c;
}
 
int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }
 
 

 
void menu_principal()
{
   bool repite = true;
   int opcion;   
   
   // Titulo del men� y nombres de las opciones
   const char *titulo = "MENU PRINCIPAL";
   const char *opciones[] = {"NUEVA PARTIDA","TABLA DE PUNTOS","DIFICULTAD","SALIR"};
   int numopciones = 4;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      switch (opcion) {
         case 1:
            menu_partida();
            break;
 
 
         case 2:
            menu_puntos();
            break;
 
         case 3:
            menu_dificultad();
            break;
 
         case 4:
         	Beep(900,50);
         	Beep(700,30);
         	Beep(600,50);
         	Beep(1000,30);
         	gotoxy(35,25);
            cout << " GRACIAS POR JUGAR !! ADIOS" << endl;
            repite = false;
            system("pause>nul");
            break;
      }
 
   } while(repite);
}
 
void menu_partida()
{
   bool repite = true;
   int opcion;
   // Titulo del men� y nombres de las opciones
   const char *titulo = "MENU DE PARTIDA";
   const char *opciones[] = {"INICIAR PARTIDA","CAMBIAR AVION","ATRAS"};
   int numopciones = 3;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
         	system("color 0a");
			gotoxy (50,16);
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
 
         case 2:
         	system("color 0a");
			gotoxy (50,16);
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
         case 3:
            repite = false;
            break;
      }
 
   } while(repite);
}
 
void menu_puntos()
{
   bool repite = true;
   int opcion;
   // Titulo del men� y nombres de las opciones
   const char *titulo = "MENU DE PUNTOS";
   const char *opciones[] = {"HISTORIAL","MAYOR PUNTAJE","ATRAS"};
   int numopciones = 3;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
         	system("color 0a");
			gotoxy (50,16);
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
 
         case 2:
         	system("color 0a");
			gotoxy (50,16);
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
         case 3:
            repite = false;
            break;
      }
 
   } while(repite);
}
 
void menu_dificultad()
{
   bool repite = true;
   int opcion;
   // Titulo del men� y nombres de las opciones
   const char *titulo = "MENU DE DIFICULTAD";
   const char *opciones[] = {"FACIL","MEDIO","DIFICIL","ATRAS"};
   int numopciones = 4;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
         	system("color 0a");
			gotoxy (40,16);
            cout << " LA DIFICULTAD FUE CAMBIADA A FACIL ";
            system("pause>nul");
            break;
 

         case 2:
         	system("color 0a");
			gotoxy (40,16);
            cout << " LA DIFICULTAD FUE CAMBIADA A MEDIO ";
            system("pause>nul");
            break;
            
 		 case 3:
 		 	system("color 0a");
			gotoxy (40,16);
            cout << " LA DIFICULTAD FUE CAMBIADA A DIFICIL ";
            system("pause>nul");
            break;
            
         case 4:
            repite = false;
            break;
      }
 
   } while(repite);
}
  
int menu(const char titulo[], const char *opciones[], int numopciones)
{
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
 
   int tecla;
 
   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
   
 
   do {
   		 
      system("cls");
      system("color 0a");
      write();
      gotoxy(40, 15 + opcionSeleccionada); cout << "==>" << endl;
 
      // Imprime el t�tulo del men�
      gotoxy(47, 14); cout << titulo;
 
      // Imprime las opciones del men�
      for (int i = 0; i < numopciones; ++i) {
         gotoxy(47, 16 + i); cout << i + 1 << ") " << opciones[i];
      }
 
      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
 
      do {
         tecla = getch2();
         // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
 
      switch (tecla) {
 
         case ARRIBA:   // En caso que se presione ARRIBA
 			Beep(800,70);
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = numopciones;
            }
 
            break;
 
         case ABAJO:
         	Beep(800,70);
            opcionSeleccionada++;
 
            if (opcionSeleccionada > numopciones) {
               opcionSeleccionada = 1;
            }
 
            break;
 
         case ENTER:
         	Beep(700,50);
         	Beep(500,30);
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}

void cancion_1()
{
	/*
	usleep(100); 
    Beep(120,150);
    usleep(100); 
    Beep(100,200);
    usleep(100); 
    Beep(110,200);
    usleep(100); 
    Beep(120,200);
    usleep(100); 
    Beep(100,150);
    usleep(100); 
    Beep(110,200);
    usleep(100); 
    Beep(120,150);
    usleep(100); 
    Beep(100,200);
    usleep(100); 
    Beep(110,200);
    usleep(100); 
    Beep(120,200);
    usleep(100); 
    Beep(100,150);
    usleep(100); 
    Beep(110,200);
    */
    
    usleep(100); 
    Beep(120,150);
    usleep(100); 
    Beep(100,200);
    usleep(100); 
    Beep(110,200);
    usleep(100); 
    Beep(120,200);
    usleep(100); 
    Beep(100,150);
    usleep(100); 
    Beep(110,200);
    
    usleep(160000);
    Beep(100,200);
    usleep(300000); 
    Beep(100,200);
    usleep(10000); 
    Beep(190,700);
    usleep(500000); 
    
    Beep(210,100);
    usleep(50); 
    Beep(190,100);
    usleep(50); 
    Beep(170,100);
    usleep(50); 
    Beep(210,100);
    usleep(100); 
    Beep(190,700);
}

void loader(){
	char caracter = 254;
	char caracter1= 205;
	char caracter2 = 176;
	char caracter3 = 186;
	
	write();
	
	system("color 0a");
	gotoxy (50,16);
	cout<<" CARGANDO"<<endl;
	gotoxy (37,18);
	cout<<"======================================"<<endl;
	gotoxy (37,20);
	cout<<"======================================"<<endl;
	
	for (int j=2; j<117; j++){ //cuadro
		gotoxy (j,3); cout<<caracter1;
		gotoxy (j,30); cout<<caracter1;
	}
	
	for (int k=4; k<30; k++){ //cuadro
		gotoxy (2,k); cout<<caracter3;
		gotoxy (116,k); cout<<caracter3;
	}
	
	for (int i=38;i<74;i++){
		system("color 02");
		system("color 06");
		system("color 09");
		gotoxy (i,19);
		cout<<caracter;
		
		for (int j=1;j<3;j++){
			for (int k=1;k<3;k++){
				gotoxy(k,24);
			}
		}
	}

}

void write (){
	
	char caracter1= 205;
	char caracter3 = 186;
	
	for (int j=2; j<117; j++){ //cuadro
		gotoxy (j,3); cout<<caracter1;
		gotoxy (j,30); cout<<caracter1;
	}
	
	for (int k=4; k<30; k++){ //cuadro
		gotoxy (2,k); cout<<caracter3;
		gotoxy (116,k); cout<<caracter3;
	}
	
		gotoxy (20,6);
	  cout<<" M7MMMMMq.    M7MMF'  M7MF `7MN.  M7MF'`7MN.  M7MF'` 7MMMMMYMM   M7MMMMMMq."<<endl;
	 	 gotoxy (20,7);
      cout<<"  MM   -MM.   MM       M    MMN.    M    MMN.    M    MM    -7    MM   -MM." <<endl;
      	gotoxy (20,8);
      cout<<"  MM   ,M9    MM       M    M YMb   M    M YMb   M    MM   d      MM   ,M9  "<<endl;
     	gotoxy (20,9);
      cout<<"  MMmmdM9     MM       M    M  -MN. M    M  -MN. M    MMmmMM      MMmmdM9 "  <<endl;
     	 gotoxy (20,10);
      cout<<"  MM  YM.     MM       M    M   -MM.M    M   -MM.M    MM   Y  ,   MM  YM.  " <<endl;
     	 gotoxy (20,11);
      cout<<"  MM   -Mb.   YM.     ,M    M     YMM    M     YMM    MM     ,M   MM   -Mb. "<<endl;
    	 gotoxy (20,12);
      cout<<"-.JMML. .JMM.   -bmmmmd'  .JML.    YM  .JML.    YM  .JMMmmmmMMM .JMML. .JMM.M"<<endl;
	
}

