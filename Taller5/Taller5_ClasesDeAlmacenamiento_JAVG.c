/*
Taller5_ClasesDeAlmacenamiento.c
Jorge Antonio Vazquez Guzman
30 de septiembre  de 2023
Este archivo contiene los codigos de la actividad 5
*/
#include <stdio.h>
#include <stdlib.h>
#include "externa.h" //Libreria para guardar una variable (Es mas practico y "correcto" de esta manera segun investigue)

// Variable global
float pi = 3.14159;

// Variable externa que tiene que buscar en la libreria
extern int saldo;

// Declaracion de prototipos
void vauto(void);
void menu(void);
void vext(void);
void vest(void);
void vreg(void);
void vglob(void);
void prueb(void);

// Funcion main que llama al menu
int main()
{
    menu();
    return 0;
}

// Funcion que permite al usuario seleccionar el tipo de variable que quiere usar
void menu()
{
    int op;

    printf("\t MENU\n");
    printf("1. Variable automatica\n");
    printf("2. Variable externa\n");
    printf("3. Variable estatica\n");
    printf("4. Variable de registro\n");
    printf("5. Variable global\n");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        for (int i = 0; i < 10; i++)
        {
            vauto();
        }
        break;
    case 2:
        vext();
        break;
    case 3:
        for (int i = 0; i < 10; i++)
        {
            vest();
        }
        break;
    case 4:
        vreg();
        break;
    case 5:
        vglob();
        prueb();
        break;
    default:
        printf("\nOpcion invalida...");
    }
}

// Funcion que usa la variable automatica
void vauto()
{
    int c = 0;

    for (int i = 0; i < 5; i++)
    {
        c++;
        printf("\nContador= %d", c);
    }
    // Al salir de la funcion todo esto se borra de memoria, y las variables se eliminan igual
}

// Funcion que usa una variable externa
void vext()
{
    saldo += 50;
    printf("El nuevo saldo es de %d", saldo);
    // El tiempo de vida es hasta que el programa termine su ejecucion, y puede ser usada en cualquier funcion
}

// Funcion que usa una variable estatica
void vest()
{
    static int c = 0;

    c++;
    printf("\nEl valor del contador es de %d", c);
    // Al salir de la funcion la variable sigue conservando su valor
    // Difiere al no eliminarse o "resetearse" al terminar la funcion
}

// Funcion que usa una variable de registro
void vreg()
{
    register int temp;
    int valor;

    temp = 10;
    valor = 29;
    printf("\n El valor de la variable de registro es de %d y la automatica es de %d", temp, valor);
    // Actualmente no usaria una variable de registro, pero se utilizaba para acceder mas rapido a cierta informacion
}

// Funcion que usa una variable global
void vglob()
{
    printf("\nEl valor de pi como global es %f", pi);
    // Ambito es cuando aparece o se crea fuera de cualquier bloque y la visibiladad es su rango de vida o uso
}

// Funcion que apoya a la anterior pero de manera local
void prueb()
{
    float pi = 3.141592;

    printf("\nEl valor de pi como local es %f", pi);
}
