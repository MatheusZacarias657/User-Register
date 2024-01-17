
/* Declaração das funções contidas em consultaCadastro.c
 * e cria uma variavel do tipo usuario para receber os dados
 * descriptografados
 */

#ifndef CONSULTACADASTRO_H
#define CONSULTACADASTRO_H
#include "cadastraUsuario.h"

Usuario consultado;

int consulta();
void exibeUsuario();
int verificaUsuario();
void trocaSenha(int indice);
void certificaSenha(char* senha);

#endif // CONSULTACADASTRO_H
