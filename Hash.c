#include "Hash.h"

void CrearTabla(TABLADISPERSION *T){
	int i;
	for(i=0; i<TAM; i++){
		T->Tabla[i]=NULL;
	}
	T->elementos=0;
}

long funcionHash(char *clave){
	long p=0;
	int i;
	for(i=0; i<strlen(clave); i++){
		p=p*31+clave[i];
	}
	p=abs(p);
	return p;
}

int direccion(TABLADISPERSION *T, char *clave){
	long p=funcionHash(clave);
	int i=1;
	p=p%TAM;
	while(T->Tabla[i]!=NULL && strcmp(T->Tabla[i]->bol, clave)){
		p=p+i*i;
		p=p%TAM;
		i++;
	}
	return (int) p;
}

void insertarReg(TABLADISPERSION *T, ALUMNO A){
	int dir=direccion(T, A.bol);
	ALUMNO *B=(ALUMNO *)malloc(sizeof(ALUMNO));
	strcpy(B->nm, A.nm);
	strcpy(B->bol, A.bol);
	B->edad=A.edad;
	B->alta=1;
	T->Tabla[dir]=B;
	T->elementos++;
}

void eliminarReg(TABLADISPERSION *T, char *clave){
	int dir=direccion(T, clave);
	if(T->Tabla[dir]!=NULL && T->Tabla[dir]->alta==1){
		T->Tabla[dir]->alta=0;
		T->elementos--;
	}
}

void mostrarAlumno(ALUMNO a){
	printf("Nombre: %s\nBoleta: %s\nEdad: %d\n\n", a.nm, a.bol, a.edad);
}

void buscar(TABLADISPERSION *T, char *clave){
	int dir=direccion(T, clave);
	if(T->Tabla[dir]!=NULL && T->Tabla[dir]->alta==1){
		mostrarAlumno(*(T->Tabla[dir]));
	}
}

void mostrarTabla(TABLADISPERSION *T){
	int i;
	for(i=0; i<TAM; i++){
		if(T->Tabla[i]!=NULL && T->Tabla[i]->alta==1){
			mostrarAlumno(*(T->Tabla[i]));
		}
	}
}
