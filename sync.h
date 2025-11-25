#pragma once
#include <latch>

struct SyncLatches {
    std:: latch start_g{10};
    std:: latch start_h_i{13};
    std:: latch start_j{14};
    std:: latch main_wait{4};
};