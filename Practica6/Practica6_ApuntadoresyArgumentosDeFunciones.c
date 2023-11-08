#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu();
int validar(char msg[], int ri, int rf);
int sumVect(int *vect, int n);
void copyVect(int *copy, int *origin, int n);
void concat(int *conca, int *vect1, int *vect2, int n, int m);
int compar(int *vect1, int *vect2, int n);
int max(int *vect, int n);
void printvect(int *vect, int n);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op, r, vectCop[5], vectConcat[10];
    int vect1[] = {4, 7, 1, 5, 9};
    int vect2[] = {6, 5, 3, 2, 7};
    int vect3[] = {4, 7, 1, 5, 9};

    do
    {
        printf("\n\t MENU \n");
        printf("1. SUMA DE ELEMENTOS EN UN ARREGLO \n");
        printf("2. COPIA DE ARREGLOS \n");
        printf("3. CONCATENACION DE ARREGLOS \n");
        printf("4. COMPARACION DE ARREGLOS \n");
        printf("5. ENCONTRAR EL ELEMENTO MAXIMO \n");
        printf("0. SALIR  \n");
        op = validar("Escoge una opcion: ", 0, 5);
        switch (op)
        {
        case 1:
            r = sumVect(vect1, 5);
            printf("Vector: \n");
            printvect(vect1, 5);
            printf("\nLa suma es %d", r);
            break;
        case 2:
            copyVect(vectCop, vect1, 5);
            printf("Copia: \n");
            printvect(vectCop, 5);
            break;
        case 3:
            concat(vectConcat, vect1, vect2, 5, 5);
            printf("Arreglo concatenado:\n");
            printvect(vectConcat, 10);
            break;
        case 4:
            printf("\nEl arreglo 1 y 2 ");
            if (compar(vect1, vect2, 5) == 1)
            {
                printf("son iguales\n");
            }
            else
            {
                printf("son diferentes\n");
            }

            printf("El arreglo 1 y 3 ");
            if (compar(vect1, vect3, 5) == 1)
            {
                printf("son iguales\n");
            }
            else
            {
                printf("son diferentes\n");
            }
            break;
        case 5:
            r = max(vect1, 5);
            printf("\nEl elemento maximo es %d", r);
            break;
        default:
            printf("\n Adios....");
            break;
        }
        system("pause");
    } while (op != 0);
}

/*
validar
valida que la opcion este dentro del rango
*/
int validar(char msg[], int ri, int rf)
{
    char cadena[50];
    int op;

    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        op = atoi(cadena);        // Convierte la cadena a un numero
    } while (op < ri || op > rf); // Valida que este dentro de los rangos

    return op;
}

/*
printvect
imprime el vector de n elementos
*/
void printvect(int *vect, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,", *(vect + i));
    }
}

/*
copyVect
copia un vector n a otro vector n
*/
void copyVect(int *copy, int *origin, int n)
{
    for (int i; i < n; i++)
    {
        *(copy + i) = *(origin + i);
    }
}

/*
sumVect
suma los n elementos de un vector
*/
int sumVect(int *vect, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += *(vect + i);
    }
    return suma;
}

/*
concat
concatena una cadena con otra sin usar la libreria string
*/
void concat(int *conca, int *vect1, int *vect2, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        *(conca + i) = *(vect1 + i);
    }
    for (int i = 0; i < m; i++)
    {
        *(conca + n + i) = *(vect2 + i);
    }
}

/*
compar
compara dos vectores
*/
int compar(int *vect1, int *vect2, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(vect1 + 1) != *(vect2 + i))
        {
            return 0;
        }
    }
    return 1;
}

/*
max
encuentra el valor mas alto en el vector
*/
int max(int *vect, int n)
{
    int maximo = vect[0];

    for (int i = 0; i < n; i++)
    {
        if (*(vect + i) > maximo)
        {
            maximo = *(vect + i);
        }
    }
    return maximo;
}
