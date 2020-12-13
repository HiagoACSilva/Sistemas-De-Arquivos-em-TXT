#include "SA.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
        if(cont >= MAX){
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

int QuantBloco(char *Entrada){
    int cont = 0;
    while(TRUE){
        if(Entrada[cont]==NULL){
            return cont-1;
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
void Quebra(char s[]){
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    s[i]='\n';
    s[i+1]='\0';
}
void ULTIMO(int MAX, char *NOME, char *CONTEUDO){
    SA=fopen("Teste.txt","r");
    int cont=0, ho, re;
    int status=TRUE;
    while(status==TRUE){
        fscanf(SA, "%s", palavra);
        if(cont >= MAX-4){
            fscanf(SA, "%s", palavra);
            fscanf(SA, "%s", palavra);
            ho=atoi(palavra);
            fscanf(SA, "%s", palavra);
            re=atoi(palavra);
            fclose(SA);
            status=FALSE;
        }
        cont++;
    }
    SA=fopen("Teste.txt","a");
    fputs(NOME, SA);
    fputs(CONTEUDO, SA);
    char buf[10];
    int QUANTIDADE=QuantBloco(CONTEUDO);
    sprintf(buf,"%i", QUANTIDADE);
    printf("\nQUANTIDADE: %s\n",buf);
    Quebra(buf);
    fputs(buf, SA);
    int INICIAL=ho+re;
    sprintf(buf,"%i", INICIAL);
    Quebra(buf);
    printf("INICIO: %s\n",buf);
    fputs(buf, SA);
    fclose(SA);
}
