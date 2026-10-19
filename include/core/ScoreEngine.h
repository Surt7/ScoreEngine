#pragma once
#include "Event.h"
#include "../rules/IRule.h"
#include <vector>
#include <memory>
#include "Score.h"

class ScoreEngine {
public:
    ScoreEngine() = default;

    EngineResult process_event(const Event &event);

    ~ScoreEngine() = default;

    void add_rule(std::unique_ptr<IRule> rule);

    [[nodiscard]] int64_t total_score() const { return total_score_.value(); }

    template<typename T, typename... Args>
    void add_rule(Args &&... args) {
        rules_.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

private:
    Score total_score_;
    uint64_t last_sequence_id_{0};
    std::vector<std::unique_ptr<IRule> > rules_;
};
