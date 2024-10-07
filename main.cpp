#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 4;
int board[SIZE][SIZE] = {0};


void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0)
                std::cout << ".\t";  
            else
                std::cout << board[i][j] << "\t";
        }
        std::cout << "\n";
    }
}


void spawnTile(int board[SIZE][SIZE]) {
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (board[x][y] != 0);

    board[x][y] = (rand() % 10 < 9) ? 2 : 4;
}


char getMove() {
    char move;
    std::cout << "Enter your move (w: up, a: left, s: down, d: right): ";
    std::cin >> move;
    return move;
}


void moveLeft(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k-1] == 0) {
                    board[i][k-1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
            }
        }
       
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] == board[i][j-1] && board[i][j] != 0) {
                board[i][j-1] *= 2;
                board[i][j] = 0;
            }
        }
        
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k-1] == 0) {
                    board[i][k-1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
            }
        }
    }
}


void moveRight(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j;
                while (k < SIZE - 1 && board[i][k+1] == 0) {
                    board[i][k+1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
            }
        }
        
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] == board[i][j+1] && board[i][j] != 0) {
                board[i][j+1] *= 2;
                board[i][j] = 0;
            }
        }
       
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j;
                while (k < SIZE - 1 && board[i][k+1] == 0) {
                    board[i][k+1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
            }
        }
    }
}


void moveUp(int board[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k-1][j] == 0) {
                    board[k-1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
            }
        }
        
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] == board[i-1][j] && board[i][j] != 0) {
                board[i-1][j] *= 2;
                board[i][j] = 0;
            }
        }
        
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k-1][j] == 0) {
                    board[k-1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
            }
        }
    }
}


void moveDown(int board[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < SIZE - 1 && board[k+1][j] == 0) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
            }
        }

        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] == board[i+1][j] && board[i][j] != 0) {
                board[i+1][j] *= 2;
                board[i][j] = 0;
            }
        }
        
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < SIZE - 1 && board[k+1][j] == 0) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
            }
        }
    }
}


bool isGameOver(int board[SIZE][SIZE]) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) return false;  
            if (i < SIZE-1 && board[i][j] == board[i+1][j]) return false; 
            if (j < SIZE-1 && board[i][j] == board[i][j+1]) return false;  
        }
    }
    return true;  
}


int main() {
    srand(static_cast<unsigned int>(time(0)));  

    
    spawnTile(board);
    spawnTile(board);

    
    while (true) {
        printBoard(board);

        if (isGameOver(board)) {
            std::cout << "Game Over!" << std::endl;
            break;
        }

        char move = getMove();
        switch (move) {
            case 'w': moveUp(board); break;
            case 'a': moveLeft(board); break;
            case 's': moveDown(board); break;
            case 'd': moveRight(board); break;
            default: std::cout << "Invalid move!" << std::endl; continue;
        }

        spawnTile(board);  
    }

    return 0;
}
