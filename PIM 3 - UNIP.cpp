#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define ARQUIVO_USUARIOS "usuarios.txt"
#define ARQUIVO_PACIENTES "pacientes.txt"
#define ARQUIVO_PAGAMENTOS "pagamentos.txt"
#define ARQUIVO_COBRANCA "cobrancas.txt"
#define ARQUIVO_PRONTUARIO "prontuarios.txt"
#define MSG_PCT_NAO_ENCONTRADO "\nPaciente não encontrado\n"
#define PESQUISAR_UNIDADE "pesquisar_unid"
#define STR_ESPACO "%[^\n]%*c"
#define TRACO "-"
#define ESPACO " "
#define CPF_INEXISTENTE "cpf_inexistente"
#define DATA_INEXISTENTE "data_inexistente"
#define FORMATO_PACIENTE "%s;%s;%s;%s;%s"
#define LICENCA 10


//definições de variáveis
struct Usuario {
	int nivel;
	char rg[20];
	char cpf[20];
	char nome[50];
	char senha[6];
	char email[50];
};

struct Paciente {
	char cpf[12];
	char nome[50];
	char rg[20];
	char endereco[300];
	char telefone[20];
};

struct Prontuario {	
	char cpf[15];
	char data[11];
	char descricao[800];
};

struct Pagamento {
	int unidade;
	char tipo[30];
	char valor[15];
	char data[11];
	char observacoes[100];
};

struct Cobranca {
	int unidade;
	char nome_especialidade[50];
	char valor[20];
	char data[20];
	char forma_pag[2];
};

//definição de funções
void cadastrarPaciente();
Paciente consultarPaciente();
void cadastrarUsuario();
Usuario loginUsuario();
int recuperarSenha();
void cadastroProntuario();
void consultaProntuario();
void cadastroPagamento();
void consultaPagamento();
void cadastroCobranca();
void consultarCobranca();
char* substituir(const char* s, const char* oldW, const char* newW);
Paciente *todosPacientes();
int consultarIdxPaciente(Paciente *pacientes, char *cpf_consultado);
void atualizarTodosPacientes(Paciente *pacientes);
void editarPaciente();
void excluirPaciente();
Pagamento* relatorioContasPagar(char *unidade_inserida);
Cobranca* relatorioContasReceber(char *unidade_inserida);
void relatorioFaturamento();

int main() {
	
	struct Usuario usuario;
	struct Paciente paciente;
	struct Pagamento pagamento;
	struct Cobranca cobranca;
	struct Prontuario prontuario;

	char opcao_char;
	int opcao_int;

	setlocale(LC_ALL, "");
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
	
	scanf("%s", &opcao_char);
	if (opcao_char == 'n')
	{
		system("cls");
		goto login;
	}
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t     INSIRA O CÓDIGO DE COMPRA: ");
	int codigo_inserido;
	scanf("%d", &codigo_inserido);
	if (LICENCA == codigo_inserido)
	{
		printf("\n\n\t\t\t\t\t\t\t     INICIANDO O SISTEMA......\n\n");
		system("pause");
		system("cls");
		goto usuario;
	}
	else
	{
		printf("n\n\n\t\t\t\t\t\t\t     CÓDIGO INCORRETO......\n\n");
		system("pause");
		system("cls");
		goto inicio;
	}
//tela de Cadastro de Usuario
usuario: 
	cadastrarUsuario();
	printf("\n\nDeseja cadastrar um novo usuário [s] ou [n] ? ");
	scanf("%s", &opcao_char);
	if (opcao_char == 's') {
		goto usuario;
	}

//tela de login
login:
	system("cls");
	printf("\n\n\t\t\t\t\t\t**************Acesso ao Sistema**************\n\n\n\n\n");
	printf("\t\t\t Login [1]		Recuperar senha [2]		  Voltar [3] \n\n");
	printf("\t\t\t Selecione a Opção: ");
	scanf("%d", &opcao_int);
	if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
		goto login;
	}
	
	switch (opcao_int) {
	case 1:
		usuario = loginUsuario();
		if (usuario.nivel != -1) {
			system("pause");
			goto menuInicial;
			
		} else {
			printf("\nTente novamente\n");
			system("pause");
			system("cls");
			goto login;
		}
		break;
	case 2:
		recSenha:
		system("cls");
		if (recuperarSenha()) {
			goto login;	
		} else {
			printf("\t\t\t\t\t\t***** CPF incorreto ****\n\n");
			printf(" Tentar Novamente [s] ou [n] ?  ");
			scanf("%s", &opcao_char);
			if (opcao_char == 's') {
				goto recSenha;
			}
		}
		break;
	case 3:
		system("cls");
		goto inicio;
	}

menuInicial: //Tela do Menu Inicial
	system("cls");
	printf("\n\n\t\t\t\t\t*****MENU INICIAL*****\n\n\n");
	if (usuario.nivel == 1) {
		printf(" Pacientes [1]				Prontuários [2]				Agendar consultas [3] \n\n");
		printf(" Reclamações e Elogios [4]  		Financeiro [5]				Recursos Humanos [6]\n\n");
		printf(" Relatórios [7] \n\n");
	}
	
	if (usuario.nivel == 2) {
		printf(" Financeiro [5]				Recursos Humanos [6]			Relatórios [7]\n\n");
	}
	
	if (usuario.nivel == 3) {
		printf(" Pacientes [1]				Prontuários [2]				Agendar consultas [3] \n\n");
		printf(" Reclamações e Elogios [6]    Financeiro [5]\n\n");
	}
	
	if (usuario.nivel == 4) {
		printf(" Prontuários [2]				Agendar consultas [3]\n\n");
	}
	
	scanf("%d", &opcao_int);

	switch (opcao_int) {
		pacientes:
			
		case 1:
			cadPac:		
				system("cls");
				printf("\n\n\t\t\t\t\t*****PACIENTES*****\n\n\n");
		
				printf("\t\t\tCadastrar novo Paciente [1]  Consultar Paciente [2]  Editar [3]  Excluir [4]  Voltar [5]\n\n");
				printf(" Selecione uma opção: ");
				
				scanf("%d", &opcao_int);
				if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3 && opcao_int != 4 && opcao_int != 5) {
					goto cadPac;
				}
				
				switch (opcao_int) {
				case 1:
					system("cls");
					cadastrarPaciente();
					printf("\n\nDeseja efetuar novo cadastro [s] ou [n] ?  ");
					scanf("%s", &opcao_char);
					if (opcao_char == 's') {
						goto cadPac;
					} else {
						goto pacientes;
					}
					break;					
				case 2:
					system("cls");
					paciente = consultarPaciente();
					if (strcmp(paciente.cpf, CPF_INEXISTENTE) == 0) {
						printf(MSG_PCT_NAO_ENCONTRADO);
					}
					
					printf("\n\nDeseja realizar nova consulta [s] ou [n] ?  \n\n");
					scanf("%s", &opcao_char);
					if (opcao_char == 's') {
						system("cls");
						goto cadPac;
					}
				case 3:
					editarpaciente:
						
					editarPaciente();
					printf("\n\nDeseja realizar uma nova edição [s] ou [n] ?  \n\n");
					scanf("%s", &opcao_char);
					if (opcao_char == 's') {
						system("cls");
						goto editarpaciente;
					} else {
						goto cadPac;
					}
					break;
				case 4:
					excluirpaciente:
						
					excluirPaciente();
					system("pause");
					printf(" \n\nDeseja realizar uma nova exclusão [s] ou [n] ?  \n\n");
					scanf("%s", &opcao_char);
					if (opcao_char == 's') {
						system("cls");
						goto excluirpaciente;
					} else {
						goto cadPac;
					}
					break;		
				case 5:
					goto menuInicial;
					system("cls");
				}

		case 2:
		prontuarioinicio:
			
		system("cls");
		printf("\n\n\t\t\t\t\t******PRONTUÁRIOS******\n\n\n");
		printf("\t\t\t\tInserir [1]  Consultar [2]  Voltar [3]\n\n");
		printf(" Selecione uma opção: ");
		scanf("%d", &opcao_int);
		if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
			goto prontuarioinicio;
		}
	
			switch (opcao_int){
				case 1:
				cadastroprontuario:
				system("cls");	
				cadastroProntuario();
				printf("\n\nDeseja cadastrar um novo prontuário [s] [n]?");
				scanf("%s", &opcao_char);
				if(opcao_char == 's') {
					system("cls");
					goto cadastroprontuario;
				} else {
					system("cls");
					goto prontuarioinicio;	
					system("pause");
				}
				break;
		
				case 2:
					consultaprontuario:
					consultaProntuario();
					printf("\n\n\nDeseja consultar um novo prontuário [s] [n]?");
					scanf("%s", &opcao_char);
					if(opcao_char == 's'){
					system("cls");
					goto consultaprontuario;
					} else {
					system("cls");
					goto prontuarioinicio;	
					system("pause");
					}
					break;
				case 3:
					system("cls");
					goto menuInicial;
			}
			
		/*case 3:
		AGENDAR CONSULTAS

		case 4: RECLAMAÇÕES E ELOGIOS
		*/

		case 5:
			financeiro: //menu inicial financeiro
			
			system("cls");
			printf("\n\n\t\t\t\t\t\t\t*****FINANCEIRO*****\n\n");
			printf("\t\t\t\tCobrança [1]  Contas à pagar [2]  Voltar[3]\n\n");
			printf("Selecione uma opção: ");
			scanf("%d", &opcao_int);
			
			if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
				goto financeiro;
			}

			switch(opcao_int) {
				case 1:
					menuCobranca: //menu cobrancas
						
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t*****COBRANÇA*****\n\n");
					printf("\t\t\tInserir [1]  Consultar [2]  Voltar [3]\n\n");
					printf("Selecione uma opção: ");
					scanf("%d", &opcao_int);
						
					if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
						goto menuCobranca;
					}
						switch(opcao_int){
							case 1:
								cadastrocobranca:
									
								system("cls");
								cadastroCobranca();
								printf("\n\nDeseja inserir uma nova cobrança [s] [n]?");
								scanf("%s", &opcao_char);
								if(opcao_char == 's'){
								system("pause");
								system("cls");
								goto cadastrocobranca;
								}else{
								system("cls");
								goto menuCobranca;
								}
								break;
						
							case 2: 
								consultacobranca:
									
								system("cls");
								consultarCobranca();
								printf("\n\nDeseja realizar uma nova consulta [s] ou [n]? ");
								scanf("%s", &opcao_char);
								if(opcao_char == 's') {
								system("cls");
								goto consultacobranca;
								} else {
								system("cls");
								goto menuCobranca;	
								system("pause");
								}
								break;
							case 3:
								system("cls");
								goto menuCobranca;
								break;
						}
			
			case 2:
				pagamentos: //Tela de cadastro contas a pagar
				
				system("cls");
				printf("\n\n\t\t\t\t\t\t\t*****CONTAS A PAGAR*****\n\n");
				printf("\t\t\tInserir [1]  Consultar [2] Voltar [3]\n\n");
				printf("Selecione uma opção: ");
				scanf("%d", &opcao_int);
					
				if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
					goto pagamentos;
				}
				switch(opcao_int) {
					case 1:
						cadastrocontaspag: //cadastro de contas a pagar
						
						cadastroPagamento();
						printf("\n\nDeseja cadastrar uma nova conta? [s] ou [n] ? ");
						scanf("%s", &opcao_char);
						if(opcao_char == 's') {
							system("cls");
							goto cadastrocontaspag;
						} else {
							system("cls");
							goto pagamentos;
						}
							break;
					case 2:
						consultapagamentos:  //consulta contas a pagar
						
						system("cls");
						consultaPagamento();
						printf("\n\nDeseja realizar uma nova consulta [s] ou [n]? ");
						scanf("%s", &opcao_char);
						if(opcao_char == 's') {
							system("cls");
							goto consultapagamentos;
						} else {
							system("cls");
							goto pagamentos;
							system("pause");
						}
							break;			
					case 3:	
						system("cls");
						goto financeiro;
						break;
				}
			}
			
		//case 6: RECURSOS HUMANOS

		case 7:
			relatorios: //menu relatorios
				system("cls");
				printf("\n\n\t\t\t\t\t\t\t*****RELATÓRIOS*****\n\n");
				printf("\t\t\tFinanceiro [1]  Voltar [2]\n\n");
				printf("Selecione uma opção: ");
				scanf("%d", &opcao_int);
				
				if (opcao_int != 1 && opcao_int != 2) {
					goto relatorios;
				}
				
				switch(opcao_int) {
					case 1:
						relatoriofinanceiro:
							system("cls");
							printf("\n\n\t\t\t\t\t\t\t*****RELATÓRIO FINANCEIRO*****\n\n");
							printf("\t\t\tContas à pagar [1]  Contas à Receber [2]  Faturamento [3]  Voltar [4]\n\n");
							printf("Selecione uma opção: ");
							scanf("%d", &opcao_int);
						
							if (opcao_int != 1 && opcao_int != 2 && opcao_int != 3) {
								goto relatoriofinanceiro;
							}
							
							switch(opcao_int){
								case 1:
									relatorioContasPagar(PESQUISAR_UNIDADE);
									printf("\n\nDeseja gerar um novo relatório [s] ou [n]? ");
									scanf("%s", &opcao_char);
									if(opcao_char == 's'){
										system("cls");
										goto relatorios;
									} else {
										system("cls");
										goto menuInicial;
										system("pause");
									}	
										break;			
								case 2:
									relatorioContasReceber(PESQUISAR_UNIDADE);
									printf("\n\nDeseja gerar um novo relatório [s] ou [n]? ");
									scanf("%s", &opcao_char);
									if(opcao_char == 's'){
										system("cls");
										goto relatorios;
									} else {
										system("cls");
										goto menuInicial;
										system("pause");
									}
										break;
								case 3:
									relatorioFaturamento();
									printf("\n\nDeseja gerar um novo relatório [s] ou [n]? ");
									scanf("%s", &opcao_char);
									if(opcao_char == 's'){
										system("cls");
										goto relatorios;
									} else {
										system("cls");
										goto menuInicial;
										system("pause");
									}
									break;
								case 4:
									system("cls");
									goto relatorios;
						
							}	
				}
	}
}

void relatorioFaturamento() {
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t***RELATÓRIO DE FATURAMENTO ***\n\n");
	char unidade_inserida[2];
	printf("Insira a unidade: ");
	fflush(stdin);
	scanf("%s", &unidade_inserida);
	
	Pagamento *pagamentos = relatorioContasPagar(unidade_inserida);
	Cobranca *cobrancas = relatorioContasReceber(unidade_inserida);
	
	int total = 1000;
	float total_pag = 0;
	float total_cob = 0;
	
	for (int i = 0; i < total; ++i) {
		if (strcmp(pagamentos[i].valor, "") != 0) {
			total_pag += strtof(pagamentos[i].valor, NULL);
		} else {
			break;
		}
	  
	}
	
	for (int i =0; i < total; ++i) {
		if (strcmp(cobrancas[i].valor, "") != 0) {
	  		total_cob += strtof(cobrancas[i].valor, NULL);
		} else {
			break;
		}
	}
   
    printf("\n\n\t\t\t\t\t\t\t***RELATÓRIO DE FATURAMENTO ***\n\n");
    printf("Unidade (%s) ", unidade_inserida);
    printf("\nTOTAL CONTAS A PAGAR: %.2f", total_pag);
	printf("\nTOTAL CONTAS A RECEBER: %.2f", total_cob);
	
	printf("\nFATURAMENTO: %.2f", total_cob);
	printf("\nLUCRO: %.2f", (total_cob - total_pag));
}

Pagamento* relatorioContasPagar(char *unidade_inserida) {
	system("cls");
	FILE *arquivo_pagamentos = fopen(ARQUIVO_PAGAMENTOS, "r");
	
	char unidade_aux[100];
	if (strcmp(unidade_inserida, PESQUISAR_UNIDADE) == 0) {
		printf("\n\n\t\t\t\t\t\t\t***RELATÓRIO DE CONTAS A PAGAR***\n\n");
		
		printf("Insira a unidade: ");
		fflush(stdin);
		scanf("%s", &unidade_aux);
	}
	
	char linha[250];
	fflush(stdin);
	struct Pagamento pagamentos[1000];
	
	int i = 0;
	while(fscanf(arquivo_pagamentos,"%s", linha) != EOF) {
		char *unidade = strtok(linha, ";");
		char *tipo = strtok(NULL, ";");
		char *valor = strtok(NULL, ";");
		char *data = strtok(NULL, ";");
		char *observacoes = strtok(NULL, ";");
		
		tipo = substituir(tipo, ESPACO, TRACO);
		observacoes = substituir (observacoes, ESPACO, TRACO);
	 	   	
		if(strcmp(unidade_inserida, unidade) == 0 
			|| strcmp(unidade_aux, unidade) == 0) { //busca de contas no arquivo arquivo_contas_pagar
			
			if (strcmp(unidade_aux, "") != 0) {
				printf("\nTipo de Cobrança:%s\nValor: R$%s\nData de vencimento:%s\nObservações:%s\n\n", tipo, valor, data, observacoes);
			}
			Pagamento pagamento = {0};
			strcpy(pagamento.tipo, tipo);
			strcpy(pagamento.valor, valor);
			strcpy(pagamento.data, data);
			strcpy(pagamento.observacoes, observacoes);
			pagamentos[i++] = pagamento;
		}
	}
	
	fclose(arquivo_pagamentos);
	return pagamentos;
	system("pause");
}

Cobranca* relatorioContasReceber(char *unidade_inserida) {
	system("cls");
	FILE *arquivo_cobranca = fopen(ARQUIVO_COBRANCA, "r");
	char unidade_aux[100];
	if (strcmp(unidade_inserida, PESQUISAR_UNIDADE) == 0) {
		printf("\n\n\t\t\t\t\t\t\t***RELATÓRIO DE CONTAS A RECEBER***\n\n");
		printf("Insira a unidade: ");
		fflush(stdin);
		scanf("%s", &unidade_aux);
	}
	
	char linha[250];
	fflush(stdin);
	struct Cobranca cobrancas[1000];
	
	int i = 0;
	
	while(fscanf(arquivo_cobranca,"%s", linha) != EOF) {
		char *unidade = strtok(linha, ";");
		char *nome_especialidade = strtok(NULL, ";");
		char *valor = strtok(NULL, ";");
		char *data = strtok(NULL, ";");
		char *forma_pag = strtok(NULL, ";");
		   	
		if(strcmp(unidade, unidade_inserida) == 0 || strcmp(unidade_aux, unidade) == 0) { //busca de cobranca no arquivo cobranca
			if (strcmp(unidade_aux, "") != 0 ) {
				printf("\nEspecialidade:%s\nValor da consulta: R$%s\nData de pagamento:%s\nOpção de pagamento (Débito [1] Crédito [2] Dinheiro [3]):%s\n\n",
				nome_especialidade, valor, data, forma_pag);
			}
			Cobranca cobranca = {0};
			strcpy(cobranca.nome_especialidade, nome_especialidade);
			strcpy(cobranca.valor, valor);
			strcpy(cobranca.data, data);
			strcpy(cobranca.forma_pag, forma_pag);
			fflush(stdin);
			cobrancas[i++] = cobranca;
		}
	}
	
	fclose(arquivo_cobranca);
	return cobrancas;
	system("pause");
}

void cadastrarPaciente() {
	system("cls");
	printf("\n\n\t\t\t\t\t****** Cadastro de Pacientes******\n\n\n");
	fflush(stdin);
	char nome[50];
	printf(" Nome do Paciente: ");
	scanf(STR_ESPACO, &nome);
	printf(" CPF do Paciente: ");
	fflush(stdin);
	char cpf[11];
	scanf("%s", &cpf);
	printf(" RG do Paciente: ");
	fflush(stdin);
	char rg[20];
	scanf("%s", &rg);
	printf(" Telefone do Paciente: ");
	fflush(stdin);
	char telefone[20];
	scanf(STR_ESPACO, &telefone);
	fflush(stdin);
	char endereco[300];
	printf(" Endereço do Paciente: ");
	scanf(STR_ESPACO, &endereco);
	FILE *arquivo_paciente = fopen(ARQUIVO_PACIENTES, "a");
	
	fprintf(arquivo_paciente, "%s;%s;%s;%s;%s\n", cpf, rg, 
		substituir(telefone, TRACO, ESPACO), 
		substituir(nome, TRACO, ESPACO), 
		substituir(endereco, TRACO, ESPACO));
	fclose(arquivo_paciente);	
}

void editarPaciente() {
	editarPact:
		//consulta o paciente
		struct Paciente paciente = consultarPaciente();
		
		//verifica se o paciente está cadastrado
		if (strcmp(paciente.cpf, CPF_INEXISTENTE) == 0) {
			printf(MSG_PCT_NAO_ENCONTRADO);
			system("pause");
			goto editarPact;
			
		} else {
			system("cls");
			printf("\n\n\t\t\t\t\t******Editar Paciente******\n\n\n");
			fflush(stdin);
			char nome[50];
			printf(" Nome do Paciente (%s): ", paciente.nome);
			scanf(STR_ESPACO, &nome);
			printf(" CPF do Paciente (%s): ", paciente.cpf);
			fflush(stdin);
			char cpf[11];
			scanf("%s", &cpf);
			printf(" RG do Paciente (%s): ", paciente.rg);
			fflush(stdin);
			char rg[20];
			scanf("%s", &rg);
			printf(" Telefone do Paciente (%s): ", paciente.telefone);
			fflush(stdin);
			char telefone[20];
			scanf(STR_ESPACO, &telefone);
			fflush(stdin);
			char endereco[300];
			printf(" Endereço do Paciente (%s): ", paciente.endereco);
			scanf(STR_ESPACO, &endereco);
			//busca todos os pacientes e insere em um array
			Paciente *pacientes = todosPacientes();
			//verifica qual é a posição do paciente no array pelo cpf
			int idx = consultarIdxPaciente(pacientes, paciente.cpf);
			
			pacientes[idx] = {0};
			//n-a = excluido, ou seja, seta todas as informações com n-a
			strcpy(pacientes[idx].cpf, cpf); 
			strcpy(pacientes[idx].nome, substituir(nome, TRACO, ESPACO)); 
			strcpy(pacientes[idx].rg, substituir(rg, TRACO, ESPACO)); 
			strcpy(pacientes[idx].endereco, substituir(endereco, TRACO, ESPACO));
			strcpy(pacientes[idx].telefone, substituir(telefone, TRACO, ESPACO)); 
			atualizarTodosPacientes(pacientes);
			printf("\n\n Paciente atualizado com sucesso! \n\n ");
		}
}

void excluirPaciente() {
	excluirPact:
		//consulta o paciente
		struct Paciente paciente = consultarPaciente();
		
		//verifica se o paciente está cadastrado
		if (strcmp(paciente.cpf, CPF_INEXISTENTE) == 0) {
			printf(MSG_PCT_NAO_ENCONTRADO);
			system("pause");
			goto excluirPact;
			
		} else {
			//busca todos os pacientes e insere em um array
			Paciente *pacientes = todosPacientes();
			//verifica qual é a posição do paciente no array pelo cpf
			int idx = consultarIdxPaciente(pacientes, paciente.cpf);
			//limpa os dados da struct
			pacientes[idx] = {0};
			//n-a = excluido, ou seja, seta todas as informações com n-a
			strcpy(pacientes[idx].cpf, "n-a"); 
			strcpy(pacientes[idx].nome, "n-a"); 
			strcpy(pacientes[idx].rg, "n-a"); 
			strcpy(pacientes[idx].endereco, "n-a");
			strcpy(pacientes[idx].telefone, "n-a"); 
			atualizarTodosPacientes(pacientes);
			printf("\n\n Paciente excluído com sucesso! \n\n ");
		}
			
}

void atualizarTodosPacientes(Paciente *pacientes) {
	//limpa o arquivo		
	FILE *arquivo = fopen(ARQUIVO_PACIENTES, "w");
	fprintf(arquivo, "%s", "");
	fclose(arquivo);
	
	//abre novamente em modo append, para inserir linnha por linha do array
	arquivo = fopen(ARQUIVO_PACIENTES, "a");
	fflush(stdin);
	
	//no maximo 1000 registros de paciente
	for (int i = 0; i < 1000; ++i) {
		Paciente paciente = pacientes[i];
		//verifica se o cpf está vazio, pois é o fim do arquivo
		if (strcmp(paciente.cpf, "") == 0) {
			break;
		}
		
		//gambiarra pra fazer funcionar a escrita do cpf
		strcat(paciente.cpf, "");
		//salva novamente os dados no arquivo linha por linha, inclusive com o paciente com os dados n-a
		fprintf(arquivo, "%s;%s;%s;%s;%s\n", 
				paciente.cpf, 
				paciente.rg, 
				paciente.telefone, 
				paciente.nome, 
				paciente.endereco);
	}
	
	fclose(arquivo);
}


int consultarIdxPaciente(Paciente *pacientes, char *cpf_consultado) {
	for (int i = 0; i < 1000; ++i) {
		if (strcmp(pacientes[i].cpf, cpf_consultado) == 0) {
		  return i;
		}
	}
	return -1;
}

Paciente* todosPacientes() {
	FILE *arquivo_paciente = fopen(ARQUIVO_PACIENTES, "r");
	Paciente pacientes[1000];
	int i = 0;
	char linha[250];
	while (fscanf(arquivo_paciente, "%s", linha) != EOF) {
		char *cpf = strtok(linha, ";");
		char *rg = strtok(NULL, ";");
		char *telefone = strtok(NULL, ";");
		char *nome = strtok(NULL, ";");
		char *endereco = strtok(NULL, ";");
		
		Paciente paciente = {0};
		strcpy(paciente.cpf, cpf);
		strcpy(paciente.rg, rg);
		strcpy(paciente.telefone, telefone);
		strcpy(paciente.nome, nome);
		strcpy(paciente.endereco, endereco);
		pacientes[i++] = paciente;
	}
	
	fclose(arquivo_paciente);
	return pacientes;
}


Paciente consultarPaciente() {
	system("cls");
	printf("\n\n\t\t\t\t\t******CONSULTAR PACIENTE******\n\n\n");
	FILE *arquivo_paciente = fopen(ARQUIVO_PACIENTES, "r");
	struct Paciente paciente = {0};
	printf("Digite o CPF do Paciente: ");
	fflush(stdin);
	char cpf_inserido[12];
	scanf("%s", &cpf_inserido);
	char linha[250];
	bool paciente_encontrado = false;
	fflush(stdin);
	strcpy(paciente.cpf, CPF_INEXISTENTE);
	
	while (fscanf(arquivo_paciente, "%s", linha) != EOF) {
		char *cpf = strtok(linha, ";");
		char *rg = strtok(NULL, ";");
		char *telefone = strtok(NULL, ";");
		char *nome = strtok(NULL, ";");
		char *endereco = strtok(NULL, ";");
		
		telefone = substituir(telefone, ESPACO, TRACO);
		nome = substituir(nome, ESPACO, TRACO);
		endereco = substituir(endereco, ESPACO, TRACO);
		
		if(strcmp(cpf_inserido, cpf) == 0) {
			printf("NOME: %s\nCPF: %s\nRG: %s\nTelefone: %s\nEndereço: %s\n", nome, cpf, rg, telefone, endereco);
			strcpy(paciente.cpf, cpf);
			strcpy(paciente.rg, rg);
			strcpy(paciente.telefone, telefone);
			strcpy(paciente.nome, nome);
			strcpy(paciente.endereco, endereco);
			
			fclose(arquivo_paciente);
			break;
		}
	}	
	return paciente;
}

void cadastroProntuario() {
	system("cls");		
	printf("\n\n\t\t\t\t\t******CADASTRAR PRONTUÁRIO******\n\n\n");
	cadastroPront:
		struct Paciente paciente = consultarPaciente();
		if (strcmp(paciente.cpf, CPF_INEXISTENTE) == 0 ) {
	 		printf(MSG_PCT_NAO_ENCONTRADO);
	 		system("pause");
	 		goto cadastroPront;
	 		
		} else {
			printf("\n\nDescrição da consulta: ");
			fflush(stdin);
			char descricao[800];
			scanf(STR_ESPACO, &descricao);
			
			printf("\nData: ");
			fflush(stdin);
			char data[11];
			scanf("%s", &data);
			
			FILE *arquivo_prontuario = fopen(ARQUIVO_PRONTUARIO, "a");
			fprintf(arquivo_prontuario, "%s;%s;%s\n", paciente.cpf, data, substituir(descricao, TRACO, ESPACO));
			printf("Prontuário salvo com sucesso!\n");
			fclose(arquivo_prontuario);
			system("pause");
		}
}

void consultaProntuario() {
	system("cls");	
	printf("\n\n\t\t\t\t\t******CONSULTAR PRONTUÁRIOS******\n\n\n");
	struct Prontuario prontuario = {0};
	consultaPront: 
		struct Paciente paciente = consultarPaciente();
		if (strcmp(paciente.cpf, CPF_INEXISTENTE) == 0 ) {
	 		printf(MSG_PCT_NAO_ENCONTRADO);
	 		system("pause");
	 		goto consultaPront;
		} else {
			printf("\n\n\t\t\t\t\t******Prontuários do paciente******\n\n\n");
			FILE *arquivo_prontuario = fopen(ARQUIVO_PRONTUARIO, "r");
			char linha[1000];
			while(fscanf(arquivo_prontuario,"%s", linha) != EOF) {
				char *cpf = strtok(linha, ";");
				char *data = strtok(NULL, ";");
				char *descricao = strtok(NULL, ";");
				
				descricao = substituir(descricao, ESPACO, TRACO);
				   	
				if(strcmp(paciente.cpf, cpf) == 0) {
					printf("\n\nData: %s", data);
					printf("\n\nDescrição do atendimento: %s", descricao);
				}
			}
			
			fclose(arquivo_prontuario);
		}
}


void cadastrarUsuario() {
	system("cls");
	FILE *arquivo_usuario = fopen(ARQUIVO_USUARIOS, "a");
	printf("\n\n\t\t\t\t\t\t\t*****CADASTRO NOVO USUÁRIO*****\n\n");	
	printf("Nome Completo: ");
	char nome[50];
	fflush(stdin);
	scanf(STR_ESPACO, &nome);
	printf("\nDigite o RG: ");
	char rg[20];
	fflush(stdin);
	scanf("%s", &rg);
	printf("\nDigite seu E-mail: ");
	char email[50];
	fflush(stdin);
	scanf("%s", &email);
	printf("\n\n\t\t\t\t\t\t*****Selecione o Nível do Usuário*****\n\n\n");
	printf("[1] Diretoria			[2] Administrativo			[3] Atendimento			[4]Médico \n\n\n");
	printf("Nível do usuário: ");
	int nivel;
	fflush(stdin);
	scanf("%d", &nivel);
	printf("\n\n\n\t\t\t\t\t\t***Cadastro Login e Senha***\n\n\n");
	printf("Insira o Login/CPF: ");
	char cpf[20];
	fflush(stdin);
	scanf("%s", &cpf);
	printf("Insira a senha de 6 dígitos:");
	char senha[6];
	fflush(stdin);
	scanf("%s", &senha);
	fprintf(arquivo_usuario, "%s;%s;%s;%s;%d;%s\n", cpf, senha, email, rg, nivel, nome);

	printf("\n\nUsuário cadastrado com sucesso!\n\n");
	fclose(arquivo_usuario);
}


Usuario loginUsuario() {
	system("cls");
	FILE *arquivo_usuario = fopen(ARQUIVO_USUARIOS, "r");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\t*****LOGIN*****\n\n\n\n\n");
	printf("Insira seu CPF: ");
	char cpf_inserido[11];
	scanf("%s", &cpf_inserido);
	printf("Senha de 6 dígitos: ");
	char senha_inserida[6];
	for (int i=0; i < 6; i++){
		senha_inserida[i]=getch();
		printf("*");
	}
	
	char linha[250];
	struct Usuario usuario = {0};
	usuario.nivel = -1;
	
	while (fscanf(arquivo_usuario, "%s", linha) != EOF) {
		char *cpf = strtok(linha, ";");
		char *senha = strtok(NULL, ";");
		char *email = strtok(NULL, ";");
		char *rg = strtok(NULL, ";");
		char *nivel = strtok(NULL, ";");
		char *nome = strtok(NULL, ";");

		if (strcmp(cpf, cpf_inserido) == 0 && strcmp(senha, senha_inserida) == 0)
		{
			printf("\n\n\t\t\t\t\t***Login realizado com sucesso!***\n\n\n");
			
			strcpy(usuario.cpf, cpf);
			strcpy(usuario.email, email);
			strcpy(usuario.rg, rg);
			char nivelChar[1];
			strcpy(nivelChar, nivel);
			usuario.nivel = (int) nivelChar[0] - 48;
			strcpy(usuario.nome, nome);
			break;
		}
	}
	
	fclose(arquivo_usuario);
	return usuario;
}


int recuperarSenha() {
	printf("\n\n\t\t\t\t\t\t*****RECUPERAÇÃO DE SENHA*****\n\n\n\n\n");
	fflush(stdin);
	printf(" Insira seu CPF: ");
	fflush(stdin);
	char cpf_inserido[11];
	scanf("%s", &cpf_inserido);
	fflush(stdin);
	char linha[100];
	FILE *arquivo_usuario = fopen(ARQUIVO_USUARIOS, "r");
	while (fscanf(arquivo_usuario, "%s", linha) != EOF) {
		char *cpf = strtok(linha, ";");

		if (strcmp(cpf, cpf_inserido) == 0) {
			printf("\t\t\t\t\t\t*** E-mail enviado com sucesso! ***");
			fclose(arquivo_usuario);
			return 1;
		}
	}
	
	fclose(arquivo_usuario);
	return 0;
}

void cadastroPagamento() {
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t****INSERIR****\n\n");
	printf("\nUnidade (1, 2 ou 3):");
	fflush(stdin);
	int unidade;
	scanf("%d", &unidade);
	printf("\nTipo de Cobrança:");
	fflush(stdin);
	char tipo[30];
	scanf(STR_ESPACO, &tipo);
	printf("\nValor à pagar: R$");
	fflush(stdin);
	char valor[15];
	scanf(STR_ESPACO, &valor);
	printf("\nData de vencimento (DD/MM/AAA):");
	fflush(stdin);
	char data[11];
	scanf("%s", &data);
	printf("\nObservações: ");
	fflush(stdin);
	char observacoes[100];
	scanf(STR_ESPACO, &observacoes);
	FILE *arquivo_contas_pagar = fopen(ARQUIVO_PAGAMENTOS, "a");
	fprintf(arquivo_contas_pagar,"%d;%s;%s;%s;%s\n",
		unidade,
		substituir(tipo, TRACO, ESPACO), 
		valor, 
		data, 
		substituir(observacoes, TRACO, ESPACO));
	fclose(arquivo_contas_pagar);
	printf("Conta cadastrada com sucesso!\n\n");
}


void consultaPagamento() {
	system("cls");
	FILE *arquivo_pagamentos = fopen(ARQUIVO_PAGAMENTOS, "r");
	struct Pagamento pagamento = {0};
	printf("\n\n\t\t\t\t\t\t\t*****CONSULTA DE CONTAS A PAGAR*****\n\n");
	printf("Insira a data que deseja consultar (DD/MM/AAAA):");
	char data_inserida[11];
	fflush(stdin);
	scanf("%s", &data_inserida);
	char linha[250];
	fflush(stdin);

	while(fscanf(arquivo_pagamentos,"%s", linha) != EOF) {
		char *unidade = strtok(linha, ";");
		char *tipo = strtok(NULL, ";");
		char *valor = strtok(NULL, ";");
		char *data = strtok(NULL, ";");
		char *observacoes = strtok(NULL, ";");
		
		tipo = substituir(tipo, ESPACO, TRACO);
		observacoes = substituir (observacoes, ESPACO, TRACO);
		   	
		if(strcmp(data_inserida, data) == 0 ) { //busca de contas no arquivo arquivo_contas_pagar
			printf("\nUnidade:%s\nTipo de Cobrança:%s\nValor: R$%s\nData de vencimento:%s\nObservações:%s\n\n", 
			unidade, tipo, valor, data, observacoes);
		}
	}
	
	fclose(arquivo_pagamentos);
}

void cadastroCobranca() {
	printf("\n\n\t\t\t\t\t\t*****CADASTRO DE COBRANÇA*****\n\n");
	printf("\nUnidade (1, 2 ou 3):");
	fflush(stdin);
	int unidade;
	scanf("%d", &unidade);
	printf("\nInforme a especialidade: ");
	char nome_especialidade[50];
	fflush(stdin);
	scanf("%s", &nome_especialidade);
	printf("\nData do pagamento (DD/MM/AAAA):");
	char data_inserida[20];
	fflush(stdin);
	scanf("%s", &data_inserida);
	printf("\nInforme o valor da consulta %s : R$", nome_especialidade);
	char valor_consulta[20];
	fflush(stdin);
	scanf("%s", &valor_consulta);
	printf("\n\nForma de pagamento Débito [1] Crédito [2] Dinheiro [3]: ");
	int forma_pag;
	fflush(stdin);
	scanf("%d", &forma_pag);
	FILE *arquivo_cobranca = fopen(ARQUIVO_COBRANCA, "a");
	fprintf(arquivo_cobranca,"%d;%s;%s;%s;%d\n", unidade, nome_especialidade, valor_consulta, data_inserida, forma_pag);
	fclose(arquivo_cobranca);
	printf("Cobrança realizada com sucesso!");
}

void consultarCobranca() {
	FILE *arquivo_cobranca = fopen(ARQUIVO_COBRANCA, "r");
	struct Cobranca cobranca = {0};
	printf("\n\n\t\t\t\t\t\t\t*****CONSULTA DE COBRANÇA*****\n\n");
	printf("Insira a data que deseja consultar (DD/MM/AAAA):");
	fflush(stdin);
	char data_inserida[20];
	scanf("%s", &data_inserida);
	char linha[250];
	fflush(stdin);
	
	while(fscanf(arquivo_cobranca,"%s", linha) != EOF) {
		char *unidade = strtok(linha, ";");
		char *nome_especialidade = strtok(NULL, ";");
		char *valor_consulta = strtok(NULL, ";");
		char *data = strtok(NULL, ";");
		char *forma_pag = strtok(NULL, ";");
		   	
		if(strcmp(data, data_inserida) == 0 ) { //busca de cobranca no arquivo cobranca
			printf("\nUnidade:%s\nEspecialidade:%s\nValor da consulta: R$%s\nData de pagamento:%s\nOpção de pagamento (Débito [1] Crédito [2] Dinheiro [3]):%s\n\n", 
			unidade, nome_especialidade, valor_consulta, data_inserida, forma_pag);
		}
	}
}
	

//Referência -> https://www.geeksforgeeks.org/c-program-replace-word-text-another-given-word/
char* substituir(const char* s,
                  const char* newW, const char* oldW) { 
    char* result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) { 
        if (strstr(&s[i], oldW) == &s[i]) { 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        } 
    } 
  
    // Making new string of enough length 
    result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s) { 
        // compare the substring with the result 
        if (strstr(s, oldW) == s) { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
} 

