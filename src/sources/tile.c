#include "../headers/tile.h"
//#include "../headers/board_utils.h"

/**
 * @param tile The tile to be initialized.
 * @param position The position of the tile.
 *
 * Pre: The variable tile has to be defined (with a position and a target_position) and a new position variable has to be defined (the result of the dice throw).
 * Post: The variable of position of the tile has to change to the new value of the new position and the variable target_position has to "aim" to an empty target.
 */
void init_tile(Tile* tile, int position) {
    tile -> position = position;
    tile -> target_position = position;
}

/**
 * @param tile The tile to be queried.
 * @return The position of the tile.
 *
 * Pre: The variable tile has to be defined (with a position and a target_position).
 * Post: The functions returns the variable position of the tile previously defined.
 */
int get_position(Tile* tile) {
    return tile -> position;
}

/**
 * @param tile The tile to be queried.
 * @return The position the tile targets or EMPTY_TARGET, if does not target another tile.
 *
 * Pre: The variable tile has to be defined (with a position and a target_position).
 * Post: The functions returns the variable target_position of the tile previously defined.
 */
int get_target_position(Tile* tile) {
    return tile -> target_position;
}

/**
 * @param tile The tile to be modified.
 * @return INVALID_POSITION if the target_position is less than 0, SUCCESS otherwise.
 *
 * Pre: There has to be a defined tile (with a position and a target_position) and a new variable target_position to substitute the value of the tile and the  target_position has to be greater than 0.
 * Post: The function changes the value of the target_position of the tile to the new value of the parameter.
 */
int set_target_position(Tile* tile, int target_position) {
    if (target_position < 0) {
        return INVALID_POSITION;
    }
    tile -> target_position = target_position;
    return SUCCESS;
}

/**
 * @param tile The tile to be modified.
 *
 * Pre: There has to be a defined tile (with a position and a target_position).
 * Post: The function changes the value of the variable target_position of the tile to the value empty_target.
 */
void clear_target_position(Tile* tile) {
    tile -> target_position = EMPTY_TARGET;
}

/**
 * @param tile The tile to be queried.
 * @return TRUE if the tile contains a ladder.
 *
 * Pre: There has to be a defined tile (with a position and a target_position).
 * Post: Returns TRUE if the value of teh variable target_position of the tile is greater than the value of the variable position and FALSE if not.
 */
int is_ladder(Tile* tile) {
    if (tile -> target_position > tile -> position) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @param tile The tile to be queried.
 * @return TRUE if the tile contains a snake, FALSE otherwise.
 *
 * Pre: There has to be a defined tile (with a position and a target_position).
 * Post: Returns TRUE if the value of the variable position of the tile is greater than the value of the variable target_position and FALSE if not.
 */
int is_snake(Tile* tile) {
    if (tile -> target_position < tile -> position) {
        return TRUE;
    }
    return FALSE;
}
