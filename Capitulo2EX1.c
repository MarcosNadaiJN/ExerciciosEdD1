#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tamanho 5

struct plivro{
    int codigo[tamanho];
    char tlivro[50];
    char autor[50];
};

struct ppilha{
    struct plivro dados[tamanho];
    int inicio;
    int fim;
};

struct plivro livro;
struct ppilha pilha;
int op=-1;

void empilhamento();
void desempilhamento();
void mostra_pilha();
void menu();

int main(){
    setlocale(LC_ALL,"");
    pilha.inicio = 0;
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
        scanf("%s", pilha.dados[pilha.fim].tlivro);
        fflush(stdin);
        printf("Digite o Autor do Livro: ");
        scanf("%s", pilha.dados[pilha.fim].autor);
        fflush(stdin);
        printf("Digite o Codigo do Livro: ");
        scanf("%d", &pilha.dados[pilha.fim].codigo);
        fflush(stdin);
        pilha.fim++;
    }
}

void desempilhamento(){
    if (pilha.fim == pilha.inicio)
    {
        printf("A Pilha está vazia");
        system("pause");
    }else{
        pilha.dados[pilha.fim-1].codigo = 0;
        strcpy(pilha.dados[pilha.fim-1].tlivro, "");
        strcpy(pilha.dados[pilha.fim-1].autor, "");
        pilha.fim--;
    }
}

void mostra_pilha(){
    int i;
    for (int i = 0; i < tamanho; i++)
    {
        printf("Titulo: %c \n",pilha.dados[i].tlivro);
        printf("Autor: %c \n", pilha.dados[i].autor);
        printf("Codigo: %d \n\n\n", pilha.dados[i].codigo);
    }
}
