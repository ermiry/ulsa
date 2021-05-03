#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"

#define TIPO_SIMBOLO_NO_TERMINAL 1
#define TIPO_SIMBOLO_TERMINAL 2

#define ESPACIOS_POR_TAB 8

#define SCANNER_ERROR -1
#define TOKEN_RECONOCIDO -1

#define SIMBOLO_NO_TERMINAL_S                       1
#define SIMBOLO_NO_TERMINAL_InstruccionCompuesta    2
#define SIMBOLO_NO_TERMINAL_BloqueInstruccion       3
#define SIMBOLO_NO_TERMINAL_BloqueInstruccion2      4
#define SIMBOLO_NO_TERMINAL_Instruccion             5  
#define SIMBOLO_NO_TERMINAL_InstruccionAsigancion   6
#define SIMBOLO_NO_TERMINAL_InstruccionIf           7
#define SIMBOLO_NO_TERMINAL_InstruccionIf2          8
#define SIMBOLO_NO_TERMINAL_InstruccionWhile        9
#define SIMBOLO_NO_TERMINAL_InstruccionImprime      10
#define SIMBOLO_NO_TERMINAL_Expresion               11
#define SIMBOLO_NO_TERMINAL_Expresion2              12
#define SIMBOLO_NO_TERMINAL_ExpRelacional           13
#define SIMBOLO_NO_TERMINAL_ExpRelacional2          14
#define SIMBOLO_NO_TERMINAL_ExpCompuesta            15
#define SIMBOLO_NO_TERMINAL_ExpCompuesta2           16
#define SIMBOLO_NO_TERMINAL_ExpSimple               17
#define SIMBOLO_NO_TERMINAL_ExpSimple2              18
#define SIMBOLO_NO_TERMINAL_Factor                  19
#define SIMBOLO_NO_TERMINAL_Factor2                 20
#define SIMBOLO_NO_TERMINAL_Termino                 21
#define SIMBOLO_NO_TERMINAL_OpAditivo               22
#define SIMBOLO_NO_TERMINAL_OpMultiplicativo        23
#define SIMBOLO_NO_TERMINAL_OpRelacional            24
#define SIMBOLO_NO_TERMINAL_OpLogico                25
#define SIMBOLO_NO_TERMINAL_OpPon                   26
#define SIMBOLO_NO_TERMINAL_Numero                  27

#define SIMBOLO_NO_TERMINAL_InstruccionIDs          31
#define SIMBOLO_NO_TERMINAL_InstruccionIDs2         32



t_token *ptrTokenList;
t_token *ptrCurrentToken;

struct t_stack{
    int intSimboloTipo; 
    int intSimboloCodigo; 

    struct t_stack *ptrSig; }; typedef struct t_stack t_stack;

t_stack *ptrStackTop = NULL;

void pushNT(int intSimboloNTCodigo);
void pushT(int intSimboloTCodigo);
void pop();
void push(int intSimboloTipo, int intSimboloCodigo);

#define SIMBOLO_NO_TERMINALES_MAXNUM 32 //7
#define SIMBOLO_TERMINALES_MAXNUM 36  //12

int MR[SIMBOLO_NO_TERMINALES_MAXNUM][SIMBOLO_TERMINALES_MAXNUM]={
{-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1},
{-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{3,-1,3,-1,-1,-1,3,-1,-1,-1,3,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,5,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{6,-1,10,5,-1,-1,7,-1,-1,-1,8,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,-1},
{11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,14,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{17,-1,-1,-1,17,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,17,17,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,19,-1,19,-1,19,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,19,-1,-1},
{20,-1,-1,-1,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,22,-1,22,-1,22,-1,-1,-1,-1,-1,21,21,21,21,21,21,22,22,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,-1,-1},
{23,-1,-1,-1,23,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,25,-1,25,-1,25,-1,-1,24,24,-1,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,-1,-1},
{26,-1,-1,-1,26,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,28,-1,28,-1,28,-1,-1,28,28,27,28,28,28,28,28,28,28,28,-1,-1,-1,-1,-1,-1,-1,27,-1,28,28,-1,-1},
{29,-1,-1,-1,29,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,29,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,31,-1,31,-1,31,-1,-1,31,31,31,31,31,31,31,31,31,31,31,-1,-1,-1,-1,-1,-1,-1,31,-1,31,31,-1,30},
{33,-1,-1,-1,34,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,32,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,36,37,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,38,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,39,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,40,42,41,43,44,45,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,46,47,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,52,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,53,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,54,-1,-1},
{55,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,57,57,56,-1},
};

void SustituyeNTenStackPorParteDerehcaDeLaRegla(int intNumReglaObtenidaDeMR){
    pop();
    
    switch (intNumReglaObtenidaDeMR)
    {
case 1: //Regla 1) S → programa InstruccionCompuesta
        pushNT(SIMBOLO_NO_TERMINAL_InstruccionCompuesta);
        pushT(SIMBOLO_TERMINAL_programa);
         break;
        case 2: // Regla 2) InstruccionCompuesta → { BloqueInstrucciones }
            pushT(SIMBOLO_TERMINAL_LLAVE_C);
            pushNT(SIMBOLO_NO_TERMINAL_BloqueInstruccion);
            pushT(SIMBOLO_TERMINAL_LLAVE_A);
         break;
        case 3: //Regla 3) BloqueInstruccion -> Instrucción BloqueInstruccion2
            pushNT(SIMBOLO_NO_TERMINAL_BloqueInstruccion2);
            pushNT(SIMBOLO_NO_TERMINAL_Instruccion);
         break;
        case 4: //Regla 4) BloqueInstruccion2 -> ; Instrucción BloqueInstruccion2
              pushNT(SIMBOLO_NO_TERMINAL_BloqueInstruccion2);
              pushNT(SIMBOLO_NO_TERMINAL_Instruccion);
              pushT(SIMBOLO_TERMINAL_PuntoYComa);
         break;
        case 5: //Regla 5)

         break;
        case 6: //Regla 6) Instrucion -> InstruccionAsignacion
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionAsigancion);
         break;
        case 7: //Regla 7) Instrucion -> InstrucciónIf
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionIf);
         break;
        case 8: //Regla 8) Instrucion -> InstruccionWhile
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionWhile);
         break;
        case 9: //Regla 9) Instrucion -> InstruccionImprime
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionImprime);
         break;
        case 10: // REGLA 10) Instrucion -> InstruccionCompuesta
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionCompuesta);
         break;
        case 11: //Regla 11) InstruccionAsigancion -> ID = Expresion
            pushNT(SIMBOLO_NO_TERMINAL_Expresion);
            pushT(SIMBOLO_TERMINAL_IGUAL);
            pushT(SIMBOLO_TERMINAL_ID);
         break;
        case 12: //InstruccionIf -> if (  Expresion ) Instruccion InstrucciónIf2
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionIf2);
            pushNT(SIMBOLO_NO_TERMINAL_Instruccion);
            pushT(SIMBOLO_TERMINAL_PARENTESIS_C);
            pushNT(SIMBOLO_NO_TERMINAL_Expresion);
            pushT(SIMBOLO_TERMINAL_PARENTESIS_A);
            pushT(SIMBOLO_TERMINAL_if);
         break;
        case 13: //InstruccionIf2 -> else Instrucción
            pushNT(SIMBOLO_NO_TERMINAL_Instruccion);
            pushT(SIMBOLO_TERMINAL_else);
         break;
          case 14: //REGLA 14) InstruccionIf2 -> epsilon

         break;
        case 15: //InstruccionWhile -> while { Expresion } Instrucción
            pushNT(SIMBOLO_NO_TERMINAL_Instruccion);
            pushT(SIMBOLO_TERMINAL_LLAVE_C);
            pushNT(SIMBOLO_NO_TERMINAL_Expresion);
            pushT(SIMBOLO_TERMINAL_LLAVE_A);
            pushT(SIMBOLO_TERMINAL_while);
         break;
        case 16: //InstrucciónImprime -> ? Expresion
            pushNT(SIMBOLO_NO_TERMINAL_Expresion);
            pushT(SIMBOLO_TERMINAL_INTERROGACION);
         break;
        case 17: //Expresion -> ExpRelacional Expresion2
            pushNT(SIMBOLO_NO_TERMINAL_Expresion2);
            pushNT(SIMBOLO_NO_TERMINAL_ExpRelacional);
         break;
        case 18: //Expresion2 -> OpLogico ExpRelacional
            pushNT(SIMBOLO_NO_TERMINAL_ExpRelacional);
            pushNT(SIMBOLO_NO_TERMINAL_OpLogico);
         break;
        case 19: //Expresion2 -> épsilon

         break;
        case 20: //ExpRelacional -> ExpCompuesta ExpRelacional2
            pushNT(SIMBOLO_NO_TERMINAL_ExpRelacional2);
            pushNT(SIMBOLO_NO_TERMINAL_ExpCompuesta);
         break;
        case 21: //ExpRelacional2 -> OpRelacional ExpCompuesta
            pushNT(SIMBOLO_NO_TERMINAL_ExpCompuesta);
            pushNT(SIMBOLO_NO_TERMINAL_OpRelacional);
         break;
        case 22: //ExpRelacional2 -> épsilon

         break;
        case 23: //ExpCompuesta -> ExpSimple ExpCompuesta2
            pushNT(SIMBOLO_NO_TERMINAL_ExpCompuesta2);
            pushNT(SIMBOLO_NO_TERMINAL_ExpSimple);
         break;
        case 24: //ExpCompuesta2 -> OpAditivo ExpSimple
            pushNT(SIMBOLO_NO_TERMINAL_ExpSimple);
            pushNT(SIMBOLO_NO_TERMINAL_OpAditivo);
         break;
        case 25: //ExpCompuesta2 -> épsilon

         break;
        case 26: //ExpSimple -> Factor ExpSimple2
            pushNT(SIMBOLO_NO_TERMINAL_ExpSimple2);
            pushNT(SIMBOLO_NO_TERMINAL_Factor);
         break;
        case 27: //ExpSimple2 -> OpMultiplicativo Factor
            pushNT(SIMBOLO_NO_TERMINAL_Factor);
            pushNT(SIMBOLO_NO_TERMINAL_OpMultiplicativo);
         break;
        case 28: //ExpSimple2 -> epsilon
         break;
        case 29: //Factor -> Termino Factor2
            pushNT(SIMBOLO_NO_TERMINAL_Factor2);
            pushNT(SIMBOLO_NO_TERMINAL_Termino);
         break;
        case 30: //Factor2 -> OpPon termino
            pushNT(SIMBOLO_NO_TERMINAL_Termino);
            pushNT(SIMBOLO_NO_TERMINAL_OpPon);
         break;
        case 31: //Factor2 -> epsilon

         break;
        case 32: //Termino -> Numer
            pushNT(SIMBOLO_NO_TERMINAL_Numero);
         break;
        case 33: //Termino -> ID
            pushT(SIMBOLO_TERMINAL_ID);
         break;
        case 34: //Termino -> ( Expresion )
            pushT(SIMBOLO_TERMINAL_PARENTESIS_C);
            pushNT(SIMBOLO_NO_TERMINAL_Expresion);
            pushT(SIMBOLO_TERMINAL_PARENTESIS_A);
         break;
        case 35: //Termino -> !
            pushT(SIMBOLO_TERMINAL_NEGACION);
         break;
        case 36: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_MAS);
         break;
        case 37: //OpAditivo -> -
            pushT(SIMBOLO_TERMINAL_MENOS);
         break;
        case 38: //OpMultiplicativo -> *
            pushT(SIMBOLO_TERMINAL_POR);
         break;
        case 39: //OpMultiplicativo ->  /
            pushT(SIMBOLO_TERMINAL_DIVISION);
         break;
        case 40: //OpRelacional -> >
            pushT(SIMBOLO_TERMINAL_MAYORQUE);
         break;
        case 41: //OpRelacional -> <
            pushT(SIMBOLO_TERMINAL_MENORQUE);
         break;
        case 42: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_MAYOROIGUAL);
         break;
        case 43: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_MENOROIGUAL);
         break;
        case 44: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_IGUALDAD);
         break;
        case 45: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_DESIGUAL);
         break;
        case 46: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_AND);
         break;
        case 47: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_OR);
         break;
        case 48: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_POTENCIA);
         break;
        case 49: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_NUMERO_ENTERO);
         break;
        case 50: //OpAditivo -> +
            pushT(SIMBOLO_TERMINAL_NUMERO_REAL);
         break;

        break;
        case 54: //InstruccionWhere -> Where Expression ;
            pushNT(SIMBOLO_TERMINAL_PuntoYComa);
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionAsigancion);
            pushT(SIMBOLO_TERMINAL_WHERE);
        break;
        case 55: //Instruccion IDs -> ID InstruccionIDs2
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionIDs2);
            pushT(SIMBOLO_TERMINAL_ID);
        break;
        case 56: //Instruccion IDs2 -> , Instruccion ID
            pushNT(SIMBOLO_NO_TERMINAL_InstruccionIDs2);
            pushT(SIMBOLO_TERMINAL_ID);
            pushT(SIMBOLO_TERMINAL_COMA);
        break;
        case 57: //InstruccionIDs2 -> epsilon

        break;
        default:
            break;
    }
}
void imprime_regla(int intNumReglaObtenidaDeMR){
    switch (intNumReglaObtenidaDeMR)
    {
        case 1:  (void) printf (LOG_COLOR_BLUE "1. S → programa InstruccionCompuesta \n"); break;
        case 2:  (void) printf (LOG_COLOR_BLUE "2. InstruccionCompuesta → { BloqueInstruccion  }  \n"); break;
        case 3:  (void) printf (LOG_COLOR_BLUE "3. BloqueInstruccion → Instrucción BloqueInstruccion2  \n"); break;
        case 4:  (void) printf (LOG_COLOR_BLUE "4. BloqueInstruccion2 → ; Instrucción BloqueInstruccion2  \n");break;
        case 5:  (void) printf (LOG_COLOR_BLUE "5. BloqueInstruccion2 → epsilon \n"); break;
        case 6:  (void) printf (LOG_COLOR_BLUE "6. Instruccion → InstruccionAsignacion \n"); break;
        case 7:  (void) printf (LOG_COLOR_BLUE "7. Instruccion → InstrucciónIf \n"); break;
        case 8:  (void) printf (LOG_COLOR_BLUE "8. Instruccion → InstrucciónWhile \n"); break;
        case 9:  (void) printf (LOG_COLOR_BLUE "9. Instruccion → InstruccionImprime \n"); break;
        case 10: (void) printf (LOG_COLOR_BLUE "10. Instruccion → InstrucciónCompuesta \n"); break;
        case 11: (void) printf (LOG_COLOR_BLUE "11. InstruccionAsigancion → ID = Expresion \n");  break;
        case 12: (void) printf (LOG_COLOR_BLUE "12. InstruccionIf → if (  Expresion ) Instruccion InstrucciónIf2\n");  break;
        case 13: (void) printf (LOG_COLOR_BLUE "13. InstruccionIf2 → else Instrucción\n"); break;
        case 14: (void) printf (LOG_COLOR_BLUE "14. InstruccionIf2 → epsilon\n"); break;
        case 15: (void) printf (LOG_COLOR_BLUE "15. InstruccionWhile → while {Expresion} Instruccion\n"); break;
        case 16: (void) printf (LOG_COLOR_BLUE "16. InstrucciónImprime → ? Expresion\n");  break;
        case 17: (void) printf (LOG_COLOR_BLUE "17. Expresion → ExpRelacional Expresion2\n"); break;
        case 18: (void) printf (LOG_COLOR_BLUE "18. Expresion2 → OpLogico ExpRelacional  \n");  break;
        case 19: (void) printf (LOG_COLOR_BLUE "19. Expresion2 → epsilon  \n"); break;
        case 20: (void) printf (LOG_COLOR_BLUE "20. ExpRelacional → ExpCompuesta ExpRelacional2\n"); break;
        case 21: (void) printf (LOG_COLOR_BLUE "21. ExpRelacional2 → OpRelacional ExpCompuesta  \n"); break;
        case 22: (void) printf (LOG_COLOR_BLUE "22. ExpRelacional2 → épsilon\n");  break;
        case 23: (void) printf (LOG_COLOR_BLUE "23. ExpCompuesta → ExpSimple ExpCompuesta2\n");  break;
        case 24: (void) printf (LOG_COLOR_BLUE "24. ExpCompuesta2 → OpAditivo ExpSimple\n");  break;
        case 25: (void) printf (LOG_COLOR_BLUE "25. ExpCompuesta2 → épsilon\n"); break;
        case 26: (void) printf (LOG_COLOR_BLUE "26. ExpSimple → Factor ExpSimple2\n");  break;
        case 27: (void) printf (LOG_COLOR_BLUE "27. ExpSimple2 → OpMultiplicativo Factor \n"); break;
        case 28: (void) printf (LOG_COLOR_BLUE "28. ExpSimple2 → epsilon \n");  break;
        case 29: (void) printf (LOG_COLOR_BLUE "29. Factor → Termino Factor2 \n");  break;
        case 30: (void) printf (LOG_COLOR_BLUE "30. Factor2 → OpPon termino \n");  break;
        case 31: (void) printf (LOG_COLOR_BLUE "31. Factor2 → epsilon \n"); break;
        case 32: (void) printf (LOG_COLOR_BLUE "32. Termino → Numero \n");  break;
        case 33: (void) printf (LOG_COLOR_BLUE "33. Termino → ID \n");  break;
        case 34: (void) printf (LOG_COLOR_BLUE "34. Termino →  ( Expresion ) \n");  break;
        case 35: (void) printf (LOG_COLOR_BLUE "35. Termino → ! \n");  break;
        case 36: (void) printf (LOG_COLOR_BLUE "36. OpAditivo → + \n");  break;
        case 37: (void) printf (LOG_COLOR_BLUE "37. OpAditivo → - \n"); break;
        case 38: (void) printf (LOG_COLOR_BLUE "38. OpMultiplicativo → * \n");  break;
        case 39: (void) printf (LOG_COLOR_BLUE "39. OpMultiplicativo → / \n"); break;
        case 40: (void) printf (LOG_COLOR_BLUE "40. OpRelacional → >  \n"); break;
        case 41: (void) printf (LOG_COLOR_BLUE "41. OpRelacional → <  \n"); break;
        case 42: (void) printf (LOG_COLOR_BLUE "42. OpRelacional → >=  \n"); break;
        case 43: (void) printf (LOG_COLOR_BLUE "43. OpRelacional → <=  \n"); break;
        case 44: (void) printf (LOG_COLOR_BLUE "44. OpRelacional → ==  \n"); break;
        case 45: (void) printf (LOG_COLOR_BLUE "45. OpRelacional → !=  \n"); break;
        case 46: (void) printf (LOG_COLOR_BLUE "46. OpLogico → AND  \n"); break;
        case 47: (void) printf (LOG_COLOR_BLUE "47. OpLogico → OR \n"); break;
        case 48: (void) printf (LOG_COLOR_BLUE "48. OpPon → ^  \n");  break;
        case 49: (void) printf (LOG_COLOR_BLUE "49. Numero → NumeroEntero  \n"); break;
        case 50: (void) printf (LOG_COLOR_BLUE "50. Numero → NumeroReal  \n"); break;
        case 51: (void) printf (LOG_COLOR_BLUE "51. Instruccion → InstruccionSelect \n"); break;
        case 52: (void) printf (LOG_COLOR_BLUE "52. InstruccionSelect → Select InstruccionId InstruccionFrom \n"); break;
        case 53: (void) printf (LOG_COLOR_BLUE "53. InstruccionFrom → From ID InstruccionWhere \n"); break;
        case 54: (void) printf (LOG_COLOR_BLUE "54. InstruccionWhere → Where InstrAsignacion ; \n"); break;
        case 55: (void) printf (LOG_COLOR_BLUE "55. InstruccionId → ID InstruccionId2 \n"); break;
        case 56: (void) printf (LOG_COLOR_BLUE "56. InstruccionId2 → , ID InstruccionID2  \n"); break;
        case 57: (void) printf (LOG_COLOR_BLUE "57. InstruccionID2 → epsilon \n"); break;
        
        default: break ;    
    }
}

int ParserLL_AplicaRegla(){

    int intNumReglaObtenidaDeMR;
    
    intNumReglaObtenidaDeMR= MR[ptrStackTop->intSimboloCodigo - 1][ptrCurrentToken->intTokenCodigo - 1];
    // intNumReglaObtenidaDeMR= 1;
    // printf("//DEBUG: %d\n",intNumReglaObtenidaDeMR );
    // printf("//DEBUG: ptrStackTop->intSimboloTipo %d\n",ptrStackTop->intSimboloTipo );
    // printf("//DEBUG: ptrCurrentToken->intTokenCodigo %d\n",ptrCurrentToken->intTokenCodigo );

    if (intNumReglaObtenidaDeMR>0)
    {
        imprime_regla(intNumReglaObtenidaDeMR);
        SustituyeNTenStackPorParteDerehcaDeLaRegla(intNumReglaObtenidaDeMR);
    }
    else{
        // printf("//DEBUG: ParserLL_AplicaRegla(TRUE)\n");
        return TRUE;
    }
    return FALSE;
}

int stack_top_es_NT(){
    int intRes=FALSE;
    if(ptrStackTop!=NULL){
        if(ptrStackTop->intSimboloTipo== TIPO_SIMBOLO_NO_TERMINAL)  intRes= TRUE;
    }
    return intRes;
}

void imprimeT(int intSimboloCodigo){
    switch (intSimboloCodigo)
    {
        case SIMBOLO_TERMINAL_ID             : printf("SIMBOLO_TERMINAL_ID              \n"); break;
        case SIMBOLO_TERMINAL_programa       : printf("SIMBOLO_TERMINAL_programa        \n"); break;
        case SIMBOLO_TERMINAL_LLAVE_A        : printf("SIMBOLO_TERMINAL_LLAVE_A         \n"); break;
        case SIMBOLO_TERMINAL_LLAVE_C        : printf("SIMBOLO_TERMINAL_LLAVE_C         \n"); break;
        case SIMBOLO_TERMINAL_PARENTESIS_A   : printf("SIMBOLO_TERMINAL_PARENTESIS_A    \n"); break;
        case SIMBOLO_TERMINAL_PARENTESIS_C   : printf("SIMBOLO_TERMINAL_PARENTESIS_C    \n"); break;
        case SIMBOLO_TERMINAL_if             : printf("SIMBOLO_TERMINAL_if              \n"); break;
        case SIMBOLO_TERMINAL_PuntoYComa     : printf("SIMBOLO_TERMINAL_PuntoYComa      \n"); break;
        case SIMBOLO_TERMINAL_IGUAL          : printf("SIMBOLO_TERMINAL_IGUAL           \n"); break;
        case SIMBOLO_TERMINAL_else           : printf("SIMBOLO_TERMINAL_else            \n"); break;
        case SIMBOLO_TERMINAL_while          : printf("SIMBOLO_TERMINAL_while           \n"); break;
        case SIMBOLO_TERMINAL_INTERROGACION  : printf("SIMBOLO_TERMINAL_INTERROGACION   \n"); break;
        case SIMBOLO_TERMINAL_MAS            : printf("SIMBOLO_TERMINAL_MAS             \n"); break;
        case SIMBOLO_TERMINAL_MENOS          : printf("SIMBOLO_TERMINAL_MENOS           \n"); break;
        case SIMBOLO_TERMINAL_POR            : printf("SIMBOLO_TERMINAL_POR             \n"); break;
        case SIMBOLO_TERMINAL_MAYORQUE       : printf("SIMBOLO_TERMINAL_MAYORQUE        \n"); break;
        case SIMBOLO_TERMINAL_MAYOROIGUAL    : printf("SIMBOLO_TERMINAL_MAYOROIGUAL     \n"); break;
        case SIMBOLO_TERMINAL_MENORQUE       : printf("SIMBOLO_TERMINAL_MENORQUE        \n"); break;
        case SIMBOLO_TERMINAL_MENOROIGUAL    : printf("SIMBOLO_TERMINAL_MENOROIGUAL     \n"); break;
        case SIMBOLO_TERMINAL_IGUALDAD       : printf("SIMBOLO_TERMINAL_IGUALDAD        \n"); break;
        case SIMBOLO_TERMINAL_DESIGUAL       : printf("SIMBOLO_TERMINAL_DESIGUAL        \n"); break;
        case SIMBOLO_TERMINAL_AND            : printf("SIMBOLO_TERMINAL_AND             \n"); break;
        case SIMBOLO_TERMINAL_OR             : printf("SIMBOLO_TERMINAL_OR              \n"); break;
        case SIMBOLO_TERMINAL_NUMERO_ENTERO  : printf("SIMBOLO_TERMINAL_NUMERO_ENTERO   \n"); break;
        case SIMBOLO_TERMINAL_NUMERO_REAL    : printf("SIMBOLO_TERMINAL_NUMERO_REAL     \n"); break;
        case SIMBOLO_TERMINAL_Espacio        : printf("SIMBOLO_TERMINAL_Espacio         \n"); break;
        case SIMBOLO_TERMINAL_Tabulador      : printf("SIMBOLO_TERMINAL_Tabulador       \n"); break;
        case SIMBOLO_TERMINAL_SaltoDeLinea   : printf("SIMBOLO_TERMINAL_SaltoDeLinea    \n"); break;
        case SIMBOLO_TERMINAL_FinalDeArchivo : printf("SIMBOLO_TERMINAL_FinalDeArchivo  \n"); break;
        case SIMBOLO_TERMINAL_NEGACION       : printf("SIMBOLO_TERMINAL_NEGACION        \n"); break;
        case SIMBOLO_TERMINAL_DIVISION       : printf("SIMBOLO_TERMINAL_DIVISION        \n"); break;
        case SIMBOLO_TERMINAL_SELECT         : printf("SIMBOLO_TERMINAL_SELECT          \n"); break;
        case SIMBOLO_TERMINAL_FROM           : printf("SIMBOLO_TERMINAL_FROM            \n"); break;
        case SIMBOLO_TERMINAL_WHERE          : printf("SIMBOLO_TERMINAL_WHERE           \n"); break;
        case SIMBOLO_TERMINAL_COMA           : printf("SIMBOLO_TERMINAL_COMA            \n"); break;
        case SIMBOLO_TERMINAL_POTENCIA       : printf("SIMBOLO_TERMINAL_POTENCIA        \n"); break;
        default: printf("ERROR"); break;
    }
}

void imprimeNT(int intSimboloCodigo){
    switch (intSimboloCodigo)
    {
        case SIMBOLO_NO_TERMINAL_S                       : printf("SIMBOLO_NO_TERMINAL_S                     \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionCompuesta    : printf("SIMBOLO_NO_TERMINAL_InstruccionCompuesta  \n"); break;
        case SIMBOLO_NO_TERMINAL_BloqueInstruccion       : printf("SIMBOLO_NO_TERMINAL_BloqueInstruccion     \n"); break;
        case SIMBOLO_NO_TERMINAL_BloqueInstruccion2      : printf("SIMBOLO_NO_TERMINAL_BloqueInstruccion2    \n"); break;
        case SIMBOLO_NO_TERMINAL_Instruccion             : printf("SIMBOLO_NO_TERMINAL_Instruccion           \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionAsigancion   : printf("SIMBOLO_NO_TERMINAL_InstruccionAsigancion \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionIf           : printf("SIMBOLO_NO_TERMINAL_InstruccionIf         \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionIf2          : printf("SIMBOLO_NO_TERMINAL_InstruccionIf2        \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionWhile        : printf("SIMBOLO_NO_TERMINAL_InstruccionWhile      \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionImprime      : printf("SIMBOLO_NO_TERMINAL_InstruccionImprime    \n"); break;
        case SIMBOLO_NO_TERMINAL_Expresion               : printf("SIMBOLO_NO_TERMINAL_Expresion             \n"); break;
        case SIMBOLO_NO_TERMINAL_Expresion2              : printf("SIMBOLO_NO_TERMINAL_Expresion2            \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpRelacional           : printf("SIMBOLO_NO_TERMINAL_ExpRelacional         \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpRelacional2          : printf("SIMBOLO_NO_TERMINAL_ExpRelacional2        \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpCompuesta            : printf("SIMBOLO_NO_TERMINAL_ExpCompuesta          \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpCompuesta2           : printf("SIMBOLO_NO_TERMINAL_ExpCompuesta2         \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpSimple               : printf("SIMBOLO_NO_TERMINAL_ExpSimple             \n"); break;
        case SIMBOLO_NO_TERMINAL_ExpSimple2              : printf("SIMBOLO_NO_TERMINAL_ExpSimple2            \n"); break;
        case SIMBOLO_NO_TERMINAL_Factor                  : printf("SIMBOLO_NO_TERMINAL_Factor                \n"); break;
        case SIMBOLO_NO_TERMINAL_Factor2                 : printf("SIMBOLO_NO_TERMINAL_Factor2               \n"); break;
        case SIMBOLO_NO_TERMINAL_Termino                 : printf("SIMBOLO_NO_TERMINAL_Termino               \n"); break;
        case SIMBOLO_NO_TERMINAL_OpAditivo               : printf("SIMBOLO_NO_TERMINAL_OpAditivo             \n"); break;
        case SIMBOLO_NO_TERMINAL_OpMultiplicativo        : printf("SIMBOLO_NO_TERMINAL_OpMultiplicativo      \n"); break;
        case SIMBOLO_NO_TERMINAL_OpRelacional            : printf("SIMBOLO_NO_TERMINAL_OpRelacional          \n"); break;
        case SIMBOLO_NO_TERMINAL_OpLogico                : printf("SIMBOLO_NO_TERMINAL_OpLogico              \n"); break;
        case SIMBOLO_NO_TERMINAL_OpPon                   : printf("SIMBOLO_NO_TERMINAL_OpPon                 \n"); break;
        case SIMBOLO_NO_TERMINAL_Numero                  : printf("SIMBOLO_NO_TERMINAL_Numero                \n"); break;
       
        case SIMBOLO_NO_TERMINAL_InstruccionIDs          : printf("SIMBOLO_NO_TERMINAL_InstruccionIDs        \n"); break;
        case SIMBOLO_NO_TERMINAL_InstruccionIDs2         : printf("SIMBOLO_NO_TERMINAL_InstruccionIDs2       \n"); break;
        default: printf("Error"); break;
    }
}

void pushNT(int intSimboloNTCodigo){
    push(TIPO_SIMBOLO_NO_TERMINAL, intSimboloNTCodigo );
}

void pushT(int intSimboloTCodigo){
     push(TIPO_SIMBOLO_TERMINAL, intSimboloTCodigo);
}

void pop(){
    t_stack *aux;

    if(ptrStackTop != NULL)
    {
        aux = ptrStackTop;
        ptrStackTop = ptrStackTop->ptrSig;
        free(aux);
    }
}

void vaciar_stack(){
    while (ptrStackTop)
    {
        pop();
    }
    
}

void push(int intSimboloTipo, int intSimboloCodigo){
    t_stack *nuevo = (t_stack *) malloc(sizeof(t_stack));
    nuevo->intSimboloTipo = intSimboloTipo;
    nuevo->intSimboloCodigo = intSimboloCodigo;
    nuevo->ptrSig = NULL;

    if (ptrStackTop != NULL) //Hay elementos en el stack
    {
        nuevo -> ptrSig = ptrStackTop;
        ptrStackTop = nuevo;
    } else {
        
        ptrStackTop = nuevo;
    }
}

void stack_imprime_internal(t_stack *nodoStack){
    if (nodoStack)
    {
        stack_imprime_internal(nodoStack->ptrSig);
        switch (nodoStack->intSimboloTipo)
        {
            case TIPO_SIMBOLO_NO_TERMINAL:
                imprimeNT(nodoStack->intSimboloCodigo);
                break;
            case TIPO_SIMBOLO_TERMINAL:
                imprimeT(nodoStack->intSimboloCodigo);
                break;
            default:
                printf("Error");
                break;
        }
    }
    
}

void stack_imprime(){
    (void) printf (LOG_COLOR_GREEN "Stack: \n" LOG_COLOR_RESET);
    stack_imprime_internal(ptrStackTop);
    printf("\n");
}

void entrada_imprime(){
    t_token *aux = ptrCurrentToken;

    (void) printf (LOG_COLOR_GREEN "Entrada: \n" LOG_COLOR_RESET);
    while (aux) 
    {
        imprimeT(aux->intTokenCodigo);
        // printf(" ");
        aux = aux->ptrSig;
    }
    // printf("|");
    
}

void printError (void) {

    (void) printf (
        "\033[1;31m \t\tError Sintactico=%s, Renglon=%d, Columna=%d\n",
        ptrCurrentToken->strTokenTextoFuente, 
        ptrCurrentToken->intRenglon, 
        ptrCurrentToken->intColumna
    );

}

void parser_LL(){

    int intBanderaErrorSintactico = FALSE;
    int IntBanderaEntradaReconocida = FALSE;

    ptrCurrentToken = ptrTokenList;
    pushT(SIMBOLO_TERMINAL_FinalDeArchivo);
    pushNT(SIMBOLO_NO_TERMINAL_S);

    do
    {
        stack_imprime();
        entrada_imprime();
        if (stack_top_es_NT())
        {
            intBanderaErrorSintactico=ParserLL_AplicaRegla();
            if (intBanderaErrorSintactico) printError();
            
            
        }
        
        else{
            // printf("//DEBUG: Es Terminal\n");
            if((ptrStackTop) && (ptrCurrentToken))
            {   
                // printf("//DEBUG//: (ptrStackTop) && (ptrCurrentToken)");
                if(ptrStackTop->intSimboloCodigo == ptrCurrentToken->intTokenCodigo)
                {
                    if(ptrStackTop->intSimboloCodigo == SIMBOLO_TERMINAL_FinalDeArchivo)
                    {
                        IntBanderaEntradaReconocida = TRUE;
                        printf("\nEntrada Reconocida. Analisis Sintactico Correcto\n");
                    }
                    else
                    {
                        // printf("\nExpect \n");
                        pop();
                        ptrCurrentToken = ptrCurrentToken->ptrSig;
                    }
                }
                else
                {
                    IntBanderaEntradaReconocida = TRUE;
                    printError();
                }
            }else
            {
                // printf("//DEBUG: intBanderaErrorSintactico=TRUE\n");
                intBanderaErrorSintactico=TRUE;
                if (!ptrStackTop)
                {
                    printf("Pila Vacia\n");
                }else if(!ptrCurrentToken)
                {
                    printf("Ya no hay elementos\n");
                }
                
                
            }
            
            
        }
        
    } while ((!intBanderaErrorSintactico) && (!IntBanderaEntradaReconocida));
    
}
