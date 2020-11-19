#include <stdio.h>
#define ROWS 3
#define COLS 3

char checkWinner(int moves, char arr[ROWS][COLS]) {
	
	for (int i = 0; i < ROWS; i++) {
		if (arr[i][0] != ' ' && (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])) {
			return arr[i][0];
		}
	}

	for (int i = 0; i < COLS; i++) {
		if (arr[0][i] != ' ' && (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])) {
			return arr[0][i];
		}
	}

	if (arr[1][1] != ' ' && ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))) {
		return arr[1][1];
	}
	if (moves > 9) {
		return 'D';
	}
	return 0;
}

int main(void) {
	char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int count = 0, turn = 0, x, y;
	printf("---|---|---\n");
	for (int i = 0; i < 3; i++) {
		
		printf(" %c | %c | %c \n", board[i][0], board[i][1],	board[i][2]);
		printf("---|---|---\n");
	}
	

	while (1) {
		if (turn == 0) {
			printf("(x,y) You:");
			while (1) {
				scanf_s("%1d%1d", &x, &y); 

				if (x > 2 || y > 2 || x < 0 || y < 0) {
					printf("Please choose a different value!!\n");
					printf("(x,y) You:");
					continue;
				}
				if (board[x][y] != ' ') {
					printf("Please choose a different value!\n");
					printf("(x,y) You:");
					continue;
				}
				break;
			}
			count++;
			board[x][y] = 'X';
			turn = 1;
		}
		else if (turn == 1) {
			for (int i=0, j, k = 0; i < 3, k == 0; i++) {
				for (j = 0; j < 3, k == 0; j++) {
					if (board[i][j] == ' ') {
						count++;
						board[i][j] = 'O';
						printf("(x,y) Computer: %d, %d\n", i, j);
						k = 1;
						turn = 0;
					}
				}
				break;
			}
		}
		printf("-------\n");
		for (int i = 0; i < 3; i++) {
			printf("|%c|%c|%c|\n", board[i][0], board[i][1], board[i][2]);
			printf("-------\n");
		}
		

		char winner = checkWinner(count, board);
		if (winner == 'X' || winner == 'O') {
			printf("%c Won!", winner);
			return 0;
		}
		else if (winner == 'D') {
			return 0;
		}
	}
}
