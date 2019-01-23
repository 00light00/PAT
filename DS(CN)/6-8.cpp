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

BinTree CreatBinTree();
int GetHeight(BinTree BT);

int main()
{
	BinTree BT = CreatBinTree();
	printf("%d\n", GetHeight(BT));
	return 0;
}
int GetHeight(BinTree BT) {
	if (BT) {
		int hl = 0, hr = 0;
		if (BT->Left)
			hl += GetHeight(BT->Left);
		if (BT->Right)
			hr += GetHeight(BT->Right);
		return hr > hl ? hr + 1 : hl + 1;
	}
	else
		return 0;
}