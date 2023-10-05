/*
Escribe un programa en C que encuentre y muestre todos los números perfectos en un rango dado por el usuario.
Un número perfecto es un número entero positivo que es igual a la suma de sus divisores propios positivos (excluyendo a sí mismo).
Requisitos del programa:
+Solicita al usuario que ingrese un número entero positivo "n" que representa el rango.
+El programa buscará números perfectos en el rango de 1 a "n".
+Valida que "n" sea un número entero positivo.
+Si encuentras un número perfecto, muestra ese número y sus divisores propios positivos.
+Después de encontrar todos los números perfectos en el rango, pregunta al usuario si desea buscar números perfectos en otro rango.
 Si la respuesta es afirmativa, el programa debe repetirse; de lo contrario, debe finalizar.
*/
#include <stdio.h>
#include <stdlib.h>

int sumver(int n);

int main()
{
    int n, op;
    do
    {
    again: //Esta etiqueta es para la validacion
        printf("Ingrese un numero entero positvo: \n");
        scanf("%d", &n);
        if (n > 0)
        {
            sumver(n);
        }
        else
        {
            printf("\n Debe ingresar un numero entero positivo mayor a 0\n");
            goto again;
        }

        printf("\nDeseas intentarlo nuevamente?\n 1.Si \n 0.No\n");
        scanf("%d", &op);

    } while (op != 0);
    system("CLS");
    printf("\nHasta luego...");

    return 0;
}

//Funcion que verifica e imprime si es o no un numero perfecto
int sumver(int n)
{
    int i, sum;

    sum = 0;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i; //Esto me da la suma de los divisores exactos
        }
    }
    if (sum == n) //En caso de ser perfecto en este ciclo me lo imprime
    {
        printf("El numero es perfecto, y los numeros que lo componen son: ");
        for (i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                printf("%d ", i);
            }
        }
    }
    else{
        printf("El numero no es perfecto\n");
    }
    return sum;
}
