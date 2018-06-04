#include <stdio.h>
int main()
{
    int a[50],i,max,n,max2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    max=max2=a[0];
    
    for (i=0; i<a[i]; i++) {
        
    
    if (a[i]>max) {
        max2=max;
        max=a[i];
    }
    else if (max2 < a[i] && a[i]!=max)
        max2 = a[i];
}
    printf("Second Largest Number is : %d\n",max2);
}

