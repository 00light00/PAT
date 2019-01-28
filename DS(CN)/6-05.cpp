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

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		if (L == ERROR) printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			L = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (L == ERROR)
				printf("Wrong Answer or Empty List.\n");
		}
	}
	L = Insert(L, X, NULL);
	if (L == ERROR) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	tmp = Insert(L, X, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	tmp = Delete(L, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
	return 0;
}
Position Find(List L, ElementType X) {
	Position pos = ERROR;
	List p = L;
	while (p != NULL) {
		if (X == p->Data) {
			pos = p;
			break;
		}
		p = p->Next;
	}
	return pos;
}
List Insert(List L, ElementType X, Position P) {
	if (L) {
		List p = L;
		if (p == P) {
			p = (List)malloc(sizeof(struct LNode));
			p->Data = X;
			p->Next = L;
			return p;
		}
		else {
			while (p != NULL) {
				if (p->Next == P) {
					break;
				}
				p = p->Next;
			}
			if (p) {
				p->Next = (List)malloc(sizeof(struct LNode));
				p->Next->Data = X;
				p->Next->Next = P;
				return L;
			}
			else {
				printf("Wrong Position for Insertion\n");
				return ERROR;
			}
		}
	}
	else {
		L = (List)malloc(sizeof(struct LNode));
		L->Next = NULL;
		L->Data = X;
		return L;
	}
}
List Delete(List L, Position P) {
	List p = (List)malloc(sizeof(struct LNode));
	p->Next = L;
	List hp = p;
	while (p != NULL) {
		if (p->Next == P)
			break;
		p = p->Next;
	}
	if (p == NULL) {
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
	else {
		p->Next = P->Next;
		L = hp->Next;
		free(P);
		free(hp);
		return L;
	}
	
}