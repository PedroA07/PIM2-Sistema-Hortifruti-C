#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para trabalhar com cadeia de caracteres do tipo string.
#include <locale.h> //Permite que o c�digo entenda caracteres especiais.
#include <windows.h> //Uso de fun��es do sistema.
#include <conio.h> //Para personalizar as defini��es de cores.
#include <ctype.h> //Uso de fun��es para classificar e modificar caracteres.

//As fun��es principais que foram feitas, ficam no arquivo funcoes.c
#include "interface.c"
#include "funcoes.c"
#include "estilos.c"
#include "cadastros.c"

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "Portuguese"); /* Definindo configura��o padr�o do sistema */

    telaTamanho();
    telaEstilo();
    telaInicio();

    return 0;
}
