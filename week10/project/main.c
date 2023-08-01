#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int find_empty(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *col) {
    for (*row = 0; *row < BOARD_SIZE; (*row)++) {
        for (*col = 0; *col < BOARD_SIZE; (*col)++) {
            if (board[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    // Check 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    if (!find_empty(board, &row, &col)) {
        // Board is full, solution found
        return 1;
    }
    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (solve_board(board)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int read_board(const char *filename, int board[BOARD_SIZE][BOARD_SIZE]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Failed to open file\n");
        return 0;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (fscanf(file, "%d", &board[i][j]) != 1) {
                printf("Error: Invalid input file\n");
                fclose(file);
                return 0;
            }
        }
    }
    fclose(file);
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    int board[BOARD_SIZE][BOARD_SIZE];
    if (!read_board(argv[1], board)) {
        return 1;
    }
    printf("Input:\n");
    print_board(board);
    if (solve_board(board)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}
