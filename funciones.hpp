/******************************************
 * Fichero interfaz del módulo 'funciones'
 * del programa '3 en raya'
 * Autor: PcjSnow
*******************************************/

#include <iostream>

// Dimensiones máximas del tablero
const unsigned DIM_MAXIMAS = 15;

/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya.
 * Post: Ha inicializado los <n> primeros componentes de la matriz con un
 * asterisco '*'.
 */
void inicializarTablero(char tablero[][DIM_MAXIMAS], unsigned n);

/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya.
 * Post: ha pedido al jugador humano que introduzca las coordenadas
 * de una casilla del tablero.
 */
void turnoJugador(char tablero[][DIM_MAXIMAS], unsigned n, unsigned& i, unsigned& j);

/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya.
 * Post: Se han generado dos números aleatorios entre 0 y n-1 incluídos
 * que representan la elección del ordenador de casilla.
 */
void turnoOrdenador(char tablero[][DIM_MAXIMAS], unsigned n, unsigned& i, unsigned& j);

/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya.
 * Post: ha mostrado por pantalla el estado actual del tablero.
 */
void mostrarTablero(char tablero[][DIM_MAXIMAS], unsigned n);


/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya y <i> y <j> representan
 * las coordenadas de la última casilla rellenada.
 * Post: Ha devuelto true si la casilla <i><j> completa un n en raya vertical.
 */
bool comprobarVertical(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j);


/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya y <i> y <j> representan
 * las coordenadas de la última casilla rellenada.
 * Post: Ha devuelto true si la casilla <i><j> completa un n en raya horizontal.
 */
bool comprobarHorizontal(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j);


/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del n en raya y <i> y <j> representan
 * las coordenadas de la última casilla rellenada.
 * Post: Ha devuelto true si la casilla <i><j> completa un n en raya diagonal.
 */
bool comprobarDiagonales(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j);


/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del 3 en raya y <i> y <j> representan
 * las coordenadas de la última casilla rellenada.
 * Post: ha devuelto true si se ha completado algún n en raya.
 */
bool esTresEnRaya(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j);

/* Pre: <tablero> es una matriz de tipo char de n x n dimensiones
 * que representa al tablero del 3 en raya y <i> y <j> representan
 * las coordenadas de la última casilla rellenada.
 * Post : ha devuelto true si se da la situación de empate, esto es, el tablero
 * está lleno y no se ha logrado ningún n en raya.
 */
bool esEmpate(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j);

/* Pre: ---
 * Post: Ha devuelto estadísticas básicas sobre el nombre del jugador, sus victorias,
 * derrotas y empates.
 */
void stats(std::string username, unsigned wins, unsigned loses, unsigned draws);