#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "color.h"
#include "marca.h"
#include "auto.h"
#include "servicios.h"
#include "trabajo.h"
#include "informes.h"

#define TAM 9
#define TAMM 5
#define TAMC 5
#define TAMHARD 8
#define TAMS 4
#define TAMTRAB 7
#define TAMHARDT 6

void hardCodearTrabajos(eTrabajo vec[], int tam);

int main()
{
char respuesta;
char seguir = 's';

eAuto autos[TAM];
eTrabajo trabajo[TAMTRAB];
eMarca marcas[TAMM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
eServicio servicios[TAMS] ={
        {20000,"Lavado",250},
        {20001,"Pulido",300},
        {20002,"Encerado",400},
        {20003,"Completo",600},
    };

inicializarTrabajo(trabajo,TAMTRAB);
inicializarAutos(autos,TAM);
hardCodearTrabajos(trabajo, TAMHARDT);
int idTrab=50 + TAMHARDT;
int flag=-1;

if(hardcodeo(autos,TAMHARD))
{
        flag=1;

}
int idAuto=1000 + TAMHARD;

do
{

switch(menuOpciones())
        {
        case 'a':
           if(altaAuto(autos,TAM,colores,TAMC,marcas,TAMM,idAuto)){
                flag=1;
                idAuto++;
           }
            break;
        case 'b':
             if(flag==-1)
            {
                printf("Primero debe dar de alta un auto\n");

            }else
            {
               modificarAuto(autos,TAM,marcas,TAMM,colores,TAMC);
            }
            break;
        case 'c':
            if(flag==-1)
            {
                printf("Primero debe dar de alta un auto\n");

            }else
            {
                bajaAuto(autos,TAM,marcas,TAMM,colores,TAMC);
            }
           break;
        case 'd':
            ordenar(autos,TAM);
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
            if(altaTrabajo(idTrab,trabajo,TAMTRAB,autos,TAM,servicios,TAMS,marcas,TAMM,colores,TAMC)){
               idTrab++;
            }

            break;
        case 'i':
           mostrarTrabajos(trabajo,TAMTRAB,servicios,TAMS);
            break;
        case 'j':
            informes(autos,TAM,colores,TAMC,marcas,TAMM,trabajo,TAMTRAB,servicios,TAMS);
            break;
        case 'k':
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


void hardCodearTrabajos(eTrabajo vec[], int tam)
{
    eTrabajo trabajo [8]=
    {

        {"CAI202",20000,50,0,{12,3,2019}},
        {"LOL431",20000,51,0,{2,4,2019}},
        {"IND666",20001,52,0,{7,1,2019}},
        {"ROJ201",20002,53,0,{9,11,2019}},
        {"BKD999",20003,54,0,{12,12,2019}},
        {"LOA495",20001,55,0,{21,7,2019}},
        {"SAW123",20002,56,0,{21,7,2019}},
        {"JBV555",20003,57,0,{21,7,2019}},

    };

    for(int i=0; i<tam; i++)
    {
        vec[i]= trabajo[i];
    }
}
