#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"

int getRandomNumber(int from, int to, int init)
{   //Obtengo un numero aleatorio a partir de rand y srand.
    int randomNumber;
    if (init)
    {
        srand (time(NULL));
    }   //Establezco rango y un numero inicial.
    randomNumber = from + (rand() % (to + 1 - from));
    return randomNumber;
}

int validateFloatNumber(char str[])
{   //Valido si el numero es flotante fijandome si tiene punto y son solo numeros.
    int isValid = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '.')
        {
            isValid = 1;
        }
        if (str[i]<'0'||str[i]>'9')
        {
            isValid = 0;
        }
        i++;
    }
    return isValid;
}

int validateIntNumber(char str[])
{   //isdigit() toma un char como argumento y devuelve 1 si es un digito, cero si no lo es.
    int i, j, isValid = 1;
    j = strlen(str);
    i = 0;
    while(i < j && isValid == 1)
    {   //Jugando con esto, puedo darme cuenta si se trata de un numero o no.
        if(isdigit(str[i]) != 0)
        {
            i++;
        }
        else
        {
            isValid = 0;
        }
    }
    return isValid;
}

int validateString(char str[])
{   //Valido si se trata de un string sin numeros y contando espacios.
    int i;
    int isValid = 1;
    i = 0;
    while(str[i]!='\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ')
        {
            isValid = 0;
        }
        i++;
    }
    return isValid;
}

int validatePhoneNumber(char str[])
{   //Valido si se trata de un numero de telefono, fijandome si solo hay numeros, espacios o guiones.
    int hyphenCounter = 0;
    int flag = 0; //Bandera que me permite saber si solo posee numeros y guiones.
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
        {
            flag = -1;
        }
        if (str[i] == '-')
        {
            hyphenCounter++; //Cuento los guiones.
        }
    }
    if(flag == 0 && hyphenCounter != 0)
    {
        flag = 1;
    }
    return flag;
}

unsigned long int getFactorial(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    return n * getFactorial(n - 1);
}

int validateIntOrFloat(float n)
{   //Calculo la resta entre un entero y flotante.
    int number = (int)n, isInt = 0;
    if(n - number == 0){
        isInt = 1;
    }
    return isInt;
}

int determinatePrime(int number)
{
    int i, cont = 0, isPrime = 0;
    for(i=1; i<=number; i++)
    {   //Divido entre todos los numeros menores a mi numero para saber si es primo.
        if(number % i == 0)
        {
            cont++;
        }
    }
    if(cont == 2)
    {
        isPrime = 1;
    }
    return isPrime;
}
/* Funcion original que imprime la lista completa de empleados
void employee_printEmployees(sEmployee listE[], int sizeE, sSector listS[], int sizeS)
{
    int i = 0;
    printf("----------------------------------------------------------------------------------------\n");
    printf("%10s %20s %20s %10s %20s\n", "Legajo", "Nombre", "Apellido", "Salario", "Sector");
    printf("----------------------------------------------------------------------------------------\n");
    for(i=0; i<sizeE; i++)
    {
        if(listE[i].isEmpty == BUSY)
        {
            employee_printOneEmployee(listE[i], listS, sizeS, 0);
        }
    }
    printf("\n");
}
*/

/*
void mostrarEmpleadosPorSector(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i, j;
    for(i=0; i<ts; i++)
    {
        printf("\n%s:\n\n", sectores[i].descripcion);
        for(j=0; j<tam; j++)
        {
            if(lista[j].idSector == sectores[i].idSector && lista[j].estado == OCUPADO)
            {
                printf("%d - %s - %c - %.2f - %.2f\n", lista[j].legajo, lista[j].nombre, lista[j].sexo, lista[j].sueldoBruto, lista[j].sueldoNeto);
            }
        }
    }
    printf("\n");
    system("pause");
}
*/

/*
int numeros[] = {4,2,3,1,5};
int i = 0, pos, aux;
Ordenamiento por Insercion
for(i=0; i<5; i++)
{
    pos = i;
    aux = numeros[i];
    while(pos > 0 && numeros[pos-1] > aux)
    {
        numeros[pos] = numeros[pos-1];
        pos--;
    }
    numeros[pos] = aux;
}
*/

