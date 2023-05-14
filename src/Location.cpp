#include "Location.h"

Location::Location() : x(0), y(0) {}

Location::Location(int x_, int y_) : x(x_), y(y_) {}

Location Location::operator+(const Location& other) const {
    int new_x = this->x + other.x;
    if (new_x > max_cols) {
        new_x = 2*max_cols - new_x;
    }
    else if (new_x < 0) {
		new_x = -new_x;
	}

    int new_y = y + other.y;
    if (new_y > max_rows) {
		new_y = 2*max_rows - new_y;
	}
    else if (new_y < 0) {
        new_y = -new_y;
    }

    return Location(new_x, new_y);
}

Location& Location::operator+=(const Location& other) {
    *this = *this + other;
	return *this;
}

bool Location::operator==(const Location& other) const {
    return x == other.x && y == other.y;
}

bool Location::operator!=(const Location& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << "(" << location.x << ", " << location.y << ")";
    return os;
}

Location Location::operator*(int factor) const {
	return Location(x * factor, y * factor);
}

Location& Location::operator*=(int factor) {
	*this = *this * factor;
	return *this;
}


