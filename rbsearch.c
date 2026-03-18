#include<stdio.h>
int rbsearch(int a[],int l,int h,int key){
    int mid;
    if (l==h)
    {
        if (a[l]==key)
        {
            return 1;
        }
        else
        {
            return 0;
        } 
    }
    else
    {
        mid=(l+h)/2;
        if (key==a[mid])
        {
            return mid;
        }
        else if(key<a[mid]){
            return rbsearch(a,l,mid-1,key);
        }
        else{
            return rbsearch(a,mid+1,h,key);
        }   
    }
    return 0;
}

void main()
{
int l=1,i,h,key,hold;
printf("enter the size of an arrays:\n");
scanf("%d",&h);
int a[h];
printf("enter the %d number element:\n",h);
for ( i = 0; i < h; i++)
{
    scanf("%d",&a[i]);
}
printf("enter the searching element:");
scanf("%d",&key);
hold=rbsearch(a,l,h,key);
printf("\nyour final result index is in  :%d",hold);
}
