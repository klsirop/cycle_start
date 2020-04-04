#ifndef CYCLE_START_H
# define CYCLE_START_H

struct Node {
  int value;
  struct Node *next;
};

/*
** unit_tests.cpp
*/

void	test_all();

/*
** cycle_start.cpp
*/

struct Node* cycleStart(struct Node* head);

#endif
