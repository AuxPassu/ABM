#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"
#define EMPTY 0
#define BUSY 1

void employee_initEmployees(sEmployee listE[], int sizeE)
{
    int i;
    for(i=0; i<sizeE; i++)
    {
        listE[i].isEmpty = EMPTY; //Dejo en libre todos los espacios de mi array de empleados.
    }
}

int employee_addEmployee(sEmployee listE[], int sizeE, sSector listS[], int sizeS)
{
    int loaded = -1, isSatisfied;
    int index = employee_searchEmpty(listE, sizeE); //Busco lugar libre en mi array de empleados.
    sSector sector; //Variable auxiliar de sector.
    if(index != -1) //Si hay lugar, empiezo a pedir datos de un empleado.
    {
        printf("Dando de alta un empleado...\n\n");
        listE[index].id = getRandomNumber(10000, 11000, 1); //Calculo de manera random el legajo del empleado.
        employee_getEmployeeName(listE, 51, index); //Llamo a la funcion que me permite pedir nombre.
        employee_getEmployeeLastName(listE, 51, index); //Llamo a la funcion que me permite pedir apellido.
        listE[index].salary = getPositiveFloat("salario", 1, 100000); //Pido un salario con rango 1-100000 (depedera completamente de que salario y moneda, por eso este rango).
        sector = sector_getSector(listS, sizeS); //Obtengo los datos del sector ingresado y lo vinculo al empleado.
        listE[index].sector = sector.id;
        isSatisfied = employee_verifyCompliance("'s' para confirmar el alta del empleado"); //Verifico la conformidad del usuario con esta alta.
        if(isSatisfied == 1)
        {   //Si esta satisfecho, el lugar pasa a estar ocupado e indico que se pudo cargar al empleado.
            listE[index].isEmpty = BUSY;
            loaded = 0;
        }
        else
        {
            printf("\nSe cancelo el alta del empleado.\n\n");
        }
    }
    else{
        printf("Error: No hay mas espacio libre.\n\n");
    }
    return loaded;
}

void employee_modifyEmployeeInfo(sEmployee listE[], int sizeE, sSector listS[], int sizeS)
{
    int option, idToFind, index, isSatisfied, found = 0;
    sEmployee auxEmp[sizeE]; //Creo un array auxiliar de empleados.
    sSector sector; //Variable auxiliar de sector.
    do
    {
        option = showMenu(" 1. Seleccionar empleado.\n 2. Modificar nombre.\n 3. Modificar apellido.\n 4. Modificar salario.\n 5. Modificar sector.\n 6. Atras."); //Creo un nuevo menu correspondiente a modificaciones.
        switch(option)
        {
            case 1:
                if(found == 1)
                {   //La variable found me ayuda a saber si se selecciono a un empleado para realizar modificaciones en sus datos.
                    printf("Empleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1); //Mostrare al empleado seleccionado actualmente al elegir cualquier opcion.
                    printf("\n");
                } //Ordeno y muestro la lista actual de empleados (por apellido y sector) para que se puedan visualizar todos los datos de los mismos.
                employee_sortEmployees(listE, sizeE, 1);
                employee_printEmployees(listE, sizeE, listS, sizeS);
                idToFind = getValidInt("ID del empleado a modificar datos", 10000, 11000, 0); //Pido el ID del empleado a modificar sus datos.
                index = employee_findEmployeeById(listE, sizeE, idToFind); //Lo busco.
                if(index != -1)
                {   //Si existe, tengo a un empleado seleccionado y listo para realizar modificaciones.
                    found = 1;
                    printf("\nEmpleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1);
                    printf("\n");
                }
                else
                {
                    printf("\nError: Empleado no encontrado.\n\n");
                }
                system("pause");
                break;
            case 2:
                if(found == 1)
                {   //Siempre y cuando haya seleccionado a un empleado, lo muestro y pido el nuevo nombre del mismo.
                    printf("Empleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1);
                    printf("\nModificando el nombre del empleado...\n\n");
                    employee_getEmployeeName(auxEmp, 51, index);
                    isSatisfied = employee_verifyCompliance("'s' para confirmar la modificacion"); //Pregunto si quiere realizar la modificacion.
                    if(isSatisfied == 1)
                    {   //Si el usuario esta satisfecho con la modificacion, actualizo el dato del empleado.
                        strcpy(listE[index].name, auxEmp[index].name);
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar un empleado.\n\n");
                }
                system("pause");
                break;
            case 3:
                if(found == 1)
                {   //Lo mismo que en el case 2.
                    printf("Empleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1);
                    printf("\nModificando el apellido del empleado...\n\n");
                    employee_getEmployeeLastName(auxEmp, 51, index);
                    isSatisfied = employee_verifyCompliance("'s' para confirmar la modificacion");
                    if(isSatisfied == 1)
                    {
                        strcpy(listE[index].lastName, auxEmp[index].lastName);
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar un empleado.\n\n");
                }
                system("pause");
                break;
            case 4:
                if(found == 1)
                {   //Los mismos pasos pero para el salario.
                    printf("Empleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1);
                    printf("\nModificando el salario del empleado...\n\n");
                    auxEmp[index].salary = getPositiveFloat("nuevo salario", 1, 100000);
                    isSatisfied = employee_verifyCompliance("'s' para confirmar la modificacion");
                    if(isSatisfied == 1)
                    {
                        listE[index].salary = auxEmp[index].salary;
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar un empleado.\n\n");
                }
                system("pause");
                break;
            case 5:
                if(found == 1)
                {   //Los mismos pasos pero para el sector.
                    printf("Empleado seleccionado actualmente:\n\n");
                    employee_printOneEmployee(listE[index], listS, sizeS, 1);
                    printf("\nModificando el sector del empleado...\n");
                    sector = sector_getSector(listS, sizeS);
                    auxEmp[index].sector = sector.id;
                    isSatisfied = employee_verifyCompliance("'s' para confirmar la modificacion");
                    if(isSatisfied == 1)
                    {
                        listE[index].sector = auxEmp[index].sector;
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar un empleado.\n\n");
                }
                system("pause");
                break;
            case 6: //Si se elige la opcion 6, salimos del menu modificar y volvemos al anterior.
                break;
            default:
                printf("Error: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    }while(option != 6); //Permaneceremos en este menu hasta que se elija la opcion 6.
}

int employee_removeEmployee(sEmployee listE[], int sizeE, int toRemove)
{
    int itCould = -1, index, isSatisfied;
    index = employee_findEmployeeById(listE, sizeE, toRemove); //Busco el ID del empleado a dar de baja.
    if(index != -1)
    {   //Si existe, pido la conformidad del usuario.
        isSatisfied = employee_verifyCompliance("'s' para confirmar la baja del empleado");
        if(isSatisfied == 1)
        {   //Si esta satisfecho con su decision, hago una baja logica cambiando isEmpty a cero.
            listE[index].isEmpty = EMPTY;
            itCould = 0; //Tambien señalo que se pudo eliminar del sistema a ese empleado.
        }
        else
        {
            printf("\nSe cancelo la baja del empleado.\n\n");
        }
    }
    else
    {
        printf("\nError: Empleado no encontrado.\n\n");
    }
    return itCould;
}

int employee_searchEmpty(sEmployee listE[], int sizeE)
{
    int i, index = -1;
    for(i=0; i<sizeE; i++)
    {   //Recorro mi array de empleados hasta encontrar una posicion libre.
        if(listE[i].isEmpty == EMPTY)
        {   //Si encuentro espacio libre, mi index sera esa posicion.
            index = i;
            break;
        }
    }
    return index;
}

int employee_findEmployeeById(sEmployee listE[], int sizeE, int idToFind)
{
    int i, index = -1;
    for(i=0; i<sizeE; i++)
    {   //Recorro mi array de empleados y voy comparando el ID ingresado por el usuario.
        if(listE[i].id == idToFind && listE[i].isEmpty == BUSY) //Tambien debo tener en cuenta si es un empleado activo.
        {   //Si encuentro al empleado, mi index sera esa posicion.
            index = i;
            break;
        }
    }
    return index;
}

sSector sector_getSector(sSector listS[], int sizeS)
{
    int i, sector;
    sSector sectorReturn; //Creo una variable auxiliar de sector.
    for(i=0; i<sizeS; i++)
    {   //Recorro mi array de sectores y voy imprimiendo su ID y descripcion correspondiente.
        printf("\n%d. %s", listS[i].id, listS[i].description);
    }
    printf("\n\n");
    sector = getValidInt("id del sector", 1, sizeS, 0); //El usuario elige un sector.
    for(i=0; i<sizeS; i++)
    {   //Recorro nuevamente mi array de sectores y comparo si el ID del sector ingresado corresponde.
        if(listS[i].id == sector)
        {   //Guardo el sector elegido.
            sectorReturn = listS[i];
            break;
        }
    }
    return sectorReturn;
}

void employee_getEmployeeName(sEmployee listE[], int strSize, int index)
{
    getValidString("nombre", listE[index].name, strSize); //Pido nombre del empleado y luego le doy formato.
    changeStringToLower(listE[index].name);
    changeFirstToUpper(listE[index].name);
}

void employee_getEmployeeLastName(sEmployee listE[], int strSize, int index)
{
    getValidString("apellido", listE[index].lastName, strSize); //Pido apellido del empleado y luego le doy formato.
    changeStringToLower(listE[index].lastName);
    changeFirstToUpper(listE[index].lastName);
}

void employee_sortEmployees(sEmployee listE[], int sizeE, int order)
{   //Utilizo el metodo de burbujeo para ordenar alfabeticamente en orden ascendente o descendente.
    int i, j;
    sEmployee auxEmp;
    for(i=0; i<sizeE-1; i++)
    {
        for(j=i+1; j<sizeE; j++)
        {
            if(order == 1) //Ascendente
            {
                if(strcmp(listE[i].lastName, listE[j].lastName) > 0)
                {
                    auxEmp = listE[i];
                    listE[i] = listE[j];
                    listE[j] = auxEmp;
                }
            }
            else{ //Descendente
                if(strcmp(listE[j].lastName, listE[i].lastName) > 0)
                {
                    auxEmp = listE[j];
                    listE[j] = listE[i];
                    listE[i] = auxEmp;
                }
            }
        }
    }
}

void employee_printEmployees(sEmployee listE[], int sizeE, sSector listS[], int sizeS)
{
    int i, j;
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("%10s %20s %20s %20s %20s\n", "Legajo", "Nombre", "Apellido", "Salario", "Sector");
    for(j=0; j<sizeS; j++)
    {   //Separo por sectores a mis empleados.
        printf("--------------------------------------------------------------------------------------------------\n");
        for(i=0; i<sizeE; i++)
        {
            if(listE[i].sector == listS[j].id && listE[i].isEmpty == BUSY)
            {   //Y mientras sea un empleado activo cuyo ID de sector corresponda con alguno de los sectores existentes, lo imprimo.
                employee_printOneEmployee(listE[i], listS, sizeS, 0);
            }
        }
    }
    printf("--------------------------------------------------------------------------------------------------\n\n");
}

void employee_printOneEmployee(sEmployee oneEmployee, sSector listS[], int sizeS, int format)
{
    int i;
    char sectorDescription[51]; //Cadena de caracteres auxiliar para guardar descripcion de sector.
    for(i=0; i<sizeS; i++)
    {   //Recorro el array de sectores y si el ID de sector de un empleado corresponde con alguno de los sectores existentes, guardo descripcion.
        if(oneEmployee.sector == listS[i].id)
        {
            strcpy(sectorDescription, listS[i].description);
            break;
        }
    }
    if(format == 0)
    {   //Una vez que tengo descripcion del sector del empleado, segun el formato elegido, imprimo de una u otra manera al empleado.
        printf("%10d %20s %20s %20.2f %20s\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, sectorDescription);
    }
    else
    {
        printf("Legajo: %d | Nombre: %s | Apellido: %s | Salario: %.2f | Sector: %s\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, sectorDescription);
    }
}

void employee_calculateSalaryInfo(sEmployee listE[], int sizeE)
{
    int i, employeeCounter = 0, employeeExceedCounter = 0;
    float salaryAcumulator = 0, salaryAverage;
    for(i=0; i<sizeE; i++)
    {   //Recorro mi array de empleados, mientras sea uno activo, sumo su salario en un acumulador.
        if(listE[i].isEmpty == BUSY)
        {
            salaryAcumulator += listE[i].salary;
            employeeCounter++; //Ademas, cuento 1 empleado.
        }
    }
    salaryAverage = salaryAcumulator / employeeCounter; //Calculo el salario promedio.
    for(i=0; i<sizeE; i++)
    {   //Recorro nuevamente y me fijo que empleado activo supera el salario promedio.
        if(listE[i].salary > salaryAverage && listE[i].isEmpty == BUSY)
        {
            employeeExceedCounter++; //Lo cuento.
        }
    } //Por ultimo, imprimo total, promedio y empleados que superan ese promedio.
    printf("Total de salarios: $%.2f | Promedio de salarios: $%.2f | Empleados que superan el promedio: %d\n\n", salaryAcumulator, salaryAverage, employeeExceedCounter);
}

int employee_verifyCompliance(char message[])
{
    int isSatisfied = 0; //Esta variable va a indicar si el usuario esta satisfecho con lo que hizo.
    char answer; //Repuesta del usuario.
    printf("\n");
    answer = getChar(message); //Le pido al usuario que ingrese una respuesta.
    if(answer == 's' || answer == 'S')
    {   //Si responde 's' o 'S', esta satisfecho.
        isSatisfied = 1;
    }
    return isSatisfied; //Retorno ese valor.
}

void employee_hardCodeEmployees(sEmployee listE[], int sizeE)
{   //Hardcodeo empleados.
    int i;
    int ids[] = {10345,10253,10708,10543,10224,10023};
    char names[][51] = {"Carlos","Maria","Juan","Pedro","Carlos","Lourdes"};
    char lastNames[][51] = {"Diaz","Leyva","Ramirez","Perez","Etchegaray","Acevedo"};
    float salaries[] = {6500,5600,5100,7800,10400,9600};
    int sectors[] = {1,2,3,1,2,2};
    for(i=0; i<sizeE-994; i++)
    {   //Recorro el array de empleados y voy llenando datos.
        listE[i].id = ids[i];
        strcpy(listE[i].name, names[i]);
        strcpy(listE[i].lastName, lastNames[i]);
        listE[i].salary = salaries[i];
        listE[i].isEmpty = BUSY;
        listE[i].sector = sectors[i];
    }
}
