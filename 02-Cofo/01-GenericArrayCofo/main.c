#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cofo.h"

typedef struct _Product_{
    char name[30];
    int id;
    int amtStock;
    float price;
} Product;

int getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

int cmpInt(void* n1, void* n2){
    int *in1, *in2;
    in1 = (int*)n1;
    in2 = (int*)n2;
    if (*in1 < *in2)
        return -1;
    else if (*in1 > *in2)
        return TRUE;
    else
        return FALSE;
}

float cmpFloat(void* n1, void* n2){
    float *in1, *in2;
    in1 = (float*)n1;
    in2 = (float*)n2;
    if (*in1 < *in2)
        return -1;
    else if (*in1 > *in2)
        return TRUE;
    else
        return FALSE;
}

int findByName(void *item, void *key){
    Product *prod;
    char *keyName;
    prod = (Product *)item;
    keyName = (char *)key;
    if (strcmp(prod->name, keyName))
        return TRUE;
    else
        return FALSE;
}

int findByID(void *item, void *key){
    Product *prod;
    int *keyID;
    prod = (Product *)item;
    keyID = (int *)key;
    if (prod->id == *keyID)
        return TRUE;
    else
        return FALSE;
}

int findByPrice(void *item, void *key){
    Product *prod;
    float *keyPrice;
    prod = (Product *)item;
    keyPrice = (float *)key;
    if (prod->price == *keyPrice)
        return TRUE;
    else
        return FALSE;
}

void main(void){
    gCofo *cofo = NULL;
    Product *product;

    int answer = -1;

    void* aux;
    int flagAux;

    char name[30];
    float price;
    int id;

    char end;

    do {
        printf("--------------------------------------------------------------\n");
        printf("- [0] - Sair do programa!             ------------------------\n");
        printf("- [1] - Criar o cofo!                 ------------------------\n");
        printf("- [2] - Inserir um produto no cofo!   ------------------------\n");
        printf("- [3] - Remover produto!              ------------------------\n");
        printf("- [4] - Achar produto!                ------------------------\n");
        printf("- [5] - Mostrar os elementos do cofo! ------------------------\n");
        printf("- [6] - Esvaziar o cofo!              ------------------------\n");
        printf("- [7] - Destruir o cofo!              ------------------------\n");
        printf("--------------------------------------------------------------\n");
        answer = -1;
        getUserInput(&answer);
        switch(answer){
            case 0:
                printf("--------------------------------------------------------------\n");
                printf("----------------------- Tchau tchau :( -----------------------\n");
                printf("--------------------------------------------------------------\n");
                break;
            case 1:
                printf("--------------------------------------------------------------\n");
                printf("- Qual a quantidade de itens que desejas que caibam no cofo? -\n");
                printf("--------------------------------------------------------------\n");
                getUserInput(&answer);

                cofo = gCofCreate(answer);
                if (cofo == NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("-------------- Não foi possível criar o cofo :( --------------\n");
                    printf("--------------------------------------------------------------\n");
                }

                break;
            case 2:
                product = (Product*)malloc(sizeof(Product));
                if (product == NULL){
                    printf("--------------------------------------------------------------\n");
                    printf("---------- Não será possível inicializar o produto. ----------\n");
                    printf("--------------------------------------------------------------\n");
                }

                printf("--------------------------------------------------------------\n");
                printf("-- Insira os dados do produto que desejas inserir no cofo. ---\n");
                printf("--------------------------------------------------------------\n");

                printf("--------------------------------------------------------------\n");
                printf("-- Nome:                  ------------------------------------\n");
                scanf("%s", &product->name);
                while(getchar() != '\n');
                printf("-- Id                     ------------------------------------\n");
                getUserInput(&product->id);
                printf("-- Quantidade em estoque: ------------------------------------\n");
                getUserInput(&product->amtStock);
                printf("-- Preço:                 ------------------------------------\n");
                scanf("%f", &product->price);
                while(getchar() != '\n');
                printf("--------------------------------------------------------------\n");

                flagAux = gCofInsert(cofo, (void*)product);

                if (flagAux == TRUE){
                    printf("--------------------------------------------------------------\n");
                    printf("----- O produto de id: '%d' foi adicionado com sucesso. ------\n",
                        product->id);
                    printf("--------------------------------------------------------------\n");
                }
                else if (flagAux == FALSE){
                    printf("--------------------------------------------------------------\n");
                    printf("------- Não foi possível inserir o produto no cofo... --------\n");
                    printf("--------------------------------------------------------------\n");
                }

                break;
            case 3:
                printf("--------------------------------------------------------------\n");
                printf("----- Escolha de que maneira desejas remover o elemento. -----\n");
                printf("--------------------------------------------------------------\n");
                printf("- [1] - Nome  ------------------------------------------------\n");
                printf("- [2] - ID    ------------------------------------------------\n");
                printf("- [3] - Preço ------------------------------------------------\n");
                printf("--------------------------------------------------------------\n");
                getUserInput(&answer);
                switch (answer){
                    case 1:
                        scanf("%s", &name);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, name, &findByName);
                        break;
                    case 2:
                        scanf("%s", &id);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, name, &findByID);
                        break;
                    case 3:
                        scanf("%s", &price);
                        while(getchar() != '\n');
                        product = (Product *)gCofRemove(cofo, name, &findByPrice);
                        break;
                    default:
                        printf("--------------------------------------------------------------\n");
                        printf("---- Busca por dado inválido! --------------------------------\n");
                        printf("--------------------------------------------------------------\n");
                }
                printf("--------------------------------------------------------------\n");
                printf("- Produto removido: %s ---------------------------------------\n",
                    product->name);
                printf("- Estoque: %d ------------------------------------------------\n",
                    product->amtStock);
                printf("- Id: %d      ------------------------------------------------\n",
                    product->id);
                printf("- Preço: %.2f   ------------------------------------------------\n",
                    product->price);
                printf("--------------------------------------------------------------\n");

                if (answer == 0)
                    answer = -1;
                break;
            case 4:
                printf("--------------------------------------------------------------\n");
                printf("--- Escolha de que maneira desejas procurar pelo elemento. ---\n");
                printf("--------------------------------------------------------------\n");
                printf("- [1] - Nome  ------------------------------------------------\n");
                printf("- [2] - ID    ------------------------------------------------\n");
                printf("- [3] - Preço ------------------------------------------------\n");
                printf("--------------------------------------------------------------\n");

                getUserInput(&answer);
                switch (answer){
                    case 1:
                        scanf("%s", &name);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, name, &findByName);
                        break;
                    case 2:
                        scanf("%s", &id);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, name, &findByID);
                        break;
                    case 3:
                        scanf("%s", &price);
                        while(getchar() != '\n');
                        product = (Product *)gCofQuery(cofo, name, &findByPrice);
                        break;
                    default:
                        printf("--------------------------------------------------------------\n");
                        printf("---- Busca por dado inválido! :( -----------------------------\n");
                        printf("--------------------------------------------------------------\n");
                }

                printf("--------------------------------------------------------------\n");
                printf("- Produto removido: %s ---------------------------------------\n",
                    product->name);
                printf("- Estoque: %d ------------------------------------------------\n",
                    product->amtStock);
                printf("- Id: %d      ------------------------------------------------\n",
                    product->id);
                printf("- Preço: %.2f   ------------------------------------------------\n",
                    product->price);
                printf("--------------------------------------------------------------\n");

                if (answer == 0)
                    answer = -1;
                break;
            case 5:
                printf("Os elementos da coleção são:\n");

                product = (Product*)gCofGetFirst(cofo);
                printf("--------------------------------------------------------------\n");
                printf("- Produto removido: %s ---------------------------------------\n",
                    product->name);
                printf("- Estoque: %d ------------------------------------------------\n",
                    product->amtStock);
                printf("- Id: %d      ------------------------------------------------\n",
                    product->id);
                printf("- Preço: %.2f   ------------------------------------------------\n",
                    product->price);
                printf("--------------------------------------------------------------\n");

                while (gCofGetNext(cofo) != NULL){
                    product = (Product*)cofo->items[cofo->curr];
                    printf("--------------------------------------------------------------\n");
                    printf("- Produto removido: %s ---------------------------------------\n",
                        product->name);
                    printf("- Estoque: %d ------------------------------------------------\n",
                        product->amtStock);
                    printf("- Id: %d      ------------------------------------------------\n",
                        product->id);
                    printf("- Preço: %.2f   ----------------------------------------------\n",
                        product->price);
                    printf("--------------------------------------------------------------\n");
                }
                break;
            case 6:
                printf("--------------------------------------------------------------\n");
                printf("--- O cofo será esvaziado! -----------------------------------\n");
                printf("--------------------------------------------------------------\n");
                int i = 0;
                for (i = cofo->numItems - 1; i >= 0; i--){
                    flagAux = i;
                    product = gCofRemoveByIndex(cofo, i);
                    if (product == NULL)
                        i = flagAux;
                }
                if (cofo->numItems != 0){
                    printf("--------------------------------------------------------------\n");
                    printf("--- Não foi possível esvaziar o cofo! ------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                else{
                    printf("--------------------------------------------------------------\n");
                    printf("--- O cofo foi esvaziado com sucesso! ------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                break;
            case 7:
                printf("--------------------------------------------------------------\n");
                printf("--- O cofo será destruído! -----------------------------------\n");
                printf("--------------------------------------------------------------\n");
                flagAux = gCofDestroy(cofo);
                if (flagAux == TRUE){
                    printf("--------------------------------------------------------------\n");
                    printf("--- Cofo destruído com sucesso. ------------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                else {
                    printf("--------------------------------------------------------------\n");
                    printf("--- O cofo não pôde ser destruído! ---------------------------\n");
                    printf("--------------------------------------------------------------\n");
                }
                break;
        }
    } while (answer != 0);
}