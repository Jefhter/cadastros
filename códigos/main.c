#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 1 - cadastrar aluno, sendo:
//   a - um aluno deve cursar ao menos 4 disciplinas
//   b - para cada disciplina deve haver 4 notas, com o respectivo cálculo da sua média
// //recebe um vetor do tipo td_aluno e sua dimensão
void cadastraAluno(){

}

//2 - validar data - não deve ser permitido o cadastro de uma data que não seja válida
//recebe um ponteiro para a struct td_data, que irá apontar para a data de matrícula na struct td_aluno
int verificaData(){

    return 0;
}

//3 - validar hora - não deve ser permitido o cadastro de um horário que não seja válido
//recebe um ponteiro para a struct td_hora, que irá apontar para o horário do compromisso
int verificaHorario(){

    return 0;
}

// 4 - cadastrar um compromisso
//   a - um aluno não pode ter mais do que dois compromissos cadastrados na mesma data
//   b - caso um aluno possua dois compromissos na mesma data, os horários não podem estar sobrepostos/coincidentes
//recebe um vetor do tipo td_compromisso e sua dimensão
void cadastraCompromisso(){

}

//5 - imprimir os dados de aluno:
//recebe um vetor do tipo aluno e sua dimensão
void imprimeVetorAlunos(){

}

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

//recebe um ponteiro para a struct td_hora, que irá apontar para o horário do compromisso
void leHorario(){

}

//recebe um ponteiro para a struct data, que irá apontar para a data de matrícula na struct td_aluno
void leData(){

}

// Roda o menu enquanto a resposta nao for 7 (sair)
void menu(){
    char resp[2];
    do{
        printf("Funcionalidades do Sistema:\n1 - Cadastrar Aluno\n2 - Cadastrar Compromisso\n3 - Imprimir Compromissos\n\ta - de um aluno\n\tb - de todos os alunos\n\tc - de uma data\n\td - de todas as datas\n4 - Imprimir dados de um aluno\n5 - Imprimir dados de todos os alunos\n6 - Sair");
        fgets(resp, sizeof(resp), stdin);
        switch (resp[0]){
            case '1':
                cadastraAluno();
                break;
            case '2':
                cadastraCompromisso();
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