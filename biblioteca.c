/*Trabalho de Linguagem de Programação 02/2022
Professor Basílio

Implementar um coletor automático de lixo em C utilizando a técnica de contagem de referências
● Para tal, deve-se criar uma biblioteca estática que ofereça as seguintes funções:
● endereço malloc2(tamanho) → esta função realiza a alocação dinâmica e retorna o endereço da área criada
● void atrib2(endereco, endereço2) → esta função realiza a atribuição de ponteiros em C

O trabalho teve como base do mesmo trabalho realizado pela colega @neriallemand (github).  Houve modificações na biblioteca e na main,
tendo como objetivo aprofundar sobre o assunto cobrado*/

#include<stdio.h>
#include<stdlib.h>

typedef struct st_conte_referencias{
    struct st_conte_referencias *proximo;
    void *endereco;
    int cont;
}st_conte_referencias;
st_conte_referencias *st_lista_ref = NULL;

void ajustar_cont(void *end1, int m){ // vai ajustar as referencias de acordo com s variaveis.
    st_conte_referencias *aux = st_lista_ref;
    while(aux != NULL){
        if(aux->endereco == end1){
            aux->cont = aux->cont + m;
            break;
        }
        aux = aux->proximo;
    }
}

st_conte_referencias *faxina(st_conte_referencias *l){
    if(l != NULL){
        if(l->cont == 0){
            l->proximo = faxina(l->proximo);
            st_conte_referencias *aux = l->proximo;
            free(l);
            return aux;
        }
        else{
            l->proximo = faxina(l->proximo);
            return l;
        }
    }
    return NULL;
}

void dump(){
    st_conte_referencias *aux = st_lista_ref; //faz a copia do endereço do st_lista_ref para o aux.
    printf("iniciando o Impressão\n");
    while(aux != NULL){
        printf("[Endereco: %p, Referencias: %d]\n", aux->endereco, aux->cont);
        aux = aux->proximo;
    }
    printf("\n\n");
}

void *atrib2(void *end1, void *end2){ //recebe dois valores
    ajustar_cont(end1, -1); // chama a função ajustar_cont
    ajustar_cont(end2, 1); // chama a função ajustar_cont
    st_lista_ref = faxina(st_lista_ref);
    return end2;
}

void *malloc2(int tam){ //recebe o tamanho da varável inteiro.
    st_conte_referencias *aux = st_lista_ref; //faz a copia do endereço do st_lista_ref para o aux.
    st_lista_ref = malloc(sizeof(st_conte_referencias)); //cria uma "celula" da estrutura,alocando um espaço para ela.
    st_lista_ref->proximo = aux; //a emenda.  insere a "celula" no inicio da lista.
    st_lista_ref->endereco = malloc(tam); // aqui recebe o endereço reservado.
    st_lista_ref->cont = 1; //contagem de referencia.
    return st_lista_ref->endereco;
}

void finaliza(){
    while(st_lista_ref != NULL){
        st_conte_referencias *aux = st_lista_ref->proximo;
        free(st_lista_ref->endereco);
        free(st_lista_ref);
        st_lista_ref = aux;
    }
}
