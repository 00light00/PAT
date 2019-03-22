#include<bits/stdc++.h>
using namespace std;

typedef struct node* List;
struct node {
	int val;
	node * next;
	node(int v = 0) :val(v), next(NULL) {};
};

List create() {
	List re = new node;
	List p = re;
	int val;
	scanf("%d", &val);
	while (val != -1) {
		p->next = new node(val);
		p = p->next;
		scanf("%d", &val);
	}
	return re;
}

List combine(List l1, List l2) {
	List re = new node;
	List p = re;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 && l2) {
		if (l1->val > l2->val) {
			p->next = l2;
			l2 = l2->next;
			p = p->next;
		}
		else {
			p->next = l1;
			l1 = l1->next;
			p = p->next;
		}
	}

	if (l1) {
		p->next = l1;
		l1 = NULL;
	}
	if (l2) {
		p->next = l2;
		l2 = NULL;
	}
	return re;
}

void print(List l) {
	int flag = 0;
	if (l->next == NULL)
		printf("NULL\n");
	while (l->next) {
		l = l->next;
		if (flag) {
			printf(" ");
		}
		else
			flag = 1;
		printf("%d", l->val);
	}
}

int main() {
	List l1 = create(), l2 = create();
	List l = combine(l1, l2);
	print(l);
	return 0;
}