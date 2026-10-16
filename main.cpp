#include <iostream>
#include <cstdint>

#include "ScoreEngine.h"


int main() {
    ScoreEngine engine;

    // start

    const Event e1{
        .sequence_id = 1,
        .switch_code = "START_BUTTON",
        .timestamp_ns = 1000,
        .signature = "VALID_SECRET"
    };

    // bumper hit
    const auto res1 = engine.process_event(e1);
    std::cout << "[Event 1] Action: " << to_string(res1.action)
            << "| Score: " << res1.total_score << std::endl;


    const Event e2{
        .sequence_id = 2,
        .switch_code = "BUMPER_1",
        .timestamp_ns = 2000,
        .signature = "VALID_SECRET"
    };

    const auto res_replay = engine.process_event(e2);
    std::cout << "[Rejeu bloque !] Action: " << to_string(res_replay.action)
            << " | Score: " << res_replay.total_score << std::endl;

    // replay attack
    const auto res3 = engine.process_event(e2);
    std::cout << "[Event 3 - Rejeu] Action: " << to_string(res3.action)
            << " | Score: " << res3.total_score << std::endl;

    return 0;
}
