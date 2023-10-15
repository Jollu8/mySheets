// my headers;
#include "header/formula.h"

// headers;

#include <algorithm>
#include <regex>
#include <sstream>

//my headers;

#include "header/FormulaAST.h"
#include "header/cell.h"


std::ostream &operator<<(std::ostream &output, FormulaError error) {
    return output << error.ToString();

}

struct CellValueGetter {
    double operator()(const std::string &text) {
        try {
            static const std::regex kDoubleValuePattern("^(-?)(0|([1-9][0-9]*))(.[0-9]+)?$");
            std::smatch match;
            if (std::regex_match(text.cbegin(), text.cend(), match, kDoubleValuePattern)) return std::stod(text);

            throw std::runtime_error("");

        } catch (...) {
            throw FormulaError(FormulaError::Category::Value);
        }
    }

    double operator()(double value) {
        return value;
    }

    double operator()(const FormulaError &error) {
        throw error;
    }
}
