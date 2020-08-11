//
// Created by Ethan Sawyer on 7/19/20.
//

#ifndef PROJECT1_TRANSLATOR_H
#define PROJECT1_TRANSLATOR_H

#include "dfa.h"
#include "nfa.h"
#include "Set.h"
#include "LinkedList.h"

typedef struct Translator *Translator;

extern Translator new_Translator();

extern void Translator_free(Translator translator);

extern DFA NFA_to_DFA(NFA nfa);

extern void set_inputs(Translator translator, NFA nfa);

extern void print_inputs(LinkedList linkedList);

extern void print_list_bit(LinkedList list);

extern DFA build_DFA(Translator this, NFA nfa);

extern int get_state(BitSet symbol, Translator this);

extern bool lists_contains_all_unions(LinkedList tempUnion, LinkedList states, Translator translator, BitSet currState);

#endif //PROJECT1_TRANSLATOR_H
