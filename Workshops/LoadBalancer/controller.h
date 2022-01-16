#pragma once

#include "load_balancer.h"

class Controller {
private:
    LoadBalancer load_balancer{};
    Algorithm algorithm;

public:
    void balance();
    void set_algorithm(Algorithm algorithm);
};
