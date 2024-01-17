
/* Ele recebe os as informações do usuario e concatena
 * separando por '*' e depois embaralha aleatoriamente
 * através da rand() e gera a ordem que foi embralhado
 * e concatena seperando por - e cada numero por '.'
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "criptografia.h"
#include "cadastraUsuario.h"
#include "trataHexa.h"

Usuario trocado;

void startCriptografia(int start){

    int i;

    if (start == 0){
        char textoFinal[500] = "";

        trocaLetras();
        concatenaTexto();

        int chaveCrip[strlen(textoCrip)];
        char chaveTratada[510] = "";
        embaralhar(textoCrip, strlen(textoCrip), chaveCrip);
        strncat(textoFinal,textoCrip,strlen(textoCrip));
        strncat(textoFinal,"-",1);
        geraChave(chaveCrip, strlen(textoCrip), chaveTratada);
        strncat(textoFinal,chaveTratada, strlen(chaveTratada));
        strcpy(mandaTexto, textoFinal);
    }
}

void trocaLetras(){

    int i;

    for (i=0;i<strlen(user.nome);i++){
        trocado.nome[i] = user.nome[i] +3;
    }

    for (i=0;i<strlen(user.CPF);i++){
        trocado.CPF[i] = user.CPF[i] +3;
    }

    for (i=0;i<strlen(user.aniversario);i++){
        trocado.aniversario[i] = user.aniversario[i] +3;
    }

    for (i=0;i<strlen(user.senha);i++){
        trocado.senha[i] = user.senha[i] +3;
    }
}

int concatenaTexto(){

    char crip [255] = "";
    strncat(crip,converteHex(trocado.nome,strlen(trocado.nome)),strlen(trocado.nome)*2);
    strncat(crip, "*", 1);
    strncat(crip,converteHex(trocado.CPF,strlen(trocado.CPF)),strlen(trocado.CPF)*2);
    strncat(crip, "*", 1);
    strncat(crip,converteHex(trocado.aniversario,strlen(trocado.aniversario)),strlen(trocado.aniversario)*2);
    strncat(crip, "*", 1);
    strncat(crip,converteHex(trocado.senha,strlen(trocado.senha)),strlen(trocado.senha)*2);
    strcpy(textoCrip, crip);

    return 0;
}

void embaralhar(char* vet, int vetSize, int* chave){

	int i, r, temp;

	//recolhe os segundos de 1970 até o momento da execução garantindo um valor diferente a cada execução
	srand(time(NULL));

	//embaralha o vetor
	for (i=0;i<vetSize; i++){
		r = rand() % vetSize;
		chave [i] = r;
		temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void geraChave(int* chave, int tamanho, char* retorno){

    int i;
    char recebe [5];

    for(i=0; i<tamanho;i++){
        itoa(chave[i], recebe, 10);
        if (i != tamanho-1){
            strncat(retorno, recebe,strlen(recebe));
            strncat(retorno, ".", 1);
        }
        else{
           strncat(retorno, recebe,strlen(recebe));
        }

    }
}
