//Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.
//
//Format of functions :
//List Reverse(List L);
//where List is defined as the following :
//
//typedef struct Node *PtrToNode;
//typedef PtrToNode List;
//typedef PtrToNode Position;
//struct Node {
//	ElementType Element;
//	Position Next;
//};
//The function Reverse is supposed to return the reverse linked list of L, with a dummy header.
//
//Sample program of judge :
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int ElementType;
//typedef struct Node *PtrToNode;
//typedef PtrToNode List;
//typedef PtrToNode Position;
//struct Node {
//	ElementType Element;
//	Position Next;
//};
//
//List Read(); /* details omitted */
//void Print(List L); /* details omitted */
//List Reverse(List L);
//
//int main()
//{
//	List L1, L2;
//	L1 = Read();
//	L2 = Reverse(L1);
//	Print(L1);
//	Print(L2);
//	return 0;
//}
//
///* Your function will be put here */
//
//Sample Input :
//5
//1 3 4 5 2
//Sample Output :
//2 5 4 3 1
//2 5 4 3 1

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
	ElementType Element;
	Position Next;
};

List Read(); /* details omitted */
void Print(List L); /* details omitted */
List Reverse(List L);

List Read() {
	List re = (List)malloc(sizeof(struct Node));
	re->Next = NULL;
	PtrToNode p = re;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int elem;
		scanf("%d", &elem);
		p->Next = (PtrToNode)malloc(sizeof(struct Node));
		p = p->Next;
		p->Element = elem;
		p->Next = NULL;
	}
	return re;
}

void Print(List L) {
	while (L->Next) {
		L = L->Next;
		printf("%d ", L->Element);
	}
}
int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

List Reverse(List L) {
	PtrToNode pl = NULL, p = L->Next, pr;
	if (p) {
		pr = p->Next;
		while (pr) {
			p->Next = pl;
			pl = p;
			p = pr;
			pr = pr->Next;
		} 
		p->Next = pl;
		L->Next = p;
	}

	return L;
}