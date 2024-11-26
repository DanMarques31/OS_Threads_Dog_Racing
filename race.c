#include <stdio.h>
#include <stdlib.h>
#include "race.h"

// Mutex para sincronizar a impressão na tela
pthread_mutex_t mutex;
char *ranking[MAX_CORREDORES];
int posicao_atual = 0;

void *corrida(void *arg) {
    Dog *c = (Dog *)arg;
    while (c->distancia < DISTANCIA_TOTAL) {
        // Incrementa a distância percorrida aleatoriamente
        c->distancia += rand() % 10 + 1;

        // Sincroniza a saída para evitar sobreposição de prints
        pthread_mutex_lock(&mutex);
        printf("%s correu! Distância atual: %d\n", c->raca, c->distancia);
        pthread_mutex_unlock(&mutex);

        // Pausa para simular a corrida
        usleep(100000);
    }

    // Término da corrida
    pthread_mutex_lock(&mutex);
    ranking[posicao_atual++] = c->raca;
    printf("%s terminou a corrida!\n", c->raca);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Função para exibir o ranking final
void exibe_ranking() {
    printf("\n=== Ranking Final ===\n");
    for (int i = 0; i < posicao_atual; i++) {
        printf("%dº lugar: %s\n", i + 1, ranking[i]);
    }
}

// Função para inicializar o mutex
void inicializa_mutex() {
    pthread_mutex_init(&mutex, NULL);
}

// Função para destruir o mutex
void destroi_mutex() {
    pthread_mutex_destroy(&mutex);
}