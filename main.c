/*Trabalho de Linguagem de Programação 02/2022
Professor Basílio

Implementar um coletor automático de lixo em C utilizando a técnica de contagem de referências
● Para tal, deve-se criar uma biblioteca estática que ofereça as seguintes funções:
● endereço malloc2(tamanho) → esta função realiza a alocação dinâmica e retorna o endereço da área criada
● void atrib2(endereco, endereço2) → esta função realiza a atribuição de ponteiros em C

O trabalho teve como base do mesmo trabalho realizado pela colega @neriallemand (github).  Houve modificações na biblioteca e na main,
tendo como objetivo aprofundar sobre o assunto cobrado
*/

#include"biblioteca.h"

int main(){
    int *v = malloc2(sizeof(int)); /*retorna o endereço reservado.  Lembrando que é uma estrutura, onde estará o contador de referencia.*/
    dump(); //imprime  a única celula com seu endereço e a quantidade de referencia.
    *v = 10;
    int *w = malloc2(sizeof(int)); /*retorna já com duas celulas (v e w). Nos comentarios da função está mais explicado.*/
    dump(); //imprime  duas celulas com seus endereços e a quantidade de referencia.
    *w = 20;
    v = atrib2(v, w);
    dump();
    char *c = malloc2(sizeof(char));
    *c = 'Z';
    dump();
    w = atrib2(w, NULL);
    dump();

    int *k = malloc2(sizeof(int));
    dump();
    *k = 30;
    k = atrib2(v,k);
    dump();
    w = atrib2(w,k);
    dump();
    w=k;
    dump();
    return 0;

}
