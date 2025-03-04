#include <iostream>
#include <cassert>

/**
 * @brief Asks person A if they know person B.
 * @param a The number of person A.
 * @param b The number of person B.
 * @return true if A knows B, otherwise returns false.
 */
bool ask_a_to_know_b(int a, int b) {
    int result;
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

/**
 * @brief Verifies if person x is a celebrity.
 * @param x The number of the person to verify, or -1 if there is no celebrity.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer(int x) {
    int result;
    std::cout << "! " << x << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,result = 1;
    std::cin >> n;

    for(int i=2;i<=n;i++) if(ask_a_to_know_b(result,i)) result = i;

    for(int i=1;i<=n;i++)
        if(result!=i && (ask_a_to_know_b(result,i) || !ask_a_to_know_b(i,result))) answer(-1);

    return answer(result);
}
