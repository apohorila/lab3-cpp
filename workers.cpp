#include "workers.h"
#include "sync.h"
#include <iostream>
#include <syncstream>
#include <format>
#include <string>

void f (char task_name, int task_id){
    std::osyncstream(std::cout) << "З набору " << task_name << " виконано дію " << task_id << ".\n";
}

void execute_set(char task_name, int start_index, int op_count){
    for (int i = 0; i < op_count; ++i){
        f(task_name, start_index + i);
    }
}

void worker_t1(SyncLatches& latches){

    execute_set('d',1,9);
    latches.start_j.count_down(9);

    execute_set('a',1,1);
    latches.start_g.count_down(1);

    latches.start_j.wait();

    execute_set('j',1,7);

    latches.main_wait.count_down();

}

void worker_t2(SyncLatches& latches) {
    execute_set('b', 1, 8); 
    latches.start_h_i.count_down(8);
    
    execute_set('c', 1, 1); 
    latches.start_g.count_down(1);

    latches.start_h_i.wait(); 
    execute_set('h', 1, 8); 
    
    latches.main_wait.count_down();
}

void worker_t3(SyncLatches& latches) {
    execute_set('a', 2, 3); 
    latches.start_g.count_down(3); 

    execute_set('f', 1, 5); 
    latches.start_j.count_down(5); 

    latches.start_g.wait(); 
    execute_set('g', 1, 9); 
    
    latches.main_wait.count_down();
}

void worker_t4(SyncLatches& latches) {
    execute_set('e', 1, 5); 
    latches.start_h_i.count_down(5); 

    execute_set('c', 2, 5);
    latches.start_g.count_down(5); 

    latches.start_h_i.wait(); 
    execute_set('i', 1, 7); 
    
    latches.main_wait.count_down();
}