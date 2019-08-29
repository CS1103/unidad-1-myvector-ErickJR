//
// Created by utec on 29/08/19.
//

#include "Matriz.h"
Matriz::Matriz(char *rute) {
    FILE *F;
    F = freopen(rute, "r", stdin);
    cin >> fila >> columna;
    matriz.resize(fila);
    for(int i=0; i<fila; i++) matriz[i].resize(columna);
    char x;
    for(int i=0; i<fila; i++){
        for(int j=0; j<columna; j++){
            cin >> x;
            matriz[i][j] = x-'0';
        }
    }
    fclose(F);
    factor_fila = 1;
    factor_columna = 1;

}
Matriz::Matriz(const Imagen &other) {
    factor_fila = other.factor_fila;
    factor_columna = other.factor_columna;
    fila = other.fila;
    columna = other.columna;
    matriz.resize(factor_fila*fila);
    for(int i=0; i<factor_fila*fila; i++){
        matriz[i].resize(factor_columna*columna);
        for(int j=0; j<factor_columna*columna; j++)
            matriz[i][j] = other.matriz[i][j];
    }

