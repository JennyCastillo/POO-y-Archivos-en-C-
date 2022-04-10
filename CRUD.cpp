#include "Estudiante.cpp"
#include <iostream>

using namespace std;
const char *nombre_archivo  = "archivo.dat";
const char *archivo_temporal  = "temporal.dat";

		    void menu();
			void ingresar_estudiante();
			void abrir_estudiante();
			void modificar_estudiante();
			void buscar_codigo();
			void eliminar_estudiante();
class CRUD: Estudiante{
	protected : string nombre, apellido, direccion;
				int telefono, codigo;
	protected :
			
	void mostrar();
 void menu(){
	int op;
	do{
		cout<<"__________________Menu__________________"<<endl;
		cout<<"1. Ingresar un estudiante"<<endl;
		cout<<"2. Mostrar los datos de un estudiante"<<endl;
		cout<<"3. Modificar los datos de un estudiante"<<endl;
		cout<<"4. Eliminar los datos de un estudiante"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		
		switch (op){
			case 1: ingresar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 2: abrir_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 3: modificar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
			case 4: eliminar_estudiante();
					cout<<"\n";
					system("PAUSE");
					break;
		}
		system("cls");
	}while(op!=5);
}


void buscar_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	CRUD crud;
	fread(&crud,sizeof(CRUD),1,archivo);	
	do{
	   if(crud.codigo == cod)	{
	   	cout<<"Codigo: "<<crud.codigo<<endl;
	   	cout<<"Nombres: "<<crud.nombre<<endl;
	   	cout<<"Apellidos: "<<crud.apellido<<endl;
	   	cout<<"Direccion: "<<crud.direccion<<endl;
	   	cout<<"Telefono: "<<crud.telefono<<endl;
	   }
	   fread(&crud,sizeof(CRUD),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}

void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(CRUD), SEEK_SET );
	
	CRUD crud;
	
    fread ( &crud, sizeof( CRUD ), 1, archivo );

    	cout << "Codigo: " << crud.codigo << endl;
        cout << "Nombre: " << crud.nombre << endl;
        cout << "Apellido: " << crud.apellido << endl;
		cout <<"Direccion: "<<crud.direccion<<endl;
        cout << "Telefono: " << crud.telefono << endl;
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_crud(){

	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombre_archivo, "w+b");
	}
	CRUD crud;
	int registro=0;
	fread ( &crud, sizeof(CRUD), 1, archivo );
	cout<<"_______________________________________________________________________________________________________"<<endl;
	cout <<"| "<< "id" <<" | "<< "CODIGO" <<" | "<< "NOMBRE"<<" | "<<"APELLIDO"<<" | "<<"DIRECCION"<<" | "<<"TELEFONO"<<" | "<<endl;	
		do{
		cout<<"____________________________________________________________________________________________________"<<endl;
		cout <<"| "<< registro <<" |  "<< crud.codigo <<" | "<< crud.nombre <<" | "<< crud.apellido <<" | "<< crud.direccion <<" | "<< crud.telefono<<" | "<<endl;
        
        
		fread ( &crud, sizeof(CRUD), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_crud(){
	
	char continuar;
	FILE* archivo = fopen(nombre_archivo, "ab");
	
	
		CRUD crud;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>crud.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		cin>>crud.nombre;
        cin.ignore();
			
		cout<<"Ingrese el Apellido:";
		cin>>crud.apellido;
        cin.ignore();
		
		cout<<"Ingrese la Direccion:";
		cin>>crud.direccion;
        cin.ignore();
		
		cout<<"Ingrese el Telefono:";
		cin>>crud.telefono;
        cin.ignore();
		
		fwrite( &crud, sizeof(CRUD), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
}
void modificar_crud(){
	
	FILE* archivo = fopen(nombre_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	CRUD crud;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(CRUD), SEEK_SET );
	
		cout<<"Ingrese el Codigo:";
		cin>>crud.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		cin>>crud.nombre;
        cin.ignore();
			
		cout<<"Ingrese el Apellido:";
		cin>>crud.apellido;
        cin.ignore();

		cout<<"Ingrese la Direccion:";
		cin>>crud.direccion;
        cin.ignore(); 
				
		cout<<"Ingrese el Telefono:";
		cin>>crud.telefono;
        cin.ignore();
		
		fwrite( &crud, sizeof(CRUD), 1, archivo );
		
	fclose(archivo);
	abrir_crud();
		system("PAUSE");
}

void eliminar_crud() {

		FILE *archivo, *archivo_temp; 
	archivo_temp=fopen(archivo_temporal,"w+b"); 
	archivo=fopen(nombre_archivo,"rb"); 
	int codigo; 
	CRUD crud; 

	                      				                
	cout<<"INGRESE CODIGO DEL CRUD A ELIMINAR: "<<endl; 
		cin>>codigo; 
	                                                                                
		while(fread(&crud,sizeof(CRUD),1,archivo)){	
			
			if (codigo != crud.codigo) {
			fwrite(&crud,sizeof(CRUD),1,archivo_temp); 
			}
			else{
			}
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	
	remove("Archivo.dat");
	rename("temporal.dat", "Archivo.dat");
	
	}
	};
