p=rearA->next;
q=rearB->next;

rearA->next=rearB->next->next;
rearB->next=p
free(q);