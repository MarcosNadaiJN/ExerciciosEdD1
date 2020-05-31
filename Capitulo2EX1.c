#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tamanho 5

struct plivro{
    int codigo[tamanho];
    char tlivro[50];
    char autor[50];
    int ini;
    int fim;
};

struct plivro pilha;
int op=-1;
char ttlivro, aautor;

void empilhamento();
void desempilhamento();
void mostra_pilha();
void menu();

int main(){
    setlocale(LC_ALL,"");
    pilha.ini = 0;
    pilha.fim = 0;
    while (op != 0)
    {
        system("cls");
        mostra_pilha();
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            empilhamento();
            break;
        case 2:
            desempilhamento();
            break;
        }
    }
    return(0);
}

void menu(){
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void empilhamento(){
    if (pilha.fim == tamanho)
    {
        printf("A Pilha está Cheia, Impossivel empilhar mais");
        system("pause");
    } else {
        printf("Digite o Titulo do Livro: ");
        scanf("%s", &ttlivro);
        strcpy(pilha.tlivro[pilha.fim], ttlivro);
        fflush(stdin);
        printf("Digite o Autor do Livro: ");
        scanf("%s", &aautor);
        strcpy(pilha.autor[pilha.fim], aautor);
        fflush(stdin);
        printf("Digite o Codigo do Livro: ");
        scanf("%d", &pilha.codigo[pilha.fim]);
        fflush(stdin);
        pilha.fim++;
    }
}

void desempilhamento(){
    if (pilha.fim == pilha.ini)
    {
        printf("A Pilha está vazia");
    }else
    {
        pilha.autor[pilha.fim-1] = 0;
        pilha.tlivro[pilha.fim-1] = 0;
        pilha.codigo[pilha.fim-1] = 0;
        pilha.fim--;
    }
}
//teste
void mostra_pilha(){
    int i;
    for (int i = 0; i < tamanho; i++)
    {
        printf("Titulo: %c \n",pilha.tlivro[i]);
        printf("Autor: %c \n", pilha.autor[i]);
        printf("Codigo: %d \n\n\n", pilha.codigo[i]);
    }
}