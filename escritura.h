#include <fstream> 
#include <iostream> //Entrada y salida de datos en consola
using namespace std;

ofstream archivoPlayList;

void crearArchivoPlayList(string id){
	archivoPlayList.open("PlayList_"+ id + "_GENERADA.txt", ios::out);//Acá iría añadido el id de la PlayList
}

void cerrarArchivoPlayList(){
	archivoPlayList.close();
}

void generarArchivo(string id, string nombre, string cantCanciones, vector<string> canciones){
	string texto = "";
	texto+=id+"\n";
	texto+=nombre+"\n";
	texto+=cantCanciones;
	
	for(string s : canciones){
		texto+"\n"+=s;
	}
	//Escribe en el archivo la info
	crearArchivoPlayList(id);
	archivoPlayList << texto;
	cerrarArchivoPlayList();
}
