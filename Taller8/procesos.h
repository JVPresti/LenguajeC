#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declaracion de prototipos de funciones
void printMe1(char *p, int m, int n);
void printMe2(char v[], int m, int n);
void printMe3(char A[][3], int m, int n);
void printMe4(char *p[], int m, int n);
void printMe5(char **q, int m, int n);

void busquedaLineal_Metodo1(char *p, int m, int n, char letra);
void busquedaLineal_Metodo2(char v[], int m, int n, char letra);
void busquedaLineal_Metodo3(char A[][3], int m, int n, char letra);
void busquedaLineal_Metodo4(char *p[], int m, int n, char letra);
void busquedaLineal_Metodo5(char **q, int m, int n, char letra);

/*
Funciones que se encargan de imprimir la matriz con cada metodo
Reciben el puntero al vector, el tamaño de la matriz y el tamaño de la matriz
*/

void printMe1(char *p, int m, int n)
{
    int i, j;
    printf("\nLa matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c\t", *(p + i * n + j));
        }
        printf("\n");
    }
}

void printMe2(char v[], int m, int n)
{
    int i, j;
    printf("\nLa matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c\t", v[i * n + j]);
        }
        printf("\n");
    }
}

void printMe3(char A[][3], int m, int n)
{
    int i, j;
    printf("\nLa matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c\t", A[i][j]);
        }
        printf("\n");
    }
}

void printMe4(char *p[], int m, int n)
{
    int i, j;
    printf("\nLa matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c\t", p[i][j]);
        }
        printf("\n");
    }
}

void printMe5(char **q, int m, int n)
{
    int i, j;
    printf("\nLa matriz es: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c\t", q[i][j]);
        }
        printf("\n");
    }
}

/*
Funciones que buscan una letra en el vector de caracteres y regresa la posicion 
Esto para cada uno de los 5 metodos
Reciben el puntero al vector, el tamaño de la matriz, el tamaño de la matriz y la letra a buscar
*/

void busquedaLineal_Metodo1(char *p, int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (*(p + i * n + j) == letra)
            {
                printf("Letra %c encontrada en posicion [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("Letra %c no encontrada\n", letra);
}

void busquedaLineal_Metodo2(char v[], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i * n + j] == letra)
            {
                printf("Letra %c encontrada en posicion [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("Letra %c no encontrada\n", letra);
}

void busquedaLineal_Metodo3(char A[][3], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == letra)
            {
                printf("Letra %c encontrada en posicion [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("Letra %c no encontrada\n", letra);
}

void busquedaLineal_Metodo4(char *p[], int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i][j] == letra)
            {
                printf("Letra %c encontrada en posicion [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("Letra %c no encontrada\n", letra);
}

void busquedaLineal_Metodo5(char **q, int m, int n, char letra)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i][j] == letra)
            {
                printf("Letra %c encontrada en posicion [%d][%d]\n", letra, i, j);
                return;
            }
        }
    }
    printf("Letra %c no encontrada\n", letra);
}
