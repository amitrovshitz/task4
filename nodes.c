#include "nodes.h"
pnode new_node(int id, pnode next) {
    pnode new = (pnode)malloc(sizeof(node));
    new->node_num = id;
    new->next = next;
    new->edges = NULL;
    return new;
}
pnode generate(int k) {
    pnode head = NULL;
    int i=k;
        while(i)
        {
          head = new_node(i, head);
          i--;
        }
      
    return head;
}
//remove thee edges 
void remove_eo(pnode s) {
    pedge next = s->edges;
    while (next) {
        pedge last = next;
        next = next->next;
        free(last);
    }
}
//remove the node
void remove_source(int id, pnode s) {
    pedge e = s->edges;
    if (e) {
        if (e->endpoint->node_num == id) {
            pedge del =e;
            s->edges = e->next;
            free(del);
            return;
        }
        while (e->next != NULL) {
            if (e->next->endpoint->node_num == id) {
                pedge del = e->next;
                e->next = del->next;
                free(del);
                return;
            }
            e = e->next;
        }
    }
}
// insert node to the list
pnode insert_node(int id, pnode *head) {
    pnode *p = head;
    while ((*p)->next) {
        if ((*p)->node_num < id && (*p)->next->node_num > id) {
            pnode new = new_node(id, (*p)->next);
            (*p)->next = new;
            return new;
        }
        p = &((*p)->next);
    }
    pnode new = new_node(id, (*p)->next);
    (*p)->next = new;
    return new;
}
//cheak if the node exist and returm him
pnode exist(int id, pnode head) {
    while (head) {
        if (head->node_num == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}