#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

void parser_LL();

int main()
{
    printf("\n\n\n");
    printf("\t\t \033[1;35m ┌────────────────────────┐\n");
    printf("\t\t \033[1;35m │         SCANNER        │\n");
    printf("\t\t \033[1;35m └────────────────────────┘\n\n");

    scanner("./data/fuente.txt");
    ListaTokens_Imprime();

    printf("\n\n\n");
    printf("\t\t \033[1;35m ┌────────────────────────┐\n");
    printf("\t\t \033[1;35m │         PARSER         │\n");
    printf("\t\t \033[1;35m └────────────────────────┘\n\n");
    parser_LL();

    ListaTokens_Libera();
    //ImprimirListaToken();
    //LiberarListaToken();

    return 0;
}//main
