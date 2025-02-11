#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
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
    Data matricula;
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
void cadastraAluno(Aluno *alunos, int d) {
    for (int i = 0; i < d; i++) {
        printf("\nAluno %d...\n", i + 1);
        printf("RA: ");
        scanf("%d", &alunos[i].ra);
        getchar(); // Limpa o buffer do teclado
        
        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0; // Remove o '\n' do fgets

        printf("Data de matrícula (dd mm aaaa): ");
        scanf("%d %d %d", &alunos[i].matricula.dia, &alunos[i].matricula.mes, &alunos[i].matricula.ano);
        getchar();

        for (int j = 0; j < 4; j++) {
            printf("Código da disciplina %d: ", j + 1);
            scanf("%d", &alunos[i].disciplinas[j].codigo_dis);
            getchar();

            printf("Nome da disciplina: ");
            fgets(alunos[i].disciplinas[j].disciplina, sizeof(alunos[i].disciplinas[j].disciplina), stdin);
            alunos[i].disciplinas[j].disciplina[strcspn(alunos[i].disciplinas[j].disciplina, "\n")] = 0;

            printf("Notas (4 valores): ");
            for (int k = 0; k < 4; k++) {
                scanf("%f", &alunos[i].disciplinas[j].notas[k]);
            }
            getchar();

            // Calcula média
            float soma = 0;
            for (int k = 0; k < 4; k++) {
                soma += alunos[i].disciplinas[j].notas[k];
            }
            alunos[i].disciplinas[j].media = soma / 4;
        }

        printf("E-mail: ");
        fgets(alunos[i].email, sizeof(alunos[i].email), stdin);
        alunos[i].email[strcspn(alunos[i].email, "\n")] = 0;

        system("cls");
    }
}


// CADASTRAR COMPROMISSO //
//   a - um aluno não pode ter mais do que dois compromissos cadastrados na mesma data
//   b - caso um aluno possua dois compromissos na mesma data, os horários não podem estar sobrepostos/coincidentes
//recebe um vetor do tipo td_compromisso e sua dimensão

void cadastraCompromisso(Compromisso *comp, Aluno *alunos, int numAlunos, int d) {
    for (int i = 0; i < d; i++) {
        printf("\nCompromisso %d...\n", i + 1);

        printf("RA do aluno: ");
        int raBusca;
        scanf("%d", &raBusca);
        getchar();

        int encontrado = 0;
        for (int j = 0; j < numAlunos; j++) {
            if (alunos[j].ra == raBusca) {
                comp[i].aluno = alunos[j];
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Aluno não encontrado!\n");
            i--;
            continue;
        }

        printf("Data (dd mm aaaa): ");
        scanf("%d %d %d", &comp[i].data.dia, &comp[i].data.mes, &comp[i].data.ano);
        getchar();

        printf("Horário (hh mm): ");
        scanf("%d %d", &comp[i].horario.hora, &comp[i].horario.min);
        getchar();

        printf("Descrição: ");
        fgets(comp[i].descricao, sizeof(comp[i].descricao), stdin);
        comp[i].descricao[strcspn(comp[i].descricao, "\n")] = 0;

        system("cls");
    }
}



//--------------//
// VERIFICAÇÕES //
//--------------//


// VALIDAR DATA - não deve ser permitido o cadastro de uma data que não seja válida
//recebe um ponteiro para a struct td_data, que irá apontar para a data de matrícula na struct td_aluno
int ehAnoBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int verificaData(Data *data) {
    if (data->ano < 1 || data->mes < 1 || data->mes > 12 || data->dia < 1)
        return 0;

    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajuste para fevereiro em ano bissexto
    if (data->mes == 2 && ehAnoBissexto(data->ano))
        diasNoMes[1] = 29;

    return data->dia <= diasNoMes[data->mes - 1];
}


// VALIDAR HORA - não deve ser permitido o cadastro de um horário que não seja válido
//recebe um ponteiro para a struct td_hora, que irá apontar para o horário do compromisso
int verificaHorario(Hora *horario) {
    return (horario->hora >= 0 && horario->hora < 24) &&
           (horario->min >= 0 && horario->min < 60);
}


int verificaEmail(char *email) {
    if (email == NULL || strlen(email) < 5)  // Ex: "a@b.c" (mínimo possível)
        return 0;

    char *arroba = strchr(email, '@');
    if (!arroba || arroba == email)  // '@' não pode ser o primeiro caractere
        return 0;

    char *ponto = strrchr(email, '.');
    if (!ponto || ponto < arroba + 2 || ponto[1] == '\0')  // '.' depois do '@' e com pelo menos dois caracteres após
        return 0;

    return 1;  // E-mail válido
}

int verificaCompromisso(Compromisso *compromissos, int total, Compromisso novo) {
    int count = 0;
    
    for (int i = 0; i < total; i++) {
        if (compromissos[i].aluno.ra == novo.aluno.ra &&
            compromissos[i].data.dia == novo.data.dia &&
            compromissos[i].data.mes == novo.data.mes &&
            compromissos[i].data.ano == novo.data.ano) {
            
            count++;  // Conta quantos compromissos o aluno já tem na mesma data

            // Verifica se há sobreposição de horário
            if (compromissos[i].horario.hora == novo.horario.hora &&
                compromissos[i].horario.min == novo.horario.min) {
                return 0;  // Conflito de horário
            }
        }
    }

    return count < 2;  // Permite no máximo dois compromissos por dia
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
    system("cls");
}

void imprimeDadosAluno(){
    system("cls");
    
}

void imprimeCompromisso(char tipo){
    switch (tipo){
        case 'a':
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        default:
            printf("Erro!");
    }
}

//-----------//
// ALOCAÇÕES //
//-----------//


Aluno* alocaVetorAlunos(int tamanho) {
    return (Aluno*) malloc(tamanho * sizeof(Aluno));
}

Aluno* realocaVetorAlunos(Aluno *alunos, int novoTamanho) {
    return (Aluno*) realloc(alunos, novoTamanho * sizeof(Aluno));
}

Compromisso* alocaVetorCompromissos(int tamanho) {
    return (Compromisso*) malloc(tamanho * sizeof(Compromisso));
}

Compromisso* realocaVetorCompromissos(Compromisso *comp, int novoTamanho) {
    return (Compromisso*) realloc(comp, novoTamanho * sizeof(Compromisso));
}


// Roda o menu enquanto a resposta nao for 7 (sair)
void menu(){
    char resp[2];
    do{
        int quant;
        //imprime o menu
        printf("Funcionalidades do Sistema:\n-------------------------------------------------------\n\t1 - Cadastrar Aluno\n\t2 - Cadastrar Compromisso\n\t3 - Imprimir Compromissos\n\t\ta - de um aluno\n\t\tb - de todos os alunos\n\t\tc - de uma data\n\t\td - de todas as datas\n\t4 - Imprimir dados de um aluno\n\t5 - Imprimir dados de todos os alunos\n\t6 - Sair\n-------------------------------------------------------");
        
        // pega o número corespondente à funcionalidade e armaneza em resp
        printf("\nO que deseja fazer? ");
        fgets(resp, sizeof(resp), stdin);

        //teste de erro de resp

        // analisa qual número o usuário respondeu e chama a função correspondente à funcionalidade
        // nos compromissos avalia a segunda parte da variável e manda na função a especificação
        switch (resp[0]){
            case '1':
                printf("Quantos alunos deseja cadastrar? ");
                scanf("%i", &quant);
                cadastraAluno(quant);
                break;
            case '2':
                printf("Quantos comprimissos deseja cadastrar? ");
                scanf("%i", &quant);
                cadastraCompromisso(quant);
                break;
            case '3':
                switch (resp[1]){
                    // armazenar outro resp

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
                    default:
                        printf("Resposta Inválida.");
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
                system("cls");
                printf("Resposta (%s%s) Inválida!!\n\tFormato correto de resposta:\n\tNúmero correspondente a primeira opção seguido de Letra correspondente à especificação do Compromisso Caso nao haja, usar apenas o número da primeira opção.\n\tSEM ESPAÇOS!\n", resp[0], resp[1]);
        }
    }while(resp[0]!='6');
}

int main(){
    //Reconhece caracteres em pt-BR
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //Apresenta o Trabalho
    system("cls");
    printf("\n------------------------------------------------------\nBem-vindo ao meu Trabalho de Algoritmos 2!!\n\tAluno: Jefhter Cabral\n\tRA: 2565390\n\tProfessor: Gabriel Canhadas Genvigir\n\tProjeto: Sistema de Cadastro\n------------------------------------------------------\n\n");
    
    //Limpa a tela
    printf("Press Enter to continue... ");
    char resp = getchar();
    system("cls");
    
    //chama o menu
    menu();

    //finalização do programa
    system("cls");
    printf("\n\n-------------------------------\nBy: Jefhter R. Cabral - 2565390\n11/2024.\n-------------------------------\n\n");
    return 0;
}




// IDEIAS DE FUNÇÕES QUE PODEM SER USADAS:
int comparaAlunos(const void *a, const void *b) {
    return ((Aluno *)a)->ra - ((Aluno *)b)->ra;
}

int comparaCompromissos(const void *a, const void *b) {
    Compromisso *c1 = (Compromisso *)a;
    Compromisso *c2 = (Compromisso *)b;

    if (c1->data.ano != c2->data.ano)
        return c1->data.ano - c2->data.ano;
    if (c1->data.mes != c2->data.mes)
        return c1->data.mes - c2->data.mes;
    if (c1->data.dia != c2->data.dia)
        return c1->data.dia - c2->data.dia;
    if (c1->horario.hora != c2->horario.hora)
        return c1->horario.hora - c2->horario.hora;
    
    return c1->horario.min - c2->horario.min;
}

void ordenaAlunos(Aluno *alunos, int tamanho) {
    qsort(alunos, tamanho, sizeof(Aluno), comparaAlunos);
}

void ordenaCompromissos(Compromisso *comp, int tamanho) {
    qsort(comp, tamanho, sizeof(Compromisso), comparaCompromissos);
}
