
#include <iostream>
#include <string>
#include <string_view>

#include "src/header/common.h"
#include "src/header/test_runner_p.h"

inline std::ostream& operator<<(std::ostream& output, Position pos) {
    return output << "(" << pos.row << ", " << pos.col << ")";
}

inline Position operator"" _pos(const char* str, std::size_t) {
    return Position::FromString(str);
}

int main() {

    return 0;
}