#include"estructuras.h"
#include <string>
//Declaración de todos los métodos
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes);
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista,bool primerArtista);
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

int generarIdArtista();
int generarIdAlbum();
int generarIdCancion();
int generarIdPlaylist();

Artista obtenerArtista(string nombre);
Artista obtenerArtista(int id);
Album obtenerAlbum(string nombre);
Album obtenerAlbum(int id);
Cancion obtenerCancion(string nombre);
Playlist obtenerPlaylist(string nombre);
Playlist obtenerPlaylist(int id);

void mostrarInfoArtista(Artista a);
void mostrarInfoAlbum(Album a);
void mostrarInfoCancion(Cancion c);
void mostrarInfoPlaylist(Playlist p);

void modificarArtista(int id, Album a);
void modificarAlbum(string nombre, Artista a);
//void modificarArtista(string nombre, Album a);
//void modificarArtista(string nombre, Album a);

bool eliminarAlbum(int idArtista, int idAlbum);

//Metodo para agregar un artista a la lista
bool agregarArtista(int id, string nombre, int cantAlbumes, vector<string> listaAlbumes, int cantOyentes){
	cout << "Entro a agregarArtista"<<endl;
	if(buscarArtista(id)){
		cout << "\n\t\t\t Artista ya existente" << endl;
		return false;
	}
	//Creación del artista
	Artista a;
	a.id = id;
	a.nombre = nombre;
	a.cantAlbumes = cantAlbumes;
	a.cantOyentes = cantOyentes;
	
	//Creación y agregación de albumes
	vector<Album> listaAlbumesFinal;
	for(int i=0; i<cantAlbumes; i++){
		cout << "Voy a crear albumes para el artista"<<endl;
		vector<string> vacio;
		if(!buscarAlbum(nombre)){
			agregarAlbum(generarIdAlbum(),listaAlbumes.at(i),0,vacio,"",nombre, true);
		}
		modificarAlbum(listaAlbumes.at(i), a);
		listaAlbumesFinal.push_back(obtenerAlbum(listaAlbumes.at(i)));
	}
	a.listaAlbumes = listaAlbumesFinal;
	
	//Agregación del artista
	artistas.push_back(a);
	listarArtistas();
	return true;
}
//Metodo para agregar un album a la lista
bool agregarAlbum(int id, string nombre, int cantCanciones, vector<string> listaCanciones, string fechaLanzamiento, string artista, bool primerArtista){
	cout << "Entro a agregarAlbum"<<endl;
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
	
	vector<string> vacio;
	int cantOyentes =0;
	if(!buscarArtista(artista) && !primerArtista){
		cout << "\t\t\t El artista" << artista << " no existe, ingresa su cantidad de oyentes: " << endl << "\t\t\t";
		cin >> cantOyentes;
		int idArtista = generarIdArtista();
		agregarArtista(idArtista,artista,0,vacio,cantOyentes);
		for (int i=0; i<artistas.size(); i++){
			if(artistas.at(i).nombre == artista){
				a.artista = artistas.at(i);
			}
		}
		modificarArtista(idArtista,a);
	}else if (buscarArtista(artista)){
		for (int i=0; i<artistas.size(); i++){
				if(artistas.at(i).nombre == artista){
				artistas.at(i).listaAlbumes.push_back(a);
				artistas.at(i).cantAlbumes++;
				a.artista = artistas.at(i);
				}
		}
	}else{
		cout << "NO ENTRO A NADA";
	}
	
	
	//Creación y agregación de canciones
	vector<Cancion> listaCancionesFinal;
	for(int i=0; i<cantCanciones; i++){
		cout << "Voy a crear canciones para album"<<endl;
		vector<string> vacio;
		if(!buscarCancion(nombre)){
			agregarCancion(generarIdCancion(), listaCanciones.at(i),artista,"1 00",false);
		}
		listaCancionesFinal.push_back(obtenerCancion(listaCanciones.at(i)));
	}
	a.listaCanciones = listaCancionesFinal;
	
	albumes.push_back(a);
	listarAlbumes();
}
//Metodo para agregar un album a la lista
bool agregarCancion(int id, string nombre, string artista, string duracion, bool gusta){
	cout << "Entro a agregarCancion"<<endl;
	if(buscarCancion(id)){
		cout << "\n\t\t\t Canción ya existente" << endl;
		return false;
	}
	Cancion c;
	c.id = id;
	c.nombre = nombre;
	c.duracion = duracion;
	c.gusta = gusta;
	
	vector<string> vacio;
	int cantOyentes =0;
	if(!buscarArtista(artista)){
		cout << "\t\t\t El artista " << artista << " no existe, ingresa su cantidad de oyentes: " << endl << "\t\t\t";
		cin >> cantOyentes;
		agregarArtista(generarIdArtista(),artista,0,vacio,cantOyentes);
	}
	c.artista = obtenerArtista(artista);

	canciones.push_back(c);
	listarCanciones();
}
//Metodo para agregar una playlist a la lista
bool agregarPlaylist(int id, string nombre, int cantCanciones, vector<string> listaCanciones){
	cout << "Entro a agregarPlaylist"<<endl;
	if(buscarPlaylist(id)){
		cout << "\n\t\t\t Playlist ya existente" << endl;
		return false;
	}
	Playlist p;
	p.id = id;
	p.nombre = nombre;
	p.cantCanciones = cantCanciones;
	//
	
	//Creación y agregación de canciones
	vector<Cancion> listaCancionesFinal;
	for(int i=0; i<cantCanciones; i++){
		vector<string> vacio;
		if(!buscarCancion(listaCanciones.at(i))){
			char nombre[50];
			char duracion[50];
			bool gusta;
			int opcion;
			cout << "\t\t\t La canción " << listaCanciones.at(i) << " no existe, escribe el nombre del artista a continuación: "<<endl<< "\t\t\t";
			if(i!=0){cin.ignore();} // Evita error al iniciar al leer
			cin.getline(nombre, 50);
			cout << "\t\t\t Escribe la duración de la canción: " << endl<< "\t\t\t";
			cin.getline(duracion, 50);
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
			
			agregarCancion(generarIdCancion(), listaCanciones.at(i),nombre,duracion,gusta);
		}
		listaCancionesFinal.push_back(obtenerCancion(listaCanciones.at(i)));
	}
	p.listaCanciones = listaCancionesFinal;
	
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
		cout << "\n\t\t\t * ID:" << a.id << " - NOMBRE:" << a.nombre << endl;
	}
}
//Listar albumes
void listarAlbumes(){
	cout << "\n\t\t\t Lista de albumes: " << endl;
	for(Album a : albumes){
		cout << "For Lista Albumes" << endl;
		cout << "\n\t\t\t * ID:" << a.id << " - NOMBRE:" << a.nombre << endl;
	}
}

//Listar canciones
void listarCanciones(){
	cout << "\n\t\t\t Lista de canciones: " << endl;
	for(Cancion c : canciones){
		cout << "\n\t\t\t * ID:" << c.id << " - NOMBRE:" << c.nombre;
		if(c.gusta){
			cout << " TE GUSTA"<<endl;
		}else{
			cout << " NO TE GUSTA"<<endl;
		}
	}
}

//Listar Playlists
void listarPlaylists(){
	cout << "\n\t\t\t Lista de playlists: " << endl;
	for(Playlist p : playLists){
		cout << "\n\t\t\t * ID:" << p.id << " - NOMBRE:" << p.nombre << endl;
	}
}



//Generar IDs automáticos



//Generar ID para un artista
int generarIdArtista(){	
	if(artistas.size()==0){
		return 1;
	}else if(artistas.size()==1){
		cout << "artistas at 0: " << artistas.at(0).id<< endl;
		return artistas.at(0).id+1;
	}
	
	int temp; 
	int listaNumeros[artistas.size()];
	
	for(int i=0; i<artistas.size(); i++){
		listaNumeros[i] = artistas.at(i).id;
	}
	
	cout << "El tamaño de los artistas es: " << artistas.size() << endl;
    for(int i=0;i<artistas.size();i++){
    	for(int j=0;j<artistas.size()-1;j++){ 
	        if(artistas.at(j).id>artistas.at(j+1).id){
	            temp=artistas.at(j+1).id; 
	            listaNumeros[j]=artistas.at(j).id; 
	            listaNumeros[j+1]=temp;
			}
        }
	}
	cout << "LISTADO DE IDs en LISTANUMEROS: " << endl;
	for(int num : listaNumeros){
		cout << " - " << num;
	}
	cout << endl;
		cout << "LISTADO DE IDs en ARTISTAS: " << endl;
	for(Artista a : artistas){
		cout << " - " << a.id;
	}
	cout << "ID GENERADO ALBUM AUTOMÁTICO: " << listaNumeros[artistas.size()-1]+1 << endl;
	return listaNumeros[artistas.size()-1]+1;
}


/*int generarIdArtista(){
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
}*/

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
    	for(int j=0;j<albumes.size()-1;j++){ 
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


//Generar ID para una canción
int generarIdCancion(){
	if(canciones.size()==0){
		return 1;
	}else if(canciones.size()==1){
		cout << "Canciones at 0: " << canciones.at(0).id<< endl;
		return canciones.at(0).id+1;
	}
	
	int temp; 
	int listaNumeros[canciones.size()];
	
	for(int i=0; i<canciones.size(); i++){
		listaNumeros[i] = canciones.at(i).id;
	}
	
	cout << "El tamaño de las canciones es: " << canciones.size() << endl;
    for(int i=0;i<canciones.size();i++){
    	for(int j=0;j<canciones.size()-1;j++){ 
	        if(canciones.at(j).id>canciones.at(j+1).id){
	            temp=canciones.at(j+1).id; 
	            listaNumeros[j]=canciones.at(j).id; 
	            listaNumeros[j+1]=temp;
			}
        }
	}
	cout << "LISTADO DE IDs en LISTANUMEROS: " << endl;
	for(int num : listaNumeros){
		cout << " - " << num;
	}
	cout << endl;
		cout << "LISTADO DE IDs en CANCIONES: " << endl;
	for(Cancion a : canciones){
		cout << " - " << a.id;
	}
	cout << "ID GENERADO ALBUM AUTOMÁTICO: " << listaNumeros[canciones.size()-1]+1 << endl;
	return listaNumeros[canciones.size()-1]+1;
}

//Generar ID para una playlist
int generarIdPlaylist(){
	if(playLists.size()==0){
		return 1;
	}else if(playLists.size()==1){
		cout << "playLists at 0: " << playLists.at(0).id<< endl;
		return playLists.at(0).id+1;
	}
	
	int temp; 
	int listaNumeros[playLists.size()];
	
	for(int i=0; i<playLists.size(); i++){
		listaNumeros[i] = playLists.at(i).id;
	}
	
	cout << "El tamaño de los playLists es: " << playLists.size() << endl;
    for(int i=0;i<playLists.size();i++){
    	for(int j=0;j<playLists.size()-1;j++){ 
	        if(playLists.at(j).id>playLists.at(j+1).id){
	            temp=playLists.at(j+1).id; 
	            listaNumeros[j]=playLists.at(j).id; 
	            listaNumeros[j+1]=temp;
			}
        }
	}
	cout << "LISTADO DE IDs en LISTANUMEROS: " << endl;
	for(int num : listaNumeros){
		cout << " - " << num;
	}
	cout << endl;
		cout << "LISTADO DE IDs en playLists: " << endl;
	for(Playlist p : playLists){
		cout << " - " << p.id;
	}
	cout << "ID GENERADO ALBUM AUTOMÁTICO: " << listaNumeros[playLists.size()-1]+1 << endl;
	return listaNumeros[playLists.size()-1]+1;
}



//Métodos para devolver las estructuras
Artista obtenerArtista(string nombre){
	Artista artista;
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).nombre==nombre){
			artista = artistas.at(i);
		}
	}
    return artista;   
}

Artista obtenerArtista(int id){
	Artista artista;
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).id==id){
			artista = artistas.at(i);
		}
	}
    return artista;   
}

Album obtenerAlbum(string nombre){
	Album album;
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).nombre==nombre){
			album = albumes.at(i);
		}
	}
    return album;   
}

Album obtenerAlbum(int id){
	Album album;
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).id==id){
			album = albumes.at(i);
		}
	}
    return album;   
}

Cancion obtenerCancion(string nombre){
	Cancion cancion;
	for (int i=0; i<canciones.size(); i++){
		if(canciones.at(i).nombre==nombre){
			cancion = canciones.at(i);
		}
	}
    return cancion;   
}

Cancion obtenerCancion(int id){
	Cancion cancion;
	for (int i=0; i<canciones.size(); i++){
		if(canciones.at(i).id==id){
			cancion = canciones.at(i);
		}
	}
    return cancion;   
}

Playlist obtenerPlaylist(string nombre){
	Playlist playlist;
	for (int i=0; i<playLists.size(); i++){
		if(playLists.at(i).nombre==nombre){
			playlist = playLists.at(i);
		}
	}
    return playlist;   
}

Playlist obtenerPlaylist(int id){
	Playlist playlist;
	for (int i=0; i<playLists.size(); i++){
		if(playLists.at(i).id==id){
			playlist = playLists.at(i);
		}
	}
    return playlist;   
}


//Métodos para mostrar toda la info 
//Mostrar info de artista
void mostrarInfoArtista(Artista a){
	cout << "\t\t\t* ID:" << a.id << " - NOMBRE:" << a.nombre << " - CANTIDAD DE ALBUMES: " << a.cantAlbumes << endl;
	cout << "\t\t\t Listado de álbumes:" <<endl;
	for(Album al : a.listaAlbumes){
		cout << "\t\t\t\t -ID:" << al.id << " -NOMBRE:" << al.nombre << endl;
	}
	cout << "\t\t\t CANTIDAD DE OYENTES:" << a.cantOyentes << endl;
}


//Mostrar info de album
void mostrarInfoAlbum(Album a){
	cout << "\t\t\t* ID:" << a.id << " - NOMBRE:" << a.nombre << " - CANTIDAD DE CANCIONES: " << a.cantCanciones << endl;
	cout << "\t\t\t Listado de canciones:" <<endl;
	for(Cancion c : a.listaCanciones){
		cout << "\t\t\t\t -" << c.nombre << endl;
	}
	cout << "\t\t\t FECHA DE LANZAMIENTO:" << a.fechaLanzamiento << " - ARTISTA:"<< a.artista.nombre << endl;
	
}

//Mostrar info de cancion
void mostrarInfoCancion(Cancion c){
	cout << "\t\t\t* ID:" << c.id << " - NOMBRE:" << c.nombre << " - ARTISTA: " << c.artista.nombre << endl;
	cout << "\t\t\t DURACIÓN:" << c.duracion;
	if(c.gusta){
		cout << " - TE GUSTA ESTA CANCIÓN";
	}else{
		cout << " - NO TE GUSTA ESTA CANCIÓN";
	}
}

//Mostrar info de cancion
void mostrarInfoPlaylist(Playlist p){
	cout << "\t\t\t* ID:" << p.id << " - NOMBRE:" << p.nombre << " - CANTIDAD DE CANCIONES: " << p.cantCanciones << endl;
	cout << "\t\t\t Listado de canciones:" <<endl;
	for(Cancion c : p.listaCanciones){
		cout << "\t\t\t\t -" << c.nombre << endl;
	}
}

//METODOS EXTRAS
void mostrarCancionesDuracion(string duracion){
	cout << "\t\t\t Canciones con duración " << duracion << " encontradas: "<<endl; 
	for(Cancion c : canciones){
		if(c.duracion==duracion){
			cout << "\t\t\t * Id: " << c.id << " - Nombre: " << c.nombre << endl;
		}
	}
}

void mostrarCantidadMeGusta(){
	for(Cancion c : canciones){
		if(c.gusta){
			cout << "\t\t\t *ID:" << c.id << " - NOMBRE:" << c.nombre << endl;
		}
	}
}

string obtenerNombreArtista(int id){
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).id==id){
			return artistas.at(i).nombre;
		}
	}
    return "";   
}

int obtenerIdArtista(string nombre){
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).nombre==nombre){
			return artistas.at(i).id;
		}
	}
    return 0;   
}

void modificarCancion(int id){
	for (int i=0; i<canciones.size(); i++){
		if(canciones.at(i).id==id){
			if(canciones.at(i).gusta){
				canciones.at(i).gusta = false;
				cout << "\t\t\t La canción " << canciones.at(i).nombre << " ahora NO TE GUSTA" << endl;
			}else{
				canciones.at(i).gusta = true;
				cout << "\t\t\t La canción " << canciones.at(i).nombre << " ahora TE GUSTA" << endl;
			}
		}
	}
}


//MÉTODOS PARA MODIFICAR ELEMENTOS
void modificarArtista(int id, Album a){
	for (int i=0; i<artistas.size(); i++){
		if(artistas.at(i).id==id){
			artistas.at(i).cantAlbumes++;
			artistas.at(i).listaAlbumes.push_back(a);;
		}
	}
}

void modificarAlbum(string nombre, Artista a){
	for (int i=0; i<albumes.size(); i++){
		if(albumes.at(i).nombre==nombre){
			albumes.at(i).artista = a;
		}
	}
}



//METODOS PARA ELIMINAR ELEMENTOS

bool eliminarAlbum(int idArtista, int idAlbum){
	vector<Album>::iterator itArtista;
	vector<Album>::iterator itAlbumes;
	
	for (int i=0; i<artistas.size(); i++){
			if(artistas.at(i).id==idArtista){
				itArtista = artistas.at(i).listaAlbumes.begin();
				
				for(int j=0; j<artistas.at(i).listaAlbumes.size();j++){
					if(artistas.at(i).listaAlbumes.at(j).id == idAlbum){
						artistas.at(i).listaAlbumes.erase(itArtista+j);
						artistas.at(i).cantAlbumes--;
					}
				}
				for (int k=0; k<albumes.size(); k++){
					if(albumes.at(k).id == idAlbum){
						itAlbumes = albumes.begin();
						albumes.erase(itAlbumes+k);
					}
				}
				return true;
		}
	}
	return false;
}








