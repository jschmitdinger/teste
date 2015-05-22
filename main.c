#include <stdio.h>
#include <stdlib.h>

#define SABABA 0
#define QTD 3
#undef DEBUG

const char NOME_ARQ[] = "TESTE.txt";

typedef struct barcas{
    char marca[80];
    char modelo[80];
    int preco;
    int ano;
}barcas;

int maisCaro(barcas carro[]);
int maisVelho(barcas carro[]);

int main()
{
    int count = 0;
    int n;
    int carroMaisCaro;
    int carroMaisVelho;

    barcas carro[QTD];

    FILE *fp;
    fp = fopen(NOME_ARQ, "r");

    if (fp == NULL){
        printf("Erro ao abrir arquivo %s.\n", NOME_ARQ);
        exit(1);
    }

    while(1){
        n = fscanf(fp, "%s %s %d %d", carro[count].marca, carro[count].modelo, &carro[count].preco, &carro[count].ano);

        #ifdef DEBUG0
            printf("###n: %d", n);
        #endif

        if(n == EOF)
            break;

        printf("\n%s %s %d %d", carro[count].marca, carro[count].modelo, carro[count].preco, carro[count].ano);
        count++;
    }

    fclose(fp);

    carroMaisCaro = maisCaro(carro);
    printf("\n\tO carro mais caro eh o %s %s", carro[carroMaisCaro].marca, carro[carroMaisCaro].modelo);

    carroMaisVelho = maisVelho(carro);
    printf("\n\tO carro mais velho eh o %s %s", carro[carroMaisVelho].marca, carro[carroMaisVelho].modelo);

    return 0;
}

int maisCaro(barcas carro[])
{
    int maior;
    int maiorn;
    int i;

    for(i=0, maior = 0; i<QTD; i++){
        if(maior < carro[i].preco){
            maior = carro[i].preco;
            maiorn = i;
        }
    }

    return maiorn;
}

int maisVelho(barcas carro[])
{
    int maior;
    int maiorn;
    int i;

    for(i=0, maior = 3000; i<QTD; i++){
        if(maior > carro[i].ano){
            maior = carro[i].ano;
            maiorn = i;
        }
    }

    return maiorn;
}
