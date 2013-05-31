/**
\file deikstra.cpp 
*/

/**
\fn int main() 
*/

#include <stdlib.h>
#include <math.h>
#include <iosfwd>
#include <limits.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
const int N = 6; ///количество вершин
using namespace std;

/** 
@function main
Главная функция
*/

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int predok[N], nach = 0, D[N];
    bool flag[N];
   
    int A[N][N] = {				///массив хранящий расстояние 
        {0, 3, 11, 14, 22, 22},
        {3, 0, 7, 22, 12, 15},
        {11, 7, 0, 2, 22, 11},
        {14, 22, 2, 0, 9, 22},
        {22, 12, 22, 9, 0, 6},
        {22, 15, 11, 22, 6, 0}
    };

    for (int i = 0; i < N; i++) {
        predok[i] = nach;
        flag[i] = false;
        D[i] = A[nach][i];
    }

    /** Пока известно только одно расстояние:
      от вершины nach  до нее же, равное 0.
     */
    flag[nach] = true;
    predok[nach] = 0;
    for (int i = 0; i < N - 1; i++) {
        int k = 0;
        int minras = 22;
        /// Находим минимальное расстояние до непомеченных вершин
        for (int j = 0; j < N; j++) {
            if (!flag[j] && minras > D[j]) {
                minras = D[j];
                k = j;
            }
        }
        /// Вершина k помечается просмотренной
        flag[k] = true;
        for (int j = 0; j < N; j++) {
            /** Если для вершины j еще не найдено кратчайшее расстояние от
             нач. и из вершины k по дуге A[k][j] путь в j короче
              чем найденное ранее, то запоминаем его.
             */
            if (!flag[j] && D[j] > D[k] + A[k][j]) {
                D[j] = D[k] + A[k][j];
                predok[j] = k;
            }
        }
    }

    cout<<"Расстояния:"<<endl;
    for (int i = 0; i < N; i++) {
        printf("От %d до %d: %d\n", nach, i, D[i]);
    }

    getch();
    return 0;
}