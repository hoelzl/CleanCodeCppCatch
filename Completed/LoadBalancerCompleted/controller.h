#pragma once

#include <memory>

#include "load_balancer.h"

class Controller
{
private:
    std::unique_ptr<LoadBalancer> load_balancer{};

public:
    void balance() const;
    void set_load_balancer(std::unique_ptr<LoadBalancer> new_load_balancer);
};
