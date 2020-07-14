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
    int initialState;
    int numStates;
    int numInputs;
    int **tfunction;
};

/**
 * Allocate and return a new DFA containing the given number of states.
 */
extern DFA new_DFA(int numStates) {
    DFA this = (DFA) malloc(sizeof(struct DFA));
    this->initialState = 0;
    this->numStates = numStates;
    this->numInputs = 128;
    this->tfunction = (int **) calloc(130, sizeof(int *));
    for (int k = 0; k < 130; k++) {
        this->tfunction[k] = (int *) calloc(129, sizeof(int));
    }

    for (int r = 0; r < numStates + 2; r++) { //because of boolean value that can be 0, and calc sets all to 0
        for (int c = 0; c < 131; c++) {
            this->tfunction[r][c] = -1;
        }
    }

    return this; //returns the dfa with the characteristic determined above
}

//// TODO: fix the function below
///**
// * Free the given DFA.
// */
//extern void DFA_free(DFA dfa) {
//
//}
//
///**
// * Return the number of states in the given DFA.
// */
//extern int DFA_get_size(DFA dfa) {
//    return dfa->numStates;
//}
//
///**
// * Return the state specified by the given DFA's transition function from
// * state src on input symbol sym.
// */
//extern int DFA_get_transition(DFA dfa, int src, char sym) {
//    return dfa->tfunction[src][(int) sym];
//}
//
///**
// * For the given DFA, set the transition from state src on input symbol
// * sym to be the state dst.
// */
//extern void DFA_set_transition(DFA dfa, int src, char sym, int dst) {
//    //  printf("Bullshit in set transition\n");
//    //  printf("in in: %d",(int)sym);
//    //  printf("in in: %c",sym);
//    //  printf("%d",dfa -> tfunction [src][(int)sym]);
//    // int** tf= dfa ->tfunction;
//    dfa->tfunction[src][(int) sym] = dst; //making a transition on sym from current state to destination
//    //and storing it in a transition table
//
//    // printf("after set trans");
//}
//
//// TODO: fix the two functions below
//int string_length(char string[]) {
//    int c = 0;
//    while (string[c] != '\0')
//        c++;
//    return c;
//}
//
///**
// * Set the transitions of the given DFA for each symbol in the given str.
// * This is a nice shortcut when you have multiple labels on an edge between
// * two states.
// */
//extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst) {
//    int strSize = string_length(str);
//    for (int i = 0; i <= strSize; i++) {
//        DFA_set_transition(dfa, src, str[i], dst);
//    }
//}
//
//// TODO: not sure if the below function needs to be implemented
//
///**
// * Set the transitions of the given DFA for all input symbols.
// * Another shortcut method.
// */
//extern void DFA_set_transition_all(DFA dfa, int src, int dst) {
//
//}
//
///**
// * Set whether the given DFA's state is accepting or not.
// */
//extern void DFA_set_accepting(DFA dfa, int state, bool value) {
//    dfa->tfunction[state][128] = value;
//}
//
///**
// * Return true if the given DFA's state is an accepting state.
// */
//extern bool DFA_get_accepting(DFA dfa, int state) {
//    printf("state is %d \n", state);
//
//    bool temp = dfa->tfunction[state][128];
//    printf("state is %d  and value of temp is %d\n", state, temp);
//
//    if (temp == 1) {
//        return true;
//    } else {
//        return false;
//    }
//}
//
///**
// * Run the given DFA on the given input string, and return true if it accepts
// * the input, otherwise false.
// */
//extern bool DFA_execute(DFA dfa, char *input) {
//
//    int tempState = dfa->initialState;
//    int inputSize = string_length(input);
//    printf("I am in execute 2 and the input size is %d ", inputSize);
//
//    for (int i = 0; i < inputSize; i++) {
//        //printf("I am in execute loop\n");
//        tempState = DFA_get_transition(dfa, tempState, input[i]);
//        if (tempState == -1) {
//            printf("in condition");
//            return false;
//
//        }
//        printf("I am in state : %d\n", tempState);
//    }
//    printf("value of our last cell %d", dfa->tfunction[6][128]);
//    return DFA_get_accepting(dfa, tempState);
//
//}

/**
 * Print the given DFA to System.out.
 */
extern void DFA_print(DFA dfa) {
    printf("This DFA has %d states\n", dfa->numStates);
    //printf("%i", dfa->tfunction[8][0]);
    for (int r = 0; r < dfa->numStates + 2; r++) {
        for (int c = 0; c < 131; c++) {
            printf("%i", dfa->tfunction[r][c]);
        }//because of boolean value that can be 0, and calc sets all to 0
        printf("\n");
    }


//    for (int i = 0; i < dfa->numStates; i++) {
//        for (int j = 0; j < dfa->numInputs + 1; j++) {
//            // if(dfa -> tfunction[i][j]= 0 && i=0)
//            //     continue;
//            // else
//            // {
//            printf("%s\t", dfa->tfunction[i][j]);
//            // }
//        }
//        printf("\n");
//    }
}