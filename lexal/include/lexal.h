#ifndef _TEDAX_H_
#define _TEDAX_H_

#define TIPO_NODO_Inicial						0
#define TIPO_NODO_Intermedio					1
#define TIPO_NODO_IntermedioFinal				2
#define TIPO_NODO_Final							3

#define SCANNER_ERROR							-1
#define TOKEN_RECONOCIDO						-1

#define ESPACIOS_POR_TAB						8

#define AUTOMATA_ESTADOS_NUM					67
#define AUTOAMATA_SIMBOLOS_ENTRADA_Y_CONTROL	86

#define AUTOMATA_TIPO_NODO (AUTOAMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 2)
#define AUTOMATA_CODIGO_SALIDA (AUTOAMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 1)

#define SIMBOLO_TERMINAL_MAP(XX)											\
	XX(0,	NONE, 					None)									\
	XX(1,	Programa, 				SIMBOLO_TERMINAL_PROGRAMA)				\
	XX(2,	LlaveInicio, 			SIMBOLO_TERMINAL_LLAVE_INICIO)			\
	XX(3,	LlaveFin, 				SIMBOLO_TERMINAL_LLAVE_FIN)				\
	XX(4,	Igual, 					SIMBOLO_TERMINAL_IGUAL)					\
	XX(5,	IgualIgual, 			SIMBOLO_TERMINAL_IGUAL_IGUAL)			\
	XX(6,	If, 					SIMBOLO_TERMINAL_IF)					\
	XX(7,	ParentesisInicio, 		SIMBOLO_TERMINAL_PARENTESIS_INICIO)		\
	XX(8,	ParentesisFin, 			SIMBOLO_TERMINAL_PARENTESIS_FIN)		\
	XX(9,	Else, 					SIMBOLO_TERMINAL_ELSE)					\
	XX(10,	While, 					SIMBOLO_TERMINAL_WHILE)					\
	XX(11,	Interrogacion, 			SIMBOLO_TERMINAL_INTERROGACION)			\
	XX(12,	Admiracion, 			SIMBOLO_TERMINAL_ADMIRACION)			\
	XX(13,	Desigual, 				SIMBOLO_TERMINAL_DESIGUAL)				\
	XX(14,	Suma, 					SIMBOLO_TERMINAL_SUMA)					\
	XX(15,	Resta, 					SIMBOLO_TERMINAL_RESTA)					\
	XX(16,	Multiplicacion, 		SIMBOLO_TERMINAL_MULTIPLICACION)		\
	XX(17,	Division, 				SIMBOLO_TERMINAL_DIVISION)				\
	XX(18,	MayorQue, 				SIMBOLO_TERMINAL_MAYOR_QUE)				\
	XX(19,	MayorIgualQue, 			SIMBOLO_TERMINAL_MAYOR_IGUAL_QUE)		\
	XX(20,	MenorQue, 				SIMBOLO_TERMINAL_MENOR_QUE)				\
	XX(21,	MenorIgualQue, 			SIMBOLO_TERMINAL_MENOR_IGUAL_QUE)		\
	XX(22,	AND, 					SIMBOLO_TERMINAL_AND)					\
	XX(23,	OR, 					SIMBOLO_TERMINAL_OR)					\
	XX(24,	Potencia, 				SIMBOLO_TERMINAL_POTENCIA)				\
	XX(25,	NumEntero, 				SIMBOLO_TERMINAL_NUM_ENTERO)			\
	XX(26,	NumReal, 				SIMBOLO_TERMINAL_NUM_REAL)				\
	/* EXTRA */																\
	XX(27,	PuntoYComa, 			SIMBOLO_TERMINAL_PuntoYComa	)			\
	XX(28,	Espacio, 				SIMBOLO_TERMINAL_Espacio)				\
	XX(29,	Tabulador, 				SIMBOLO_TERMINAL_Tabulador)				\
	XX(30,	SaltoDeLinea, 			SIMBOLO_TERMINAL_SaltoDeLinea)			\
	XX(31,	FinDeArchivo, 			SIMBOLO_TERMINAL_FinDeArchivo)			\
	XX(32,	Switch, 				SIMBOLO_TERMINAL_Switch)				\
	XX(33,	Case, 					SIMBOLO_TERMINAL_Case)					\
	XX(34,	Break, 					SIMBOLO_TERMINAL_Break)					\
	XX(35,	DosPuntos, 				SIMBOLO_TERMINAL_DosPuntos)				\
	/* ID */																\
	XX(36,	ID, 					SIMBOLO_TERMINAL_ID)					\

typedef enum SimboloTerminal {

	#define XX(num, name, string) SIMBOLO_TERMINAL_##name = num,
	SIMBOLO_TERMINAL_MAP (XX)
	#undef XX

} SimboloTerminal;

typedef struct t_token {

	int intTokenCodigo;
	char *strTokenTextoFuente;
	int intRenglon;
	int intColumna;
	struct t_token *ptrSig;

} t_token;

#endif