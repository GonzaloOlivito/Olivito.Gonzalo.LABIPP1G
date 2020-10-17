#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"

/** \brief Lista las marcas de los autos
 *
 * \param marcas[] eMarca
 * \param tamM int
 * \return void
 *
 */
void listarMarcas(eMarca marcas[], int tamM)
{
    printf("ID      MARCA\n");
  for(int i=0;i<tamM;i++)
    {
        printf("%d   %6s \n", marcas[i].id,marcas[i].nombreMarca);
    }
}

/** \brief Compara los ids y le carga el nombre del color a traves del id
 *
 * \param id int
 * \param nombreColor[] char
 * \param color[] eColor
 * \param tamc int
 * \return int
 *
 */
int cargarDescripcionMarca(int id, char nombreMarca[],eMarca marcas[], int tamM)
{
    int retorno = -1;
    for(int i=0;i<tamM;i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(nombreMarca,marcas[i].nombreMarca);
            retorno = 1;
        }
    }

    return retorno;
}
