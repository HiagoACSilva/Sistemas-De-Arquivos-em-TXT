#include "SA.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
    char m[LIMITE_BLOCO];
    char n[LIMITE_BLOCO];
    fgets(m,LIMITE_BLOCO,stdin);
    fgets(n,LIMITE_BLOCO,stdin);
    /*printf(m);
    int t=sizeof(m);
    printf("\ntamanho e %i\n", t);
    t=QuantBloco(m)-1;
    printf("tamanho e %i", t);
    //criar();
    ADICIONAR(m,t);
    */
    int Max = linhas();
    ULTIMO(Max,m,n);
    LISTAR(Max);
}

