#include <stdio.h>
#include <stdlib.h>


#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
	ElementType Element;
	PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
	PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push(ElementType X, Deque D);
ElementType Pop(Deque D);
int Inject(ElementType X, Deque D);
ElementType Eject(Deque D);

Operation GetOp();          /* details omitted */
void PrintDeque(Deque D); /* details omitted */

int main()
{
	ElementType X;
	Deque D;
	int done = 0;

	D = CreateDeque();
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d", &X);
			if (!Push(X, D)) printf("Memory is Full!\n");
			break;
		case pop:
			X = Pop(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case inject:
			scanf("%d", &X);
			if (!Inject(X, D)) printf("Memory is Full!\n");
			break;
		case eject:
			X = Eject(D);
			if (X == ERROR) printf("Deque is Empty!\n");
			break;
		case end:
			PrintDeque(D);
			done = 1;
			break;
		}
	}
	return 0;
}

Operation GetOp() {
	char op[20];
	scanf("%s", op);
	int len = 0;
	while (op[len])
		len++;
	switch (len) {
	case 3:
		if (op[0] == 'P')
			return pop;
		else
			return end;
	case 4:
		return push;
	case 5:
		return eject;
	case 6:
		return inject;
	}
}

void PrintDeque(Deque D) {
	printf("Inside Deque:");
	while (D->Front != D->Rear) {
		printf(" %d", Eject(D));
	}
}

Deque CreateDeque() {
	Deque re = (Deque)malloc(sizeof(struct DequeRecord));
	re->Front = (PtrToNode)malloc(sizeof(struct Node));
	re->Rear = re->Front;
	re->Front->Last = re->Front->Next = NULL;
	return re;
}

int Push(ElementType X, Deque D) {
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL)
		return 0;
	p->Element = X;
	p->Next = D->Front->Next;
	p->Last = D->Front;
	D->Front->Next = p;
	if (D->Front == D->Rear)
		D->Rear = p;
	else
		p->Next->Last = p;
	return 1;
}

ElementType Pop(Deque D) {
	ElementType re = ERROR;
	if (D->Front != D->Rear) {
		re = D->Front->Next->Element;
		PtrToNode p = D->Front->Next;
		D->Front->Next = p->Next;
		if (p == D->Rear)
			D->Rear = D->Front;
		else
			p->Next->Last = D->Front;
		free(p);
	}
	return re;
}

int Inject(ElementType X, Deque D) {
	if (D->Rear == D->Front)
		return Push(X, D);
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL)
		return 0;
	p->Element = X;
	p->Last = D->Rear;
	D->Rear = p;
	p->Next = NULL;
	p->Last->Next = p;
	return 1;
}

ElementType Eject(Deque D) {
	ElementType re = ERROR;
	if (D->Front != D->Rear) {
		re = D->Rear->Last->Element;
		PtrToNode p = D->Rear;
		D->Rear = p->Last;
		D->Rear->Next = NULL;
		free(p);
	}
	return re;
}