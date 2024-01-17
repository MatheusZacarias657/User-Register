
/* Solicita o número do usuário que vai se consultar
 * descriptografa o que foi escrito no arquivo (verifica
 * se o arquivo existe obviamente) e para ver os dados é
 * pedido para confirmar a senha e caso erre a senha é oferecido
 * a troca mediante a confirmação de cpf ou de aniversario
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "trataTxt.h"
#include "cabecalho.h"
#include "consultaCadastro.h"
#include "descriptografia.h"
#include "criptografia.h"
#include "cadastraUsuario.h"
#include "menu.h"

int consulta (){

    int entrada, repete, tentativa = 1;

    bool verifica = false;

    do{
        char recebe[tamanhoMax] = "";
        cabecalho();
        mostraCursor();
        printf("\n Digite o número do usuário que deseja consultar: ");
        scanf("%d", &entrada);

        criaNome(entrada);
        strcpy(recebe, LerArquivo());

        if (arquivo == NULL){
            cabecalho();
            printf("\n Arquivo não encontrado, favor verifique o número digitado.\n");
            verifica = true;
        }
        else{
            cabecalho();
            descriptografa(recebe);
            if (verificaUsuario() != 0){
                verifica = true;
                if (tentativa == 2){
                    //trocaSenha(0);
                    tentativa = 0;
                }
                else{
                  tentativa ++;
                }
            }
            else{
                cabecalho();
                exibeUsuario();
                verifica = false;
                repete = 1;
            }

        }

        if (verifica == true){
            tiraCursor();
            printf("\n ========================================================================\n");
            printf("\n Para tentar novamente precione Enter...");
            fflush(stdin);
            repete = getch();
        }
    }while (repete == 13);

    return 0;
}

void exibeUsuario (){

    printf("\n Arquivo de usuário: %s", nomeArquivo);
    printf("\n Nome completo: %s", consultado.nome);
    printf("\n CPF: %s",  consultado.CPF);
    printf("\n Aniversário: %s",  consultado.aniversario);
}

int verificaUsuario(){

    char recolheSenha[50] ="";

    cabecalho();
    printf("\n Por favor confirme a sua senha: ");
    fflush(stdin);
    gets(recolheSenha);

    int avr = strncmp(recolheSenha, consultado.senha, strlen(consultado.senha));

    if (avr != 0){
        cabecalho();
        printf("\n A senha não coincide, por favor verifique a senha \n");
    }

    return avr;
}

void trocaSenha(int indice){

    char novaSenha[50]="";
    char confirma[30]="";
    int resposta, varia, avr;

    resposta = varia = avr = 0;
    cabecalho();
    tiraCursor();
    printf("\n Esqueceu sua senha? Aperte Enter para troca-lá... \n");
    fflush(stdin);
    resposta = getch();

    if (resposta == 13){
        cabecalho();

        varia = strlen(consultado.nome)%2;

        if (varia == 1){
            printf("\n Primeiramente confirme seu CPF: ");
            fflush(stdin);
            gets(confirma);

            avr = strncmp(confirma, consultado.CPF, strlen(consultado.CPF));
        }
        else{
            printf("\n Primeiramente confirme seu aniversário: ");
            fflush(stdin);
            gets(confirma);

            avr = strncmp(confirma, consultado.aniversario, strlen(consultado.aniversario));
        }

        if (avr == 0){
            cabecalho();
            printf("\n Digite sua nova senha de acesso (mínimo de 6 caracteres): ");
            fflush(stdin);
            gets(novaSenha);
            certificaSenha(novaSenha);

            strncpy(user.nome,consultado.nome, strlen(consultado.nome));
            strncpy(user.CPF,consultado.CPF, strlen(consultado.CPF));
            strncpy(user.aniversario,consultado.aniversario, strlen(consultado.aniversario));
            strncpy(user.senha,novaSenha, strlen(novaSenha));
            criaNome(indice);
            startCriptografia(0);
            SalvarArquivo(mandaTexto);
        }

    }
}

void certificaSenha(char* senha){

    while (strlen(senha < 6)){
        cabecalho();
        printf("\n Senha inválida, digite novamente: ");
        fflush(stdin);
        gets(senha);
    }
}
