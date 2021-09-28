//顺序查找，a维数组，n为要查找的数组中的元素个数，key为要查找的关键字
int Sequential_Search(int* a, int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key) return i;
    }
    return 0;
}

//有哨兵的顺序查找


//有序查找
//二分查找
int binary_Search(int* a, int n, int key)
{
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<a[mid]) high=mid-1;
        else if(key>a[mid]) low=mid+1;
        else return mid;
    }
    return 0;
}

//插值查找
int Interpolation_Search(int* a, int n, int key)
{
    int low,high,mid;
    low=1;
    high=n;
    while(low<=high)
    {
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);//插值
        if(key<a[mid])
            high=mid-1;
        else if(key>a[mid])
            low=mid+1;
        else
            return mid;
    }
    return 0;
}

//斐波那契查找

