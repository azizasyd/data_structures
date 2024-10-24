#include <bits/stdc++.h>

//          1
//     2        3
//  4     5    6 7
// 8 9  10 11

// 1           2           4              8           (left_null)  (cout << 8)  (right_null)  (return to 4)
//                         (cout << 4)    9           (left_null)  (cout << 9)  (left_null)   (return to 2)
//             (cout << 2) 5              10          (left_null)  (cout << 10) (right_null)  (return to 5)
//                         (cout << 5)    11          (left_null)  (cout << 11) (right_null)  (return to 1)
// (cout << 1) 3           6              (left_null) (cout << 6)  (right_null) (return to 3)
//             (cout << 3) 7              (left_null) (cout << 7)  (right_null) (return to 1)

// 8 4 9 2 10 5 11 1 6 3 7

// left vertex right
void LVR(int v, int n) {
    if (v > n) {
        // return to prev call, resumes where it stopped (goes to next operation (print && right))
        return;
    }

    LVR(2 * v, n); // until null

    // curr node
    std::cout << v << " ";

    // right (called once, since left node goes first)
    LVR(2 * v + 1, n); // until null
}

int main(){
    int n;
    std::cin >> n;
    LVR(1, n);
    return 0;
}