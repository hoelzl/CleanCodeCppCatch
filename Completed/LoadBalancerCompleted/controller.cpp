#include "controller.h"

#include <iostream>

void Controller::balance() const { load_balancer->balance(); }

void Controller::set_load_balancer(std::unique_ptr<LoadBalancer> new_load_balancer)
{
    new_load_balancer->add_resource({"r1"});
    load_balancer = std::move(new_load_balancer);
}
