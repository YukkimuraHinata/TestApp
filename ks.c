#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void signJudge(int * judge, char * computeSign)
{
    int temp;
    temp = *judge;
    if(temp == 0){
        *computeSign = '+';
    }
    if(temp == 1){
        *computeSign = '-';
    }
    if(temp == 2){
        *computeSign = 'x';
    }
    if(temp == 3){
        *computeSign = '/';
    }
}

int main()
{
    int i,n,x,y,z,result;  //z = sign, x,y = number  
    char ch;
    printf_s("输入想要生成的题目数量\n");
    scanf_s("%d",&n);
    int question[n][3];
    char computeSign[n + 1];
    srand((unsigned)time(NULL));
    for(i = 0;i < n;i++)
    {
        z = rand()%4;  // 0 = add, 1 = sub, 2 = multi, 3 = div
        if(z == 2 || z == 3) //multi and division
        {
            if(z == 2){
                x = rand() % 10;
                y = rand() % 10;
                if(x|y == 0){
                    i--;
                }
                else{
                question[i][0] = x;
                question[i][1] = y;
                question[i][2] = x*y;
                signJudge(&z,&computeSign[i]);
                printf_s("%d %c %d\n",question[i][0],computeSign[i],question[i][1]);
                }
            }
            else{
                if(x|y == 0){
                    i--;
                }
                else{
                x = rand() % 10;
                y = rand() % 10;
                question[i][0] = x*y;
                question[i][1] = x;
                question[i][2] = y;
                signJudge(&z,&computeSign[i]);
                printf_s("%d %c %d\n",question[i][0],computeSign[i],question[i][1]);
                }
            }
        }
        else{
            x = rand() % 100;  //add and sub
            y = rand() % 100;
            if(z == 0){
                question[i][2] = x+y;
            }
            else{
                question[i][2] = x-y;
            }
            question[i][0] = x;
            question[i][1] = y;
            signJudge(&z,&computeSign[i]);
            printf_s("%d %c %d\n",question[i][0],computeSign[i],question[i][1]);
        }
    }
    fflush(stdin);
    printf_s("Press Enter to check the anwser");
    ch = getchar();
    ch = getchar();
    for(i = 0;i < n;i++)
        {
            printf_s("%d %c %d = %d\n",question[i][0],computeSign[i],question[i][1],question[i][2]);
        }
        return 0; 
}