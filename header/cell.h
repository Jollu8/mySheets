#pragma once
#include "common.h"
#include "formula.h"
#include <optional>
#include <unordered_set>
#include <memory>



class Cell : public CellInterface {
public:  // Types
    using CellsStorage = std::unordered_set<const Cell*>;

public:  // Constructor
    explicit Cell(SheetInterface& sheet);

public:  // Destructor
    ~Cell() override = default;

public:  // Methods
    void Set(std::string text) override;
    void Clear();

    Value GetValue() const override;
    std::string GetText() const override;
    std::vector<Position> GetReferencedCells() const override;

    bool IsReferenced() const;

private:  // Types and using
    class CellValueInterface;
    class EmptyCellValue;
    class TextCellValue;
    class FormulaCellValue;

    using CellValueIntefaceUPtr = std::unique_ptr<CellValueInterface>;

private:
    /* SET METHOD HELPERS */
    void InstantiateCellsIfNotExists(const CellValueIntefaceUPtr& current);
    bool HasCircularDependency(const Cell* reference, const CellValueIntefaceUPtr& current,
                               CellsStorage& visited) const;
    void RemoveOldConnections();
    void EstablishNewConnections(FormulaCellValue* formula_cell);
    void InvalidateReferencedCellsCache(CellsStorage& visited) const;

    /* SUPPORT FUNCTIONS */

    const Cell* GetCell(Position position) const;
    void GetReferencedCellsImpl(std::vector<Position>& referenced, CellsStorage& visited) const;
    CellValueIntefaceUPtr TryCreateCell(std::string text, SheetInterface& sheet) const;
    FormulaCellValue* TryInterpretAsFormula(const CellValueIntefaceUPtr& cell) const;

private:
    SheetInterface& sheet_;
    CellValueIntefaceUPtr value_{nullptr};

    mutable CellsStorage descending_cells_;
    mutable CellsStorage ascending_cells_;
};
class Cell::CellValueInterface {
public:  // Types
    using Value = CellInterface::Value;

    enum class Type { Empty, Text, Formula };

public:  // Constructor
    explicit CellValueInterface(Type type) : type_(type) {}

public:  // Destructor
    virtual ~CellValueInterface() = default;

public:  // Methods
    [[nodiscard]] virtual Value GetValue() const = 0;
    [[nodiscard]] virtual Value GetRawValue() const = 0;
    [[nodiscard]] virtual std::string GetText() const = 0;

    [[nodiscard]] Type GetType() const {
        return type_;
    }

private:  // Fields
    Type type_;
};
