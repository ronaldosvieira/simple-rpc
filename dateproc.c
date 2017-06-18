/* dateproc.c - procedimentos remotos; chamado pelo stub do servidor */

#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include "date.h"

long * bindate_1_svc(void* arg1, struct svc_req *arg2) {
    static long timeval; /* precisa ser static */
    
    timeval = time((long *) 0);
    
    return (&timeval);
}