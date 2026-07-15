#pragma once
#include <vector>

/** 
 * @file 
 * @brief Define los constructores para resolver sistemas de ecuaciones lineales mediante matrices.
 * @details El presente archivo contiene los prototipos de las funciones necesarias para imprimir el contenido
 * de la matriz A y el vector B del problema situado, así como para resolver la matriz A utilizando el método de
 * eliminación de Gauss, obtener la matriz inversa de A, y multiplicar la matriz A por el vector B, con el
 * próposito de encontrar el valor de las incógnitas del sistema de ecuaciones lineales.
 * @author Camila A. J. M.
 */

using namespace std;

void verMatriz(const vector<vector<double>>& A); ///< Imprime el contenido de la matriz A.
void verVector(const vector<double>& b); ///< Imprime el contenido del vector B, el cual corresponde a los resultados de cada ecuación del sistema lineal.

vector<double> metodoGauss(vector<vector<double>> A, vector<double> b); ///< Resuelve la matriz A mediante el método de eliminación de Gauss, devolviendo el valor de las incógnitas del sistema.
vector<double> matrizInversa(vector<vector<double>> A, const vector<double>& b); ///< Obtiene la matriz inversa de A utilizando el método de eliminación de Gauss-Jordan.
vector<double> productoMatrices(const vector<vector<double>>& A, const vector<double>& b); ///< Multiplica la matriz A por el vector B, lo cual es útil para calcular el producto de la matriz inversa de A por el vector B.
