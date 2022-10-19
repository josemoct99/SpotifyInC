#include <fstream> 
#include <iostream> //Entrada y salida de datos en consola
#include<vector>//Para usar vector
using namespace std;

ofstream archivoGenerarPlayList;

void generarArchivo(string id, string nombre, string cantCanciones, vector<string> canciones){
	string texto = "";
	texto+=id+"\n";
	texto+=nombre+"\n";
	texto+=cantCanciones;
	
	for(string s : canciones){
		texto+="\n"+s;
	}
	//Escribe en el archivo la info
	archivoGenerarPlayList.open("./archivos/PlayList_"+ id + "_GENERADA.txt", ios::out);//Acá iría añadido el id de la PlayList
	archivoGenerarPlayList << texto;
	archivoGenerarPlayList.close();
}
