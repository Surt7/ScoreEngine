#include "core/GameSession.h"
#include "rules/Rules.h"
#include "parser/EventParser.h"
#include "display/ConsoleDisplay.h"
#include <iostream>

void GameSession::init() {
    engine_.add_rule<StartButtonRule>();
    engine_.add_rule<BumperRule>();
}

void GameSession::process_batch(const std::vector<std::string_view> &messages) {
    for (const auto msg: messages) {
        if (auto maybe_event = EventParser::parse(msg); maybe_event.has_value()) {
            auto result = engine_.process_event(*maybe_event);
            history_.push_back(result);
            ConsoleDisplay::show_event_result(msg, result);
        } else {
            ++parse_errors_count_;
            ConsoleDisplay::show_parse_error(msg);
        }
    }
}

void GameSession::display_summary() const {
    std::cout << "\n==============================\n";
    std::cout << "        BILAN DE SESSION      \n";
    std::cout << "==============================\n";
    std::cout << "Evenements traites : " << history_.size() << "\n";
    std::cout << "Erreurs de parsing : " << parse_errors_count_ << "\n";
    std::cout << "Score Total Final  : " << engine_.total_score() << " pts\n";
    std::cout << "==============================\n";
}
