#include <iostream>
using namespace std;
class Estudiante{
	protected : string nombre, apellido, direccion;
				int telefono, codigo;
	protected :
			Estudiante(){
			}
			Estudiante(string nom,string ape, string dir, int tel, int cod){
				nombre = nom;
				apellido = ape;
				direccion = dir;
				telefono = tel;
				codigo = cod;
			}
	void mostrar();
}; 