#include <stdio.h>
#include "dfa.h"
#include "nfa.h"
#include "BitSet.h"
#include "translator.h"
#include <string.h>

DFA one_a() {
    // (a) Exactly the string happy
    DFA dfa_happy = new_DFA(6);
    DFA_set_transition(dfa_happy, 0, 'h', 1);
    DFA_set_transition(dfa_happy, 1, 'a', 2);
    DFA_set_transition(dfa_happy, 2, 'p', 3);
    DFA_set_transition(dfa_happy, 3, 'p', 4);
    DFA_set_transition(dfa_happy, 4, 'y', 5);
    DFA_set_accepting(dfa_happy, 5, true);

    return dfa_happy;
}

DFA one_b() {
    // (b) Any string that starts with three 9’s
    DFA dfa_three_9s = new_DFA(4);
    DFA_set_transition(dfa_three_9s, 0, '9', 1);
    DFA_set_transition(dfa_three_9s, 1, '9', 2);
    DFA_set_transition(dfa_three_9s, 2, '9', 3);
    DFA_set_transition_all(dfa_three_9s, 3, 3);
    DFA_set_accepting(dfa_three_9s, 3, true);

    return dfa_three_9s;
}

DFA one_c() {
    // (c) Binary input with an even number of 1’s
    DFA even_1s = new_DFA(3);
    DFA_set_transition(even_1s, 0, '0', 0);
    DFA_set_transition(even_1s, 0, '1', 1);
    DFA_set_transition(even_1s, 1, '0', 1);
    DFA_set_transition(even_1s, 1, '1', 2);
    DFA_set_transition(even_1s, 2, '0', 2);
    DFA_set_transition(even_1s, 2, '1', 1);
    DFA_set_accepting(even_1s, 2, true);

    return even_1s;
}

DFA one_d() {
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

    return odd_0s_even_1s;
}

DFA one_e() {
    // (e) Exactly the string csc173
    DFA dfa_csc173 = new_DFA(7);
    DFA_set_transition(dfa_csc173, 0, 'c', 1);
    DFA_set_transition(dfa_csc173, 1, 's', 2);
    DFA_set_transition(dfa_csc173, 2, 'c', 3);
    DFA_set_transition(dfa_csc173, 3, '1', 4);
    DFA_set_transition(dfa_csc173, 4, '7', 5);
    DFA_set_transition(dfa_csc173, 5, '3', 6);
    DFA_set_accepting(dfa_csc173, 6, true);
    return dfa_csc173;


}

NFA two_a() {
    // (a) Strings ending in ing
    NFA end_ing = new_NFA(4);

    NFA_add_transition_all(end_ing, 0, 0);
    NFA_add_transition(end_ing, 0, 'i', 1);
    NFA_add_transition(end_ing, 1, 'n', 2);
    NFA_add_transition(end_ing, 2, 'g', 3);
    NFA_set_accepting(end_ing, 3, true);

    return end_ing;
}

NFA two_b() {
    // (b) Strings containing ing
    NFA contains_ing = new_NFA(4);
    NFA_add_transition_all(contains_ing, 0, 0);
    NFA_add_transition(contains_ing, 0, 'i', 1);
    NFA_add_transition(contains_ing, 1, 'n', 2);
    NFA_add_transition(contains_ing, 2, 'g', 3);
    NFA_add_transition_all(contains_ing, 3, 3);
    NFA_set_accepting(contains_ing, 3, true);

    return contains_ing;
}

NFA two_c() {
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

    return washington;
}

NFA two_d() {

    NFA ending_heyo = new_NFA(5);
    NFA_add_transition_all(ending_heyo, 0, 0);
    NFA_add_transition(ending_heyo, 0, 'h', 1);
    NFA_add_transition(ending_heyo, 1, 'e', 2);
    NFA_add_transition(ending_heyo, 2, 'y', 3);
    NFA_add_transition(ending_heyo, 3, 'o', 4);
    NFA_set_accepting(ending_heyo, 4, true);
    return ending_heyo;
}

void replDFA(DFA dfa_repl) {
    char input1[128];
    while (strcmp("quit", input1) != 0) {
        printf("Enter an input (or quit): ");
        fgets(input1, 128, stdin);
        for (int i = 127; i >= 0; i--) {
            if (input1[i] == '\n') {
                input1[i] = '\0';
            }
        }
        if (strcmp("quit", input1) != 0) {
            DFA_execute(dfa_repl, input1);
            printf("\n");
        }
    }
}

void replNFA(NFA nfa_repl) {
    char input1[128];
    while (strcmp("quit", input1) != 0) {
        printf("Enter an input (or quit): ");
        fgets(input1, 128, stdin);
        for (int i = 127; i >= 0; i--) {
            if (input1[i] == '\n') {
                input1[i] = '\0';
            }
        }
        if (strcmp("quit", input1) != 0) {
            NFA_execute(nfa_repl, input1);
            printf("\n");
        }
    }

}

int main() {
    printf("CSC 173 Project 1 by Ethan Sawyer\n\n");

    printf("Testing DFA that recognizes exactly the string happy\n");
    char input[128];
    replDFA(one_a());
    printf("\n");

    printf("Testing DFA that recognizes any string that starts with three 9’s\n");
    replDFA(one_b());
    printf("\n");

    printf("Testing DFA that recognizes binary input with an even number of 1’s\n");
    replDFA(one_c());
    printf("\n");

    printf("Testing DFA that recognizes binary input with an odd number of 0’s and an even number of 1’s\n");
    replDFA(one_d());
    printf("\n");

    printf("Testing DFA that recognizes exactly the string csc173\n");
    replDFA(one_e());
    printf("\n");

    printf("Testing NFA that recognizes strings ending in ing\n");
    replNFA(two_a());
    printf("\n");

    printf("Testing NFA that recognizes strings containing ing\n");
    replNFA(two_b());
    printf("\n");

    printf("Testing NFA that recognizes strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s\n");
    replNFA(two_c());
    printf("\n");

    printf("Testing NFA that recognizes string ending in heyo\n");
    replNFA(two_d());
    printf("\n");

    printf("Translating NFA from 1a) to a DFA\n");
    DFA convert1 = NFA_to_DFA(two_a());
    printf("States in the resulting DFA: %i\n", DFA_get_size(convert1));
    printf("Testing new DFA that recognizes strings ending in ing\n");
    replDFA(convert1);
    printf("\n");

    printf("Translating NFA from 2b) to a DFA\n");
    DFA convert2 = NFA_to_DFA(two_b());
    printf("States in the resulting DFA: %i\n", DFA_get_size(convert2));
    printf("Testing new DFA that recognizes strings containing ing\n");
    replDFA(convert2);
    printf("\n");
}