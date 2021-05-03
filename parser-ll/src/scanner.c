#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../include/scanner.h"


#define AUTOMATA_ESTADOS_NUM 67
#define AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL 85

#define AUTOMATA_TIPO_NODO (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 2)
#define AUTOMATA_CODIGO_SALIDA (AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL - 1)

int MT[AUTOMATA_ESTADOS_NUM][AUTOMATA_SIMBOLOS_ENTRADA_Y_CONTROL] = {
// A  C  D  G  I  J  L  M  O  P  R  S  T  U  V  0  1  2  3  4  5  6  7  8  9 _  ;  esp tab \n EOF
{36,50,50,50,50,63,50,50,50,50,50,50,50,50,39,50,50,50,51,50,50,50,58,50,50,50,50,50,50,50,17,50,50,50,13,50,50,50,50,50,50,1,50,50,50,50,50,50,21,50,50,50,42,42,42,42,42,42,42,42,42,42,27,28,29,49,16,35,32,30,26,41,9,10,11,12,44,46,45,50,15,57,47,TIPO_NODO_Intermedio,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,2,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,3,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,4,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,5,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,6,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,7,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,8,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_programa},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_LLAVE_A},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_LLAVE_C},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_PARENTESIS_A},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_PARENTESIS_C},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,14,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_if},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_PuntoYComa},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_IGUAL},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,18,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,19,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,20,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_else},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,22,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,23,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,24,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,25,50,50,50,50,50,50,-1,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_while},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_INTERROGACION},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MAS},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MENOS},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_POR},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,31,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MAYORQUE},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MAYOROIGUAL},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MENORQUE},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MENOROIGUAL},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_IGUALDAD},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,37,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,38,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_AND},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,40,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_OR},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,42,42,42,42,42,42,42,42,42,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_NUMERO_ENTERO},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,43,43,43,43,43,43,43,43,43,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_NUMERO_REAL},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Espacio},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Tabulador},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SaltoDeLinea},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_FinalDeArchivo},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_DESIGUAL},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_DIVISION},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,52,50,50,50,50,50,50,-1,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,53,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,54,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,55,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_SELECT},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,56,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_COMA},
{50,50,50,50,50,50,50,59,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,60,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,61,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,62,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_WHERE},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,64,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,65,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,66,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_FROM}

};


t_token *ptrTokenList = NULL;


void InsertarEnTokenList(int intTokenCodigo, const char *strTokenTextoFuente,int intRenglon, int intColumna)
{
    t_token *ptrTmp = ptrTokenList;

    t_token *ptrTokenNuevo = (t_token *)malloc(sizeof(t_token));
    ptrTokenNuevo->intTokenCodigo = intTokenCodigo;
    ptrTokenNuevo->strTokenTextoFuente =
        (char *)malloc(strlen(strTokenTextoFuente)+1);
    ptrTokenNuevo->strTokenTextoFuente[0] = '\0';
    strcpy(ptrTokenNuevo->strTokenTextoFuente, strTokenTextoFuente);
    ptrTokenNuevo->intRenglon = intRenglon;
    ptrTokenNuevo->intColumna = intColumna;
    ptrTokenNuevo->ptrSig =NULL;

    if (ptrTmp == NULL) //La lista est� vac�a
    {
        ptrTokenList = ptrTokenNuevo;
    }
    else
    {
        while(ptrTmp->ptrSig != NULL)
        {
            ptrTmp = ptrTmp->ptrSig;
        }
        ptrTmp->ptrSig = ptrTokenNuevo;
    }

}//InsertarEnTokenList


int ObtenerCodigoSimboloEntrada(char c)
{
    int intCodigoSimboloEntrada = -1;

    switch(c)
    {
        case 'A': return 0; break;
        case 'B': return 1; break;
        case 'C': return 2; break;
        case 'D': return 3; break;
        case 'E': return 4; break;
        case 'F': return 5; break;
        case 'G': return 6; break;
        case 'H': return 7; break;
        case 'I': return 8; break;
        case 'J': return 9; break;
        case 'K': return 10; break;
        case 'L': return 11; break;
        case 'M': return 12; break;
        case 'N': return 13; break;
        case 'O': return 14; break;
        case 'P': return 15; break;
        case 'Q': return 16; break;
        case 'R': return 17; break;
        case 'S': return 18; break;
        case 'T': return 19; break;
        case 'U': return 20; break;
        case 'V': return 21; break;
        case 'W': return 22; break;
        case 'X': return 23; break;
        case 'Y': return 24; break;
        case 'Z': return 25; break;
        case 'a': return 26; break;
        case 'b': return 27; break;
        case 'c': return 28; break;
        case 'd': return 29; break;
        case 'e': return 30; break;
        case 'f': return 31; break;
        case 'g': return 32; break;
        case 'h': return 33; break;
        case 'i': return 34; break;
        case 'j': return 35; break;
        case 'k': return 36; break;
        case 'l': return 37; break;
        case 'm': return 38; break;
        case 'n': return 39; break;
        case 'o': return 40; break;
        case 'p': return 41; break;
        case 'q': return 42; break;
        case 'r': return 43; break;
        case 's': return 44; break;
        case 't': return 45; break;
        case 'u': return 46; break;
        case 'v': return 47; break;
        case 'w': return 48; break;
        case 'x': return 49; break;
        case 'y': return 50; break;
        case 'z': return 51; break;
        case '0': return 52; break;
        case '1': return 53; break;
        case '2': return 54; break;
        case '3': return 55; break;
        case '4': return 56; break;
        case '5': return 57; break;
        case '6': return 58; break;
        case '7': return 59; break;
        case '8': return 60; break;
        case '9': return 61; break;
        case '+': return 62; break;
        case '-': return 63; break;
        case '*': return 64; break;
        case '/': return 65; break;
        case '=': return 66; break;
        case '!': return 67; break;
        case '<': return 68; break;
        case '>': return 69; break;
        case '?': return 70; break;
        case '^': return 71; break;
        case '{': return 72; break;
        case '}': return 73; break;
        case '(': return 74; break;
        case ')': return 75; break;
        case ' ': return 76; break;
        case '\r':
        case '\n': return 77; break;
        case '\t': return 78; break;
        case '.' : return 79; break;
        case ';': return 80; break;
        case ',': return 81; break;



        default: return 99; break;

    }//switch

    return intCodigoSimboloEntrada;
}//ObtenerCodigoSimboloEntrada

char *ObtenerEtiquetaDelSimboloTermina(int intCodigoSimboloTerminal)
{
    char *strTokenSimboloTerminal = (char *)malloc(255);
    strTokenSimboloTerminal[0] = '\0';

       
       switch(intCodigoSimboloTerminal)
    {
        case SIMBOLO_TERMINAL_ID:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_ID"); break;
        case SIMBOLO_TERMINAL_programa:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_programa"); break;
        case SIMBOLO_TERMINAL_LLAVE_A:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_LLAVE_A"); break;
        case SIMBOLO_TERMINAL_LLAVE_C:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_LLAVE_C"); break;
        case SIMBOLO_TERMINAL_PARENTESIS_A:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_PARENTESIS_A"); break;
        case SIMBOLO_TERMINAL_PARENTESIS_C:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_PARENTESIS_C"); break;
        case SIMBOLO_TERMINAL_if:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_if"); break;
        case SIMBOLO_TERMINAL_PuntoYComa:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_PuntoYComa"); break;
        case SIMBOLO_TERMINAL_IGUAL:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_IGUAL"); break;
        case SIMBOLO_TERMINAL_else:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_else"); break;
        case SIMBOLO_TERMINAL_while:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_while"); break;
        case SIMBOLO_TERMINAL_INTERROGACION:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_INTERROGACION"); break;
        case SIMBOLO_TERMINAL_MAS:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MAS"); break;
        case SIMBOLO_TERMINAL_MENOS:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MENOS"); break;
        case SIMBOLO_TERMINAL_POR:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_POR"); break;
        case SIMBOLO_TERMINAL_MAYORQUE:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MAYORQUE"); break;
        case SIMBOLO_TERMINAL_MAYOROIGUAL:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MAYOROIGUAL"); break;
        case SIMBOLO_TERMINAL_MENORQUE:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MENORQUE"); break;
        case SIMBOLO_TERMINAL_MENOROIGUAL:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_MENOROIGUAL"); break;
        case SIMBOLO_TERMINAL_IGUALDAD:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_IGUALDAD"); break;
        case SIMBOLO_TERMINAL_DESIGUAL:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_DESIGUAL"); break;
        case SIMBOLO_TERMINAL_AND:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_AND"); break;
        case SIMBOLO_TERMINAL_OR:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_OR"); break;
        case SIMBOLO_TERMINAL_NUMERO_ENTERO:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_NUMERO_ENTERO"); break;
        case SIMBOLO_TERMINAL_NUMERO_REAL:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_NUMERO_REAL"); break;
        case SIMBOLO_TERMINAL_Espacio:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_Espacio"); break;
        case SIMBOLO_TERMINAL_Tabulador:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_Tabulador"); break;
        case SIMBOLO_TERMINAL_SaltoDeLinea:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SaltoDeLinea"); break;
        case SIMBOLO_TERMINAL_FinalDeArchivo:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_FinalDeArchivo"); break;
        case SIMBOLO_TERMINAL_NEGACION:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_NEGACION"); break;
        case SIMBOLO_TERMINAL_DIVISION:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_DIVISION"); break;
        case SIMBOLO_TERMINAL_SELECT:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_SELECT"); break;
        case SIMBOLO_TERMINAL_FROM:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_FROM"); break;
        case SIMBOLO_TERMINAL_WHERE:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_WHERE"); break;
        case SIMBOLO_TERMINAL_COMA:
            strcpy(strTokenSimboloTerminal,"SIMBOLO_TERMINAL_COMA"); break;
            
        }//switch
    //switch

    return strTokenSimboloTerminal;
}//ObtenerEtiquetaDelSimboloTermina

int EsTokenSeparador(int intCodigoSimboloTerminal)
{
    int boolRespuesta = false;

    switch(intCodigoSimboloTerminal)
    {
        case SIMBOLO_TERMINAL_Espacio:
            boolRespuesta = true;
            break;
        case SIMBOLO_TERMINAL_Tabulador:
            boolRespuesta = true;
            break;
        case SIMBOLO_TERMINAL_SaltoDeLinea:
            boolRespuesta = true;
            break;
        default: break;
    }//switch

    return boolRespuesta;
}//EsTokenSeparador

int scanner(const char *strArchivoNombre)
{
    FILE *ptrArchivoFuente;
    //s := s0;
    int intEstadoActual = 0;
    char c;
    int intEstadoSiguiente;
    int intCodigoSimboloEntrada;
    int intTipoNodo;
    int intCodigoSimboloTerminal;
    int boolBanderaLee = true;
    char *strTokenSimboloEntrada; // = (char *)malloc(1024);
    int intRenglon = 1;
    int intColumna = 0;
    int intRenglonToken;
    int intColumnaToken;
    char *strBuffer = (char *)malloc(1024);
    strBuffer[0] = '\0';
    int intLenAux;
    ptrArchivoFuente = fopen(strArchivoNombre,"r");

    if (ptrArchivoFuente == NULL)
    {
        printf("\033[0;31m Error en archivo fuente.\n");
    }//if
    else
    {
        do
        {
            if (boolBanderaLee)
            {
                //c := siguientecaracter;
                c = getc(ptrArchivoFuente);
                if (c == '\n' || c == '\r')
                {
                    intRenglon++;
                    intColumna=0;
                }//if
                else
                {
                    if (c == '\t')
                    {
                        intColumna = intColumna
                            + (ESPACIOS_POR_TAB - (intColumna  % ESPACIOS_POR_TAB));
                    }
                    else
                    {
                        intColumna++;
                    }
                }//else
            }//if

            if (intEstadoActual == 0)
            {
                intRenglonToken = intRenglon;
                intColumnaToken = intColumna;
            }//if

            if (!boolBanderaLee)
            {
                boolBanderaLee = true;
            }//if

            intCodigoSimboloEntrada = ObtenerCodigoSimboloEntrada(c);
            //   s := mov(s,c);
            intEstadoSiguiente =
                MT[intEstadoActual][intCodigoSimboloEntrada];
            intTipoNodo =
                MT[intEstadoActual][AUTOMATA_TIPO_NODO];
            

            if((intEstadoSiguiente == TOKEN_RECONOCIDO)
               && ((intTipoNodo == TIPO_NODO_Final)
                    || (intTipoNodo == TIPO_NODO_IntermedioFinal)
                  )
              )
            {//SE ACABA DE RECONOCER UN TOKEN
                intCodigoSimboloTerminal =
                   MT[intEstadoActual][AUTOMATA_CODIGO_SALIDA];
                if (!EsTokenSeparador(intCodigoSimboloTerminal))
                {
                    strTokenSimboloEntrada =
                       ObtenerEtiquetaDelSimboloTermina(intCodigoSimboloTerminal);
                    if(strcmp(strBuffer, "SELECT") == 0){
                        intCodigoSimboloTerminal = SIMBOLO_TERMINAL_SELECT;
                        strcpy(strTokenSimboloEntrada, "SIMBOLO_TERMINAL_SELECT");
                    }

                    printf(" \033[0;32m Token Reconocido r[%d] c[%d] [%d]: \033[0;36m [%s] - \033[0;34m  Codigo:[ \033[0m %s\n",
                           intRenglonToken, intColumnaToken,
                           intCodigoSimboloTerminal, strTokenSimboloEntrada,
                           strBuffer);

                    InsertarEnTokenList(intCodigoSimboloTerminal, strBuffer,
                                        intRenglonToken, intColumnaToken);


                    free(strTokenSimboloEntrada);
                }//if

                boolBanderaLee = false;
                intEstadoActual = 0;
                strBuffer[0] = '\0';

            }//if
            else if (intEstadoSiguiente == SCANNER_ERROR)
            {//HAY UN ERROR LEXICO

                printf("Error Lexico r[%d]c[%d]\n",
                       intRenglonToken, intColumnaToken);
                intEstadoActual = 0;
            }//else if
            else
            {//ESTAMOS RECONOCIENDO EL TOKEN ACTUAL
                intEstadoActual = intEstadoSiguiente;

                intLenAux = strlen(strBuffer);
                strBuffer[intLenAux] = c;
                strBuffer[intLenAux+1] = '\0';

            }
        } while (c != EOF);
        //while c <> eof do
        //end;
    }//else

    //free(strTokenSimboloEntrada);
    InsertarEnTokenList(SIMBOLO_TERMINAL_FinalDeArchivo, "SIMBOLO_TERMINAL_EOF",intRenglonToken, intColumnaToken );
    
    free(strBuffer);

    return 0;
}//scanner

void ListaTokens_Libera()
{
    t_token *ptrAux = ptrTokenList;
    t_token *ptrAnt;

    while(ptrAux != NULL) //Mientras no sea igual a nulo se libera el nodo
    {
        ptrAnt = ptrAux;
        ptrAux = ptrAux->ptrSig;

        if(ptrAnt->strTokenTextoFuente != NULL)
            free(ptrAnt->strTokenTextoFuente);
        free(ptrAnt);
    }//while

    ptrTokenList=NULL;
}//ListaTokens_Libera

void ListaTokens_Imprime()
{
    t_token *ptrAux = ptrTokenList;
    printf("\n\n\n");
    printf("\t\t \033[1;35m ┌────────────────────────┐\n");
    printf("\t\t \033[1;35m │   Impresion de lista   │\n");
    printf("\t\t \033[1;35m └────────────────────────┘\n\n");

    while(ptrAux != NULL)
    {
        printf(" \033[0;32m Token Reconocido[%d,%d]: \033[0;34m [%d]-Codigo:[ \033[0m %s \n",
                ptrAux->intRenglon,
                ptrAux->intColumna,
                ptrAux->intTokenCodigo,
                ptrAux->strTokenTextoFuente
                );


        ptrAux = ptrAux->ptrSig;
    }//while
    
}//ListaTokens_Imprime()


