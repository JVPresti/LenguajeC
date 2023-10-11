//Punteros
#include <stdio.h>

void main(){
    int a,b,c, *p1, *p2;

    p1=&a;
    *p1=1;
    p2=&b;
    *p2=2;
    p1=p2;
    *p1=0;
    p2=&c;
    *p2=3;
    printf("%d %d %d", a, b, c);
    p1=p2;
    p2=&a;
    *p2=*p1;
    printf("\n%d %d %d", a, b, c);


}