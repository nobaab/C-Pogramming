#include <stdio.h>
int main()
{
    int i, j,temp=0,a[100],n;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
        scanf("%d",&a[i]);
    for(i = 0;i < n;i++)
    {
        for(j = i-1;j >= 0;j--)
        {
            if(a[i] == a[j])
            {
                temp = 1;
            }
        }
        if(temp == 0)
        {
            printf("%d",a[i]);
            
        }
        temp = 0;
    }
    return 0;
}
