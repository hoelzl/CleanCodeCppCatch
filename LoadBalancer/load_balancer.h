#pragma once

#include "resource.h"
#include <vector>
#include <utility>

enum class Algorithm
{
    ROUND_ROBIN,
    WEIGHTED_ROUND_ROBIN
};

using queue_t = std::vector<Resource>;

class LoadBalancer {
public:
    // For RR scheduling
    queue_t queue{};
    // For Weighted RR scheduling
    std::vector<std::pair<double, queue_t>> weighted_queues{};
};
