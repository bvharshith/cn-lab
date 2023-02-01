#include<bits/stdc++.h>
#include <limits.h>
#include <stdio.h>
 using namespace std;

#define V 5


int minDistance(int dist[], bool Test[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if ( Test[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}


void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool Test[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, Test[i] = false;


    dist[src] = 0;


    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, Test);


        Test[u] = true;


        for (int v = 0; v < V; v++)


            if (!Test[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }


    printSolution(dist);
}


int main()
{

    int graph[V][V] ;
    cout<<"Enter the graph "<<endl;
    for(int i = 0; i<V; i++)
    {
        for(int j = 0; j<V; j++)
            cin>>graph[i][j];
    }

    dijkstra(graph, 0);

    return 0;
}

output:
Enter the graph 
0 1 4 0 5
2 0 3 6 0
4 8 0 0 6
7 0 0 9 10
0 0 4 0 8
Vertex           Distance from Source
0                0
1                1
2                4
3                7
4                5


...Program finished with exit code 0
Press ENTER to exit console.
