//Write a program to find the unweighted shortest distances from any vertex to a given source vertex in a digraph.
//
//Format of functions :
//void ShortestDist(LGraph Graph, int dist[], Vertex S);
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
//The shortest distance from V to the source S is supposed to be stored in dist[V].If V cannot be reached from S, store - 1 instead.
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
//void ShortestDist(LGraph Graph, int dist[], Vertex S);
//
//int main()
//{
//	int dist[MaxVertexNum];
//	Vertex S, V;
//	LGraph G = ReadG();
//
//	scanf("%d", &S);
//	ShortestDist(G, dist, S);
//
//	for (V = 0; V < G->Nv; V++)
//		printf("%d ", dist[V]);
//
//	return 0;
//}
//
////* Your function will be put here */
//
//Sample Input(for the graph shown in the figure) :
//
//
//	7 9
//	0 1
//	0 5
//	0 6
//	5 3
//	2 1
//	2 6
//	6 4
//	4 5
//	6 5
//	2
//	Sample Output :
//-1 1 0 3 2 2 1

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

void ShortestDist(LGraph Graph, int dist[], Vertex S);

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
	int dist[MaxVertexNum];
	Vertex S, V;
	LGraph G = ReadG();

	scanf("%d", &S);
	ShortestDist(G, dist, S);

	for (V = 0; V < G->Nv; V++)
		printf("%d ", dist[V]);

	return 0;
}

/* Your function will be put here */

void ShortestDist(LGraph Graph, int dist[], Vertex S) {
	Vertex que[MaxVertexNum*MaxVertexNum];
	Vertex visit[MaxVertexNum] = { 0 };
	int front = 0, rear = 0, pv = 0;
	int dis = 0;
	Vertex v;
	for (v = 0; v < Graph->Nv; v++) {
		dist[v] = -1;
	}
	que[front++] = S;
	pv = front;
	while (front != rear) {
		Vertex now = que[rear++];
		if (!visit[now]) {
			visit[now] = 1;
			dist[now] = dis;
			PtrToAdjVNode nV = Graph->G[now].FirstEdge;
			while (nV) {
				Vertex vv = nV->AdjV;
				if (!visit[vv])
					que[front++] = vv;
				nV = nV->Next;
			}
		}

		if (rear == pv) {
			pv = front;
			dis++;
		}
	}
}