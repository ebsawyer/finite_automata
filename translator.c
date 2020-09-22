//
// Created by Ethan Sawyer on 7/19/20.
//

#include "translator.h"
#include "nfa.h"
#include "dfa.h"
#include "BitSet.h"
#include <stdbool.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <stdio.h>

struct Translator {
    DFA outputDFA;
    int numStates;
    LinkedList inputs;
    LinkedList states;
    BitSet currState;
    LinkedList finList;
};

extern Translator new_Translator() {
    Translator this = (Translator) malloc(sizeof(struct Translator));
    if (this == NULL) {
        return NULL; // Out of memory
    }
    this->numStates = 1;
    this->inputs = new_LinkedList();
    this->currState = new_BitSet();
    BitSet_insert(this->currState, 0);
    this->states = new_LinkedList();
    this->finList = new_LinkedList();

    return this;
}

extern void Translator_free(Translator translator) {

}

extern void set_inputs(Translator translator, NFA nfa) {

    for (int r = 0; r <= NFA_get_size(nfa) - 1; r++) {
        for (int c = 0; c <= 127; c++) {
            if (BitSet_isEmpty(NFA_get_tFunction(nfa)[r][c]) == false) {
                //printf("Input: %i\n", c);
                char *input = (char *) malloc(sizeof(char));
                *input = (char) c;
                //printf("%c\n", *input);
                bool contains = false;
                LinkedListIterator iterator = LinkedList_iterator(translator->inputs);
                while (LinkedListIterator_hasNext(iterator)) {
                    char *inputInList = LinkedListIterator_next(iterator);
                    if (*input == *inputInList) {
                        contains = true;
                    }
                }
                if (contains != true) {
                    LinkedList_add_at_end(translator->inputs, input);
                }
            }
        }
    }
    // print_inputs(translator->inputs);
}

extern void print_inputs(LinkedList inputs) {

    LinkedListIterator iterator = LinkedList_iterator(inputs);
    while (LinkedListIterator_hasNext(iterator)) {
        char *input = LinkedListIterator_next(iterator);
        //  printf("%c", *input);

    }
    //printf("hi");
    // printf("\n");
}

// TODO: fix this function
extern bool
lists_contains_all_unions(LinkedList unionList, LinkedList stateList, Translator translator, BitSet currState) {

    LinkedListIterator unionIterator = LinkedList_iterator(unionList);
    //  printf("Comparing lists...\n");
    //  printf("Big S list: ");
    //  print_list_bit(stateList);
    //  printf("\n");
    //  printf("Union list: ");
    //   print_list_bit(unionList);
    //   printf("\n");
    bool final = true;
    //bool checker = false;
    //for each union
    while (LinkedListIterator_hasNext(unionIterator)) {
        // TODO: could be the problem
        bool checker = false;
        //bool final = true;

        BitSet currUnion = LinkedListIterator_next(unionIterator);
        //printf("Current  union: ");
        //BitSet_print(currUnion);
        // printf("\n");
        //for each state
        LinkedListIterator stateIterator = LinkedList_iterator(stateList);
        while (LinkedListIterator_hasNext(stateIterator)) {
            BitSet currState = LinkedListIterator_next(stateIterator);
            //printf("Current big S state: ");
            //BitSet_print(currState);
            //printf("\n");
            //printf("Output: %i", BitSet_equals(currState, currUnion));
            //printf("\n");
            //printf("checker %i\n", checker);
            if (BitSet_equals(currState, currUnion)) {
                //printf("In this conditional\n");
                checker = true;
            }


//            if (BitSet_equals(currState, currUnion) == false ) {
//                printf("In this conditional\n");
//                BitSet empty = new_BitSet();
//                //if (BitSet_equals(currUnion, empty) == false) {
//                    LinkedList_add_at_end(translator->states, currUnion);
//                //8}
//                print_list_bit(translator->states);
//                printf("\n");
//                final = false;
//            }
        }
        //printf("FINALLLLL b4 the if: %i\n", final);
        if (checker == false) {
            //printf("checker is false\n");
            BitSet empty = new_BitSet();
            if (BitSet_equals(currUnion, empty) == false) {
                //printf("hiyaa\n");
                translator->numStates++;
                LinkedList_add_at_end(stateList, currUnion);
                translator->currState = currUnion;
                //printf("Current state: ");
                //BitSet_print(translator->currState);
                //printf("\n");
            }
            //printf("FINALLLLL b4: %i\n", final);
            final = false;
            //printf("FINALLLLL: %i\n", final);
            break;
        }
    }
    //printf("Result: %i\n", final);
    return final;
}

extern void print_list_bit(LinkedList list) {
    LinkedListIterator listIterator = LinkedList_iterator(list);
    while (LinkedListIterator_hasNext(listIterator)) {
        BitSet temp = LinkedListIterator_next(listIterator);
        //BitSet_print(temp);
    }
}

extern int get_state(BitSet symbol, Translator this) {

    int returnState;
    int currState = 0;
    LinkedListIterator bigSIterator = LinkedList_iterator(this->finList);
    while (LinkedListIterator_hasNext(bigSIterator)) {
        BitSet tempBigS = LinkedListIterator_next(bigSIterator);
        if (BitSet_equals(symbol, tempBigS)) {
            returnState = currState;
        }
        currState++;
    }
    return returnState;
}

extern DFA build_DFA(Translator this, NFA nfa) {

    DFA returnDFA = new_DFA(this->numStates);

    //printf("Big S states list: ");
    // print_list_bit(this->finList);
    //printf("\n");


    //iterate through states in BIG S
    LinkedListIterator bigSIterator = LinkedList_iterator(this->finList);
    while (LinkedListIterator_hasNext(bigSIterator)) {
        BitSet tempBigS = LinkedListIterator_next(bigSIterator);
        //printf("S: ");
        // BitSet_print(tempBigS);
        //printf("\n");

        //iterate through the alphabet of inputs
        LinkedListIterator inputIterator = LinkedList_iterator(this->inputs);
        while (LinkedListIterator_hasNext(inputIterator)) {
            BitSet tempTransitions = new_BitSet();
            char *currInput = LinkedListIterator_next(inputIterator);
            // printf("Current input: %c\n", *currInput);
            int tempState;
            //Iterate through states in a BIG S state
            BitSetIterator currStateIterator = BitSet_iterator(tempBigS);
            while (BitSetIterator_hasNext(currStateIterator)) {
                tempState = BitSetIterator_next(currStateIterator);
                //printf("Current state: %i\n", tempState);
                if (NFA_get_accepting(nfa, tempState)) {
                    DFA_set_accepting(returnDFA, get_state(tempBigS, this), true);
                }
                //printf("Transition: ");
                //    BitSet_print(NFA_get_transitions(nfa, tempState, *currInput));
                //printf("\n");
                BitSet_union(tempTransitions, NFA_get_transitions(nfa, tempState, *currInput));
            }
            //printf("Union: ");
            // BitSet_print(tempTransitions);
            //printf("\n");
            // printf("Big s state number: %i\n", get_state(tempBigS, this));
            // printf("Current input: %c\n", *currInput);
            // printf("Transition state number: %i\n", get_state(tempTransitions, this));


            DFA_set_transition(returnDFA, get_state(tempBigS, this), *currInput, get_state(tempTransitions, this));
            //DFA_set_transition_str(returnDFA, get_state(tempBigS, this), *currInput, get_state(tempTransitions, this));

        }
    }
    // DFA_print(returnDFA);
    return returnDFA;
}

extern DFA NFA_to_DFA(NFA nfa) {
    Translator this = new_Translator();

    set_inputs(this, nfa);
    //  int numStates = 0;

    //Sets the first state as {0}
    //BitSet currState = this->currState;
    LinkedList_add_at_end(this->states, this->currState);

    //Keeps track of the union of the current state
    LinkedList tempUnion = new_LinkedList();
    //Adds an empty BitSet to the tempUnion.
    //This is only used so program doesn't crash
    BitSet empty = new_BitSet();
    LinkedList_add_at_end(tempUnion, empty);
    while (lists_contains_all_unions(tempUnion, this->states, this, this->currState) == false) {
        //for (int k = 0; k < 4; k++) {
        //printf("THESE RESULTS: %i\n", lists_contains_all_unions(tempUnion, this->states, this, this->currState));

        //("Big S states list: ");
        // print_list_bit(this->states);
        //printf("\n");
        tempUnion = new_LinkedList();

        //  printf("S: ");
        //   BitSet_print(this->currState);
        //  printf("\n");
        //Traversing each input in the alphabet
        LinkedListIterator iterator = LinkedList_iterator(this->inputs);
        while (LinkedListIterator_hasNext(iterator)) {
            BitSet tempTransitions = new_BitSet();
            char *currInput = LinkedListIterator_next(iterator);
            // printf("Current input: %c\n", *currInput);
            //Traversing each state in the state BitSet
            BitSetIterator stateIterator = BitSet_iterator(this->currState);
            while (BitSetIterator_hasNext(stateIterator)) {
                int tempState = BitSetIterator_next(stateIterator);
                //    printf("Current state: %i\n", tempState);
                //    printf("Transition: ");
                //   BitSet_print(NFA_get_transitions(nfa, tempState, *currInput));
                BitSet_union(tempTransitions, NFA_get_transitions(nfa, tempState, *currInput));
                //   printf("\n");
                //   print_list_bit(this->states);
                //   printf("\n");

                //DFA_set_transition(this->outputDFA, tempState, *currInput, get_state(this, nfa));

            }
            // TODO: below function might not work
            LinkedList_add_at_end(tempUnion, tempTransitions);
            //printf("Union: ");
            // BitSet_print(tempTransitions);
            // printf("\n");
        }
        // printf("Union States: ");
        // print_list_bit(tempUnion);
        // printf("\n");

    }


    //LinkedList temp = this->states;
    // printf("The States of the DFA: ");
    // print_list_bit(this->states);
    this->finList = this->states;
    // printf("\n");
    // printf("\n");
    // printf("Build DFA function\n");


    //  printf("\n");
    //  printf("Number of states: %i\n", this->numStates);
    //this->outputDFA = new_DFA(this->numStates);

    return build_DFA(this, nfa);
//    DFA_print(this->outputDFA);
    //return this->outputDFA;

}