
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicios.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;

}eFecha;

typedef struct{
char patente[20];
int idServicio;
int idTrabajo;
int isEmpty;
eFecha fecha;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

void inicializarTrabajo(eTrabajo trabajos[], int tamtrab);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamtrab);
int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtrab, eAuto vec[], int tam, eServicio servicios[], int tams, eMarca marcas[],
                int tamM, eColor colores[], int tamc);

void mostrarTrabajo (eTrabajo trabajo, eServicio servicios[], int tams);
void mostrarTrabajos (eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams);
int hardcodeoTrabajo(eAuto vec[], int tam, eTrabajo trabajos[],int tamt);
