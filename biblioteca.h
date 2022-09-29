/*Trabalho de Linguagem de Programação 02/2022
Professor Basílio

Implementar um coletor automático de lixo em C utilizando a técnica de contagem de referências
● Para tal, deve-se criar uma biblioteca estática que ofereça as seguintes funções:
● endereço malloc2(tamanho) → esta função realiza a alocação dinâmica e retorna o endereço da área criada
● void atrib2(endereco, endereço2) → esta função realiza a atribuição de ponteiros em C

O trabalho teve como base do mesmo trabalho realizado pela colega @neriallemand (github).  Houve modificações na biblioteca e na main,
tendo como objetivo aprofundar sobre o assunto cobrado*/

#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct st_conte_referencias{
    struct st_conte_referencias *proximo;
    void *endereco;
    int cont;
}st_conte_referencias;

void ajustar_cont(void *end1, int m);

st_conte_referencias *removelixo(st_conte_referencias *l);

void dump();

void *atrib2(void *end1, void *end2);

void *malloc2(int tam);

void finaliza();

#endif
