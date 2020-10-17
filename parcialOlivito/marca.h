#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{
int id;
char nombreMarca[20];
}eMarca;


#endif // MARCA_H_INCLUDED
void listarMarcas(eMarca marcas[], int tamM);
int cargarDescripcionMarca(int id, char nombreMarca[],eMarca marcas[], int tamM);
