
/* Ele só converte e desconverte em hexadecimal,
 * nada além
 */

#include <stdio.h>
#include <stdlib.h>
#include "trataHexa.h"

char charHexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char* converteHex (char str[], int strSize){

	unsigned int num, i, j;
	char numEmHexa[3];
	char* hexa = (char*) malloc((strSize*2) * sizeof(char));

    for(i=0; i<strSize*2; i++){
		hexa[i] = '\0';
	}

	for(i=0; i<strSize; i++){
		for(j=0;j<4;j++){
			numEmHexa[j] = '\0';
		}
		num = (int) str[i];
		numEmHexa[0] = charHexa[ ((num & 0xF0) >> 4) ];
        numEmHexa[1] = charHexa[ (num & 0x0F) ];
        numEmHexa[2] = '\0';
        strcat(hexa, numEmHexa);
	}

	return hexa;
}

char desconverteHex(char posUm, char posDois){

	int i, valorUm, valorDois, decimal;
	char caracter;

	for (i=0;i<16;i++){
		if (posUm == charHexa[i]){
			valorUm =i;
			break;
		}
	}

	for (i=0;i<16;i++){
		if (posDois == charHexa[i]){
			valorDois =i;
			break;
		}
	}

	decimal = (valorUm*16) + valorDois;
	caracter = (char) decimal;

	return caracter;
}
