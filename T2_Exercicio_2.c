#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char endereco[100];
    int matricula;
} estudante;

int main()
{
    int tamanho, i;
    printf("Digite a quantidade de estudantes: ");
    scanf("%d", &tamanho);
    getchar(); //Para tirar o \n do scanf
    estudante *pEstuda; //Um ponteiro para a struct estudante

    pEstuda = (estudante*) malloc(sizeof(estudante)*tamanho); //Define o tamanho do vetor

    for(i=0; i<tamanho; i++) //Coloca o conteudo no vetor
    {
        printf("\nAluno numero %d\nDigite o nome para o aluno: ", i);
        fgets((pEstuda+i)-> nome, 50, stdin);
        printf("Digite o endereco do aluno: ");
        fgets((pEstuda+i)-> endereco, 100, stdin);
        printf("Digite a matricula do aluno: ");
        scanf("%d", &(pEstuda+i )-> matricula);
        getchar();
    }

    for(i=0; i<tamanho; i++) //Imprime as posicoes e os conteudos
        {
        printf("\nNa posicao %d", i);
        printf("\nNome: %s", (pEstuda+i) -> nome);
        printf("Endereco: %s", (pEstuda+i) -> endereco);
        printf("Matricula: %d\n", (pEstuda+i) -> matricula);
    }
}
