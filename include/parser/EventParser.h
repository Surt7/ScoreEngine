#pragma once
#include "../core/Event.h"
#include <optional>
#include <string_view>


class EventParser {
public:
    static std::optional<Event> parse(std::string_view raw_line);

    static std::string serialize_result(const EngineResult &result);
};
