#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "race.h"

int main() {
    srand(time(NULL));

    // Nomes das raças dos cachorros
    char *racas[] = {"Labrador", "Galgo", "Beagle", "Golden Retriever", "Borde Collie"};
    int num_Dogs = sizeof(racas) / sizeof(racas[0]);

    // Array para armazenar as threads e os cachorros
    pthread_t threads[num_Dogs];
    Dog Dogs[num_Dogs];

    // Inicializa o mutex
    inicializa_mutex();

    // Cria as threads
    for (int i = 0; i < num_Dogs; i++) {
        Dogs[i].raca = racas[i];
        Dogs[i].distancia = 0;
        pthread_create(&threads[i], NULL, corrida, &Dogs[i]);
    }

    // Aguarda todas as threads terminarem
    for (int i = 0; i < num_Dogs; i++) {
        pthread_join(threads[i], NULL);
    }

    // Exibe o ranking final
    exibe_ranking();

    // Destroi o mutex
    destroi_mutex();
}
