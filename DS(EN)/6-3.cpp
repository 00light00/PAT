//Write a function to add two polynomials.Do not destroy the input.Use a linked list implementation with a dummy head node.Note: The zero polynomial is represented by an empty list with only the dummy head node.
//
//Format of functions :
//Polynomial Add(Polynomial a, Polynomial b);
//where Polynomial is defined as the following :
//
//typedef struct Node *PtrToNode;
//struct Node {
//	int Coefficient;
//	int Exponent;
//	PtrToNode Next;
//};
//typedef PtrToNode Polynomial;
///* Nodes are sorted in decreasing order of exponents.*/
//The function Add is supposed to return a polynomial which is the sum of a and b.
//
//Sample program of judge :
//#include <stdio.h>
//#include <stdlib.h>
//typedef struct Node *PtrToNode;
//struct Node {
//	int Coefficient;
//	int Exponent;
//	PtrToNode Next;
//};
//typedef PtrToNode Polynomial;
//
//Polynomial Read(); /* details omitted */
//void Print(Polynomial p); /* details omitted */
//Polynomial Add(Polynomial a, Polynomial b);
//
//int main()
//{
//	Polynomial a, b, s;
//	a = Read();
//	b = Read();
//	s = Add(a, b);
//	Print(s);
//	return 0;
//}
//
///* Your function will be put here */
//
//Sample Input :
//4
//3 4 - 5 2 6 1 - 2 0
//3
//5 20 - 7 4 3 1
//Sample Output :
//5 20 - 4 4 - 5 2 9 1 - 2 0

#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node {
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print(Polynomial p); /* details omitted */
Polynomial Add(Polynomial a, Polynomial b);

Polynomial Read() {
	Polynomial re = (Polynomial)malloc(sizeof(struct Node));
	re->Next = NULL;
	PtrToNode p = re;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int co, ex;
		scanf("%d %d", &co, &ex);
		p->Next = (Polynomial)malloc(sizeof(struct Node));
		p = p->Next;
		p->Coefficient = co;
		p->Exponent = ex;
		p->Next = NULL;
	}
	return re;
}

void Print(Polynomial p) {
	p = p->Next;
	while (p) {
		printf("%d %d ", p->Coefficient, p->Exponent);
		p = p->Next;
	}
}

int main()
{
	Polynomial a, b, s;
	a = Read();
	b = Read();
	s = Add(a, b);
	Print(s);
	return 0;
}


Polynomial Add(Polynomial a, Polynomial b) {
	Polynomial re = (Polynomial)malloc(sizeof(struct Node));
	re->Next = NULL;
	PtrToNode pre = re;
	PtrToNode pa = a->Next;
	PtrToNode pb = b->Next;
	while (pa || pb) {
		int co = 0, ex = 0;
		if (!pb || (pa && pb && pa->Exponent > pb->Exponent)) {
			co = pa->Coefficient;
			ex = pa->Exponent;
			pa = pa->Next;
			pre->Next = (PtrToNode)malloc(sizeof(struct Node));
			pre = pre->Next;
			pre->Coefficient = co;
			pre->Exponent = ex;
			pre->Next = NULL;
		}
		else if (!pa || (pa && pb && pa->Exponent < pb->Exponent)) {
			co = pb->Coefficient;
			ex = pb->Exponent;
			pb = pb->Next;
			pre->Next = (PtrToNode)malloc(sizeof(struct Node));
			pre = pre->Next;
			pre->Coefficient = co;
			pre->Exponent = ex;
			pre->Next = NULL;
		}
		else {
			co = pa->Coefficient + pb->Coefficient;
			ex = pa->Exponent;
			if (co) {
				pre->Next = (PtrToNode)malloc(sizeof(struct Node));
				pre = pre->Next;
				pre->Coefficient = co;
				pre->Exponent = ex;
				pre->Next = NULL;
			}
			pa = pa->Next;
			pb = pb->Next;
		}
	}
	if (re->Next == NULL) {
		re->Next = (PtrToNode)malloc(sizeof(struct Node));
		re->Next->Coefficient = re->Exponent = 0;
		re->Next->Next = NULL;
	}
	return re;
}