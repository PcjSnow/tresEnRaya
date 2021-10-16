#include <iostream>
#include "funciones.hpp"



using namespace std;

void stats(string username, unsigned wins, unsigned loses, unsigned draws) {
    cout << "Usuario: " << username << endl;
    cout << "Total Partidas: " << wins + loses + draws << endl;
    cout << "Partidas Ganadas: " << wins << endl;
    cout << "Partidas Perdidas: " << loses << endl;
    cout << "Partidas Empatadas: " << draws << endl;
}


int main() {

    
    char tablero[DIM_MAXIMAS][DIM_MAXIMAS];
    unsigned int i, j, n, ganadas, perdidas, empate, opcion;
    string username;
    ganadas = 0;
    perdidas = 0;
    empate = 0;

    cout << "Introduzca su nombre de usuario: ";
    cout << "\033[35m";
    getline(cin, username);

    do{
        /* code */
     
    
        cout << "De qué tamaño desea el tablero? (3 en raya, 4 en raya...): ";
        cin >> n;

        inicializarTablero(tablero, n);
        mostrarTablero(tablero, n);

        cout << "\nDesea empezar usted o el ordenador? ";
        cout << "\033[35m";
        cout << "( 1 usted | 0 el ordenador): ";
        int opt;
        cin >> opt;
        fflush(stdin);

        if (opt == 1)
        {
            turnoJugador(tablero, n, i, j);
        }
        else {
            turnoOrdenador(tablero, n, i, j);
            mostrarTablero(tablero, n);
            turnoJugador(tablero, n, i, j);
        }
        

        while (!esTresEnRaya(tablero, n, i, j) && !esEmpate(tablero, n, i, j))
        {
            mostrarTablero(tablero, n);
            turnoOrdenador(tablero, n, i, j);
            mostrarTablero(tablero, n);

            if (esTresEnRaya(tablero, n, i, j) || esEmpate(tablero, n, i, j))
            {
                break;
            }

            turnoJugador(tablero, n, i, j);
            
        }

        mostrarTablero(tablero, n);

        

        if (tablero[i][j] == 'X' && esTresEnRaya(tablero, n, i, j))
        {
            cout << "\033[32m"; // texto en verde

            cout << "\n\n ____________________" << n << " EN RAYA!____________________" << endl;

            cout << "\033[31m";
            cout << "GANA EL JUGADOR!" << endl;
            ganadas++;
        }
        else if (esTresEnRaya(tablero, n, i, j))
        {
            cout << "\033[32m"; // texto en verde

            cout << "\n\n ____________________" << n << " EN RAYA!____________________" << endl;

            cout << "\033[32m";
            cout << "GANA EL ORDENADOR!" << endl;
            perdidas++;
        }
        else {

            cout << "\033[35m";
            cout << "____________EMPATE____________" << endl;
            empate++;
        }
        
        stats(username, ganadas, perdidas, empate);

        cout << "\033[35m";

        cout << "Desea jugar otra partida? (1 SÍ | 0 NO): ";
        fflush(stdin);
        cin >> opcion;

        cout << opcion;
    
    }while(opcion == 1);

    return 0;
}