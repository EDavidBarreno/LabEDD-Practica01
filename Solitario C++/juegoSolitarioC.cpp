#include "juegoSolitarioC.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <ctime>

using namespace std;

void mostrarJuegoSolitarioC() {
    string palabras[] = {"1-<3-R", "2-<3-R", "3-<3-R", "4-<3-R", "5-<3-R","6-<3-R","7-<3-R","8-<3-R","9-<3-R","10-<3-R","J-<3-R","Q-<3-R","K-<3-R",
                              "1-<>-R","2-<>-R","3-<>-R","4-<>-R","5-<>-R","6-<>-R","7-<>-R","8-<>-R","9-<>-R","10-<>-R","J-<>-R","Q-<>-R","K-<>-R",
                              "1-E3-N","2-E3-N","3-E3-N","4-E3-N","5-E3-N","6-E3-N","7-E3-N","8-E3-N","9-E3-N","10-E3-N","J-E3-N","Q-E3-N", "K-E3-N",
                              "1-!!-N","2-!!-N","3-!!-N","4-!!-N","5-!!-N","6-!!-N","7-!!-N","8-!!-N","9-!!-N","10-!!-N","J-!!-N","Q-!!-N","K-!!-N"};

    srand(time(0));

    string palabraAleatorias[52];
    copy(begin(palabras), end(palabras), begin(palabraAleatorias));

    random_shuffle(begin(palabraAleatorias), end(palabraAleatorias));

    for (const auto &str : palabraAleatorias) {
        cout << str << "\n";

    }
    
}
