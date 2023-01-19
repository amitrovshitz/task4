#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#include "edges.h"
#include "graph.h"
#include "nodes.h"

qnode* new_queuenode(pnode data, int p);
pnode pop(qnode** head);
void push(qnode** head, pnode d, int p);
int isEmpty(qnode** head);
int peek(qnode** head);