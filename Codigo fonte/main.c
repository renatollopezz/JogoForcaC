#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include "rotinas.c"

int main(){
int operacao;
char palavras[1][3][54];
int novaPartida;

do{
operacao = selecionarOp();
listarPalavras(operacao,palavras);
novaPartida = montarQuadroPalavras(palavras,operacao);
}while(novaPartida == 1);
system("cls");
printf("Obrigado por jogar!");
return 0;
}
