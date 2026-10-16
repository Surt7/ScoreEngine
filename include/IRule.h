#pragma once
#include "Event.h"

struct RuleEffect {
    int32_t score_delta{0};
    GameAction action{GameAction::None};
};

class IRule {
public:
    virtual ~IRule() = default;

    virtual bool matches(const Event &event) const = 0;

    virtual RuleEffect apply(const Event &event) =0;
};
