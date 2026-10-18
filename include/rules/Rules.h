#pragma once
#include "IRule.h"

class BumperRule : public IRule {
public:
    [[nodiscard]] bool matches(const Event &event) const override {
        return event.switch_code == "BUMPER_1";
    };

    RuleEffect apply(const Event &) override {
        return RuleEffect{
            .score_delta = 100,
            .action = GameAction::BumperHit
        };
    };
};

class StartButtonRule : public IRule {
public:
    [[nodiscard]] bool matches(const Event &event) const override {
        return event.switch_code == "START_BUTTON";
    }

    RuleEffect apply(const Event &) override {
        return RuleEffect{
            .score_delta = 0,
            .action = GameAction::GameStart
        };
    };
};

