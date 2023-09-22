/*
Practica4_FuncionesConYSinRetorno_VazquezGuzman_Jorge.cpp
Jorge Vazquez
21 de septiembre de 2023
Programa completo de la pracrica 4. Dependiendo la opcion de la usuario calcula algun valor
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declaracio de prototipos
void calcularFibonacci(int n);
int calcularFibonacciRecursion(int n);
void GenerarTrianguloPascal(int n);
int factorial(int n);

/*
main
Funcion main, se encarga de llamar a la funcion que sea necesaria segun el usuario
nada
retorna 0
*/
int main(){
    int n, op, op2, res;
    do{
        system("CLS");
        printf("\t M E N U\n");
        printf("1. Fibonacci\n");
        printf("2. Fibonacci recursivo\n");
        printf("3. Triangulo de pascal\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &op);
        system("CLS");

        switch (op){
        case 1:
            printf("Ingresa un numero: ");
            scanf("%d", &n);
            if(n<=0){
                printf("\nIngresa un numero positivo\n");
                getch();
                break;
            }
            calcularFibonacci(n);
            printf("El resultado de %d es: \n", n);
            break;
        case 2:
            printf("Ingresa un numero: ");
            scanf("%d", &n);
            if(n<=0){
                printf("\nIngresa un numero positivo\n");
                getch();
                break;
            }
            res=calcularFibonacciRecursion(n-1);
            printf("Del numero %d, su fibonacci es: %d \n", n, res);
            system("PAUSE");
            break;
        case 3:
            printf("Ingresa el numero de filas que desea: ");
            scanf("%d", &n);
            GenerarTrianguloPascal(n);
            getch();
            break;
        default:
            printf("\n Adios");
            getch();
        break;
        }

        system("CLS");
        printf("Quieres realizar alguna otra operacion?\n1. Si\n2. No\n");
        scanf("%d",&op2);

        if(op2==1){
            main();
        }
        if(op2==2){
            printf("\nAdios...");
            break;
        }
               
    } while(op!=4);

    return 0;
}

/*
calcularFibonacci
Esta funcion cuando es llamada recibe el valor a calcular y realiza su fibonacci sin recursion
n
no retorna nada
*/
void calcularFibonacci(int n){
    int a=-1, s=1, res;

    for (int i=0; i<n; i++){
        res=a+s;
        printf(" %d", res);
        a=s;
        s=res;
    }
}

/*
calcularFibonacciRecursion
Esta funcion al ser llamada recibe el valor del cual calcular su Fibonacci con recursion
n
retorna el valor de fibonacci
*/
int calcularFibonacciRecursion(int n){
    if(n<=1){
        return n;
    }
    else{
        return calcularFibonacciRecursion(n-1) + calcularFibonacciRecursion(n-2);
    }
}

/*
Factorial
Esta funcion solo es llamada por la de pascal, ayuda a calcular su factorial
n
retorna el factorial
*/
int factorial(int n){
    int i, res=1;
    for(i=1; i<=n; i++){
        res*=i;
    }

    return res;
}

/*
GenerarTrianguloPascal
Esta funcion al ser llamada calcula n lineas del triangulo de pascal
n
no retorna nada
*/
void GenerarTrianguloPascal(int n){
    int i, j;

    for(i=0; i<n; i++){
        printf("\nFila %d: ", i+1);
        for (j=0; j<=i; j++){
            printf("%d ", (factorial(i)/(factorial(j)*factorial(i - j))));
        }
    }
}