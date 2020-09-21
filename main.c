#include <stdio.h>
#include "dfa.h"
#include "nfa.h"
#include "BitSet.h"
#include "translator.h"


int main() {

    //testing git

    // 1. DFAs

    // (a) Exactly the string happy
    DFA dfa_happy = new_DFA(6);
    DFA_set_transition(dfa_happy, 0, 'h', 1);
    DFA_set_transition(dfa_happy, 1, 'a', 2);
    DFA_set_transition(dfa_happy, 2, 'p', 3);
    DFA_set_transition(dfa_happy, 3, 'p', 4);
    DFA_set_transition(dfa_happy, 4, 'y', 5);
    DFA_set_accepting(dfa_happy, 5, true);
    //DFA_execute(dfa_happy, "happy");

    // (b) Any string that starts with three 9’s
    DFA dfa_three_9s = new_DFA(4);
    DFA_set_transition(dfa_three_9s, 0, '9', 1);
    DFA_set_transition(dfa_three_9s, 1, '9', 2);
    DFA_set_transition(dfa_three_9s, 2, '9', 3);
    DFA_set_transition_all(dfa_three_9s, 3, 3);
    DFA_set_accepting(dfa_three_9s, 3, true);
    //DFA_execute(dfa_three_9s, "999fsdf");

    // (c) Binary input with an even number of 1’s
    DFA even_1s = new_DFA(3);
    DFA_set_transition(even_1s, 0, '0', 0);
    DFA_set_transition(even_1s, 0, '1', 1);
    DFA_set_transition(even_1s, 1, '0', 1);
    DFA_set_transition(even_1s, 1, '1', 2);
    DFA_set_transition(even_1s, 2, '0', 2);
    DFA_set_transition(even_1s, 2, '1', 1);
    DFA_set_accepting(even_1s, 2, true);
    //DFA_execute(even_1s, "011");

    // (d) Binary input with an odd number of 0’s and an even number of 1’s
    DFA odd_0s_even_1s = new_DFA(4);
    DFA_set_transition(odd_0s_even_1s, 0, '1', 1);
    DFA_set_transition(odd_0s_even_1s, 0, '0', 3);
    DFA_set_transition(odd_0s_even_1s, 1, '1', 0);
    DFA_set_transition(odd_0s_even_1s, 1, '0', 2);
    DFA_set_transition(odd_0s_even_1s, 2, '1', 3);
    DFA_set_transition(odd_0s_even_1s, 2, '0', 1);
    DFA_set_transition(odd_0s_even_1s, 3, '1', 2);
    DFA_set_transition(odd_0s_even_1s, 3, '0', 0);
    DFA_set_accepting(odd_0s_even_1s, 3, true);
    //DFA_execute(odd_0s_even_1s, "110");

    // (e) At least one other pattern that you think is interesting
    DFA dfa_interesting = new_DFA(7);

    // 2. NFAs

    // (a) Strings ending in ing
    NFA end_ing = new_NFA(4);

    NFA_add_transition_all(end_ing, 0, 0);
    NFA_add_transition(end_ing, 0, 'i', 1);
    NFA_add_transition(end_ing, 1, 'n', 2);
    NFA_add_transition(end_ing, 2, 'g', 3);
    NFA_set_accepting(end_ing, 3, true);
    //printf("Final Value: %i",  NFA_execute(end_ing, "ing"));

    // (b) Strings containing ing
    NFA contains_ing = new_NFA(4);

    NFA_add_transition_all(contains_ing, 0, 0);
    NFA_add_transition(contains_ing, 0, 'i', 1);
    NFA_add_transition(contains_ing, 1, 'n', 2);
    NFA_add_transition(contains_ing, 2, 'g', 3);
    NFA_add_transition_all(contains_ing, 3, 3);
    NFA_set_accepting(contains_ing, 3, true);
    //printf("Final Value: %i",  NFA_execute(contains_ing, "ing"));

    // (c) Strings with more than one a,g,h,i,o,s,t,orw,or more than two n’s
    NFA washington = new_NFA(20);

    //first row a
    NFA_add_transition_all(washington, 0, 0);
    NFA_add_transition(washington, 0, 'a', 1);
    NFA_add_transition_minus(washington, 1, 'a', 1);
    NFA_add_transition(washington, 1, 'a', 2);

    //second row g
    NFA_add_transition(washington, 0, 'g', 3);
    NFA_add_transition_minus(washington, 3, 'g', 3);
    NFA_add_transition(washington, 3, 'g', 4);

    //third row h
    NFA_add_transition(washington, 0, 'h', 5);
    NFA_add_transition_minus(washington, 5, 'h', 5);
    NFA_add_transition(washington, 5, 'h', 6);

    //fourth row i
    NFA_add_transition(washington, 0, 'g', 7);
    NFA_add_transition_minus(washington, 7, 'g', 7);
    NFA_add_transition(washington, 7, 'g', 8);

    //fifth row n
    NFA_add_transition(washington, 0, 'n', 9);
    NFA_add_transition_minus(washington, 9, 'n', 9);
    NFA_add_transition(washington, 9, 'n', 10);
    NFA_add_transition_minus(washington, 10, 'n', 10);
    NFA_add_transition(washington, 10, 'n', 11);

    //sixth row o
    NFA_add_transition(washington, 0, 'o', 12);
    NFA_add_transition_minus(washington, 12, 'o', 12);
    NFA_add_transition(washington, 12, 'o', 13);

    //sixth row s
    NFA_add_transition(washington, 0, 's', 14);
    NFA_add_transition_minus(washington, 14, 's', 14);
    NFA_add_transition(washington, 14, 's', 15);

    //sixth row t
    NFA_add_transition(washington, 0, 't', 16);
    NFA_add_transition_minus(washington, 16, 't', 16);
    NFA_add_transition(washington, 16, 't', 17);

    //sixth row w
    NFA_add_transition(washington, 0, 'w', 18);
    NFA_add_transition_minus(washington, 18, 'w', 18);
    NFA_add_transition(washington, 18, 'w', 19);

    NFA_set_accepting(washington, 2, true);
    NFA_set_accepting(washington, 4, true);
    NFA_set_accepting(washington, 6, true);
    NFA_set_accepting(washington, 8, true);
    NFA_set_accepting(washington, 11, true);
    NFA_set_accepting(washington, 13, true);
    NFA_set_accepting(washington, 15, true);
    NFA_set_accepting(washington, 17, true);
    NFA_set_accepting(washington, 19, true);

    NFA_print(washington);

    //printf("Final Value: %i",  NFA_execute(washington, "nn"));

    // (e) At least one other pattern that you think is interesting

    // 3. Translator

    //NFA end_ing_2 = new_NFA(4);
    //NFA contains_ing_2 = new_NFA(4);

    //DFA_execute(NFA_to_DFA(end_ing), "ingy");
    DFA_execute(NFA_to_DFA(contains_ing), "hing");
}
