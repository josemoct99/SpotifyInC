#include <cstdlib> //Para usar System (refrescar la pantalla en el CLI )
#include <iostream> //Entrada y salida de datos en consola
#include <clocale> //Permitir tildes en consola
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
	//Variable para leer el nuevo artista
	char nomArtista[50];	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar artista por consola" << endl;
		cout << "\t\t\t 2. Cargar artista por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << "\t\t\t Escribe el nombre de la sala" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomArtista,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Se ha agregado el artista "<<nomArtista<<endl;
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
				cout << "\t\t\t Escribe el nombre de la canción" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomCancion,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Se ha agregado el artista "<<nomCancion<<endl;
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
	//Variable para leer el nuevo artista
	char nomAlbum[50];	
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Album por consola" << endl;
		cout << "\t\t\t 2. Cargar Album por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << "\t\t\t Escribe el nombre de la Album" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomAlbum,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Se ha agregado el artista "<<nomAlbum<<endl;
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
	do{
		system("cls");
		cout << "\t\t\t 1. Cargar Playlist por consola" << endl;
		cout << "\t\t\t 2. Cargar Playlist por archivo de texto" << endl;
		cout << "\t\t\t 0. Ir atrás" << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << "\t\t\t Escribe el nombre de la Playlist" << endl << "\t\t\t";
				cin.ignore();  //Le pide a getline que ignore el salto de linea hecho anteriormente (endl)
				cin.getline(nomPlaylist,50); //Ya que encuentra directamente un cambio de linea se hace lo de arriba
				cout << "\t\t\t Se ha agregado el artista "<<nomPlaylist<<endl;
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
        cout << "\t\t\t 2. Modificar canción" <<endl;
        cout << "\t\t\t 3. Modificar álbum" <<endl;
        cout << "\t\t\t 4. Modificar PlayList" << endl;
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

//Menú para buscar Información
void menuBuscarInfo(){
		//mientras sea verdadero se mantendra el menu en pantalla
	bool repetir = true;
	//lee la opcion del usuario (elige un numero)
	int opcion;
	
	do{
		system("cls");
		
		//Titulo del menu principal
		cout << "\n\t\t\t	Modificar información" << endl << endl;
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



