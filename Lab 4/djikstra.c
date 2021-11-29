#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
#define MAX 10


//function to implement dijkstra's algorithm
void dijkstra(int G[MAX][MAX], int n, int startNode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, minDistance, nextNode, i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];

	for (i = 0; i < n; i++)
	{
		distance[i] = cost[startNode][i];
		pred[i] = startNode;
		visited[i] = 0;
	}
	distance[startNode] = 0;
	visited[startNode] = 1;
	count = 1;
	while (count < n - 1)
	{
		minDistance = INFINITY;
		for (i = 0; i < n; i++)
			if (distance[i] < minDistance && !visited[i])
			{
				minDistance = distance[i];
				nextNode = i;
			}
		visited[nextNode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (minDistance + cost[nextNode][i] < distance[i])
				{
					distance[i] = minDistance + cost[nextNode][i];
					pred[i] = nextNode;
				}
		count++;
	}

	for (i = 0; i < n; i++)
		if (i != startNode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j = i;
			do
			{
				j = pred[j];
				printf(" <-%d", j);
			} while (j != startNode);
		}
}


void main()
{
	int G[MAX][MAX], i, j, n, u;
	printf("\nEnter the no. of vertices:: ");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix::\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	printf("\nEnter the starting node:: ");
	scanf("%d", &u);
	dijkstra(G, n, u);
}