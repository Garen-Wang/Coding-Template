#include<iostream>

int main()
{
    int y, b, r; std::cin >> y >> b >> r;
    if(y + 1 <= b && y + 2 <= r)
    {
        std::cout << y + y + 1 + y + 2 << std::endl;
    }
    else if(b - 1 <= y && b + 1 <= r)
    {
        std::cout << 3 * b << std::endl;
    }
    else if(r - 2 <= y && r - 1 <= b)
    {
        std::cout << r + r - 1 + r - 2 << std::endl;
    }
    return 0;
}
