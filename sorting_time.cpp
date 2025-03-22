#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <thread>
#include <filesystem>

#define NUM_PRUEBAS 1000
#define MIN_TAMANO 10
#define MAX_TAMANO 1000
#define INCREMENTO 10
#define NUM_ALGORITMOS 7

// Prototipos de funciones principales
void insertion_sort(int arr[], int n);   // 1
void bubble_sort(int arr[], int n);      // 2
void selection_sort(int arr[], int n);   // 3
void merge_sort(int arr[], int n);       // 4
void quick_sort(int arr[], int n);       // 5
void heap_sort(int arr[], int n);        // 6
void shell_sort(int arr[], int n);       // 7

// Prototipos de funciones auxiliares
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void swap(int* a, int* b);
int Partition(int arr[], int inicio, int fin);
void QuickSortHelper(int arr[], int inicio, int fin);
void heapify(int arr[], int length, int i);

using namespace std;
using namespace std::chrono;
namespace fs = std::filesystem;

double insertion_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double bubble_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double selection_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double merge_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double quick_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double heap_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];
double shell_time[NUM_PRUEBAS+1][(MAX_TAMANO/INCREMENTO)+1];

int main() {
    srand(time(nullptr));
    const int length = MAX_TAMANO;
    int arr[length];
    int iterations = NUM_PRUEBAS+1;
    int column_counter = 1;
    int length_counter = MIN_TAMANO;
    double total_insertion = 0;
    double total_bubble = 0;
    double total_selection = 0;
    double total_merge = 0;
    double total_quick = 0;
    double total_heap = 0;
    double total_shell = 0;

    cout << "Leer el README de github para mayor comprensi\242n del programa" << endl;
    cout << "El programa se ejecutar\240 en" << endl;
    for (int i = 5; i > 0; --i) {
        cout << i << "\n";
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Inicia ciclo para contar tiempo
    for (int j = 1; j < 101; j++) {
        // Se repite mil veces el proceso para un mismo length_counter
        cout << "Ejecutando algoritmos en longitud " << length_counter << "..." << endl;
        for (int i = 1; i < iterations; i++) {

            // Genera un arreglo de numeros aleatoreos del 1 al 1000 de longitud lenght
            for (int k = 0; k < length_counter; k++) {
                arr[k] = 1 + rand() % 1000;
            }


                // Insertion
            // Inicia el timer
            auto insertion_start = high_resolution_clock::now();
            insertion_sort(arr, length_counter);
            // Termina el timer
            auto insertion_end = high_resolution_clock::now();
            duration<double> insertion_duration = insertion_end - insertion_start;
            insertion_time[i][column_counter] = insertion_duration.count() * 1000;
            total_insertion += insertion_time[i][column_counter];

                // Bubble
            // Inicia el timer
            auto bubble_start = high_resolution_clock::now();
            bubble_sort(arr, length_counter);
            // Termina el timer
            auto bubble_end = high_resolution_clock::now();
            duration<double> bubble_duration = bubble_end - bubble_start;
            bubble_time[i][column_counter] = bubble_duration.count() * 1000;
            total_bubble += bubble_time[i][column_counter];

                // Selection
            // Inicia el timer
            auto selection_start = high_resolution_clock::now();
            selection_sort(arr, length_counter);
            // Termina el timer
            auto selection_end = high_resolution_clock::now();
            duration<double> selection_duration = selection_end - selection_start;
            selection_time[i][column_counter] = selection_duration.count() * 1000;
            total_selection += selection_time[i][column_counter];

                // Merge
            // Inicia el timer
            auto merge_start = high_resolution_clock::now();
            merge_sort(arr, length_counter);
            // Termina el timer
            auto merge_end = high_resolution_clock::now();
            duration<double> merge_duration = merge_end - merge_start;
            merge_time[i][column_counter] = merge_duration.count() * 1000;
            total_merge += merge_time[i][column_counter];

                // Quick
            // Inicia el timer
            auto quick_start = high_resolution_clock::now();
            quick_sort(arr, length_counter);
            // Termina el timer
            auto quick_end = high_resolution_clock::now();
            duration<double> quick_duration = quick_end - quick_start;
            quick_time[i][column_counter] = quick_duration.count() * 1000;
            total_quick += quick_time[i][column_counter];

                // Heap
            // Inicia el timer
            auto heap_start = high_resolution_clock::now();
            heap_sort(arr, length_counter);
            // Termina el timer
            auto heap_end = high_resolution_clock::now();
            duration<double> heap_duration = heap_end - heap_start;
            heap_time[i][column_counter] = heap_duration.count() * 1000;
            total_heap += heap_time[i][column_counter];

                // Shell
            // Inicia el timer
            auto shell_start = high_resolution_clock::now();
            shell_sort(arr, length_counter);
            // Termina el timer
            auto shell_end = high_resolution_clock::now();
            duration<double> shell_duration = shell_end - shell_start;
            shell_time[i][column_counter] = shell_duration.count() * 1000;
            total_shell += shell_time[i][column_counter];

        }
        cout << "Algoritmos en longitud " << length_counter << " ejecutados!" << endl << endl;

        insertion_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_insertion / 1000.0;
        bubble_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_bubble / 1000.0;
        selection_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_selection / 1000.0;
        merge_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_merge / 1000.0;
        quick_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_quick / 1000.0;
        heap_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_heap / 1000.0;
        shell_time[(MAX_TAMANO/INCREMENTO)+1][j-1] = total_shell / 1000.0;

        column_counter++;
        length_counter += INCREMENTO;

        total_insertion = 0;
        total_bubble = 0;
        total_selection = 0;
        total_merge = 0;
        total_quick = 0;
        total_heap = 0;
        total_shell = 0;
    }

    int recorrido = (MAX_TAMANO/INCREMENTO)+1;
    int tamanos = (MAX_TAMANO/INCREMENTO);

        // Insersion
    // Abre un archivo para escribir los tiempos
    ofstream outFileInsertion("1_Insercion_Ordenamiento.csv");
    if (!outFileInsertion.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileInsertion << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileInsertion << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileInsertion <<  insertion_time[i][j] << ",";
        }
        outFileInsertion << endl;
    }
    outFileInsertion << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileInsertion << insertion_time[recorrido][i] << ",";
    }
    outFileInsertion.close();


    // Bubble
    // Abre un archivo para escribir los tiempos
    ofstream outFileBubble("2_Burbuja_Ordenamiento.csv");
    if (!outFileBubble.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileBubble << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileBubble << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileBubble <<  bubble_time[i][j] << ",";
        }
        outFileBubble << endl;
    }
    outFileBubble << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileBubble << bubble_time[recorrido][i] << ",";
    }
    outFileBubble.close();


        // Selection
    // Abre un archivo para escribir los tiempos
    ofstream outFileSelection("3_Seleccion_Ordenamiento.csv");
    if (!outFileSelection.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileSelection << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileSelection << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileSelection <<  selection_time[i][j] << ",";
        }
        outFileSelection << endl;
    }
    outFileSelection << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileSelection << selection_time[recorrido][i] << ",";
    }
    outFileSelection.close();

        // Merge
    // Abre un archivo para escribir los tiempos
    ofstream outFileMerge("4_Mezcla_Ordenamiento.csv");
    if (!outFileMerge.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileMerge << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileMerge << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileMerge <<  merge_time[i][j] << ",";
        }
        outFileMerge << endl;
    }
    outFileMerge << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileMerge << merge_time[recorrido][i] << ",";
    }
    outFileMerge.close();



        // Quick
    // Abre un archivo para escribir los tiempos
    ofstream outFileQuick("5_Rapido_Ordenamiento.csv");
    if (!outFileQuick.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileQuick << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileQuick << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileQuick <<  quick_time[i][j] << ",";
        }
        outFileQuick << endl;
    }
    outFileQuick << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileQuick << quick_time[recorrido][i] << ",";
    }
    outFileQuick.close();


        // Heap
    // Abre un archivo para escribir los tiempos
    ofstream outFileHeap("6_Monticulos_Ordenamiento.csv");
    if (!outFileHeap.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileHeap << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileHeap << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileHeap <<  heap_time[i][j] << ",";
        }
        outFileHeap << endl;
    }
    outFileHeap << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileHeap << heap_time[recorrido][i] << ",";
    }
    outFileHeap.close();


        // Shell
    // Abre un archivo para escribir los tiempos
    ofstream outFileShell("7_Shell_Ordenamiento.csv");
    if (!outFileShell.is_open()) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1; // Exit the program if the file cannot be opened
    }
    length_counter = 0;
    for (int i = 0; i < recorrido; i++) {
        outFileShell << "Tama\361o " << length_counter << ",";
        length_counter += INCREMENTO;
    }
    for (int i = 0; i < iterations; i++){
        outFileShell << i << ",";
        for (int j = 1; j < recorrido; j++){
            outFileShell <<  shell_time[i][j] << ",";
        }
        outFileShell << endl;
    }
    outFileShell << "Promedio:,";
    for (int i = 0; i < tamanos; i++) {
        outFileShell << shell_time[recorrido][i] << ",";
    }
    outFileShell.close();

    cout << "Se han generado los archivos con extensi\242n .csv de todos los algoritmos." << endl;

    return 0;
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
           arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

// Función Burbuja
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}

// Función Selección
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Intercambio de elementos
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Función Mezcla
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int n) {

    mergeSort(arr, 0, n - 1);

}

// Función Rápido
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int inicio, int fin) {
    int pivote = arr[fin]; // Selecciona el último elemento como pivote
    int i = inicio - 1; // Índice del elemento más pequeño

    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivote) {
            i++; // Incrementa el índice del elemento más pequeño
            swap(&arr[i], &arr[j]); // Intercambia arr[i] y arr[j]
        }
    }
    swap(&arr[i + 1], &arr[fin]); // Intercambia el pivote con arr[i + 1]
    return i + 1; // Retorna el índice del pivote
}

void QuickSortHelper(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        // Obtiene el índice del pivote
        int pivote_idx = Partition(arr, inicio, fin);

        // Ordena recursivamente los elementos antes y después de la partición
        QuickSortHelper(arr, inicio, pivote_idx - 1);
        QuickSortHelper(arr, pivote_idx + 1, fin);
    }
}

void quick_sort(int arr[], int n) {

    QuickSortHelper(arr, 0, n - 1);


}

// Función Montículo
void heapify(int arr[], int length, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, length, largest);
    }
}

void heap_sort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}

// Función Shell
void shell_sort(int arr[], int n) {
    // Inicializar la secuencia de gaps (intervalos)
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Aplicar el insertion sort para cada gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Almacena el valor actual
            int j;
            // Desplazar los elementos anteriores que son mayores que temp
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Colocar temp en su posición correcta
            arr[j] = temp;
        }
    }

}