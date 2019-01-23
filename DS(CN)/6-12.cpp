#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}

BinTree Insert(BinTree BST, ElementType X) {
	if (BST) {
		if (BST->Data > X) {
			BST->Left = Insert(BST->Left, X);
		}
		else {
			BST->Right = Insert(BST->Right, X);
		}
		return BST;
	}
	else {
		BinTree p = (BinTree)malloc(sizeof(struct TNode));
		p->Data = X;
		p->Left = NULL;
		p->Right = NULL;
		return p;
	}
}

BinTree Delete(BinTree BST, ElementType X) {
	if (BST) {
		if (BST->Data > X)
			BST->Left = Delete(BST->Left, X);
		else if (BST->Data < X)
			BST->Right = Delete(BST->Right, X);
		else {
			Position p = BST;
			if (p->Left) {
				FindMax(p->Left)->Right = p->Right;
				return p->Left;
			}
			else
				return p->Right;
		}
		return BST;
	}
	else {
		printf("Not Found\n");
		return NULL;
	}
}

Position Find(BinTree BST, ElementType X) {
	Position re = NULL;
	if (BST) {
		if (BST->Data == X) {
			re = BST;
		}
		else if (BST->Data > X) {
			re = Find(BST->Left, X);
		}
		else {
			re = Find(BST->Right, X);
		}
	}
	return re;
}

Position FindMin(BinTree BST) {
	Position re = BST;
	if (re && re->Left)
		re = FindMin(re->Left);
	return re;
}

Position FindMax(BinTree BST) {
	Position re = BST;
	if (re && re->Right)
		re = FindMax(re->Right);
	return re;
}


void InorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %d", BT->Data);
		InorderTraversal(BT->Right);
	}
	return;
}

void PreorderTraversal(BinTree BT) {
	if (BT) {
		printf(" %d", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
	return;
}

void PostorderTraversal(BinTree BT) {
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %d", BT->Data);
	}
}