#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{ 
    setlocale(LC_ALL, "Portuguese");
    int selecao = 0;
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    char arquivo[1000];
    strcpy(arquivo, cpf); // copia o cpf para o string arquivo

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w");
    fprintf(file, "%s", cpf); //salva o valor da variável no arquivo 
    fclose(file); //fecha o arquivo

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, " ");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso.\n");
    printf("\n\n");

    printf("Escolha uma opção:\n\n");
    printf("\t1- Cadastrar mais colaboradores\n");
    printf("\t2- Voltar ao menu\n\n");
    system("pause");

    scanf("%d", &selecao);
    switch(selecao){
    case 1:
         system("cls");
         registro();
       
        scanf("%d", &selecao);
        break;
    case 2:
     system("pause");
                system("cls");
                return 0;
                break;
    default:
                printf("Opção inválida! Tente novamente.\n\n");
                system("pause");
                system("cls");
                return 0;
                break;
}

}

int consultar()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o cpf que deseja consultar: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não localizado!\n");
        system("pause");
        system("cls");

        return 0;
        
    }

    printf("\nEssas são as informações do usuário:\n\n");
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
    }
    printf("\n\n");
    fclose(file);
    system("pause");
    system("cls");
    return 0;
    
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];

    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s", cpf);

    if(remove(cpf) == 0) //verifica se o arquivo foi deletado com sucesso
    {
        printf("Cadastro deletado com sucesso.\n");
    }
    else
    {
        printf("Erro ao deletar cadastro.\n");
    }
    printf("\n\n");
    system("pause");
    system("cls");
    return 0;
    
}

int main()
{
    int opcao = 0;
    int continuar = 1;
    

    setlocale(LC_ALL, "Portuguese");

    while (continuar) // loop principal
    {
        printf("\tRegistro de dados da EBAC\n\n"); // início do menu
        printf("Bem-vindo\n\n");
        printf("\t1-Registrar nomes\n");
        printf("\t2-Consultar nomes\n");
        printf("\t3-Deletar nomes\n\n"); // fim do menu
        printf("\t4-Sair do sistema\n\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // armazena a escolha do usuário

        switch (opcao) // início da seleção
        {
            case 1:
                registro();
                break;
            case 2:
                consultar();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Obrigado por utilizar o sistema\n");
                return 0;
                break;

            default:
                printf("Opção inválida! Tente novamente.\n\n");
                system("cls");
                main();
                break;
          } // fim da seleção
    }

    }
