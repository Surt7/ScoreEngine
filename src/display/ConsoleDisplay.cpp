#include "display/ConsoleDisplay.h"
#include <iostream>
#include "parser/EventParser.h"


void ConsoleDisplay::show_event_result(const std::string_view raw_msg, const EngineResult &result) {
    std::cout << "[OK] Message: " << raw_msg
            << " -> Action: " << to_string(result.action)
            << " | Score: " << result.total_score << "\n";
}


void ConsoleDisplay::show_parse_error(const std::string_view raw_msg) {
    std::cout << "[ERREUR] Message: " << raw_msg
            << " -> Trame corrompue !\n";
}


void ConsoleDisplay::show_json_result(const EngineResult &result) {
    std::cout << "[JSON Output]: "
            << EventParser::serialize_result(result) << "\n";
}
