#include <iostream>
#include <vector>
#include "cycle_start.h"

using namespace std;

/*
** return NULL if there is no cycle
** else return an element that is in cycle
*/
struct Node* find_el_in_loop(Node *head) {
	Node *step_one = head;
	Node *step_two = head;

	if (!step_one || !step_two || !step_two->next)
		return NULL;
	do {
		step_one = step_one->next;
		step_two = step_two->next;
			if (step_two)
				step_two = step_two->next;
	} while (step_one != NULL && step_two != NULL && step_one != step_two);
	if (!step_one || !step_two)
		return NULL;
	return step_one;
}

size_t find_cycle_len(Node * el_in_cycle) {
	Node *tmp = el_in_cycle;
	size_t cycle_len = 0;

	do {
		tmp = tmp->next;
		cycle_len++;
	} while (tmp != el_in_cycle);

	return (cycle_len);
}

struct Node *find_cycle_start(Node *head, Node *el_in_cycle, size_t cycle_len) {
	Node *one_step = head;
	Node *two_step = head;

	for (int i = 0; i < cycle_len; i++) {
		two_step = two_step->next;
	}
	if (two_step == one_step) {
		/*
		** this is ring
		*/
		return two_step;
	}
	do {
		one_step = one_step->next;
		two_step = two_step->next;
	} while (one_step != two_step);
	return one_step;
}

struct Node* cycleStart(struct Node* head) {
	if (!head)
		return NULL;

	Node *el_in_cycle = find_el_in_loop(head);
	if (!el_in_cycle) {
		return NULL;
	}

	size_t cycle_len = find_cycle_len(el_in_cycle);

	Node *cycle_start = find_cycle_start(head, el_in_cycle, cycle_len);
	return cycle_start;
}
