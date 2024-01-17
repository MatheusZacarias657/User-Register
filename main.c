
/* A main é responsável por verificar se há uma pasta que já foi
 * definida como iniciar a contagem dos registros
 */

#include<stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "trataTxt.h"
#include "cadastraUsuario.h"

int main(){

    num = 0;
    strcpy(caminhoPasta, LeConfiguracao());
    menu();

    return 0;
}
