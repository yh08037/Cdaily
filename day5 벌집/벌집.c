#include <stdio.h>

int main(void)
{
    int N, n=2;
    scanf("%d", &N);
    
    if(N==1) 
    {
        printf("1");
    }
    
    else
    {
        while(1)
        {
            if(N>=3*n*n-9*n+8)
            {
            	n += 1;
			}
			else
			{
				break;
			}
        }
        printf("%d", n-1);
    }
    
    return 0;
}
