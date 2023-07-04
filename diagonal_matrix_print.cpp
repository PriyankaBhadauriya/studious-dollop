#include <iostream>
#include <vector>

void printDiagonal(const std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<int> diagonal;

    for (int i = 0; i < rows; i++)
    {
        int row = i;
        int col = 0;
        while (row >= 0 && col < cols)
        {
            diagonal.push_back(matrix[row][col]);
            row -= 1;
            col += 1;
        }
    }

    for (int j = 1; j < cols; j++)
    {
        int row = rows - 1;
        int col = j;
        while (row >= 0 && col < cols)
        {
            diagonal.push_back(matrix[row][col]);
            row -= 1;
            col += 1;
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
