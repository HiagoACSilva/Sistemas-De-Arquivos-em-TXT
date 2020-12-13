#include "SA.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//VARIAVEIS GLOBAIS
FILE *SA; //PONTEIRO GLOBAL
char palavra[100];//APENAS UM CHAR PARA PEGAR VALORES NAS FUNÇÕES
void CRIAR(){//CRIA UM ARQUIVO
    SA=fopen("SO.txt","w");
    fclose(SA);
}
void LISTAR(int MAX){//FUNÇÃO QUE LISTA OS ARQUIVOS
    SA=fopen("SO.txt","r");
    int cont=0;
    int status=TRUE;
    while(status==TRUE){//ENQUANTO VERDADEIRO
        fscanf(SA, "%s", palavra);//VAI PARA UMA LINHA
        if(cont >= MAX){//ENQUANTO O CONTADOR CHEGAR NO MAX DE LINHAS
            fclose(SA);//O ARQUIVO FECHA
            status=FALSE;//E O STATUS FICA FALSO, TERMINANDO A FUNÇÃO
        }else{
            printf("%s\t",palavra);//SENAO ELE PRINTA O NOME DO ARQUIVO
            fscanf(SA, "%s", palavra);//PULA O CONTEUDO
            fscanf(SA, "%s", palavra);//PEGA O TAMANHO
            printf("%s\t",palavra);//IMPRIME O TAMANHO
            fscanf(SA, "%s", palavra);//PEGA O INICIO
            printf("%s\n",palavra);//IMPRIME O INICIO
            cont+=4;//E O CONTADOR SOMA +4
        }
    }
}

int QuantBloco(char *Entrada){//FUNÇÃO QUE RETORNA A QUANTIDADE DE BLOCOS USADOS POR ARQUIVO
    //A QUANTIDADE DE BLOCOS FICOU DEFINIDA POR, CADA LINHA REMETE A UM BLOCO
    int cont = 0;
    while(TRUE){
        if(Entrada[cont]==NULL){
            return cont-1;
        }else{
            cont++;
        }
    }
}
int linhas () {//RETORNA O NUMERO MAX DE LINHAS

    FILE *arq;

    char c, letra = '\n';

    int vezes;

    arq = fopen("SO.txt","r");

        while(fread (&c, sizeof(char), 1, arq)) {
            if(c == letra) {
                vezes++;
            }
        }

    fclose(arq);
    return vezes;
}
void Quebra(char s[]){//FUNÇÃO PARA ADICIONAR \n NAS PALAVRAS PARA NÃO HAVER ALGUM ERRO NA HORA DA COMPARAÇÃO
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }
    s[i]='\n';
    s[i+1]='\0';
}
void ULTIMO(int MAX, char *NOME, char *CONTEUDO){//FUNÇÃO QUE ADICIONA UM ARQUIVO
    SA=fopen("SO.txt","r");;//PRIMEIRO ABRE O ARQUIVO COMO LEITURA PARA PEGAR OS VALORES DO ULTIMO ARQUIVO SALVO
    int cont=0, TAMANHO, INICIO;
    int status=TRUE;
    while(status==TRUE){
        fscanf(SA, "%s", palavra);
        if(cont >= MAX-4){
            fscanf(SA, "%s", palavra);
            fscanf(SA, "%s", palavra);
            TAMANHO=atoi(palavra);
            fscanf(SA, "%s", palavra);
            INICIO=atoi(palavra);
            fclose(SA);
            status=FALSE;
        }
        cont++;
    }//DEPOIS O ARQUIVO É ABERTO PARA ADICIONAR AS INFORMAÇÕES DO NOVO ARQUIVO
    SA=fopen("SO.txt","a");
    fputs(NOME, SA);
    fputs(CONTEUDO, SA);
    char buf[10];
    int QUANTIDADE=QuantBloco(CONTEUDO);
    sprintf(buf,"%i", QUANTIDADE);
    printf("\nQUANTIDADE: %s\n",buf);
    Quebra(buf);
    fputs(buf, SA);
    int INICIAL=TAMANHO+INICIO;
    sprintf(buf,"%i", INICIAL);
    Quebra(buf);
    printf("INICIO: %s\n",buf);
    fputs(buf, SA);
    fclose(SA);
}
void READ(char NOME[], int Max){//FUNÇÃO QUE LE O CONTEUDO DO ARQUIVO ESPECIFICADO
    SA=fopen("SO.txt","r");
    int cont = 0;
    int status=TRUE;
    while(status==TRUE && cont < Max){
        fscanf(SA, "%s", palavra);
        Quebra(palavra);
        if(strcmp(NOME,palavra)==0){
            fscanf(SA, "%s", palavra);
            printf(palavra);
            fclose(SA);
            status=FALSE;
        }
        cont++;
    }
    fclose(SA);
}
void Sistema(){//LOOP DO PROGRAMA
    char ESCOLHA[LIMITE_BLOCO];
    char NOME[LIMITE_BLOCO];
    char CONTEUDO[LIMITE_BLOCO];
    while(TRUE){
        printf("\nLISTA DE COMANDOS:\nls:\tListar\nmore:\tMostrar conteudo do arquivo\ncat:\tAdicionar Arquivo\nDigite Sair para sair do programa\n");
        fgets(ESCOLHA,LIMITE_BLOCO,stdin);
        if(strcmp(ESCOLHA,"cat\n")==0){
            printf("\nDigite o nome do arquivo:\t");
            fgets(NOME,LIMITE_BLOCO,stdin);
            printf("\nDigite o conteudo do arquivo: \t");
            fgets(CONTEUDO,LIMITE_BLOCO,stdin);
            ULTIMO(linhas(),NOME,CONTEUDO);
            printf("Conteudo Criado\n");
        }else if(strcmp(ESCOLHA,"ls\n")==0){
            LISTAR(linhas());
            printf("\nLISTAGEM FEITA\n");
        }else if(strcmp(ESCOLHA,"more\n")==0){
            printf("\nDigite o Arquivo:\t");
            fgets(NOME,LIMITE_BLOCO,stdin);
            READ(NOME,linhas());
        }else if(strcmp(ESCOLHA,"Sair\n")==0){
            exit(-1);
        }else{
            printf("\nComando Invalido\n");
        }
    }
}
