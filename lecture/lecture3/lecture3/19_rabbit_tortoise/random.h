#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

//函数：RandomInit
//用法：RandomInit()
//作用：此函数初始化随机数种子
void RandomInit();

//函数：RandomInteger
//用法：n = RandomInteger(low, high)
//作用：此函数返回一个low到high之间的随机数，包括low和high
int RandomInteger(int low, int high);

#endif // RANDOM_H_INCLUDED
