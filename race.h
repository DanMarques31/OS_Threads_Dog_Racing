#ifndef RACE_H
#define RACE_H
#include <pthread.h>

typedef struct {

    char *raca;
    int distancia;

} Dog;

#define DISTANCIA_TOTAL 100
#define MAX_CORREDORES 10

void *corrida(void *arg);
void inicializa_mutex();
void destroi_mutex();
void exibe_ranking();

#endif