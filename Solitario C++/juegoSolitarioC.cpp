#include "juegoSolitarioC.h"
#include <iostream>
#include <algorithm> //Solo se uso para ordenar las cartas al azar
#include <random>  //Solo se uso para ordenar las cartas al azar


using namespace std;

struct NodoBarajaInicial{
    string barajaInicial;
    NodoBarajaInicial *siguienteBarajaInicial;
};
struct NodoBarajaInicial2{
    string barajaInicial2;
    NodoBarajaInicial2 *siguienteBarajaInicial2;
};
struct NodoBarajaOcultaB{
    string barajaOcultaB;
    NodoBarajaOcultaB *siguienteBarajaOcultaB;
};
struct NodoBarajaOcultaC{
    string barajaOcultaC;
    NodoBarajaOcultaC *siguienteBarajaOcultaC;
};
struct NodoBarajaOcultaD{
    string barajaOcultaD;
    NodoBarajaOcultaD *siguienteBarajaOcultaD;
};
struct NodoBarajaOcultaE{
    string barajaOcultaE;
    NodoBarajaOcultaE *siguienteBarajaOcultaE;
};
struct NodoBarajaOcultaF{
    string barajaOcultaF;
    NodoBarajaOcultaF *siguienteBarajaOcultaF;
};
struct NodoBarajaOcultaG{
    string barajaOcultaG;
    NodoBarajaOcultaG *siguienteBarajaOcultaG;
};
struct NodoBarajaVisibleA{
    string barajaVisibleA;
    NodoBarajaVisibleA *siguienteBarajaVisibleA;
};
struct NodoBarajaVisibleB{
    string barajaVisibleB;
    NodoBarajaVisibleB *siguienteBarajaVisibleB;
};
struct NodoBarajaVisibleC{
    string barajaVisibleC;
    NodoBarajaVisibleC *siguienteBarajaVisibleC;
};
struct NodoBarajaVisibleD{
    string barajaVisibleD;
    NodoBarajaVisibleD *siguienteBarajaVisibleD;
};
struct NodoBarajaVisibleE{
    string barajaVisibleE;
    NodoBarajaVisibleE *siguienteBarajaVisibleE;
};
struct NodoBarajaVisibleF{
    string barajaVisibleF;
    NodoBarajaVisibleF *siguienteBarajaVisibleF;
};
struct NodoBarajaVisibleG{
    string barajaVisibleG;
    NodoBarajaVisibleG *siguienteBarajaVisibleG;
};

void insertarColaBarajaInicial(NodoBarajaInicial *&, NodoBarajaInicial *&, string);
bool colaBarajaInicial_vacia(NodoBarajaInicial *);
void eliminarColaBarajaInicial(NodoBarajaInicial *&, NodoBarajaInicial *&, string&);

void insertarColaBarajaInicial2(NodoBarajaInicial2 *&, NodoBarajaInicial2 *&, string);
bool colaBarajaInicial_vacia2(NodoBarajaInicial2 *);

void insertarPilaBarajaOcultaB(NodoBarajaOcultaB *&, string);
void insertarPilaBarajaOcultaC(NodoBarajaOcultaC *&, string);
void insertarPilaBarajaOcultaD(NodoBarajaOcultaD *&, string);
void insertarPilaBarajaOcultaE(NodoBarajaOcultaE *&, string);
void insertarPilaBarajaOcultaF(NodoBarajaOcultaF *&, string);
void insertarPilaBarajaOcultaG(NodoBarajaOcultaG *&, string);

void insertarPilaBarajaVisibleA(NodoBarajaVisibleA *&, string);
void insertarPilaBarajaVisibleB(NodoBarajaVisibleB *&, string);
void insertarPilaBarajaVisibleC(NodoBarajaVisibleC *&, string);
void insertarPilaBarajaVisibleD(NodoBarajaVisibleD *&, string);
void insertarPilaBarajaVisibleE(NodoBarajaVisibleE *&, string);
void insertarPilaBarajaVisibleF(NodoBarajaVisibleF *&, string);
void insertarPilaBarajaVisibleG(NodoBarajaVisibleG *&, string);

void mostrarJuegoSolitarioC() {
    string cartasOrigen[] = {"01-<3-R", "02-<3-R", "03-<3-R", "04-<3-R", "05-<3-R","06-<3-R","07-<3-R","08-<3-R","09-<3-R","10-<3-R"," J-<3-R"," Q-<3-R"," K-<3-R",
                             "01-<>-R","02-<>-R","03-<>-R","04-<>-R","05-<>-R","06-<>-R","07-<>-R","08-<>-R","09-<>-R","10-<>-R"," J-<>-R"," Q-<>-R"," K-<>-R",
                             "01-E3-N","02-E3-N","03-E3-N","04-E3-N","05-E3-N","06-E3-N","07-E3-N","08-E3-N","09-E3-N","10-E3-N"," J-E3-N"," Q-E3-N", " K-E3-N",
                             "01-!!-N","02-!!-N","03-!!-N","04-!!-N","05-!!-N","06-!!-N","07-!!-N","08-!!-N","09-!!-N","10-!!-N"," J-!!-N"," Q-!!-N"," K-!!-N"};


    const int tamano = sizeof(cartasOrigen) / sizeof(cartasOrigen[0]);

    string cartasOrigen2[tamano];
    copy(begin(cartasOrigen), end(cartasOrigen), begin(cartasOrigen2));

    random_device rd;
    mt19937 g(rd());
    shuffle(begin(cartasOrigen2), end(cartasOrigen2), g);

    for (const auto& elemento : cartasOrigen2) {
        //cout << elemento << endl;     //------- Ya imprime las cartas al azar :D
    }
    //cout<<"ACA esta"+cartasOrigen2[51];

    //   ---   DEFINIMOS NUESTRA BARAJA PRINCIPAL COLA1


    NodoBarajaInicial *frenteBarajaInicial = NULL;
    NodoBarajaInicial *finBarajaInicial = NULL;

    NodoBarajaInicial2 *frenteBarajaInicial2 = NULL;
    NodoBarajaInicial2 *finBarajaInicial2 = NULL;

    const int tamano2 = sizeof(cartasOrigen2) / sizeof(cartasOrigen2[0]);

    int contBarajaInicial;
    for (contBarajaInicial = 1; contBarajaInicial <= 52; contBarajaInicial++){
        insertarColaBarajaInicial(frenteBarajaInicial,finBarajaInicial,cartasOrigen2[contBarajaInicial]);
    }

    NodoBarajaOcultaB *pilaNodoBarajaOcultaB = NULL;
    NodoBarajaOcultaC *pilaNodoBarajaOcultaC = NULL;
    NodoBarajaOcultaD *pilaNodoBarajaOcultaD = NULL;
    NodoBarajaOcultaE *pilaNodoBarajaOcultaE = NULL;
    NodoBarajaOcultaF *pilaNodoBarajaOcultaF = NULL;
    NodoBarajaOcultaG *pilaNodoBarajaOcultaG = NULL;

    int ocultoA = 0;
    int ocultoB = 0;
    int ocultoC = 0;
    int ocultoD = 0;
    int ocultoE = 0;
    int ocultoF = 0;
    int ocultoG = 0;
    insertarPilaBarajaOcultaB(pilaNodoBarajaOcultaB,finBarajaInicial->barajaInicial);ocultoB++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaC(pilaNodoBarajaOcultaC,finBarajaInicial->barajaInicial);ocultoC++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaD(pilaNodoBarajaOcultaD,finBarajaInicial->barajaInicial);ocultoD++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaE(pilaNodoBarajaOcultaE,finBarajaInicial->barajaInicial);ocultoE++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaF(pilaNodoBarajaOcultaF,finBarajaInicial->barajaInicial);ocultoF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaC(pilaNodoBarajaOcultaC,finBarajaInicial->barajaInicial);ocultoC++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaD(pilaNodoBarajaOcultaD,finBarajaInicial->barajaInicial);ocultoD++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaE(pilaNodoBarajaOcultaE,finBarajaInicial->barajaInicial);ocultoE++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaF(pilaNodoBarajaOcultaF,finBarajaInicial->barajaInicial);ocultoF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaD(pilaNodoBarajaOcultaD,finBarajaInicial->barajaInicial);ocultoD++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaE(pilaNodoBarajaOcultaE,finBarajaInicial->barajaInicial);ocultoE++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaF(pilaNodoBarajaOcultaF,finBarajaInicial->barajaInicial);ocultoF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaE(pilaNodoBarajaOcultaE,finBarajaInicial->barajaInicial);ocultoE++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaF(pilaNodoBarajaOcultaF,finBarajaInicial->barajaInicial);ocultoF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaF(pilaNodoBarajaOcultaF,finBarajaInicial->barajaInicial);ocultoF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaOcultaG(pilaNodoBarajaOcultaG,finBarajaInicial->barajaInicial);ocultoG++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);


    NodoBarajaVisibleA *pilaNodoBarajaVisibleA = NULL;
    NodoBarajaVisibleB *pilaNodoBarajaVisibleB = NULL;
    NodoBarajaVisibleC *pilaNodoBarajaVisibleC = NULL;
    NodoBarajaVisibleD *pilaNodoBarajaVisibleD = NULL;
    NodoBarajaVisibleE *pilaNodoBarajaVisibleE = NULL;
    NodoBarajaVisibleF *pilaNodoBarajaVisibleF = NULL;
    NodoBarajaVisibleG *pilaNodoBarajaVisibleG = NULL;

    int visivleA = 0;
    int visivleB = 0;
    int visivleC = 0;
    int visivleD = 0;
    int visivleE = 0;
    int visivleF = 0;
    int visivleG = 0;

    insertarPilaBarajaVisibleA(pilaNodoBarajaVisibleA,finBarajaInicial->barajaInicial);visivleA++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleB(pilaNodoBarajaVisibleB,finBarajaInicial->barajaInicial);visivleB++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleC(pilaNodoBarajaVisibleC,finBarajaInicial->barajaInicial);visivleC++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleD(pilaNodoBarajaVisibleD,finBarajaInicial->barajaInicial);visivleD++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleE(pilaNodoBarajaVisibleE,finBarajaInicial->barajaInicial);visivleE++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleF(pilaNodoBarajaVisibleF,finBarajaInicial->barajaInicial);visivleF++;
    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
    insertarPilaBarajaVisibleG(pilaNodoBarajaVisibleG,finBarajaInicial->barajaInicial);visivleG++;


    //DEFINIMOS LA ESTRUCTURA DEL JUEGO




    int opcion;

    do {
        string matrizOculto[52][7];
        for(int i=0; i<1; i++){
            for(int j=0; j< ocultoA; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=1; i<2; i++){
            for(int j=0; j< ocultoB; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=2; i<3; i++){
            for(int j=0; j< ocultoC; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=3; i<4; i++){
            for(int j=0; j< ocultoD; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=4; i<5; i++){
            for(int j=0; j< ocultoE; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=5; i<6; i++){
            for(int j=0; j< ocultoF; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }
        for(int i=6; i<7; i++){
            for(int j=0; j< ocultoG; j++){
                matrizOculto[i][j] = "*******  |  ";
            }
        }

        string matriVisible[52][7];

        for(int i=0; i<1; i++){
            for(int j=0; j< visivleA; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleA->barajaVisibleA+"  |  ";
            }
        }
        for(int i=1; i<2; i++){
            for(int j=0; j< visivleB; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleB->barajaVisibleB+"  |  ";
            }
        }
        for(int i=2; i<3; i++){
            for(int j=0; j< visivleC; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleC->barajaVisibleC+"  |  ";
            }
        }
        for(int i=3; i<4; i++){
            for(int j=0; j< visivleD; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleD->barajaVisibleD+"  |  ";
            }
        }
        for(int i=4; i<5; i++){
            for(int j=0; j< visivleE; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleE->barajaVisibleE+"  |  ";
            }
        }
        for(int i=5; i<6; i++){
            for(int j=0; j< visivleF; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleF->barajaVisibleF+"  |  ";
            }
        }
        for(int i=6; i<7; i++){
            for(int j=0; j< visivleG; j++){
                matriVisible[i][j] = pilaNodoBarajaVisibleG->barajaVisibleG+"  |  ";
            }
        }




        cout<< "\n\n---------------------------------------------------------------------------------\n";
        cout<< "   A     |     B     |     C     |     D     |     E     |     F     |     G     |\n";
        cout<< "---------------------------------------------------------------------------------\n";

        if (!colaBarajaInicial_vacia2(frenteBarajaInicial2) & !colaBarajaInicial_vacia(frenteBarajaInicial)) {
            cout << finBarajaInicial->barajaInicial + "  |  " + finBarajaInicial2->barajaInicial2 + "\n";
        }else{
            if (!colaBarajaInicial_vacia2(frenteBarajaInicial2) & colaBarajaInicial_vacia(frenteBarajaInicial)){
                cout <<"Sin cartas |  " + finBarajaInicial2->barajaInicial2 + "\n";
            }else{
                if (colaBarajaInicial_vacia2(frenteBarajaInicial2) & !colaBarajaInicial_vacia(frenteBarajaInicial)){
                    cout << finBarajaInicial->barajaInicial + "  |" + "Sin cartas\n";
                }
            }
        }


        /*if (!colaBarajaInicial_vacia(frenteBarajaInicial)) {
            cout << finBarajaInicial->barajaInicial + "  |  " + finBarajaInicial2->barajaInicial2 + "\n";
        } else {
            cout <<"Sin cartas |  " + finBarajaInicial2->barajaInicial2 + "\n";
        }*/
        //cout<<finBarajaInicial->barajaInicial+"  |  "+finBarajaInicial2->barajaInicial2+"\n";
        cout<< "---------------------------------------------------------------------------------\n";
        for(int i=0; i<7;i++){
            for(int j=0;j<ocultoG;j++){
                cout<<matrizOculto[i][j];
            }
            cout<<"\n";
        }
        cout<< "---------------------------------------------------------------------------------\n";
        for(int i=0; i<7;i++){
            for(int j=0;j<visivleG;j++){
                cout<<matriVisible[i][j];
            }
            cout<<"\n";
        }
        cout<< "---------------------------------------------------------------------------------\n\n";
        cout<< "1--- Siguiente carta.\n";
        cout<< "2--- Insertar carta.\n";
        cout<< "3--- Mover carta.\n";
        cout<< "4--- Regresar movimiento.\n";
        cout<< "5--- Pista.\n";
        cout<< "6--- RENDIRSE.\n\n";
        cout<< "---------------------------------------------------------------------------------\n";
        cout<< "Su respuesta es: --->";

        try {
            cin >> opcion;

            if (cin.fail()) {
                throw invalid_argument("ERROR --- Ingresar solo numeros del 1 al 6.");
            }

            switch (opcion) {
                case 1:
                    insertarColaBarajaInicial2(frenteBarajaInicial2,finBarajaInicial2,finBarajaInicial->barajaInicial);
                    eliminarColaBarajaInicial(frenteBarajaInicial, finBarajaInicial, finBarajaInicial->barajaInicial);
                    break;
                case 2:
                    cout << "Insertar Instrucciones...\n";

                    break;
                case 3:
                    cout << "Insertar Instrucciones...\n";
                    break;
                case 4:
                    cout << "Insertar Instrucciones...\n";
                    break;
                case 5:
                    cout << "Insertar Instrucciones...\n";
                    break;
                case 6:
                    cout << "\n\n   ----------------------------------------\n";
                    cout << "   ---        SALIENDO DEL JUEGO        ---\n";
                    cout << "   ---   Regresando al menu principal   ---\n";
                    cout << "   ----------------------------------------\n";
                    break;
                default:
                    cout << "ERROR --- Ingresar solo numeros del 1 al 6.\n";
            }
        } catch (const std::invalid_argument& e) {
            cout << e.what() << "\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (opcion != 6);



}

void insertarColaBarajaInicial(NodoBarajaInicial *&frenteBarajaInicial, NodoBarajaInicial *&finBarajaInicial, string nBarajaInicial){
    NodoBarajaInicial *nuevoNodoBarajaInicial = new NodoBarajaInicial();

    nuevoNodoBarajaInicial->barajaInicial = nBarajaInicial;
    nuevoNodoBarajaInicial->siguienteBarajaInicial = NULL;
    if (colaBarajaInicial_vacia(frenteBarajaInicial)){
        frenteBarajaInicial = nuevoNodoBarajaInicial;
    }
    else{
        finBarajaInicial->siguienteBarajaInicial = nuevoNodoBarajaInicial;
    }
    finBarajaInicial = nuevoNodoBarajaInicial;
    //cout<<"Elemento    "<<nBarajaInicial<< "     Insertado correctamente\n";
}

void eliminarColaBarajaInicial(NodoBarajaInicial *&frenteBarajaInicial, NodoBarajaInicial *&finBarajaInicial, string &nBarajaInicial){
    nBarajaInicial = frenteBarajaInicial->barajaInicial;
    NodoBarajaInicial *aux = frenteBarajaInicial;

    if(frenteBarajaInicial == finBarajaInicial){
        frenteBarajaInicial = NULL;
        finBarajaInicial = NULL;
    } else{
        frenteBarajaInicial = frenteBarajaInicial -> siguienteBarajaInicial;
    }
    delete aux;
}
bool colaBarajaInicial_vacia(NodoBarajaInicial *frenteBarajaInicial){
    return (frenteBarajaInicial == NULL )? true : false;

}
void insertarColaBarajaInicial2(NodoBarajaInicial2 *&frenteBarajaInicial2, NodoBarajaInicial2 *&finBarajaInicial2, string nBarajaInicial2){
    NodoBarajaInicial2 *nuevoNodoBarajaInicial2 = new NodoBarajaInicial2();

    nuevoNodoBarajaInicial2->barajaInicial2 = nBarajaInicial2;
    nuevoNodoBarajaInicial2->siguienteBarajaInicial2 = NULL;
    if (colaBarajaInicial_vacia2(frenteBarajaInicial2)){
        frenteBarajaInicial2 = nuevoNodoBarajaInicial2;
    }
    else{
        finBarajaInicial2->siguienteBarajaInicial2 = nuevoNodoBarajaInicial2;
    }
    finBarajaInicial2 = nuevoNodoBarajaInicial2;
    //cout<<"Elemento    "<<nBarajaInicial2<< "     Insertado correctamente\n";
}

bool colaBarajaInicial_vacia2(NodoBarajaInicial2 *frenteBarajaInicial2){
    return (frenteBarajaInicial2 == NULL )? true : false;

}
void insertarPilaBarajaOcultaB(NodoBarajaOcultaB *&pilaNodoBarajaOcultaB, string nBarajaOcultaB){
    NodoBarajaOcultaB *nuevoNodoBarajaOcultaB = new NodoBarajaOcultaB();
    nuevoNodoBarajaOcultaB->barajaOcultaB = nBarajaOcultaB;
    nuevoNodoBarajaOcultaB->siguienteBarajaOcultaB = pilaNodoBarajaOcultaB;
    pilaNodoBarajaOcultaB = nuevoNodoBarajaOcultaB;
}
void insertarPilaBarajaOcultaC(NodoBarajaOcultaC *&pilaNodoBarajaOcultaC, string nBarajaOcultaC){
    NodoBarajaOcultaC *nuevoNodoBarajaOcultaC = new NodoBarajaOcultaC();
    nuevoNodoBarajaOcultaC->barajaOcultaC = nBarajaOcultaC;
    nuevoNodoBarajaOcultaC->siguienteBarajaOcultaC = pilaNodoBarajaOcultaC;
    pilaNodoBarajaOcultaC = nuevoNodoBarajaOcultaC;
}
void insertarPilaBarajaOcultaD(NodoBarajaOcultaD *&pilaNodoBarajaOcultaD, string nBarajaOcultaD){
    NodoBarajaOcultaD *nuevoNodoBarajaOcultaD = new NodoBarajaOcultaD();
    nuevoNodoBarajaOcultaD->barajaOcultaD = nBarajaOcultaD;
    nuevoNodoBarajaOcultaD->siguienteBarajaOcultaD = pilaNodoBarajaOcultaD;
    pilaNodoBarajaOcultaD = nuevoNodoBarajaOcultaD;
}
void insertarPilaBarajaOcultaE(NodoBarajaOcultaE *&pilaNodoBarajaOcultaE, string nBarajaOcultaE){
    NodoBarajaOcultaE *nuevoNodoBarajaOcultaE = new NodoBarajaOcultaE();
    nuevoNodoBarajaOcultaE->barajaOcultaE = nBarajaOcultaE;
    nuevoNodoBarajaOcultaE->siguienteBarajaOcultaE = pilaNodoBarajaOcultaE;
    pilaNodoBarajaOcultaE = nuevoNodoBarajaOcultaE;
}
void insertarPilaBarajaOcultaF(NodoBarajaOcultaF *&pilaNodoBarajaOcultaF, string nBarajaOcultaF){
    NodoBarajaOcultaF *nuevoNodoBarajaOcultaF = new NodoBarajaOcultaF();
    nuevoNodoBarajaOcultaF->barajaOcultaF = nBarajaOcultaF;
    nuevoNodoBarajaOcultaF->siguienteBarajaOcultaF = pilaNodoBarajaOcultaF;
    pilaNodoBarajaOcultaF = nuevoNodoBarajaOcultaF;
}
void insertarPilaBarajaOcultaG(NodoBarajaOcultaG *&pilaNodoBarajaOcultaG, string nBarajaOcultaG){
    NodoBarajaOcultaG *nuevoNodoBarajaOcultaG = new NodoBarajaOcultaG();
    nuevoNodoBarajaOcultaG->barajaOcultaG = nBarajaOcultaG;
    nuevoNodoBarajaOcultaG->siguienteBarajaOcultaG = pilaNodoBarajaOcultaG;
    pilaNodoBarajaOcultaG = nuevoNodoBarajaOcultaG;
}
void insertarPilaBarajaVisibleA(NodoBarajaVisibleA *&pilaNodoBarajaVisibleA, string nBarajaVisibleA){
    NodoBarajaVisibleA *nuevoNodoBarajaVisivleA = new NodoBarajaVisibleA();
    nuevoNodoBarajaVisivleA->barajaVisibleA = nBarajaVisibleA;
    nuevoNodoBarajaVisivleA->siguienteBarajaVisibleA = pilaNodoBarajaVisibleA;
    pilaNodoBarajaVisibleA = nuevoNodoBarajaVisivleA;
}
void insertarPilaBarajaVisibleB(NodoBarajaVisibleB *&pilaNodoBarajaVisibleB, string nBarajaVisibleB){
    NodoBarajaVisibleB *nuevoNodoBarajaVisivleB = new NodoBarajaVisibleB();
    nuevoNodoBarajaVisivleB->barajaVisibleB = nBarajaVisibleB;
    nuevoNodoBarajaVisivleB->siguienteBarajaVisibleB = pilaNodoBarajaVisibleB;
    pilaNodoBarajaVisibleB = nuevoNodoBarajaVisivleB;
}
void insertarPilaBarajaVisibleC(NodoBarajaVisibleC *&pilaNodoBarajaVisibleC, string nBarajaVisibleC){
    NodoBarajaVisibleC *nuevoNodoBarajaVisivleC = new NodoBarajaVisibleC();
    nuevoNodoBarajaVisivleC->barajaVisibleC = nBarajaVisibleC;
    nuevoNodoBarajaVisivleC->siguienteBarajaVisibleC = pilaNodoBarajaVisibleC;
    pilaNodoBarajaVisibleC = nuevoNodoBarajaVisivleC;
}
void insertarPilaBarajaVisibleD(NodoBarajaVisibleD *&pilaNodoBarajaVisibleD, string nBarajaVisibleD){
    NodoBarajaVisibleD *nuevoNodoBarajaVisivleD = new NodoBarajaVisibleD();
    nuevoNodoBarajaVisivleD->barajaVisibleD = nBarajaVisibleD;
    nuevoNodoBarajaVisivleD->siguienteBarajaVisibleD = pilaNodoBarajaVisibleD;
    pilaNodoBarajaVisibleD = nuevoNodoBarajaVisivleD;
}
void insertarPilaBarajaVisibleE(NodoBarajaVisibleE *&pilaNodoBarajaVisibleE, string nBarajaVisibleE){
    NodoBarajaVisibleE *nuevoNodoBarajaVisivleE = new NodoBarajaVisibleE();
    nuevoNodoBarajaVisivleE->barajaVisibleE = nBarajaVisibleE;
    nuevoNodoBarajaVisivleE->siguienteBarajaVisibleE = pilaNodoBarajaVisibleE;
    pilaNodoBarajaVisibleE = nuevoNodoBarajaVisivleE;
}
void insertarPilaBarajaVisibleF(NodoBarajaVisibleF *&pilaNodoBarajaVisibleF, string nBarajaVisibleF){
    NodoBarajaVisibleF *nuevoNodoBarajaVisivleF = new NodoBarajaVisibleF();
    nuevoNodoBarajaVisivleF->barajaVisibleF = nBarajaVisibleF;
    nuevoNodoBarajaVisivleF->siguienteBarajaVisibleF = pilaNodoBarajaVisibleF;
    pilaNodoBarajaVisibleF = nuevoNodoBarajaVisivleF;
}
void insertarPilaBarajaVisibleG(NodoBarajaVisibleG *&pilaNodoBarajaVisibleG, string nBarajaVisibleG){
    NodoBarajaVisibleG *nuevoNodoBarajaVisivleG = new NodoBarajaVisibleG();
    nuevoNodoBarajaVisivleG->barajaVisibleG = nBarajaVisibleG;
    nuevoNodoBarajaVisivleG->siguienteBarajaVisibleG = pilaNodoBarajaVisibleG;
    pilaNodoBarajaVisibleG = nuevoNodoBarajaVisivleG;
}