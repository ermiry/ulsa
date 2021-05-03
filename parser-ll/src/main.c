#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

int main (int argc, const char **argv) {

	if (argc > 1) {
		(void) printf ("==============================");
		(void) printf ("\n SCANNER \n\n");
		(void) printf ("==============================");
		scanner (argv[1]);
		
		ListaTokens_Imprime ();

		(void) printf ("==============================");
		(void) printf ("\n\n PARSER \n\n");
		(void) printf ("==============================");
		parser_LL ();

		ListaTokens_Libera ();
	}

	else {
		(void) printf ("Missing input file!\n\n");
	}

	return 0;

}
