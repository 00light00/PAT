#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
	BinTree BT = CreatBinTree();
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
	return 0;
}

void InorderTraversal(BinTree BT) {
	if (BT) {
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
	return;
}

void PreorderTraversal(BinTree BT) {
	if (BT) {
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
	return;
}

void PostorderTraversal(BinTree BT) {
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}

void LevelorderTraversal(BinTree BT) {
	if (BT) {
		BinTree que[100];
		int front = 0, rear = 0;
		que[rear++] = BT;
		while (front != rear) {
			BinTree tmp = que[front++];
			printf(" %c", tmp->Data);
			if (tmp->Left)
				que[rear++] = tmp->Left;
			if (tmp->Right)
				que[rear++] = tmp->Right;
		}
	}
}