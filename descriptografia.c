
/* recebe a string do .txt, separa entre os dados e a chave,
 * pega a chave e converte para inteiro, desenbaralha os dados
 * desconverte do hexa e subtrai três dos caracteres (ou seja
 * o processo inverso da criptografia)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trataHexa.h"
#include "descriptografia.h"
#include "consultaCadastro.h"

void descriptografa(char* recebeTexto){

    int i;
    char dados [255]="";
    char leituraChave [510]="";

    while(recebeTexto[i] != '-'){
        i++;
    }

    strncpy(dados,string_substring(recebeTexto, 0, i),i);
    strcpy(leituraChave,string_substring(recebeTexto, i+1, strlen(recebeTexto)));

    int chaveNum [strlen(dados)];

    converteChave(leituraChave, strlen(leituraChave), chaveNum, strlen(dados));
    desenbaralha(dados, strlen(dados), chaveNum);
    separaDados(dados);
    desconverteDados();
}

void converteChave(char* leitura_chave, int leng, int* chave, int tamanho){

    int i, pontoUm, pontoDois, recebe, j;
    bool trava, comeco, verifica;
    char *filtro;

    trava = comeco = verifica = false;
    j = 1;
    for (i=0;i<=leng;i++){
		if ((leitura_chave[i] == '.') && (trava == false)){
			pontoUm = i;
			trava = true;
			continue;
		}
		else if ((leitura_chave[i] == '.') && (trava == true)){
			pontoDois = i;
			trava = false;
		}

		if (pontoUm != 0 && comeco == false){
			filtro = string_substring(leitura_chave, 0, pontoUm);
			chave [0] = atoi(filtro);
			comeco = true;
		}

		if (pontoUm < pontoDois && verifica == false){
			filtro = string_substring(leitura_chave, pontoUm+1, pontoDois);
			if (filtro != NULL){
				recebe = atoi(filtro);
				chave [j] = recebe;
				j++;
				verifica = true;
			}
		}
		else if (pontoUm > pontoDois && verifica == true){
			filtro = string_substring(leitura_chave, pontoDois+1, pontoUm);
			if (filtro != NULL){
				recebe = atoi(filtro);
				chave[j] = recebe;
				j++;
				verifica = false;
			}
		}
	}

	//atribui o último valor ao vetor chave
	if (pontoDois > pontoUm){
        filtro = string_substring(leitura_chave, pontoDois+1, leng);
	}
	else{
        filtro = string_substring(leitura_chave, pontoUm+1, leng);
	}

	chave [tamanho-1] = atoi(filtro);
}

void desenbaralha (char* vet, int vetSize, int* chave){

    int i, r, temp;

    vetSize --;
    for (i=vetSize;i>=0; i--){
		r = chave[i];
		temp = vet[r];
		vet[r] = vet[i];
		vet[i] = temp;
	}
}

char* string_substring(char str[], int start, int end) {
    int i, j;
    char *sub;

    if(start >= end || end > strlen(str)) {
        return NULL;
    }

    sub = (char *) malloc(sizeof(char) * (end - start + 1));

    for(i = start, j = 0; i < end; i++, j++) {
        sub[j] = str[i];
    }

    return sub;
}

void separaDados (char* str){

    int procura, inicio;

    procura = inicio = 0;

    while (str[procura] != '*'){
        procura++;
    }

    strncpy(recebe.nome, string_substring(str, 0, procura), procura);
    inicio = procura+1;
    procura ++;

    while (str[procura] != '*'){
        procura++;
    }

    strcpy(recebe.CPF, string_substring(str, inicio, procura));
    inicio = procura+1;
    procura ++;

    while (str[procura] != '*'){
        procura++;
    }

    strcpy(recebe.aniversario, string_substring(str, inicio, procura));
    procura ++;
    strcpy(recebe.senha, string_substring(str, procura, strlen(str)));
}

void desconverteDados (){

    int i, j;
    char recebeStr;

    j=0;
    for (i=0;i<strlen(recebe.nome);i+=2){
    	recebeStr = desconverteHex(recebe.nome[i],recebe.nome[i+1]);
    	consultado.nome[j] = recebeStr;
    	j++;
	}
	for(i=0;i<strlen(consultado.nome);i++){
        consultado.nome[i] = consultado.nome[i]-3;
	}

	j=0;
    for (i=0;i<strlen(recebe.CPF);i+=2){
    	recebeStr = desconverteHex(recebe.CPF[i],recebe.CPF[i+1]);
    	consultado.CPF[j] = recebeStr;
    	j++;
	}
	for(i=0;i<strlen(consultado.CPF);i++){
        consultado.CPF[i] = consultado.CPF[i]-3;
	}

	j=0;
    for (i=0;i<strlen(recebe.aniversario);i+=2){
    	recebeStr = desconverteHex(recebe.aniversario[i],recebe.aniversario[i+1]);
    	consultado.aniversario[j] = recebeStr;
    	j++;
	}
	for(i=0;i<strlen(consultado.aniversario);i++){
        consultado.aniversario[i] = consultado.aniversario[i]-3;
	}

	j=0;
    for (i=0;i<strlen(recebe.senha);i+=2){
    	recebeStr = desconverteHex(recebe.senha[i],recebe.senha[i+1]);
    	consultado.senha[j] = recebeStr;
    	j++;
	}
	for(i=0;i<strlen(consultado.senha);i++){
        consultado.senha[i] = consultado.senha[i]-3;
	}
}
