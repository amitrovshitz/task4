#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

pnode generate(int k);
pnode new_node(int k, pnode next);
pnode find_node(int data, pnode head);
void remove_out_edges(pnode here);
void remove_source(int data, pnode here);
pnode insert_node(int data, pnode *head);