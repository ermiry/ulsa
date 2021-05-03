#ifndef _SCANNER_H_
#define _SCANNER_H_

#define TIPO_NODO_Inicial 0
#define TIPO_NODO_Intermedio 1
#define TIPO_NODO_IntermedioFinal 2
#define TIPO_NODO_Final 3

#define TRUE (-1)
#define FALSE (0)

#define ESPACIOS_POR_TAB 8

#define SCANNER_ERROR -1
#define TOKEN_RECONOCIDO -1


#define SIMBOLO_TERMINAL_ID 1
#define SIMBOLO_TERMINAL_programa 2
#define SIMBOLO_TERMINAL_LLAVE_A 3
#define SIMBOLO_TERMINAL_LLAVE_C 4
#define SIMBOLO_TERMINAL_PARENTESIS_A 5
#define SIMBOLO_TERMINAL_PARENTESIS_C 6
#define SIMBOLO_TERMINAL_if 7
#define SIMBOLO_TERMINAL_PuntoYComa 8
#define SIMBOLO_TERMINAL_IGUAL 9
#define SIMBOLO_TERMINAL_else 10
#define SIMBOLO_TERMINAL_while 11
#define SIMBOLO_TERMINAL_INTERROGACION 12
#define SIMBOLO_TERMINAL_MAS  13
#define SIMBOLO_TERMINAL_MENOS 14
#define SIMBOLO_TERMINAL_POR 15
#define SIMBOLO_TERMINAL_MAYORQUE 16
#define SIMBOLO_TERMINAL_MAYOROIGUAL 17
#define SIMBOLO_TERMINAL_MENORQUE 18
#define SIMBOLO_TERMINAL_MENOROIGUAL 19
#define SIMBOLO_TERMINAL_IGUALDAD 20
#define SIMBOLO_TERMINAL_DESIGUAL 21
#define SIMBOLO_TERMINAL_AND 22
#define SIMBOLO_TERMINAL_OR 23
#define SIMBOLO_TERMINAL_NUMERO_ENTERO 24
#define SIMBOLO_TERMINAL_NUMERO_REAL 25
#define SIMBOLO_TERMINAL_Espacio 26
#define SIMBOLO_TERMINAL_Tabulador 27
#define SIMBOLO_TERMINAL_SaltoDeLinea 28
#define SIMBOLO_TERMINAL_FinalDeArchivo 29
#define SIMBOLO_TERMINAL_NEGACION 30
#define SIMBOLO_TERMINAL_DIVISION 31
#define SIMBOLO_TERMINAL_SELECT 32
#define SIMBOLO_TERMINAL_FROM 33
#define SIMBOLO_TERMINAL_WHERE 34
#define SIMBOLO_TERMINAL_COMA 35
#define SIMBOLO_TERMINAL_POTENCIA 36

struct t_token
{
    int intTokenCodigo;
    char *strTokenTextoFuente;
    int intRenglon;
    int intColumna;
    struct t_token *ptrSig;
};

typedef struct t_token t_token;

extern int scanner(const char *strArchivoNombre);
extern void ListaTokens_Libera(void);
extern void ListaTokens_Imprime(void);

#endif

