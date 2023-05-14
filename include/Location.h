#pragma once
#include <ostream>

struct Location {
    int x;
    int y;
    static const int max_rows = 19; // 0-19: 20 rows
    static const int max_cols = 39; // 0-39: 40 columns

    Location();
    Location(int x_, int y_);

    Location operator+(const Location& other) const;
    Location& operator+=(const Location& other);
    bool operator==(const Location& other) const;
    bool operator!=(const Location& other) const;
    Location operator*(int factor) const;
    Location& operator*=(int factor);


    friend std::ostream& operator<<(std::ostream& os, const Location& location);
};
