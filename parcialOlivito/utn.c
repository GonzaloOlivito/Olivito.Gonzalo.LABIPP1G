#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int confimarSalir(char* mensaje)
{
    int retorno;
    char confirma;

    printf("%s",mensaje);
    fflush(stdin);
    confirma=getchar();
    confirma=tolower(confirma);

    while(confirma != 's' && confirma != 'n')
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        confirma=getchar();
        confirma=tolower(confirma);
    }

    if(confirma == 's')
    {
        retorno = 1;
    }
    else
    {
        retorno =0;
    }

    return retorno;

}

void getStringAlpha(int longMax, char* mensaje, char* dondeAsignar)
{

    char aux[longMax];

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while((isalpha(aux[i])==0) || strlen(aux) > longMax)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    strlwr(aux);
    aux[0]=toupper(aux[0]);

    strcpy(dondeAsignar, aux);

}

void getIntRange(int* dondeAsignar, int min, int max, char* mensaje)
{

    int auxInt;
    char aux[20];

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(aux);


    for(int i=0; i<strlen(aux); i++)
    {
        while(isdigit(aux[i])==0)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxInt=atoi(aux);

    while(auxInt < min || auxInt > max)
    {
        printf("Error. %s",mensaje);
          fflush(stdin);
        scanf("%d",&auxInt);
    }


    *dondeAsignar = auxInt;

}

void getSexo(char* dondeAsignar, char* mensaje)
{
    char aux;

    printf("%s",mensaje);
    fflush(stdin);
    aux=getchar();

    while(aux !='f' && aux!='m')
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        aux=getchar();
    }

        *dondeAsignar = aux;

}

int getChar(int intentos, char* dondeAsignar, char* mensaje)
{
    int todoOk = 1;
    char aux;

    printf("%s",mensaje);
    fflush(stdin);
    aux=getchar();

    while(isalpha(aux)==0)
    {
        intentos--;

        if(intentos == 0)
        {
            todoOk =0;
            break;
        }

        printf("Error. %s",mensaje);
        fflush(stdin);
        aux=getchar();
    }

    if(intentos != 0)
    {
        *dondeAsignar = aux;
    }

    return todoOk;

}

void getFloatRange(float min, float max, float* dondeAsignar, char* mensaje)
{
    float auxFloat;
    char aux[20];

    printf("%s",mensaje);
      fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while((isdigit(aux[i])==0))
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxFloat=atoi(aux);


    while(auxFloat < min || auxFloat > max)
    {
        printf("Error. %s",mensaje);
          fflush(stdin);
        scanf("%f",&auxFloat);
    }

        *dondeAsignar = auxFloat;

}

void getStringAlphaNum(int longMax, char* mensaje, char* dondeAsignar)
{
    char aux[longMax];
    int i=0;

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while( strlen(aux) > longMax)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    strlwr(aux);
    aux[0]=toupper(aux[0]);

    while( aux[i] != '\0')
    {
        if(aux[i] == ' ')
        {
            aux[i +1] = toupper(aux[i+1]);

        }
        i++;
    }

    strcpy(dondeAsignar, aux);

}

void pedirTelefono (char* var_dondeAsignar, int longitudMaxString, char* mensaje)
{

    int i;
    int invalido;
    char auxiliar[longitudMaxString];
    int len;

    do
    {

        invalido = 0;
        fflush(stdin);
        printf("%s\n",mensaje);
        fgets(auxiliar,longitudMaxString,stdin);
        len = (strlen(auxiliar)-1);

        if ( ( len < 8 ) || (len > longitudMaxString) )
        {
            invalido = 1;
        }
        else
        {

            for (i=0; i<strlen(auxiliar)-1; i++)
            {
                if (auxiliar[i]<'0' || auxiliar[i]>'9')
                {
                    invalido = 1;
                    break;
                };

            };
        };

        if (invalido == 1)
        {
            printf("\n*Telefono Invalido*\n");

        }

    }
    while (invalido == 1);

    //elimino saltos de linea//

    len = (strlen(auxiliar));

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';

    };

    strcpy(var_dondeAsignar,auxiliar);

    return;
}

void pedirEmail (char* var_dondeAsignar, int longitudMaxString, char* mensaje)
{

    int cantidadArrobas, cantidadPuntos, pusoArroba;
    int i;
    int invalido;
    char auxiliar[longitudMaxString];
    do
    {

        cantidadArrobas = 0, cantidadPuntos = 0, invalido = 0, pusoArroba = 0;
        fflush(stdin);
        printf("%s\n",mensaje);
        fgets(auxiliar,longitudMaxString,stdin);
        strlwr(auxiliar);

        for (i=0 ; i<strlen(auxiliar)-1 ; i++)
        {

            if (auxiliar[i] == ' ')
            {
                invalido = 1;
                break;
            };

            if (i==0 && (auxiliar[i] == '@' || auxiliar[i] == '.'))
            {
                invalido = 1;
                break;
            };

            if ( ((auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i]<'0' || auxiliar[i]>'9')) && (auxiliar[i] != '@') && (auxiliar[i] != '.') && (auxiliar[i] != '_') && (auxiliar[i] =! '-')  )
            {
                invalido=1;
                break;
            };

            if (auxiliar[i] == '@')
            {
                if (cantidadArrobas >= 1)
                {
                    invalido=1;
                    break;
                };
                pusoArroba = 1;
                cantidadArrobas ++;
            };

            if (auxiliar[i] == '.')
            {

                if (cantidadPuntos >= 1 || pusoArroba == 0)
                {
                    invalido = 1;
                    break;
                };
                cantidadPuntos ++;
            };

        } // for

        if(cantidadPuntos == 0 || pusoArroba == 0)
        {
            invalido = 1;
        };

        if ( invalido == 1 )
        {
            printf("\n*Mail invalido*\n");
        };

    }
    while (invalido == 1);

    //elimino saltos de linea//
    int len = strlen(auxiliar);

    if(auxiliar[len-1]=='\n')
    {

        auxiliar[len-1]='\0';
    };

    strcpy(var_dondeAsignar, auxiliar);

    return;
}
