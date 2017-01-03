#include<stdio.h>

//c code
int AdjustArray(int s[], int l, int r) //返回调整后基准数的位置
{
	int i = l, j = r;
	int x = s[l]; //s[l]即s[i]就是第一个坑
	while (i < j)
	{
		// 从右向左找小于x的数来填s[i]
		while(i < j && s[j] >= x) 
			j--;  
		if(i < j) 
		{
			s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}

		// 从左向右找大于或等于x的数来填s[j]
		while(i < j && s[i] < x)
			i++;  
		if(i < j) 
		{
			s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = x;

	return i;
}

void quick_sort1(int s[], int l, int r)
{
	if (l < r)
    {
		int i = AdjustArray(s, l, r);//先成挖坑填数法调整s[]
		quick_sort1(s, l, i - 1); // 递归调用 
		quick_sort1(s, i + 1, r);
	}
}
/* python code
def getMidNum(list):
    return (list[0] + list[len(list) - 1] + list[len(list)/2])/3
def qsort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = getMidNum(arr)
        return qsort([x for x in arr[0:] if x < pivot]) + \
               [x for x in arr[0:] if x == pivot] + \
               qsort([x for x in arr[0:] if x > pivot]) 
*/

int main()
{
  int a[]={1,3,2,6,8,2,1,3};
  quick_sort1(a,0,7);
  int k = 0;
  for(;k<7;k++)
    printf("%d ",a[k]);
  return 1;
}
