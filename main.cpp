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
// Complejidad: O(n), n es la cadena de números en la entrada
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
/**
* Complejidad en el peor caso: O(n) debido a la selección aleatoria del pivote
* Complejidad en el mejor caso: O(1) si se encuentra el elemento en la primera iteración 
* Complejidad en el caso promedio: O(log n) como en la búsqueda binaria tradicional
 */
int randomizedBinarySearch(vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int randomIndex = left + rand() % (right - left + 1); // Selecciona un pivote aleatorio (O(1))

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
    srand(time(0)); // Inicializa la semilla aleatoria O(1)

    int target;
    string input;

    // Leer número objetivo O(1)
    cout << "Ingrese el número a buscar: ";
    cin >> target;
    cin.ignore();

    // Leer lista de números O(n)
    cout << "Ingrese la lista de números separados por comas: ";
    getline(cin, input); 

    // Convertir la entrada en un vector de enteros O(n)
    vector<int> numbers = parseInput(input);

    // Ejecutar búsqueda binaria aleatoria
    int index = randomizedBinarySearch(numbers, 0, numbers.size() - 1, target);

    // Imprimir resultado O(1)
    if (index != -1) {
        cout << "El elemento esta presente en el indice: " << index << endl;
    } else {
        cout << "El elemento no esta presente en el arreglo" << endl;
    }

    return 0;
}
