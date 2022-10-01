#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include <clocale> //Permitir tildes en consola

#include <vector>
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
		cout << "\t\t\tElige una opci�n: "<<endl;
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
		cout << "\t\t\tElige una opci�n: "<<endl;
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
	
	vector<string> listPrueba;
	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar artista por consola" << endl;
		cout << "\t\t\t 2. Cargar artista por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl;
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
					listPrueba.push_back(nomAlbum);
				}
				
				for(string album : listPrueba){
					cout << "ALBUM: " << album << endl;
				}
				
				
				cout << "\t\t\t Escribe la cantidad de oyentes del artista" << endl << "\t\t\t";
				cin >> cantOyentes;
				
				//RESTO
				
				
				
				cout << "\t\t\t Se ha agregado el artista "<<nomArtista<<endl<<id<<endl<<cantAlbumes<<endl<<cantOyentes;
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

//Funci�n para agregarCancion
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
		cout << "\t\t\t 0. Ir atr�s" << endl;
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
				
				cout << "\t\t\t Se ha agregado el la canci�n "<<endl<<id<<endl<<nomCancion<<endl<<nomArtista<<endl<<duracion<<endl<<gusta;
				
				
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
	vector<string> listPrueba;
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Album por consola" << endl;
		cout << "\t\t\t 2. Cargar Album por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl;
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
					listPrueba.push_back(nomCancion);
				}
				
				for(string cancion : listPrueba){
					cout << "CANCION: " << cancion << endl;
				}
				
				cout << "\t\t\t Escribe el a�o de lanzamiento del �lbum" << endl << "\t\t\t";
				cin.getline(fechaLanzamiento,6);
				cout << "\t\t\t Escribe el nombre del artista del �lbum" << endl << "\t\t\t";
				cin.getline(nomArtista,50);
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado el album "<<endl<<nomAlbum<<endl<<id<<endl<<cantCanciones<<endl<<fechaLanzamiento<<endl<<nomArtista;
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
	
	vector<string> listPrueba;
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Playlist por consola" << endl;
		cout << "\t\t\t 2. Cargar Playlist por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atr�s" << endl;
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
					listPrueba.push_back(nomCancion);
				}
				
				for(string cancion : listPrueba){
					cout << "CANCI�N: " << cancion << endl;
				}
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado el Playlist "<<endl<<nomPlaylist<<endl<<id<<endl<<cantCanciones<<endl;
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
		cout << "\t\t\tElige una opci�n: "<<endl;
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\t Escoge el artista que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ARTISTAS
				cout << "\t\t\t SE MUESTRA LISTADO DE ARTISTAS " << endl << "\t\t\t";
				cout << "\t\t\t Escribe a continuaci�n el id del �lbum para modificar o Escribe 0 para a�adir un alb�m nuevo al artista" << endl << "\t\t\t";
				break;
			case 2:
				cout << "\t\t\t Escoge el �lbum que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE �LBUMES " << endl << "\t\t\t";
				cout << "\t\t\t Escoge el �lbum que deseas modificar: " << endl << "\t\t\t";
				
				cout << "\t\t\t Escribe a continuaci�n el id del �lbum para modificar o Escribe 0 para a�adir un alb�m nuevo al artista" << endl << "\t\t\t";				
				break;
			case 3:
				cout << "\t\t\t Escoge la canci�n que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE CANCIONES " << endl << "\t\t\t";
				cout << "\t\t\t Escoge la canci�n que deseas modificar: " << endl << "\t\t\t";
				break;
			case 4:
				
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
        cout << "\t\t\t 2. Buscar canci�n" <<endl;
        cout << "\t\t\t 3. Buscar �lbum" <<endl;
        cout << "\t\t\t 4. Buscar PlayList" << endl;
        cout << "\t\t\t 5. Mostrar cantidad de ME GUSTA" << endl;
        cout << "\t\t\t 6. Exportar PlayList" << endl;
        cout << "\t\t\t 0. Ir atr�s" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opci�n: "<<endl;
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}


