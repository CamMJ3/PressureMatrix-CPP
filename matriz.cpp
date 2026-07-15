#include <iostream>
#include <iomanip>
#include "matriz.h"

using namespace std;

/** 
 * @file 
 * @brief Implementación de los constructores para resolver el sistema de ecuaciones lineales representado
 * en la matriz A y el vector B.
 */

using namespace std;

/***********************************************************************/

/** 
 * @brief Imprime el contenido de la matriz A.
 * @details Se itera sobre cada fila de la matriz A, imprimiendo los coeficientes respectivos.
 * @param A Matriz de coeficientes del sistema de ecuaciones lineales.
 */

void verMatriz(const vector<vector<double>>& A) 
{
    for (auto& row : A) {
        for (auto val : row)
            cout << setw(8) << val << " ";
        cout << endl;
    }
}

/***********************************************************************/

/** 
 * @brief Imprime el contenido del vector B, el cual corresponde a los resultados de cada ecuación del sistema lineal.
 * @details Se itera sobre cada elemento del vector B, imprimiendo los resultados respectivos.
 * @param b Vector de resultados del sistema de ecuaciones lineales.
 */

void verVector(const vector<double>& b) 
{
    for (auto val : b)
        cout << setw(8) << val << endl;
}

/***********************************************************************/

/** 
 * @brief Resuelve la matriz A mediante el método de eliminación de Gauss, devolviendo el valor de las incógnitas del sistema.
 * @details Transforma la matriz A, primero, en una matriz aumentada de A que incluye el vector B, posteriormente, se transforma 
 * en una matriz triangular superior, normalizando cada fila (el pivote se vuelve 1) y eliminando los coeficientes debajo del pivote (los
 * coeficientes debajo del pivote se vuelven 0).
 * 
 * Para encontrar el valor de las incógnitas, se sustituye a partir de la última fila hacia arriba.
 * 
 * @param A Matriz de coeficientes del sistema de ecuaciones lineales.
 * @param b Vector de resultados del sistema de ecuaciones lineales.
 */

vector<double> metodoGauss(vector<vector<double>> A, vector<double> b) 
{
    int n = A.size();

    cout << "\n--- MÉTODO DE GAUSS ---\n";

    for (int i = 0; i < n; i++) 
    {
        double pivot = A[i][i];

        for (int j = i; j < n; j++)
            A[i][j] /= pivot;
        b[i] /= pivot;

        cout << "\nPaso " << i+1 << " (Normalizar fila " << i+1 << "):\n";
        verMatriz(A);
        verVector(b);

        for (int k = i+1; k < n; k++) 
        {
            double factor = A[k][i];
            for (int j = i; j < n; j++)
                A[k][j] -= factor * A[i][j];
            b[k] -= factor * b[i];
        }

        cout << "\nEliminación en columna " << i+1 << ":\n";
        verMatriz(A);
        verVector(b);
    }

    vector<double> x(n);

    for (int i = n-1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i+1; j < n; j++)
            x[i] -= A[i][j] * x[j];
    }

    cout << "\n--- RESULTADO DEL MÉTODO DE GAUSS ---\n";
    verVector(x);

    return x;
}

/***********************************************************************/

/** 
 * @brief Obtiene la matriz inversa de A utilizando el método de eliminación de Gauss-Jordan.
 * @details Se utiliza la matriz identidad para transformar la matriz A en una matriz aumentada, posteriormente,
 * se normaliza cada fila (el pivote se vuelve 1) y elimina los coeficientes debajo del pivote (los coeficientes debajo 
 * del pivote se vuelven 0), a tal modo que la matriz A se transforme en una matriz identidad.
 * 
 * La matriz identidad, una vez transformada, se convierte en la matriz inversa de A, la cual es necesaria
 * para encontrar las incógnitas del sistema de ecuaciones lineales al multiplicarla por el vector B.
 * 
 * @param a Matriz de coeficientes del sistema de ecuaciones lineales.
 * @param b Vector de resultados del sistema de ecuaciones lineales.
 */

vector<double> matrizInversa(vector<vector<double>> A, const vector<double>& b) 
{
    int n = A.size();
    vector<vector<double>> I(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        I[i][i] = 1;

    cout << "\n--- MATRIZ INVERSA DE A ---\n";

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];

        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            I[i][j] /= pivot;
        }

        cout << "\nNormalizando fila " << i+1 << ":\n";
        verMatriz(A);

        for (int k = 0; k < n; k++) 
        {
            if (k != i) 
            {
                double factor = A[k][i];
                for (int j = 0; j < n; j++) 
                {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }

        cout << "\nEliminando columna " << i+1 << ":\n";
        verMatriz(A);
    }

    cout << "\n--- MATRIZ INVERSA DE A ---\n";
    verMatriz(I);

    vector<double> x = productoMatrices(I, b);

    cout << "\n--- RESULTADO DEL MÉTODO DE GAUSS-JORDAN ---\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "P" << i+1 << " = " << x[i] << endl;
    }

    return x; 
}

/***********************************************************************/

/** 
 * @brief Multiplica la matriz A por el vector B, lo cual es útil para calcular el producto de la matriz inversa de A por el vector B.
 * @details Se multiplica cada fila de la matriz A por el vector B, sumando los productos para encontrar el valor de cada incógnita del
 * sistema de ecuaciones lineales.
 * @param a Matriz de coeficientes del sistema de ecuaciones lineales.
 * @param b Vector de resultados de sistemas de ecuaciones lineales.
 */

vector<double> productoMatrices(const vector<vector<double>>& A, const vector<double>& b) 
{
    int n = A.size();
    vector<double> result(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i] += A[i][j] * b[j];
        }
    }

    return result;
} 
