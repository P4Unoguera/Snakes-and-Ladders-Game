#include <stdlib.h>
#include <stdio.h>

#include "../headers/sequence.h"

/**
 * TODO: Initializes a sequence, setting the initial values of the structure according to the implementation.
 *
 * Pre: sequence is a valid pointer to a Sequence structure
 * Post: initializes initial_step and last_step to NULL, and size to 0
 */
void init_sequence(Sequence* sequence) {
    sequence -> initial_step = NULL;
    sequence -> last_step = NULL;
    sequence -> size = 0;
}

/**
 * TODO: Adds a step, creating it if needed, as the first step of the sequence.
 *
 * Pre: the arguments are valid variables (pointer, integer and integer)
 * Post: adds a new step at the beginning of the sequence (this can be: if the sequence is empty, the new step becomes the 'initial_step' and 'last_step'; is the sequence is not empty, the new step is added before the current initial_step and the initial_step pointer is updated to the newly added step; the size of the sequence is incremented by 1 after adding the new step)
 */
void add_step_as_first(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*) malloc (sizeof(Step));
    step -> dice_value = dice_value;
    step -> resulting_position = position;
    step -> next_step = NULL;

    if(sequence -> initial_step == NULL) {      // Si la seqüència està buida
        sequence -> initial_step = step;
        sequence -> last_step = step;
    }
    else {      // Si ja hi ha passos, afegir-ne de nous
        step -> next_step = sequence -> initial_step;
        sequence -> initial_step = step;
    }

    sequence -> size++;
}

/**
 * TODO: Adds a step, creating it if needed, as the last step of the sequence.
 *
 * Pre: the arguments are valid variables (pointer, integer and integer)
 * Post: adds a new step at the end of the sequence (this can be: if the sequence is empty, the new step becomes the 'initial_step' and 'last_step'; is the sequence is not empty, the new step is added before the current initial_step and the initial_step pointer is updated to the newly added step; the size of the sequence is incremented by 1 after adding the new step)
 */
void add_step_as_last(Sequence* sequence, int position, int dice_value) {
    Step* step = (Step*) malloc (sizeof(Step));
    step -> dice_value = dice_value;
    step -> resulting_position = position;
    step -> next_step = NULL;

    if(sequence -> initial_step == NULL) {
        sequence -> initial_step = step;
        sequence -> last_step = step;
    }
    else {
        sequence -> last_step -> next_step = step;
        sequence -> last_step = step;
    }

    sequence -> size++;
}

/**
 * TODO: Returns the number of steps stored in the sequence.
 *
 * Pre: sequence is a valid pointer to a Sequence structure
 * Post: returns a integer number of the size
 */
int get_sequence_size(Sequence* sequence) {
    return sequence -> size;
}

/**
 * Deletes (freeing if needed) all the steps stored in the sequence.
 * @param sequence The sequence to be cleared.
 *
 * Pre: sequence is a valid pointer to a Sequence structure
 * Post: deletes all the steps stored in the Sequence and sets the initial_step, last_step ans size to NULL and 0
 */
 void clear_sequence(Sequence* sequence) {
    Step* step = sequence -> initial_step;
    while (step != NULL) {
        Step* next_step = step -> next_step;
        free(step);
        step = next_step;
    }
    sequence -> initial_step = NULL;
    sequence -> last_step = NULL;
    sequence -> size = 0;
}

/**
 * Prints the sequence of moves leading to the state.
 * @param sequence The sequence to be shown.
 *
 * Pre: sequence is a valid pointer to a Sequence structure
 * Post: prints the sequence of moves
 */
void print_sequence(Sequence* sequence) {
    Step *step = sequence -> initial_step;
    while(step != NULL) {
        printf("(%d, %d)\n", step -> dice_value, step -> resulting_position);
        step = step -> next_step;
    }
}
