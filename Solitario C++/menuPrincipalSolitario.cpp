#include "menuPrincipalSolitario.h"
#include "juegoSolitarioC.h"
#include <iostream>
#include <limits>
using namespace std;

void mostrarMenuPrincipalSolitario() {
    int opcion;

    do {
        cout << "\n\n   -------------------------------\n";
        cout << "   ---   BIENBENIDO AL JUEGO   ---\n";
        cout << "   ---     SOLITARIO EN C++    ---\n";
        cout << "   -------------------------------";
        cout << "\n\nA continuacion seleccione una opcion: \n\n";
        cout << "1--- Empezar una nueva partida.\n";
        cout << "2--- Instrucciones.\n";
        cout << "3--- Regresar al menu principal.\n\n";
        cout << "Su respuesta es: --->";

        try {
            cin >> opcion;

            if (cin.fail()) {
                throw invalid_argument("ERROR --- Ingresar solo numeros del 1 al 3.");
            }

            switch (opcion) {
                case 1:
                    mostrarJuegoSolitarioC();
                    break;
                case 2:
                    cout << "Insertar Instrucciones...\n";
                    break;
                case 3:
                    cout << "\n\n   ----------------------------------------\n";
                    cout << "   ---        SALIENDO DEL JUEGO        ---\n";
                    cout << "   ---   Regresando al menu principal   ---\n";
                    cout << "   ----------------------------------------\n";
                    break;
                default:
                    cout << "ERROR --- Ingresar solo numeros del 1 al 3.\n";
            }
        } catch (const std::invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (opcion != 3);
}
