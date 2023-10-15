#include "header/sheet.h"

//headers;
#include <functional>
#include <iostream>
#include <utility>


namespace {
    void CheckIfPositionValid(Position position) {
        if(!position.IsValid()) {
            std::stringstream ss;
            ss << "Position (" << position.row << "," << position.col << ") is invalid could: not use it in table";
            throw InvalidPositionException(ss.str());
        }
    }
}


void Sheet::SetCell(Position position, std::string text) {
    CheckIfPositionValid(position);

    if (auto* cell = GetCell(position)) {
        dynamic_cast<Cell*>(cell)->Set(std::move(text));
    } else {
        ResizeStorage(position);
        data_.at(position.row).at(position.col) = std::make_unique<Cell>(*this);
        SetCell(position, std::move(text));
    }
}
const CellInterface* Sheet::GetCell(Position position) const {
    return const_cast<Sheet*>(this)->GetCell(position);
}

CellInterface* Sheet::GetCell(Position position) {
    CheckIfPositionValid(position);

    if (position.row >= static_cast<int>(data_.size()))
        return nullptr;
    if (position.col >= static_cast<int>(data_.at(position.row).size()))
        return nullptr;

    return data_.at(position.row).at(position.col).get();
}

void Sheet::ClearCell(Position position) {
    CheckIfPositionValid(position);

    if (GetCell(position))
        data_.at(position.row).at(position.col).reset();
}