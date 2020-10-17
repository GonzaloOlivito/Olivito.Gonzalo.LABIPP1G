#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct{
int id;
char descripcion[25];
float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED

void listarServicios(eServicio servicios[], int tamc);
void cargarDescripcionServicio(eServicio servicios[], int tams, int idServicio, char servicio[]);
