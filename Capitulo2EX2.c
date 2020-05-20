#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tamanho 5

struct fcliente{
    char nome[30];
    char hora[30];
    int ini;
    int fim;
};

struct fcliente fila;
int op=-1;
char elementoc[30], elementoh[30];

void enfileiramento();
void desenfileiramento();
void mostra_fila();
void menu();

int main(){
    setlocale(LC_ALL,"");
    fila.ini = 0;
    fila.fim = 0;
    while (op != 0)
    {
        system("cls");
        mostra_fila();
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            enfileiramento();
            break;
        case 2:
            desenfileiramento();
            break;
        }
    }
    return(0);
}

void menu(){
    printf("1 - Cliente Chegou\n");
    printf("2 - Cliente foi Atendido\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void enfileiramento(){
    if (fila.fim == tamanho)
    {
        printf("A Fila está Cheia, Impossivel enfileirar mais");
        system("pause");
    } else {
        fflush(stdin);
        printf("Digite o Nome do Cliente: ");
        scanf("%s", &fila.nome[fila.fim]);
        fflush(stdin);
        printf("Digite o Horario que o Cliente Chegou: ");
        scanf("%s", &fila.hora[fila.fim]);
        fflush(stdin);
        fila.fim++;
    }
}

void desenfileiramento(){
    if (fila.fim == fila.ini)
    {
        printf("A Fila está vazia");
    }else
    {
        for (int i = 0; i < tamanho; i++)
        {
            strcpy(fila.nome[i], fila.nome[i+1]);
            strcpy(fila.hora[i], fila.hora[i+1]);
        }
        strcpy(fila.nome[fila.fim], "");
        strcpy(fila.hora[fila.fim], "");
        fila.fim--;
    }
}

void mostra_fila(){
    int i;
    for (int i = 0; i < tamanho; i++)
    {
        printf("Cliente: %c \n",fila.nome[i]);
        printf("Hora: %c \n\n\n", fila.hora[i]);
    }
}