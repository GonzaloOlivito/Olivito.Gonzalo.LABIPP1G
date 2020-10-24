#include "marca.h"
#include "color.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{
int id;
char patentes[10];
int isEmpty;
int modelo;
int idMarca;
int idColor;
} eAuto;

#endif // AUTO_H_INCLUDED

char menuOpciones();
void inicializarAutos(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int buscarAuto(int id, eAuto vec[], int tam);
int altaAuto(eAuto vec[], int tam, eColor colores[], int tamc, eMarca marcas[], int tamM, int idAuto);
void mostrarAuto (eAuto unAuto, eMarca marcaAuto[], int tamM, eColor colorAuto[], int tamC);
void mostrarAutos (eAuto vec[], int tam, eMarca marcaAuto[], int tamM, eColor colorAuto[], int tamC);
int hardcodeo(eAuto vec[], int tam);
int modificarAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamc);
int bajaAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamc);
void ordenar(eAuto vec[], int tam);
int buscarPatente(eAuto vec[], int tam, char patenteAux[]);

