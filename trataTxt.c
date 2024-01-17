
/* Ele possui algumas funções muito importantes para
 * o projeto, a primeira cria o nome (e consequentemente)
 * o endereço dos arquivos se preocupando com o número do registro
 * depois ele tem uma função que salva o arquivo, le algum arquivo
 * e depois a penultima pega o texto que seja digitado para endereço
 * de registro dos usuarios e transforma em comando para pode ser usado
 * tipo C:/desktop tem q virar C://desktop
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "trataTxt.h"
#include "descriptografia.h"

int criaNome (int indice){

    char num[3], recebe[5];
    char caminho [200] = "";
    char nome [16]= "";

    itoa(indice, recebe, 10);

    if (indice < 10){
        strcat(num, "00");
        strncat(num, recebe,strlen(recebe));
    }
    else if (indice < 100){
        strcat(num, "0");
        strncat(num, recebe,strlen(recebe));
    }
    else{
        strncat(num, recebe,strlen(recebe));
    }

    if (strlen(caminhoPasta) == 0){
        strncat(caminho,caminhoNome, 8);
        strncat(caminho, num, 3);
        strncat(caminho, caminhoEnd, 4);
        strncpy(caminhoArquivo, caminho, 15);
    }
    else{
        strncat(caminho,caminhoPasta, strlen(caminhoPasta));
        strncat(caminho,caminhoNome, 8);
        strncat(caminho, num, 3);
        strncat(caminho, caminhoEnd, 4);
        strncpy(caminhoArquivo, caminho, strlen(caminho));
    }

    strncat(nome,caminhoNome, 8);
    strncat(nome, num, 3);
    strncat(nome, caminhoEnd, 4);
    strncpy(nomeArquivo, nome, strlen(nome));

    return 0;
}

int SalvarArquivo(char* Conteudo){

	int retorno;

	arquivo = fopen(caminhoArquivo, "wt");
	retorno =  fprintf(arquivo, "%s", Conteudo);
	fclose(arquivo);

	return retorno;
}

char* LerArquivo(){

	arquivo = fopen(caminhoArquivo, "r");
	char* texto = (char*) malloc(tamanhoMax * sizeof(char));
	int i;

	for(i=0; i<tamanhoMax; i++) texto[i] = 0;
	fgets(texto, tamanhoMax, arquivo);
	fclose(arquivo);

	return texto;
}

void setaCaminho (){

    int i, j, marca, cont;
    char caminho[180] = "";
    bool trava;
    char pasta [180]= "";

    strcpy(pasta, caminho);
    cabecalho();
    printf("\n Cole o caminho da pasta que deseja guardar os arquivos: ");
    printf("\n\n\n Caso esteja em dúvida de como achar o caminhho abra a Barra de Tarefas > Explorador de Arquivos");
    printf("\n procure a pasta e abra a guia Inicio > Copiar caminho. Não utilize pastas com caractéres especiais");
    printf("\n no nome, com exceção a espaço.");
    gotoxy(58, 5);
    fflush(stdin);
    gets(caminho);
    system("cls");

    i = j = marca = cont = 0;
    trava = true;

    while (trava == true){
        if (caminho[i] == '\\'){
            cont++;
        }
        if (i > strlen(caminho)){
            break;
        }
        i++;
    }
    i=0;
    while(i <cont){

        while(caminho[j] != '\\'){
            j++;
        }
        strncat(pasta,string_substring(caminho,marca,j), j-marca);
        strncat(pasta, "\\\\",2);
        j++;
        marca = j;
        i ++;
    }

    strncat(pasta,string_substring(caminho,j,strlen(caminho)), strlen(caminho)-j);

    if (pasta[0] == '"'){
        strncpy(caminhoPasta,string_substring(pasta,1,strlen(pasta)-1), strlen(pasta)-2);
    }
    strncat(caminhoPasta, "\\\\",2);


    config = fopen("config.txt", "wt");
	fprintf(config, "%s", caminhoPasta);
	fclose(config);

    cabecalho();
    printf("\n Caminho registrado com sucesso! ");
}

char* LeConfiguracao(){

	config = fopen("config.txt", "r");
	char* conf = (char*) malloc(tamanhoMax * sizeof(char));
	int i;

	for(i=0; i<tamanhoMax; i++) conf[i] = 0;
	fgets(conf, tamanhoMax, config);
	fclose(config);

	return conf;
}

void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
