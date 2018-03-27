#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tamanho, *vetor, i; //Cria as variaveis
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho); //Aloca a memoria do tamanho que foi passado anteriormente

    for(i=0; i<tamanho; i++) //Pega o conteudo das posicoes
    {
        printf("\nDigite o conteudo da posicao %d: ", i);
        scanf("%d", (vetor+i));
    }

    for(i=0; i<tamanho; i++) //Printa a posicao, conteudo e endereco
    {
        printf("\nPosicao: %d", i);
        printf("\nConteudo: %d", *(vetor+i));
        printf("\nEndereco: %p", (vetor+i));
    }
}
