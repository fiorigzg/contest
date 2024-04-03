#include <iostream>
#include <vector>

using std::vector;

class Minesweeper
{
private:
    size_t RowsCount, ColumnsCount;
    vector<vector<int>> Table;

public:
    Minesweeper(size_t rowsCount, size_t columnsCount) : RowsCount(rowsCount), ColumnsCount(columnsCount)
    {
        Table.resize(RowsCount);
        for (auto& row: Table)
        {
            row.resize(ColumnsCount);
            for (auto& val: row)
            {
                val = 0;
            }
        }
    }

    size_t Rows() const
    {
        return RowsCount;
    }

    size_t Columns() const
    {
        return ColumnsCount;
    }

    void SetMine(size_t row, size_t column)
    {
        if (row < RowsCount && column < ColumnsCount)
            Table[row][column] = -1;
    }

    int operator()(size_t row, size_t column) const
    {
        if (row < RowsCount && column < ColumnsCount)
            return Table[row][column];
        else
            return 0;
    }

    void CheckForMinesAround()
    {
        for (size_t row = 0; row < RowsCount; ++row)
            for (size_t column = 0; column < ColumnsCount; ++column)
                CheckForMinesAround(row, column);
    }

private:
    void CheckForMinesAround(size_t row, size_t column)
    {
        int counter = 0;
        if (Table[row][column] != -1)
        {
            for (int dx = -1; dx <= 1; ++dx)
            {
                for (int dy = -1; dy <= 1; ++dy)
                {
                    if (0 <= row + dx && row + dx < RowsCount && 0 <= column + dy && column + dy < ColumnsCount && Table[row + dx][column + dy] == -1)
                    {
                        ++counter;
                    }
                }
            }
            Table[row][column] = counter;
        }
    }
};

std::ostream& operator<<(std::ostream& out, const Minesweeper& ms)
{
    for (size_t row = 0; row < ms.Rows(); ++row)
    {
        for (size_t column = 0; column < ms.Columns(); ++column)
        {
            if (ms(row, column) == -1)
                out << '*';
            else
                out << ms(row, column);
        }
        out << "\n";
    }
    return out;
}