/** \brief Obtiene un numero entero random en un rango.
 *
 * \param int Limite inferior.
 * \param int Limite superior.
 * \param int Indicador de inicio.
 * \return int Devuelve el numero generado.
 *
 */
int getRandomNumber(int, int, int);

/** \brief Valida si se trata de un numero decimal (tratando una cadena de caracteres).
 *
 * \param char[] La cadena de caracteres.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int validateFloatNumber(char[]);

/** \brief Valida si se trata de un numero entero (tratando una cadena de caracteres).
 *
 * \param char[] La cadena de caracteres.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int validateIntNumber(char[]);

/** \brief Valida si se trata de una palabra sin numeros.
 *
 * \param char[] La cadena de caracteres.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int validateString(char[]);

/** \brief Valida si se trata de un numero de telefono (tratando una cadena de caracteres).
 *
 * \param char[] La cadena de caracteres.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int validatePhoneNumber(char[]);

/** \brief Calcula de manera recursiva el factorial de un numero.
 *
 * \param int El entero al que se le quiere hallar su factorial.
 * \return unsigned long int Devuelve el factorial de dicho numero.
 *
 */
unsigned long int getFactorial(int);

/** \brief Evalua si se trata de un numero entero o decimal.
 *
 * \param float El decimal a evaluar.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int validateIntOrFloat(float);

/** \brief Determina si un numero entero es o no primo.
 *
 * \param int El entero a evaluar.
 * \return int Devuelve 1 si es valido, cero caso contrario.
 *
 */
int determinatePrime(int);

