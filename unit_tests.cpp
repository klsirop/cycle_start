#include <iostream>
#include <vector>
#include "cycle_start.h"

using namespace std;

void	PrintList(Node *head) {
	if (!head)
		return ;

	Node *tmp = head;

	cout << "list:";
	while (tmp != NULL) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void	create_list(Node* &head, const vector<int>& v) {
	if (v.empty())
		return ;

	Node *tmp = new Node;
	tmp->value = v[0];
	tmp->next = NULL;
	head = tmp;

	size_t size = v.size();
	for (int i = 1; i < size; i++) {
		tmp->next = new Node;
		tmp = tmp->next;
		tmp->value = v[i];
		tmp->next = NULL;
	}
}

void	delete_list(Node* &head) {
	Node *tmp = head;

	while (tmp) {
		head = head->next;
		free(tmp);
		tmp = NULL;
		tmp = head;
	}
}

void	do_cycle(Node* &head, size_t start_cycle, size_t end_cycle) {
	Node *tmp = head;
	int i = 0;
	Node *first_cycle = NULL;
	Node *last_cycle = NULL;
	Node *end_list = NULL;

	while (tmp) {
		if (i == start_cycle) {
			first_cycle = tmp;
		}
		if (i == end_cycle) {
			last_cycle = tmp;
		}
		if (!tmp->next)
			end_list = tmp;
		i++;
		tmp = tmp->next;
	}
	if (!first_cycle || !last_cycle)
		throw runtime_error("can't do cycle: start cycle is bigger than list size");
	last_cycle->next = first_cycle;
}

void	create_cycle_list(Node* &head, vector<int> v, size_t start_cycle, size_t end_cycle) {

	create_list(head, v);
	try {
		do_cycle(head, start_cycle, end_cycle);
	} catch (exception &ex) {
		cout << ex.what() << endl;
	}
}

void	assert_equal(vector<int> v, int num, int &failes) {
	Node *head_not_cycle = NULL;
	create_list(head_not_cycle, v);
	Node *cycle_start = cycleStart(head_not_cycle);
	if (cycle_start != NULL) {
		cerr << "test_not_cycle_" << num <<  " failes" << endl;
		failes++;
	}
	if (head_not_cycle)
		delete_list(head_not_cycle);
}

int	tests_not_cycle() {
	int failes = 0;

	//test1
	assert_equal({}, 1, failes);

	//test2
	assert_equal({1}, 2, failes);

	//test3
	assert_equal({1, 2}, 3, failes);

	//test4
	assert_equal({1, 2, 3, 4, 5}, 4, failes);

	return (failes);
}

/*
** test form : (list, start_cycle, end_cycle, right_answer, test_number, failes_counter)
*/
void	assert_equal_cycle(vector<int> v, size_t start, size_t end, int result, int num, int &failes) {
	Node *head_cycle = NULL;
	create_cycle_list(head_cycle, v, start, end);
	Node *cycle_start = cycleStart(head_cycle);
	if (!cycle_start || cycle_start->value != result) {
		cerr << "test_cycle_" << num << " failes" << endl;
		failes++;
	}
}

int tests_random_cycle() {
	int failes = 0;
	//test1
	assert_equal_cycle({1, 2, 3}, 0, 0, 1, 1, failes);

	//test2
	assert_equal_cycle({1, 2, 3}, 1, 1, 2, 2, failes);

	//test3
	assert_equal_cycle({1, 2, 3}, 2, 2, 3, 3, failes);

	//test4
	assert_equal_cycle({1, 2, 3}, 1, 2, 2, 4, failes);

	//test5
	assert_equal_cycle({1, 2, 3}, 0, 1, 1, 5, failes);

	//test6
	assert_equal_cycle({1, 2, 3, 4}, 1, 2, 2, 6, failes);

	//test7
	assert_equal_cycle({1, 2, 3, 4}, 2, 3, 3, 7, failes);

	//test8
	assert_equal_cycle({1, 2, 3, 4}, 0, 1, 1, 8, failes);

	//test9
	assert_equal_cycle({1, 2, 3, 4}, 1, 3, 2, 9, failes);

	//test10
	assert_equal_cycle({1, 2, 3, 4}, 0, 2, 1, 10, failes);

	//test11
	assert_equal_cycle({1, 2, 3, 4, 5}, 2, 4, 3, 11, failes);

	//test12
	assert_equal_cycle({1, 2, 3, 4, 5}, 1, 3, 2, 12, failes);

	//test13
	assert_equal_cycle({1, 2, 3, 4, 5}, 0, 2, 1, 13, failes);
	return (failes);
}

int tests_full_cycle() {
	int failes = 0;

	//test14
	assert_equal_cycle({1, 2, 3, 4, 5}, 0, 4, 1, 14, failes);

	//test15
	assert_equal_cycle({1}, 0, 0, 1, 15, failes);

	//test16
	assert_equal_cycle({1, 2}, 0, 1, 1, 16, failes);
	return (failes);
}

void test_all() {
	int failes = 0;

	failes += tests_not_cycle();
	failes += tests_random_cycle();
	failes += tests_full_cycle();

	if (!failes)
		cerr << "All tests OK" << endl;
}

int main() {
	test_all();

	return (0);
}
