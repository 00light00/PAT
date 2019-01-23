#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;
	bool flag;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		flag = Insert(L, X, L->Next);
		if (flag == false) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			flag = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (flag == false)
				printf("Wrong Answer.\n");
		}
	}
	flag = Insert(L, X, NULL);
	if (flag == false) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	flag = Insert(L, X, P);
	if (flag == true) printf("Wrong Answer\n");
	flag = Delete(L, P);
	if (flag == true) printf("Wrong Answer\n");
	for (P = L->Next; P; P = P->Next) printf("%d ", P->Data);
	return 0;
}

List MakeEmpty() {
	List p = (List)malloc(sizeof(struct LNode));
	p->Next = NULL;
	return p;
}

Position Find(List L, ElementType X) {
	List p = ERROR;
	L = L->Next;
	while (L != NULL) {
		if (L->Data == X) {
			p = L;
			break;
		}
		L = L->Next;
	}
	return p;
}

bool Insert(List L, ElementType X, Position P) {
	List p = L;
	while (p != NULL){
		if (p->Next == P)
			break;
		p = p->Next;
	}
	if (p) {
		p->Next = (List)malloc(sizeof(struct LNode));
		p->Next->Data = X;
		p->Next->Next = P;
		return true;
	}
	else {
		printf("Wrong Position for Insertion\n");
		return false;
	}
}
bool Delete(List L, Position P) {
	List p = L;
	while (p != NULL) {
		if (p->Next == P)
			break;
		p = p->Next;
	}
	if (p) {
		p->Next = P->Next;
		free(P);
		return true;
	}
	else {
		printf("Wrong Position for Deletion\n");
		return false;
	}
}