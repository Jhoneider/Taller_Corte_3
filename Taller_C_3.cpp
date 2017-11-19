#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//#define NuevoNodoSimple (NodoSimple*)malloc(sizeof(NodoSimple));
//#define NuevoNodoDoble (NodoDoble*)malloc(sizeof(NodoDoble));
//#define NuevoNodoCircularsimple (NodoCircularsimple*)malloc(sizeof(NodoCircularsimple));
//#define NuevoNodoCirculardoble (NodoCirculardoble*)malloc(sizeof(NodoCirculardoble));

using namespace std;

//variables globales
int TipoLista=0;
bool ordenada=true;
//fin variables globales

//estructuras globales
struct NodoSimple{
	int dato;
	NodoSimple *siguiente;
}*PNsimple=NULL;

struct NodoDoble{
	int dato;
	NodoDoble *siguiente;
	NodoDoble *anterior;
}*PNdobleI=NULL,*PNdobleF=NULL;

struct NodoCircularsimple{
	int dato;
	NodoCircularsimple *siguiente;
}*PNcircularI=NULL,*PNcircularF=NULL;

struct NodoCirculardoble{
	int dato;
	NodoCirculardoble *siguiente;
	NodoCirculardoble *anterior;
}*PNCdobleI=NULL,*PNCdobleF=NULL;

//fin estructuras globales

//funciones generales
void agregarElementoGeneral();
void QuitarElementoGeneral();
void MostrarElementoGeneral();
void BuscarElementoGeneral();
void ModificarElementoGeneral();

void JuegoDeJosepha();
//fin funciones generales

//funciones especificas
void agregarElementoASimple(int);
void agregarElementoADoble(int);
void agregarElementoACircularsimple(int);
void agregarElementoACirculardoble(int);

void QuitarElementoASimple();
void QuitarElementoADoble();
void QuitarElementoACircularsimple();
void QuitarElementoACirculardoble();

void MostrarListaSimple();
void MostrarListaDoble();
void MostrarListaCircularsimple();
void MostrarListaCirculardoble();

void BuscarEnListaSimple();
void BuscarEnListaDoble();
void BuscarEnListaCircularsimple();
void BuscarEnListaCirculardoble();

void ModificarEnListaSimple();
void ModificarEnListaDoble();
void ModificarEnListaCircularsimple();
void ModificarEnListaCirculardoble();



void menuPrincipal();
void menuGeneral();

int main(int argc, char *argv[]) {
	
	menuPrincipal();
	
	return 0;
}

void menuPrincipal(){
	int opcion = 0;
	
	do{
		system("cls");
		printf("*** ESTRUCTURA DE DATOS II - JHONEIDER HINCAPIE _ JOHN ALEJANDRO GIRALDO ***\n\n");
		printf("1. Lista simple enlazada.\n");
		printf("2. Lista doble enlazada.\n");
		printf("3. Lista circular simple.\n");
		printf("4. Lista circular doble.\n");
		printf("5. salir.\n\n");
		printf("Escoja una opcion : ");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				TipoLista=0;
				menuGeneral();
				break;
			case 2:
				TipoLista=1;
				menuGeneral();
				break;
			case 3:
				TipoLista=2;
				menuGeneral();
			break;
			case 4:
				TipoLista=3;
				menuGeneral();
				break;
			case 5:
				printf("\n *** Adios *** \n");
				break;
		default:
			printf("No se reconoce su peticion. \n");
			system("pause");
		}
		
	} while(opcion!=5);
}

void menuGeneral(){
	int opcion = 0;
	
	do{
		system("cls");
		//if(ListaSimple)printf("*** LISTA SIMPLE ENLAZADA ***\n\n");else printf("*** LISTA DOBLE ENLAZADA ***\n\n");
		
		switch(TipoLista){ //ver a que lista se va a agregar
		case 0: //lista enlazada simple
			printf("*** LISTA SIMPLE ENLAZADA ***\n\n");
			break;
		case 1:
			printf("*** LISTA DOBLE ENLAZADA ***\n\n");
			break;
		case 2:
			printf("*** LISTA CIRCULAR SIMPLE ***\n\n");
			break;
		case 3:
			printf("*** LISTA CIRCULAR DOBLE ***\n\n");
			break;
		}
		
		printf("1. Agregar elemento.\n");
		printf("2. Quitar un elemento.\n");
		printf("3. Mostrar lista.\n");
		printf("4. Buscar dato.\n");
		printf("5. Editar dato.\n");
		printf("6. Juego de josepha.\n");
		printf("7. Regresar.\n\n");
		printf("Escoja una opcion : ");
		scanf("%d",&opcion);
		
		switch(opcion){
		case 1:
				agregarElementoGeneral();
				printf("\n");system("pause");
			break;
		case 2:
				QuitarElementoGeneral();
				printf("\n");system("pause");
			break;
		case 3:
				MostrarElementoGeneral();
				printf("\n");system("pause");
			break;
		case 4:
				BuscarElementoGeneral();
				printf("\n");system("pause");
			break;
		case 5:
				ModificarElementoGeneral();
				printf("\n");system("pause");
			break;
		case 6:
			//juego de josepha
			JuegoDeJosepha();
			printf("\n");system("pause");
			break;
		case 7:
			 menuPrincipal();
			break;
		default:
			printf("No se reconoce su peticion. \n");
			system("pause");
		}
		
	} while(opcion!=7);
}


void agregarElementoGeneral(){
	int opc = 0;
	
	do{
		printf("Escoja la opcion de insercion. Ordenada 1.  Desordenada 2. : ");
		scanf("%d",&opc);
		
		if(opc==1){
			ordenada = true;
			printf("\n");
		}else if(opc==2){
			ordenada = false;
			printf("\n");
		} else {
			printf("\nNo se reconoce su peticion.");
		}
	} while(opc!=1 && opc!=2);
	
	int daton;
	
	switch(TipoLista){ //ver a que lista se va a agregar
		case 0: //lista enlazada simple
			
			printf("Ingrese el numero que desee insertar: ");scanf("%d",&daton);
				agregarElementoASimple(daton);
			break;
		case 1:

			printf("Ingrese el numero que desee insertar: ");scanf("%d",&daton);
				agregarElementoADoble(daton);
			break;
		case 2:

			printf("Ingrese el numero que desee insertar: ");scanf("%d",&daton);
			agregarElementoACircularsimple(daton);
			break;
		case 3:

			printf("Ingrese el numero que desee insertar: ");scanf("%d",&daton);
			agregarElementoACirculardoble(daton);
			break;
	}
}

void QuitarElementoGeneral(){
	switch(TipoLista){ //ver a que lista se va a agregar
	case 0: //lista enlazada simple
		QuitarElementoASimple();
		break;
	case 1:
		QuitarElementoADoble();
		break;
	case 2:
		QuitarElementoACircularsimple();
		break;
	case 3:
		QuitarElementoACirculardoble();
		break;
	}
}

void MostrarElementoGeneral(){
	switch(TipoLista){ //ver a que lista se va a agregar
	case 0: //lista enlazada simple
		MostrarListaSimple();
		break;
	case 1:
		MostrarListaDoble();
		break;
	case 2:
		MostrarListaCircularsimple();
		break;
	case 3:
		MostrarListaCirculardoble();
		break;
	}
}

void BuscarElementoGeneral(){ 
	switch(TipoLista){ //ver a que lista se va a agregar
	case 0: //lista enlazada simple
		BuscarEnListaSimple();
		break;
	case 1:
		BuscarEnListaDoble();
		break;
	case 2:
		BuscarEnListaCircularsimple();
		break;
	case 3:
		BuscarEnListaCirculardoble();
		break;
	}
}

void ModificarElementoGeneral(){
	switch(TipoLista){ //ver a que lista se va a agregar
	case 0: //lista enlazada simple
			ModificarEnListaSimple();
		break;
	case 1:
			ModificarEnListaDoble();
		break;
	case 2:
			ModificarEnListaCircularsimple();
		break;
	case 3:
			ModificarEnListaCirculardoble();
		break;
	}
}

void JuegoDeJosepha(){
	if(TipoLista!=4){
		printf("\nLa lista no es apropiada para el juego, escoja una circular.");
		return;
	}else {
		
		do{
			if(PNcircularI==NULL){
				printf("La lista se encuentra vacia.");
				break;
			}
			
			NodoCirculardoble *Aux= PNCdobleI;
			int n;
			printf("Ingrese un numero : ");scanf("%d",&n);
			
			while(n>=0){
				n--;
				if(n==0){
					if(Aux==PNCdobleI){
						PNCdobleI=Aux->siguiente;
						int da = Aux->dato;
						free(Aux);
						Aux = PNCdobleI;
						printf("\n.Se ha retirado el numero %d",da);
					} else {
						NodoCirculardoble *Ant = Aux->anterior;
						NodoCirculardoble *sig = Aux->siguiente;
						int da = Aux->dato;
						sig->anterior = Ant;
						Ant->siguiente=sig;
						free(Aux);
						printf("\n.Se ha retirado el numero %d",da);
					}
				}
				Aux=Aux->siguiente;
				
			}
		} while(PNCdobleI!=NULL);
	}
}


void agregarElementoASimple(int Ndato){
	if(ordenada){
		NodoSimple* NuevoNodo = (NodoSimple*)malloc(sizeof(NodoSimple));
		NuevoNodo->dato = Ndato;
		NodoSimple* aux1 = PNsimple;
		NodoSimple* aux2;
		
		while(aux1!=NULL && aux1->dato < Ndato){
			aux2=aux1;
			aux1=aux1->siguiente;
		}
		
		if(aux1==PNsimple){
			NuevoNodo->siguiente=aux1;
			PNsimple=NuevoNodo;
		} else {
			aux2->siguiente=NuevoNodo;
			NuevoNodo->siguiente=aux1;
		}
		
		printf("\nEl dato se ha agregado ordenado correctamente.");
		
	} else {

		NodoSimple* NuevoNodo = (NodoSimple*)malloc(sizeof(NodoSimple));
		NuevoNodo->dato = Ndato;
		NuevoNodo->siguiente = PNsimple;
		PNsimple = NuevoNodo;
		printf("\nEl dato se ha agregado correctamente.");
	}
}

void agregarElementoADoble(int Ndato){
	if(ordenada){
		NodoDoble* NuevoNodo = (NodoDoble*)malloc(sizeof(NodoDoble));
		NuevoNodo->dato = Ndato;
		NodoDoble* aux1 = PNdobleI;
		NodoDoble* aux2;
		
		while(aux1!=NULL && aux1->dato < Ndato){
			aux2=aux1;
			aux1=aux1->siguiente;
		}
		
		if(aux1==PNdobleI){
			NuevoNodo->siguiente=aux1;
			NuevoNodo->anterior=NULL;
			PNdobleI=NuevoNodo;
		} else if(aux1==PNdobleF){
			NuevoNodo->siguiente=NULL;
			NuevoNodo->anterior=aux1;
			PNdobleF=NuevoNodo;
		} else {
			aux2->siguiente=NuevoNodo;
			NuevoNodo->siguiente=aux1;
			NuevoNodo->anterior=aux2;
		}
		
		printf("\nEl dato se ha agregado ordenado correctamente.");
		
	} else {
		bool primero=false;
		if(PNdobleI==NULL){
			primero=true;
		}
		  
		NodoDoble* NuevoNodo = (NodoDoble*)malloc(sizeof(NodoDoble));
		NuevoNodo->dato = Ndato;
		NuevoNodo->siguiente = PNdobleI;
		NuevoNodo->anterior = NULL;
		PNdobleI = NuevoNodo;
		if(primero)PNdobleF = NuevoNodo;else PNdobleF = NULL;
		
		printf("\nEl dato se ha agregado correctamente.");
	}
}

void agregarElementoACircularsimple(int Ndato){
	if(ordenada){
		NodoCircularsimple* NuevoNodo = (NodoCircularsimple*)malloc(sizeof(NodoCircularsimple));
		NuevoNodo->dato = Ndato;
		
		if(PNcircularI==NULL){
			PNcircularI=NuevoNodo;
			PNcircularF=NuevoNodo;
			NuevoNodo->siguiente = NuevoNodo;
			printf("\nEl dato se ha agregado ordenado correctamente.");
		} else {
			NodoCircularsimple* aux1 = PNcircularI;
			NodoCircularsimple* aux2;
			
			while(aux1!=NULL && aux1->dato < Ndato){
				aux2=aux1;
				aux1=aux1->siguiente;
			}
			
			if(aux1==PNcircularI){
				NuevoNodo->siguiente=aux1;
				PNcircularI=NuevoNodo;
			} else {
				aux2->siguiente=NuevoNodo;
				NuevoNodo->siguiente=aux1;
			}
			
			printf("\nEl dato se ha agregado ordenado correctamente.");
		}
	
	} else {
		
		if(PNcircularI==NULL){
			NodoCircularsimple* NuevoNodo = (NodoCircularsimple*)malloc(sizeof(NodoCircularsimple));
			PNcircularI=NuevoNodo;
			PNcircularF=NuevoNodo;
			NuevoNodo->siguiente = NuevoNodo;
			printf("\nEl dato se ha agregado ordenado correctamente.");
		}else {
			NodoCircularsimple* NuevoNodo = (NodoCircularsimple*)malloc(sizeof(NodoCircularsimple));
			NuevoNodo->dato = Ndato;
			NuevoNodo->siguiente = PNcircularI;
			PNcircularI = NuevoNodo;
			printf("\nEl dato se ha agregado correctamente.");
		}
	}
}

void agregarElementoACirculardoble(int Ndato){
	if(ordenada){
		NodoCirculardoble* NuevoNodo = (NodoCirculardoble*)malloc(sizeof(NodoCirculardoble));
		NuevoNodo->dato = Ndato;
		NodoCirculardoble* aux1 = PNCdobleI;
		NodoCirculardoble* aux2;
		
		while(aux1!=NULL && aux1->dato < Ndato){
			aux2=aux1;
			aux1=aux1->siguiente;
		}
		
		if(aux1==PNCdobleI){
			NuevoNodo->siguiente=aux1;
			NuevoNodo->anterior=NULL;
			PNCdobleI=NuevoNodo;
		} else if(aux1==PNCdobleF){
			NuevoNodo->siguiente=NULL;
			NuevoNodo->anterior=aux1;
			PNCdobleF=NuevoNodo;
		} else {
			aux2->siguiente=NuevoNodo;
			NuevoNodo->siguiente=aux1;
			NuevoNodo->anterior=aux2;
		}
		
		printf("\nEl dato se ha agregado ordenado correctamente.");
		
	} else {
		bool primero=false;
		if(PNCdobleI==NULL){
			primero=true;
		}
		
		NodoCirculardoble* NuevoNodo = (NodoCirculardoble*)malloc(sizeof(NodoCirculardoble));
		NuevoNodo->dato = Ndato;
		NuevoNodo->siguiente = PNCdobleI;
		NuevoNodo->anterior = NULL;
		PNCdobleI = NuevoNodo;
		if(primero)PNCdobleF = NuevoNodo;
		
		printf("\nEl dato se ha agregado correctamente.");
	}
}

void QuitarElementoASimple(){
	
	if(PNsimple==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoSimple* aux = PNsimple;
	int da = aux->dato;
	PNsimple = aux->siguiente;
	free(aux);
	printf("\nSe ha eliminado el elemento : %d de la lista.",da);
}

void QuitarElementoADoble(){
	if(PNdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoDoble* aux = PNdobleI;
	int da = aux->dato;
	PNdobleI = aux->siguiente;
	free(aux);
	aux=PNdobleI;
	aux->anterior=NULL;
	printf("\nSe ha eliminado el elemento : %d de la lista.",da);
}

void QuitarElementoACircularsimple(){
	if(PNcircularI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoCircularsimple* aux = PNcircularI;
	int da = aux->dato;
	PNcircularI = aux->siguiente;
	free(aux);
	aux=PNcircularI;
	printf("\nSe ha eliminado el elemento : %d de la lista.",da);
}

void QuitarElementoACirculardoble(){
	if(PNCdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoCirculardoble* aux = PNCdobleI;
	int da = aux->dato;
	PNCdobleI = aux->siguiente;
	free(aux);
	aux=PNCdobleI;
	printf("\nSe ha eliminado el elemento : %d de la lista.",da);
}

void MostrarListaSimple(){
	if(PNsimple==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoSimple* aux = PNsimple;
	
	while(aux!=NULL){
		printf("\n %d",aux->dato);
		aux=aux->siguiente;
	}
}

void MostrarListaDoble(){
	if(PNdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoDoble* aux = PNdobleI;
	
	while(aux!=NULL){
		printf("\n %d",aux->dato);
		aux=aux->siguiente;
	}
}
void MostrarListaCircularsimple(){
	if(PNcircularI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoCircularsimple* aux = PNcircularI;
	
	while(aux!=NULL){
		printf("\n %d",aux->dato);
		aux=aux->siguiente;
	}
}

void MostrarListaCirculardoble(){
	if(PNCdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	
	NodoCirculardoble* aux = PNCdobleI;
	
	while(aux!=NULL){
		printf("\n %d",aux->dato);
		aux=aux->siguiente;
	}
}

void BuscarEnListaSimple(){
	if(PNsimple==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	int datob;
	printf("Ingrese el numero que desee buscar : ");scanf("%d",&datob);
	NodoSimple* aux = PNsimple;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datob){
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado en la pocision %d",posc);
	}else {
		printf("\n El dato no ha sido encontrado.");
	}
}

void BuscarEnListaDoble(){
	if(PNdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	int datob;
	printf("Ingrese el numero que desee buscar : ");scanf("%d",&datob);
	NodoDoble* aux = PNdobleI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datob){
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado en la pocision %d",posc);
	}else {
		printf("\n El dato no ha sido encontrado.");
	}
}

void BuscarEnListaCircularsimple(){
	if(PNcircularI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	int datob;
	printf("Ingrese el numero que desee buscar : ");scanf("%d",&datob);
	NodoCircularsimple* aux = PNcircularI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datob){
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado en la pocision %d",posc);
	}else {
		printf("\n El dato no ha sido encontrado.");
	}
}

void BuscarEnListaCirculardoble(){
	if(PNCdobleI==NULL){
		printf("\nLa lista se encuentra vacia.");
		return;
	}
	int datob;
	printf("Ingrese el numero que desee buscar : ");scanf("%d",&datob);
	NodoCirculardoble* aux = PNCdobleI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datob){
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado en la pocision %d",posc);
	}else {
		printf("\n El dato no ha sido encontrado.");
	}
}

void ModificarEnListaSimple(){
	int datoViejo,Datonuevo;
	printf("Ingrese el numero que desee modificar de la lista : ");scanf("%d",&datoViejo);
	printf("Ingrese el numero que desee insertar en la lista : ");scanf("%d",&Datonuevo);
	
	NodoSimple* aux = PNsimple;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datoViejo){
			aux->dato = Datonuevo;
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado y modificado correctamente.");
	}else {
		printf("\n El dato no ha sido encontrado y por ende no modificado.");
	}
	
}

void ModificarEnListaDoble(){
	int datoViejo,Datonuevo;
	printf("Ingrese el numero que desee modificar de la lista : ");scanf("%d",&datoViejo);
	printf("Ingrese el numero que desee insertar en la lista : ");scanf("%d",&Datonuevo);
	
	NodoDoble* aux = PNdobleI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datoViejo){
			aux->dato = Datonuevo;
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado y modificado correctamente.");
	}else {
		printf("\n El dato no ha sido encontrado y por ende no modificado.");
	}
}

void ModificarEnListaCircularsimple(){
	int datoViejo,Datonuevo;
	printf("Ingrese el numero que desee modificar de la lista : ");scanf("%d",&datoViejo);
	printf("Ingrese el numero que desee insertar en la lista : ");scanf("%d",&Datonuevo);
	
	NodoCircularsimple* aux = PNcircularI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datoViejo){
			aux->dato = Datonuevo;
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado y modificado correctamente.");
	}else {
		printf("\n El dato no ha sido encontrado y por ende no modificado.");
	}
}

void ModificarEnListaCirculardoble(){
	int datoViejo,Datonuevo;
	printf("Ingrese el numero que desee modificar de la lista : ");scanf("%d",&datoViejo);
	printf("Ingrese el numero que desee insertar en la lista : ");scanf("%d",&Datonuevo);
	
	NodoCirculardoble* aux = PNCdobleI;
	int posc=1;bool encontrado=false;
	while(aux!=NULL){
		if(aux->dato==datoViejo){
			aux->dato = Datonuevo;
			encontrado=true;
			break;
		}
		
		aux=aux->siguiente;
		posc++;
	}
	
	if(encontrado){
		printf("\n El dato ha sido encontrado y modificado correctamente.");
	}else {
		printf("\n El dato no ha sido encontrado y por ende no modificado.");
	}
}





