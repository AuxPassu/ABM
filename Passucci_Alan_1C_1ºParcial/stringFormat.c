#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"

void changeFirstToUpper(char str[])
{   //Paso todo a minusculas, luego a mayuscula la primer letra, si hay un espacio, pongo en mayuscula la siguiente letra.
    strlwr(str);
    str[0] = toupper(str[0]);
    int i = 0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            str[i+1]= toupper(str[i+1]);
        }
        i++;
    }
}

void changeStringToUpper (char str[])
{
    int i = 0;
    while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}

void changeStringToLower (char str[])
{
    int i = 0;
    while(str[i] != '\0'){
        str[i] = tolower(str[i]);
        i++;
    }
}


