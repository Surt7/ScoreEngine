#include <iostream>
#include <cstdint>

#include "core/GameSession.h"
#include "display/ConsoleDisplay.h"
#include "include/parser/EventParser.h"
#include "include/rules/Rules.h"
#include "include/core/ScoreEngine.h"


int main() {
    GameSession session;
    session.init();
    // start

    const std::vector<std::string_view> messages = {
        "1;START_BUTTON;1000;VALID_SECRET",
        "2;BUMPER_1;2000;VALID_SECRET",
        "2;BUMPER_1;2000;VALID_SECRET",
        "3;BUMPER_2;3000;VALID_SECRET",
        "TRAME_CORROMPUE_SANS_SEPARATEUR"
    };

    session.process_batch(messages);
    session.display_summary();

    
    return 0;
}
