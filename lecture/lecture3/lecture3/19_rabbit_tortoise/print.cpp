// �ļ�����print.cpp

#include <iostream>
using namespace std;

void print_position(int timer, int t, int h)
{
 if (timer % 6 == 0) cout << endl; //ÿ��6�ο�һ��
     cout << timer << '\t' << t << '\t' << h << '\n';
}
