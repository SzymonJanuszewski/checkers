#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 typedef struct {
    int x;
    int y;
}Position;

Position makePosition(int z, int c) {
    Position a;
    a.x = z;
    a.y = c;

    return a;
}

void createBoard(char array[9][9]){


    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < 9; j++) {
            if(i%2 != 0 && j%2 != 0 || i%2 == 0 && j%2 ==0){
                if(i<4){
                    array[i][j] = 'W';
                }
                else if (i>5) {
                    array[i][j] = 'B';
                }
                else array[i][j] = '  ';
            }
            else array[i][j] = '  ';
        }
    }
}

void displayBoard(char array[9][9]){

    for(int i = 1; i < 9; i++) {
        printf("%d|", i);
        for(int j = 1; j < 9; j++) {
            printf("%c|", array[i][j]);
        }
        printf("\n");
    }
}

void checkerMove( Position a, Position b, char array[9][9], int playerNumber) {

    if(playerNumber%2 != 0){
        array[a.x][a.y] = '  ';
        array[b.x][b.y] = 'W';

    } else {
        array[a.x][a.y] = '  ';
        array[b.x][b.y] = 'B';
    }

}

void checkerJump(Position a, Position b, char array[9][9], int playerNumber) {
    if(playerNumber%2 != 0){
        array[a.x][a.y] = '  ';

        array[b.x][b.y] = 'W';

    } else {
        array[a.x][a.y] = '  ';
        array[b.x][b.y] = 'B';
    }
}

int main() {

    char board[9][9];
    int counter = 1, player, a;
    int x0, x1, y0, y1;
    int whitePoints = 0, blackPoints = 0;

    printf("Welcome to the game\n\n");

    printf("What would you like to do?\n");
    printf("1. Instruction\n");
    printf("2. Let's play\n");
    printf("3. Exit\n");

    scanf("%d", &a);

    switch(a) {
    case 1:
        system("clear");
        printf("1. You can Move your checkers only on black fields\n2. You can move only one field diagonaly forward or backward \n3. You can jump over other player checker only when there is free square behind it\n\n\n\n");
        break;
    case 2:
        system("clear");
            createBoard(board);



            while(whitePoints < 12 || blackPoints < 12){
                printf(" -1-2-3-4-5-6-7-8-\n");
                displayBoard(board);
                if(counter%2 != 0){
                    player = 1;
                }
                else {
                    player = 2;
                }

               if(player == 1){
                    do{
                        printf("Player1 turn (W):\n");
                        do{
                            printf("Initial position: \n");
                            printf("x: ");
                            scanf("%d", &x0);
                            printf("y: ");
                            scanf("%d", &y0);
                        }while(board[x0][y0] != 'W' || x0 > 8 || y0 > 8 || x0 < 1 || y0 < 1);
                        do{
                            printf("Final position: \n");
                            printf("x: ");
                            scanf("%d", &x1);
                            printf("y: ");
                            scanf("%d", &y1);
                        }while(board[x1][y1] == 'W' || board[x1][y1] == 'B'|| x1 > 8 || y1 > 8 || x1 < 1 || y1 < 1);
                        system("clear");
                        displayBoard(board);
                    }while((x0-x1 != -1 && x0-x1 != 1) || (y0-y1 != -1 && y0-y1 != 1));
                }
                else {
                    do{
                        printf("Player2 turn (B):\n");
                        do{
                            printf("Initial position: \n");
                            printf("x: ");
                            scanf("%d", &x0);
                            printf("y: ");
                            scanf("%d", &y0);
                        }while(board[x0][y0] != 'B' || x0 > 8 || y0 > 8 || x0 < 1 || y0 < 0);
                        do{
                            printf("Final position: \n");
                            printf("x: ");
                            scanf("%d", &x1);
                            printf("y: ");
                            scanf("%d", &y1);
                        }while(board[x1][y1] == 'B' || board[x1][y1] == 'W'|| x1 > 8 || y1 > 8 || x1 < 1 || y1 < 1);
                        system("clear");
                        displayBoard(board);
                    }while((x0-x1 != 1 && x0-x1 != -1) || (y0-y1 != 1 && y0-y1 != -1));
                }

                Position initialP = makePosition(x0, y0);
                Position finalP = makePosition(x1, y1);

                checkerMove(initialP, finalP, board, player);

                counter++;
                system("clear");
            }
        printf("\n\n\n\n");
        break;
    default:
        printf("Non option was chosen\n");
        break;

    }

system("pause");
return 0;
}
