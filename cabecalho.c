
/* Apenas limpa o terminal e exibe um cabe�alho serve
 * par an�o deixa-lo polu�do
 */

#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cabecalho.h"


void cabecalho(){

    setlocale(LC_ALL, "Portuguese");

    system("cls");
	printf("\n\t\t\t   Cadastro de Usu�rios");
	printf("\n ========================================================================\n");
}
