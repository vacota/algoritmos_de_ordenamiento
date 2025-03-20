# Algoritmos de ordenamiento

Un pequeño programa que ejecuta diferentes algoritmos de ordenamiento y recupera los datos del tiempo de ejecución.

Algoritmos utilizados
1. **Ordenamiento por Inserción**
2. **Ordenamiento de Burbuja**
3. **Ordenamiento por Selección**
4. **Ordenamiento por Mezcla**
5. **Ordenamiento Rápido**
6. **Ordenamiento por Montículos**
7. **Ordenamiento de Shell**

Los elementos a ordenar son números enteros del 1 al 1000 generados de manera aleatoria, guardados en arreglo de tamaño variable, iniciando en 10 y sumandole 10 a esa cantidad hasta llegar a 1000. Se guarda el resultado del tiempo de ejecución de cada algorimo en milisegundos y se exporta a un archivo csv con el nombre del correspondiente algoritmo.

## Preferencias para la ejecución del programa

- **GCC** (GNU Compiler Collection)
- **CMake** para la correcta ejecución del proyecto

## Instalación 🔧
1. Clone el repositorio:
   ```sh
   git clone https://github.com/vacota/algoritmos_de_ordenamiento.git
   ```
2. Entre al directorio del proyecto:
   ```sh
   cd algoritmos_de_ordenamiento
   ```
3. Compile el código:
   ```sh
   g++ sorting_time.cpp -o sorting_time -std=c++20
   ```
4. Ejecute el código
   ```sh
   ./sorting_time
   ```

## Proyecto

- **`sorting_time.cpp`**: Es el código fuente, en el que se realizan todos los procesos y se encuentran tanto la función principal **main** como las funciones de ordeamiento. Aquí se genera el arreglo a ordenar, se ejecutan los algoritmos de ordenamiento y se exportan los resultados.
- **`README.md`**: Se encuentran los detalles del proyecto y la descripción del mismo.
- **`Archivos CSV`**: Archivos que contienen los datos del tiempo y promedio entre los de misma longitud.
