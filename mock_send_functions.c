#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include <stdbool.h>
#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "CuTest.h"

#include "linked_list_queue.h"

#include "raft.h"

typedef struct {
    void* inbox;
} sender_t;

int sender_send(void* caller, void* udata, void* peer, const unsigned char* data, int len)
{
    sender_t* me = udata;
    void* n;

    n = malloc(len);
    memcpy(n,data,len);
    llqueue_offer(me->inbox,(void*)data);
    return 0;
}

void* sender_new()
{
    sender_t* me;

    me = malloc(sizeof(sender_t));
    me->inbox = llqueue_new();
    return me;
}

void* sender_poll_msg(void* s)
{
    return NULL;
}
