#include <iostream>
#include "random.h"
#include "print.h"
using namespace std;

int move_tortoise()
{
 //����0��9֮��������
 int probability = RandomInteger(0,9);
 if (probability < 5) return 3; //����
 else if (probability < 7) return -6; //��
 else return 1; //����
}

int move_rabbit()
{
 int probability = RandomInteger(0,9);
 if (probability < 2) return 0; //˯��
 else if (probability < 4) return -9; //���
 else if (probability < 5) return 14; //����
 else if (probability < 8) return 3; //С����
 else return -2; //����
}

#define RACE_END 70

int main()
{
  int rabbit = 0, tortoise = 0, timer = 0;

  RandomInit(); //�������ʼ��
  cout << "timer  tortoise  rabbit\n"; //�����ͷ
  while (rabbit < RACE_END && tortoise < RACE_END)
  {   tortoise += move_tortoise(); //�ڹ��ƶ�
      rabbit += move_rabbit(); //�����ƶ�
      print_position(timer, tortoise, rabbit);
      ++timer;
   }
   if (rabbit > tortoise) cout << "\n rabbit wins!\n";
       else cout << "\n tortoise wins!\n";
   return 0;
}
