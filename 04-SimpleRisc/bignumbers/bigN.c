
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#define MAX_SIZE_FOR_CARRY 1000000000u

typedef struct _uint32_{
    unsigned int number;
    int size;
} uint32;

typedef struct _uint256_{
    uint32 words[10];
} uint256;

uint256 * new(){
    uint256 *n = (uint256 *) malloc( sizeof(uint256) );
    return n;
}

uint32 stringToUint32(char* string, int offset) {
	// Vai retirando char da string até ter UINT64_MAX dar overflow
	uint32 retorno;
	uint32_t curMult = 1, temp;
	retorno.number = 0;
	retorno.size = 0;

	for (int i = strlen(string) - offset - 1; i >= 0; i--) {
		temp = retorno.number + (*(string + i) - '0') * curMult;

		// Limite
		if (retorno.size == 9) {
			return retorno;
		}

		// Overflow
		if ( ((retorno.number % 10) != (temp % 10)) && curMult != 1 ) {
			return retorno;
		}

		retorno.number += (*(string + i) - '0') * curMult;
		retorno.size ++;
		curMult *= 10;
	}
	return retorno;
}

uint256 * stringToUint256(char* string) {
	uint256 *retorno = new();
	uint32_t offset = 0;
	uint32 temp;

	// Pega primeiro o byte de baixo
	temp = stringToUint32(string, offset);
	retorno->words[0] = temp;
	offset += temp.size;

    for (int i = 1; i < 10; i++){
        temp = stringToUint32(string, offset);
        retorno->words[i] = temp;
        offset += temp.size;
    }

	return retorno;
}

uint256 addUint256(uint256 a, uint256 b) {
	// Soma a com b
	uint256 retorno;
    bool p[10];

	// Primeiro o low byte 1
	retorno.words[0].number = a.words[0].number + b.words[0].number;
	p[0] = (retorno.words[0].number < a.words[0].number && retorno.words[0].number < b.words[0].number);

    for (int i = 1; i < 10; i++){
        retorno.words[i].number = a.words[i].number + b.words[i].number + p[0];
        p[1] = (retorno.words[i].number < a.words[i].number && retorno.words[i].number < b.words[i].number);

        // Remove o carry do número anterior caso necessário
        if (retorno.words[i].number >= MAX_SIZE_FOR_CARRY) {
            p[1] = true;
            retorno.words[i].number -= MAX_SIZE_FOR_CARRY;
        }
    }

	return retorno;

}

void printUint256(uint256 r) {
    for (int i = 9; i >= 0; i--){
        printf("%09u\n", r.words[i].number);
    }
}

int main(){

    uint256 *a, *b, r;
	char stra[80] = "115792089210356248762697446949407573530086143415290314195533631308867097853951";
	char strb[80] = "140929056875212190070682550560009930198227808570709790430510819830666007717983";

    char str_aux[] = "1157920 892103562 487626974 469494075 735300861 434152903 141955336 313088670 97853951";

    // Registrador A
	a = stringToUint256(stra);

	// Registrador B
	b = stringToUint256(strb);

	// Resposta
	r = addUint256(*a, *b);

    printUint256(*a);
	printf("\n+\n");
	printUint256(*b);
	printf("\n=\n");
	printUint256(r);
    printf("\n");

    return 0;
}