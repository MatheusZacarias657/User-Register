

/* Declaração das funções contidas em cadastraUsuario.c
 * e cria a variavel de contagem de usuarios e o struct
 * responsvel por recolher os dados
 */

#ifndef CADASTRAUSUARIO_H
#define CADASTRAUSUARIO_H

#include <stdbool.h>
typedef struct{

    char nome [50];
    char CPF [14];
    char aniversario[10];
    char senha [50];

} Usuario;

Usuario user;
int num;

int cadastro ();
void avaliaNome ();
void avaliaCPF ();
void avaliaAniversario ();
void avaliaSenha();
int confirmaCadastro();
bool analisaData();

#endif // CADASTRAUSUARIO_H
