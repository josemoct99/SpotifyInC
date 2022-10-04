#include"estructuras.h"
#include <string>
//Declaración de todos los métodos
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes);
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista);
bool agregarCancion(int id, string nombre, string artista, string duracion, string gusta);
bool agregarPlaylist(int id, string nombre, int cantCanciones, vector<string> listaCanciones);

bool buscarArtista(int id);
bool buscarAlbum(int id);
bool buscarCancion(int id);
bool buscarPlaylist(int id);

void listarArtistas();

//Metodo para agregar un artista a la lista
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes){
	//vector<Album> listaAlbumes;
	
	if(buscarArtista(id)){
		cout << "\n\t\t\t Artista ya existente" << endl;
		return false;
	}
	Artista a;
	a.id = id;
	artistas.push_back(a);
	listarArtistas();
	return true;
}
//Metodo para agregar un album a la lista
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista){
	if(!buscarAlbum(id)){
		return false;
	}
}
//Metodo para agregar un album a la lista
bool agregarCancion(int id, string nombre, string artista, string duracion, string gusta){
	if(!buscarCancion(id)){
		return false;
	}
	
}
//Metodo para agregar una playlist a la lista
bool agregarPlaylist(int id, string nombre, int cantCanciones, vector<string> listaCanciones){
	if(!buscarPlaylist(id)){
		return false;
	}
	
}


//METOOS DE BÚSQUEDA POR ID

//Metodo para encontrar un artista dado un id
bool buscarArtista(int id){
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).id==id){
			return true;
		}
	}
    return false;      
}
//Metodo para encontrar un album dado un id
bool buscarAlbum(int id){
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).id==id){
			return true;
		}
	}
    return false;    
}
//Metodo para encontrar una canción dado un id
bool buscarCancion(int id){
	for (int i=0; i<canciones.size(); i++){
		if(canciones.at(i).id==id){
			return true;
		}
	}
    return false;    
}
//Metodo para encontrar una playlist dado un id
bool buscarPlaylist(int id){
	for (int i=0; i<playLists.size(); i++){
		if(playLists.at(i).id==id){
			return true;
		}
	}
    return false;    
}



//METODOS PARA LISTAR
void listarArtistas(){
	cout << "\n\t\t\t Lista de artistas: " << endl;
	for(Artista a : artistas){
		cout << "\n\t\t\t -" << a.id << endl;
	}
}
