#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5


int minCost(int cost[], bool visited[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (visited[v] == false && cost[v] < min)
			min = cost[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V])
{
	
	int parent[V];
	int cost[V];
	bool visited[V];

	for (int i = 0; i < V; i++)
		cost[i] = INT_MAX, visited[i] = false;


	cost[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		
		int u = minCost(cost, visited);

		
		visited[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && visited[v] == false && graph[u][v] < cost[v])
				parent[v] = u, cost[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
    // printf("Enter no of vertices \n");
    // int V=0;
    // scanf("%d", &V);
    int graph[V][V];


	printf("Enter adjacency matrix for a graph with 5 vertices");
	
    for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
			scanf("%d", &graph[i][j]);
	}

	primMST(graph);

	return 0;
}
