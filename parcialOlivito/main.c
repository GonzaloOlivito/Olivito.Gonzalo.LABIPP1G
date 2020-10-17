#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "auto.h"
#include "servicios.h"
#include "trabajo.h"

#define TAM 9
#define TAMM 5
#define TAMC 5
#define TAMHARD 6
#define TAMS 4
#define TAMTRAB 3
int main()
{

char respuesta;
char seguir = 's';
int idTrab=50;
eAuto autos[TAM];
eMarca marcas[TAMM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
eServicio servicios[TAMS] ={
        {20000,"Lavado",250},
        {20001,"Pulido",300},
        {20002,"Encerado",400},
        {20003,"Completo",600},
    };
eTrabajo trabajos[TAMTRAB];
inicializarAutos(autos,TAM);
inicializarTrabajo(trabajos,TAMTRAB);

int flag=-1;
if(hardcodeo(autos,TAMHARD))
{
        flag=1;
}
do
{

switch(menuOpciones())
        {
        case 'a':
           if(altaAuto(autos,TAM,colores,TAMC,marcas,TAMM)){
                flag=1;
           }
            break;
        case 'b':
             if(flag==-1)
            {
                printf("Primero debe dar de alta un auto\n");

            }else
            {
               modificarAuto(autos,TAMC,marcas,TAMM,colores,TAMC);
            }
            break;
        case 'c':
            if(flag==-1)
            {
                printf("Primero debe dar de alta un auto\n");

            }else
            {
                bajaAuto(autos,TAMC,marcas,TAMM,colores,TAMC);
            }
           break;
        case 'd':
            ordenar(autos,TAMC);
            mostrarAutos(autos,TAM,marcas,TAMM,colores,TAMC);
            break;
        case 'e':
            system("cls");
            printf("***LISTA DE MARCAS***\n");
            listarMarcas(marcas,TAMM);
           break;
        case 'f':
            system("cls");
            printf("***LISTA DE COLORES***\n");
           listarColores(colores,TAMC);
            break;
        case 'g':
           system("cls");

           listarServicios(servicios,TAMS);
            break;
        case 'h':
           altaTrabajo(idTrab,trabajos,TAMTRAB,autos,TAM,servicios,TAMS,marcas,TAMM,colores,TAMC);
            break;
        case 'i':
           mostrarTrabajos(trabajos,TAMTRAB,servicios,TAMS);
            break;
        case 'j':
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
    }while(seguir == 's');
    return 0;


return 0;
}
