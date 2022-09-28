#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include <clocale> //Permitir tildes en consola
using namespace std;

//Declaraci�n de las funciones
void menuPrincipal();
void menuIngresarInfo();
//void menuModificarInfo();
//void menuBuscarInfo();

//Main de la aplicaci�n
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	menuPrincipal();
}

//Funci�n para el Menu principal
void menuPrincipal(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Men� principal SPOTIFY" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Ingresar informaci�n" <<endl;
        cout << "\t\t\t 2. Modificar informaci�n" <<endl;
        cout << "\t\t\t 3. B�squeda de informaci�n" <<endl;
        cout << "\t\t\t 0. Salir de la aplicaci�n" << endl << endl;		
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				menuIngresarInfo();
				break;
			case 2:
				//menuModificarInfo();
				break;
			case 3:
				//menuBuscarInfo();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}


//Funci�n para el Menu Ingresar Informaci�n
void menuIngresarInfo(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Ingreso de informaci�n" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Agregar nuevo artista" <<endl;
        cout << "\t\t\t 2. Agregar nueva canci�n" <<endl;
        cout << "\t\t\t 3. Agregar nuevo �lbum" <<endl;
        cout << "\t\t\t 4. Crear una nueva PlayList" << endl;
        cout << "\t\t\t 0. Ir atr�s" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: ";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\t 1. Cargar por consola" << endl;
				cout << "\t\t\t 2. Cargar por archivo de texto" << endl;
				cout << "\t\t\t 0. Ir atr�s" << endl;
				cin >> opcion;
				switch(opcion){
					case 1:
						cout << "Ac� se carga por consola" << endl;
						break;
					case 2:
						cout << "Ac� se carga por archivo de texto" << endl;
						break;
					case 0:
						menuIngresarInfo();
						break;			
				}
				break;
			case 2:
				//menuModificarInfo();
				break;
			case 3:
				//menuBuscarInfo();
				break;
			case 4:
				//menuBuscarInfo();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}
