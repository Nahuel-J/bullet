// Se usa la función getch implementada mediante la API de Windows
// Solo las teclas i k para arrib y abajo
 
#include <iostream>
#include <windows.h>
#include <unistd.h>
#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13

using namespace std;
 
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
 
 
int menu(const char titulo[], const char *opciones[], int n);
void menu_principal();
void menu_partida();
void menu_puntos();
void menu_dificultad();
void cancion_1();
 
int main()
{
	cancion_1();
   menu_principal();
   return 0;
}
 
void menu_principal()
{
   bool repite = true;
   int opcion;   
 	
   // Titulo del menú y nombres de las opciones
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
            cout << "\nGRACIAS POR JUGAR !! ADIOS" << endl;
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
   // Titulo del menú y nombres de las opciones
   const char *titulo = "MENU DE PARTIDA";
   const char *opciones[] = {"INICIAR PARTIDA","CAMBIAR AVION","ATRAS"};
   int numopciones = 3;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
 
         case 2:
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
   // Titulo del menú y nombres de las opciones
   const char *titulo = "MENU DE PUNTOS";
   const char *opciones[] = {"HISTORIAL","MAYOR PUNTAJE","ATRAS"};
   int numopciones = 3;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
 
         case 2:
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
   // Titulo del menú y nombres de las opciones
   const char *titulo = "MENU DE DIFICULTAD";
   const char *opciones[] = {"FACIL","MEDIO","DIFICIL","ROMPEME EL ORTO","ATRAS"};
   int numopciones = 5;  // Numero de opciones
 
   do {
      opcion = menu(titulo, opciones, numopciones);
 
      system("cls");
      switch (opcion) {
         case 1:
            cout << "numero1 = ";
            system("pause>nul");
            break;
 
 
         case 2:
            cout << "numero1 = ";
            system("pause>nul");
            break;
            
 		 case 3:
            cout << "numero1 = ";
            system("pause>nul");
            break;
            
         case 4:
            cout << "numero1 = ";
            system("pause>nul");
            break;  
			 
         case 5:
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
      system("color 1e");
      gotoxy(5, 3 + opcionSeleccionada); cout << "==>" << endl;
 
      // Imprime el título del menú
      gotoxy(15, 2); cout << titulo;
 
      // Imprime las opciones del menú
      for (int i = 0; i < numopciones; ++i) {
         gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
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

