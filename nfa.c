//
// Created by Ethan Sawyer on 7/14/20.
//

#include "nfa.h"
#include <stdbool.h>
#include <stdlib.h>
#include "Set.h"

/**
 * The data structure used to represent a nondeterministic finite automaton.
 * @see FOCS Section 10.3
 * @see Comments for DFA in dfa.h
 */
typedef struct NFA {
    int numStates;
    int numInputs;
    int **tFunction
};

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFA new_NFA(int numStates) {
    NFA this = (NFA) malloc(sizeof(struct NFA));
    if (this == NULL) {
        return NULL; // Out of memory
    }
    this->numStates = numStates;
    this->numInputs = 128;
    /*
     * The array should have columns ranging from 0 - 128 (inclusive)
     * and the number of rows should be equal to the number of states
     */
};

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA nfa);

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA nfa);

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern Set NFA_get_transitions(NFA nfa, int state, char sym);

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA nfa, int src, char sym, int dst);

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst);

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA nfa, int src, int dst);

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA nfa, int state, bool value);

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFA nfa, int state);

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool NFA_execute(NFA nfa, char *input);

/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA nfa);
