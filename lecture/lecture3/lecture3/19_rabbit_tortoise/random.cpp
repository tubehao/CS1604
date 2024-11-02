//文件：random.cpp
//该文件实现了random库
#include <cstdlib>
#include <ctime>
#include "random.h"

//函数：RandomInit
//该函数取当前系统时间作为随机数发生器的种子
void RandomInit()
{
  srand(time(NULL));
}

// 函数：RandomInteger
// 该函数将0到RAND_MAX的区间的随机数转换成low到high区间
int RandomInteger(int low, int high)
{
 return (low + (high - low + 1) * rand()/(RAND_MAX + 1));
}
