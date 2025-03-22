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

## Explicación del funcionamiento del programa

El programa para calcular el tiempo de ejecución de los algortimos fue realizado a partir del hecho de ordenar un arreglo con valores aleatorios en un intervalo que va aumentando cada vez que los algoritmos de ordenamiento ejecutaban su trabajo un total de 1000 veces cada uno.

Iniciamos con la idea de tener un arreglo con "n" valores aleatorios que se generan a partir de un intervalo de "n" espacios con un incremento (el que por defecto es 10) asignado por una variable global.

   #### Arreglo a ordenar

Pero, **¿qué pasa con nuestro arreglo de números?**. El arreglo tiene una cantidad estática de elementos dado por una constante, y la forma en la que ordenamos esos elementos se restringe al intervalo que estamos evaluando pese a que el arreglo tenga más elementos "basura" en otros indices del arreglo. Esto se explica en el siguiente ejemplo:

Tenemos el arreglo de dimensión 1000 arr[n], donde n = 1000 y en el que sus elementos están dados por índices: [ , , , , , , , ]
                                                                                                                1 2 3 4 5 ...n-1

Al empezar el programa se generarían 10 números aleatorios en dicho arreglo, pero pese a eso, el arreglo se vería algo así: [10, 400, 231, 678, 144, 958, 567, 407, 701, 580, ..., 3214124, 243214, 1, 34324]

**¿Por qué pasa esto?** Esto pasa debido a los números basura que se encuentran en la memoria de la computadora, **¿pero deberíamos preocuparnos por ellos?** la respuesta es que no, debido a que el programa está diseñado para que **no** se pueda acceder a ese espacio del arreglo hasta que se hayan generado nuevos números aleatorios en esas posiciones y hasta que nuestro contador que mida la longitud lo permita.

      #### Algoritmos de ordenamiento





