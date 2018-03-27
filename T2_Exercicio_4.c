#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2){ //Funcao de uniao
   int i, x;

   int *v3 = (int *) malloc((n1+n2) * sizeof(int)); //Aloca espaco para o vetor de uniao

   for(i = 0; i < n1; i++){ //Preenche a uniao com o primeiro veotr
      *(v3+i) = *(v1+i);
   }
   for(x = 0; x < n2; x++, i++){ //Preenche a uniao com o segundo valor, de onde parouo primeiro
      *(v3+i) = *(v2+x);
   }
   return v3;
}

int main(){
   int *v1, n1, *v2, n2, *v3, i;

   printf("Informe o tamanho do primeiro vetor: ");
   scanf("%d", &n1);
   v1 = (int *)malloc(n1 * sizeof(int));
   printf("Informe o conteudo do vetor: ");
   for(i = 0; i < n1; i++){
      scanf("%d", (v1+i));
   }

   printf("Informe o tamanho do segundo vetor: ");
   scanf("%d", &n2);
   v2 = (int *)malloc(n2 * sizeof(int));
   printf("Informe o conteudo do segundo vetor: ");
   for(i = 0; i < n2; i++){
      scanf("%d", (v2+i));
   }

   v3 = uniao(v1, n1, v2, n2); //Passa os valores por referencia para a Função

    printf("A uniao e: \n");
   for(i = 0; i < (n1+n2); i++){ //Printa a uniao
      printf("%d ", *(v3+i));
   }
}
