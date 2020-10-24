#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "color.h"
#include "informes.h"
#include "marca.h"
#include "servicios.h"
#include "utn.h"
#include "trabajo.h"

/** \brief Funcion que abarca el submenu de informes y recibe todas las estructuras
 *
 * \param vec[] eAuto
 * \param tam int
 * \param colores[] eColor
 * \param tamc int
 * \param marcas[] eMarca
 * \param tamM int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void informes(eAuto vec[], int tam, eColor colores[], int tamc, eMarca marcas[], int tamM, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    char respuesta;
    char seguir='s';
    do
    {
        switch(menuInformes())
        {
        case 1:
            informarAutosPorColor(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;
        case 2:
            informarAutosPorMarca(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;
        case 3:
            informarAutoMasViejo(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;
        case 4:
            autosSeparadosPorMarca(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;
        case 5:
            autosListadosPorMarcaYColor(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
        case 6:
            trabajosUnAuto(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;
        case 7:
            importesPorAuto(vec,tam,marcas,tamM,colores,tamc,trabajos,tamT,servicios,tamS);
            break;

        case 8:
          printf("\nSeguro que desea salir?s/n: ");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta == 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir == 's');


}

/** \brief Funcion que contiene el subMenu de informes
 *
 * \return int
 *
 */
int menuInformes()
{
    int opcion;
    system("cls");
    printf("\n*** Informe Autos ***\n\n");
    printf("1. Informe autos por color seleccionado\n");
    printf("2. Informe autos por marca\n");
    printf("3. Informe auto mas viejo\n");
    printf("4. Informe autos por marca\n");
    printf("5. Informe cantidad de autos del mismo color y marca\n");
    printf("6. Trabajos realizados a un solo auto\n");
    printf("7. Mostrar importes totales de servicios por auto\n");
    printf("8. Salir  \n");

    printf("Ingrese una respuesta: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/** \brief Funcion que informa los autos separados por color
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void informarAutosPorColor(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    int idColor;
    char descriColor[20];
    system("cls");
    printf("***AUTOS POR COLOR***\n\n");

    listarColores(colores,tamC);
    getIntRange(&idColor,5000,5004,"Ingrese el ID del color de auto a seleccionar: ");
    cargarDescripcionColor(idColor,descriColor,colores,tamC);
    system("cls");
    printf("\nUsted eligio el color : %s\n", descriColor);
    printf("ID        MARCA    COLOR    PATENTE   MODELO     \n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(idColor == vec[i].idColor)
            {
               mostrarAuto(vec[i],marcas,tamM,colores,tamC);
            }
        }

    }

}

/** \brief Funcion que informa los autos filtrados por marca
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void informarAutosPorMarca(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    int idMarca;
    char descriMarca[20];
    system("cls");
    printf("***AUTOS POR MARCA***\n\n");

    listarMarcas(marcas,tamM);
    getIntRange(&idMarca,1000,1004,"Ingrese el ID de la marca del auto a seleccionar: ");
    cargarDescripcionMarca(idMarca,descriMarca,marcas,tamM);
    system("cls");
    printf("\nUsted eligio la marca : %s\n", descriMarca);
    printf("ID       MARCA    COLOR    PATENTE   MODELO     \n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(idMarca == vec[i].idMarca)
            {
               mostrarAuto(vec[i],marcas,tamM,colores,tamC);
            }
        }

    }

}

/** \brief Funcion que informa el auto mas viejo
 *
 * \param autos[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamC int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void informarAutoMasViejo(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    system("cls");
    printf("***AUTO MAS VIEJO***\n\n");

    float menor;
    int flag=0;
    for(int i=0; i<tam; i++)
    {
        if(autos[i].isEmpty==0)
        {
            if(menor > autos[i].modelo || flag == 0)
            {
               menor=autos[i].modelo;
               flag=1;
            }
        }
    }
       for(int i=0;i<tam;i++)
    {
        if(autos[i].modelo == menor && autos[i].isEmpty==0)
            {
                 printf("ID       MARCA    COLOR    PATENTE   MODELO     \n");
                  mostrarAuto(autos[i],marcas,tamM,colores,tamC);

                printf("\nEl auto mas viejo registrado es modelo: %0.f \n\n",menor);
            }
    }


}

/** \brief Funcion que separa los autos por marca
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamc int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void autosSeparadosPorMarca(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamc, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
      system("cls");
    printf("***AUTOS POR MARCA***\n\n");
    for(int t=0;t<tamM;t++)
    {

        printf("Marca: %s \n\n",marcas[t].nombreMarca);
        printf("ID       MARCA      COLOR    PATENTE   MODELO     \n");
        for(int b=0;b<tam;b++)
        {

            if(vec[b].idMarca==marcas[t].id)
            {

                mostrarAuto(vec[b],marcas,tamM,colores,tamc);
            }


        }
         printf("----------------------------------------------------------\n");
    }
}

/** \brief Funcion que lista los autos por marca y color
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamc int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void autosListadosPorMarcaYColor(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamc, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
    system("cls");
    int idMarca;
    int idColor;
    int contador=0;
    char descripMarca[20];
    char descripColor[20];
    system("cls");
    printf("   ****LISTADO DE AUTOS POR MARCA Y COLOR****\n\n");
    listarMarcas(marcas,tamM);
    getIntRange(&idMarca,1000,1004,"Ingrese el id de la marca del auto: ");
    listarColores(colores,tamc);
    getIntRange(&idColor,5000,5004,"Ingrese el id del color del auto: ");
    cargarDescripcionMarca(idMarca,descripMarca,marcas,tamM);
    cargarDescripcionColor(idColor,descripColor,colores,tamc);
    printf("ID       MARCA      COLOR    PATENTE   MODELO     \n");
    for(int i=0;i<tam;i++)
    {
        if(vec[i].isEmpty==0)
        {
            if(vec[i].idColor==idColor && vec[i].idMarca==idMarca)
            {

                contador++;
                 mostrarAuto(vec[i],marcas,tamM,colores,tamc);
            }
        }
    }

    printf("\n\nHay %d autos de la marca %s y color %s\n",contador,descripMarca,descripColor);

}

/** \brief Funcion que informa los trabajos realizados a un auto
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamc int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void trabajosUnAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamc, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{

    int indicePatente;
    char patente[7];

    mostrarAutos(vec,tam,marcas,tamM,colores,tamc);
    getStringAlphaNum(7,"Ingrese patente(XXX123):",patente);

    indicePatente=buscarPatente(vec, tam, patente );

    if(indicePatente == -1)
    {
        printf("Patente incorrecta!");
    }else
    {

        printf("\n ***TRABAJOS REALIZADOS*** \n");
        printf("   ID      PATENTE     TRABAJO     FECHA\n");

        for(int i=0; i<tamT; i++)
        {
            if(strcmp(trabajos[i].patente, patente)==0 && trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamS);
            }
        }
        printf("\n\n");
    }
}

/** \brief Funcion que informa el costo total de los trabajos realizados a un auto
 *
 * \param vec[] eAuto
 * \param tam int
 * \param marcas[] eMarca
 * \param tamM int
 * \param colores[] eColor
 * \param tamc int
 * \param trabajos[] eTrabajo
 * \param tamT int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void importesPorAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamc, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS)
{
  int indicePatente;
    char patente[7];
     int acumulador=0;

    mostrarAutos(vec,tam,marcas,tamM,colores,tamc);
    getStringAlphaNum(7,"Ingrese patente(XXX123):",patente);

    indicePatente=buscarPatente(vec, tam, patente );

    if(indicePatente == -1)
    {
        printf("Patente incorrecta!");
    }else
    {
        system("cls");
        printf(" ID       PATENTE    TRABAJO   FECHA");
        printf("\n");

        for(int i=0; i<tamT; i++)
        {
            for(int j=0; j<tamS; j++)
            {
                if(stricmp(trabajos[i].patente, patente)==0 && trabajos[i].idServicio==servicios[j].id)
                {
                    mostrarTrabajo(trabajos[i], servicios, tamS);
                    acumulador+=servicios[j].precio;
                }
            }
        }
        printf("\nImporte total: %d.\n\n", acumulador);
        system("pause");

    }
}
