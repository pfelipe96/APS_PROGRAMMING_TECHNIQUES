#include <stdio.h>
#include <stdlib.h>

const int length = 4;

void dataAboutPlayers(char aboutPlayers[length][length], float heightPlayers[length], int length);
float averagePlayers(float it[length], int length);
void bubbleSort(float it[length], int n);
float medianPlayers(float heightPlayers[length]);

int main(){
    char fullNamesPlayers[length][length];
    float heightPlayers[length];
    char registerPlayers[length][length];
    int isOpen = 1;
    int option = 0;

    //Get names on players 
    for(int i = 0; i < length; i++){
        printf("%s %d \n", "Insira o nome do jogador ", i);
        scanf("%s", &fullNamesPlayers[i]);
        printf("%s \n", "Insira altura do jogador em cm:");
        scanf("%f",&heightPlayers[i]);
        // printf("%s %d \n", "Insira o RA do jogador:", i);
        // scanf("%s", registerPlayers[i]);
    }

    printf("\n");

    //Do e o switch serve para blb
    do{
        printf("Escolha a opção:\n1 - Mostra os dados do jogadores:\n2 - Média de altura dos jogadores:\n5 - Mediana de altura dos jogadores:\n6 - Sair\n");

        scanf("%d", &option);

        printf("\n");

        switch (option){
            case 1:
                if(fullNamesPlayers[0] != NULL){
                    dataAboutPlayers(fullNamesPlayers, heightPlayers, length);
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 2:
                if(fullNamesPlayers[0] != NULL){
                    printf("%s %f\n", "Média da altura dos jogadores é: ", averagePlayers(heightPlayers, length));
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 5:
                if(fullNamesPlayers[0] != NULL){
                    printf("%s %f\n", "Mediana da altura dos jogadores é: ", medianPlayers(heightPlayers));
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 6:
                printf("Até mais tarde!");
                printf("\n");
                exit(0);
                break;
            default:
                printf("Opção não encontrada, escolha um opção entre 1 à 6.\n");
                printf("\n");
                break;
        }
    }while (isOpen);
}

//Recupera os dados dos jogadores e mostra o nome, altura e registro.
void dataAboutPlayers(char aboutPlayers[length][length], float heightPlayers[length], int length){
    for(int i = 0; i < length; i++){
        printf("%s \n", "-----------------------");
        printf("%s | %f cm\n", aboutPlayers[i], heightPlayers[i]);
    }
}

//Calcular a média da altura dos jogadores
float averagePlayers(float it[length], int length){
    float sumAll = 0;

    for(int i = 0; i < length; i++){
        sumAll += it[i];
    }

    return (sumAll / length);
}

// double standardDeviationPlayers(){

// }

// double higherAndLowerHeight(int time, int isHighe){}

//Calcular a mediana dos jogadores
float medianPlayers(float heightPlayers[length]){
    bubbleSort(heightPlayers, length);

    float varOne = heightPlayers[1];
    float varSecond = heightPlayers[2];

    return (varOne + varSecond) / 2;
}

//Ordernar o vetor por causa da função mediana.
void bubbleSort(float it[length], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (it[j] > it[j + 1]) {
                aux = it[j];
                it[j] = it[j + 1];
                it[j + 1] = aux;
            }
        }
    }
}





