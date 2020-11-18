#include <stdio.h>

int main(void) {
    char arr[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int countMoves = 0, turn = 0, x, y;
    
    printf("Welcome to tic-tac-toe game!\n");
        
    printf("-------\n");
    for(int i = 0; i < 3; i++) {
        printf("|%c|%c|%c|\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    printf("-------\n");

    while(1) {
        if(turn == 0) {
            printf("(x, y) You :");
            while(1) {
                if(scanf("%d %d", &x, &y) != 2) {
                    printf("Invalid input. Please try again.\n");
                    printf("(x, y) You :");
                    continue;
                }
                if(arr[x][y] != ' ') {
                    printf("The place is already taken. Choose a different point.\n");
                    printf("(x, y) You :");
                    continue;
                }
                if(x > 2 || y > 2 || x < 0 || y < 0) {
                    printf("Out of range. Choose a different point.\n");
                    printf("(x, y) You :");
                    continue;
                }
                break;
            }
            countMoves++;
            arr[x][y] = 'X';
            turn = 1;
        }
        
        else if(turn == 1) {
            for(int i = 0, j, k = 0; i < 3, k == 0; i++) { 
                for(j = 0; j < 3, k == 0; j++) { 
                    if(arr[i][j] == ' ') { 
                        arr[i][j] = 'O';
                        countMoves++;
                        printf("(x, y) Computer: %d %d\n", i, j);
                        k = 1;
                        turn = 0;
                    }
                }
            }
        }
        
        printf("-------\n");
        for(int i = 0; i < 3; i++) {
            printf("|%c|%c|%c|\n", arr[i][0], arr[i][1], arr[i][2]);
        }
        printf("-------\n");
       
        for(int i = 0; i < 3; i++) {
            if(arr[i][0] != ' ' && (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])) {
                printf("Winnter is the player \'%c\'!\n", arr[i][0]);
                return 0;
            }
        }
        
        for(int i = 0; i < 3; i++) {
            if(arr[0][i] != ' ' && (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])) {
                printf("Winnter is the player \'%c\'!\n", arr[0][i]);
                return 0;
            }
        }
        
        if(arr[1][1] != ' ' && ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))) {
            printf("Winnter is the player \'%c\'!\n", arr[1][1]);
            return 0;
        }

        if(countMoves >= 9) {
            printf("It's a draw!\n");
            return 0;
        }
    }
}
