#include "controller.h"
#include <iostream>

void Controller::balance()
{
    load_balancer->balance();
}

void Controller::set_load_balancer(std::unique_ptr<LoadBalancer> load_balancer)
{
    load_balancer->add_resource({"r1"});
    this->load_balancer = std::move(load_balancer);
}
