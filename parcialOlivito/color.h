#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
int id;
char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

void listarColores(eColor colores[], int tamc);
int cargarDescripcionColor(int id, char nombreColor[],eColor color[], int tamc);
