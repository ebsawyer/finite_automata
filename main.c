#include <stdio.h>
#include "dfa.h"
#include "nfa.h"
#include "BitSet.h"
#include "translator.h"


int main() {
//    DFA dfa_csc173 = new_DFA(7);
//
//    DFA_set_transition(dfa_csc173, 0, 'c', 1);
//    DFA_set_transition(dfa_csc173, 1, 's', 2);
//    DFA_set_transition(dfa_csc173, 2, 'c', 3);
//    DFA_set_transition(dfa_csc173, 3, '1', 4);
//    DFA_set_transition(dfa_csc173, 4, '7', 5);
//    DFA_set_transition(dfa_csc173, 5, '3', 6);
//
//    DFA_set_accepting(dfa_csc173, 6, true);
//
//    DFA_print(dfa_csc173);
//    DFA_execute(dfa_csc173, "csc173");

//    DFA dfa_cat = new_DFA(4);
//
//    DFA_set_transition(dfa_cat, 0, 'c', 1);
//    DFA_set_transition(dfa_cat, 1, 'a', 2);
//    DFA_set_transition(dfa_cat, 2, 't', 3);
//    DFA_set_transition_all(dfa_cat, 3, 3);
//
//    DFA_set_accepting(dfa_cat, 3, true);
//
//    DFA_print(dfa_cat);
//    DFA_execute(dfa_cat, "catsssssssss");

//    DFA even_0s = new_DFA(3);
//    DFA_set_transition(even_0s, 0, '1', 0);
//    DFA_set_transition(even_0s, 0, '0', 1);
//    DFA_set_transition(even_0s, 1, '1', 1);
//    DFA_set_transition(even_0s, 1, '0', 2);
//    DFA_set_transition(even_0s, 2, '1', 2);
//    DFA_set_transition(even_0s, 2, '0', 1);
//
//    DFA_set_accepting(even_0s, 2, true);
//
//    DFA_print(even_0s);
//    DFA_execute(even_0s, "11010");

//    DFA even_0s_1s = new_DFA(4);
//    DFA_set_transition(even_0s_1s, 0, '1', 3);
//    DFA_set_transition(even_0s_1s, 0, '0', 1);
//    DFA_set_transition(even_0s_1s, 1, '1', 2);
//    DFA_set_transition(even_0s_1s, 1, '0', 0);
//    DFA_set_transition(even_0s_1s, 2, '1', 1);
//    DFA_set_transition(even_0s_1s, 2, '0', 3);
//    DFA_set_transition(even_0s_1s, 3, '1', 0);
//    DFA_set_transition(even_0s_1s, 3, '0', 2);
//
//    DFA_set_accepting(even_0s_1s, 0, true);
//
//    DFA_print(even_0s_1s);
    //DFA_execute(even_0s_1s, "11000101");
    //DFA_execute(even_0s_1s, "0101");
    //DFA_execute(even_0s_1s, "101001");
    //DFA_execute(even_0s_1s, "110");
    //DFA_execute(even_0s_1s, "1100");

    // TODO: look up DFAs on google to make sure the transition tables are correct

//    NFA end_code = new_NFA(5);
//
//    NFA_add_transition_all(end_code, 0, 0);
//    NFA_add_transition(end_code, 0, 'c', 1);
//    NFA_add_transition(end_code, 1, 'o', 2);
//    NFA_add_transition(end_code, 2, 'd', 3);
//    NFA_add_transition(end_code, 3, 'e', 4);
//    NFA_set_accepting(end_code, 4, true);
//    NFA_print(end_code);
    //printf("Final Value: %i", NFA_execute(end_code, "code"));

    // TODO: make sure the execute command for DFA and NFA both works with the
    // TODO: running on the terminal (single and double quote issues)

//    NFA h1 = new_NFA(2);
//    NFA_add_transition(h1, 0, 'a', 0);
//    NFA_add_transition(h1, 0, 'a', 1);
//    NFA_add_transition(h1, 0, 'b', 0);
//    NFA_add_transition(h1, 0, 'b', 1);
//    NFA_add_transition(h1, 1, 'a', 1);
//    NFA_add_transition(h1, 1, 'b', 1);
//
//    NFA_set_accepting(h1, 0, true);
//    NFA_set_accepting(h1, 1, true);
//
//    NFA_print(h1);

    NFA washington = new_NFA(20);
    NFA_add_transition_all(washington, 0, 0);
    NFA_add_transition(washington, 0, 'c', 1);
    NFA_add_transition(washington, 1, 'o', 2);
    NFA_add_transition(washington, 2, 'd', 3);
    NFA_add_transition(washington, 3, 'e', 4);
    NFA_set_accepting(washington, 4, true);
    NFA_print(washington);

    DFA_execute(NFA_to_DFA(end_code), "hfuhjs hi - code");
}
