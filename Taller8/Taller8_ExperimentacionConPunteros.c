#include "procesos.h"
#define M 100
#define N 15

//Declaracion de prototipos de funciones
char solicitarLetra();
void llenarMatriz(char **q, int m, int n);

/*
Funcion main que se encarga de establecer tiempo de ejecucion de cada metodo
Llama a las funciones de busqueda lineal de cada metodo
Llama a la funcion de llenar matriz
Llama a la funcion de solicitar letra
*/

int main()
{
    clock_t start, end;
    srand(time(NULL));
    int i, k, n;
    char b[M][N];
    char *q[M];
    char **r = q;
    double tiempo1 = 0, tiempo2 = 0, tiempo3 = 0, tiempo4 = 0, tiempo5 = 0;

    for (i = 0; i < M; i++)
    {
        q[i] = &b[i][0];
    }
    llenarMatriz(r, M, N);

    printf("Ingrese la cantidad de veces que desea iterar las busquedas: ");
    scanf("%d", &n);

    char letraBusq[n];
    for (i = 0; i < n; i++)
    {
        letraBusq[i] = 'A' + rand() % 26; 
    }

    for (k = 0; k < n; k++)
    {
        char letra = letraBusq[k];

        printf("Metodo 1\n");
        start = clock();
        printMe1(&b[0][0], M, N);
        busquedaLineal_Metodo1(&b[0][0], M, N, letra);
        end = clock();
        tiempo1 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 2\n");
        start = clock();
        printMe2(&b[0][0], M, N);
        busquedaLineal_Metodo2(&b[0][0], M, N, letra);
        end = clock();
        tiempo2 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 3\n");
        start = clock();
        printMe3(b, M, N);
        busquedaLineal_Metodo3(b, M, N, letra);
        end = clock();
        tiempo3 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 4\n");
        start = clock();
        printMe4(q, M, N);
        busquedaLineal_Metodo4(q, M, N, letra);
        end = clock();
        tiempo4 += (double)(end - start) / CLOCKS_PER_SEC;

        printf("Metodo 5\n");
        start = clock();
        printMe5(r, M, N);
        busquedaLineal_Metodo5(r, M, N, letra);
        end = clock();
        tiempo5 += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("\nTiempo metodo 1: %f segundos\n", tiempo1);
    printf("Tiempo metodo 2: %f segundos\n", tiempo2);
    printf("Tiempo metodo 3: %f segundos\n", tiempo3);
    printf("Tiempo metodo 4: %f segundos\n", tiempo4);
    printf("Tiempo metodo 5: %f segundos\n", tiempo5);

    return 0;
}

/*
Funcion solicitarLetra que se encarga de solicitar una letra al usuario
Retorna la letra que selecciono el usuario
*/
char solicitarLetra()
{
    char letra;
    printf("Ingrese la letra que desea buscar: ");
    scanf(" %c", &letra);

    return letra;
}

/*
Funcion llenarMatriz que se encarga de llenar la matriz con letras aleatorias
*/
void llenarMatriz(char **q, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            q[i][j] = 'A' + rand() % 26; // Genera letras aleatorias de la A a la Z
        }
    }
}