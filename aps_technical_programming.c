#include <stdio.h>
#include <stdlib.h>

const int length = 2;

void dataAboutPlayers(char aboutPlayers[length][length], float heightPlayers[length]);
float averagePlayers(float it[length]);
float medianPlayers(float heightPlayers[length]);
void mergeSort(float arr[], int l, int r);
void merge(float arr[], int l, int m, int r);
void higherAndLowerHeight(char aboutPlayers[length][length], float heightPlayers[length]);
float standardDeviationPlayers(float heightPlayers[length]);

int main(){
    char fullNamesPlayers[length][length];
    float heightPlayers[length];
    char registerPlayers[length][length];
    int isOpen = 1;
    int option = 0;
    int count = 0;

    printf("Grupo: \n Paulo Felipe Oliveira de Souza RA 20898988 \n Guilherme Takakuwa 20913698 \n Vitor Cunha Silva 20900163 \n Levi da Costa Silva 20755873\n\n");

    //Get names on players 
    for(int i = 0; i < length; i++){
        printf("%s %d \n", "Insira o nome do jogador ", i);
        scanf("%s", &fullNamesPlayers[i]);  
    
        float inputHeight = 0;

        do{
            printf("%s \n", "Insira altura do jogador em cm (acima de 0 cm):");
            scanf("%f",&inputHeight);
            if(inputHeight > 0){
                heightPlayers[i] = inputHeight;
            }
        }while(inputHeight < 0);
    }

    printf("\n");

    mergeSort(heightPlayers, 0, (length - 1));

    //Do e o switch serve para blb
    do{
        printf("Escolha a opção:\n1 - Mostra os dados do jogadores:\n2 - Média de altura dos jogadores:\n3 - Desvio Padrão das alturas:\n4 - Maior e Menor altura:\n5 - Mediana de altura dos jogadores:\n6 - Sair\n");

        scanf("%d", &option);

        printf("\n");

        switch (option){
            case 1:
                if(fullNamesPlayers[0] != NULL){
                    dataAboutPlayers(fullNamesPlayers, heightPlayers);
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 2:
                if(fullNamesPlayers[0] != NULL){
                    printf("%s %f\n", "Média da altura dos jogadores é: ", averagePlayers(heightPlayers));
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 3:
                if(fullNamesPlayers[0] != NULL){
                    printf("%s %f\n", "Desvio padrão dos jogadores é: ", standardDeviationPlayers(heightPlayers));
                }else{
                    printf("Não tem nenhum dado de jogadores registrado.");
                }
                printf("\n");
                break;
            case 4:
                if(fullNamesPlayers[0] != NULL){
                    higherAndLowerHeight(fullNamesPlayers, heightPlayers);
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
                printf("Volte sempre!");
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
void dataAboutPlayers(char aboutPlayers[length][length], float heightPlayers[length]){
    for(int i = 0; i < length; i++){
        printf("%s \n", "-----------------------");
        printf("%s | %f cm\n", aboutPlayers[i], heightPlayers[i]);
    }
}

//Calcular a média da altura dos jogadores
float averagePlayers(float it[length]){
    float sumAll = 0;

    for(int i = 0; i < length; i++){
        sumAll += it[i];
    }

    return (sumAll / length);
}

float standardDeviationPlayers(float heightPlayers[length]){
    float sumHeightPow, sumHeight = 0;
    float average = averagePlayers(heightPlayers);

    for(int i = 0; i < length; i++){
        //Picking up only one player at a time
        float heightPlayer = heightPlayers[i];
        //Calculating player height by square
        sumHeightPow += (heightPlayer*heightPlayer);
        //Adding height of all players
        sumHeight += heightPlayer;
    }

    return (sumHeightPow/sumHeight) - (average*average);
}

void higherAndLowerHeight(char aboutPlayers[length][length], float heightPlayers[length]){
    printf("Menor jogador: %s | %f cm\n", aboutPlayers[0], heightPlayers[0]);
    printf("Maior jogador: %s | %f cm\n", aboutPlayers[(length - 1)], heightPlayers[(length - 1)]);
}

//Calcular a mediana dos jogadores
float medianPlayers(float heightPlayers[length]){
    int half = (length / 2);

    if(length % 2 == 0){
        float varOne = heightPlayers[half];
        float varSecond = heightPlayers[half - 1];
        return (varOne + varSecond) / 2;
    }else{
        return heightPlayers[(half - 1)];
    }
}

//Ordernar o vetor por causa da função mediana e maior e menor altura.

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
// Method get on @https://www.geeksforgeeks.org/merge-sort/
void merge(float arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(float arr[], int l, int r) { 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}





