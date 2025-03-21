#include <stdio.h>
#include <locale.h>
#include <string.h>

int opcao = 0;
char login[50], senha[15];  // Aumentei o tamanho de login para 50 para suportar nomes maiores

// Função do cadastro, onde você coloca as credenciais
void fazerCadastro() {
    printf("\nMe diz aí qual vai ser o seu CADASTRO: ");
    scanf(" %[^\n]", login);  // Agora, lê o login com espaços (primeiro nome + sobrenome)

    printf("Agora, me manda sua SENHA: ");
    scanf("%s", senha);  // Agora você coloca a senha, pra garantir que só você vai acessar

    printf("Confirma sua SENHA AI MEU FII: ");
    scanf("%s", senha);  // Só pra garantir que a senha tá certinha, né? Não queremos erro aqui!

    printf("\nCadastro feito com sucesso, pode ficar tranquilo que tá tudo certo!\n\n");
}

// Função do login, onde você entra no sistema com as suas credenciais
int fazerLogin() {
    char loginTentativa[50], senhaTentativa[15];

    printf("Agora digita seu LOGIN: ");
    scanf(" %[^\n]", loginTentativa);  // Tentando o login que você digitou na hora do cadastro

    printf("Agora manda sua SENHA: ");
    scanf("%s", senhaTentativa);  // Tentando a senha

    // Aqui comparamos se o login e senha que o cara digitou são os mesmos que a gente guardou
    if (strcmp(login, loginTentativa) == 0 && strcmp(senha, senhaTentativa) == 0) {
        printf("\n\nLogin realizado com sucesso! Agora você tá dentro, irmão!\n\n");
        return 1;  // Retorna 1 quando o login for top
    } else {
        printf("\n\nEsses dados não bateram... tenta de novo, meu chapa.\n\n");
        return 0;  // Retorna 0 se a tentativa falhou
    }
}

// Função que exibe o menu de opções
void mostrarMenu() {
    printf("*************************************\n");
    printf("****** Bem-vindo ao IMOBNIP! ******\n");
    printf("*************************************\n");

    printf("1) Cadastro de Clientes\n");
    printf("2) Cadastro de Corretores\n");
    printf("3) Sair\n\n");

    printf("Escolha uma opção, vai ser rápida: ");
    scanf("%d", &opcao);  // Aí você escolhe o que vai fazer
    getchar();  // Só pra limpar o buffer
}

// Função para cadastrar os clientes
void cadastrarClientes() {
    char nome[50], cpf[15], telefone[15];

    printf("\nAgora, vamos cadastrar um cliente!\n");
    printf("Qual o nome do cliente? ");
    scanf(" %[^\n]", nome);  // Agora você pode colocar o nome do cliente com espaços

    printf("Qual o CPF? ");
    scanf("%s", cpf);  // CPF do cliente

    printf("E o telefone? ");
    scanf("%s", telefone);  // O telefone do cliente

    printf("\nCadastro realizado com sucesso!\n");
    printf("Cliente: %s\n", nome);  // Mostra tudo o que você digitou
    printf("CPF: %s\n", cpf);
    printf("Telefone: %s\n", telefone);
}

// Função para cadastrar os corretores
void cadastrarCorretores() {
    char nome[50], creci[15], telefone[15];

    printf("\nAgora, vamos cadastrar um corretor!\n");
    printf("Qual o nome do corretor? ");
    scanf(" %[^\n]", nome);  // Nome do corretor

    printf("Qual o CRECI? ");
    scanf("%s", creci);  // CRECI do corretor

    printf("E o telefone? ");
    scanf("%s", telefone);  // Telefone do corretor

    printf("\nCadastro do corretor feito com sucesso!\n");
    printf("Corretor: %s\n", nome);
    printf("CRECI: %s\n", creci);
    printf("Telefone: %s\n", telefone);
}

int main() {
    setlocale(LC_ALL, "");  // Aqui a gente garante que os caracteres especiais (como acento) vão funcionar direitinho

    // Passo 1: Realizar o cadastro
    fazerCadastro();

    // Passo 2: Agora é a hora do login, tenta até conseguir entrar, relaxa que vai dar certo
    int loginValido = 0;
    while (loginValido == 0) {
        loginValido = fazerLogin();  // Se der errado, tenta mais uma vez
    }

    // Passo 3: Depois de logado, você já pode acessar o sistema e escolher o que fazer
    printf("\nTudo certo, agora você tem acesso ao sistema!\n");
    mostrarMenu();

    // Passo 4: De acordo com a opção que você escolheu, vai fazer a ação
    switch (opcao) {
        case 1:
            cadastrarClientes();  // Se escolher 1, vamos cadastrar um cliente
            break;

        case 2:
            cadastrarCorretores();  // Se escolher 2, vamos cadastrar um corretor
            break;

        default:
            printf("Eita, você digitou algo errado. Que tal tentar novamente?\n");
            break;
    }

    return 0;
}


//TIVE AJUDA, MAIS DEU CERTO, QUEBREI A CABEÇA. ASSISTIR VARIOS VIDEOS KSKS, E CONSEGUIR, UNS 20 VIDEOS KKKL, CUIDAAAA LOGO E VAI ESTUDAR MANNN 
