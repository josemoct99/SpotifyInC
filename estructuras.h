#include<vector>//Para usar vector
using namespace std;
//Definición de estructuras
struct Album;
struct Artista;
struct Cancion;
struct Playlist;

//Definición de arreglos globales
vector<Artista> artistas;
vector<Album> albumes;
vector<Cancion> canciones;
vector<Playlist> playLists;
//Estructura de un artísta
struct Artista{
	int id;
	string nombre;
	int cantAlbumes;
	vector<Album> listaAlbumes;
	int cantOyentes;
};

//Estructura de un álbum
struct Album{
	int id;
	string nombre;
	int cantCanciones;
	vector<Cancion> listaCanciones;
	string fechaLanzamiento;
	Artista artista;
};


struct Cancion{
	int id;
	string nombre;
	Artista artista;
	string duracion;
	bool gusta;
};


struct Playlist{
	int id;
	string nombre;
	int catnCanciones;
	vector<Cancion> listaCanciones;

};
