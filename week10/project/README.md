# SUDOKU
#### Video Demo:  https://youtu.be/D8f7MyBic5Y
#### Description:
Sudoku is an ancient game with profound mathematical essence and fascinating charm. I really enjoy playing this game, so I made it my final project! My project was written in C language!

This is a small program implemented in C language to solve Sudoku puzzles. It's very simple, after all, I completed a similar version using Python in CS50P!

The program includes the following functions:

- print_board(): print the numbers on the Sudoku board.
- find_empty(): find empty cells on the Sudoku board.
- is_valid(): check if placing a number at a given position is valid.
- solve_board(): recursively attempt to solve the Sudoku board.
- read_board(): read the Sudoku board from a file.

In the main function, first it checks whether there are correct number of command line arguments. If not, it outputs usage information and returns. Otherwise, it uses read_board() function to read in the Sudoku board from input file. Then, it prints out input board, calls solve_board() function to solve the Sudoku board and prints out solution or "No solution" message.

USAGE：
```
./main test.txt
```

You can test freely, of course, you need to be aware that if the Sudoku puzzle is particularly difficult, the program may run very slowly!
##### More about sudoku
Sudoku is a logic puzzle that is usually represented using a 9x9 grid. Each grid can contain a number ranging from 1 to 9. The goal of the Sudoku puzzle is to fill the grid so that each number appears only once in each row, column, and 3x3 sub-grid.

The rules of Sudoku are very simple, but it can become very complex and challenging. Sudoku puzzles typically appear at different levels of difficulty, ranging from beginner level to expert level. Solving Sudoku puzzles requires logical reasoning and trial-and-error, without requiring any mathematical skills or calculators.

The history of Sudoku can be traced back to Europe in the 18th century, but its modern form was invented by Japanese mathematicians in the 1970s. In Japan, Sudoku is called "Sudoku", which means "single digit".

Solving Sudoku typically involves recursive algorithms and backtracking algorithms. A recursive algorithm is a method for solving problems where functions call themselves to solve smaller sub-problems. Backtracking algorithm is a type of recursive algorithm where the program tries placing numbers in each cell and checks if that number is valid or not. If the number is invalid then the program goes back to the previous cell and tries another number instead. If the program successfully fills up all cells then it has found a solution.

Solving sudoku also involves some techniques and strategies such as unique candidate strategy, lone possibility strategy, exclusion strategy and chain reasoning strategy etc., These techniques help solve more complex sudoku puzzles without resorting to trial-and-error or backtracking methods.