#include <limits.h>

#include "algo.h"
#include "edges.h"
#include "graph.h"
#include "nodes.h"
#include "queue.h"
//The function takes in two parameters: an array of integers "arr" and a pointer to a node "src" representing the source vertex in a graph.
//This algorithm is used to find the shortest path from a source node to all other nodes in a weighted graph, where the edge weights are non-negative.
void dijkstra(int *arr, pnode src) {
    qnode *sq = new_queue_node(src, 0);
    while (!is_empty(&sq)) {
        src = pop(&sq);
        pedge curr_edge = src->edges;
        while (curr_edge) {
            if (arr[src->index] + curr_edge->weight < arr[curr_edge->endpoint->index]) {
                arr[curr_edge->endpoint->index] = arr[src->index] + curr_edge->weight;
                push(&sq, curr_edge->endpoint, arr[curr_edge->endpoint->index]);
            }
            curr_edge = curr_edge->next;
        }
    }
}
//generates all possible permutations of a given array and finds the shortest path through the permutations using the Dijkstra algorithm. The function takes in the following parameters:

// cheak: the array to generate permutations of
// start and end: the start and end indices of the permutation
// size: the size of the array
// ans: a pointer to an int to store the shortest path length
// head: a pointer to the head node of a linked list used in the Dijkstra algorithm
void permutation(int *cheak, int start, int end, int size, int *ans, pnode head) {
    if (start == end) {
        int len = 0;
        int *dij = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            dij[i] = INT_MAX;
        }
        pnode src = find_node(cheak[0], head);
        dij[src->index] = 0;
        for (int i = 1; i <= end; i++) {
            dijkstra(dij, src);
            if (dij[find_node(cheak[i], head)->index] == INT_MAX) {
                free(dij);
                return;
            }
            src = find_node(cheak[i], head);
            len = len + dij[src->index];
            for (int j = 0; j < size; j++) {
                dij[j] = INT_MAX;
            }
            dij[src->index] = 0;
        }
        free(dij);
        if (len < *ans && len != 0) {
            *ans = len;
        }
        return;
    }
    for (int k = start; k <= end; k++) {
        swap(cheak + k, cheak + start);
        permutation(cheak, start + 1, end, size, ans, head);
        swap(cheak + k, cheak + start);
    }
}
//swaps the values of two variables. It takes in two pointers a and b which point to two integers that need to be swapped.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}