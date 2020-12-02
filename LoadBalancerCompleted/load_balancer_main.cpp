#include "controller.h"

int main()
{
    Controller controller{};
    controller.set_load_balancer(std::make_unique<RoundRobin>());
    controller.balance();

    std::cout << std::endl;
    controller.set_load_balancer(std::make_unique<WeightedRoundRobin>());
    controller.balance();
}