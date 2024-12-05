#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

// 1 - cadastrar aluno, sendo:
//   a - um aluno deve cursar ao menos 4 disciplinas
//   b - para cada disciplina deve haver 4 notas, com o respectivo cálculo da sua média
// //recebe um vetor do tipo td_aluno e sua dimensão
void cadastraAluno(){
    system("cls");
    // int i, n;
    // //Aluno alunos = alocaVetorAlunos();
    // for(i=0; i<n; i++){
    //     printf("Cadastro do Aluno %i", i+1);
    //     printf("Informe o RA do Aluno: ");
    //     //scanf("%i", &alunos.ra);


    // }
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
    system("cls");

}

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

// 6 – alocar dinamicamente o vetor de alunos
void alocaVetorAlunos(){


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
                cadastraAluno();
                break;
            case '2':
                cadastraCompromisso();
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