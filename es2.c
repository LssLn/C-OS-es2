/*main thread genera 2 t e rende detached il secondo, inoltre il main inizializza var globale A=5 e ogni t genera un numero casuale tra 1 e a,  va in sleep per 5 secondi (A) per finire e termina. Il main attende la terminazione del primo e va in sleep A sec, terminando l’esecuzione*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int A;


void *f(){
    int n = rand()%A +1; //senza +1 è da 0 a 4
    printf("\nthread , ho generato n = %d",n);
    sleep(A);
    pthread_exit(EXIT_SUCCESS);
}

int main(){
    pthread_t tid1,tid2;
    int res;

    A=5;

    res=pthread_create(&tid1,NULL,f,NULL);
    if(res!=0){
        //...
    }
    res=pthread_create(&tid2,NULL,f,NULL);
    if(res!=0){
        //...
    }
    pthread_detach(tid2);

    pthread_join(tid1,NULL);
    sleep(A);
    exit(EXIT_SUCCESS);
}