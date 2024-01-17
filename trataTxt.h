
/* Declaração das funções contidas em trataTxt.c
 * os arquivo de registro e configurações, algumas variaveis
 * e constante de nome para poder fazer os arquivos
 */

#ifndef TRATATXT_H
#define TRATATXT_H

#define tamanhoMax 1000000
#define caminhoNome "Registro"
#define caminhoEnd ".txt"

FILE *arquivo;
FILE *config;
char caminhoArquivo[200];
char caminhoPasta [180];
char nomeArquivo [15];

int criaNome (int indice);
int SalvarArquivo(char* Conteudo);
char* LerArquivo();
void setaCaminho();
char* LeConfiguracao();
void gotoxy(int x, int y);


#endif // TRATATXT_H
