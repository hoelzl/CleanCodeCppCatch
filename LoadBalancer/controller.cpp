#include "controller.h"
#include <iostream>

void Controller::balance()
{
    switch (algorithm) {
        case Algorithm::ROUND_ROBIN: {
            queue_t& queue = load_balancer.queue;
            std::cout << "Using round robin balancer." << std::endl;
            break;        
        }
        case Algorithm::WEIGHTED_ROUND_ROBIN: {
            std::vector<queue_t>& queues = load_balancer.queues;
            std::cout << "Using weighted round robin balancer." << std::endl;
            break;        
        }
        default: std::cerr << "Error: bad algorithm type.";
    }
}

void Controller::set_algorithm(Algorithm algorithm)
{
    this->algorithm = algorithm;
}
