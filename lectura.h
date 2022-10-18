#include <iostream>
#include <fstream> 
#include <string>
#include <cstdlib> //Para pasar de string a int
#include "control.h"
#include <clocale>
using namespace std;
//Tipo de datos para leer archivos
ifstream archivoArtista;
ifstream archivoAlbum;
ifstream archivoCancion;
ifstream archivoPlayList;

void leerArchivoArtista(){
	//Abre el archivo
	archivoArtista.open("./archivos/Artista.txt", ios::in);
	vector<string> datos;
	int id;
	string nomArtista;
	int cantAlbumes;
	vector<string> listaAlbumes;
	int cantOyentes;
	string linea = "";
	
	while(getline(archivoArtista, linea)){
		datos.push_back(linea);
	}
	id = atoi(datos.at(0).c_str());
	nomArtista = datos.at(1);
	cantAlbumes = atoi(datos.at(2).c_str());
	
	for(int i=0; i<cantAlbumes; i++){
		listaAlbumes.push_back(datos.at(i+3));
	}
	cantOyentes = atoi(datos.at(datos.size()-1).c_str());
	
	if(agregarArtista(id, nomArtista, cantAlbumes, listaAlbumes, cantOyentes)){
		cout << "\t\t\t Se ha agregado el artista "<<"\n \t\t\t"<<nomArtista<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantAlbumes<<"\n \t\t\t"<<cantOyentes;	
	}else{
		cout << "\t\t\t No se ha agregado el artista" << endl;
	}
}

void leerArchivoAlbum(){
	//Abre el archivo
	archivoAlbum.open("./archivos/Album.txt", ios::in);
	vector<string> datos;
	
	int id;
	string nomAlbum;
	int cantCanciones;
	vector<string> listaCanciones;
	string fechaLanzamiento;
	string artista;
	
	string linea = "";
	
	while(getline(archivoAlbum, linea)){
		datos.push_back(linea);
	}
	id = atoi(datos.at(0).c_str());
	nomAlbum = datos.at(1);
	cantCanciones = atoi(datos.at(2).c_str());
	
	for(int i=0; i<cantCanciones; i++){
		listaCanciones.push_back(datos.at(i+3));
	}
	
	fechaLanzamiento = datos.at(datos.size()-2);
	artista = datos.at(datos.size()-1);
	
	
	if(agregarAlbum(id,nomAlbum,cantCanciones,listaCanciones,fechaLanzamiento,artista, false)){
		cout << "\t\t\t Se ha agregado el album "<<"\n \t\t\t"<<nomAlbum<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantCanciones<<"\n \t\t\t"<<fechaLanzamiento<<"\n \t\t\t"<<artista;
	}else{
		cout << "\t\t\t No se ha agregado el album" << endl;
	}
	
}

void leerArchivoCancion(){
	//Abre el archivo
	archivoCancion.open("./archivos/Cancion.txt", ios::in);
	vector<string> datos;
	int id;
	string nomCancion;
	string artista;
	string duracion;
	bool meGusta;
	string gustaEscrito = "";
	string linea = "";
	
	while(getline(archivoCancion, linea)){
		datos.push_back(linea);
	}
	id = atoi(datos.at(0).c_str());
	nomCancion = datos.at(1);
	artista = datos.at(2);
	duracion = datos.at(3);
	
	if(datos.at(4)=="true"){
		meGusta = true;
		gustaEscrito = "Te Gusta";
	}else{
		meGusta = false;
		gustaEscrito = "No te Gusta";
	}
	
	if(agregarCancion(id,nomCancion,artista,duracion,meGusta)){
		cout << "\t\t\t Se ha agregado la canción "<<"\n \t\t\t"<<id<<"\n \t\t\t"<<nomCancion<<"\n \t\t\t"<<artista<<"\n \t\t\t"<<duracion<<"\n \t\t\t"<<gustaEscrito;
	}else{
		cout << "\t\t\t No se ha agregado la canción" << endl;
	}
	
}

void leerArchivoPlayList(){
	//Abre el archivo
	archivoPlayList.open("./archivos/PlayList.txt", ios::in);
	vector<string> datos;
	
	int id;
	string nomPlaylist;
	int cantCanciones;
	vector<string> listaCanciones;
	
	string linea = "";
	
	while(getline(archivoPlayList, linea)){
		datos.push_back(linea);
	}
	id = atoi(datos.at(0).c_str());
	nomPlaylist = datos.at(1);
	cantCanciones = atoi(datos.at(2).c_str());
	
	for(int i=0; i<cantCanciones; i++){
		listaCanciones.push_back(datos.at(i+3));
	}
	
	if(agregarPlaylist(id,nomPlaylist,cantCanciones,listaCanciones)){
		cout << "\t\t\t Se ha agregado la PlayList "<<"\n \t\t\t"<<nomPlaylist<<"\n \t\t\t"<<id<<"\n \t\t\t"<<cantCanciones;
	}else{
		cout << "\t\t\t No se ha agregado la PlayList" << endl;
	}
}
