
#pragma once
#include <cstdint>
#include <string>
#include <string_view>


enum class EngineStatus: uint8_t {
    Accepted,
    RejectedInvalidSignature,
    RejectedReplay,
    RejectedUnknownSwitch
};

enum class GameAction: uint8_t {
    None,
    GameStart,
    BumperHit,
    LeftFlipperPressed,
    RightFlipperPressed,
    UnknownSwitch,
    RejectedReplay,
    RejectedInvalidSignature
};


constexpr std::string_view to_string(GameAction action) {
    switch (action) {
        case GameAction::None: return "None";
        case GameAction::GameStart: return "GameStart";
        case GameAction::BumperHit: return "BumperHit";
        case GameAction::LeftFlipperPressed: return "LeftFlipperPressed";
        case GameAction::RightFlipperPressed: return "RightFlipperPressed";
        case GameAction::UnknownSwitch: return "UnknownSwitch";
        case GameAction::RejectedReplay: return "RejectedReplay";
        case GameAction::RejectedInvalidSignature: return "RejectedInvalidSignature";
    }
    return "Unknown";
}


struct Event {
    uint64_t sequence_id{0};
    std::string switch_code{};
    int64_t timestamp_ns{0};
    std::string signature{};
};


struct EngineResult {
    EngineStatus status{EngineStatus::Accepted};
    uint64_t sequence_id{0};
    int32_t score_delta{0};
    int64_t total_score{0};
    GameAction action{GameAction::None};
};
