#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

/* ESTRUTURA DO ELEMENTO */
typedef struct item{
    int codigo;
    char nome [100];
    char descricao [100];
    float preco;
    int quantidade;

}TProduto;

/* ESTRUTURA DA CÉLULA. */
typedef struct celula{
    TProduto item;
    struct celula *prox;
}TCelula;

/* ESTRUTURA LISTA */
typedef struct fila{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
}TFila;

/* FUNÇÕES */

void FFVazia(TFila *Fila);

void Enfileirar(TProduto Item, TFila *Fila);

void Desenfileirar (TFila *Fila, TProduto *Item);

void LiberarFila(TFila *Fila);

int Vazia(TFila Fila);

void Imprimir(TFila *Fila);

void ImprimirProduto(TProduto Item);

void LerProduto(TProduto *Item);

TProduto Busca (TFila *Fila, TProduto Item);

int VerificaIguais(TFila *Fila1, TFila *Fila2);

void RemoverItem(TFila *Fila, int cod);

void Intersecao(TFila *Fila1, TFila *Fila2, TFila *Fila3);

void Diferenca(TFila *Fila1, TFila *Fila2, TFila *Fila3);


#endif /* FILA_H_INCLUDED */
