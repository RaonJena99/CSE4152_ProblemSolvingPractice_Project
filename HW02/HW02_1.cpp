#include <iostream>
#include <cassert>

/**
 * @brief Query the value of the cell (r, c).
 * @param r The row number of the cell.
 * @param c The column number of the cell.
 * @return The value of the cell (r, c).
 */
int query_cell(int r, int c) {
    int result;
    std::cout << "? " << r << ' ' << c << std::endl;
    std::cin >> result;
    assert(result != -1);
    return result;
}

/**
 * @brief Verifies if the value of the cell (r, c) is equal to K.
 * @param r The row number of the cell.
 * @param c The column number of the cell.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer_with_cell(int r, int c) {
    int result;
    std::cout << "! " << r << ' ' << c << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

/**
 * @brief Verifies if there is no cell with value K in the matrix.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer_without_cell() {
    int result;
    std::cout << "! -1" << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    int i=1,j=n;
    while(i<=n && j >= 1){
        int value = query_cell(i,j);
        if(value==k) return answer_with_cell(i,j);
        else if(value<k) i++;
        else j--;
    }

    return answer_without_cell();
}
