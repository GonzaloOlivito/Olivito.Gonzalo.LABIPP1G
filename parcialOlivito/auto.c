#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "utn.h"
#include "hardcodeo.h"
#include "marca.h"
#include "color.h"

/** \brief Funcion que engloba todas las opciones del programa
 *
 * \return devuelve la opcion ingresada
 *
 */
char menuOpciones()
{
    char opcion;
    system("cls");

    printf("BIENVENIDO \n\n");
    printf("A.Alta auto\n");
    printf("B.Modificar auto\n");
    printf("C.Baja auto\n");
    printf("D.Lista auto\n");
    printf("E.Listar marca\n");
    printf("F.Listar colores\n");
    printf("G.Listar Servicios\n");
    printf("H.Alta trabajo\n");
    printf("I.Mostrar trabajos\n");
    printf("J.Salir\n");
    printf("Ingrese la opcion deseada: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

/** \brief Funcion que inicializa todas los autos vacias en 1
 *
 * \param vec[] eAuto Recibe el vector de autos
 * \param tam int El tamaño del vector
 * \return No retorna nada
 *
 */
void inicializarAutos(eAuto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

/** \brief Funcion que busca lugar libre en el vector
 *
 * \param vec[] eAuto Recibe el vector de autos
 * \param tam int Tamaño del vector
 * \return int retorna -1 en caso de error o el lugar libre en el vector
 *
 */
int buscarLibre(eAuto vec[], int tam)
{
    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
/** \brief Funcion que busca un auto por ID
 *
 * \param Se ingresa el id a buscar
 * \param Se busca en el vector
 * \return Retorna -1 en caso de no encontrarlo o el vector posicion en caso de encontrarlo
 *
 */

int buscarAuto(int id, eAuto vec[], int tam)
{

    int retorno = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id == id)
        {
            retorno = i;
            break;
        }

    }
    return retorno;
}

int altaAuto(eAuto vec[], int tam, eColor colores[], int tamc, eMarca marcas[], int tamM)
{
    system("cls");
    printf("**ALTA AUTO**\n\n");
    int todoOk=0;
    int libre=buscarLibre(vec,tam);
    int esta;
    int id;
    if(libre==-1)
    {
        printf("No hay lugar\n");
    }
    else
    {
        getIntRange(&id,0,9999,"Ingrese id (entre 0 y 9999): ");
        esta=buscarAuto(id,vec,tam);
        if(esta==-1)
        {
            vec[libre].id=id;
            getIntRange(&vec[libre].modelo,1950,2020,"Ingrese el modelo del auto: ");
            printf("\n");
            listarMarcas(marcas,tamM);
            getIntRange(&vec[libre].idMarca,1000,1004,"Ingrese el id tipo: ");
            printf("\n");
            listarColores(colores,tamc);
            getIntRange(&vec[libre].idColor,5000,5004,"Ingrese el id color: ");
            getStringAlphaNum(20,"Ingrese la patente del auto(xxx 000):", vec[libre].patentes);

            vec[libre].isEmpty=0;
            todoOk=1;
            printf("\nAlta exitosa! \n");
        }
        else
        {
            printf("El id ya esta registrado, reintente.\n");
        }
    }

    return todoOk;
}

void mostrarAuto (eAuto unAuto, eMarca marcaAuto[], int tamM, eColor colorAuto[], int tamC)
{
    char marcaDes[20];
    char colorDes[20];
    cargarDescripcionMarca(unAuto.idMarca,marcaDes,marcaAuto,tamM);
    cargarDescripcionColor(unAuto.idColor,colorDes,colorAuto,tamC);
    printf("%d %10s%10s %10s    %d \n",unAuto.id,marcaDes,colorDes,unAuto.patentes,unAuto.modelo);
}

void mostrarAutos (eAuto vec[], int tam, eMarca marcaAuto[], int tamM, eColor colorAuto[], int tamC)
{
    system("cls");
    printf("** LISTADO AUTOS ** \n\n");
    printf("ID      MARCA      COLOR     PATENTE   MODELO     \n");
    int flag=-1;
    for(int i =0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarAuto(vec[i],marcaAuto,tamM,colorAuto,tamC);
            flag=1;
        }
    }
    if(flag==-1)
    {
        printf("No hay autos que mostrar\n\n");
    }
}


int hardcodeo(eAuto vec[], int tam)
{
    int retorno=-1;
    for(int i=0; i<tam; i++)
    {
        vec[i].id=ids[i];
        vec[i].idColor=idsColor[i];
        vec[i].idMarca=idsMarca[i];
        vec[i].modelo=modelos[i];
        strcpy(vec[i].patentes,patentes[i]);
        vec[i].isEmpty=0;
        retorno=1;
    }
    return retorno;
}


int modificarAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamc)
{
    int id;
    int eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU MODIFICACION***\n\n");
    mostrarAutos(vec,tam,marca,tamM,color,tamc);

    getIntRange(&id,0,9999,"Ingrese el id a modificar: ");
    esta=buscarAuto(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    }
    else
    {
        system("cls");
        printf("ID      MARCA      COLOR     PATENTE   MODELO     \n");
        mostrarAuto(vec[esta],marca,tamM,color,tamc);
        printf("1. Modificar color\n");
        printf("2. Modificar modelo\n");
        getIntRange(&eleccion,1,2,"Ingrese la opcion a modificar: ");
        switch(eleccion)
        {
        case 1:
            listarColores(color,tamc);
            getIntRange(&vec[esta].idColor,5000,5004, "Ingrese el ID del nuevo color: ");

            break;
        case 2:
            getIntRange(&vec[esta].modelo,1950,2020,"Ingrese el nuevo modelo: ");

            break;

        }
        printf("Modificacion realizada con exito!! \n");

        retorno = 1;
    }

    return retorno;
}


int bajaAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamc)
{
    int id;
    char eleccion;
    int retorno=-1;
    int esta;
    system("cls");
    printf("***MENU BAJA***\n\n");
   mostrarAutos(vec,tam,marca,tamM,color,tamc);

    getIntRange(&id,0,9999,"Ingrese el id a dar de baja: ");
    esta=buscarAuto(id,vec,tam);
    if(esta== -1)
    {
        printf("Id mal ingresado, reintente.");
    }
    else
    {
        system("cls");
        printf("\nSelecciono: \n");
        printf("ID      MARCA      COLOR     PATENTE   MODELO     \n");
        mostrarAuto(vec[esta],marca,tamM,color,tamc);
        getChar(3,&eleccion,"Confirma baja? s/n: ");
        if(eleccion == 's')
        {
            vec[esta].isEmpty=1;
            printf("Baja realizada con exito");
            retorno = 1;
        }
    }
    return retorno;
}

void ordenar(eAuto vec[], int tam)
{
    eAuto aux;

    for(int i = 0 ; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].idMarca>vec[j].idMarca)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(vec[i].idMarca==vec[j].idMarca && stricmp(vec[i].patentes, vec[j].patentes)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

