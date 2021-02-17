#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lexal.h"

t_token *ptrTokenList = NULL;

int MT[AUTOMATA_ESTADOS_NUM][AUTOAMATA_SIMBOLOS_ENTRADA_Y_CONTROL] = {
{37,50,50,50,50,50,50,50,50,50,50,50,50,50,40,50,50,50,50,50,50,50,50,50,50,50,50,61,57,50,17,50,50,50,13,50,50,50,50,50,50,1,50,50,51,50,50,50,21,50,50,50,43,43,43,43,43,43,43,43,43,43,9,10,11,15,16,26,27,29,30,31,32,33,35,42,66,50,-1,45,46,47,48,49,TIPO_NODO_Intermedio,SCANNER_ERROR},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,2,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,3,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,4,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,5,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,6,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,7,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,8,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Programa},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_LlaveInicio},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_LlaveFin},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Igual},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_IgualIgual},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,14,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_If},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ParentesisInicio},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ParentesisFin},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,18,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,19,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,20,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Else},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,22,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,23,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,24,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,25,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_While},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Interrogacion},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Admiracion},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Desigual},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Suma},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Resta},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Multiplicacion},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Division},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MayorQue},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MayorIgualQue},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MenorQue},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_MenorIgualQue},
{50,50,50,50,50,50,50,50,50,50,50,50,50,38,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,39,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_AND},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,41,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_ID},
{50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_OR},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_Potencia},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,43,43,43,43,43,43,43,43,43,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,44,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_NumEntero},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,44,44,44,44,44,44,44,44,44,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_IntermedioFinal,SIMBOLO_TERMINAL_NumReal},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_PuntoYComa},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Espacio},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_Tabulador},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,TIPO_NODO_Final,SIMBOLO_TERMINAL_SaltoDeLinea},
};

const char *obtener_etiqueta_del_simbolo_que_termina (SimboloTerminal simbolo) {

	switch (simbolo) {
		#define XX(num, name, string) case SIMBOLO_TERMINAL_##name: return #string;
		SIMBOLO_TERMINAL_MAP(XX)
		#undef XX
	}

	return obtener_etiqueta_del_simbolo_que_termina (SIMBOLO_TERMINAL_NONE);

}

int obtener_codigo_simbolo_entrada (char a) {

	switch (a) {
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
		case '{': return 62; break;
		case '}': return 63; break;
		case '=': return 64; break;
		case '(': return 65; break;
		case ')': return 66; break;
		case '?': return 67; break;
		case '!': return 68; break;
		case '+': return 69; break;
		case '-': return 70; break;
		case '*': return 71; break;
		case '/': return 72; break;
		case '>': return 73; break;
		case '<': return 74; break;
		case '^': return 75; break;
		case '_': return 76; break;
		case ':': return 77; break;
		case '.': return 78; break;
		case ';': return 79; break;
		case ' ': return 80; break;
		case '\t': return 81; break;
		case '\n': return 82; break;
		case -1: return 83; break;
		default: return 99; break;
	}

}

void token_list_add (
	int intTokenCodigo, char *strTokenTextoFuente,
	int intRenglon, int intColumna
) {

	t_token *ptrTmp = ptrTokenList;

	t_token *ptrTokenNuevo = (t_token *) malloc (sizeof(t_token));
	ptrTokenNuevo->intTokenCodigo = intTokenCodigo;
	ptrTokenNuevo->strTokenTextoFuente =
		(char *) malloc (strlen(strTokenTextoFuente) + 1);
	ptrTokenNuevo->strTokenTextoFuente[0] = '\0';
	(void) strcpy (ptrTokenNuevo->strTokenTextoFuente, strTokenTextoFuente);
	ptrTokenNuevo->intRenglon = intRenglon;
	ptrTokenNuevo->intColumna = intColumna;
	ptrTokenNuevo->ptrSig = NULL;

	if (ptrTmp == NULL) {
		ptrTokenList = ptrTokenNuevo;
	}

	else {
		while (ptrTmp->ptrSig != NULL) {
			ptrTmp = ptrTmp->ptrSig;
		}

		ptrTmp->ptrSig = ptrTokenNuevo;
	}

}

int es_token_separador(int intCodigoSimboloTerminal) {

	int boolRespuesta = false;

	switch (intCodigoSimboloTerminal) {
		case SIMBOLO_TERMINAL_Espacio:
			boolRespuesta = true;
			break;
		case SIMBOLO_TERMINAL_Tabulador:
			boolRespuesta = true;
			break;
		case SIMBOLO_TERMINAL_SaltoDeLinea:
			boolRespuesta = true;
			break;
		default:
			break;
	}

	return boolRespuesta;
}

void scanner (const char *strArchivoNombre) {

	FILE *ptrArchivoFuente = NULL;
	int intEstadoActual = 0;
	char c = 0;
	int intEstadoSiguiente = 0;
	int intCodigoSimboloEntrada = 0;
	int intTipoNodo = 0;
	int intCodigoSimboloTerminal = 0;
	int boolBanderaLee = true;
	int intRenglon = 1;
	int intColumna = 0;
	int intRenglonToken = 0;
	int intColumnaToken = 0;

	int intLenAux;
	ptrArchivoFuente = fopen (strArchivoNombre, "r");


	char strBuffer[1024] = { 0 };

	if (ptrArchivoFuente == NULL) {
		perror ("Error en archivo fuente.\n");
	}

	else {
		do {
			if (boolBanderaLee) {
				c = getc(ptrArchivoFuente);

				if (c == '\n') {
					intRenglon++;
					intColumna = 0;
				}

				else {
					if (c == '\t') {
						intColumna = intColumna + (ESPACIOS_POR_TAB - (intColumna % ESPACIOS_POR_TAB));
					}

					else {
						intColumna++;
					}
				}
			}

			if (intEstadoActual == 0) {
				intRenglonToken = intRenglon;
				intColumnaToken = intColumna;
			}

			if (!boolBanderaLee) {
				boolBanderaLee = true;
			}

			intCodigoSimboloEntrada = obtener_codigo_simbolo_entrada(c);

			// printf ("%d\n", intCodigoSimboloEntrada);

			if (intCodigoSimboloEntrada == 99) {
				strcpy(strBuffer,"\0");
			}

			intEstadoSiguiente = MT[intEstadoActual][intCodigoSimboloEntrada];
			intTipoNodo =
				MT[intEstadoActual][AUTOMATA_TIPO_NODO];

			// printf ("%d\n", MT[intEstadoActual][intCodigoSimboloEntrada]);

			if (
				(intEstadoSiguiente == TOKEN_RECONOCIDO)
				&& ((intTipoNodo == TIPO_NODO_Final) || (intTipoNodo == TIPO_NODO_IntermedioFinal))
			) {
				intCodigoSimboloTerminal = MT[intEstadoActual][AUTOMATA_CODIGO_SALIDA];

				if (!es_token_separador (intCodigoSimboloTerminal)) {
					(void) printf (
						"Token Reconocido r[%d] c[%d][%d]: [%s] Codigo: [%s]\n",
						intRenglonToken, intColumnaToken,
						intCodigoSimboloTerminal, obtener_etiqueta_del_simbolo_que_termina (
							intCodigoSimboloTerminal
						),
						strBuffer
					);

					token_list_add (
						intCodigoSimboloTerminal, strBuffer,
						intRenglonToken, intColumnaToken
					);
				}

				boolBanderaLee = false;
				intEstadoActual = 0;
				strBuffer[0] = '\0';

			}

			else if (intEstadoSiguiente == SCANNER_ERROR) {
				(void) printf ("Error Lexico r[%d]c[%d]\n", intRenglonToken, intColumnaToken);
				intEstadoActual = 0;
				(void) strcpy (strBuffer,"\0");
			}

			else {
				intEstadoActual = intEstadoSiguiente;

				intLenAux = strlen(strBuffer);
				strBuffer[intLenAux] = c;
				strBuffer[intLenAux + 1] = '\0';
			}
		} while (c != EOF);
	}

}

int main (int argc, const char **argv) {

	scanner ("./data/fuente.txt");

	return 0;

}