#include "../../include/parser/EventParser.h"
#include <charconv>


std::optional<Event> EventParser::parse(std::string_view raw_line) {
    if (raw_line.empty()) {
        return std::nullopt;
    }

    const auto pos1 = raw_line.find(';');
    if (pos1 == std::string_view::npos) return std::nullopt;

    const auto pos2 = raw_line.find(';', pos1 + 1);
    if (pos2 == std::string_view::npos) return std::nullopt;

    const auto pos3 = raw_line.find(';', pos2 + 1);
    if (pos3 == std::string_view::npos) return std::nullopt;


    const auto seq_str = raw_line.substr(0, pos1);
    const auto switch_str = raw_line.substr(pos1 + 1, pos2 - pos1 - 1);
    const auto time_str = raw_line.substr(pos2 + 1, pos3 - pos2 - 1);
    const auto sig_str = raw_line.substr(pos3 + 1);

    uint64_t seq_id{0};
    auto [ptr_seq, ec_seq] = std::from_chars(seq_str.data(), seq_str.data() + seq_str.size(), seq_id);
    if (ec_seq != std::errc{}) {
        return std::nullopt;
    }

    int64_t timestamp{0};
    auto [ptr_timestamp, ec_timestamp] = std::from_chars(time_str.data(), time_str.data() + time_str.size(), timestamp);
    if (ec_timestamp != std::errc{}) {
        return std::nullopt;
    }


    return Event{
        .sequence_id = seq_id,
        .switch_code = std::string(switch_str),
        .timestamp_ns = timestamp,
        .signature = std::string(sig_str)
    };
}

