#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> 
#include <conio.h> 

struct usuarios_infos{
	char tipo[5];
	char rg[20];
	char cpf[20];
	char nome[50];
	char senha[6];
	char email[30];
};

struct paciente{
	char cpf[20];
	char nome[50];
	char rg[20];
	char endereco[50];
	char telefone[20];
	char id[20];
	
};


int licenca = 10;
char k, sen;
char s[6];
int  i, rec;
char log[20];
bool senOk = false;

int main(){
	
	
	struct usuarios_infos usuarios_infos;
	
	setlocale (LC_ALL, "");
	system("mode con: cols=160 lines=78");
	inicio:
	system("color f1");	
	printf("\n\n\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t     SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER SAUDEMASTER  \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n");
	printf("\t\t\t\t\t\t\t\t  SAUDEMASTER SAUDEMASTER SAUDEMASTER \n\n\n");
	
		printf("\t\t\t\t\t\t\t\t      LOANDING................... \n\n\n");
		
		printf("\t\t\t\t\t\t\t\t    PRIMEIRO ACESSO ? [s] ou [n] : ");
		scanf("%s", &k);
	 	if (k == 'n'){
			system("cls");
			goto login;
		}
        system("cls");
	//tela de instalação
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t     INSIRA O CODIGO DE COMPRA: ");
	scanf("%d", &i);
		if(licenca == i){		
			printf("\n\n\t\t\t\t\t\t\t     INICIANDO O SISTEMA......\n\n");
			system("pause");
			system("cls");
			goto usuario;
		}else{
			printf("n\n\n\t\t\t\t\t\t\t     CODIGO INCORRETO......\n\n");
			system("pause");
			system("cls");
			goto inicio;
		}


	usuario:	//Tela de Cadastro de Usuario 
	
	FILE *user;
	user = fopen("login.txt", "a");
	
	printf ("\n\n\t\t\t\t\t\t\t**Cadastro Novo Usuario**\n\n");
	
	printf("Nome Completo: ");
	scanf("%s", &usuarios_infos.nome);
	fflush(stdin);
	printf("\nDigite o RG: ");
	scanf("%s", &usuarios_infos.rg);
	fflush(stdin);
    printf("\nDigite seu E-mail: ");
	scanf("%s", &usuarios_infos.email);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t*****Selecione o Nivel do Usuario*****\n\n\n");
	printf("[1] Diretoria			[2] Administrativo			[3] Atendimento			[4]Medico \n\n\n");
	printf("Nivel do usuario: ");
	scanf("%s", &usuarios_infos.tipo);
	fflush(stdin);
	printf ("\n\n\n\t\t\t\t\t\t**Cadastro Login e Senha**\n\n\n");
	printf("Insira o Login/CPF: ");
	scanf("%s", &usuarios_infos.cpf);
	fflush(stdin);
   	printf("insira a senha de 6 digitos:");
	scanf("%s", &usuarios_infos.senha);
	fflush(stdin);	
	
	
	fprintf(user,"%s %s %s %s %s %s", usuarios_infos.nome, usuarios_infos.rg, usuarios_infos.email, usuarios_infos.tipo, usuarios_infos.cpf, usuarios_infos.senha);
	fclose(user);
	
	printf("Usuario Cadastrado com sucesso!");
	system("pause");
 
 	printf ("\n\nCadastrar Novo Usuario [s] ou [n] ? ");
 	scanf("%s", &k);
	 	if(k == 's'){
	 		system("cls");
			goto usuario;
		}

	  	login://Tela de Login
	  	system("cls");
		user = fopen("login.txt", "r");
	 	printf("\n\n\t\t\t\t\t\t**************Acesso ao Sistema**************\n\n\n\n\n");
		printf("\t\t\t Login [1]		Recuperar senha [2]		  Voltar [3] \n\n");
		printf("\t\t\t Selecione a Opção: ");
		scanf("%d", &rec);
		switch (rec){
			 case 1:
				    system("cls");
  	 			    printf("\n\n\t\t\t\t\t\t**Login**\n\n\n\n\n");
				    printf("Insira seu CPF: ");
				    scanf("%s", &log);
				    fflush(stdin);
		  		    printf("Senha: ");
				    scanf("%s", &s);
				    fflush(stdin);
				    while(fscanf(user,"%s;%s", usuarios_infos.cpf, usuarios_infos.senha) != EOF){
				    	if(strcmp(usuarios_infos.cpf, log) == 0 && strcmp(usuarios_infos.senha, s) == 0){
						printf("\n\n\t\t\t\t\t***Login realizado com sucesso****\n");
					 	system("pause");
					 	system("cls");
					 	goto menuInicial;
					}
				}
					printf("tente novamente\n");
					fclose(user);
					system("pause");	
					system("cls");
					goto login;
			 case 2:
			 		recSenha: //Recuperação de senha
					system("cls");
  			 		user = fopen("login.txt", "r");
  			 		printf("\n\n\t\t\t\t\t\t**Recuperação de Senha**\n\n\n\n\n");
			 		printf(" Insira seu CPF: ");
			 		scanf("%d", &i); 
 	 		 		fflush(stdin);
			 		printf(" Insira seu E-mail: ");
			 		scanf("%s", &s); 
 	 		 		fflush(stdin);
 	 		 		 		if((usuarios_infos.cpf[20] == i) && strcmp(usuarios_infos.email, s) == 0){
			   				printf("\t\t\t\t\t\t***** E-mail Enviado com Sucesso ****");
			   				system("pause");
			   				system("cls");
			        		fclose(user);
			   				goto login;
			   				}
			   		printf("\t\t\t\t\t\t***** CPF ou E-mail incorreto ****\n\n");
			   		printf(" Tentar Novamente ? [s] ou [n] ?  ");
			    	scanf("%s", &k);
	 		 			if (k == 's'){
							system("cls");
			    			goto recSenha;
							}
					system("cls");
					goto login;
			 case 3:
					system("cls");
					goto inicio;
				
		}
		
		menuInicial: //Tela do Menu Inicial
		printf("\n\n\t\t\t\t\t***Menu Inicial***\n\n\n");
		user = fopen("login.txt", "r");
			for(usuarios_infos.tipo[5] ==1){
				printf(" Pacientes [1]				Prontuarios [2]				Agendar consultas/exames [3] \n\n");
				printf(" Cancelamentos [4]			Reagendamentos [5]			Reclamações e Elogios [6] \n\n");
				printf(" Financeiro [7]				Recursos Humanos [8]			Relatórios [9] \n\n");
				scanf("%d", &i);
			}
			/*	switch (i){
						case 1:
	  		  					FILE *patient;

								struct paciente paciente;
	
								system("cls");

								printf("\n\n\t\t\t\t\t******Pacientes******\n\n\n");
	
								printf(" Cadastrar novo Paciente [1]				Consultar Paciente [2]\n\n");
								printf(" Selecione uma opçao: ");
								scanf("%d", &i);
									switch (i){
											case 1:
											do{
												cadPac:
												system("cls");
												printf("\n\n\t\t\t\t\t****** Cadastro de Pacientes******\n\n\n");
													if((patient = fopen("CadPaciente.txt", "a"))==NULL){
														puts("Não encontrado");
														exit(1);
														};
			
														fflush(stdin);
														printf(" Nome do Paciente: ");
														scanf("%s", &paciente.nome);
														printf(" CPF do Paciente: ");
														scanf("%s", &paciente.cpf);
														printf("Repita o CFP do Paciente: ");
														scanf("%s", &paciente.id);
														printf(" RG do Paciente: ");
														scanf("%s", &paciente.rg);
														printf(" Telefone do Paciente: ");
														scanf("%s", &paciente.telefone);
														printf(" Endereço do Paciente: ");
														scanf("%s", &paciente.endereco);
		
														fprintf(patient, "%s\n |NOME: %s\n |CPF: %s\n |RG: %s\n |Telefone: %s\n |Endereço: %s\n\n..........................................................................\n\n", paciente.id, paciente.nome, paciente.cpf, paciente.rg, paciente.telefone, paciente.endereco);
														fclose(patient);
			
														printf(" \n\n\t\t\t Deseja efetuar novo cadastro [s] ou [n] ?  ");
														scanf("%s", &k);	
						
														}while(k == 's');
															goto cadPac;
																if( k == 'n'){
																goto menuInicial;
															}
									case 2:
											system("cls");
											printf("\n\n\t\t\t\t\t****** Conultar Pacientes ******\n\n\n");
												do{
													if((patient = fopen("CadPaciente.txt", "r"))==NULL){
													puts("Não encontrado");
													exit(1);
													};
													printf("Digite o CPF do Paciente: ");
													scanf("%s", &p);
													for(p[20] == paciente.id[20]){
					
													printf(" %s \n %s \n %s \n %s \n %s \n.............................................................\n", paciente.nome, paciente.rg, paciente.cpf, paciente.telefone, paciente.endereco);					
													fclose(patient);
													system("pause");
													}	
													printf("\n\n\t\t\t\t\t********* Paciente não encontrado********");
					
													printf(" \n\n\t\t\t Deseja efetuar nova Consulta [s] ou [n] ?  \n\n");
													scanf("%s", &k);	
													}while(k == 's');	
            										goto cadPac;
														}
														
														}
											/*case 2:
														
						case 2:
						
						case 3:
					
						case 4:
					
						case 5:
					
						case 6:
							
						case 7:
					
						case 8:
						
						case 9:	
						
				};
				
				}if(usuarios_infos.tipo ==2){
					printf(" Financeiro [1]				Recursos Humanos [2]			Relatórios [3] ");
					scanf("%d", &i)
						switch (i){
							case 1:
					
							case 2:
						
							case 3:
							}	
					}if(usuarios_infos.tipo ==3){
						printf(" Pacientes [1]				Prontuarios [2]				Agendar consultas/exames [3] \n\n");
						printf(" Cancelamentos [4]			Reagendamentos [5]			Reclamações e Elogios [6] \n\n");
						printf(" Financeiro [7]");
						scanf("%d", &i)
							switch (i){
								case 1:
					
								case 2:
						
								case 3:
					
								case 4:
					
								case 5:
					
								case 6:
					
								case 7:
						}if(usuarios_infos.tipo ==4){
							prinf("Prontiarios [1]			Agendar consultas/exames [2]");
							scanf("%d", &i)
								switch (i){
									case 1:
					
									case 2:
									}
						}*/
					
		
					
}
