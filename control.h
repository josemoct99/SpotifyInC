#include"estructuras.h"
#include <string>
//Declaración de todos los métodos
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes);
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista);
bool agregarCancion(int id, string nombre, string artista, string duracion, bool gusta);
bool agregarPlaylist(int id, string nombre, int cantCanciones, vector<string> listaCanciones);

bool buscarArtista(int id);
bool buscarArtista(string nombre);
bool buscarAlbum(int id);
bool buscarAlbum(string nombre);
bool buscarCancion(int id);
bool buscarCancion(string nombre);
bool buscarPlaylist(int id);
bool buscarPlaylist(string nombre);

void listarArtistas();
void listarAlbumes();
void listarCanciones();
void listarPlaylists();

int generarIdAlbum();
int generarIdArtista();

Album obtenerAlbum(string nombre);

//Metodo para agregar un artista a la lista
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes){
	if(buscarArtista(id)){
		cout << "\n\t\t\t Artista ya existente" << endl;
		return false;
	}
	//Creación del artista
	Artista a;
	a.id = id;
	a.nombre = nombre;
	vector<Albumes> listaAlbumesFinal;
	//Creación de albumes
	for(int i=0; i<cantAlbumes; i++){
		if(!buscarAlbum(nombre)){
			agregarAlbum(generarIdAlbum(),listaAlbumes.at(i),0,vacio,"",nombre);	
		}
		listaAlbumesFinal.push_back(obtenerAlbum(nombre));
	}
	a.listaAlbumes = listaAlbumesFinal;
	
	//Agregación del artista
	artistas.push_back(a);
	listarArtistas();
	return true;
}
//Metodo para agregar un album a la lista
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista){
	if(buscarAlbum(id)){
		cout << "\n\t\t\t Album ya existente" << endl;
		return false;
	}
	Album a;
	a.id = id;
	a.nombre = nombre;
	a.cantCanciones = cantCanciones;
	a.fechaLanzamiento = fechaLanzamiento;
	//
	
	albumes.push_back(a);
	listarAlbumes();
}
//Metodo para agregar un album a la lista
bool agregarCancion(int id, string nombre, string artista, string duracion, bool gusta){
	if(buscarCancion(id)){
		cout << "\n\t\t\t Canción ya existente" << endl;
		return false;
	}
	Cancion c;
	c.id = id;
	c.nombre = nombre;
	c.duracion = duracion;
	c.gusta = gusta;
	//
	
	canciones.push_back(c);
	listarCanciones();
}
//Metodo para agregar una playlist a la lista
bool agregarPlaylist(int id, string nombre, int cantCanciones, vector<string> listaCanciones){
	if(buscarPlaylist(id)){
		cout << "\n\t\t\t Playlist ya existente" << endl;
		return false;
	}
	Playlist p;
	p.id = id;
	p.nombre = nombre;
	p.cantCanciones = cantCanciones;
	//
	
	playLists.push_back(p);
	listarPlaylists();
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



//METOOS DE BÚSQUEDA POR NOMBRE

//Metodo para encontrar un artista dado un nombre
bool buscarArtista(string nombre){
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).nombre == nombre){
			return true;
		}
	}
    return false;      
}
//Metodo para encontrar un album dado un nombre
bool buscarAlbum(string nombre){
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).nombre == nombre){
			return true;
		}
	}
    return false;    
}
//Metodo para encontrar una canción dado un nombre
bool buscarCancion(string nombre){
	for (int i=0; i<canciones.size(); i++){
		if(canciones.at(i).nombre == nombre){
			return true;
		}
	}
    return false;    
}
//Metodo para encontrar una playlist dado un nombre
bool buscarPlaylist(string nombre){
	for (int i=0; i<playLists.size(); i++){
		if(playLists.at(i).nombre == nombre){
			return true;
		}
	}
    return false;    
}





//METODOS PARA LISTAR
//Listar artistas
void listarArtistas(){
	cout << "\n\t\t\t Lista de artistas: " << endl;
	for(Artista a : artistas){
		cout << "\n\t\t\t *" << a.id << endl;
	}
}
//Listar albumes
void listarAlbumes(){
	cout << "\n\t\t\t Lista de albumes: " << endl;
	for(Album a : albumes){
		cout << "\n\t\t\t *" << a.id << endl;
	}
}

//Listar canciones
void listarCanciones(){
	cout << "\n\t\t\t Lista de canciones: " << endl;
	for(Cancion c : canciones){
		cout << "\n\t\t\t *" << c.id << endl;
	}
}

//Listar Playlists
void listarPlaylists(){
	cout << "\n\t\t\t Lista de playlists: " << endl;
	for(Playlist p : playLists){
		cout << "\n\t\t\t *" << p.id << endl;
	}
}



//Generar ID automático

//Generar ID para un artista
int generarIdArtista(){
	if(artistas.size()==0){
		return 1;
	}
	int temp; 
	int listaNumeros[artistas.size()];
    for(int i=0;i<artistas.size();i++){
    	for(int j=0;j<artistas.size()-1;j++){ 
	        if(artistas.at(j).id<artistas.at(j+1).id){
	            temp=artistas.at(j).id; 
	            listaNumeros[j]=artistas.at(j+1).id; 
	            listaNumeros[j+1]=temp;} 
        }
	}
	cout << "ID GENERADO ARTISTA AUTOMÁTICO: " << listaNumeros[artistas.size()-1]+1 << endl;
	return listaNumeros[artistas.size()-1]+1;
}

//Generar ID para un album
int generarIdAlbum(){	
	if(albumes.size()==0){
		return 1;
	}else if(albumes.size()==1){
		cout << "Albumes at 0: " << albumes.at(0).id<< endl;
		return albumes.at(0).id+1;
	}
	
	int temp; 
	int listaNumeros[albumes.size()];
	
	for(int i=0; i<albumes.size(); i++){
		listaNumeros[i] = albumes.at(i).id;
	}
	
	cout << "El tamaño de los albumes es: " << albumes.size() << endl;
    for(int i=0;i<albumes.size();i++){
    	for(int j=0;j<artistas.size()-1;j++){ 
	        if(albumes.at(j).id>albumes.at(j+1).id){
	            temp=albumes.at(j+1).id; 
	            listaNumeros[j]=albumes.at(j).id; 
	            listaNumeros[j+1]=temp;
			}
        }
	}
	cout << "LISTADO DE IDs en LISTANUMEROS: " << endl;
	for(int num : listaNumeros){
		cout << " - " << num;
	}
	cout << endl;
		cout << "LISTADO DE IDs en ALBUMES: " << endl;
	for(Album a : albumes){
		cout << " - " << a.id;
	}
	cout << "ID GENERADO ALBUM AUTOMÁTICO: " << listaNumeros[albumes.size()-1]+1 << endl;
	return listaNumeros[albumes.size()-1]+1;
}




Album obtenerAlbum(string nombre){
	Album album;
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).nombre==nombre){
			album = albumes.at(nombre);
		}
	}
    return album;   
}
