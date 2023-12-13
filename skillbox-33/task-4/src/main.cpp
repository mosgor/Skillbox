#include <iostream>

template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

template < typename T >
double average(T array[8])
{
    double sum;
    for (int i = 0; i < 8; ++i)
    {
        sum += array[i];
    }
    return sum / 8;
}

int main(){
    int arr[8];
    input(arr);
    std::cout << "Average is " << average(arr);
    return 0;
}