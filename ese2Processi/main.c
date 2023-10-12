#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define dimensione 1000

void CaricaVettore(int w[], int dim){
    srand(time(NULL));

    for(int i = 0; i < dim; i++){
        w[i] = rand() % 1000;
    }


}

void StampaVettore(int w[], int dim, char* commento){

    for(int i = 0; i < dim; i++){
        printf("%s %i \t",commento, w[i] );


    }

}

void BubbleSort(int w[], int dim){
    int count = 0;

    for(int j = 0; j < dim - 1; j++) {


        for (int i = 0; i < dim - 1; i++) {
            if (w[i] > w[i + 1]) {
                int tmp = w[i];
                w[i] = w[i + 1];
                w[i + 1] = tmp;
                count++;
            }
        }
    }
    printf("scambi: %i \n", count);
}


int main() {







    int a[dimensione] = {};
    CaricaVettore(a, dimensione);
    int id = fork();


    if(id == 0){

        //siamo nel figlio
        int b[(dimensione/2)] = {};  //prima metà array iniziale

        for(int i = 0; i < ((dimensione / 2) - 1); i++){
            b[i] = a[i];
        }
        BubbleSort(b, (dimensione/2));
        StampaVettore(b, (dimensione / 2), "val dal figlio: ");

    }

    else{


        //siamo nel padre

        int c[(dimensione / 2)] = {};

        for(int i = (dimensione / 2); i < dimensione; i++){
            c[i-dimensione/2] = a[i];
        }
        BubbleSort(c, (dimensione/2));
        StampaVettore(c, (dimensione / 2), "val dal padre: ");
    }

}