//Write a program to find the weighted shortest distances from any vertex to a given source vertex in a digraph.It is guaranteed that all the weights are positive.
//
//Format of functions :
//void ShortestDist(MGraph Graph, int dist[], Vertex S);
//where MGraph is defined as the following :
//
//typedef struct GNode *PtrToGNode;
//struct GNode {
//	int Nv;
//	int Ne;
//	WeightType G[MaxVertexNum][MaxVertexNum];
//};
//typedef PtrToGNode MGraph;
//The shortest distance from V to the source S is supposed to be stored in dist[V].If V cannot be reached from S, store - 1 instead.
//
//Sample program of judge :
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef enum { false, true } bool;
//#define INFINITY 1000000
//#define MaxVertexNum 10  /* maximum number of vertices */
//typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
//typedef int WeightType;
//
//typedef struct GNode *PtrToGNode;
//struct GNode {
//	int Nv;
//	int Ne;
//	WeightType G[MaxVertexNum][MaxVertexNum];
//};
//typedef PtrToGNode MGraph;
//
//MGraph ReadG(); /* details omitted */
//
//void ShortestDist(MGraph Graph, int dist[], Vertex S);
//
//int main()
//{
//	int dist[MaxVertexNum];
//	Vertex S, V;
//	MGraph G = ReadG();
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
//	0 1 1
//	0 5 1
//	0 6 1
//	5 3 1
//	2 1 2
//	2 6 3
//	6 4 4
//	4 5 5
//	6 5 12
//	2
//	Sample Output :
//-1 2 0 13 7 12 3

#include <stdio.h>
#include <stdlib.h>


#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(); /* details omitted */

void ShortestDist(MGraph Graph, int dist[], Vertex S);

MGraph ReadG() {
	MGraph graph = new GNode;
	scanf("%d %d", &graph->Nv, &graph->Ne);
	for (int i = 0; i < graph->Nv; i++) {
		for (int j = 0; j < graph->Nv; j++) {
			graph->G[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < graph->Ne; i++) {
		Vertex v1, v2;
		WeightType w;
		scanf("%d %d %d", &v1, &v2, &w);
		graph->G[v1][v2] = w;
	}

	return graph;
}

int main()
{
	int dist[MaxVertexNum];
	Vertex S, V;
	MGraph G = ReadG();

	scanf("%d", &S);
	ShortestDist(G, dist, S);

	for (V = 0; V < G->Nv; V++)
		printf("%d ", dist[V]);

	return 0;
}

/* Your function will be put here */

void ShortestDist(MGraph Graph, int dist[], Vertex S) {
	WeightType visit[MaxVertexNum] = { 0 };
	Vertex i, j;
	for (i = 0; i < Graph->Nv; i++) {
		dist[i] = INFINITY;
	}

	dist[S] = 0;
	for (i = 0; i < Graph->Nv; i++) {
		WeightType mind = INFINITY;
		Vertex now = MaxVertexNum;
		for (j = 0; j < Graph->Nv; j++) {
			if (dist[j] < mind && !visit[j]) {
				now = j;
				mind = dist[j];
			}
		}

		if (now == MaxVertexNum)
			break;
		visit[now] = 1;

		for (j = 0; j < Graph->Nv; j++) {
			if (dist[j] > Graph->G[now][j] + dist[now]) {
				dist[j] = Graph->G[now][j] + dist[now];
			}
		}
	}

	for (i = 0; i < Graph->Nv; i++) {
		if (dist[i] == INFINITY)
			dist[i] = -1;
	}
}
