#include<iostream>

#define MAXEDGE 15
#define MAXVEX 9
#define INF 65535
using namespace std;

int Find(int *parent, int f);
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

typedef struct
{
	int vexs[MAXEDGE];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

void MiniSpantree_Kruskal(MGraph *G)
{
	int i, n, j, m,k=0;
	Edge edges[MAXEDGE];
	int parent[MAXVEX];
	Edge temp;

	for (i = 0; i<G->numVertexes; i++)
		for (j = 0; j<i+1; j++)
		{
			if (i != j&&G->arc[i][j] != INF)
			{
				edges[k].begin = j;
				edges[k].end = i;
				edges[k].weight = G->arc[i][j];
				k++;
			}
		}
	for (i = 0; i<G->numEdges; i++)
		for (j = 0; j<G->numEdges-1; j++)
		{
			if (edges[j].weight > edges[j + 1].weight)
			{
				temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}

	for (i = 0; i<G->numVertexes; i++)
	{
		parent[i] = 0;
	}
	for (i = 0; i<G->numEdges; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			cout << "(" << edges[i].begin << "," << edges[i].end << ") " << edges[i].weight << endl;
		}
	}
}

int Find(int *parent, int f)
{
	while (parent[f]>0)
		f = parent[f];
	return f;
}

int main()
{
	int i = 0, j = 0;
	MGraph *G = new MGraph;
	G->numVertexes = MAXVEX;
	G->numEdges = MAXEDGE;
	for (i = 0; i<MAXEDGE; i++)
	{
		G->vexs[i] = i;
	}
	for (i = 0; i<MAXVEX; i++)
		for (j = 0; j<MAXVEX; j++)
		{
			G->arc[i][j] = INF;
		}
	G->arc[4][5] = 26;
	G->arc[3][6] = 24;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][4] = 20;
	G->arc[6][7] = 19;
	G->arc[1][2] = 18;
	G->arc[5][6] = 17;
	G->arc[1][6] = 16;
	G->arc[3][7] = 16;
	G->arc[1][8] = 12;
	G->arc[0][5] = 11;
	G->arc[0][1] = 10;
	G->arc[2][8] = 8;
	G->arc[4][7] = 7;
	for(i=0;i<MAXVEX;i++)
		for (j = 0; j < MAXVEX; j++)
		{
			if (G->arc[j][i] != INF)
				G->arc[i][j] = G->arc[j][i];
			if (G->arc[i][j] != INF)
				G->arc[j][i] = G->arc[i][j];
		}
	MiniSpantree_Kruskal(G);
	return 1;
}














