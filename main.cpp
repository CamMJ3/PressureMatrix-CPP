#include <iostream> 
#include "matriz.h"

/** 
 * @file 
 * @brief El programa completo para la manipulación de la matriz A y el vector B.
 *
 * @details Las opciones son las siguientes:
 * - Opción: 1 Visualizar la matriz A y el vector B.
 * - Opción 2: Visualizar la resolución del sistema de ecuaciones lineales mediante el método de Gauss.
 * - Opción 3: Visualizar la matriz inversa de A y la resolución del sistema mediante el método de Gauss-Jordan.
 * - Opción 4: Salir del programa.
 */

int menu();
using namespace std;

int main()
{
    vector<vector<double>> A = {
        {4, -1, -1, 0, 0},
        {-1, 3, 0, -1, 0},
        {-1, 0, 3, 0, -1},
        {0, -1, -1, 4, -1},
        {0, 0, -1, -1, 3}
    };

    vector<double> b = {50, 0, 10, 0, 20};

    while (true)
	{
		switch (menu())
		{
        case 1:
        {
            cout << "\n--- Matriz A ---\n";
            verMatriz(A);

            cout << "\n--- Vector B ---\n";
            verVector(b);
            break;
        }
        case 2:
        {
            vector<double> sol = metodoGauss(A, b);

            cout << "\n--- Valores finales ---\n";
            for (int i = 0; i < sol.size(); i++)
            {
                cout << "P" << i+1 << " = " << sol[i] << endl;
            }

            break;
        }
		case 3:
        {
            auto inv = matrizInversa(A, b);

            cout << "\n--- Valores finales ---\n";
            for (int i = 0; i < inv.size(); i++)
            {
                cout << "P" << i+1 << " = " << inv[i] << endl;
            }

            break;
        }
        case 4:
        {
			cout << "\nSaliendo del programa...";
			exit(0);
			break;
        }
        }
    }
}

/***********************************************************************/

/** 
 * @brief Menú del programa que maneja el input (aportación) del usuario.
 *
 * @details Devuelve una opción a la función main().
 */

int menu()
{
    int opcion;
	do
	{
		cout << "\n\n\n\t--- MENU! ---";
        cout << "\n\n1) Ver la matriz A y el vector B.\n";
		cout << "2) Resolver la matriz A mediante el método de Gauss.\n";
		cout << "3) Obtener la matriz inversa de A y resolución mediante el método de Gauss-Jordan.\n";
        cout << "4) Salir del programa.\n";
		cout << "\n--> Seleccione una opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);
	return opcion;
}
