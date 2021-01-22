#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	7		/* ������ �� */
#define INF	1000	/* ���Ѵ� (������ ���� ���) */

/* ��Ʈ��ũ�� ������� */


typedef struct GraphType {
	int n;					// ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int weight[MAX_VERTICES][MAX_VERTICES];
int previous[MAX_VERTICES];
// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
     // ����
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++){
			g->adj_mat[r][c]=INF;
			weight[r][c] = INF;
		}
}



/*
int weight[MAX_VERTICES][MAX_VERTICES] = {
	{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } };
*/
int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES];		/* �湮�� ���� ǥ�� */
								//

void read_graph(GraphType *g, char *filename)
{
     // ����
	int number, u, v, weight_print;
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
	while(fscanf(fp, "%d %d %d\n", &u, &v, &weight_print) != EOF)
	{
		g->adj_mat[u][v] = weight_print;
		g->adj_mat[v][u] = weight_print;
		weight[u][v] = weight_print;
		weight[v][u] = weight_print;
	}
     fclose(fp);
}
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
//
void print_previous(int n, int d[])
{
	if(n == 0){
		printf("%d \n", previous[n]);
		return;
	}
	printf("%d -> ", previous[n]);

	print_previous(n - 1, d);
	

	printf("(%d)\n", d[n]);
}
void shortest_path(int start, int n)
{
	int i, u, w;
	for (i = 0; i<n; i++) /* �ʱ�ȭ */
	{
		distance[i] = weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;


	for (i = 0; i< n - 1; i++) {
		printf("\n%d -> ", start);

		u = choose(distance, n, found);
		
		found[u] = TRUE;

		//printf("%d (%d)\n", u, distance[u]);
		
		for (w = 0; w<n; w++) {
			if (!found[w])
				if (distance[u] + weight[u][w] < distance[w]){
					distance[w] = distance[u] + weight[u][w];
					previous[w] = u;
					//printf("\n:: %d\n\n", previous[w]);
				}
		}

		print_previous(i + 1, distance);
	}
}
//


void main()
{
	GraphType g;
	int n;
	graph_init(&g);
	read_graph(&g, "test.txt");
	n = g.n;
	
	shortest_path(0, n);
	printf("\n\n");
	//shortest_path(4, n);
}

