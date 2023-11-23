#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char enfermedad[50];
    int age;
    int status;
    int total;
} Pet;

void agregar(Pet vect[], int i);
void actualizar(Pet vect[], int i, int search);
void imprimir(Pet vect[], int i);
int buscar(Pet vect[], int i, int search);
void archivo(Pet vect[], int i);
int cargar(Pet vect[], int i);

int main()
{
    Pet vect[50];
    int op, i = 0, search, posi;

    do
    {
        system("cls");
        printf("\t MENU\n");
        printf("1. Agregar\n");
        printf("2. Actualizar\n");
        printf("3. Imprimir\n");
        printf("4. Buscar\n");
        printf("5. Archivo (Guardar)\n");
        printf("6. Archivo (Cargar)\n");
        printf("0. Salir\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            agregar(vect, i);
            i++;
            break;
        case 2:
            printf("Ingrese el numero de registro a actualizar: ");
            scanf("%d", &search);
            search--;
            actualizar(vect, i, search);
            break;
        case 3:
            imprimir(vect, i);
            break;
        case 4:
            printf("Ingrese el numero de registro a buscar: ");
            scanf("%d", &search);
            posi=buscar(vect, i, search);
            printf("\nSe encuentra en la posicion %d\n", posi);
            break;
        case 5:
            archivo(vect, i);
            break;
        case 6:
            i=cargar(vect, i);
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (op != 0);
    return 0;
}

void agregar(Pet vect[], int i)
{
    printf("Ingrese el nombre de la mascota: ");
    scanf("%s", vect[i].name);
    printf("Ingrese la enfermedad de la mascota: ");
    scanf("%s", vect[i].enfermedad);
    printf("Ingrese la edad de la mascota: ");
    scanf("%d", &vect[i].age);
    printf("Ingrese el identificador de la mascota: ");
    scanf("%d", &vect[i].status);
    printf("Ingrese el total de visitas: ");
    scanf("%d", &vect[i].total);
}

void actualizar(Pet vect[], int i, int search)
{
    int op;
    printf("1. Nombre\n");
    printf("2. Enfermedad\n");
    printf("3. Edad\n");
    printf("4. Identificador\n");
    printf("5. Total de visitas\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("Ingrese el nuevo nombre: ");
        scanf("%s", vect[search].name);
        break;
    case 2:
        printf("Ingrese la nueva enfermedad: ");
        scanf("%s", vect[search].enfermedad);
        break;
    case 3:
        printf("Ingrese la nueva edad: ");
        scanf("%d", &vect[search].age);
        break;
    case 4:
        printf("Ingrese el nuevo identificador: ");
        scanf("%d", &vect[search].status);
        break;
    case 5:
        printf("Ingrese el nuevo total de visitas: ");
        scanf("%d", &vect[search].total);
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
}

void imprimir(Pet vect[], int i)
{
    for (int j = 0; j < i; j++)
    {
        printf("Nombre: %s\n", vect[j].name);
        printf("Enfermedad: %s\n", vect[j].enfermedad);
        printf("Edad: %d\n", vect[j].age);
        printf("Identificador: %d\n", vect[j].status);
        printf("Total de visitas: %d\n", vect[j].total);
        printf("\n");
        system("pause");
    }
}

int buscar(Pet vect[], int i, int search){
    int j;
    for(j=0; j<i; j++){
        if(search == j){
            printf("Se encontro el registro\n");
            printf("Nombre: %s\n", vect[j].name);
            printf("Enfermedad: %s\n", vect[j].enfermedad);
            printf("Edad: %d\n", vect[j].age);
            printf("Identificador: %d\n", vect[j].status);
            printf("Total de visitas: %d\n", vect[j].total);
            printf("\n");
            system("pause");
            return j;
        }
    }
    return -1;
}

void archivo(Pet vect[], int i){
    int j;
    FILE *fa;
    fa = fopen("datos.txt", "w");
    for (j = 0; j < i; j++)
    {
        fprintf(fa, "%-9s   %-15s   %-10d   %-10d   %-4d \n", vect[j].name, vect[j].enfermedad, vect[j].age, vect[j].status, vect[j].total);
    }

    printf("Archivo escrito con exito\n");
    fclose(fa);
    system("pause");
}

int cargar(Pet vect[], int i){
    int j;
    FILE *fa;
    fa = fopen("datos.txt", "r");
    for (j = 0; j < i; j++)
    {
        fscanf(fa, "%s %s %d %d %d", vect[j].name, vect[j].enfermedad, &vect[j].age, &vect[j].status, &vect[j].total);
    }

    printf("Archivo cargado con exito\n");
    fclose(fa);
    system("pause");
    return j;
}