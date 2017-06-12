#include <iostream>

bool XOR(bool a, bool b)
{
    return (a + b) % 2;
}

int main()
{
    using namespace std;
    cout << "XOR(true, true):\t" << XOR(true, true) << endl
         << "XOR(true, false):\t" << XOR(true, false) << endl
         << "XOR(false, true):\t" << XOR(false, true) << endl
         << "XOR(false, false):\t" << XOR(false, false) << endl
         << "XOR(0, 0):\t\t" << XOR(0, 0) << endl
         << "XOR(1, 0):\t\t" << XOR(1, 0) << endl
         << "XOR(5, 0):\t\t" << XOR(5, 0) << endl
         << "XOR(20, 0):\t\t" << XOR(20, 0) << endl
         << "XOR(6, 6):\t\t" << XOR(5, 5) << endl
         << "XOR(5, 6):\t\t" << XOR(5, 6) << endl
         << "XOR(1, 1):\t\t" << XOR(1, 1) << endl;
    return 0;
}