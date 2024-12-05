#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Observações:
// - o vetor de alunos deve ser alocado dinamicamente, com a dimensão inicial 10, através de uma função;
// - deve haver uma função para realocar o vetor de alunos, aumentando sempre a dimensão em 10, toda vez que o vetor for preenchido completamente;
// - o vetor de compromissos deve ser alocado dinamicamente, com a dimensão inicial 15, através de função;
// - deve haver uma função para realocar o vetor de compromissos, aumentando sempre a dimensão em 5, toda vez que o vetor for preenchido completamente;
// - utilizar a função qsort (disponível em stdlib.h), para reallizar ordenação de vetores.


// 1 - uma struct para armazenar data:
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// 2 - uma struct para armazenar horário:
typedef struct {
    int hora;
    int min;
} Hora;

// 3 - uma struct para armazenar dados de disciplina:
typedef struct{
    int codigo_dis;
    char disciplina[100];
    float notas[4];
    float media;
} Disciplina;

// 4 - uma struct para armazenar dados de aluno:
typedef struct {
    int ra;
    char nome[100];
    Data matrícula;
    Disciplina disciplinas[4];
    char email[100];
} Aluno;

//5 - uma struct para armazenar dados de compromisso:
typedef struct {
    Aluno aluno;
    Hora horario;
    Data data;
    char descricao[300];
} Compromisso;

//----------------------------- /
//**************************** */
//     FUNÇÕES DO PROGRAMA      /
//**************************** */
//----------------------------- /

//----------------//
// CADASTRAMENTOS //
//----------------//


void cadastraDisciplina(Disciplina *disciplinas[]){

}



// CADASTRAR ALUNO, sendo:
//   a - um aluno deve cursar ao menos 4 disciplinas
//   b - para cada disciplina deve haver 4 notas, com o respectivo cálculo da sua média
// //recebe um vetor do tipo td_aluno e sua dimensão
void cadastraAluno(Aluno *aluno[], int d){
    int i;
    for(i=0; i<d; i++){
        printf("-------------Cadastramento de Aluno--------");
        printf("\nAluno %d...", i+1);
        printf("\nRA: ");
        scanf("%i", &aluno[i].ra);
        printf("\nNome: ");
        fgets(aluno[i].nome, sizeof(aluno[i].nome), stdin);
        leData(aluno[i].matricula);
        cadastraDisciplina(aluno[i]->disciplinas);
        printf("Qual o email do aluno? ");
        verificaEmail(fgets(aluno[i]->email, sizeof(aluno[i]->email), stdin));
        printf("\n\n-----------------------------------------------");
        system("cls");


    }
}

// CADASTRAR COMPROMISSO //
//   a - um aluno não pode ter mais do que dois compromissos cadastrados na mesma data
//   b - caso um aluno possua dois compromissos na mesma data, os horários não podem estar sobrepostos/coincidentes
//recebe um vetor do tipo td_compromisso e sua dimensão


void cadastraCompromisso(Compromisso *comp[], int d){
    int i;
    for(i=0; i<d; i++){
        printf("-------------Cadastramento de Compromisso--------");
        printf("\n\nCOMPROMISSO %d...", i+1);
        leData(&comp[i].data);
        leHorario(&comp[i].horario);
        printf("\nDescreva: ");
        fgets(comp[i].descricao, sizeof(comp[i].descricao), stdin);
        printf("\n\n-----------------------------------------------");
        system("cls");
        // Falta o Atributo Aluno aluno de Compromisso
    }
}


//--------------//
// VERIFICAÇÕES //
//--------------//


// VALIDAR DATA - não deve ser permitido o cadastro de uma data que não seja válida
//recebe um ponteiro para a struct td_data, que irá apontar para a data de matrícula na struct td_aluno
int verificaData(Data *data){
	// retorna 1 para data correta e 0 pra incorreta
	if (data->ano <= 0) // se o ano for negativo retorna 0
		return 0; 
	else if (data->dia < 1 || data->dia > 31) // se o dia nao estiver entre 1 e 31 retorna 0
		return 0; 
	else if (data->mes < 1 || data->mes > 12) // se o mês nao estiver entre 1 e 12 retorna 0
		return 0; 
	else if ((data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11) && data->dia == 31) //retorna 0 caso coloque que um mês que não tem 31 dias tem mais que 30 dias
		return 0; 
	else if (data->mes == 2 && data->dia > 29) // retorna 0 caso coloque que fevereiro tem mais que 28 dias
		return 0; 
	else if (data->mes == 2 && data->dia == 29 && ((data->ano % 4 != 0) || (data->ano % 100 == 0 && data->ano % 400 != 0))) // considera ano bissexto
		return 0; 
	else
		return 1; // caso nenhum dos casos anteriores for verdadeiro (é um data válida), retorna 1 
}

// VALIDAR HORA - não deve ser permitido o cadastro de um horário que não seja válido
//recebe um ponteiro para a struct td_hora, que irá apontar para o horário do compromisso
int verificaHorario(Hora *horario){
	// retorna 1 para hora correta e 0 para incorreta
	if(horario->hora < 0 && horario->min < 0) // retorna 0 se a hora ou minuto for negativo
		return 0; 
	else if (horario->hora > 23) // returna 0 se a hora for maior que 23
		return 0; 
	else if (horario->min > 59) // retorna 0 se os minutos forem maiores que 59
		return 0;
	else
		return 1; // caso nenhum dos casos anteriores for verdadeiro (é uma horário válido), retorna 1
}

int verificaEmail(char email){

    return 1;
}


// GOTOXY //
// vai pra linhas e colunas especificas 
// Usado em leHorario() e leData()
void gotoxy(int x, int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

//----------//
// LEITURAS //
//----------//

//recebe um ponteiro para a struct td_hora, que irá apontar para o horário do compromisso
void leHorario(Hora *horario){
	char hora[3], min[3];
	int i, linha = 5;
	int colunas[] = {1, 10, 13};
	do{
		gotoxy(colunas[0], linha);
		printf("Horario:   :  "); 
		gotoxy(colunas[1], linha);
		for(i = 0; i <= 1; i++)
			hora[i] = getche();
		hora[i] = '\0';
		horario->hora = atoi(hora);
		gotoxy(colunas[2], linha);
		for(i = 0; i <= 1; i++)
			min[i] = getche();
		min[i] = '\0';
		horario->min = atoi(min);
	}while(!(verificaHorario(horario)));
}

//recebe um ponteiro para a struct data, que irá apontar para a data de matrícula na struct td_aluno
void leData(Data *data){
    char dia[3], mes[3], ano[5];
    int i, linha = 4;
    int colunas[] = {1, 7, 10, 13};
    do{
        gotoxy(colunas[0], linha);
        printf("Data:   /  /    ");
        gotoxy(colunas[1], linha);
        for(i = 0; i <= 1; i++)
            dia[i] = getche();
        dia[i] = '\0'; 
        data->dia = atoi(dia);
        gotoxy(colunas[2], linha);
        for(i = 0; i <= 1; i++)
            mes[i] = getche();
        mes[i] = '\0';
        data->mes = atoi(mes);
        gotoxy(colunas[3], linha);
        for(i = 0; i <= 3; i++)
            ano[i] = getche();
        ano[i] = '\0';
        data->ano = atoi(ano);
    }while(!(verificaData(data)));
}


//------------//
// IMPRESSÕES //
//------------//

//5 - imprimir os dados de aluno:
//recebe um vetor do tipo aluno e sua dimensão
void imprimeVetorAlunos(){

}

//-----------//
// ALOCAÇÕES //
//-----------//


// 6 – alocar dinamicamente o vetor de alunos
void alocaVetorAulunos(){

}

// 7 – realocar dinamicamente o vetor de alunos
void realocaVetorAlunos(){

}

// 8 – alocar dinamicamente o vetor de compromissos
void alocaVetorCompromissos(){

}

// 9 – realocar dinamicamente o vetor de compromissos
void realocaVetorcompromissos(){

}

// Roda o menu enquanto a resposta nao for 7 (sair)
void menu(){
    char resp[2];
    do{
        printf("Funcionalidades do Sistema:\n1 - Cadastrar Aluno\n2 - Cadastrar Compromisso\n3 - Imprimir Compromissos\n\ta - de um aluno\n\tb - de todos os alunos\n\tc - de uma data\n\td - de todas as datas\n4 - Imprimir dados de um aluno\n5 - Imprimir dados de todos os alunos\n6 - Sair");
        fgets(resp, sizeof(resp), stdin);
        switch (resp[0]){
            case '1':
                int quant;
                printf("Quantos alunos deseja cadastrar? ");
                scanf("%i", &quant);
                cadastraAluno(quant);
                break;
            case '2':
                int quant;
                printf("Quantos comprimissos deseja cadastrar? ");
                scanf("%i", &quant);
                cadastraCompromisso(quant);
                break;
            case '3':
                switch (resp[1]){
                    case 'a':
                        imprimeCompromisso('a');
                        break;
                    case 'b':
                        imprimeCompromisso('b');
                        break;
                    case 'c':
                        imprimeCompromisso('c');
                        break;
                    case 'd':
                        imprimeCompromisso('d');
                        break;
                }
            case '4':
                imprimeDadosAluno();
                break;
            case '5':
                imprimeVetorAlunos();
                break;
            case '6':
                printf("Obrigado por usar meu sistema!\nVolte sempre!!");
                break;
            default:
                printf("Resposta Inválida.");
        }
    }while(resp[0]!='6');

}

int main(){
    printf("Bem-vindo ao meu Trabalho de Algoritmos 2!!\n\tAluno: Jefhter Cabral\n\tRA: 2565390\n\tProfessor: Gabriel Gengivir\n\tProjeto: Sistema de Cadastro");
    menu();
    printf("By: Jefhter R. Cabral - 2565390\n11/2024.");
    return 0;
}




// IDEIAS DE FUNÇÕES QUE PODEM SER USADAS:
int comparaCompromisso(const void *ptr1, const void *ptr2){
	Compromisso *comp1 = (Compromisso *)ptr1;
	Compromisso *comp2 = (Compromisso *)ptr2;

	if (comp1->data.ano != comp2->data.ano)
		return comp1->data.ano - comp2->data.ano;

	if (comp1->data.mes != comp2->data.mes)
		return comp1->data.mes - comp2->data.mes;

	if (comp1->data.dia != comp2->data.dia)
		return comp1->data.dia - comp2->data.dia;

	if (comp1->horario.hora != comp2->horario.hora)
		return comp1->horario.hora - comp2->horario.hora;

	return comp1->horario.min - comp2->horario.min;
}