/** \brief Pide el ingreso de un entero.
 *
 * \param char[] Lo que se quiere pedir.
 * \return int Devuelve el entero ingresado.
 *
 */
int getInt(char[]);

/** \brief Pide el ingreso de un numero decimal.
 *
 * \param char[] Lo que se quiere pedir.
 * \return float Devuelve el numero decimal.
 *
 */
float getFloat(char[]);

/** \brief Pide el ingreso de un caracter.
 *
 * \param char[] Lo que se quiere pedir.
 * \return char Devuelve el caracter.
 *
 */
char getChar(char[]);

/** \brief Pide el ingreso de una cadena de caracteres (palabra).
 *
 * \param char[] Lo que se quiere pedir.
 * \param char[] La cadena de caracteres destino.
 * \return void
 *
 */
void getString(char[], char[]);

/** \brief Pide el ingreso de una cadena de caracteres valida (palabra).
 *
 * \param char[] Lo que se quiere pedir.
 * \param char[] La cadena de caracteres destino.
 * \param int El tamaño de la cadena de caracteres destino.
 * \return void No devuelve algo.
 *
 */
void getValidString(char[], char[], int);

/** \brief Pide el ingreso de un numero entero valido en un rango o no.
 *
 * \param char[] Lo que se quiere pedir.
 * \param int Limite inferior.
 * \param int Limite superior.
 * \param int Formato cero si se quiere pedir en un rango, 1 caso contrario.
 * \return int Devuelve el entero ingresado.
 *
 */
int getValidInt(char[], int, int, int);

/** \brief Pide el ingreso de un numero decimal que sea positivo.
 *
 * \param char[] Lo que se quiere pedir.
 * \param float Limite inferior.
 * \param float Limite superior.
 * \return float Devuelve el numero decimal.
 *
 */
float getPositiveFloat(char[], float, float);

