#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/** \brief Lista los colores de los autos
 *
 * \param colores[] eColor
 * \param tamc int
 * \return void
 *
 */
void listarColores(eColor colores[], int tamc)
{
    printf("ID      COLOR\n");
  for(int i=0;i<tamc;i++)
    {
        printf("%d   %6s \n", colores[i].id,colores[i].nombreColor);
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
int cargarDescripcionColor(int id, char nombreColor[],eColor color[], int tamc)
{
    int retorno = -1;
    for(int i=0;i<tamc;i++)
    {
        if(color[i].id == id)
        {
            strcpy(nombreColor,color[i].nombreColor);
            retorno = 1;
        }
    }

    return retorno;
}
