#include "funcoes.h"

Pessoa usuarioLogado; // Definindo uma estrutura global para armazenar os dados do usu�rio logado.

int verificaLogin(char *ent_usuario, char *ent_senha, char *cargo){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    Pessoa pessoa;

    FILE *arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    if(arquivo == NULL){
        // Se o arquivo n�o existe, cria um novo e adiciona o cadastro do Administrador.
        arquivo = fopen("dados\\funcionarios\\cadastros.bin", "wb");
        if(arquivo == NULL){
            printf(RED "\n\n                                       [ERRO:] Ocorreu um erro ao criar o arquivo!");
            bold(1);
            bold(0);
            SetConsoleTextAttribute(hConsole, saved_attributes);
            Sleep(800);
            return 0; // Retorna 0 em caso de erro
        }
        // Cria cadastro do Administrador.
        pessoa.ID = 0;
        strcpy(pessoa.nome, "Administrador\0");
        strcpy(pessoa.login.usuario, "admin\0");
        strcpy(pessoa.login.senha, "admin123\0");
        strcpy(pessoa.cargo, "ADMINISTRADOR\0");

        // Escreve cadastro Administrador no arquivo.
        fwrite(&pessoa, sizeof(Pessoa), 1, arquivo);
        fclose(arquivo);
    }

    // Reabre o arquivo para leitura
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    while (fread(&pessoa, sizeof(Pessoa), 1, arquivo)) {
        if (strcmp(pessoa.login.usuario, ent_usuario) == 0 && strcmp(pessoa.login.senha, ent_senha) == 0) {
            fclose(arquivo);
            strcpy(cargo, pessoa.cargo); // Armazena o cargo do usu�rio
            // Pega informa��es do usu�rio
            usuarioLogado = pessoa; // Armazena os dados do usu�rio logado
            return 1; // Usu�rio encontrado.
        }
    }
    fclose(arquivo);
    return 0; // Usu�rio n�o encontrado.
}

void mascSenha(char ent_senha, char *senha[TAM_user]){

    char senha_usuario[TAM_user] = "0";
    int pos = 0;
    int comparador;

    do{
        ent_senha = getch();

        if(isprint(ent_senha)){
            senha_usuario[pos++] = ent_senha;
            printf("%c", '*');
        }
        else if(ent_senha == 8 && pos){
            senha_usuario[pos--] = '\0';
            printf("%s", "\b \b");
        }
        strcpy(senha, senha_usuario);
    }while(ent_senha != 13);
}

int lerUltimoID(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\funcionarios\\ultimo_id.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID, sizeof(int), 1, arquivo); // L� o �ltimo ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo n�o existir, inicializa ultimoID com 0
        ultimoID = 0;
    }

    return ultimoID;
}

int salvarUltimoID(int ultimoID){

    FILE *arquivo;

    //Abre um arquivo bin�rio (cria de n�o existe).
    arquivo = fopen("dados\\funcionarios\\ultimo_id.bin", "wb");
    if(arquivo != NULL){
        //Escreve o �ltimo ID no arquivo.
        fwrite(&ultimoID, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID(){

    static int ultimoID; // Remove a inicializa��o com lerUltimoID().

    //Verificando se � a primeira vez que a fun��o � chamada.
    if(ultimoID == 0){
        // L� o �ltimo ID do arquivo.
        ultimoID = lerUltimoID();
    }
    return ++ultimoID; // Retorna o pr�ximo ID incremental.
}

int usuarioExiste(char *usuario){

    FILE *arquivo;

    //Abre um arquivo bin�rio (cria de n�o existe).
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");

    if(arquivo == NULL){
        return 0; //Arquivo n�o existe, ou n�o pode ser aberto;
    }

    Pessoa pessoa;
    while(fread(&pessoa, sizeof(Pessoa), 1, arquivo)){
        if(pessoa.ID != 1 && strcmp(pessoa.login.usuario, usuario) == 0){
            fclose(arquivo);
            return 1; //Usu�rio encontrado.
        }
    }
    fclose(arquivo);
    return 0;
}

void verificaSenhas(char ent_senha1[], char ent_senha2[], int *comparador){

    int compSenha;

    compSenha = strcmp(ent_senha1, ent_senha2);

    if(compSenha == 0){
        *comparador = 0;
    }else{
        *comparador = 1;
    }
}

Pessoa buscarCadastroPorID(int id){
    FILE *arquivo;
    Pessoa cadastro;
    int encontrado = 0;

    //Abre o arquivo para leitura.
    arquivo = fopen("dados\\funcionarios\\cadastros.bin", "rb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return cadastro; //Retorna um cadastro vazio em caso de erro.
    }

    //L� os cadastros at� encontrar o ID
    while(fread(&cadastro, sizeof(Pessoa), 1, arquivo)){
        if (cadastro.ID == id) { //Compara com o ID de entrada, n�o Pessoa.ID.
            encontrado = 1;
            break; //Encerra o loop se o ID for encontrado.
        }
    }

    fclose(arquivo); //Fecha o arquivo.

    if(!encontrado){
        cadastro.ID = -1; //Indica que n�o foi encontrado.
    }

    return cadastro; //Retorna o cadastro encontrado ou vazio.
}

int lerUltimoID_Produto(){

    FILE *arquivo;

    // Verifica se o arquivo existe
    arquivo = fopen("dados\\produtos\\ultimo_id_produto.bin", "rb");
    if(arquivo != NULL){
        fread(&ultimoID_Produto, sizeof(int), 1, arquivo); // L� �ltimo ID do arquivo
        fclose(arquivo);
    }else{
        // Se o arquivo n�o existir, inicializa ultimoID_Produto com 0
        ultimoID_Produto = 0;
    }

    return ultimoID_Produto;
}

int salvarUltimoID_Produto(int ultimoID_Produto){

    FILE *arquivo;

    //Abre um arquivo bin�rio (cria se n�o existir)
    arquivo = fopen("dados\\produtos\\ultimo_id_produto.bin", "wb");
    if(arquivo != NULL){
        // Escreve o �ltimo ID no arquivo
        fwrite(&ultimoID_Produto, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

int gerarID_Produto(){

    static int ultimoID_Produto; //Remove a inicializa��o com lerUltimoID_Produto()

    // Verifica se � a primeira vez que a fun��o � chamada
    if(ultimoID_Produto == 0){
        // L� o �ltimo ID do arquivo
        ultimoID_Produto = lerUltimoID_Produto();
    }

    return ++ultimoID_Produto; //Retorna o pr�ximo ID incremental.
}
