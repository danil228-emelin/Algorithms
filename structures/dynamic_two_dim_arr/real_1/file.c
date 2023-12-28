#include <stdio.h>
#include <malloc.h>

int main(void){
    int a1=12;
    int a2=15;

    int *r1=&a1;
    int *r2=&a2;

    int **array_refs=malloc(sizeof(int*)*2);
    printf("%p\n",array_refs);
    printf("%p\n",array_refs[0]);
    puts("-------------------------");
    array_refs[0]=r1;
    printf("%p\n",array_refs[0]);
    printf("%d\n",*(array_refs[0]));

    array_refs[1]=r2;
}