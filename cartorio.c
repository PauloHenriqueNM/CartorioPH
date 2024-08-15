#include <stdio.h> // biblioteca de comunicação entre máquina e o usuário
#include <stdlib.h>// biblioteca de alocação de memória
#include <locale.h>// biblioteca de configuração de região para caracteres
#include <string.h>// biblioteca de strings

int registro(){
	printf("- Registro de nomes -\n\n");
	
	char arquivo [45];
	char cpf [11];
	char nome [45];
	char sobrenome [45];
	char cargo [45];
	
	printf("Digite o CPF para o cadastro: ");
	scanf("%s", cpf); // Salvar um input do usuário tipo string
	
	strcpy(arquivo, cpf); // Responsavel por copiar o valor das string no exemplo de cpf para arquivo
	
	FILE *file; //criando o arquivo
	file = fopen(arquivo,"w");//criando o arquivo o "w" serve para criar um novo arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // abrir o arquivo o "a" server para atualizar
	fprintf(file," , ");// Para realizar a separação dentro do banco de dados
	fclose(file);//fecha arquivo
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file," , ");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file," , ");
	fclose(file);
	
	system("pause");
		
}

int consulta(){
	printf("- Consulta de nomes -\n");
	
	char cpf[11];
	char conteudo[200];
	
	printf("Digite o CPF para consulta: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// O "r" serve para abrir o arquivo apenas em formato de leitura.
	
	if(file == NULL){
		printf("CPF não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){// aqui o while vai buscar dentro do arquivo até o limite de 200 caracteres e sem ser dados nulos.
		printf("\n Essas são as informações do cadastro: ");
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deleta(){
	printf("- Deletar nomes - \n\n");
	
	char cpf[11];
	
	printf("Digite o CPF para ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file){
			fclose(file);
			if (remove(cpf) == 0) {
				printf("Usuário deletado com sucesso!\n");
			} else {
				printf("Erro ao deletar usuário!\n");
			} 	
		}	else {
			printf("Usuário não encontrado!");
		}
system("pause");
}


int main (){
	
	int opcao=0;
	int laco=1;
		
		for(laco=1; laco=1;){
			
			setlocale(LC_ALL, "Portuguese");
			system("cls");
			
			printf ("----  Cartório da EBAC  ----\n");
			printf ("-- Menu Principal - Selecionar opção --\n\n");
			printf ("\t1 - Registrar nomes \n");
			printf ("\t2 - Consultar nomes \n");
			printf ("\t3 - Deletar nomes \n\n\n ");
			printf ("Opção: ");
			
			scanf ("%d", &opcao);
			system ("cls");
			
			switch(opcao){
				case 1:
				registro();
				break;
				
				case 2:	
				consulta();
				break;
				
				case 3:
				deleta();
				break;
				
				default :
				printf(" Opção inválida!\n");
				system("pause");
				break;	
			}
			
		}	
					
}


