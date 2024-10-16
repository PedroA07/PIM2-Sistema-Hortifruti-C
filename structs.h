//os arquivos .h s�o para criar as defini��es e as prototipagens de fun��es
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//In�cio de dados para cadastro de funcion�rios;
#define TAM_user 13
#define TAM_nome 101
#define TAM_comp 11
#define TAM_cep 10
#define TAM_cpf 15
#define TAM_rg 13
#define TAM_cargo 11
#define TAM_nasc 11

typedef struct login_pessoa{
    char usuario[TAM_user],
         senha[TAM_user];
}Login;

typedef struct endereco_pessoa{
    char rua[TAM_nome],
         bairro[TAM_nome],
         cep[TAM_cep],
         complemento[TAM_comp];
    int num_resid;
}Endereco;

typedef struct documentos_pessoa{
    char cpf[TAM_cpf],
         rg[TAM_rg];
}Documentos;

typedef struct dados_pessoa{
    int ID;
    char nome[TAM_nome];
    Login login;
    char email[TAM_nome],
         cargo[TAM_cargo],
         nasc[TAM_nasc];
    Documentos documentos;
    Endereco endereco;
}Pessoa;

int ultimoID = 0; // Vari�vel para armazenar o �ltimo ID gerado
//Fim

#endif // STRUCTS_H_INCLUDED
