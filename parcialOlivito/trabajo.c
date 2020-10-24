#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trabajo.h"
#include "auto.h"
#include "servicios.h"
#include "utn.h"
#include "marca.h"

void inicializarTrabajo(eTrabajo trabajos[], int tamtrab)
{

    for(int i=0; i<tamtrab; i++)
    {

            trabajos[i].isEmpty=1;

    }
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tamtrab)
{
    int retorno=-1;

    for(int i=0; i<tamtrab; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            retorno=i;
            break;
        }


    }

    return retorno;
}

int altaTrabajo(int idTrabajo, eTrabajo trabajos[], int tamtrab, eAuto vec[], int tam, eServicio servicios[], int tams, eMarca marcas[],
                int tamM, eColor colores[], int tamc)
{
    system("cls");
    printf("**ALTA TRABAJO**\n\n");
    int retorno=0;
    char patenteAux[20];
    int libre=buscarLibreTrabajo(trabajos,tamtrab);

        mostrarAutos(vec,tam,marcas,tamM,colores,tamc);
        getStringAlphaNum(20,"Ingrese la patente(XXX123):",patenteAux);
        int indicePatente=buscarPatente(vec,tam,patenteAux);
        if(indicePatente==-1)
        {
            printf("Patente mal ingresada o inexistente. Reintente");
        }
        else
            if(libre==-1)
        {
            printf("No hay mas lugar");
        }else
        {
            strcpy(trabajos[libre].patente, patenteAux);
            listarServicios(servicios,tams);
            getIntRange(&trabajos[libre].idServicio,20000,20003,"Ingrese el ID del servicio a realizar: " );
            trabajos[libre].idTrabajo=idTrabajo;
            getIntRange(&trabajos[libre].fecha.dia,0,31,"Ingrese el dia: ");
            getIntRange(&trabajos[libre].fecha.mes,0,12,"Ingrese el mes: ");
            getIntRange(&trabajos[libre].fecha.anio,1950,2020,"Ingrese el anio (entre 1950 y 2020): ");

            trabajos[libre].isEmpty=0;

            retorno=1;
            printf("\nAlta de trabajo exitosa! \n");
        }

    return retorno;
}

void mostrarTrabajo (eTrabajo trabajo, eServicio servicios[], int tams)
{
    char servicioDes[20];
    cargarDescripcionServicio(servicios,tams,trabajo.idServicio,servicioDes);
    printf("%4d    %10s  %10s    %.2d/%.2d/%d\n", trabajo.idTrabajo,trabajo.patente,servicioDes,trabajo.fecha.dia,trabajo.fecha.mes
                                                                                                            ,trabajo.fecha.anio);
}

void mostrarTrabajos (eTrabajo trabajos[], int tamtrab, eServicio servicios[], int tams)
{
    system("cls");
    printf("** LISTADO TRABAJOS ** \n\n");
    printf("ID TRABAJO  PATENTE  SERVICIO  PRECIO  FECHA\n");

    for(int i =0; i<tamtrab; i++)
    {

        if(trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i],servicios,tams);

        }
    }

}

int hardcodeoTrab(eAuto vec[], int tam, eTrabajo trabajos[], int tamt)
{
    int retorno=-1;
    for(int i=0; i<tamt; i++)
    {

        vec[i].isEmpty=0;
        retorno=1;
    }
    return retorno;
}


