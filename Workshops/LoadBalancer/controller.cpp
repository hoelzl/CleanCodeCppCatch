#include "controller.h"

#include <iostream>

#include "resource.h"

void Controller::balance() const
{
    switch (algorithm) {
    case Algorithm::round_robin: {
        const queue_t& queue = load_balancer.queue;
        std::cout << "Using round robin balancer." << std::endl;
        for (const Resource& r : queue) {
            std::cout << "Scheduling " << r << "." << std::endl;
        }
        std::cout << "Done balancing." << std::endl;
        break;
    }
    case Algorithm::weighted_round_robin: {
        const std::vector<std::pair<double, queue_t>>& weighted_queues
            = load_balancer.weighted_queues;
        std::cout << "Using weighted round robin balancer." << std::endl;
        for (const auto& wq : weighted_queues) {
            for (const Resource& r : wq.second) {
                std::cout << "Scheduling " << r << " with weight " << wq.first << "."
                          << std::endl;
            }
        }
        std::cout << "Done balancing." << std::endl;
        break;
    }
    default: std::cerr << "Error: bad algorithm type.";
    }
}

void Controller::set_algorithm(Algorithm algorithm)
{
    this->algorithm = algorithm;
    switch (algorithm) {
    case Algorithm::round_robin: {
        std::cout << "Setting round robin balancer." << std::endl;
        load_balancer.queue.push_back(Resource{"r1"});
        break;
    }
    case Algorithm::weighted_round_robin: {
        std::cout << "Setting weighted round robin balancer." << std::endl;
        std::vector<std::pair<double, queue_t>>& weighted_queues
            = load_balancer.weighted_queues;
        queue_t queue{Resource("r1")};
        load_balancer.weighted_queues.emplace_back(1, queue);
        break;
    }
    default: std::cerr << "Error: bad algorithm type.";
    }
}
