#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Definição da estrutura da fila
struct Fila {
    int frente, tras;
    int arr[MAX];
};

// Função para inicializar a fila
void inicializar(struct Fila *f) {
    f->frente = f->tras = -1;
}

// Verifica se a fila está cheia
int cheia(struct Fila *f) {
    return f->tras == MAX - 1;
}

// Verifica se a fila está vazia
int vazia(struct Fila *f) {
    return f->frente == -1;
}

// Função para enfileirar
void enfileirar(struct Fila *f, int valor) {
    if (cheia(f)) {
        printf("Fila cheia!\n");
    } else {
        if (f->frente == -1) {
            f->frente = 0;
        }
        f->arr[++f->tras] = valor;
        printf("Valor %d enfileirado.\n", valor);
    }
}

// Função para desenfileirar
int desenfileirar(struct Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        int valor = f->arr[f->frente];
        if (f->frente == f->tras) {
            f->frente = f->tras = -1;
        } else {
            f->frente++;
        }
        return valor;
    }
}

int main() {
    struct Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printf("Desenfileirado: %d\n", desenfileirar(&f));
    printf("Desenfileirado: %d\n", desenfileirar(&f));

    return 0;
}
