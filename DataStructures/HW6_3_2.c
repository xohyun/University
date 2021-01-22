#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define VERTICES 6
#define INF 1000L

int weight[VERTICES][VERTICES]={
{  0, 10, INF,  20,  70, INF },
{ 10,  0,  50,  30,  60, INF}, 
{ INF,50,   0, INF,  40, INF},
{ 20, 30, INF,   0, INF, 80},
{ 70, 60,  40, INF,   0, INF},
{ INF,INF,INF,  80, INF,   0}};

int selected[VERTICES]; // 0���� �ʱ�ȭ, �� ���õ� <����Ʈ������>�� ���������� ����
int dist[VERTICES]; // <����Ʈ������>���� �������� �ּҰŸ�
int edge[VERTICES];

// for all v such as selected[v] == FALSE, dist[v]�� �ּҰ��� v�� ��ȯ
int get_min_vertex(int n)
{
  int v,i;
  for (i = 0; i <n; i++)
    if (!selected[i]) {
      v = i; 
	  break;
    }
  for (i = 0; i < n; i++)
    if ( !selected[i] && (dist[i] < dist[v])) v = i;
  return (v);
}

void prim(int s, int n) // s�� ������, n�� ��������
{
	int i, u, v;
	int a;

	for(u = 0; u < n; u++) {
		dist[u] = INF;
	}

	// ���� ������ s�� �Ÿ��� ���� 
	dist[s] = 0;

	for(i=0;i<n;i++){
		u = get_min_vertex(n); // ���þ� �� ���� �߿��� dist[u]�� ���� ���� ���� u�� ã��
		selected[u]=TRUE; // <����Ʈ������>�� u�� ���Խ�Ŵ
		//printf("\n%d ����\n", u);
		printf("(%d %d) %d\n", edge[u], u, dist[u]);
		
		printf("selected[] =\t");
		for (a = 0; a < n; a++)
			printf("%5d ", selected[a]);
		printf("\n");

		// u�� <����Ʈ������>�� ���Խ�Ű�鼭 dist[..]�� ������
		for(v = 0; v < n; v++)
				if(!selected[v] && weight[u][v]< dist[v]) {
					dist[v] = weight[u][v];
					edge[v] = u;
				}

		printf("dist[] =\t");
		for (a = 0; a < n; a++)
			printf("%5d ", dist[a]);
		printf("\n\n");
	}
}
//
main()
{
	prim(0, VERTICES);
}
