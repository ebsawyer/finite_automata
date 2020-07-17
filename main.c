#include <stdio.h>
#include "dfa.h"

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

    DFA dfa_cat = new_DFA(4);

    DFA_set_transition(dfa_cat, 0, 'c', 1);
    DFA_set_transition(dfa_cat, 1, 'a', 2);
    DFA_set_transition(dfa_cat, 2, 't', 3);
    DFA_set_transition_all(dfa_cat, 3, 3);

    DFA_set_accepting(dfa_cat, 3, true);

    DFA_print(dfa_cat);
    DFA_execute(dfa_cat, "catsssssssss");

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

    // TODO: look up DFAs to make sure the transition tables are correct

}
