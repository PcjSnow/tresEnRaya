#include "funciones.hpp"
#include <time.h>
using namespace std;
#include <iostream>



void inicializarTablero(char tablero[][DIM_MAXIMAS], unsigned n) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tablero[i][j] = '*';
        }
        
    }
    
}


void turnoJugador(char tablero[][DIM_MAXIMAS], unsigned n, unsigned& i, unsigned& j) {

    cout << "\n\nSu turno! Introduzca la casilla (fila y columna) entre 0 y " << n-1 <<  " incluidos: ";
    cin >> i >> j;
    
    while (i < 0 || i > n-1 || j < 0 || j > n-1)
    {
        cout << "Las coordenadas son un valor entre 0 y " << n-1 << " incluídos!\n";
        cout << "Vuelva a introducirlas: ";
        cin >> i >> j;
    }

    while (tablero[i][j] != '*')
    {
        cout << "Casilla ocupada! Introduzca otra: ";
        cin >> i >> j;
    }

    tablero[i][j] = 'X';
    
    
}


void turnoOrdenador(char tablero[][DIM_MAXIMAS], unsigned n, unsigned& i, unsigned& j) {

    srand(time(NULL));

    i = (rand() % n );
    j = (rand() % n );

    while (tablero[i][j] != '*')
    {
        i = (rand() % n );
        j = (rand() % n );
    }


    tablero[i][j] = 'O';

    cout << "\n\nTurno del ordenador! Ha decidido escoger la casilla " << i << ", " << j << endl;
    
}


void mostrarTablero(char tablero[][DIM_MAXIMAS], unsigned n) {

    cout << "\nESTADO DEL TABLERO: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << endl;

        for (int j = 0; j < n; j++)
        {
             
            if (tablero[i][j] == 'X')
            {
                cout << "\033[31m";
                cout << tablero[i][j] << " ";
                cout << "\033[0m";  
            }
            else if (tablero[i][j] == 'O')
            {
                cout << "\033[34m";
                cout << tablero[i][j] << " ";
                cout << "\033[0m";
            }
            else {
                cout << "\033[0m";

                cout << tablero[i][j] << " ";
            }
            
        
            
        }
        
    }

    cout << "\033[0m"; // texto normal
    
}


bool comprobarVertical(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j) {

    bool iguales_abajo = true;
    for (int k = i; k < n; k++)
    {
        if (tablero[k][j] != tablero[i][j])
        {
            iguales_abajo = false;
        }
        
    }

    bool iguales_arriba = true;
    for (int k = i; k >= 0; k--)
    {
        if (tablero[k][j] != tablero[i][j])
        {
            iguales_arriba = false;
        }
        
    }

    return iguales_abajo && iguales_arriba;
    
}


bool comprobarHorizontal(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j) {

    bool iguales_dcha = true;
    for (int k = i; k < n; k++)
    {
        if (tablero[i][k] != tablero[i][j])
        {
            iguales_dcha = false;
        }
        
    }

    bool iguales_izq = true;
    for (int k = i; k >= 0; k--)
    {
        if (tablero[i][k] != tablero[i][j])
        {
            iguales_izq = false;
        }
        
    }

    return iguales_dcha && iguales_izq;
    
}


bool comprobarDiagonales(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j) {
    

   bool diagonal_dcha = true;

   for (int k = 0; k < n; k++)
   {
       if (tablero[k][k] != tablero[i][j])
       {
           diagonal_dcha = false;
           break;
       }
   }

   bool diagonal_izq = true;

   for (int k = 0; k < n; k++)
   {
       if (tablero[n-1-k][k] != tablero[i][j])
       {
           diagonal_izq = false;
           break;
       }
   }

    return diagonal_dcha || diagonal_izq;
}


bool esTresEnRaya(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j) {

    return comprobarDiagonales(tablero, n, i, j) || comprobarHorizontal(tablero, n, i, j) || comprobarVertical(tablero, n, i, j);

}

bool esEmpate(char tablero[][DIM_MAXIMAS], unsigned n, unsigned i, unsigned j) {
    
    bool lleno = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tablero[i][j] == '*')
            {
                lleno = false;
                break;
            }
            
        }
        
    }

    return lleno;
    
}

void stats(string username, unsigned wins, unsigned loses, unsigned draws)
{
    cout << "Usuario: " << username << endl;
    cout << "Total Partidas: " << wins + loses + draws << endl;
    cout << "Partidas Ganadas: " << wins << endl;
    cout << "Partidas Perdidas: " << loses << endl;
    cout << "Partidas Empatadas: " << draws << endl;
}
