#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"
#define SIZE_EMPLOYEES 1000
#define SIZE_SECTORS 3

int showMenu(char message[])
{
    int option;
    system("cls");
    printf("--------------------------\n");
    printf("%s", message);
    printf("\n--------------------------\n\n");
    option = getValidInt("una opcion", 0, 0, 1); //Pido un entero valido sin rango.
    printf("\n");
    return option;
}

void chooseOption(void)
{
    int option, loaded, toRemove, removed, employeesCounter = 6; //Inicializo el contador de empleados en 6 porque hardcodie 6 empleados.
    char userContinue = 's';
    sEmployee arrayEmployee[SIZE_EMPLOYEES];
    sSector arraySector[SIZE_SECTORS] = {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"}}; //Hardcodeo un array de sectores.
    employee_initEmployees(arrayEmployee, SIZE_EMPLOYEES); //Indico que el vector esta limpio de datos.
    employee_hardCodeEmployees(arrayEmployee, SIZE_EMPLOYEES); //Hardcodeo empleados para tener algunos con los cuales trabajar.
    do
    {
        option = showMenu(" 1. Alta.\n 2. Modificar.\n 3. Baja.\n 4. Informar.\n 5. Salir."); //Creo el menu principal.
        switch(option)
        {
            case 1:
                loaded = employee_addEmployee(arrayEmployee, SIZE_EMPLOYEES, arraySector, SIZE_SECTORS);
                if(loaded == 0) //Si la carga del empleado fue exitosa, mi contador de empleados aumenta.
                {
                    employeesCounter++;
                    printf("\nEmpleado dado de alta con exito.\n\n");
                }
                system("pause");
                break;
            case 2:
                if(employeesCounter > 0) //Solo puedo modificar datos si existen empleados en el sistema.
                {
                    employee_modifyEmployeeInfo(arrayEmployee, SIZE_EMPLOYEES, arraySector, SIZE_SECTORS);
                }
                else
                {
                    printf("Error: No hay empleados cargados en el sistema.\n\n");
                    system("pause");
                }

                break;
            case 3:
                if(employeesCounter > 0) //Solo puedo dar de baja si existen empleados en el sistema.
                {   //Ordeno y muestro la lista actual de empleados (por apellido y sector) para que se puedan visualizar todos los datos de los mismos.
                    employee_sortEmployees(arrayEmployee, SIZE_EMPLOYEES, 0);
                    employee_printEmployees(arrayEmployee, SIZE_EMPLOYEES, arraySector, SIZE_SECTORS);
                    toRemove = getValidInt("ID del empleado a dar de baja", 10000, 11000, 0); //Pido un ID valido para hacer su baja logica.
                    removed = employee_removeEmployee(arrayEmployee, SIZE_EMPLOYEES, toRemove);
                    if(removed != -1) //Si ese empleado existe en el sistema, lo doy de baja y disminuyo mi numero de empleados en el sistema.
                    {
                        printf("\nSe ha dado de baja al empleado exitosamente.\n\n");
                        employeesCounter--;
                    }
                }
                else
                {
                    printf("Error: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 4:
                if(employeesCounter > 0) //Solo puedo informar si existen empleados en el sistema.
                {   //Ordeno y muestro la lista actual de empleados (por apellido y sector). Luego realizo los calculos pedidos.
                    employee_sortEmployees(arrayEmployee, SIZE_EMPLOYEES, 1);
                    employee_printEmployees(arrayEmployee, SIZE_EMPLOYEES, arraySector, SIZE_SECTORS);
                    employee_calculateSalaryInfo(arrayEmployee, SIZE_EMPLOYEES);
                }
                else
                {
                    printf("Error: No hay empleados cargados en el sistema.\n\n");
                }
                system("pause");
                break;
            case 5:
                userContinue = 'n'; //Si la opcion 5 es elegida, cierro el programa.
                printf("Saliendo...\nPrograma terminado.\n\n");
                system("pause");
                break;
            default:
                printf("Error: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    } while(userContinue == 's');
}
