// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

#define  LEGS_PER_CHICKEN (2)
#define  LEGS_PER_RABBIT  (4)

int headCount = 0;
int footCount = 0;
int chichenCount = 0;
int rabbitCount = 0;

int main()
{
    while(1)
    {
        int footmin = 0;
        int footmax = 0;
        //entre head count
        printf("Please enter the number of heads:");
        scanf_s("%d",&headCount);
        //entre foot count
        printf("Please enter the number of feet:");
        scanf_s("%d", &footCount);

        footmin = LEGS_PER_CHICKEN * headCount;
        footmax = LEGS_PER_RABBIT * headCount;

        if ((footCount >= footmin)
            && (footCount <= footmax)
            && (footCount % 2 == 0) )
        {
            rabbitCount = (footCount - footmin) / 2;
            chichenCount = (footmax - footCount) / 2;
            //output result
            printf("\n successful! \n");
            printf("The number of chickens: %d\n", chichenCount);
            printf("The number of rabbits: %d\n", rabbitCount);
        }
        else
        {
            printf("\n No solution! \n");
        }
    }

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
