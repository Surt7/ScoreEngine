#pragma once
#include "Event.h"
#include "IRule.h"
#include <vector>
#include <memory>

class ScoreEngine {
public:
    ScoreEngine() = default;

    EngineResult process_event(const Event &event);

    ~ScoreEngine() = default;

    void add_rule(std::unique_ptr<IRule> rule);

private:
    int64_t total_score_{0};
    uint64_t last_sequence_id_{0};
    std::vector<std::unique_ptr<IRule> > rules_;
};
