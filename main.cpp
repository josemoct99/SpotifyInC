#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include <clocale> //Permitir tildes en consola

#include <vector>
using namespace std;

//Declaración de las funciones
void menuPrincipal();
void menuIngresarInfo();
void menuAgregarArtista();
void menuAgregarCancion();
void menuAgregarAlbum();
void menuAgregarPlaylist();
void menuModificarInfo();
void menuBuscarInfo();

//Main de la aplicación
int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	menuPrincipal();
}

//Función para el Menu principal
void menuPrincipal(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Menú principal SPOTIFY" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Ingresar información" <<endl;
        cout << "\t\t\t 2. Modificar información" <<endl;
        cout << "\t\t\t 3. Búsqueda de información" <<endl;
        cout << "\t\t\t 0. Salir de la aplicación" << endl << endl;		
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: "<<endl;
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


//Función para el Menu Ingresar Información
void menuIngresarInfo(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Ingreso de información" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Agregar nuevo artista" <<endl;
        cout << "\t\t\t 2. Agregar nueva canción" <<endl;
        cout << "\t\t\t 3. Agregar nuevo álbum" <<endl;
        cout << "\t\t\t 4. Crear una nueva PlayList" << endl;
        cout << "\t\t\t 0. Ir atrás" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: "<<endl;
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


//Función para agregarArtista
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
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre del artista
				char nomArtista[50];
				//Variable para leer el id del artista
				int id;
				//Variable para leer la cantidad de álbumes del artista
				int cantAlbumes;
				//Variable para leer el nombre de cada album del artista
				char nomAlbum[50];
				//Variable para leer la cantidad de oyentes del artista
				int cantOyentes;
				
				
				
				
				cout << "\t\t\t Escribe el código del artista" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre del artista" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomArtista,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de álbumes del artista" << endl << "\t\t\t";
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
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout << "Acá se carga por archivo de texto" << endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}

//Función para agregarCancion
void menuAgregarCancion(){
	//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	//Variable para leer el nuevo artista
	char nomCancion[50];	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar canción por consola" << endl;
		cout << "\t\t\t 2. Cargar canción por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre de la canción
				char nomCancion[50];
				//Variable para leer el id de la canción
				int id;
				//Variable para leer el nombre del artista de la canción
				char nomArtista[50];
				//Variable para leer la duración de la canción
				char duracion[20];
				//Variable para definir si la canción gusta o no
				bool gusta;
				
				cout << "\t\t\t Escribe el código de la canción" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre de la canción" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomCancion,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe el nombre del Artista la canción" << endl << "\t\t\t";
				cin.getline(nomArtista,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la duración de la canción" << endl << "\t\t\t";
				cin.getline(duracion,20); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t ¿Te gusta la canción? " << endl << "\t\t\t";
				cout << "\t\t\t 1. Sí " << endl << "\t\t\t";
				cout << "\t\t\t 2. No " << endl << "\t\t\t";
				cin>>opcion;
				
				if(opcion==1){
					gusta = true;
				}else if(opcion==2){
					gusta = false;
				}else{
					gusta = false;
					cout<<"\t\t\t Canción sin Me gusta por defecto " << endl << "\t\t\t";
				}
				
				cout << "\t\t\t Se ha agregado el la canción "<<endl<<id<<endl<<nomCancion<<endl<<nomArtista<<endl<<duracion<<endl<<gusta;
				
				
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout << "Acá se carga por archivo de texto" << endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}

//Función para agregarAlbum
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
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre del album
				char nomAlbum[50];
				//Variable para leer el id del album
				int id;
				//Variable para leer la cantidad de canciones del album
				int cantCanciones;
				//Variable para leer el nombre de la canción
				char nomCancion[50];
				//Variable para leer el año de lanzamiento del álbum
				char fechaLanzamiento[6];
				//Variable para leer el artista del álbum
				char nomArtista[50];
				
				cout << "\t\t\t Escribe el código del álbum" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre del álbum" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomAlbum,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de canciones del álbum" << endl << "\t\t\t";
				cin >> cantCanciones;
				cin.ignore();
				
				for(int i=0; i<cantCanciones; i++){
					cout << "\t\t\t Escribe el nombre de la canción " <<  i+1 <<endl << "\t\t\t";
					cin.getline(nomCancion,50);
					listPrueba.push_back(nomCancion);
				}
				
				for(string cancion : listPrueba){
					cout << "CANCION: " << cancion << endl;
				}
				
				cout << "\t\t\t Escribe el año de lanzamiento del álbum" << endl << "\t\t\t";
				cin.getline(fechaLanzamiento,6);
				cout << "\t\t\t Escribe el nombre del artista del álbum" << endl << "\t\t\t";
				cin.getline(nomArtista,50);
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado el album "<<endl<<nomAlbum<<endl<<id<<endl<<cantCanciones<<endl<<fechaLanzamiento<<endl<<nomArtista;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout << "Acá se carga por archivo de texto" << endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
}


//Función para agregarPlaylist
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
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				//Variable para leer el nombre de la Playlist
				char nomPlaylist[50];
				//Variable para leer el id de la Playlist
				int id;
				//Variable para leer la cantidad de canciones de la Playlist
				int cantCanciones;
				//Variable para leer el nombre de la canción
				char nomCancion[50];
				
				cout << "\t\t\t Escribe el código de la Playlist" << endl << "\t\t\t";
				cin >> id;
				cout << "\t\t\t Escribe el nombre de la Playlist" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomPlaylist,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Escribe la cantidad de canciones de la Playlist" << endl << "\t\t\t";
				cin >> cantCanciones;
				cin.ignore();
				
				for(int i=0; i<cantCanciones; i++){
					cout << "\t\t\t Escribe el nombre de la canción " <<  i+1 <<endl << "\t\t\t";
					cin.getline(nomCancion,50);
					listPrueba.push_back(nomCancion);
				}
				
				for(string cancion : listPrueba){
					cout << "CANCIÓN: " << cancion << endl;
				}
				
				//RESTO
				
				cout << "\t\t\t Se ha agregado el Playlist "<<endl<<nomPlaylist<<endl<<id<<endl<<cantCanciones<<endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 2:
				cout << "Acá se carga por archivo de texto" << endl;
				system("pause>nul"); //Hará una pausa y no se mostrará nada más en pantalla
				break;
			case 0:
				repetir = false;
				break;	
		}
	}while(repetir);
}

//Menú para modificar Información
void menuModificarInfo(){
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Modificar información" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Modificar artista" <<endl;
        cout << "\t\t\t 2. Modificar albúm" <<endl;
        cout << "\t\t\t 3. Modificar canción" <<endl;
        cout << "\t\t\t 4. Modificar PlayList" << endl;
        cout << "\t\t\t 0. Ir atrás" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: "<<endl;
		cin >> opcion;
		
		//Alternativas
		switch(opcion){
			case 1:
				cout << "\t\t\t Escoge el artista que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ARTISTAS
				cout << "\t\t\t SE MUESTRA LISTADO DE ARTISTAS " << endl << "\t\t\t";
				cout << "\t\t\t Escribe a continuación el id del Álbum para modificar o Escribe 0 para añadir un albúm nuevo al artista" << endl << "\t\t\t";
				break;
			case 2:
				cout << "\t\t\t Escoge el álbum que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE ÁLBUMES " << endl << "\t\t\t";
				cout << "\t\t\t Escoge el álbum que deseas modificar: " << endl << "\t\t\t";
				
				cout << "\t\t\t Escribe a continuación el id del Álbum para modificar o Escribe 0 para añadir un albúm nuevo al artista" << endl << "\t\t\t";				
				break;
			case 3:
				cout << "\t\t\t Escoge la canción que deseas modificar: " << endl << "\t\t\t";
				//LISTAR ALBUMES
				cout << "\t\t\t SE MUESTRA LISTADO DE CANCIONES " << endl << "\t\t\t";
				cout << "\t\t\t Escoge la canción que deseas modificar: " << endl << "\t\t\t";
				break;
			case 4:
				
				break;
			case 0:
				repetir = false;
				break;			
		}
		
	}while(repetir);
	
}

//Menú para buscar Información
void menuBuscarInfo(){
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Buscar información" << endl << endl;
		//Opciones del menu principal
        cout << "\t\t\t 1. Buscar artista" <<endl;
        cout << "\t\t\t 2. Buscar canción" <<endl;
        cout << "\t\t\t 3. Buscar álbum" <<endl;
        cout << "\t\t\t 4. Buscar PlayList" << endl;
        cout << "\t\t\t 5. Mostrar cantidad de ME GUSTA" << endl;
        cout << "\t\t\t 6. Exportar PlayList" << endl;
        cout << "\t\t\t 0. Ir atrás" << endl << endl;
		
		//Lee la opcion elegida del usuario
		cout << "\t\t\tElige una opción: "<<endl;
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


