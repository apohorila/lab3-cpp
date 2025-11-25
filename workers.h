#pragma once 
#include "sync.h"

void f(char task_name, int action_id);
void worker_t1(SyncLatches& latches);
void worker_t2(SyncLatches& latches);
void worker_t3(SyncLatches& latches);
void worker_t4(SyncLatches& latches);