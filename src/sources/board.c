#include <stdlib.h>

#include "../headers/board.h"

/**
 * TODO: Initializes the board, initializing also each tile of it.
 * @param board The board to be initialized.
 * @param rows The number of rows of the board.
 * @param columns The number of columns of the board.
 * @return SUCCESS code if the initialization was successful, ERROR code if rows are less than 1 or more than MAX_ROWS
 * or if columns is less than 2 or more than MAX_COLUMNS.
 *
 * Pre: board not has to be NULL; integer number for rows and integer number for columns
 * Post: if the initialization is successful returns SUCCESS, if not returns ERROR
 */
int init_board(Board* board, int rows, int columns) {
    if ((rows < 1) || (rows > MAX_ROWS)) return INVALID_BOARD_DIMENSIONS;
    if ((columns < 2) || (columns > MAX_COLUMNS)) return INVALID_BOARD_DIMENSIONS;
    board->rows = rows;
    board->columns = columns;
    int pos = 0, row = rows - 1, col = 0, right = TRUE;

    for (pos = 0; pos < rows * columns; pos++) {
        init_tile(&board->tiles[row][col], pos);
        if ((pos % columns == columns-1)) {
            row--;
            if (right == TRUE) { right = FALSE; }
            else right = TRUE;
        } else if (right == TRUE) {
            col++;
        } else {
            col--;
        }
    }
    return SUCCESS;
}

//aquest bucle for el varem fer per l'entrega del lab 2 i, ara que hem fet el lab 3, l'hem canviat perquè donava certs errors.

/*    if (rows < 1 || rows > MAX_ROWS || columns < 2 || columns > MAX_COLUMNS) {
        return INVALID_BOARD_DIMENSIONS;
    }
    board -> rows = rows;
    board -> columns = columns;
    int pos = 0, row = rows - 1, col = 0, right = TRUE;
    for (row; row >= 0; row--) {
        for (col; col < columns; col++) {
            init_tile(&board -> tiles[row][col], pos);
            pos++;
        }
        row--;
        if (row < 0) {
            break;
        }
        for (col = columns - 1; col >= 0; col--) {
            init_tile(&board -> tiles[row][col], pos);
            pos++;
        }
        if ((pos & columns) == 0){
            row--;
            if (right == TRUE) right = FALSE;
            else right = TRUE;
        }
        else if (right == TRUE) {
            col++;
        }
        else {
            col--;
        }
    }
    return SUCCESS;
}
*/

/**
 * TODO: Returns the number of rows of the board.
 * @param board The board to be queried.
 * @return The number of rows of the board.
 *
 * Pre: board is not NULL, has to be defined
 * Post: returns a integer number of rows
 */
int get_rows(Board* board) {
    return board -> rows;
}

/**
 * TODO: Sets the number of rows of the board.
 * @param board The board to be queried.
 *
 * Pre: board is not NULL, has to be defined
 * Post: returns a integer number of rows
 */
void set_rows(Board* board, int rows) {
    board -> rows = rows;
}

/**
 * TODO: Returns the number of columns of the board.
 * @param board The board to be queried.
 * @return The number of columns of the board.
 *
 * Pre: board is not NULL
 * Post: returns a integer number of columns
 */
int get_columns(Board* board) {
    return board -> columns;
}

/**
 * TODO: Sets the number of columns of the board.
 * @param board The board to be queried.
 *
 * Pre: board is not NULL
 * Post: returns a integer number of columns
 */
void set_columns(Board* board, int columns) {
    board -> columns = columns;
}

/**
 * TODO: Returns the size of the board, it is, the total number of tiles.
 * @param board The board to be queried.
 * @return The size of the board.
 *
 * Pre: board is not NULL
 * Post: returns integer number of tiles, that is the size of the board
 */
int get_size(Board* board) {
    return board -> rows * board -> columns;
}

/**
 * TODO: Returns the board tile at the specific position.
 *
 * @param board The board from which the tile should be retrieved.
 * @param position The position of the tile.
 * @return The (reference to the) tile of the board corresponding to the position if valid, NULL otherwise.
 *
 * Pre: board is not NULL; board rows and columns have been assigned
 * Post: return NULL if position not in (o, board size) or return the size of the board if the (integer number of t)
 */
Tile* get_tile_at(Board *board, int position) {
    if ((position < 0) || (position >= get_size(board))) return NULL;
    int row = (board -> rows - 1) - (position / board -> columns);
    int col = position % board -> columns;      // if moves right
    if (((board -> rows - row) &1) == 0) {      // if moves left
        col = (board -> columns - 1) - col;
    }
    return &board -> tiles[row][col];   // [row][col]
}
