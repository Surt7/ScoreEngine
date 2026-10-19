#pragma once
#include "ScoreEngine.h"
#include <vector>
#include <string_view>


class GameSession {
public:
    GameSession() = default;

    // init rule base
    void init();

    // process received messages
    void process_batch(const std::vector<std::string_view> &messages);

    // display final score , stats ...
    void display_summary() const;

    [[nodiscard]] const std::vector<EngineResult> &history() const { return history_; }

    void display_json_history() const;

private :
    ScoreEngine engine_;
    std::vector<EngineResult> history_;
    size_t parse_errors_count_{0};
};
