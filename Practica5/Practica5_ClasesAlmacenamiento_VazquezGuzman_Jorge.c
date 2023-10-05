/*
Practica5_ClasesAlmacenamiento_VazquezGuzman_Jorge.c
Jorge Antonio Vazquez Guzman
30 de septiembre  de 2023
Este archivo contiene los codigos de la practica 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaracion de los prototipos
void menu(void);
void loteria(void);
int generarLoteria(void);
int generarVelocidad(void);
void carrera(void);

/*
Main
Esta funcion llama al menu y genera la semilla de rand
*/
int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

/*
Menu
Esta funcion llama a la funcion correspondiente segun seleccione el usuario
*/
void menu()
{
    int op;

    printf("\t MENU \n");
    printf("1. Loteria\n");
    printf("2. Carrera de coches\n");
    printf("0. Salir\n");
    scanf("%d", &op);
    system("CLS");

    switch (op)
    {
    case 1:
        loteria();
        break;
    case 2:
        carrera();
        break;
    default:
        printf("\nOpcion Invalida...");
    }
}

/*
generarLoteria
Esta funcion genera un numero aleatorio ganador de loteria
El ganador
*/
int generarLoteria()
{
    return rand() % 100 + 1;
}

/*
loteria
Esta funcion llama a otra para conocer el numero ganador y te dice si ganas o no
*/
void loteria()
{
    static int win = 0;
    int n;

    if (win == 0)
    {
        win = generarLoteria();
    }

    n = generarLoteria();

    if (n == win)
    {
        printf("\n¡Felicidades, ganaste la lotería!");
    }
    else
    {
        printf("\nLo siento, no ganaste esta vez");
    }
}

/*
generarVelocidad
Esta funcion genera una velocidad aleatoria para cada auto
La velocidad
*/
int generarVelocidad()
{
    return rand() % 101 + 100;
}

/*
carrera
Esta funcion llama a otro para saber las velocidades y dice que auto gano
*/
void carrera()
{
    register int c1 = generarVelocidad();
    register int c2 = generarVelocidad();
    register int c3 = generarVelocidad();
    char n1[10] = "Tilin";
    char n2[15] = "Lobo Solitario";
    char n3[20] = "Me llaman plex mami";
    int dis = 1000;
    float t1 = (float)dis / c1;
    float t2 = (float)dis / c2;
    float t3 = (float)dis / c3;

    printf("\n%s \t Velocidad: %d km/h \t Tiempo: %.2f s", n1, c1, t1);
    printf("\n%s \t Velocidad: %d km/h \t Tiempo: %.2f s", n2, c2, t2);
    printf("\n%s \t Velocidad: %d km/h \t Tiempo: %.2f s\n", n3, c3, t3);

    if (t1 < t2)
    {
        if (t1 < t3)
        {
            printf("%s es el ganador de la carrera\n", n1);
        }
        else
        {
            printf("%s es el ganador de la carrera\n", n3);
        }
    }
    else
    {
        if (t2 < t3)
        {
            printf("%s es el ganador de la carrera\n", n2);
        }
        else
        {
            printf("%s es el ganador de la carrera\n", n3);
        }
    }
}
