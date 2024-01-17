
/* Apenas limpa o terminal e exibe um cabeçalho serve
 * par anão deixa-lo poluído
 */

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cabecalho.h"


void cabecalho(){

    setlocale(LC_ALL, "Portuguese");

    system("cls");
	printf("\n\t\t\t   Cadastro de Usuários");
	printf("\n ========================================================================\n");
}
