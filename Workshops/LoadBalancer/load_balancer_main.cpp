#include "controller.h"

int main()
{
    Controller controller{};
    controller.set_algorithm(Algorithm::round_robin);
    controller.balance();

    std::cout << std::endl;
    controller.set_algorithm(Algorithm::weighted_round_robin);
    controller.balance();
}