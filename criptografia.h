
/* Declaração das funções contidas em criptografia.c
 * e duas variaveis resposaveis por tratar o texto
 * criptografado
 */

#ifndef CRIPTOGRAFIA_H
#define CRIPTOGRAFIA_H

#include "trataTxt.h"
char textoCrip[255];
char mandaTexto[tamanhoMax];

void startCriptografia(int start);
void trocaLetras();
int concatenaTexto();
void embaralhar(char* vet, int vetSize, int* chave);
void geraChave(int* chave, int tamanho, char* retorno);
#endif // CRIPTOGRAFIA_H
