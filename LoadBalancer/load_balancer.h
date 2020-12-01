#pragma once

#include <vector>

enum class Algorithm
{
    ROUND_ROBIN,
    WEIGHTED_ROUND_ROBIN
};

using queue_t = std::vector<double>;

class LoadBalancer {
public:
    // For RR scheduling
    queue_t queue{};
    // For Weighted RR scheduling
    std::vector<double> weights{};
    std::vector<queue_t> queues{};
};
