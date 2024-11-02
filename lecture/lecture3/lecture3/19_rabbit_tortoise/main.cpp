#include <iostream>
#include "random.h"
#include "print.h"
using namespace std;

int move_tortoise()
{
 //产生0到9之间的随机数
 int probability = RandomInteger(0,9);
 if (probability < 5) return 3; //快走
 else if (probability < 7) return -6; //后滑
 else return 1; //慢走
}

int move_rabbit()
{
 int probability = RandomInteger(0,9);
 if (probability < 2) return 0; //睡觉
 else if (probability < 4) return -9; //大后滑
 else if (probability < 5) return 14; //快走
 else if (probability < 8) return 3; //小步跳
 else return -2; //慢后滑
}

#define RACE_END 70

int main()
{
  int rabbit = 0, tortoise = 0, timer = 0;

  RandomInit(); //随机数初始化
  cout << "timer  tortoise  rabbit\n"; //输出表头
  while (rabbit < RACE_END && tortoise < RACE_END)
  {   tortoise += move_tortoise(); //乌龟移动
      rabbit += move_rabbit(); //兔子移动
      print_position(timer, tortoise, rabbit);
      ++timer;
   }
   if (rabbit > tortoise) cout << "\n rabbit wins!\n";
       else cout << "\n tortoise wins!\n";
   return 0;
}
