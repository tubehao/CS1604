//�ļ���random.cpp
//���ļ�ʵ����random��
#include <cstdlib>
#include <ctime>
#include "random.h"

//������RandomInit
//�ú���ȡ��ǰϵͳʱ����Ϊ�����������������
void RandomInit()
{
  srand(time(NULL));
}

// ������RandomInteger
// �ú�����0��RAND_MAX������������ת����low��high����
int RandomInteger(int low, int high)
{
 return (low + (high - low + 1) * rand()/(RAND_MAX + 1));
}
