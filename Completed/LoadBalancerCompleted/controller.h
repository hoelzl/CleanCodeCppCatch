#pragma once

#include "load_balancer.h"
#include <memory>

class Controller {
private:
    std::unique_ptr<LoadBalancer> load_balancer{};

public:
    void balance();
    void set_load_balancer(std::unique_ptr<LoadBalancer> load_balancer);
};
