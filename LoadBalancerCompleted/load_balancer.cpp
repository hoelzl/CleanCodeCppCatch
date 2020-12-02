#include "load_balancer.h"

void RoundRobin::add_resource(Resource r)
{
    std::cout << "Adding resource to round robin balancer." << std::endl;
    queue.push_back(std::move(r));
}

void RoundRobin::balance()
{
    std::cout << "Using round robin balancer." << std::endl;
    for (const Resource& r : queue) {
        std::cout << "Scheduling " << r << "." << std::endl;
    }
    std::cout << "Done balancing." << std::endl;
}

void WeightedRoundRobin::add_resource(Resource r)
{
    std::cout << "Adding resource to weighted round robin balancer."
              << std::endl;
    queue_t queue{};
    queue.push_back(std::move(r));
    weighted_queues.push_back({1.0, std::move(queue)});
}

void WeightedRoundRobin::balance()
{
    std::cout << "Using weighted round robin balancer." << std::endl;
    for (const auto& wq : weighted_queues) {
        for (const Resource& r : wq.queue) {
            std::cout << "Scheduling " << r << " with weight " << wq.weight
                      << "." << std::endl;
        }
    }
    std::cout << "Done balancing." << std::endl;
}
