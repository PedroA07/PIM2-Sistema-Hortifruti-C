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

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED);
    animacao_de_carregamento();
    SetConsoleTextAttribute(hConsole, saved_attributes);

    int escolha;

    do{
        "\n\n\n\n\n\n\n"
               "\n                                          #===============================#                                             \n"
                 "                                          |           CADASTRO            |                                             \n"
                 "                                          #===============================#                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          |   [1] - Novo Cadastros        |                                             \n"
                 "                                          |   [2] - Listar Cadastros      |                                             \n"
                 "                                          |   [4] - Editar Cadastro       |                                             \n"
                 "                                          |   [4] - Meus Dados            |                                             \n"
                 "                                          |   [0] - Sair                  |                                             \n"
                 "                                          |                               |                                             \n"
                 "                                          #===============================#                                             \n"
               "\n                                         Escolha uma op��o para continuar: ");

        scanf("%i", &escolha);

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
        }
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
        strcpy(pessoa.nome, "Administrador");
        strcpy(pessoa.login.usuario, "admin");
        strcpy(pessoa.login.senha, "admin123");
        strcpy(pessoa.cargo, CARGO_1);

        //Escreve cadastro Administrador no arquivo.
        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);

        fclose(arquivo);
    }else{
        fclose(arquivo);
    }

    printf("\n                                          #===============================#                                             \n"
             "                                          |           CADASTRO            |                                             \n"
             "                                          #===============================#                                             \n"
             "                                                                                                                        \n"
             "                                                       ID: ");

    // Gera um novo ID incremental.
    pessoa.ID = gerarID();
    //Mostra ID atual.
    printf("%i", pessoa.ID);
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: ", pessoa.ID);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de insers�o - Senha:
    char ent_senha1, senha1[TAM_user],
         ent_senha2, senha2[TAM_user];
    while(1){
        printf("\n                                         Senha: ");
        mascSenha(ent_senha1, &senha1);
        fflush(stdin);

        if(strlen(senha1) == 0){
            bold(1);
            printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario);

        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de insers�o - Confirma��o de Senha:
    while(1){
        printf("\n                            Confirme sua senha: ");
        mascSenha(ent_senha2, &senha2);
        fflush(stdin);

        if(strlen(senha2) == 0){
            bold(1);
            printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
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
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario);
            //Campo de insers�o - Senha:
            while(1){
                printf("\n                                         Senha: ");
                mascSenha(ent_senha1, &senha1);
                fflush(stdin);

                if(strlen(senha1) == 0){
                    bold(1);
                    printf(RED "\n\n                                      [!] O campo senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |           CADASTRO            |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n"
                             "                                            ID: %i", pessoa.ID,
                           "\n                                          Nome: %s", pessoa.nome,
                           "\n                                       Usu�rio: %s", pessoa.login.usuario);

                }else{
                    break; //Sai do loop se o nome for v�lido
                }
            }
            //Campo de insers�o - Confirma��o de Senha:
            while(1){
                printf("\n                            Confirme sua senha: ");
                mascSenha(ent_senha2, &senha2);
                fflush(stdin);

                if(strlen(senha2) == 0){
                    bold(1);
                    printf(RED "\n\n                               [!] O campo confirme sua senha n�o pode estar vazio!\a");
                    bold(0);
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                    Sleep(800);
                    telaLimpa();
                    printf("\n                                          #===============================#                                             \n"
                             "                                          |           CADASTRO            |                                             \n"
                             "                                          #===============================#                                             \n"
                             "                                                                                                                        \n"
                             "                                            ID: %i", pessoa.ID,
                           "\n                                          Nome: %s", pessoa.nome,
                           "\n                                       Usu�rio: %s", pessoa.login.usuario,
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
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2);

        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de sele��o - Cargo:
    int escolhacargo;
    printf("\n\n                                                       CARGO:"
             "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA");
    while(1){
        printf("\n                               Digite o n�mero correspondente ao cargo escolhido: ");
        scanf("i", &escolhacargo);
        fflush(stdin);

        switch(escolhacargo){
        case 1:
            pessoa.cargo = CARGO_2;
            break;
        case 2:
            pessoa.cargo = CARGO_3;
            break;
        case 3:
            pessoa.cargo = CARGO_4;
            break;
        default:
            bold(1);
            printf(RED "\n\n\t\t\t [!] Op��o inv�lida! Tente novamente.\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA");
        }

        if(escolhaCargo >= 1 && escolhaCargo <= 4){
            printf("\n                                         Cargo: %s", pessoa.cargo);
            break; //Sai do loop se a op��o for v�lida
        }
    }
    //Campo de inser��o - Data de nascimento:
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo);
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - Rua:
    printf("\n\n                                                      ENDERE�O:");
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf,
                   "\n                               RG(00.000.000-0: %s", pessoa.documento.rg
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
        numero[strcspn(numero, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        pessoa.endereco.num_resd = numero;

        if(strlen(pessoa.endereco.num_resd) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo N�mero n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf,
                   "\n                               RG(00.000.000-0: %s", pessoa.documento.rg,
                   "\n\n                                                      ENDERE�O:"
                   "\n                                           Rua: %s", pessoa.endereco.rua);
        }else{
            break; //Sai do loop se o nome for v�lido
        }
    }
    //Campo de inser��o - Bairro:
    while(1){
        printf("\n                                        Bairro: ");
        fgets(pessoa.endereco.bairo, sizeof(pessoa.endereco.bairo), stdin);
        pessoa.endereco.bairo[strcspn(pessoa.endereco.bairo, "\n")] = 0; //Remove caractere de nova linha.
        fflush(stdin);

        if(strlen(pessoa.endereco.bairo) == 0){
            bold(1);
            printf(RED "\n\n                                     [!] O campo Bairro n�o pode estar vazio!\a");
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            telaLimpa();
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf,
                   "\n                               RG(00.000.000-0: %s", pessoa.documento.rg,
                   "\n\n                                                      ENDERE�O:"
                   "\n                                           Rua: %s", pessoa.endereco.rua,
                   "\n                                        N�mero: %s", pessoa.endereco.num_resid);
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf,
                   "\n                               RG(00.000.000-0: %s", pessoa.documento.rg,
                   "\n\n                                                      ENDERE�O:"
                   "\n                                           Rua: %s", pessoa.endereco.rua,
                   "\n                                        N�mero: %s", pessoa.endereco.num_resid,
                   "\n                                        Bairro: %s", pessoa.endereco.bairro);
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
            printf("\n                                          #===============================#                                             \n"
                     "                                          |           CADASTRO            |                                             \n"
                     "                                          #===============================#                                             \n"
                     "                                                                                                                        \n"
                     "                                            ID: %i", pessoa.ID,
                   "\n                                          Nome: %s", pessoa.nome,
                   "\n                                       Usu�rio: %s", pessoa.login.usuario,
                   "\n                                         Senha: %s", senha1,
                   "\n                            Confirme sua senha: %s", senha2,
                   "\n                                        e-mail: %s", pessoa.email,
                   "\n\n                                                       CARGO:"
                   "\n                               [1] GERENTE | [2] OPERADOR DE CAIXA | [3] ESTOQUISTA"
                   "\n                               Digite o n�mero correspondente ao cargo escolhido: "
                   "\n                                         Cargo: %s", pessoa.cargo,
                   "\n                Data de Nascimento(00/00/0000): %s", pessoa.nasc,
                   "\n                           CPF(000.000.000/00): %s", pessoa.documentos.cpf,
                   "\n                               RG(00.000.000-0: %s", pessoa.documento.rg,
                   "\n\n                                                      ENDERE�O:"
                   "\n                                           Rua: %s", pessoa.endereco.rua,
                   "\n                                        N�mero: %s", pessoa.endereco.num_resid,
                   "\n                                        Bairro: %s", pessoa.endereco.bairro,
                   "\n                                CEP(00000-000): %s", pessoa.endereco.cep);


        }else{
            break; //Sai do loop se o nome for v�lido.
        }
    }

    //Abre arquivo para escrita bin�ria.
    arquivo = fopen("cadastros.bin", "wb");

    //Verifica se o arquivo foi encontrado.
    if(arquivo == NULL){
        printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!"); bold(1);
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


}
