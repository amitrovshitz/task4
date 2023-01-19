#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "algo.c"
#include "edges.h"
#include "graph.h"
#include "nodes.h"
#include "queue.h"

void build_graph_cmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode source = find_node(i, *head);
    pedge prev = NULL;
    while (scanf("%d", &i) == 1) {
        pnode dest = find_node(i, *head);
        scanf("%d", &i);
        prev = new_edge(i, prev, dest);
    }
    source->edges = prev;
}

void insert_node_cmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode source = find_node(i, *head);
    if (*head == NULL) {
        *head = new_node(i, NULL);
        source = *head;
    } else if (source != NULL) {
        remove_out_edges(source);
    } else {
        source = insert_node(i, head);
    }
    pedge prev = NULL;
    while (scanf("%d", &i) == 1) {
        pnode dest = find_node(i, *head);
        scanf("%d", &i);
        prev = new_edge(i, prev, dest);
    }
    source->edges = prev;
}

void delete_node_cmd(pnode *head) {
    int i;
    scanf("%d", &i);
    pnode check_node = *head;
    pnode delete = NULL;
    if (check_node->node_num == i) {
        *head = (check_node->next);
        delete = check_node;
    } else {
        while (check_node->next) {
            if (check_node->next->node_num == i) {
                delete = check_node->next;
                check_node->next = delete->next;
                break;
            }
            check_node = check_node->next;
        }
    }
    check_node = *head;
    while (check_node) {
        remove_source(i, check_node);
        check_node = check_node->next;
    }
    remove_out_edges(delete);
    free(delete);
}

void printGraph_cmd(pnode head) {  //for self debug
    while (head) {
        printf("node id: %d\n", head->node_num);
        pedge source = head->edges;
        while (source) {
            printf("%d -> %d   w: %d\n", head->node_num, source->endpoint->node_num, source->weight);
            source = source->next;
        }
        head = head->next;
    }
}

void deleteGraph_cmd(pnode *head) {
    pnode source = *head;
    while (source) {
        remove_out_edges(source);
        pnode delete = source;
        source = source->next;
        free(delete);
    }
}
void shortsPath_cmd(pnode head) {
    int src;
    int dest;
    int got = 0;
    while (got == 0) {
        got = scanf("%d", &src);
    }
    got = 0;
    while (got == 0) {
        got = scanf("%d", &dest);
    }
    pnode source;
    pnode curr = head;
    int j = 0;
    int dst_index;
    int src_index;
    while (curr) {
        curr->index = j;
        if (curr->node_num == src) {
            source = curr;
            src_index = j;
        }
        if (curr->node_num == dest) {
            dst_index = j;
        }
        j++;
        curr = curr->next;
    }
    int *arr = (int *)malloc(sizeof(int) * j);
    for (int i = 0; i < j; i++) {
        arr[i] = INT_MAX;
    }
    arr[src_index] = 0;
    dijkstra(arr, source);
    printf("Dijsktra shortest path: %d \n", arr[dst_index] < INT_MAX ? arr[dst_index] : -1);
    free(arr);
}

void TSP_cmd(pnode head) {
    int j;
    scanf("%d", &j);
    int *cities = (int *)malloc(sizeof(int) * j);
    for (int i = 0; i < j; i++) {
        scanf("%d", &cities[i]);
    }
    int number_of_nodes = 0;
    pnode source = head;
    while (source) {
        source->index = number_of_nodes;
        number_of_nodes++;
        source = source->next;
    }
    int ans = INT_MAX;
    permutation(cities, 0, j - 1, number_of_nodes, &ans, head);
    printf("TSP shortest path: %d \n", ans != INT_MAX ? ans : -1);
    free(cities);
}

int main() {
    char s;
    int k;
    pnode head = NULL;
    while (scanf("%c", &s) != EOF) {
        switch (s) {
            case 'A':
                deleteGraph_cmd(&head);
                scanf("%d", &k);
                head = generate(k);
                break;
            case 'n':
                build_graph_cmd(&head);
                break;
            case 'B':
                insert_node_cmd(&head);
                break;
            case 'p':
                printGraph_cmd(head);
                break;
            case 'S':
                shortsPath_cmd(head);
                break;
            case 'D':
                delete_node_cmd(&head);
                break;
            case 'T':
                TSP_cmd(head);
                break;
        }
    }
    deleteGraph_cmd(&head);
    return 0;
}