/* AUTORES
 * Carlos Ernesto Soto Alarcón A01747990
 * Sergio Alfonso Casillas Santoyo A01424863
 * Karime Itzel Ruvalcaba Pérez A01656188
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para dividir una cadena en un vector de enteros
vector<int> parseInput(string input) {
    vector<int> numbers;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ',')) {
        numbers.push_back(stoi(temp));
    }
    return numbers;
}

// Implementación del Randomized Binary Search Algorithm
int randomizedBinarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int randomIndex = left + rand() % (right - left + 1); // Selecciona un pivote aleatorio

        if (arr[randomIndex] == target) {
            return randomIndex;
        } else if (arr[randomIndex] < target) {
            left = randomIndex + 1;
        } else {
            right = randomIndex - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0)); // Inicializa la semilla aleatoria

    int target;
    string input;

    // Leer número objetivo
    cout << "Ingrese el número a buscar: ";
    cin >> target;
    cin.ignore();

    // Leer lista de números
    cout << "Ingrese la lista de números separados por comas: ";
    getline(cin, input);

    // Convertir la entrada en un vector de enteros
    vector<int> numbers = parseInput(input);

    // Ejecutar búsqueda binaria aleatoria
    int index = randomizedBinarySearch(numbers, 0, numbers.size() - 1, target);

    // Imprimir resultado
    if (index != -1) {
        cout << "El elemento esta presente en el indice: " << index << endl;
    } else {
        cout << "El elemento no esta presente en el arreglo" << endl;
    }

    return 0;
}
