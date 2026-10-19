#pragma once
#include <cstdint>
#include <iostream>


class Score {
public:
    Score() = default;

    [[nodiscard]] int64_t value() const { return points_; }

    operator int64_t() const { return points_; }

    Score &operator+=(const int32_t delta) {
        points_ += delta;

        if (points_ < 0) {
            points_ = 0;
        }
        return *this;
    };

    void reset() {
        points_ = 0;
    }

private:
    int64_t points_{0};
};
