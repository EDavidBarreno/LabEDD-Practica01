#include "menuPrincipal.h"
#include "menuPrincipalSolitario.h"
#include <iostream>
#include <limits> // Para limpiar el buffer de entrada
using namespace std;

void mostrarMenuPrincipal() {
    int opcion;

    do {
        cout << "\n\n   -------------------------------\n";
        cout << "   ---   BIENBENIDO AL JUEGO   ---\n";
        cout << "   ---     SOLITARIO EN C++    ---\n";
        cout << "   -------------------------------";
        cout << "\n\nA continuacion seleccione una opcion: \n\n";
        cout << "1--- Jugar Solitario en C++.\n";
        cout << "2--- Soporte Tecnico.\n";
        cout << "3--- Salir del sistema.\n\n";
        cout << "Su respuesta es: --->";

        try {
            std::cin >> opcion;

            if (std::cin.fail()) {
                throw std::invalid_argument("ERROR --- Ingresar solo numeros del 1 al 3.");
            }

            switch (opcion) {
                case 1:
                    mostrarMenuPrincipalSolitario();
                    break;
                case 2:
                    std::cout << "Hecho por 201830233...\n";
                    break;
                case 3:
                    std::cout << "\n\n   ------------------------------------------------\n";
                    std::cout << "   ---            SALIENDO DEL SISTEMA          ---\n";
                    std::cout << "   ---   De parte de nuestros Administradores   ---\n";
                    std::cout << "   ---       le deseamos un lindo dia!!         ---\n";
                    std::cout << "   ------------------------------------------------\n";
                    break;
                default:
                    std::cout << "ERROR --- Ingresar solo numeros del 1 al 3.\n";
            }
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (opcion != 3);
}