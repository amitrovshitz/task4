#include "nodes.h"

pnode new_node(int k, pnode next) {
    pnode p = (pnode)malloc(sizeof(node));
    p->node_num = k;
    p->next = next;
    p->edges = NULL;
    return p;
}

pnode find_node(int data, pnode head) {
    while (head) {
        if (head->node_num == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

pnode generate(int k) {
    pnode head = NULL;
    for (int i = k - 1; i >= 0; i--) {
        head = new_node(i, head);
    }
    return head;
}

void remove_out_edges(pnode source) {
    pedge next = source->edges;
    while (next) {
        pedge prev = next;
        next = next->next;
        free(prev);
    }
}

void remove_source(int data, pnode source) {
    pedge check_edge = source->edges;
    if (check_edge) {
        if (check_edge->endpoint->node_num == data) {
            pedge delete = check_edge;
            source->edges = check_edge->next;
            free(delete);
            return;
        }
        while (check_edge->next != NULL) {
            if (check_edge->next->endpoint->node_num == data) {
                pedge delete = check_edge->next;
                check_edge->next = delete->next;
                free(delete);
                return;
            }
            check_edge = check_edge->next;
        }
    }
}

pnode insert_node(int data, pnode *head) {
    pnode *p = head;
    while ((*p)->next) {
        if ((*p)->node_num < data && (*p)->next->node_num > data) {
            pnode new = new_node(data, (*p)->next);
            (*p)->next = new;
            return new;
        }
        p = &((*p)->next);
    }
    pnode new = new_node(data, (*p)->next);
    (*p)->next = new;
    return new;
}