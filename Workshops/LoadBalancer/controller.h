#pragma once

#include "load_balancer.h"

class Controller
{
private:
    LoadBalancer load_balancer{};
    Algorithm algorithm{};

public:
    void balance() const;
    void set_algorithm(Algorithm algorithm);
};
