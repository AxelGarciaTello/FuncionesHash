#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1009

typedef struct alumno{
	char nm[30];
	char bol[10];
	int edad, alta;
} ALUMNO;

typedef ALUMNO* TipoDato;
typedef struct tabla{
	TipoDato Tabla[TAM];
	int elementos;
} TABLADISPERSION;

void CrearTabla(TABLADISPERSION *);
long funcionHash(char *);
int direccion(TABLADISPERSION *, char *);
void insertarReg(TABLADISPERSION *, ALUMNO);
void eliminarReg(TABLADISPERSION *, char *);
void mostrarAlumno(ALUMNO);
void bucar(TABLADISPERSION *, char *);
void mostrarTabla(TABLADISPERSION *);
