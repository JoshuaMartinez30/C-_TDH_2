#include <iostream>
#include <stdio.h>
using namespace std;
void impresion(int *M, int f, int colum, int numero){
    int esp;
    for (int i = colum - 1; i >= 0; i--){
        for (int j = 0; j < f; j++){
            esp = (numero - M[colum * j + i]) / 2;
            for (int k = 0; k < esp; k++){
                cout << " ";
            }
            for (int k = 0; k < M[colum * j + i]; k++){
                printf("%c", 220);
            }
            for (int k = 0; k < esp; k++){
                cout << " ";
            }
            cout << "\t";
        }
        cout << "\n";
    }
}

void movimientos(int *M, int f, int colum, int numero, int A_inicial, int A_destino){
    int inicial, Destino;
    inicial = colum - 1;
    Destino = colum - 1;
    while (inicial >= 0 && M[colum * A_inicial + inicial] == 0){
        inicial--;
    }
    if (inicial < 0){
        inicial = 0;
    }
    do{
        Destino--;
    } while (Destino >= 0 && M[colum * A_destino + Destino] == 0);
    M[colum * A_destino + Destino + 1] = M[colum * A_inicial + inicial];
    M[colum * A_inicial + inicial] = 0;
    impresion(M, f, colum, numero);
}

void hanoi(int *M, int f, int colum, int discos, int numero, int A_inicial, int A_auxiliar, int A_destino)
{
    if (discos == 1){
        movimientos(M, f, colum, numero, A_inicial, A_destino);
    }
    else{
        hanoi(M, f, colum, discos - 1, numero, A_inicial, A_destino, A_auxiliar);
        movimientos(M, f, colum, numero, A_inicial, A_destino);
        hanoi(M, f, colum, discos - 1, numero, A_auxiliar, A_inicial, A_destino);
    }
}

int main()
{
    int f, colum, *M = NULL, discos, numero;
    f = 3;
    discos = 1;
    cout << "Ingrese la cantidad de discos: ";
    cin >> colum;
    M = (int *)malloc(sizeof(int) * f * colum);
    for (int i = 0; i < f; i++){
        for (int j = colum - 1; j >= 0; j--){
            if (i == 0){
                M[(colum * i) + j] = discos;
                discos += 2;
            }
            else{
                M[(colum * i) + j] = 0;
            }
        }
    }
    numero = discos;
    impresion(M, f, colum, numero);
    hanoi(M, f, colum, colum, numero, 0, 1, 2);
}