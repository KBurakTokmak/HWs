#include "the4.h"

// do not add extra libraries here

int min_two(int a, int b) {
    return (a < b) ? a : b;
}

void init_dp(int** dp, int X, int Y, bool** possible_plots) {
    //init base cases as 0
    for (int i=0; i <= X; i++){
        dp[i][0] = 0;
        } 
    for (int j=0; j <= Y; j++){
        dp[0][j] = 0;
        }
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            dp[i][j] = i * j;
        }
    }

    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            if (possible_plots[i][j]) {
                dp[i][j] = 0;
            }
        }
    }
}


int divide_land(int X, int Y, bool** possible_plots) {
    
    int** dp = new int*[X + 1];
    for (int i = 0; i <= X; i++) {
        dp[i] = new int[Y + 1];
    }

    init_dp(dp, X, Y, possible_plots);

    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            if (dp[i][j] == 0) continue; 

            //horizontal check
            for (int k = 1; k < i; k++) {
                dp[i][j] = min_two(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            
            //vertical check
            for (int k = 1; k < j; k++) {
                dp[i][j] = min_two(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    int result = dp[X][Y];
    //free memory
    for (int i = 0; i <= X; i++) {
        delete[] dp[i];
    }

    return result;
}