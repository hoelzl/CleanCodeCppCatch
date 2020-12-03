#include "controller.h"

int main()
{
    Controller controller{};
    std::unique_ptr<LoadBalancer> load_balancer{std::make_unique<RoundRobin>()};
    controller.set_load_balancer(std::move(load_balancer));
    controller.balance();

    std::cout << std::endl;
    controller.set_load_balancer(std::make_unique<WeightedRoundRobin>());
    controller.balance();
}