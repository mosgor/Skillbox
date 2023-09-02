#include <iostream>

void evendigits(long long num, int& ans){
    if (num == 0) return;
    else if ((num % 10) % 2 == 0) ans++;
    return evendigits(num /= 10, ans);
}

int main(){
    int ans = 0;
    evendigits(9223372036854775806, ans);
    std::cout << ans;
    return 0;
}