#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include <clocale> //Permitir tildes en consola
#include <unistd.h>//Para usar el m�todo sleep al finalizar el programa
#include"control.h"
using namespace std;

//Declaraci�n de las funciones
void menuPrincipal();
void menuIngresarInfo();
void menuAgregarArtista();
void menuAgregarCancion();
void menuAgregarAlbum();
void menuAgregarPlaylist();
void menuModificarInfo();
void menuBuscarInfo();

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
		cout << "\t\t\tElige una opci�n: "<<endl<<"\t\t\t";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				menuIngresarInfo();
				break;
			case 2:
				menuModificarInfo();
				break;
			case 3:
				menuBuscarInfo();
				break;
			case 0:
				system("cls");
				cout << "\t\t\t GRACIAS POR PREFERIRNOS, �ADIOS!" << endl;
				sleep(2);
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
		
		cout << "\n\t\t\t	Ingreso de informaci�n" << endl << endl;
        cout << "\t\t\t 1. Agregar nuevo artista" <<endl;
        cout << "\t\t\t 2. Agregar nueva canci�n" <<endl;
        cout << "\t\t\t 3. Agregar nuevo �lbum" <<endl;
        cout << "\t\t\t 4. Crear nueva PlayList" << endl;
        cout << "\t\t\t 0. Ir atr�s" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: "<<endl<<"\t\t\t";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				menuAgregarArtista();
				break;
			case 2:
				menuAgregarCancion();
				break;
			case 3:
				menuAgregarAlbum();
				break;
			case 4:
				menuAgregarPlaylist();
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}


//Funci�n para agregarArtista
void menuAgregarArtista(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	vector<string> listTemporal;
	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar artista por consola" << endl;
		cout << "\t\t\t 2. Cargar artista por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl<< "\t\t\t";
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre del artista
				char nomArtista[50];
				//Variable para leer el id del artista
				int id;
				//Variable para leer la cantidad de �lbumes del artista
				int cantAlbumes;
				//Variable para leer el nombre de cada album del artista
				char nomAlbum[50];
				//Variable para leer la cantidad de oyentes del artista
				int cantOyentes;
				
				cout << "\t\t\t Escribe el c�digo del artista" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre del artista" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomArtista,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de �lbumes del artista" << endl << "\t\t\t";
				cin >> cantAlbumes;
				cin.ignore();
				
				for(int i=0; i<cantAlbumes; i++){
					cout << "\t\t\t Escribe el nombre del album " <<  i+1 <<endl << "\t\t\t";
					cin.getline(nomAlbum,50);
					listTemporal.push_back(nomAlbum);
				}
				
				cout << "\t\t\t Escribe la cantidad de oyentes del artista" << endl << "\t\t\t";
				cin >> cantOyentes;
				//Funci�n en el archivo Control.h que se encarga de crear el artista y agregarlo al vector de artistas
				if(agregarArtista(id, nomArtista, cantAlbumes, listTemporal, cantOyentes)){
					cout << "\t\t\t Se ha agregado el artista "<<"\n \t\t\t"<<nomArtista<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantAlbumes<<"\n \t\t\t"<<cantOyentes;	
				}else{
					cout << "\t\t\t No se ha agregado el artista" << endl;
				}
				
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout << "Ac� se carga por archivo de texto" << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}

//Funci�n para agregar Canci�n
void menuAgregarCancion(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el nuevo artista
	char nomCancion[50];	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar canci�n por consola" << endl;
		cout << "\t\t\t 2. Cargar canci�n por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl<< "\t\t\t";
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre de la canci�n
				char nomCancion[50];
				//Variable para leer el id de la canci�n
				int id;
				//Variable para leer el nombre del artista de la canci�n
				char nomArtista[50];
				//Variable para leer la duraci�n de la canci�n
				char duracion[20];
				//Variable para definir si la canci�n gusta o no
				bool gusta;
				
				cout << "\t\t\t Escribe el c�digo de la canci�n" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre de la canci�n" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomCancion,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe el nombre del Artista la canci�n" << endl << "\t\t\t";
				cin.getline(nomArtista,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la duraci�n de la canci�n" << endl << "\t\t\t";
				cin.getline(duracion,20); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t �Te gusta la canci�n? " << endl << "\t\t\t";
				cout << "\t\t\t 1. S� " << endl << "\t\t\t";
				cout << "\t\t\t 2. No " << endl << "\t\t\t";
				cin>>opcion;
				
				if(opcion==1){
					gusta = true;
				}else if(opcion==2){
					gusta = false;
				}else{
					gusta = false;
					cout<<"\t\t\t Canci�n sin Me gusta por defecto " << endl << "\t\t\t";
				}
				
				cout << "\t\t\t Se ha agregado la canci�n "<<"\n \t\t\t"<<id<<"\n \t\t\t"<<nomCancion<<"\n \t\t\t"<<nomArtista<<"\n \t\t\t"<<duracion<<"\n \t\t\t"<<gusta;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout << "Ac� se carga por archivo de texto" << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}

//Funci�n para agregarAlbum
void menuAgregarAlbum(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	vector<string> listTemporal;
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Album por consola" << endl;
		cout << "\t\t\t 2. Cargar Album por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl<<"\t\t\t";
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre del album
				char nomAlbum[50];
				//Variable para leer el id del album
				int id;
				//Variable para leer la cantidad de canciones del album
				int cantCanciones;
				//Variable para leer el nombre de la canci�n
				char nomCancion[50];
				//Variable para leer el a�o de lanzamiento del �lbum
				char fechaLanzamiento[6];
				//Variable para leer el artista del �lbum
				char nomArtista[50];
				
				cout << "\t\t\t Escribe el c�digo del �lbum" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre del �lbum" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomAlbum,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de canciones del �lbum" << endl << "\t\t\t";
				cin >> cantCanciones;
				cin.ignore();
				
				for(int i=0; i<cantCanciones; i++){
					cout << "\t\t\t Escribe el nombre de la canci�n " <<  i+1 <<endl << "\t\t\t";
					cin.getline(nomCancion,50);
					listTemporal.push_back(nomCancion);
				}
				
				cout << "\t\t\t Escribe el a�o de lanzamiento del �lbum" << endl << "\t\t\t";
				cin.getline(fechaLanzamiento,6);
				cout << "\t\t\t Escribe el nombre del artista del �lbum" << endl << "\t\t\t";
				cin.getline(nomArtista,50);
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado el album "<<"\n \t\t\t"<<nomAlbum<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantCanciones<<"\n \t\t\t"<<fechaLanzamiento<<"\n \t\t\t"<<nomArtista;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout << "Ac� se carga por archivo de texto" << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}


//Funci�n para agregarPlaylist
void menuAgregarPlaylist(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el nuevo artista
	char nomPlaylist[50];
	
	vector<string> listTemporal;
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Playlist por consola" << endl;
		cout << "\t\t\t 2. Cargar Playlist por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl <<"\t\t\t";
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre de la Playlist
				char nomPlaylist[50];
				//Variable para leer el id de la Playlist
				int id;
				//Variable para leer la cantidad de canciones de la Playlist
				int cantCanciones;
				//Variable para leer el nombre de la canci�n
				char nomCancion[50];
				
				cout << "\t\t\t Escribe el c�digo de la Playlist" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre de la Playlist" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomPlaylist,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de canciones de la Playlist" << endl << "\t\t\t";
				cin >> cantCanciones;
				cin.ignore();
				
				for(int i=0; i<cantCanciones; i++){
					cout << "\t\t\t Escribe el nombre de la canci�n " <<  i+1 <<endl << "\t\t\t";
					cin.getline(nomCancion,50);
					listTemporal.push_back(nomCancion);
				}
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado la Playlist "<<"\n \t\t\t"<<nomPlaylist<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantCanciones;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout << "Ac� se carga por archivo de texto" << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 0:
				repetir = false;
				break;	
		}
	}while(repetir);
}

//Men� para modificar Informaci�n
void menuModificarInfo(){
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Modificar informaci�n" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Modificar artista" <<endl;
        cout << "\t\t\t 2. Modificar alb�m" <<endl;
        cout << "\t\t\t 3. Modificar canci�n" <<endl;
        cout << "\t\t\t 4. Modificar PlayList" << endl;
        cout << "\t\t\t 0. Ir atr�s" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: "<<endl << "\t\t\t";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\t Escoge el artista que deseas modificar: " << endl;
				//LISTAR ARTISTAS
				cout << "\t\t\t SE MUESTRA LISTADO DE ARTISTAS " << endl;
				cout << "\t\t\t Escribe a continuaci�n el id del �lbum para modificar o Escribe 0 para a�adir un alb�m nuevo al artista"<< endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 2:
				cout << "\t\t\t Escoge el �lbum que deseas modificar: " << endl;
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE �LBUMES " << endl;
				cout << "\t\t\t Escoge la canci�n que deseas modificar: " << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				//LISTAR CANCIONES
				
				break;
			case 3:
				cout << "\t\t\t Escoge la canci�n que deseas modificar: " << endl;
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE CANCIONES " << endl;
				cout << "\t\t\t Escoge la canci�n que deseas modificar: " << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				//LISTAR CANCIONES
				break;
			case 4:
				cout << "\t\t\t Escoge la Playlist que deseas modificar: " << endl;
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE PLAYLISTS " << endl;
				cout << "\t\t\t Escoge la canci�n que deseas agregar o Escribe 0 para a�adir una canci�n nueva al �lbum: " << endl;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				//LISTAR CANCIONES
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}

//Men� para buscar Informaci�n
void menuBuscarInfo(){
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Buscar informaci�n" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Buscar artista" <<endl;
        cout << "\t\t\t 2. Buscar �lbum" <<endl;
        cout << "\t\t\t 3. Buscar canci�n" <<endl;
        cout << "\t\t\t 4. Buscar PlayList" << endl;
        cout << "\t\t\t 5. Mostrar cantidad de ME GUSTA" << endl;
        cout << "\t\t\t 6. Exportar PlayList" << endl;
        cout << "\t\t\t 0. Ir atr�s" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: "<<endl<<"\t\t\t";
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				//Variable para guardar el id del artista a buscar
				int idA;
				cout << "\t\t\t Escribe el id del artista" << endl << "\t\t\t";
				cin >> idA;
				//BUSCARLO
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				
				break;
			case 2:
				int opcion;
				cout << "\t\t\t Elige c�mo deseas buscar el �lbum: " << endl << "\t\t\t";
				cout << "\t\t\t 1. Mediante ID " << endl << "\t\t\t";
				cout << "\t\t\t 2. Mediante NOMBRE" << endl << "\t\t\t";
				
				switch(opcion){
					case 1:
						//Variable para guardar el id del �lbum a buscar
						int id;
						cout << "\t\t\t Escribe el id del �lbum" << endl << "\t\t\t";
						cin >> id;
						//BUSCARLO
						system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
						break;
					case 2:
						//Variable para guardar el id del �lbum a buscar
						char nombre[50];
						cout << "\t\t\t Escribe el nombre del �lbum" << endl << "\t\t\t";
						cin.ignore();
						cin.getline(nombre, 50);
						//BUSCARLO
						system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
						break;
					default:
					repetir = false;					
				}
				break;
			case 3:
				cout << "\t\t\t Elige c�mo deseas buscar la canci�n: " << endl << "\t\t\t";
				cout << "\t\t\t 1. Mediante ID " << endl << "\t\t\t";
				cout << "\t\t\t 2. Mediante DURACI�N" << endl << "\t\t\t";
				cin >> opcion;
				switch(opcion){
					case 1:
						//Variable para guardar el id del �lbum a buscar
						int id;
						cout << "\t\t\t Escribe el id de la canci�n" << endl << "\t\t\t";
						cin >> id;
						//BUSCARLO
						system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
						break;
					case 2:
						//Variable para guardar el id del �lbum a buscar
						char duracion[50];
						cout << "\t\t\t Escribe el la duraci�n de la canci�n" << endl << "\t\t\t";
						cin.ignore();
						cin.getline(duracion, 50);
						//BUSCARLO
						system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
						break;
					default:
					repetir = false;					
				}
				break;
			case 4:
				//Variable para guardar el id de la Playlist a buscar
				int idP;
				cout << "\t\t\t Escribe el id de la PlayList" << endl << "\t\t\t";
				cin >> idP;
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				//BUSCARLO
				break;
			case 5:
				cout << "\t\t\t Lista de canciones con ME GUSTA: " << endl << "\t\t\t";
				//listar canciones
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 6:
				cout << "\t\t\t La PlayList se ha exportado exitosamente: " << endl << "\t\t\t";
				system("pause>nul"); //Har� una pausa y no se mostrar� nada m�s en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}


