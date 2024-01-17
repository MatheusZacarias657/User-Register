
/* Declaração das funções contidas em descriptografia.c
 * e cria um novo struct com o dobro da quantidade de
 * caracteres do cadastro para receber eles em hexadecimal
 */

#ifndef DESCRIPTOGRAFIA_H
#define DESCRIPTOGRAFIA_H

typedef struct{

    char nome [100];
    char CPF [28];
    char aniversario[20];
    char senha [100];

} UsuarioHex;

UsuarioHex recebe;

char* string_substring(char str[], int start, int end);
void descriptografa(char* recebeTexto);
void converteChave(char* leitura_chave, int leng, int* chave, int tamanho);
void desenbaralha (char* vet, int vetSize, int* chave);
void separaDados (char* str);
void desconverteDados ();

#endif // DESCRIPTOGRAFIA_H
