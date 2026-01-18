#include <stdio.h>

#include "../headers/state.h"

/**
 * TODO: Initializes the state, setting the playing board, the current position to 0 and finished flag to FALSE.
 *
 * @param state The state to be initialized.
 * @param board The playing board.
 *
 * Pre: board and state are not NULL; board is defined
 * Post: game_finished becomes FALSE; user_position is 0; set the playing board
 */
void init_state(State* state, Board* board) {
     state -> game_finished = FALSE;
     state -> user_position = 0;
     state -> board = board;
     init_sequence(&(state -> history));
}

/**
 * TODO: Sets the current position.
 *
 * @param state The state to be updated.
 * @param position The current position.
 *
 * Pre: state is not NULL; position is not outside (0, get_size(state -> board))
 * Post: The function changes the value of the variable user_position to the new value of the variable position.
 */
void set_current_position(State* state, int position) {
     state -> user_position = position;
 }

/**
 * TODO: Retrieves the current position.
 *
 * @param state The state that stores the current position.
 * @return The current position.
 *
 * Pre: state is not NULL
 * Post: returns the user_position of state
 */
int get_current_position(State* state) {
    return state -> user_position;
}

/**
 * TODO: Sets the finished flag to finished value (TRUE or FALSE)
 *
 * @param state The state to be updated.
 * @param is_finished The value marking the game as finished or not.
 *
 * Pre: The variable state has to be defined (with a board, a user_position and a boolean variable that tells the computer if the game is finished or not). There also has to be a defined variable called finished.
 * Post: The function changes the value of the variable game_finished to the new value of the variable finished.
 */
void set_finished(State* state, int finished) {
    state -> game_finished = finished;
}

/**
 * TODO: Returns the value of is_finished flag (TRUE or FALSE), marking a game as finished.
 *
 * @param state The state to be updated.
 *
 * Pre: The variable state has to be defined.
 * Post: If the state of the game is finished, the function changes the variable of the state to game_finished and, therefore, exits the game.
 */
int is_finished(State* state) {
    return state -> game_finished;
}

/**
 * TODO: Moves the player a number of steps in the board, updating the state's current position. If the player ends up in a
 * tile containing a ladder or a snake updates the state's current position accordingly. Also, sets the state as
 * finished if it moves to or past the last tile. Returns SNAKE_FOUND or LADDER_FOUND if found, SUCCESS otherwise.
 *
 * @param board The playing board.
 * @param state The current state.
 * @param steps The number of steps to move.
 *
 * Pre: The variable state has to be defined, the game has to be on process and there has to be a new variable integer defined (the result of the dice throw).
 * Post: Changes the state of the game by changing the tile in which the player is located. If the player finds a snake, the player moves to the designated lower tile. If the player finds a ladder, the player moves to the designated upper tile.
 */
int move(State* state, int dice_value) {
    int current_position = get_current_position(state);
    int new_position = current_position + dice_value;
    int board_size = get_size(state -> board);

    if (new_position >= board_size - 1) {
        set_current_position(state, board_size - 1);
        set_finished(state, TRUE);
        return SUCCESS;
    } else {
        set_current_position(state, new_position);
    }

    Tile* tile = get_tile_at(state -> board, new_position);
    if (is_ladder(tile)) {
        set_current_position(state, tile -> target_position);
        return LADDER_FOUND;
    } else if (is_snake(tile)) {
        set_current_position(state, tile -> target_position);
        return SNAKE_FOUND;
    }

    return SUCCESS;
    /*  Vàrem fer aquest codi per al Lab 2, però ara l'hem millorat.
     *int current_position = get_current_position(state);
        int new_position = current_position + dice_value;
        int board_size = get_size(state -> board);

        if (new_position > board_size) {
            set_current_position(state, board_size);
            set_finished(state, TRUE);
        } else {
            set_current_position(state, new_position);
        }

        Tile* tile = get_tile_at(state -> board, new_position);
        if (is_ladder(&state -> board -> tiles[state -> board -> rows][state -> board -> columns]) == TRUE) {
            printf("You found a ladder!\n");
            set_current_position(state, tile -> target_position);
        } else if (is_snake(&state -> board -> tiles[state -> board -> rows][state -> board -> columns]) == TRUE) {
            printf("You found a snake!\n");
            set_current_position(state, tile -> target_position);
     */
}

/**
 * TODO: Adds a step to the state's sequence, as the last step of it.
 *
 * Pre: valid state argument (non-null pointer) and dice_value must be an integer between 1 and 6
 * Post: a new step will be added to the sequence of state's history
 */
void add_step(State* state, int dice_value) {
    add_step_as_last(&state -> history, state -> user_position, dice_value);
}


/**
 * Prints the sequence of the state.
 * @param sequence The sequence to be shown.
 *
 * Pre: valid state argument (non-null pointer)
 * Post: the sequence of state's history will be printed to the console
 */
void print_state_sequence(State* state) {
    print_sequence(&state -> history);
}


/**
 * Clear the state history and init the state again
 * @param state The current state to reset
 *
 * Pre: valid state argument (non-null pointer)
 * Post: the sequence of state's history will be cleared; the user's current position will be reset to 0; and the state will be defined as finished (FALSE)
 */
void reset(State *state) {
    clear_sequence(&state -> history);
    set_current_position(state, 0);
    set_finished(state, FALSE);
}
