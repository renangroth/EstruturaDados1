#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x = 4, i, z = 0; //Cria as variaveis
    int * vetor = (int *)malloc(20);
    do
    {
        printf("Digite um numero: "); //Numeros aleatorios
        scanf("%d", &n);
        if(z == x) //Quando z (que é o contador) for igual a x(que é o verificador para realocação) ele aloca mais 5 de memoria
        {
            x +=5;
            int *pNew = realloc(vetor, x * sizeof(int));
            if(pNew)
                vetor = pNew;
            printf("Memoria Realocada\n");
        }
        z++; //Contador
    }
    while(n != 0);

    for(i=0; i<z; i++) //Pega o conteudo das posicoes
    {
        printf("\nDigite o conteudo da posicao %d: ", i);
        scanf("%d", (vetor+i));
    }

    for(i=0; i<z; i++) //Printa a posicao, conteudo e endereco
    {
        printf("\nPosicao: %d", i);
        printf("\nConteudo: %d", *(vetor+i));
        printf("\nEndereco: %p", (vetor+i));
    }
}
