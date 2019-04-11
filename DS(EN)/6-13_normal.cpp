//Write a program to find the topological order in a digraph.
//
//Format of functions :
//bool TopSort(LGraph Graph, Vertex TopOrder[]);
//where LGraph is defined as the following :
//
//typedef struct AdjVNode *PtrToAdjVNode;
//struct AdjVNode {
//	Vertex AdjV;
//	PtrToAdjVNode Next;
//};
//
//typedef struct Vnode {
//	PtrToAdjVNode FirstEdge;
//} AdjList[MaxVertexNum];
//
//typedef struct GNode *PtrToGNode;
//struct GNode {
//	int Nv;
//	int Ne;
//	AdjList G;
//};
//typedef PtrToGNode LGraph;
//The topological order is supposed to be stored in TopOrder[] where TopOrder[i] is the i - th vertex in the resulting sequence.The topological sort cannot be successful if there is a cycle in the graph -- in that case TopSort must return false; otherwise return true.
//
//Notice that the topological order might not be unique, but the judge's input guarantees the uniqueness of the result.
//
//Sample program of judge :
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef enum { false, true } bool;
//#define MaxVertexNum 10  /* maximum number of vertices */
//typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
//
//typedef struct AdjVNode *PtrToAdjVNode;
//struct AdjVNode {
//	Vertex AdjV;
//	PtrToAdjVNode Next;
//};
//
//typedef struct Vnode {
//	PtrToAdjVNode FirstEdge;
//} AdjList[MaxVertexNum];
//
//typedef struct GNode *PtrToGNode;
//struct GNode {
//	int Nv;
//	int Ne;
//	AdjList G;
//};
//typedef PtrToGNode LGraph;
//
//LGraph ReadG(); /* details omitted */
//
//bool TopSort(LGraph Graph, Vertex TopOrder[]);
//
//int main()
//{
//	int i;
//	Vertex TopOrder[MaxVertexNum];
//	LGraph G = ReadG();
//
//	if (TopSort(G, TopOrder) == true)
//		for (i = 0; i < G->Nv; i++)
//			printf("%d ", TopOrder[i]);
//	else
//		printf("ERROR");
//	printf("\n");
//
//	return 0;
//}
//
////* Your function will be put here */
//
//Sample Input 1 (for the graph shown in the figure) :
//
//
//	5 7
//	1 0
//	4 3
//	2 1
//	2 0
//	3 2
//	4 1
//	4 2
//	Sample Output 1:
//4 3 2 1 0
//Sample Input 2 (for the graph shown in the figure) :
//
//
//	5 8
//	0 3
//	1 0
//	4 3
//	2 1
//	2 0
//	3 2
//	4 1
//	4 2
//	Sample Output 2:
//ERROR

#include <stdio.h>
#include <stdlib.h>


#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;
	PtrToAdjVNode Next;
};

typedef struct Vnode {
	PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort(LGraph Graph, Vertex TopOrder[]);

LGraph ReadG() {
	LGraph graph = new GNode;
	scanf("%d %d", &graph->Nv, &graph->Ne);
	for (int i = 0; i < graph->Nv; i++) {
		graph->G[i].FirstEdge = NULL;
	}
	for (int i = 0; i < graph->Ne; i++) {
		Vertex v1, v2;
		scanf("%d %d", &v1, &v2);
		PtrToAdjVNode pAdjn = graph->G[v1].FirstEdge;
		if (pAdjn) {
			while (pAdjn->Next) {
				pAdjn = pAdjn->Next;
			}
			pAdjn->Next = new AdjVNode;
			pAdjn = pAdjn->Next;
			pAdjn->AdjV = v2;
			pAdjn->Next = NULL;
		}
		else {
			pAdjn = new AdjVNode;
			pAdjn->AdjV = v2;
			pAdjn->Next = NULL;
			graph->G[v1].FirstEdge = pAdjn;
		}
	}

	return graph;
}

int main()
{
	int i;
	Vertex TopOrder[MaxVertexNum];
	LGraph G = ReadG();

	if (TopSort(G, TopOrder) == true)
		for (i = 0; i < G->Nv; i++)
			printf("%d ", TopOrder[i]);
	else
		printf("ERROR");
	printf("\n");

	return 0;
}

/* Your function will be put here */

bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int cnt[MaxVertexNum] = { 0 };
	Vertex i, j, visit[MaxVertexNum] = { 0 };
	for (i = 0; i < Graph->Nv; i++) {
		PtrToAdjVNode pnow = Graph->G[i].FirstEdge;
		while (pnow) {
			cnt[pnow->AdjV]++;
			pnow = pnow->Next;
		}
	}

	for (i = 0; i < Graph->Nv; i++) {
		Vertex now = MaxVertexNum;
		for (j = 0; j < Graph->Nv; j++) {
			if (cnt[j] == 0 &&!visit[j]) {
				now = j;
				break;
			}
		}

		if (now == MaxVertexNum) {
			return false;
		}
		visit[now] = 1;
		TopOrder[i] = now;
		PtrToAdjVNode pnow = Graph->G[now].FirstEdge;
		while (pnow) {
			cnt[pnow->AdjV]--;
			pnow = pnow->Next;
		}
	}
	return true;
}