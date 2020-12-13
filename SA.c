#include "SA.h"
#include <stdlib.h>
#include <stdio.h>

FILE *SA;
char palavra[100];
void CRIAR(){
    SA=fopen("Teste.txt","w");
    fclose(SA);
}
void LISTAR(int MAX){
    SA=fopen("Teste.txt","r");
    int cont=0;
    int status=TRUE;
    while(status==TRUE){
        fscanf(SA, "%s", palavra);
        if(cont == MAX){
            fclose(SA);
            status=FALSE;
        }else{
            printf("%s\t",palavra);
            fscanf(SA, "%s", palavra);
            fscanf(SA, "%s", palavra);
            printf("%s\t",palavra);
            fscanf(SA, "%s", palavra);
            printf("%s\n",palavra);
            cont+=4;
        }
    }
}
void ADICIONAR(char *ARQUIVO, char *CONTEUDO, char *TAMANHO, char *INICIO){
    SA=fopen("Teste.txt","a");
    fputs(ARQUIVO, SA);
    fputs(CONTEUDO, SA);
    fputs(TAMANHO, SA);
    fputs(INICIO, SA);
    fclose(SA);
}
int QuantBloco(char *Entrada){
    int cont = 0;
    while(TRUE){
        if(Entrada[cont]==NULL){
            return cont;
        }else{
            cont++;
        }
    }
}
int linhas () {

    FILE *arq;

    char c, letra = '\n';

    int vezes;

    arq = fopen("Teste.txt","r");

        //Lendo o arquivo 1 por 1
        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == letra) {
                vezes++;
            }
        }

    printf("\nLinhas: %i\n",vezes);

    fclose(arq);
    return vezes;
}
