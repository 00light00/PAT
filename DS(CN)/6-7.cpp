#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef int Position;
struct SNode {
	ElementType *Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp()  /* details omitted */ {
	char op[20];
	scanf("%s", op);
	if (op[0] == 'P') {
		if (op[1] == 'u')
			return push;
		else
			return pop;
	}
	else
		return end;
}
void PrintStack(Stack S, int Tag) /* details omitted */ {
	printf("Pop from Stack %d:", Tag);
	if (Tag == 1) {
		while (S->Top1 > 0) {
			printf(" %d", Pop(S, Tag));
		}
		
	}
	else {
		while (S->Top2 < S->MaxSize - 1) {
			printf(" %d", Pop(S, Tag));
		}
	}
	printf("\n");
}

int main()
{
	int N, Tag, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d %d", &Tag, &X);
			if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
			break;
		case pop:
			scanf("%d", &Tag);
			X = Pop(S, Tag);
			if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
			break;
		case end:
			PrintStack(S, 1);
			PrintStack(S, 2);
			done = 1;
			break;
		}
	}
	return 0;
}

Stack CreateStack(int MaxSize) {
	Stack p = (Stack)malloc(sizeof(struct SNode));
	p->MaxSize = MaxSize;
	p->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
	p->Top1 = -1;
	p->Top2 = MaxSize;
	return p;
}

bool Push(Stack S, ElementType X, int Tag) {
	if (S->Top1 == S->Top2-1) {
		printf("Stack Full\n");
		return false;
	}
	else {
		if (Tag == 1) {
			S->Data[++S->Top1] = X;
		}
		else if (Tag == 2) {
			S->Data[--S->Top2] = X;
		}
		return true;
	}
}

ElementType Pop(Stack S, int Tag) {
	ElementType re = ERROR;
	if (Tag == 1) {
		if (S->Top1 > -1) {
			re = S->Data[S->Top1--];
		}
	}
	else if (Tag == 2) {
		if (S->Top2 < S->MaxSize) {
			re = S->Data[S->Top2++];
		}
	}
	if (re == ERROR)
		printf("Stack %d Empty\n", Tag);
	return re;
}