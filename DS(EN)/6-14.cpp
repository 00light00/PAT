//Write a function to count the number of connected components in a given graph.
//
//Format of functions :
//int CountConnectedComponents(LGraph Graph);
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
//The function CountConnectedComponents is supposed to return the number of connected components in the undirected Graph.
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
//int CountConnectedComponents(LGraph Graph);
//
//int main()
//{
//	LGraph G = ReadG();
//	printf("%d\n", CountConnectedComponents(G));
//
//	return 0;
//}
//
////* Your function will be put here */
//
//Sample Input(for the graph shown in the figure) :
//
//
//	8 6
//	0 7
//	0 1
//	2 0
//	4 1
//	2 4
//	3 5
//	Sample Output :
//3

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
LGraph ReadG() {
	LGraph re = new GNode;
	scanf("%d %d", &re->Nv, &re->Ne);
	for (int i = 0; i < re->Nv; i++) {
		re->G[i].FirstEdge = NULL;
	}
	for (int i = 0; i < re->Ne; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		if (re->G[v1].FirstEdge) {
			PtrToAdjVNode p = re->G[v1].FirstEdge;
			while (p->Next) {
				p = p->Next;
			}
			p->Next = new AdjVNode;
			p = p->Next;
			p->AdjV = v2;
			p->Next = NULL;
		}
		else {
			re->G[v1].FirstEdge = new AdjVNode;
			re->G[v1].FirstEdge->AdjV = v2;
			re->G[v1].FirstEdge->Next = NULL;
		}
		if (re->G[v2].FirstEdge) {
			PtrToAdjVNode p = re->G[v2].FirstEdge;
			while (p->Next) {
				p = p->Next;
			}
			p->Next = new AdjVNode;
			p = p->Next;
			p->AdjV = v1;
			p->Next = NULL;
		}
		else {
			re->G[v2].FirstEdge = new AdjVNode;
			re->G[v2].FirstEdge->AdjV = v1;
			re->G[v2].FirstEdge->Next = NULL;
		}
	}
	return re;
}
int CountConnectedComponents(LGraph Graph);

int main()
{
	LGraph G = ReadG();
	printf("%d\n", CountConnectedComponents(G));

	return 0;
}

/* Your function will be put here */

void dfs(int v, LGraph G, int * visit) {
	if (!visit[v]) {
		visit[v] = 1;
		PtrToAdjVNode p = G->G[v].FirstEdge;
		while (p) {
			dfs(p->AdjV, G, visit);
			p = p->Next;
		}
	}
}

int CountConnectedComponents(LGraph Graph) {
	int visit[MaxVertexNum] = { 0 };
	int i, cnt = 0;
	for (i = 0; i < Graph->Nv; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i, Graph, visit);
		}
	}
	return cnt;
}