//
// Created by Ethan Sawyer on 7/10/20.
//

#include "dfa.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * The data structure used to represent a deterministic finite automaton.
 * @see FOCS Section 10.2
 * Note that YOU must specify this data structure, although you can hide
 * (encapsulate) its implementation behind the declared API functions and
 * only provide a partial declaration in the header file.
 */
struct DFA {
    int numStates;
    int numInputs;
    int **tFunction;
};

/**
 * Allocate and return a new DFA containing the given number of states.
 */
extern DFA new_DFA(int numStates) {
    DFA this = (DFA) malloc(sizeof(struct DFA));
    if (this == NULL) {
        return NULL; // Out of memory...
    }
    this->numStates = numStates;
    this->numInputs = 128;
    /*
     * The array should have columns ranging from 0 - 128 (inclusive)
     * and the number of rows should be equal to the number of states
     */
    this->tFunction = (int **) calloc(numStates, sizeof(int *));
    for (int r = 0; r <= numStates - 1; r++) {
        this->tFunction[r] = (int *) calloc(129, sizeof(int));
    }

    for (int r = 0; r <= numStates - 1; r++) {
        for (int c = 0; c <= 128; c++) {
            this->tFunction[r][c] = -1;
        }
    }

    return this;
}

// TODO: fix the function below
/**
 * Free the given DFA.
 */
extern void DFA_free(DFA dfa) {


}

/**
 * Return the number of states in the given DFA.
 */
extern int DFA_get_size(DFA dfa) {
    return dfa->numStates;
}

/**
 * Return the state specified by the given DFA's transition function from
 * state src on input symbol sym.
 */
extern int DFA_get_transition(DFA dfa, int src, char sym) {
    return dfa->tFunction[src][(int) sym];
}

/**
 * For the given DFA, set the transition from state src on input symbol
 * sym to be the state dst.
 */
extern void DFA_set_transition(DFA dfa, int src, char sym, int dst) {
    dfa->tFunction[src][(int) sym] = dst;
}

// TODO: fix the two functions below
int string_length(char string[]) {
    int c = 0;
    while (string[c] != '\0')
        c++;
    return c;
}

/**
 * Set the transitions of the given DFA for each symbol in the given str.
 * This is a nice shortcut when you have multiple labels on an edge between
 * two states.
 */
extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst) {
    int strSize = string_length(str);
    for (int i = 0; i <= strSize; i++) {
        DFA_set_transition(dfa, src, str[i], dst);
    }
}

/**
 * Set the transitions of the given DFA for all input symbols.
 * Another shortcut method.
 */
extern void DFA_set_transition_all(DFA dfa, int src, int dst) {
    for (int i = 0; i <= 128; i++) {
        dfa->tFunction[src][i] = dst;
    }

}

/**
 * Set whether the given DFA's state is accepting or not.
 */
extern void DFA_set_accepting(DFA dfa, int state, bool value) {
    dfa->tFunction[state][128] = value;
}

/**
 * Return true if the given DFA's state is an accepting state.
 */
extern bool DFA_get_accepting(DFA dfa, int state) {
    printf("Checking if state %i is accepting...\n", state);

    int temp = dfa->tFunction[state][128];
    printf("Value of state %d is %d\n", state, temp);

    if (temp == 1) {
        printf("Accepted!");
        return true;
    } else {
        printf("Not accepted!");
        return false;
    }
}

/**
 * Run the given DFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool DFA_execute(DFA dfa, char *input) {

    int currState = 0;
    int inputSize = string_length(input);
    printf("I am in execute and the input size is %d \n", inputSize);
    printf("Current state: %d\n", currState);

    for (int i = 0; i < inputSize; i++) {
        currState = DFA_get_transition(dfa, currState, input[i]);
        if (currState == -1) {
            printf("Not accepted");
            return false;

        }
        printf("Current state: %d\n", currState);
    }
    return DFA_get_accepting(dfa, currState);
}

/**
 * Print the given DFA to System.out.
 */
extern void DFA_print(DFA dfa) {
    printf("This DFA has %d states\n", dfa->numStates);
    for (int r = 0; r <= dfa->numStates - 1; r++) {
        for (int c = 0; c <= 128; c++) {
            printf("%i ", dfa->tFunction[r][c]);
        }
        printf("\n");
    }
}