/*
Jorge Antonio Vazquez Guzman
Taller 7. Apuntadores y caracteres.
25 de octubre del 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones
void menu(void);
void printNames(char *name[]);
void modNames(char *name[]);
void namesPrint(char *name[]);
void inverName(char *name);
void ordNames(char *name[]);
int comparaNames(const void *a, const void *b);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    char *name[3];
    name[0] = strdup("Pyke");
    name[1] = strdup("Senna");
    name[2] = strdup("Lux");

    do
    {
        printf("\t\n MENU \n");
        printf("1. Imprimir Nombres\n");
        printf("2. Modificar nombres\n");
        printf("3. Imprimir Nombres con Apuntadores\n");
        printf("4. Cadena Invertida\n");
        printf("5. Ordenar caracteres\n");
        printf("0. Salir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printNames(name);
            break;
        case 2:
            modNames(name);
            break;
        case 3:
            namesPrint(name);
            break;
        case 4:
            for (int i = 0; i < 3; i++)
            {
                inverName(name[i]);
            }
            break;
        case 5:
            ordNames(name);
        }
        system("cls");
    } while (op != 0);
}

// Funcion que imprime los nombres
void printNames(char *name[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n", name[i]);
    }
    system("pause");
}

// Funcion que permite ingresar nuevos nombres
void modNames(char *name[])
{
    int i;
    char newName[40];

    for (i = 0; i < 3; i++)
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(newName);
        strcpy(name[i], newName);
    }

    printf("Los nombres son los siguientes: \n");
    for (i = 0; i < 3; i++)
    {
        printf("%s\n", name[i]);
    }
    system("pause");
}

// Funcion que imprime los nombres
void namesPrint(char *name[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n", name[i]);
    }
    system("pause");
}

// Funcion que invierte la cadena usando apuntadores
void inverName(char *name)
{
    int len = strlen(name);
    int j = len - 1, i = 0;
    char temp;

    while (i < j)
    {
        temp = name[i];
        name[i] = name[j];
        name[j] = temp;
        i++;
        j--;
    }
    printf("Nombre invertido con exito\n");
    system("pause");
}

// Funcion que ordena los nombres alfabeticamente
void ordNames(char *name[])
{
    qsort(name, 3, sizeof(char *), comparaNames); // Metodo de ordenacion quick sort

    printf("\nLos nombres ordenados alfabeticamente son: \n");
    for (int i = 0; i < 3; i++)
    {
        printf("Nombre: %s\n", name[i]);
    }
    system("pause");
}

// Funcion auxiliar para el metodo de quick sort
int comparaNames(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}