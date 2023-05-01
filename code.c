#include <stdio.h>
#include <string.h>

int main()
{  
  	float f;		//频率
	float x;		//振子长度
	char z[5] = {0};
	
  	printf("************************************\n");
	printf("*                                  *\n");
	printf("*        欢迎使用振子计算器        *\n");
	printf("*                                  *\n");
	printf("************************************\n\n");
	printf("本程序用于计算使用1:1巴伦的偶极天线振子长度\n");
	restart:
  	printf("请输入需要谐振的频率(单位Mhz):");
	scanf("%f", &f);

  while (f<=0)  //判断输入是否标准(数字范围)
  {
    input:
    printf("请重新输入\n");
    goto restart;
  }
  
  printf("您输入的频率是%fMhz\n", f);
  printf("是否开始计算(Y/N)？");
  scanf("%s", &z);
  run:
  
  while (strcmp(z, "y") != 0 && strcmp(z, "Y") != 0 && strcmp(z, "n") != 0 && strcmp(z, "N") != 0 ) //判断输入是否标准(Y/N)
  {
    printf("请输入Y或N");
    scanf("%s", &z);
    goto run;
  }
  if (strcmp(z, "y") == 0 || strcmp(z, "Y") == 0 )  //判断开始计算
  {
    calculate:
    printf("正在计算\n");
	  x=300/f;
	  x=x/2;
    printf("振子总长度为: %f米\n", x);
	  printf("计算数据仅供参考！！！");
  } 
  else  //判断取消计算
  {
    printf("是否要重新输入频率？(Y/N)");
    scanf("%s", &z);

    retry:
    while (strcmp(z, "y") != 0 && strcmp(z, "Y") != 0 && strcmp(z, "n") != 0 && strcmp(z, "N") != 0 )
    {
      printf("请输入Y或N");
      scanf("%s", &z);
      goto retry;
    }

    if (strcmp(z, "y") == 0 || strcmp(z, "Y") == 0 )
    {
      goto restart;
    }
      
    else
    {
      goto calculate;
    }
  }
}
