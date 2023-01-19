  #include "nodes.h"
pedge new_edge(int weight, pedge next, pnode e) {
    pedge new = (pedge)malloc(sizeof(edge));
   new->weight=weight;
   new->endpoint=e;
   new->next=next;
    return new;
}
