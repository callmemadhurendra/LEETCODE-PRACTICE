#include <iostream>
#include <limits.h>  // For INT_MAX and INT_MIN

int reverse(int x) {
    int ans = 0;
    while (x != 0) {
        int digit = x % 10;
        
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10) ||
            (ans == INT_MAX / 10 && digit > 7) ||
            (ans == INT_MIN / 10 && digit < -8)) {
            return 0;
        }
        
        ans = ans * 10 + digit;
        x /= 10;
    }
    return ans;
}

int main() {
    int num = 123;  // Example number
    std::cout << "Reversed: " << reverse(num) << std::endl;
    return 0;
}
