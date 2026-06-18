# 1. Descripción del Proyecto

Este programa desarrollado en C++ permite evaluar y comparar la eficiencia de seis algoritmos de ordenamiento clásicos: Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Shell Sort y Heap Sort.

El usuario ingresa la cantidad de números a generar y el rango de estos. El programa genera un array aleatorio y procede a ordenar los datos utilizando cada uno de los algoritmos.
Finalmente, se muestra una tabla de clasificación ordenada de menor a mayor según el tiempo de ejecución medido en nanosegundos.

También se incluye la cantidad de pasos operacione realizados por cada algoritmo y el array final ordenado de cada uno de ellos.

# 2. Instrucciones: Cómo compilar y correr el programa
Para ejecutar este código, es necesario tener instalado un compilador de C++.
## 1. Clonar el repositorio
git clone https://github.com/dayvidjuni/Programacion-competitiva

## 2. Compilar el código fuente
g++ main.cpp -o comparador

## 3. Ejecutar el programa

### En Windows:
comparador.exe

### En Linux:
./comparador
# 3. Ejemplos de Ejecución
A continuación se presentan dos escenarios reales de ejecución del programa.

## Ejemplo 1: Evaluación básica con 6 elementos (Rango positivo)

Enter the amount of numbers to generate: 6

Enter the range of numbers (minimum and maximum): 1 50

Do you want to continue and see the comparison? (y/n): y

=== STATISTICS ===

[1ST PLACE] Insertion Sort | Steps: 22  | Time: 400 ns
Sorted Array: [ 4 12 19 33 41 48 ]

Position 2: Selection Sort | Steps: 31  | Time: 500 ns
Sorted Array: [ 4 12 19 33 41 48 ]

Position 3: Shell Sort     | Steps: 35  | Time: 600 ns
Sorted Array: [ 4 12 19 33 41 48 ]

Position 4: Quick Sort     | Steps: 42  | Time: 800 ns
Sorted Array: [ 4 12 19 33 41 48 ]

Position 5: Bubble Sort    | Steps: 45  | Time: 900 ns
Sorted Array: [ 4 12 19 33 41 48 ]

Position 6: Heap Sort      | Steps: 54  | Time: 1200 ns
Sorted Array: [ 4 12 19 33 41 48 ]

## Ejemplo 2: Evaluación con un rango mixto (negativos y positivos, 10 elementos)

Enter the amount of numbers to generate: 10

Enter the range of numbers (min and max): -50 50

Do you want to continue and see the comparison? (y/n): y

=== STATISTICS ===

[1ST PLACE] Quick Sort     | Steps: 65  | Time: 900 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]

Position 2: Shell Sort     | Steps: 82  | Time: 1100 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]

Position 3: Insertion Sort | Steps: 95  | Time: 1300 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]

Position 4: Heap Sort      | Steps: 110 | Time: 1600 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]

Position 5: Selection Sort | Steps: 145 | Time: 2100 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]

Position 6: Bubble Sort    | Steps: 165 | Time: 2500 ns
Sorted Array: [ -45 -30 -12 -5 0 8 19 25 38 49 ]   

*Nota: Los tiempos de ejecución exactos pueden variar según el hardware utilizado.
