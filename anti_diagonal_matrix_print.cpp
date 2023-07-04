#include <iostream>
#include <vector>

void printDiagonal(const std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<int> diagonal;

    for (int i = 0; i < rows + cols - 1; i++)
    {
        int startRow, startCol;
        if (i < cols)
        {
            startRow = 0;
            startCol = i;
        }
        else
        {
            startRow = i - cols + 1;
            startCol = cols - 1;
        }

        while (startRow < rows && startCol >= 0)
        {
            diagonal.push_back(matrix[startRow][startCol]);
            startRow++;
            startCol--;
        }
    }

    for (int element : diagonal)
    {
        std::cout << element << " ";
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}};

    printDiagonal(matrix);

    return 0;
}
