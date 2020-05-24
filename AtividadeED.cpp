#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Estruturas.h"

#define MAXalun 40

struct aluno{
	char nome[20];
	int code;
	char disciplina[20];
	float notas[3];
	float media;
}Aluno[MAXalun];

int info(int indAlun), alterar(int indAlun, int opt);
void cadastro(int indAlun);

main() {
	setlocale(LC_ALL, "portuguese");
	Stack *p = (Stack*)malloc(sizeof(Stack));
	ini(p);
	int opt, indAlun=0;
	float soma;
	char m[20];
	
	do{
		system("color F1");
		system("cls");
		printf("|------------ MENU PRINCIPAL ------------|");
		printf("\n\n[1] - Cadastrar aluno(a)  [%d/40]", indAlun);
		printf("\n[2] - Cadastrar discipina");
		printf("\n[3] - Lançar nota");
		printf("\n[4] - Alterar nota");
		printf("\n[5] - Visualizar informações");
		printf("\n[0] - Sair");
		printf("\n\nSua opção: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 1:
				do{
					system("cls");
					
					cadastro(indAlun);
					
					printf("\n\n[1] - Recadastrar aluno\n[2] - Voltar ao menu principal\nSua opção: ");
					scanf("%d", &opt);
					indAlun++;
				}while(opt == 1);
				break;
			
			case 2:
				do{
					system("cls");
					
					printf("\n\nNome da matéria: ");
					fflush(stdin);
					gets(m);
					push(p, m);
					
					system("pause > null");
					system("cls");
					
					printf("\n\nVocê cadastrou a matéria %s", m);
					printf("\n\n[1] - Cadastrar nova Matéria\n[2] - Voltar ao menu principal\nSua opção: ");
					scanf("%d", &opt);
				}while(opt == 1);
				break;
			
			case 3:
				do{
					system("cls");
					
					if(indAlun < 1) {
						printf("Erro! nenhum aluno cadastrado...\nFechando programa");
						return -1
					}
					
					float soma = 0;
					int optAlun, optMater;
						
					printf("\nEscolha o aluno que deseja lançar a nota\n\n");
					printf("\nNome\t\t\t");
					printf("Cod");
					for(int i=0; i<indAlun; i++) {
						printf("\n%d. %s\t\t", i+1, Aluno[i].nome);
						printf("%d", Aluno[i].code);
					}
					printf("\n\nSua opção: ");
					scanf("%d", &optAlun);
						
					system("pause > null");
					system("cls");
						
					printf("\n\nEscolha uma matéria para lançar as notas do aluno(a) %s\n\n", Aluno[optAlun-1]);
					show(p);
					printf("\nSua opção: ");
					scanf("%d", &optMater);
						
					strcpy(Aluno[optAlun-1].disciplina, p->item[optMater-1]);
						
					system("pause > null");
					system("cls");
						
					for(int i=0; i<3; i++) {
						printf("\nAv%d: ", i+1);
						scanf("%f", &Aluno[optAlun-1].notas[i]);
						soma += Aluno[optAlun-1].notas[i];
					}
									
					Aluno[optAlun-1].media = soma/3;
								
					system("pause>null");
					
					printf("\n\n[1] - Relançar notas\n[2] - Voltar ao menu principal\nSua opção: ");
					scanf("%d", &opt);
				}while(opt == 1);
				break;
				
			case 4:
				do{
					system("cls");
					alterar(indAlun, opt);
					
					system("pause > null");
					system("cls");
					
					printf("\n\n[1] - Alterar a nota de outro aluno\n[2] - Voltar ao menu principal\nSua opção: ");
					scanf("%d", &opt);
				}while(opt == 1);
				break;
			
			case 5:
				do{
					info(indAlun);
					
					printf("\n\n[1] - Voltar ao menu: ");
					scanf("%d", &opt);
				}while(opt != 1);
				break;
			
			default:
				printf("Essa opção não é válida!");
		}
	}while(opt != 0);
	
	system("cls");	
	printf("\n\nSaindo...");
	free(p);
	system("pause > null");
}

void cadastro(int indAlun) {
	if(indAlun >= 40) {
		system("color F4");
		printf("Sala lotada");
		return -1;
	}
	
	printf("\n\nNome do aluno(a): ");
	fflush(stdin);
	gets(Aluno[indAlun].nome);
					
	printf("Insira um código para %s: ", Aluno[indAlun].nome);
	scanf("%d", &Aluno[indAlun].code);
					
}

int alterar(int indAlun, int opt) {
	if(indAlun < 1) {
		system("color F4");
		printf("Erro! Nenhum aluno cadastrado...");
		return -1;
	}
	
	float soma;
	int optAlun, optAlter;
	
	printf("\n\nDeseja mudar as notas de qual aluno?");
					
	printf("\nNome\t\t\t");
	printf("Cod\t\t");
	printf("Av1 \t ");
	printf("Av2 \t ");
	printf("Av3 \t ");
	printf("Media \t   ");
	printf("Disciplina");
	for(int i=0; i<indAlun; i++) {
		printf("\n%d. %s\t\t", i+1, Aluno[i].nome);
		printf("%d\t\t", Aluno[i].code);
		printf("%.1f \t %.1f \t %.1f \t %.1f \t   ", Aluno[i].notas[0], Aluno[i].notas[1], Aluno[i].notas[2], Aluno[i].media);
		printf("%s", Aluno[i].disciplina);
	}
	printf("\nSua opção: ");
	scanf("%d", &optAlun);
					
	system("pause > null");
					
	while(opt != 0) {
		system("cls");
						
		soma = 0, optAlter;
						
		printf("Aluno: %s\n\n", Aluno[optAlun-1].nome);
		for(int i=0; i<3; i++)
		printf("Av%d. %.1f\n", i+1, Aluno[optAlun-1].notas[i]);
						
		printf("\n\nNota que deseja mudar: ");
		scanf("%d", &optAlter);
						
		printf("\n\nDigite uma nova nota para Av%d: ", optAlter);
		scanf("%f", &Aluno[optAlun-1].notas[optAlter-1]);
						
		for(int i=0; i<3; i++) 
			soma += Aluno[optAlun-1].notas[i];
						
		Aluno[optAlun-1].media = soma/3;
						
		system("pause > null");
		system("cls");
						
		printf("Deseja mudar outra nota de %s?\n", Aluno[optAlun-1].nome);
		printf("\n[1] - Sim\n[0] - Não\nSua opção: ");
		scanf("%d", &opt);
	}
}

int info(int indAlun) {
 	system("cls");
					
	if(indAlun < 1) {
		system("color F4");
		printf("Erro! nenhum aluno registrado");
		return -1;
	}
					
	printf("\nNome\t\t\t");
	printf("Cod\t\t");
	printf("Av1 \t ");
	printf("Av2 \t ");
	printf("Av3 \t ");
	printf("Media \t   ");
	printf("Disciplina");
	for(int i=0; i<indAlun; i++) {
		printf("\n%d. %s\t\t", i+1, Aluno[i].nome);
		printf("%d\t\t", Aluno[i].code);
		printf("%.1f \t %.1f \t %.1f \t %.1f \t   ", Aluno[i].notas[0], Aluno[i].notas[1], Aluno[i].notas[2], Aluno[i].media);
		printf("%s", Aluno[i].disciplina);
	}
}


