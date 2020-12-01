#include "controller.h"

int main()
{
    Controller controller{};
    controller.set_algorithm(Algorithm::ROUND_ROBIN);
    controller.balance();
    controller.set_algorithm(Algorithm::WEIGHTED_ROUND_ROBIN);
    controller.balance();
}