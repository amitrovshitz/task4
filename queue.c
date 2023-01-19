#include "queue.h"//build the queue node
qnode* new_queuenode(pnode data, int p) {
    qnode* tmp = (qnode*)malloc(sizeof(qnode));
    tmp->nodedata = data;
    tmp->priority = p;
    tmp->next = NULL;
    return tmp;
}
//enter the queue 
void push(qnode** head, pnode d, int p) {
    qnode* start = (*head);
    qnode* tmp = new_queuenode(d, p);
    if (isEmpty(head)) {
        (*head) = tmp;
        return;
    }

    if ((*head)->priority > p) {
        tmp->next = *head;
        (*head) = tmp;
    } else {
        while (start->next != NULL && start->next->priority < p) {
            start = start->next;
        }

        tmp->next = start->next;
        start->next = tmp;
    }
}
//delete from the queue the top
pnode pop(qnode** head) {
    pnode tmp = (*head)->nodedata;
    qnode* tofree = *head;
    (*head) = (*head)->next;
    free(tofree);
    return tmp;
}
//cheak if the queue is empty
int isEmpty(qnode** head) {
    return (*head) == NULL;
}