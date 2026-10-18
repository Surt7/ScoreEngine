#pragma once
#include "core/Event.h"
#include <string_view>

class ConsoleDisplay {
public :
    static void show_event_result(std::string_view raw_msg, const EngineResult &result);

    static void show_parse_error(std::string_view raw_msg);
};
