//os arquivos .h s�o para criar as defini��es e as prototipagens de fun��es
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#define TAM_user 13

typedef struct login_pessoa{
    char usuario[TAM_user],
         senha[TAM_user];
}Login_Pessoa;

#endif // STRUCTS_H_INCLUDED
