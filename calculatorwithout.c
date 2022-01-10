/***********************************************************************************************
 *  System          : Calculator without math function
 *  Program ID      : calculatorwithoutmath.c
 *  Description     : math 함수를 이용하지 않는 계산기 프로그램
 *  Author          : Jiyeoning
 ************************************************************************************************/

 /*--<HEADER FILES>------------------------------------------------------------------------------*/
#include    <stdio.h>
#include    <stdlib.h>


/*--<FUNCTION PROTOTYPE>------------------------------------------------------------------------*/
void    Description(int* pipFuncNum);
int     Calculate(int* pipFuncNum, int* pipCalcNum, double* pdpCalcNum);
int     abs(int pipCalcNum);
double  exp(double pdpCalcNum);
double  sqrt(double pdpCalcNum);
double  fmod(double pdpCalcNum01, double pdpCalcNum02);


/*----------------------------------------------------------------------------------------------
 * Function     : main
 * Description  : math 함수를 이용하지 않는 계산기 프로그램의 main 함수
 *----------------------------------------------------------------------------------------------*/
int main()
{
    int     liInputCheck = 0;
    int     liAnswer = 0;
    int     liFuncNum = 0;
    int     liCalcNum[2];
    double  ldCalcNum[2];

    system("clear");
    while (liAnswer != 2)
    {
        Description(&liFuncNum);

        liInputCheck = Calculate(&liFuncNum, liCalcNum, ldCalcNum);

        if (liInputCheck != 1)
        {
            printf("\n\n1. 다시 입력\n2. 프로그램 종료\n\n입 력 : ");
            scanf("%d", &liAnswer);
            system("clear");
        }
    }

    return 0;

} /* End of main */

/*----------------------------------------------------------------------------------------------
 * Function     : Description
 * Description  : 프로그램명과 기능 번호 출력 함수
 *----------------------------------------------------------------------------------------------*/
void Description(int* pipFuncNum)
{
    printf("\n\n[Calculator with math function]\n\n");
    printf("원하는 기능의 번호를 입력하세요.\n");
    printf("1. 덧셈 addition\n");
    printf("2. 뺄셈 subtraction\n");
    printf("3. 곱셈 multiplication\n");
    printf("4. 나눗셈 division\n");
    printf("5. 절대값 absolute value\n");
    printf("6. 익스포넨셜 exponential\n");
    printf("7. 제곱근 square root\n");
    printf("8. 모듈러 Mod\n");
    printf("\n\n입 력 : ");
    scanf("%d", pipFuncNum);

} /* End of Description */

/*----------------------------------------------------------------------------------------------
 * Function     : Calculate
 * Description  : 선택한 기능에 따라 계산하는 함수
 *----------------------------------------------------------------------------------------------*/
int Calculate(int* pipFuncNum, int* pipCalcNum, double* pdpCalcNum)
{
    void InputNum(char* str)
    {
        printf("\n%s\n", str);
        printf("첫 번째 정수 입력: ");
        scanf("%d", pipCalcNum);
        printf("두 번째 정수 입력: ");
        scanf("%d", pipCalcNum + 1);
    }

    switch (*pipFuncNum)
    {
    case 1:
        system("clear");
        InputNum("[덧 셈]");
        printf("%d + %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), *pipCalcNum + *(pipCalcNum + 1));
        return 0;
    case 2:
        system("clear");
        InputNum("[뺄 셈]");
        printf("%d - %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), *pipCalcNum - *(pipCalcNum + 1));
        return 0;
    case 3:
        system("clear");
        InputNum("[곱 셈]");
        printf("%d X %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), (*pipCalcNum) * (*(pipCalcNum + 1)));
        return 0;
    case 4:
        system("clear");
        InputNum("[나 눗 셈]");
        printf("%d / %d = %g\n", *pipCalcNum, *(pipCalcNum + 1), (double)*pipCalcNum / *(pipCalcNum + 1));
        return 0;
    case 5:
        system("clear");
        printf("\n[절 대 값]\n");
        printf("정수 입력: ");
        scanf("%d", pipCalcNum);
        printf("abs(%d) = %d\n", *pipCalcNum, abs(*pipCalcNum));
        return 0;
    case 6:
        system("clear");
        printf("\n[익 스 포 넨 셜]\n");
        printf("실수 입력: ");
        scanf("%lf", pdpCalcNum);
        printf("exp(%g) = %g\n", *pdpCalcNum, exp(*pdpCalcNum));
        return 0;
    case 7:
        system("clear");
        printf("\n[제 곱 근]\n");
        printf("실수 입력: ");
        scanf("%lf", pdpCalcNum);
        printf("sqrt(%g) = %g\n", *pdpCalcNum, sqrt(*pdpCalcNum));
        return 0;
    case 8:
        system("clear");
        printf("\n[모 듈 러]\n");
        printf("첫 번째 실수 입력: ");
        scanf("%lf", pdpCalcNum);
        printf("두 번째 실수 입력: ");
        scanf("%lf", pdpCalcNum + 1);
        printf("%g Mod %g = %g\n", *pdpCalcNum, *(pdpCalcNum + 1), fmod(*pdpCalcNum, *(pdpCalcNum + 1)));
        return 0;
    default:
        system("clear");
        printf("\n\n유효한 번호를 입력하세요.\n");
        return 1;
    }
} /* End of Calculate */

/*----------------------------------------------------------------------------------------------
 * Function     : abs
 * Description  : 절대값을 구하는 함수
 *----------------------------------------------------------------------------------------------*/
int abs(int pipCalcNum)
{
    if (pipCalcNum < 0)
    {
        pipCalcNum *= -1;
    }

    return pipCalcNum;
} /* End of abs */

/*----------------------------------------------------------------------------------------------
 * Function     : exp
 * Description  : exp값을 구하는 함수
 *----------------------------------------------------------------------------------------------*/
double exp(double pdpCalcNum)
{
    int i, j;
    int liCntNum = 0;
    double ldResultNum = 0;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < i; j++)
        {
            pdpCalcNum *= pdpCalcNum;
        }

        if (liCntNum == 0)
        {
            ldResultNum += 1;
        }
        else
        {
            ldResultNum += pdpCalcNum / (liCntNum + i);
        }

        liCntNum += i;

    }

    return ldResultNum;
} /* End of exp */

/*----------------------------------------------------------------------------------------------
 * Function     : sqrt
 * Description  : 제곱근을 구하는 함수
 *----------------------------------------------------------------------------------------------*/
double sqrt(double pdpCalcNum)
{
    double liValue;
    int i;

    /*--------------------------------------------
    * 입력값의 제곱근 근사값을 liValue 변수에 대입
    *--------------------------------------------*/
    for (i = 0; (i * i) <= pdpCalcNum; i++)
    {
        liValue = (double)i;
    }
    /*--------------------------------------------
    * 제곱근 공식
    *--------------------------------------------*/
    for (i = 0; i < 10; i++)
    {
        liValue = (liValue + (pdpCalcNum / liValue)) / 2;
    }

    return liValue;
} /* End of sqrt */

/*----------------------------------------------------------------------------------------------
 * Function     : fmod
 * Description  : 모듈러연산(나머지)값을 구하는 함수
 *----------------------------------------------------------------------------------------------*/
double fmod(double pdpCalcNum01, double pdpCalcNum02)
{
    double ldResult;
    int liDivResult;

    liDivResult = pdpCalcNum01 / pdpCalcNum02;

    ldResult = pdpCalcNum01 - (pdpCalcNum02 * liDivResult);

    return ldResult;
} /* End of fmod */
