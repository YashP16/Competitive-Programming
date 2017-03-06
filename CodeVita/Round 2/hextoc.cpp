#include <iostream>
using namespace std;
int main()
{
	unsigned char ucCharacter;
	cin >> ucCharacter;
	cout << hex << "0x" << (unsigned int)ucCharacter <<endl;
	int iChNum;
	cin >> hex >> iChNum;
	cout << (unsigned char)iChNum <<endl;
	return 0;
}