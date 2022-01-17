#pragma once

#include <utility>
#include <vector>

#include "resource.h"

enum class Algorithm
{
    round_robin,
    weighted_round_robin
};

using queue_t = std::vector<Resource>;

class LoadBalancer
{
public:
    // For RR scheduling
    queue_t queue{};
    // For Weighted RR scheduling
    std::vector<std::pair<double, queue_t>> weighted_queues{};
};
