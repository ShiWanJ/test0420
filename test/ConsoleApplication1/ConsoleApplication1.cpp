// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

#define  HEAD_PER_CHICKEN (1)
#define  HEAD_PER_RABBIT  (1)
#define  FEET_PER_CHICKEN (2)
#define  FEET_PER_RABBIT  (4)
#define  METHOD_GENERAL   (0)
#define  METHOD_MATRIX    (1)
#define  METHOD_NULL      (0xFF)

int headCount = 0;
int footCount = 0;
int chichenCount = 0;
int rabbitCount = 0;
char methodName[2][10] = { {"GENERAL"},{"MATRIX"} };

bool judgueSolution(int js_headCount, int js_footCount)
{
    int footmin = 0;
    int footmax = 0;

    footmin = FEET_PER_CHICKEN * js_headCount;
    footmax = FEET_PER_RABBIT * js_headCount;

    if ((js_headCount>= 0)
        && (js_footCount >= 0)
        && (js_footCount >= footmin)
        && (js_footCount <= footmax)
        && (js_footCount % 2 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void methodGeneral(int mg_headCount,int mg_footCount)
{
    int mg_footmin = 0;
    int mg_footmax = 0;

    mg_footmin = FEET_PER_CHICKEN * mg_headCount;
    mg_footmax = FEET_PER_RABBIT * mg_headCount;
    rabbitCount = (mg_footCount - mg_footmin) / 2;
    chichenCount = (mg_footmax - mg_footCount) / 2;
}

void methodMatrix(int mm_headCount, int mm_footCount)
{
    /*
                    //chicken          rabbit      
    int A[2][2] = { {HEAD_PER_CHICKEN, HEAD_PER_RABBIT} , //head
                    {FEET_PER_CHICKEN, FEET_PER_RABBIT}   //count
                  };
    */
                    //chicken          rabbit      
    int IA[2][2] = { {FEET_PER_RABBIT, -FEET_PER_CHICKEN} , //head
                     {-HEAD_PER_RABBIT, HEAD_PER_CHICKEN}   //count
                   };
             //chicken rabbit
    int b[2] = { 0,      0, };
    int x[2] = { 0,      0, };
    int p = 0;
    int i, j;
    //assign B
    b[0] = mm_headCount;
    b[1] = mm_footCount;
    //obtain X
    for (i = 0; i<= 1; i++)
    {
        for (j = 0; j <= 1; j++)
        {
            x[i] = x[i] + IA[j][i] * b[j];
        }
        p = (FEET_PER_RABBIT * HEAD_PER_CHICKEN - FEET_PER_CHICKEN * HEAD_PER_RABBIT);
        x[i] = x[i] / p;
    }
    chichenCount= x[0];
    rabbitCount   = x[1];
}
int main()
{
    while(1)
    {
        int methodId = METHOD_NULL;

        //entre methodId
        while (METHOD_NULL == methodId)
        { 
            printf("Please select method，general 0 ，matrix 1:");
            scanf_s("%d", &methodId);

            if (methodId != METHOD_GENERAL
                && methodId != METHOD_MATRIX)
            {
                methodId = METHOD_NULL;
            }
            else
            {
                printf("\n %s \n", methodName[methodId]);
            }
        }
    
        //entre heads and feet count
        printf("Please enter the number of heads:");
        scanf_s("%d",&headCount);
        printf("Please enter the number of feet:");
        scanf_s("%d", &footCount);

        if (judgueSolution(headCount, footCount))
        {
            switch (methodId)
            {
                case METHOD_GENERAL:
                    methodGeneral(headCount, footCount);
                    break;
                case METHOD_MATRIX:
                    methodMatrix(headCount, footCount);
                    break;
                default:
                    break;
            }
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
