#include "cadastros.h"
#include "structs.h"
#include "estilos.h"
#include "funcoes.h"

void TelaCadastro(){

    system("title Cadastros");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int escolha;

    do{
        printf("\n\n\n\n\n\n\n"
               "\n                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                 MENU                ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [0] - Voltar                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [1] - Novo Cadastro              ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [2] - Listar Cadastros           ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [3] - Buscar e Editar Cadastro   ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "    [4] - Sair                       ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           "                                     ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(                                                                                 "                                       \n"
                 "                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
        printf(                                           "  Escolha uma op��o para continuar: ");

        scanf("%i", &escolha);
        fflush(stdin);
        SetConsoleTextAttribute(hConsole, saved_attributes);

        switch(escolha){
        case 1:
            telaLimpa();
            NovoCadastro();
            break;
        case 2:
            telaLimpa();
            ListarCadastros();
            break;
        case 3:
            telaLimpa();
            EditarCadastro();
            break;
        case 4:
            telaLimpa();
            DadosUsuario();
            break;
        case 0:
            telaLimpa();
            break;
        default :
            printf(RED "\n\n\t\t\t\t\t\t [!] Op��o Inv�lida!"); bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
        }
        telaLimpa();
    }while(escolha != 0);
    telaLimpa();
}

void NovoCadastro(){

    system("title Novo Cadastro");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo;

    //Verifica se o arquivo existe.
    arquivo = fopen("cadastros.bin", "rb");
    if(arquivo == NULL){
        //Se o arquivo n�o existe, cria um novo e adiciona o cadastro do Administrador.
        arquivo = fopen("cadastros.bin", "wb");
        if(arquivo == NULL){
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!"); bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return;
        }
        //Cria cadastro do Administrador.
        pessoa.ID = 0;
        strcpy(pessoa.nome, "Administrador\0");
        strcpy(pessoa.login.usuario, "admin\0");
        strcpy(pessoa.login.senha, "admin123\0");
        strcpy(pessoa.cargo, "ADMINISTRADOR\0");

        //Escreve cadastro Administrador no arquivo.
        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);

        fclose(arquivo);
    }else{
        fclose(arquivo);
    }

    printf("\n ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                       CADASTRO                                                       \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
    printf(  "                                                                                                                      \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf(  "                                                                                                                      \n"
             "                                             ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
    printf(  " ID: ");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    // Gera um novo ID incremental.
    pessoa.ID = gerarID();
    //Mostra ID atual.
    printf(" %i", pessoa.ID);

    printf("\n\n");
    printf(" ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
    printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    //Campo de inser��o - Nome:
    while(1){
        printf("\n                                           ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                              " Nome: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
        pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nome) == 0){
            bold(1);
            printf(RED "\n\n                                       [!] O campo nome n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de Inser��o - Usu�rio:
    while(1){
        printf("\n                                        ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                           " Usu�rio: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");
        fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
        pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        while(usuarioExiste(pessoa.login.usuario)){
            bold(1);
            printf(RED "\n\n                                 [!] O Usu�rio j� existe, por favor escolha outro!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);

        }

        if(strlen(pessoa.login.usuario) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo usu�rio n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de insers�o - Senha:
    char senha1[TAM_user], senha2[TAM_user];
    while(1){
        printf("\n                                          ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                             " Senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(senha1, sizeof(senha1), stdin);
        senha1[strcspn(senha1, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(senha1) == 0){
            bold(1);
            printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usu�rio: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de insers�o - Confirma��o de Senha:
    while(1){
        printf("\n                             ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
        printf(                                " Confirme sua senha: ");
        SetConsoleTextAttribute(hConsole, saved_attributes);
        printf(" ");

        fgets(senha2, sizeof(senha2), stdin);
        senha2[strcspn(senha2, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(senha2) == 0){
            bold(1);
            printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();

            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usu�rio: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);
            printf("\n                                          ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                             " Senha: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", senha1);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    int comparador;
    //Verifica se senhas s�o iguais:
    verificaSenhas(senha1, senha2, &comparador);
    if(comparador == 1){
        comparador = 0;
        bold(1);
        printf(RED "\n\n                                             [!] Senhas n�o coincidem!\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);
        telaLimpa();
        do{
            printf("\n ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                       CADASTRO                                                       \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(" ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
            printf(  "                                                                                                                      \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(  "                                                                                                                      \n"
                     "                                             ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                                " ID: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %i\n\n ", pessoa.ID);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
            printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf("\n                                           ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                              " Nome: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.nome);
            printf("\n                                        ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
            printf(                                           " Usu�rio: ");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            printf(                                                      " %s\n", pessoa.login.usuario);

            //Campo de insers�o - Senha:
            while(1){
                printf("\n                                          ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                             " Senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(senha1, sizeof(senha1), stdin);
                senha1[strcspn(senha1, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(senha1) == 0){
                    bold(1);
                    printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(  "                                                                                                                      \n"
                             "                                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                                " ID: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %i\n\n ", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usu�rio: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);

                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }
            //Campo de insers�o - Confirma��o de Senha:
            while(1){
                printf("\n                             ");
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                printf(                                " Confirme sua senha: ");
                SetConsoleTextAttribute(hConsole, saved_attributes);
                printf(" ");

                fgets(senha2, sizeof(senha2), stdin);
                senha2[strcspn(senha2, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(senha2) == 0){
                    bold(1);
                    printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();

                    printf("\n ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                       CADASTRO                                                       \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(" ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                    printf(  "                                                                                                                      \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(  "                                                                                                                      \n"
                             "                                             ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                                " ID: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %i\n\n ", pessoa.ID);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN);
                    printf(  "                                                   DADOS DO USU�RIO:                                                  \n");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf("\n                                           ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                              " Nome: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.nome);
                    printf("\n                                        ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                           " Usu�rio: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", pessoa.login.usuario);
                    printf("\n                                          ");
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_GREEN | FOREGROUND_INTENSITY| FOREGROUND_RED | BACKGROUND_INTENSITY);
                    printf(                                             " Senha: ");
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    printf(                                                      " %s\n", senha1);
                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }
            //Verifica se senhas s�o iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                telaLimpa();
            }
        }while(comparador == 1);
    }else{
        senha2[strcspn(senha2, "\n")] = 0;
        strcpy(pessoa.login.senha, senha2);
    }
    //Campo de Inser��o - E-mail:
    while(1){
        printf("\n                                         e-mail: ");
        fgets(pessoa.email, sizeof(pessoa.email), stdin);
        pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.email) == 0){
            bold(1);
            printf(RED "\n\n\t\t\t [!] O campo e-mail n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                       "                                                                                                                        \n"
                       "                                            ID: %i", pessoa.ID);
            printf("\n\n                                                  DADOS DO USU�RIO:"
                     "\n                                          Nome: %s", pessoa.nome);
            printf(  "\n                                       Usu�rio: %s", pessoa.login.usuario);
            printf(  "\n                                         Senha: %s", senha1);
            printf(  "\n                            Confirme sua senha: %s", senha2);

        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    telaLimpa();
    //Campo de sele��o - Cargo:
    int escolhaCargo;
    printf(  "\n                                          #===============================#                                             \n"
               "                                          |           CADASTRO            |                                             \n"
               "                                          #===============================#                                             \n"
           "\n\n                                                       CARGO:"
             "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA");
    while(1){
        printf("\n                               Digite o n�mero correspondente ao cargo escolhido: ");
        scanf("%i", &escolhaCargo);
        fflush(stdin);

        switch(escolhaCargo){
        case 1:
            strcpy(pessoa.cargo, "GERENTE\0");
            break;
        case 2:
            strcpy(pessoa.cargo, "OPERADOR DE CAIXA\0");
            break;
        case 3:
            strcpy(pessoa.cargo, "ESTOQUISTA\0");
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t [!] Op��o inv�lida! Tente novamente.\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                       CARGO:"
                     "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA");
        }

        if(escolhaCargo >= 1 && escolhaCargo <= 4){
            printf("\n                                         Cargo: %s", pessoa.cargo);
            break; //Sai do loop se a op��o for v�lida
        }
    }
    telaLimpa();
    //Campo de inser��o - Data de nascimento:
    printf(  "\n                                          #===============================#                                             \n"
               "                                          |           CADASTRO            |                                             \n"
               "                                          #===============================#                                             \n"
           "\n\n                                                     DOCUMENTOS:");
    while(1){
        printf("\n                Data de Nascimento(00/00/0000): ");
        fgets(pessoa.nasc, sizeof(pessoa.nasc), stdin);
        pessoa.nasc[strcspn(pessoa.nasc, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.nasc) == 0){
            bold(1);
            printf(RED "\n\n                                 [!] O campo Data de Nascimento n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                     DOCUMENTOS:");
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - CPF:
    while(1){
        printf("\n                           CPF(000.000.000/00): ");
        fgets(pessoa.documentos.cpf, sizeof(pessoa.documentos.cpf), stdin);
        pessoa.documentos.cpf[strcspn(pessoa.documentos.cpf, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.cpf) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CPF n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                     DOCUMENTOS:"
                     "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - RG:
    while(1){
        printf("\n                               RG(00.000.000-0: ");
        fgets(pessoa.documentos.rg, sizeof(pessoa.documentos.rg), stdin);
        pessoa.documentos.rg[strcspn(pessoa.documentos.rg, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.documentos.rg) == 0){
            bold(1);
            printf(RED "\n\n                                         [!] O campo RG n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                     DOCUMENTOS:"
                     "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc);
            printf(  "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - Rua:
    printf(  "\n                                          #===============================#                                             \n"
               "                                          |           CADASTRO            |                                             \n"
               "                                          #===============================#                                             \n"
           "\n\n                                                      ENDERE�O:");
    while(1){
        printf("\n                                           Rua: ");
        fgets(pessoa.endereco.rua, sizeof(pessoa.endereco.rua), stdin);
        pessoa.endereco.rua[strcspn(pessoa.endereco.rua, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.rua) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo Rua n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                      ENDERE�O:");
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - N�mero:
    int numero;
    while(1){
        printf("\n                                        N�mero: ");
        scanf("%i", &numero);
        fflush(stdin);

        pessoa.endereco.num_resid = numero;

        if(strlen(pessoa.endereco.num_resid) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo N�mero n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                      ENDERE�O:"
                     "\n                                           Rua: %s", pessoa.endereco.rua);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - Bairro:
    while(1){
        printf("\n                                        Bairro: ");
        fgets(pessoa.endereco.bairro, sizeof(pessoa.endereco.bairro), stdin);
        pessoa.endereco.bairro[strcspn(pessoa.endereco.bairro, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.bairro) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Bairro n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                      ENDERE�O:"
                     "\n                                           Rua: %s", pessoa.endereco.rua);
            printf(  "\n                                        N�mero: %s", pessoa.endereco.num_resid);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - CEP:
    while(1){
        printf("\n                                CEP(00000-000): ");
        fgets(pessoa.endereco.cep, sizeof(pessoa.endereco.cep), stdin);
        pessoa.endereco.cep[strcspn(pessoa.endereco.cep, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.cep) == 0){
            bold(1);
            printf(RED "\n\n                                        [!] O campo CEP n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                      ENDERE�O:"
                     "\n                                           Rua: %s", pessoa.endereco.rua);
            printf(  "\n                                        N�mero: %s", pessoa.endereco.num_resid);
            printf(  "\n                                        Bairro: %s", pessoa.endereco.bairro);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - Complemento:
    while(1){
        printf("\n                                   Complemento: ");
        fgets(pessoa.endereco.complemento, sizeof(pessoa.endereco.complemento), stdin);
        pessoa.endereco.complemento[strcspn(pessoa.endereco.complemento, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.complemento) == 0){
            bold(1);
            printf(RED "\n\n                                [!] O campo Complemento n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf(  "\n                                          #===============================#                                             \n"
                       "                                          |           CADASTRO            |                                             \n"
                       "                                          #===============================#                                             \n"
                   "\n\n                                                      ENDERE�O:"
                     "\n                                           Rua: %s", pessoa.endereco.rua);
            printf(  "\n                                        N�mero: %s", pessoa.endereco.num_resid);
            printf(  "\n                                        Bairro: %s", pessoa.endereco.bairro);
            printf(  "\n                                CEP(00000-000): %s", pessoa.endereco.cep);
        }else{
            break; //Sai do loop se o nome for v�lido.
        }
    }

    int escolha;
    printf("\n\n                                          [1] SALVAR | [2] EDITAR | [3] CANCELAR"
           "\n                                                  Escolha uma op��o: ");
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha){
    case 1:
        //Abre arquivo para escrita bin�ria.
        arquivo = fopen("cadastros.bin", "wb");

        //Verifica se o arquivo foi encontrado.
        if(arquivo == NULL){
            bold(1);
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return;
        }

        //Escreve dados inseridos no arquivo.
        fwrite(&pessoa,sizeof(Pessoa), 1, arquivo);

        //Fecha arquivo.
        fclose(arquivo);

        //Salva o �ltimo ID.
        salvarUltimoID(pessoa.ID);

        //Mensagem de cadastro realizado.
        bold(1);
        printf(GREEN "\n\n                                            Cadastro realizado com sucesso!\a\a");
        bold(0);
        SetConsoleTextAttribute(hConsole, saved_attributes);
        Sleep(800);

        telaLimpa();
        TelaCadastro();

    case 2:
        telaLimpa();
        printf(  "\n                                          #===============================#                                             \n"
                   "                                          |           CADASTRO            |                                             \n"
                   "                                          #===============================#                                             \n"
                   "                                                                                                                        \n"
                   "                                            ID: %i", pessoa.ID);
        printf("\n\n                                                  DADOS DO USU�RIO:"
                 "\n                                          Nome: %s", pessoa.nome);
        printf(  "\n                                       Usu�rio: %s", pessoa.login.usuario);
        printf(  "\n                                         Senha: %s", senha1);
        printf(  "\n                            Confirme sua senha: %s", senha2);
        printf(  "\n                                        e-mail: %s", pessoa.email);
        printf("\n\n                                                       CARGO:"
                 "\n                                         Cargo: %s", pessoa.cargo);
        printf("\n\n                                                     DOCUMENTOS:"
                 "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc);
        printf(  "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf);
        printf(  "\n                               RG(00.000.000-0: %s", pessoa.documentos.rg);
        printf("\n\n                                                      ENDERE�O:"
                 "\n                                           Rua: %s", pessoa.endereco.rua);
        printf(  "\n                                        N�mero: %s", pessoa.endereco.num_resid);
        printf(  "\n                                        Bairro: %s", pessoa.endereco.bairro);
        printf(  "\n                                CEP(00000-000): %s", pessoa.endereco.cep);
        printf(  "\n                                   Complemento: %s", pessoa.endereco.complemento);
        printf("\n\n                                                    INFORMA��ES: \n"
               "\n\n                                                  DADOS DO USU�RIO:"
                 "\n                                     [1] Nome | [2] Usu�rio | [3] Senha | [4] e-mail"
               "\n\n                                                       CARGO:"
                 "\n                                                       [5] cargo"
               "\n\n                                                     DOCUMENTOS:"
                 "\n                                         [6] Data Nascimento | [7] CPF | [8] RG"
               "\n\n                                                      ENDERE�O:"
                 "\n                             [9] Rua | [10] N�mero | [11] Bairro | [12] CEP | [13] Complemento"
               "\n\n                                          Qual informa��o deseja editar: \n");
        int opcao;
        scanf("%i", opcao);
        fflush(stdin);

        telaLimpa();
        printf("\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |            EDITAR             |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                                                                                                        \n");

        switch(opcao){
        case 1:
            //Campo de inser��o - Nome:
            while(1){
                printf("\n                                          Nome: ");
                fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.nome) == 0){
                    bold(1);
                    printf(RED "\n\n                                       [!] O campo nome n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n\n\n\n\n\n\n"
                           "\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }

            //Mensagem de altera��o realizada.
            bold(1);
            printf(GREEN "\n\n                                          Altera��o realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 2:
            //Campo de Inser��o - Usu�rio:
            while(1){
                printf("\n                                       Usu�rio: ");
                fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
                pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                while(usuarioExiste(pessoa.login.usuario)){
                    printf("\n\n                              [!] O Usu�rio j� existe, por favor escolha outro!\a");
                    printf("\n                                       Usu�rio: ");
                    fgets(pessoa.login.usuario, sizeof(pessoa.login.usuario), stdin);
                    pessoa.login.usuario[strcspn(pessoa.login.usuario, "\n")] = 0; //Remove caractere de nova linha.
                    fflush(stdin);

                }

                if(strlen(pessoa.login.usuario) == 0){
                    bold(1);
                    printf(RED "\n\n                                     [!] O campo usu�rio n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n\n\n\n\n\n\n"
                           "\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }

            //Mensagem de altera��o realizada.
            bold(1);
            printf(GREEN "\n\n                                          Altera��o realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 3:
            //Campo de insers�o - Senha:
            while(1){
                printf("\n                                         Senha: ");

                fflush(stdin);

                if(strlen(senha1) == 0){
                    bold(1);
                    printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");

                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }
            //Campo de insers�o - Confirma��o de Senha:
            while(1){
                printf("\n                            Confirme sua senha: ");

                fflush(stdin);

                if(strlen(senha2) == 0){
                    bold(1);
                    printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n"
                           "\n                                         Senha: %s", senha1);
                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }
            int comparador;
            //Verifica se senhas s�o iguais:
            verificaSenhas(senha1, senha2, &comparador);
            if(comparador == 1){
                do{
                    bold(1);
                    printf(RED "\n\n                                             [!] Senhas n�o coincidem!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");
                    //Campo de insers�o - Senha:
                    while(1){
                        printf("\n                                         Senha: ");

                        fflush(stdin);

                        if(strlen(senha1) == 0){
                            bold(1);
                            printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            printf("\n                                          #===============================#                                             \n"
                                     "                                          |            EDITAR             |                                             \n"
                                     "                                          #===============================#                                             \n"
                                     "                                                                                                                        \n");

                        }else{
                            break; //Sai do loop se o nome for v�lido
                        }
                    }
                    //Campo de insers�o - Confirma��o de Senha:
                    while(1){
                        printf("\n                            Confirme sua senha: ");

                        fflush(stdin);

                        if(strlen(senha2) == 0){
                            bold(1);
                            printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
                            bold(0);
                            SetConsoleTextAttribute(hConsole, saved_attributes);
                            Sleep(800);
                            telaLimpa();
                            printf("\n                                          #===============================#                                             \n"
                                     "                                          |            EDITAR             |                                             \n"
                                     "                                          #===============================#                                             \n"
                                     "                                                                                                                        \n"
                                   "\n                                         Senha: %s", senha1);
                        }else{
                            break; //Sai do loop se o nome for v�lido
                        }
                    }
                }while(comparador == 1);
            }else{
                senha1[strcspn(senha1, "\n")] = 0;
                strcpy(pessoa.login.senha, senha1);
            }

            //Mensagem de altera��o realizada.
            bold(1);
            printf(GREEN "\n\n                                          Altera��o realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
            break;
        case 4:
            //Campo de Inser��o - E-mail:
            while(1){
                printf("\n                                         e-mail: ");
                fgets(pessoa.email, sizeof(pessoa.email), stdin);
                pessoa.email[strcspn(pessoa.email, "\n")] = 0; //Remove caractere de nova linha.
                fflush(stdin);

                if(strlen(pessoa.email) == 0){
                    bold(1);
                    printf(RED "\n\n\t\t\t [!] O campo e-mail n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |            EDITAR             |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n");

                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }

            //Mensagem de altera��o realizada.
            bold(1);
            printf(GREEN "\n\n                                          Altera��o realizada com sucesso!\a\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);

            telaLimpa();
        break;
        }
    case 3:
        telaLimpa();
        TelaCadastro();
        }
}

void ListarCadastros(){

}

void EditarCadastro(){

}

void DadosUsuario(){

}
