#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiPorDos(int *ptr);
int numRan(int vect[], int n);
int buscar(int vect[], int n, int num);
void sumarElementos(int *ptr, int n, int num);

int main(){
    srand(time(NULL));
    int x, vect[7];
    int *ptr;
    x=3;
    ptr=&x;

    printf("El valor de x es: %d, y el valor al que apunta ptr es: %p\n", x, ptr);
    printf("El valor original de x es %d\n", x);
    multiPorDos(ptr);
    printf("El valor modificado de x es %d\n", x);

    //Esto llena el vector de 7 espacios
    for(int i=0; i<7; i++){
        vect[i]= numRan(vect, i);
    }
    //Esto imprime el vector completo
    for(int i=0; i<7; i++){
        printf("%d ", vect[i]);
    }

    sumarElementos(vect, 7, 1);
    //Esto imprime el arreglo con una suma de 1
    printf("\n El arreglo modificado es \n");
    for(int i=0; i<7; i++){
        printf(" %d", vect[i]);
    }


    return 0;
}

void multiPorDos(int *ptr){
    *ptr *= 2;
}

int numRan(int vect[], int n){
    int num;
    do{
        num= rand() % 50 + 1;
    }while(buscar(vect, n, num) != -1); //Esta condicion valida que no este
    return num;
}

int buscar(int vect[], int n, int num){
    for(int i=0; i<n; i++){
        if(vect[i]==num){
            return 1; //Regresa 1 si se encontr
        }
    }
    return -1; //Regresa -1 si no lo encontro
}

void sumarElementos(int *ptr, int n, int num){
    for(int i=0; i<n; i++){
        *(ptr+i) += num; //Suma el valor
    }
}