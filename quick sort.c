#include<stdio.h>
#include<stdlib.h>

int partitioning (int*numbers,int low,int high)
{
    int pivot, s_ind, x, swapper ,pivot_ind;
    pivot = numbers[high];
    s_ind = low;

    for(x=low;x<high;x++)
    {
        if(numbers[x]<=pivot)
        {
            swapper = numbers[s_ind];
            numbers[s_ind]=numbers[x];
            numbers[x] =swapper;
            s_ind++;
        }
    }
    swapper = numbers[s_ind];
    numbers[s_ind]= numbers[high];
    numbers[high]=swapper;
    pivot_ind =s_ind+1;
    return s_ind;
}
void QuickSort(int* numbers,int start, int end)
{
    if (start<end)
    {
    int pivot_ind;
    pivot_ind = partitioning(numbers,start,end);
    QuickSort(numbers,pivot_ind+1,end);
    QuickSort(numbers,start,pivot_ind-1);
    }
}
int main()
{
    int t,y, semi;
    float median ,mean;
    int mode[512],pop,mwin;
    int sum = 0, count_mode;
    int inp[1024];
    scanf("%d",&t);
    for(y=0;y<t;y++)
    {
        scanf("%d",&inp[y]);
        sum = sum + inp[y];
    }
    mean = sum/t;
    QuickSort(inp,0,t-1);

    if (t%2 ==1)
    {
        median = inp[(t-1)/2];
    } else
    {
        semi = inp[t/2]+inp[(t/2)-1];
        median = semi/2;
    }
    pop = 0;
    mwin=0;
    count_mode = 0;
    for (y=1;y<t-1;y++)
    {
      if(inp[y]==inp[y-1])
      {
          pop++;
          if (pop > mwin)
          {
             mwin = pop;
             count_mode = 0;
             mode[count_mode] = inp[y];
          }
          if (pop==mwin)
          {
              count_mode++;
              mode[count_mode] = inp[y];
          }
      } else {pop=0;}
    }
    printf("Mean: %.2f\n",mean);
    printf("Median: %.2f\n",median);
    if(mwin ==0)
    {
        printf("There is no mode\n");
    } else
    {
        printf("Mode: ");
        for(y=0;y<count_mode;y++)
        {
            printf("%d ",mode[count_mode]);
        }
    }


    return 0;
}
