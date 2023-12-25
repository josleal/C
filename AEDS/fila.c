#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

/* FUNÇÕES */
/* CRIAR FILA */
void FFVazia(TFila *Fila){
    Fila -> frente = (TCelula*) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> frente;
    Fila -> frente -> prox = NULL;
    Fila -> tamanho = 0;
}

/* ENFILEIRAR */
void Enfileirar(TProduto Item, TFila *Fila){
    Fila -> tras -> prox = (TCelula *) malloc(sizeof(TCelula));
    Fila -> tras = Fila -> tras -> prox;
    Fila -> tras -> item = Item;
    Fila -> tras -> prox = NULL;
    Fila -> tamanho++;
}

/* DESENFILEIRAR */
void Desenfileirar (TFila *Fila, TProduto *Item){
	TCelula *Aux;
	if (!Vazia(*Fila)){
		Aux = Fila -> frente -> prox;
		Fila -> frente -> prox = Aux -> prox;
		*Item = Aux -> item;
		free(Aux);
		if(Fila -> frente ->prox == NULL){
			Fila -> tras = Fila -> frente;
		}
		Fila -> tamanho--;
	}
}

/* LIBERAR FILA */
void LiberarFila(TFila *Fila){
    TProduto AuxItem;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &AuxItem);
    }
    free(Fila -> frente);
}

/* IMPRIMIR FILA */
void Imprimir(TFila *Fila){
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto AuxItem;
    /* FIFO: desenfileirar da Fila original
     e colocar todos elementos na Fila auxiliar */
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &AuxItem);
        ImprimirProduto(AuxItem);
        Enfileirar(AuxItem, &FilaAux);
    }
    /* FIFO: desenfileirar todos elementos da Fila
     auxiliar e enfileirar na Fila original. */
    while(!Vazia(FilaAux)){
        Desenfileirar(&FilaAux, &AuxItem);
        Enfileirar(AuxItem, Fila);
    }
    LiberarFila(&FilaAux);
}

/* IMPRIMIR PRODUTO */
void ImprimirProduto(TProduto Item){

    printf("\nCodigo: %d", Item.codigo);
    printf("\nNome: %s", Item.nome);
    printf("Descricao: %s", Item.descricao);
    printf("Preco: %.2f", Item.preco);
    printf("\nQuantidade: %d\n\n", Item.quantidade);
}

/* LER PRODUTO */
void LerProduto(TProduto *Item){

    printf("Digite o codigo do produto: ");
    fflush(stdin);
    scanf("%d", &Item -> codigo);

    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(Item -> nome, 100, stdin);

    printf("Digite a descricao do produto: ");
    fflush(stdin);
    fgets(Item -> descricao, 100, stdin);

    printf("Digite o preco do produto: ");
    fflush(stdin);
    scanf("%f", &Item -> preco);

    printf("Digite a quantidade do produto: ");
    fflush(stdin);
    scanf("%d", &Item -> quantidade);

    printf("\n");
}

/* VERIFICA SE LISTA ESTÁ VAZIA */
int Vazia(TFila Fila){
  return (Fila.frente == Fila.tras);

}


/* EXERCÍCIO 1 - TAD FILA - BUSCA */
TProduto Busca(TFila *Fila, TProduto Item){
    TFila FilaAux;
    TProduto Item1, Item2;

    FFVazia(&FilaAux);
    Item1.codigo = -1;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &Item2);
        if(Item2.codigo == Item.codigo){
            Item1 = Item2;
        }
        Enfileirar(Item2, &FilaAux);
    }
    while(!Vazia(FilaAux)){
        Desenfileirar(&FilaAux, &Item2);
        Enfileirar(Item2, Fila);
    }
    LiberarFila(&FilaAux);
    return Item1;
}


/* EXERCÍCIO 2 - TAD FILA - VERIFICAR */
int VerificaIguais(TFila *Fila1, TFila *Fila2){
	TProduto Item1, Item2;
	TFila FilaAux1, FilaAux2;
	FFVazia(&FilaAux1);
	FFVazia(&FilaAux2);

	int N1, N2, igual;
	N1 = Fila1 -> tamanho;
	N2 = Fila2 -> tamanho;

	while(N1 > 0){
            igual = -1;
            /* Desenfileirar de Fila1 e enfileirar em FilaAux1 */
            Desenfileirar(Fila1, &Item1);
            Enfileirar(Item1, &FilaAux1);

        while(N2 > 0){
            /* Desenfileirar de Fila2 e enfileirar em FilaAux2 */
            Desenfileirar(Fila2, &Item2);
            Enfileirar(Item2, &FilaAux2);

            if(Item1.codigo == Item2.codigo){
                igual = 1;
            }
            /* Desenfileirar de FilaAux2 e enfileirar em Fila2 */
            Desenfileirar(&FilaAux2, &Item2);
            Enfileirar(Item2, Fila2);
            N2--;
        }
        if(igual == -1){
            return igual;
        }

        /* Desenfileirar de FilaAux1 e enfileirar em Fila1 */
        Desenfileirar(&FilaAux1, &Item1);
        Enfileirar(Item1, Fila1);

        N2 = Fila2 -> tamanho;
        N1--;
	}
	return igual;

    LiberarFila(&FilaAux1);
    LiberarFila(&FilaAux2);

}

/* EXERCÍCIO 3 - TAD FILA - REMOVER */
void RemoverItem(TFila *Fila, int cod){

    TProduto Item;
    TFila FilaAux;
    FFVazia(&FilaAux);

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &Item);

        if(Item.codigo != cod){
            Enfileirar(Item, &FilaAux);
        }
    }
    while(!Vazia(FilaAux)){
        Desenfileirar(&FilaAux, &Item);
        Enfileirar(Item, Fila);
    }
    LiberarFila(&FilaAux);
}


/* EXERCÍCIO 4 - TAD FILA - INTERSEÇÃO */
void Intersecao(TFila *Fila1, TFila *Fila2, TFila *Fila3){

	TProduto Item1, Item2;
	int N1, N2;
	N1 = Fila1 -> tamanho;
	N2 = Fila2 -> tamanho;
	while(N1 > 0){
		Desenfileirar(Fila1, &Item1);
		Fila1 -> tamanho--;

		while(N2 > 0){
			Desenfileirar(Fila2, &Item2);
			Fila2 -> tamanho--;

			if(Item1.codigo == Item2.codigo){
				Enfileirar(Item1, Fila3);
			}
			Enfileirar(Item2, Fila2);
			Fila2 -> tamanho++;
			N2--;
		}
		N2 = Fila2 -> tamanho;
		Enfileirar(Item1, Fila1);
		Fila1 -> tamanho++;
		N1--;
	}

}

/* EXERCÍCIO 5 - TAD FILA - DIFERENCA */
void Diferenca(TFila *Fila1, TFila *Fila2, TFila *Fila3){

	TProduto Item1, Item2;
	int N1, N2, igual = 0;
	N1 = Fila1 -> tamanho;
	N2 = Fila2 -> tamanho;
	while(N1 > 0){
		Desenfileirar(Fila1, &Item1);
		Fila1 -> tamanho--;

		while(N2 > 0){
			Desenfileirar(Fila2, &Item2);
			Fila2 -> tamanho--;

            /* Se for igual então Aux1 não será enfileirado em Fila3, pois o igual é 1 (Número existe em Fila2) */
			if(Item1.codigo == Item2.codigo){
                igual = 1;
			}
			Enfileirar(Item2, Fila2);
			Fila2 -> tamanho++;
			N2--;
		}
		/* Se for diferente então Aux1 é enfileirado em Fila3 */
		if(igual == 0){
            Enfileirar(Item1, Fila3);
		}
		Enfileirar(Item1, Fila1);
		Fila1 -> tamanho++;

		N2 = Fila2 -> tamanho;
		N1--;
	}
}
