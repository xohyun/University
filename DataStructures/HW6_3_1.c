#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int weight[MAX_VERTICES][MAX_VERTICES];
// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
     // ����
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)
			g->adj_mat[r][c]=INF;
}


/*  */
void insert_heap_edge(HeapType *h, int u, int v, int weight)
{
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;

	insert_min_heap(h, e);
	return;
}
void read_graph(GraphType *g, char *filename)
{
     // ����
	int number, u, v, weight;
     FILE *fp;

     fp = fopen(filename, "rt");
	if (fp == NULL) 
	{
		printf("file %s open error!\n", filename);
		return;
	}
 
     // �ڵ� ����
	fscanf(fp, "%d", &number);
	g->n = number;
	while(fscanf(fp, "%d %d %d\n", &u, &v, &weight) != EOF)
	{
		g->adj_mat[u][v] = weight;
		g->adj_mat[v][u] = weight;
	}
     fclose(fp);
}

/*  */
void write_graph(GraphType *g, char *filename)
{
     // ����
	int i, j;
     FILE *fp;
     
     if (filename == NULL) fp = stdout;
     else {
          fp = fopen(filename, "wt");
	     if (fp == NULL) 
	     {
		     printf("file %s open error!\n", filename);
	          return;
	     }
     }

	 fprintf(fp, "%d\n", g->n);
	
	 for(i = 0; i < g->n; i++)
	 {
		 for (j = i; j < g->n; j++)
			 if (weight[i][j] != 0)
				 fprintf(fp, "%d %d %d\n", i,j, weight[i][j]);
	 }

     if (filename != NULL) fclose(fp);
}

// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ���� 
// ����� ���� �׷����� �������� �����Ѵ�.

void insert_all_edges(HeapType *h, GraphType *g)
{
     // ����

	int i, j;
	element e;
	int number = g->n;

	for(i = 0; i < number; i++)
		for(j = i; j < number; j++)
			if(g->adj_mat[i][j] != INF)
			{
				//printf("%d, %d %d \n",  g->adj_mat[i][j], i,j);
				insert_heap_edge(h, i, j, g->adj_mat[i][j]);
			}
}

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType *g, GraphType *t)
{
     // ����
	int edge = 0;
	HeapType h;
	int uset, vset, i = 0;
	element e;

	init(&h);
	
	insert_all_edges(&h, g);
	set_init(g->n);

	printf("���õ� ����(�������):\n");
	while(edge < (g->n - 1))
	{
		e = delete_min_heap(&h);
		uset = set_find(e.u);
		vset = set_find(e.v);
		if(uset != vset) {
			edge++;
			printf("(%d, %d) %d\n", e.u, e.v, e.key);
			weight[e.u][e.v] = e.key;
			set_union(uset, vset);
		}
	}
}


main()
{
	GraphType g, t;		// �Է� �׷���, ��� Ʈ��
	
	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input.txt");

	graph_init(&t);
	t.n = g.n;
	
	kruskal(&g, &t);
	
     printf("\n���Ϸ� ���:\n");
	write_graph(&t, "output.txt");	
	write_graph(&t, NULL);	// to stdout
}
