#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

/** \brief Funcion para listar los servicios
 *
 * \param servicios[] eServicio
 * \param tams int
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int tams)
{
    printf("    LISTA DE SERVICIOS\n");
    printf("  ID    SERVICIO   PRECIO\n");
    for(int i=0;i<tams;i++)
    {
        printf("%d   %8s   %.2f\n", servicios[i].id,servicios[i].descripcion,servicios[i].precio);
    }
}

/** \brief Funcion para cargar la descripcion de un servicio a traves de su id
 *
 * \param servicios[] eServicio
 * \param tams int
 * \param idServicio int
 * \param servicio[] char
 * \return void
 *
 */
void cargarDescripcionServicio(eServicio servicios[], int tams, int idServicio, char servicio[])
{
    for(int i=0;i<tams;i++)
    {
        if(idServicio==servicios[i].id)
        {
            strcpy(servicio,servicios[i].descripcion);
        }
    }
}
