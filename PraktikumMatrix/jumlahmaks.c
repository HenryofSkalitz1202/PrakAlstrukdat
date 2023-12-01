#include "matrix.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>

int main(){
    Matrix main;
    int N, M, K;
    int Factors[10][2];
    scanf("%d %d %d", &N, &M, &K);

    readMatrix(&main, N, M);

    int nEff = 0;
    for(int i = 1; i <= K && i <= 10; i++){
        if(!((double)K/i > floor((double)K/i)) && K/i <= 10){
            Factors[nEff][0] = i;
            Factors[nEff][1] = (int)K/i;
            nEff++;
        }
    }

    int maxSum = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int omegaCounter = 0; omegaCounter < nEff; omegaCounter++){
                if(i + Factors[omegaCounter][0] >= N+1 || j + Factors[omegaCounter][1] >= M+1){
                    continue;
                }

                int sum = 0;
                for(int betaI = 0; betaI < Factors[omegaCounter][0]; betaI++){
                    for(int betaJ = 0; betaJ < Factors[omegaCounter][1]; betaJ++){
                        sum += ELMT(main, i + betaI, j + betaJ);
                    }
                }

                if (sum >= maxSum){
                    maxSum = sum;
                }
            }
        }
    }
    printf("%d\n", maxSum);
    return 0;
}