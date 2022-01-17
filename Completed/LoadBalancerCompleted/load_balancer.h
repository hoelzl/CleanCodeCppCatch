#pragma once

#include <iostream>
#include <vector>

#include "resource.h"

using queue_t = std::vector<Resource>;

class LoadBalancer
{
public:
    virtual ~LoadBalancer() = default;
    virtual void add_resource(Resource r) = 0;
    virtual void balance() = 0;
};

class RoundRobin : public LoadBalancer
{
    queue_t queue{};

public:
    void add_resource(Resource r) override;

    void balance() override;
};

struct WeightedQueue
{
    WeightedQueue(double weight = 1, queue_t queue = {})
        : weight(weight), queue{std::move(queue)}
    {}
    double weight;
    queue_t queue;
};

class WeightedRoundRobin : public LoadBalancer
{
public:
    using weighted_queues_t = std::vector<WeightedQueue>;

private:
    weighted_queues_t weighted_queues{};

public:
    void add_resource(Resource r) override;

    void balance() override;
};