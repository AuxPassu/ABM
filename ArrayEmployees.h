typedef struct
{
    int id;
    char description[51];
} sSector; /** Estructura de sector **/

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee; /** Estructura de empleado **/

/** \brief Para indicar que todas las posiciones del array están vacías,
           esta función pone la bandera (isEmpty) en cero en todas las posiciones
           del array.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return void No devuelve algo.
 *
 */
void employee_initEmployees(sEmployee[], int);

/** \brief Busca en el array de empleados la primer posicion libre fijandose si
           isEmpty == EMPTY
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return int Devuelve la primer posicion libre, -1 en caso de que no encuentre
               espacio disponible.
 *
 */
int employee_searchEmpty(sEmployee[], int);

/** \brief Muestra una lista con los sectores actuales y le pide al usuario
           que ingrese uno.
 *
 * \param sSector[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \return sSector Devuelve una estructura del tipo sSector.
 *
 */
sSector sector_getSector(sSector[], int);

/** \brief Le pide al usuario el nombre de un empleado y lo guarda en la posicion
           correspondiente. Luego corrige el formato de tal manera que quede una mayuscula
           al principio de un nombre y el resto en minusculas.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int La posicion en la que se quiere guardar ese nombre.
 * \return void No devuelve algo.
 *
 */
void employee_getEmployeeName(sEmployee[], int, int);

/** \brief Le pide al usuario el apellido de un empleado y lo guarda en la posicion
           correspondiente. Luego corrige el formato de tal manera que quede una mayuscula
           al principio de un apellido y el resto en minusculas.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int La posicion en la que se quiere guardar ese apellido.
 * \return void No devuelve algo.
 *
 */
void employee_getEmployeeLastName(sEmployee[], int, int);

/** \brief Pide los datos de un empleado y los agrega al array de empleados en la primer
           posicion libre.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param sSector[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \return int Devuelve cero si la carga fue exitosa, -1 si no hay espacio disponible.
 *
 */
int employee_addEmployee(sEmployee[], int, sSector[], int);

/** \brief Se realizan operaciones relacionadas a la modificacion de datos de un empleado.
           El usuario podra elegir opciones en un nuevo menu.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param sSector[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \return void No devuelve algo.
 *
 */
void employee_modifyEmployeeInfo(sEmployee[], int, sSector[], int);

/** \brief Busca un empleado recibiendo como parametro de busqueda su ID.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int El ID del empleado a buscar.
 * \return int Devuelve la posicion en la que se encuentra el empleado, -1 si no lo
               encuentra.
 *
 */
int employee_findEmployeeById(sEmployee[], int, int);

/** \brief Elimina de manera logica (isEmpty = EMPTY) un empleado recibiendo como
           parametro su ID.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int El ID del empleado a dar de baja.
 * \return int Devuelve cero en caso de haber dado de baja al empleado, -1 si no fue
               encontrado.
 *
 */
int employee_removeEmployee(sEmployee[], int, int);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int Orden 1 para ascendente, 0 para descendente.
 * \return void No devuelve algo.
 *
 */
void employee_sortEmployees(sEmployee[], int, int);

/** \brief Imprime el array de empleados en forma encolumnada.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param sSector[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \return void No devuelve algo.
 *
 */
void employee_printEmployees(sEmployee[], int, sSector[], int);

/** \brief Imprime un solo empleado.
 *
 * \param sEmployee Un empleado.
 * \param sSector[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \param int El formato 0 para encolumnado, 1 para dato por dato.
 * \return void No devuelve algo.
 *
 */
void employee_printOneEmployee(sEmployee, sSector[], int, int);

/** \brief Calcula el total, promedio y cantidad de empleados que superan
           el promedio de salario.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return void No devuelve algo.
 *
 */
void employee_calculateSalaryInfo(sEmployee[], int);

/** \brief Verifica si el usuario esta conforme con alguna accion (alta, modificar, baja).
 *
 * \param char[] Mensaje de confirmacion.
 * \return int Devuelve la respuesta del usuario, 1 si esta satisfecho, cero si no lo esta.
 *
 */
int employee_verifyCompliance(char[]);

/** \brief Carga empleados en el arreglo de forma automatica con datos preestablecidos.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return void No devuelve algo.
 *
 */
void employee_hardCodeEmployees(sEmployee[], int);
