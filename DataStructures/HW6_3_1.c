#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 9999

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int weight[MAX_VERTICES][MAX_VERTICES];
// 그래프 초기화 
void graph_init(GraphType *g)
{
     // 구현
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
     // 구현
	int number, u, v, weight;
     FILE *fp;

     fp = fopen(filename, "rt");
	if (fp == NULL) 
	{
		printf("file %s open error!\n", filename);
		return;
	}
 
     // 코드 삽입
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
     // 구현
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

// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입 
// 현재는 예제 그래프의 간선들을 삽입한다.

void insert_all_edges(HeapType *h, GraphType *g)
{
     // 구현

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

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g, GraphType *t)
{
     // 구현
	int edge = 0;
	HeapType h;
	int uset, vset, i = 0;
	element e;

	init(&h);
	
	insert_all_edges(&h, g);
	set_init(g->n);

	printf("선택된 간선(순서대로):\n");
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
	GraphType g, t;		// 입력 그래프, 결과 트리
	
	graph_init(&g);
	//read_graph(&g, "input1.txt");
	read_graph(&g, "input.txt");

	graph_init(&t);
	t.n = g.n;
	
	kruskal(&g, &t);
	
     printf("\n파일로 출력:\n");
	write_graph(&t, "output.txt");	
	write_graph(&t, NULL);	// to stdout
}
