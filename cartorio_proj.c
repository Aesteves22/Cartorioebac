#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criações de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string para salvar-la
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o ''w'' significa escrever
	fprintf(file, "\nCPF: ");//salva o valor da variável
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o ''a'' significa atualizar
	fprintf(file, "\nNome: ");//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //salvando a string
	
	file = fopen(arquivo, "a");// abertura do arquivo para atualizar
	fprintf(file, nome);//salva o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abertura do arquivo
	fprintf(file, "\nSobrenome: ");// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",sobrenome); //salvando a string
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file,sobrenome);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file, "\nCargo: ");//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",cargo);//salvando a string
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file,cargo);//salva o valor da variável
	fprintf(file, "\n\n");//
	fclose(file);//fecha o arquivo
	
	system("pause");//funcionalidade para manter o usuário na tela desejada
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//inicio da criações de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuario
	scanf("%s",cpf); //salvando a string
	
	FILE *file;//criação do arquivo
	file = fopen(cpf, "r");//abertura do arquivo sendo ''r'' como leitura do arquivo
	
	
	if(file == NULL)//informação para o sistema caso for nulo 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");//informação para o usuário
	}
	
		printf("\nEssa são as informações do usuário: \n");//informação para o usuário
	
	while(fgets(conteudo, 200, file) != NULL)//operador de repetição
	{
		printf("%s",conteudo); //salvando a string
	}
	
	system("pause");//funcionalidade para o usuário permanecer na função desejada
	fclose(file);
	
}

int deletar()
{
	//inicio da criação de variáveis/string
	char cpf[40];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: ");//coletando informação do usuário
	scanf("%s", cpf);// salvando a informação adiquirida 
	
	
	FILE *file;//criação do arquivo
	file = fopen(cpf,"r");//abertura do arquivo sendo ''r'' como leitura do arquivo
	fclose(file);
	
	if(file == NULL) //estrutura de decisão
	{
		printf("O usuário não se encontra no sistema!.\n");//informação para o usuário
		system("pause");//funcionalidade para o usuário permanecer na função desejada
	}
	
	else //estrutura de decisão 
	{
		remove(cpf); //deleta o arquivo 
		
		printf("O usuário foi deletado com sucesso!.\n");//informação para o usuário
		system("pause");//funcionalidade para o usuário permanecer na função desejada
	}
}




int main()
{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
	
			system("cls");// Responsavel por limpar a tela
		
			setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ### \n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu: \n\n"); 				
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //final do menu

			scanf("%d" , &opcao); //armazenando a escolha do usuário
	
			system("cls"); //responsavel por limpar a tela
	
		
			switch(opcao) //inicio da seleção de menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();//chamada de funções
				break;
			
				case 3:
				deletar();//chamada de funções
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:// funcionalidade caso o usuário escolha algo função inexistente 
				printf("Essa opção não está disponivel!\n");//informação para o usuário
				system("pause");//funcionalidade para manter o usuário na função desejada
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}
