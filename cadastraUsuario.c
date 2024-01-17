
/* De forma bem simples ele recebe os dados e guarda no struct
 * mas verifica se todos os dados s�o verdade analisando tamanho das
 * informa��es e se s�o condizentes
 */

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "cabecalho.h"
#include "cadastraUsuario.h"
#include "trataTxt.h"
#include "descriptografia.h"

bool verificaNome,verificaCPF, verificaAniversario;

int cadastro (){

    verificaCPF = verificaAniversario = verificaNome = false;
    setlocale(LC_ALL, "Portuguese");

    cabecalho();
    printf("\n Digite o seu nome completo: ");
    fflush(stdin);
    gets(user.nome);
    avaliaNome();

    printf("\n Digite o seu CPF: ");
    fflush(stdin);
    gets(user.CPF);
    avaliaCPF();

    printf("\n Digite a data do seu nascimento: ");
    fflush(stdin);
    gets(user.aniversario);
    avaliaAniversario();

    printf("\n Crie uma senha de acesso (m�nimo de 6 caracteres): ");
    fflush(stdin);
    gets(user.senha);
    avaliaSenha();

    return 0;
}

void avaliaNome (){

     while (strlen(user.nome) < 3){
        cabecalho();
        printf("\n Nome inv�lido, digite novamente: ");
        fflush(stdin);
        gets(user.nome);
        verificaNome = true;
     }
}

void avaliaCPF (){

    while (strlen(user.CPF) != 11){
        cabecalho();
        if (verificaNome == true){
           printf("\n Nome inv�lido, digite novamente: %s", user.nome);
        }
        else{
           printf("\n Digite o seu nome completo: %s", user.nome);
        }
        printf("\n\n CPF inv�lido, digite novamente: ");
        gets(user.CPF);
        verificaCPF =true;
    }
}

void avaliaAniversario (){

    while (strlen(user.aniversario) != 8 || analisaData()){
        cabecalho();
        if (verificaNome == true){
           printf("\n Nome inv�lido, digite novamente: %s", user.nome);
        }
        else{
           printf("\n Digite o seu nome completo: %s", user.nome);
        }

        if (verificaCPF == true){
           printf("\n\n CPF inv�lido, digite novamente: %s", user.CPF);
        }
        else{
           printf("\n\n Digite o seu CPF: %s", user.CPF);
        }

        printf("\n\n Anivers�rio inv�lido, digite novamente: ");
        fflush(stdin);
        gets(user.aniversario);
        verificaAniversario = true;
    }
}

void avaliaSenha(){

    while (strlen(user.senha) < 6){
        cabecalho();
        printf("%d", strlen (user.senha));
        if (verificaNome == true){
           printf("\n Nome inv�lido, digite novamente: %s", user.nome);
        }
        else{
           printf("\n Digite o seu nome completo: %s", user.nome);
        }

        if (verificaCPF == true){
           printf("\n\n CPF inv�lido, digite novamente: %s", user.CPF);
        }
        else{
           printf("\n\n Digite o seu CPF: %s", user.CPF);
        }

        if (verificaAniversario == true){
           printf("\n\n Anivers�rio inv�lido, digite novamente: %s", user.aniversario);
        }
        else{
           printf("\n\n Digite a data do seu nascimento: %s", user.aniversario);
        }
        printf("\n\n Senha inv�lida, digite novamente: ");
        fflush(stdin);
        gets(user.senha);
    }
}

bool analisaData(){

    bool retorna = false;
    struct tm *data_hora_atual;
    int diaReal, mesReal, anoReal, diaAni,mesAni, anoAni;

    diaReal = mesReal = anoReal = diaAni = mesAni = anoAni = 0;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    diaReal = data_hora_atual->tm_mday;
    mesReal = data_hora_atual->tm_mon+1;
    anoReal = data_hora_atual->tm_year+1900;
    diaAni = atoi(string_substring(user.aniversario,0,2));
    mesAni = atoi(string_substring(user.aniversario,2,4));
    anoAni = atoi(string_substring(user.aniversario,4,8));

    if (diaReal<diaAni && mesReal<=mesAni && anoReal<=anoAni){
        retorna = true;
    }
    else if(anoReal-150 > anoAni){
        retorna = true;
    }
    else if(diaAni > 31 || mesAni > 12 || anoReal<anoAni){
        retorna = true;
    }
    else if(diaAni > 29 && mesAni == 2 && anoAni%4 == 0){
        retorna = true;
    }
    else if(diaAni > 28 && mesAni == 2 && anoAni%4 != 0){
        retorna = true;
    }

    return retorna;
}

int confirmaCadastro (){

    int selec;
    criaNome(num);

    cabecalho();
    printf("\n Arquivo de usu�rio: %s", nomeArquivo);
    printf("\n Nome completo: %s", user.nome);
    printf("\n CPF: %s", user.CPF);
    printf("\n Anivers�rio: %s", user.aniversario);
    printf("\n\n ========================================================================\n");
    printf("\n Digite 0 para confirmar o cadastro e 1 para cancelar: ");
    scanf("%d", &selec);

    cabecalho();
    if (selec == 0){
        num ++;
        printf("\n Cadastro confirmado! \n");
    }
    else {
        printf("\n Cadastro cancelado \n");
    }

    return selec;
}
