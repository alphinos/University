#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "IO.h"
#include <string.h>

int getUserInput(int *answer){
    scanf("%d", answer);
    while(getchar() != '\n');
}

void main(void){
    Stack *stack = NULL;
    int element;

    int answer;
    int flagAux = -1;
    int menuTxt = 31;
    do {
        colorPrintNTimes('-', ROW_LEN, 1, GREEN);
        fcprint("[0] - Sair do programa!", 0, GREEN, 1, menuTxt);
        fcprint("[1] - Criar pilha!", 0, GREEN, 1, menuTxt);
        fcprint("[2] - Inserir na pilha!", 0, GREEN, 1, menuTxt);
        fcprint("[3] - Remover da pilha!", 0, GREEN, 1, menuTxt);
        fcprint("[4] - Qual o elemento do topo?", 0, GREEN, 1, menuTxt);
        fcprint("[5] - A pilha está vazia?", 0, GREEN, 1, menuTxt);
        fcprint("[6] - Destruir pilha!", 0, GREEN, 1, menuTxt);
        colorPrintNTimes('-', ROW_LEN, 1, GREEN);

        printf("%s--- Resposta: ", GREEN);
        answer = -1;
        getUserInput(&answer);
        printf("%s", COLOR_RESET);
        switch (answer){
            case 0:
                colorPrintNTimes('-', ROW_LEN, 1, GREEN);
                fcprint("Tchau Tchau :(", 0, GREEN, 1, 0);
                colorPrintNTimes('-', ROW_LEN, 1, GREEN);
                break;
            case 1:

        }

    } while (answer != 0);
}