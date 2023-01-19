#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "graph.h"
#include "nodes.h"
qnode* new_queue_node(pnode , int );
pnode pop(qnode** );
void push(qnode** , pnode , int );
int is_empty(qnode** );
