//
// Created by Ethan Sawyer on 7/14/20.
//

#include "nfa.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Set.h"
#include "BitSet.h"
#include <string.h>

// TODO: remove Set.h & IntHashSet.h files if not needed

/**
 * The data structure used to represent a nondeterministic finite automaton.
 * @see FOCS Section 10.3
 * @see Comments for DFA in dfa.h
 */
struct NFA {
    int numStates;
    int numInputs;
    BitSet **tFunction;
    BitSet initState;
};

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFA new_NFA(int numStates) {
    NFA this = (NFA) malloc(sizeof(struct NFA));
    if (this == NULL) {
        return NULL; // Out of memory
    }
    this->initState = new_BitSet();
    BitSet_insert(this->initState, 0);
    this->numStates = numStates;
    this->numInputs = 128;
    /*
     * The array should have columns ranging from 0 - 128 (inclusive)
     * and the number of rows should be equal to the number of states
     */
    this->tFunction = (BitSet **) calloc(numStates, sizeof(BitSet *));
    for (int r = 0; r <= numStates - 1; r++) {
        this->tFunction[r] = (BitSet *) calloc(129, sizeof(BitSet));
    }

    for (int r = 0; r <= numStates - 1; r++) {
        for (int c = 0; c <= 128; c++) {
            this->tFunction[r][c] = new_BitSet();
        }
    }

    return this;
}

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA nfa);

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA nfa) {
    return nfa->numStates;
}

extern BitSet **NFA_get_tFunction(NFA nfa) {
    return nfa->tFunction;
}


/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern Set NFA_get_transitions(NFA nfa, int state, char sym) {
    return nfa->tFunction[state][(int) sym];
}

// TODO: fix the function below
int NFA_string_length(char *input) {
    int c = 0;
    while (input[c] != '\0')
        c++;
    return c;
}

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA nfa, int src, char sym, int dst) {
    BitSet_insert(nfa->tFunction[src][(int) sym], dst);
}

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst);

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA nfa, int src, int dst) {
    for (int i = 0; i <= 128; i++) {
        BitSet_insert(nfa->tFunction[src][i], dst);
    }
}

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA nfa, int state, bool value) {
    BitSet_insert(nfa->tFunction[state][128], value);
}


/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFA nfa, int state) {
    return BitSet_lookup(nfa->tFunction[state][128], 1);
}

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool NFA_execute(NFA nfa, char *input) {
    int inputSize = NFA_string_length(input);
    BitSet currStateSet = new_BitSet();
    BitSet_insert(currStateSet, 0);
    printf("Current string: %s\n", input);
    printf("Input size: %i\n", inputSize);

    for (int i = 0; i < inputSize; i++) {
        printf("Current input: %c\n", input[i]);
        printf("Current state: ");
        BitSet_print(currStateSet);
        printf("\n");
        BitSetIterator iterator = BitSet_iterator(currStateSet);
        while (BitSetIterator_hasNext(iterator)) {
            int currState = BitSetIterator_next(iterator);
            printf("Current tested state: %i\n", currState);
            BitSet newState = NFA_get_transitions(nfa, currState, input[i]);
            BitSet_print(newState);
            printf("\n");
            currStateSet = new_BitSet();
            BitSet_union(currStateSet, newState);
            printf("Updated State: ");
            BitSet_print(currStateSet);
            printf("\n");
        }
    }
    bool finalVal = false;
    BitSet_print(currStateSet);
    printf("\n");
    BitSetIterator new = BitSet_iterator(currStateSet);
    while (BitSetIterator_hasNext(new)) {
        if (NFA_get_accepting(nfa, BitSetIterator_next(new)) == true) {
            printf("Accepted!\n");
            finalVal = true;
        }
    }
    return finalVal;
}

/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA nfa) {
    printf("This NFA has %d states\n", nfa->numStates);
    for (int r = 0; r <= nfa->numStates - 1; r++) {
        for (int c = 0; c <= 128; c++) {
            BitSet_print(nfa->tFunction[r][c]);
        }
        printf("\n");
    }
}
