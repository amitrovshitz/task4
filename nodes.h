#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
pnode generate(int );
pnode new_node(int , pnode );
pnode find_node(int , pnode );
void remove_out_edges(pnode );
void remove_source(int , pnode );
pnode insert_node(int , pnode *);