typedef struct
{
    int id;
    char name[51];
    char country[51];
} sActor; /** Estructura de actor **/

typedef struct
{
    int id;
    char description[51];
} sGenre; /** Estructura de genero**/

typedef struct
{
    int day;
    int month;
    int year;
} sDate; /** Estructura de fecha**/

typedef struct
{
    int id;
    char title[51];
    sDate premiere;
    int genreId;
    int actorId;
    int isEmpty;
} sMovie; /** Estructura de peliculas **/

/** \brief Para indicar que todas las posiciones del array están vacías,
           esta función pone la bandera (isEmpty) en cero en todas las posiciones
           del array.
 *
 * \param sMovies[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return void No devuelve algo.
 *
 */
void movie_initMovies(sMovie[], int);

/** \brief Busca en el array de empleados la primer posicion libre fijandose si
           isEmpty == EMPTY
 *
 * \param sMovie[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return int Devuelve la primer posicion libre, -1 en caso de que no encuentre
               espacio disponible.
 *
 */
int movie_searchEmpty(sMovie[], int);

int movie_addMovie(sMovie[], int, sGenre[], int, sActor[], int);

void movie_modifyMovieInfo(sMovie[], int, sGenre[], int, sActor[], int);

/** \brief Muestra una lista con los sectores actuales y le pide al usuario
           que ingrese uno.
 *
 * \param sGenre[] El array de sectores.
 * \param int El tamaño del array de sectores.
 * \return sGenre Devuelve una estructura del tipo sGenre.
 *
 */

int movie_findMovieById(sMovie[], int, int);

int movie_removeMovie(sMovie[], int, int);

int movie_verifyCompliance(char[]);

sGenre genre_getGenre(sGenre[], int);

sActor actor_getActor(sActor[], int);

/** \brief Le pide al usuario el nombre de un empleado y lo guarda en la posicion
           correspondiente. Luego corrige el formato de tal manera que quede una mayuscula
           al principio de un nombre y el resto en minusculas.
 *
 * \param sMovie[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \param int La posicion en la que se quiere guardar ese nombre.
 * \return void No devuelve algo.
 *
 */
void movie_getMovieTitle(sMovie[], int, int);

void movie_getMovieDate(sMovie[], int, int);

void movie_sortMovies(sMovie[], int, int);

void movie_printMovies(sMovie[], int, sGenre[], int, sActor[], int);

void movie_printOneMovie(sMovie, sGenre[], int, sActor[], int, int);

/** \brief Carga empleados en el arreglo de forma automatica con datos preestablecidos.
 *
 * \param sEmployee[] El array de empleados.
 * \param int El tamaño del array de empleados.
 * \return void No devuelve algo.
 *
 */
void movie_hardCodeMovies(sMovie[], int);
