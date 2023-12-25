#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

void MSG_MENU( ){
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. BUSCAR");
    printf("  \n\t2. VERIFICAR");
    printf("  \n\t3. REMOVER");
    printf("  \n\t4. INTERSECAO");
    printf("  \n\t5. DIFERENCA");
    printf("  \n\t6. SAIR");
}

void MENU(TFila *Fila1, TFila *Fila2){
    TProduto Item, xproduto, produto;
    TFila Fila3;
    int i, resultado, xcodigo;
    int opcao = 0;

    printf("\n\n------ Criar Filas -------\n\n");

    printf("\nFila 1:\n");
    for(i = 0; i < 4; i++){
        LerProduto(&Item);
        Enfileirar(Item, Fila1);
    }
    printf("\nFila 2:\n");
    for(i = 0; i < 4; i++){
        LerProduto(&Item);
        Enfileirar(Item, Fila2);
    }

    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:

                printf("\n\n------- Buscar Produto -------\n\n");
                printf("\nDigite o codigo do produto: ");
                fflush(stdin);
                scanf("%d", &xproduto.codigo);
                produto = Busca(Fila1, xproduto);
                if(produto.codigo != -1){
                    printf("\nProduto encontrado!\n");
                    ImprimirProduto(produto);
                }
                else{
                    printf("\nProduto nao encontrado!\n");
                }
                break;

            case 2:
                printf("\n\n------- Verificar Filas -------\n\n");
                resultado = VerificaIguais(Fila1, Fila2);
                if(resultado == -1){
                    printf("\nAs Filas sao diferentes\n\n");
                }
                else{
                    printf("\nAs Filas sao iguais\n\n");
                }
                break;

            case 3:

                printf("\n\n---------- Remover ------------\n\n");
                printf("\nDigite o codigo do produto: ");
                fflush(stdin);
                scanf("%d", &xcodigo);
                printf("\nFila apos remocao:\n");
                RemoverItem(Fila1, xcodigo);
                Imprimir(Fila1);

                break;

            case 4:

                printf("\n\n--------- Intersecao ----------\n\n");
                FFVazia(&Fila3);
                Intersecao(Fila1, Fila2, &Fila3);
                printf("\nIntersecao entre Fila 1 e Fila 2\n");
                Imprimir(&Fila3);
                LiberarFila(&Fila3);
                break;

            case 5:

                printf("\n\n--------- Diferenca ----------\n\n");
                FFVazia(&Fila3);
                Diferenca(Fila1, Fila2, &Fila3);
                printf("\nDiferenca entre Fila 1 e Fila 2\n");
                Imprimir(&Fila3);
                LiberarFila(&Fila3);
                break;

            case 6:

                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;

            default:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } /* fim do bloco switch */
    } while(opcao != 6);
}
