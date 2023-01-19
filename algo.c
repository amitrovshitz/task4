#include <limits.h>
#include "algo.h"
#include "edges.h"
#include "graph.h"
#include "nodes.h"
#include "queue.h"

//Dijkstra's algorithm is a popular algorithm for finding the shortest path between nodes in a graph.
void dijkstra(int *arr, pnode source)
//The function takes two parameters as input, an integer array "arr" and a pointer "source" to a node in the graph.
 {
    qnode *source_queue = new_queuenode(source, 0);// creates a new queue node "source_queue" and initializes it with the source node and a distance of 0.
    while (!isEmpty(&source_queue))//The while loop continues until the queue is empty
     {
        source = pop(&source_queue);//the source node is popped from the queue and a pointer "curr_edge" is initialized with the source node's edges.
        pedge curr_edge = source->edges;
        while (curr_edge)//The while loop continues until there are no more edges for the current node.
         {
            if (arr[source->index] + curr_edge->weight < arr[curr_edge->endpoint->index]) //the function checks if the distance from the source node to the current node plus the weight of the edge is less than the current distance to the endpoint node.
            {
                //the distance to the endpoint node is updated and the endpoint node is pushed to the queue with the new distance.
                arr[curr_edge->endpoint->index] = arr[source->index] + curr_edge->weight;
                push(&source_queue, curr_edge->endpoint, arr[curr_edge->endpoint->index]);
            }
            curr_edge = curr_edge->next;//The curr_edge pointer is updated to point to the next edge
        }
    }
}

//An integer array "cities" that represents the order of visiting the cities.
// An integer "start" that represents the starting index of the permutation.
// An integer "end" that represents the ending index of the permutation.
// An integer "number_of_nodes" that represents the total number of nodes in the graph.
// An integer pointer "ans" that represents the current minimum distance.
// A pointer "head" that points to the head of the graph.
// This function will help you to find all possible routes between all the cities in the graph and determine the shortest route.
// It uses the permutation algorithm to generate all possible routes, and the Dijkstra algorithm to find the shortest path between the cities in each
void permutation(int *cities, int start, int end, int number_of_nodes, int *ans, pnode head) {
    if (start == end) {
        int route_len = 0;
        int *dij = (int *)malloc(sizeof(int) * number_of_nodes);
        for (int i = 0; i < number_of_nodes; i++) {
            dij[i] = INT_MAX;
        }
        pnode source = find_node(cities[0], head);
        dij[source->index] = 0;
        for (int i = 1; i <= end; i++) {
            dijkstra(dij, source);
            if (dij[find_node(cities[i], head)->index] == INT_MAX) {
                free(dij);
                return;
            }
            source = find_node(cities[i], head);
            route_len = route_len + dij[source->index];
            for (int j = 0; j < number_of_nodes; j++) {
                dij[j] = INT_MAX;
            }
            dij[source->index] = 0;
        }
        free(dij);
        if (route_len < *ans && route_len != 0) {
            *ans = route_len;
        }
        return;
    }
    for (int k = start; k <= end; k++) {
        swap(cities + k, cities + start);
        permutation(cities, start + 1, end, number_of_nodes, ans, head);
        swap(cities + k, cities + start);
    }
}
//This function is used to swap the values of two variables. 
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}