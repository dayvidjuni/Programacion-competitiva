#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX 9

using namespace std;

bool EsSeguro(int tablero[MAX][MAX], int fila, int col, int num) {
    for (int x = 0; x < MAX; x++) {
        if (tablero[fila][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < MAX; x++) {
        if (tablero[x][col] == num) {
            return false;
        }
    }

    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool SolucionarSudoku(int tablero[MAX][MAX]) {
    int fila = -1;
    int col = -1;
    bool vacio = false;

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (tablero[i][j] == 0) {
                fila = i;
                col = j;
                vacio = true;
                break;
            }
        }
        if (vacio) {
            break;
        }
    }

    if (!vacio) {
        return true;
    }

    for (int num = 1; num <= MAX; num++) {
        if (EsSeguro(tablero, fila, col, num)) {
            tablero[fila][col] = num;

            if (SolucionarSudoku(tablero)) {
                return true;
            }

            tablero[fila][col] = 0;
        }
    }

    return false;
}

void Imprimir(int tablero[MAX][MAX]) {
    for (int fila = 0; fila < MAX; fila++) {
        if (fila % 3 == 0 && fila != 0) {
            cout << "------+-------+------" << endl;
        }

        for (int col = 0; col < MAX; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }
            cout << tablero[fila][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    ifstream archivo("in.txt");
    
    if (!archivo.is_open()) {
        cout << "Error: No se encontro el archivo in.txt" << endl;
        system("pause");
        return 1;
    }

    int tablero[MAX][MAX] = {};
    int pos_x, pos_y, valor;
    
    while (archivo >> pos_x >> pos_y >> valor) {
        if(pos_x >= 1 && pos_x <= MAX && pos_y >= 1 && pos_y <= MAX) {
            tablero[pos_x - 1][pos_y - 1] = valor;
        }
    }
    
    archivo.close();

    cout << "Tablero Inicial:" << endl;
    Imprimir(tablero);
    cout << "\n---------------------\n" << endl;

    if (SolucionarSudoku(tablero)) {
        cout << "Sudoku Resuelto:" << endl;
        Imprimir(tablero);
    } else {
        cout << "El Sudoku proporcionado no tiene solucion." << endl;
    }

    system("pause");
    return 0;
}