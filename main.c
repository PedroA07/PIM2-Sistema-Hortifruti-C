#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //Permite que o c�digo entenda caracteres especiais.
#include <windows.h>
#include <conio.h>
#include <ctype.h>

//as fun��es principais que foram feitas, ficam no arquivo funcoes.c
#include "interface.c"
#include "funcoes.c"
#include "estilos.c"

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "Portuguese"); /* Definindo configura��o padr�o do sistema */

    telaTamanho();
    telaEstilo();
    telaInicio();

    return 0;
}
