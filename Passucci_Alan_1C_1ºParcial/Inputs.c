#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"

int getInt(char message[])
{   //Pido entero.
    int number;
    printf("Ingrese %s: ", message);
    scanf("%d", &number);
    return number;
}

float getFloat(char message[])
{   //Pido numero decimal.
    float number;
    printf("Ingrese %s: ", message);
    scanf("%f", &number);
    return number;
}

char getChar(char message[])
{   //Pido un caracter.
    char character;
    printf("Ingrese %s: ", message);
    fflush(stdin);
    scanf("%c", &character);
    return character;
}

void getString(char message[], char str[])
{   //Pido un string.
    printf("Ingrese %s: ", message);
    fflush(stdin);
    scanf("%[^\n]", str);
}

void getValidString(char message[], char str[], int ssize)
{   //Realizo las validaciones correspondientes utilizando un auxiliar.
    char auxStr[256];
    getString(message, auxStr);
    while(strlen(auxStr) > ssize || validateString(auxStr) == 0)
    {
        printf("Error. ");
        getString(message, auxStr);
    }
    strcpy(str, auxStr);
}

int getValidInt(char message[], int low, int high, int format)
{   //Realizo las validaciones correspondientes utilizando auxiliares.
    char auxStr[256];
    int auxInt;
    int finalInt;
    getString(message, auxStr);
    auxInt = atoi(auxStr); //atoi() toma una cadena y convierte a entero si solo hay numeros, caso contrario devuelve cero.
    if(format == 0)
    {   //Si trabajo con formato cero, estoy usando rangos.
        while((auxInt < low || auxInt > high) || (strlen(auxStr) > 51) || (validateIntNumber(auxStr) == 0) || (validateString(auxStr)))
        {
            printf("Error. ");
            getString(message, auxStr);
            auxInt = atoi(auxStr);
        }
    }
    finalInt = auxInt;
    return finalInt;
}

float getPositiveFloat(char message[], float low, float high)
{   //Realizo las validaciones correspondientes utilizando auxiliares.
    char auxStr[256];
    double auxFloat;
    float finalFloat;
    getString(message, auxStr);
    auxFloat = atof(auxStr); //atof() hace lo mismo que atoi() pero con flotantes, la diferencia es que lo devuelve como double.
    while(auxFloat < low || auxFloat > high)
    {   //Si no respeta rango, tiro error.
        printf("Error. ");
        getString(message, auxStr);
        auxFloat = atof(auxStr);
    }
    finalFloat = (float)auxFloat; //Por ultimo, paso de double a float.
    return finalFloat;
}

