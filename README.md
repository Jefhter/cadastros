
# Cadastros
Trabalho para a Disciplina de Algoritmos 2 - UTFPR

### Conhecimentos Utilizados

- Funções
- Registros
- Ponteiros
- Alocação Dinâmica


### Descrição Do Projeto

O projeto apresentado é um sistema de cadastro e gerenciamento acadêmico desenvolvido em C, com foco na organização de alunos, disciplinas e compromissos acadêmicos. Ele utiliza estruturas dinâmicas para armazenar informações, incluindo um vetor de alunos com capacidade inicial para 10 registros e um vetor de compromissos para 15 registros, ambos realocados dinamicamente conforme necessário. Entre suas funcionalidades, o sistema permite o cadastro de alunos com dados completos, incluindo disciplinas obrigatórias, notas, cálculo de médias e validação de e-mail. Além disso, os compromissos associados aos alunos são gerenciados, garantindo que não haja sobreposição de horários ou excesso de compromissos em um mesmo dia. A ordenação dos compromissos é realizada utilizando a função ```qsort```, e os dados de datas e horários são rigorosamente validados. A interface inclui um menu interativo para cadastro e consulta de alunos e compromissos, oferecendo uma experiência organizada e prática para o gerenciamento de informações acadêmicas.


#### **📚 Bibliotecas**

- _STDLIB_
Biblioteca padrão de entrada e saída.
Fornece funções como printf(), scanf(), fopen(), entre outras.

- *STDIO*
Biblioteca padrão de utilitários.
Inclui funções para alocação dinâmica de memória como malloc() e free(), controle de processos como exit(), e conversão de números como atoi(), strtod().

- *STRING*
Fornece manipulação de strings.
Contém funções como strcpy(), strcat(), strlen(), strcmp().

- *CONIO*
Biblioteca usada para manipulação de entrada e saída de console.
Disponível principalmente em sistemas baseados em DOS e Windows.
Funções como getch() (ler caractere sem eco no console) e clrscr() (limpar a tela do console).

- *WINDOWS*
Biblioteca específica do Windows para programação de baixo nível.
Permite acesso a funcionalidades do sistema operacional, como gerenciamento de janelas, arquivos, threads e manipulação de APIs do Windows.
Comumente usado para desenvolver aplicações que interagem diretamente com o sistema operacional.
Neste programa foi utilizado por várias vezes a função system().

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
```

