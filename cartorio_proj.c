#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��es de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string para salvar-la
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o ''w'' significa escrever
	fprintf(file, "\nCPF: ");//salva o valor da vari�vel
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o ''a'' significa atualizar
	fprintf(file, "\nNome: ");//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //salvando a string
	
	file = fopen(arquivo, "a");// abertura do arquivo para atualizar
	fprintf(file, nome);//salva o valor da vari�vel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");// abertura do arquivo
	fprintf(file, "\nSobrenome: ");// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",sobrenome); //salvando a string
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file,sobrenome);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file, "\nCargo: ");//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",cargo);//salvando a string
	
	file = fopen(arquivo, "a");//abertura do arquivo para atualizar
	fprintf(file,cargo);//salva o valor da vari�vel
	fprintf(file, "\n\n");//
	fclose(file);//fecha o arquivo
	
	system("pause");//funcionalidade para manter o usu�rio na tela desejada
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//inicio da cria��es de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usuario
	scanf("%s",cpf); //salvando a string
	
	FILE *file;//cria��o do arquivo
	file = fopen(cpf, "r");//abertura do arquivo sendo ''r'' como leitura do arquivo
	
	
	if(file == NULL)//informa��o para o sistema caso for nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");//informa��o para o usu�rio
	}
	
		printf("\nEssa s�o as informa��es do usu�rio: \n");//informa��o para o usu�rio
	
	while(fgets(conteudo, 200, file) != NULL)//operador de repeti��o
	{
		printf("%s",conteudo); //salvando a string
	}
	
	system("pause");//funcionalidade para o usu�rio permanecer na fun��o desejada
	fclose(file);
	
}

int deletar()
{
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);// salvando a informa��o adiquirida 
	
	
	FILE *file;//cria��o do arquivo
	file = fopen(cpf,"r");//abertura do arquivo sendo ''r'' como leitura do arquivo
	fclose(file);
	
	if(file == NULL) //estrutura de decis�o
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");//informa��o para o usu�rio
		system("pause");//funcionalidade para o usu�rio permanecer na fun��o desejada
	}
	
	else //estrutura de decis�o 
	{
		remove(cpf); //deleta o arquivo 
		
		printf("O usu�rio foi deletado com sucesso!.\n");//informa��o para o usu�rio
		system("pause");//funcionalidade para o usu�rio permanecer na fun��o desejada
	}
}




int main()
{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
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
	
			printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu: \n\n"); 				
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //final do menu

			scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
			system("cls"); //responsavel por limpar a tela
	
		
			switch(opcao) //inicio da sele��o de menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();//chamada de fun��es
				break;
			
				case 3:
				deletar();//chamada de fun��es
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:// funcionalidade caso o usu�rio escolha algo fun��o inexistente 
				printf("Essa op��o n�o est� disponivel!\n");//informa��o para o usu�rio
				system("pause");//funcionalidade para manter o usu�rio na fun��o desejada
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!");
}
