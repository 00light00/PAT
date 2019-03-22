#include<bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node* next;
	node(int val_ = -1) :val(val_), next(NULL) {};
};

node* insert() {
	int i;
	scanf("%d", &i);
	node* head = new node;
	while (i >= 0) {
		node* p = new node(i);
		p->next = head->next;
		head->next = p;
		scanf("%d", &i);
	}
	return head;
}

void print(int i, node*first) {
	while (i--&&first != NULL) {
		first = first->next;
	}
	if (first)
		printf("%d", first->val);
	else
		printf("NULL\n");
}

int main() {
	int k;
	scanf("%d", &k);
	node* first = insert();
	print(k, first);
	return 0;
}