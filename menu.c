
/* Basicamente ele procura inicialmente o último registro
 * e logo após atribui a contagem para não sobrescrever algum
 * usuário logo após o menu é iniciado sem o cursor e conforme
 * for selecionado ele deve agir correspondendo a opção
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "cabecalho.h"
#include "menu.h"
#include "cadastraUsuario.h"
#include "consultaCadastro.h"
#include "trataTxt.h"
#include "criptografia.h"

int menu(){

	setlocale(LC_ALL, "Portuguese");

	int retorna, analisa, navega, recolhe;
	char procura[tamanhoMax];
	navega = 1;

	criaNome(num);
    strcpy(procura, LerArquivo());

    while (strlen(procura) != 0){
        num++;
        criaNome(num);
        strcpy(procura, LerArquivo());
    }

	do{
        do{
            cabecalho();
            printf(" Use w para ir para cima e s para baixo \n");
            tiraCursor();
            switch(navega){
                case 1:
                opcaoUm();
                break;
                case 2:
                opcaoDois();
                break;
                case 3:
                opcaoTres();
                break;
                case 4:
                opcaoQuatro();
                break;
                default:
                break;
            }
            fflush(stdin);
            recolhe = getch();
            recolhe = toupper(recolhe);

            if (recolhe == 87){
                if(navega == 1){
                    navega =4;
                }
                else{
                    navega --;
                }
            }

            if (recolhe == 83){
                if(navega == 4){
                    navega =1;
                }
                else{
                    navega ++;
                }
            }

        }while (recolhe != 13);

        mostraCursor();
        switch(navega){
            case 1:
            cadastro();
            analisa = confirmaCadastro();
            startCriptografia(analisa);
            SalvarArquivo(mandaTexto);
            break;
            case 2:
            consulta();
            break;
            case 3:
            setaCaminho();
            break;
            case 4:
            cabecalho();
            printf("\n Até a próxima \n");
            recolhe = 9;
            break;
            default:
            break;
        }

        if (navega != 4){
            tiraCursor();
            printf("\n ========================================================================\n");
            printf("\n Para voltar ao menu precione Enter...");
            fflush(stdin);
            recolhe = getch();
            navega = 1;
        }

	}while(recolhe == 13);

    return 0;
}

void opcaoUm(){

    printf("\n >Registar um novo usuário");
    printf("\n  Consultar dados de um usuário");
    printf("\n  Configurar pasta destino dos registros");
    printf("\n  Sair");
}

void opcaoDois(){

    printf("\n  Registar um novo usuário");
    printf("\n >Consultar dados de um usuário");
    printf("\n  Configurar pasta destino dos registros");
    printf("\n  Sair");
}

void opcaoTres(){

    printf("\n  Registar um novo usuário");
    printf("\n  Consultar dados de um usuário");
    printf("\n >Configurar pasta destino dos registros");
    printf("\n  Sair");
}

void opcaoQuatro(){

    printf("\n  Registar um novo usuário");
    printf("\n  Consultar dados de um usuário");
    printf("\n  Configurar pasta destino dos registros");
    printf("\n >Sair");
}

void tiraCursor(){

   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 5;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void mostraCursor(){

   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 5;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
