/***********************************************************************************************
 *  System          : Calculator without math function
 *  Program ID      : calculatorwithoutmath.c
 *  Description     : math �Լ��� �̿����� �ʴ� ���� ���α׷�
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
 * Description  : math �Լ��� �̿����� �ʴ� ���� ���α׷��� main �Լ�
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
            printf("\n\n1. �ٽ� �Է�\n2. ���α׷� ����\n\n�� �� : ");
            scanf("%d", &liAnswer);
            system("clear");
        }
    }

    return 0;

} /* End of main */

/*----------------------------------------------------------------------------------------------
 * Function     : Description
 * Description  : ���α׷���� ��� ��ȣ ��� �Լ�
 *----------------------------------------------------------------------------------------------*/
void Description(int* pipFuncNum)
{
    printf("\n\n[Calculator with math function]\n\n");
    printf("���ϴ� ����� ��ȣ�� �Է��ϼ���.\n");
    printf("1. ���� addition\n");
    printf("2. ���� subtraction\n");
    printf("3. ���� multiplication\n");
    printf("4. ������ division\n");
    printf("5. ���밪 absolute value\n");
    printf("6. �ͽ����ټ� exponential\n");
    printf("7. ������ square root\n");
    printf("8. ��ⷯ Mod\n");
    printf("\n\n�� �� : ");
    scanf("%d", pipFuncNum);

} /* End of Description */

/*----------------------------------------------------------------------------------------------
 * Function     : Calculate
 * Description  : ������ ��ɿ� ���� ����ϴ� �Լ�
 *----------------------------------------------------------------------------------------------*/
int Calculate(int* pipFuncNum, int* pipCalcNum, double* pdpCalcNum)
{
    void InputNum(char* str)
    {
        printf("\n%s\n", str);
        printf("ù ��° ���� �Է�: ");
        scanf("%d", pipCalcNum);
        printf("�� ��° ���� �Է�: ");
        scanf("%d", pipCalcNum + 1);
    }

    switch (*pipFuncNum)
    {
    case 1:
        system("clear");
        InputNum("[�� ��]");
        printf("%d + %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), *pipCalcNum + *(pipCalcNum + 1));
        return 0;
    case 2:
        system("clear");
        InputNum("[�� ��]");
        printf("%d - %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), *pipCalcNum - *(pipCalcNum + 1));
        return 0;
    case 3:
        system("clear");
        InputNum("[�� ��]");
        printf("%d X %d = %d\n", *pipCalcNum, *(pipCalcNum + 1), (*pipCalcNum) * (*(pipCalcNum + 1)));
        return 0;
    case 4:
        system("clear");
        InputNum("[�� �� ��]");
        printf("%d / %d = %g\n", *pipCalcNum, *(pipCalcNum + 1), (double)*pipCalcNum / *(pipCalcNum + 1));
        return 0;
    case 5:
        system("clear");
        printf("\n[�� �� ��]\n");
        printf("���� �Է�: ");
        scanf("%d", pipCalcNum);
        printf("abs(%d) = %d\n", *pipCalcNum, abs(*pipCalcNum));
        return 0;
    case 6:
        system("clear");
        printf("\n[�� �� �� �� ��]\n");
        printf("�Ǽ� �Է�: ");
        scanf("%lf", pdpCalcNum);
        printf("exp(%g) = %g\n", *pdpCalcNum, exp(*pdpCalcNum));
        return 0;
    case 7:
        system("clear");
        printf("\n[�� �� ��]\n");
        printf("�Ǽ� �Է�: ");
        scanf("%lf", pdpCalcNum);
        printf("sqrt(%g) = %g\n", *pdpCalcNum, sqrt(*pdpCalcNum));
        return 0;
    case 8:
        system("clear");
        printf("\n[�� �� ��]\n");
        printf("ù ��° �Ǽ� �Է�: ");
        scanf("%lf", pdpCalcNum);
        printf("�� ��° �Ǽ� �Է�: ");
        scanf("%lf", pdpCalcNum + 1);
        printf("%g Mod %g = %g\n", *pdpCalcNum, *(pdpCalcNum + 1), fmod(*pdpCalcNum, *(pdpCalcNum + 1)));
        return 0;
    default:
        system("clear");
        printf("\n\n��ȿ�� ��ȣ�� �Է��ϼ���.\n");
        return 1;
    }
} /* End of Calculate */

/*----------------------------------------------------------------------------------------------
 * Function     : abs
 * Description  : ���밪�� ���ϴ� �Լ�
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
 * Description  : exp���� ���ϴ� �Լ�
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
 * Description  : �������� ���ϴ� �Լ�
 *----------------------------------------------------------------------------------------------*/
double sqrt(double pdpCalcNum)
{
    double liValue;
    int i;

    /*--------------------------------------------
    * �Է°��� ������ �ٻ簪�� liValue ������ ����
    *--------------------------------------------*/
    for (i = 0; (i * i) <= pdpCalcNum; i++)
    {
        liValue = (double)i;
    }
    /*--------------------------------------------
    * ������ ����
    *--------------------------------------------*/
    for (i = 0; i < 10; i++)
    {
        liValue = (liValue + (pdpCalcNum / liValue)) / 2;
    }

    return liValue;
} /* End of sqrt */

/*----------------------------------------------------------------------------------------------
 * Function     : fmod
 * Description  : ��ⷯ����(������)���� ���ϴ� �Լ�
 *----------------------------------------------------------------------------------------------*/
double fmod(double pdpCalcNum01, double pdpCalcNum02)
{
    double ldResult;
    int liDivResult;

    liDivResult = pdpCalcNum01 / pdpCalcNum02;

    ldResult = pdpCalcNum01 - (pdpCalcNum02 * liDivResult);

    return ldResult;
} /* End of fmod */
