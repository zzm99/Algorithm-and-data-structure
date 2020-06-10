// edition one
//C++'s array range should be [low, up], the same as [low, up+1)
int partition(vector<int> &vi, int low, int up)
{
	int pivot = vi[up];
	int i = low-1;
	for (int j = low; j < up; j++)
	{
		if(vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i+1], vi[up]);
	return i+1;
}

//C++'s array range should be [low, up], the same as [low, up+1)
void quickSort(vector<int> &vi, int low, int up)
{
	if(low < up)
	{
		int mid = partition(vi, low, up);
		//Watch out! The mid position is on the place, so we don't need to consider it again.
		//That's why below is mid-1, not mid! Otherwise it will occur overflow error!!!
		quickSort(vi, low, mid-1);
		quickSort(vi, mid+1, up);
	}
}

// edition two : better
int partition(vector<int> &vi, int low, int up)
{
	int pivot = vi[up];
	int pivot_idx = up;
	while(true){
		while(vi[low] < pivot)
			++low;
		while(low < up && vi[up] >= pivot)
			--up;
		if(low >= up)
			break;
		swap(vi[low], vi[up]);
	}
	swap(vi[low], vi[pivot_idx]);
	return low;
}

void quickSort(vector<int> &vi, int low, int up)
{
	if(low < up)
	{
		int mid = partition(vi, low, up);
		quickSort(vi, low, mid-1);
		quickSort(vi, mid+1, up);
	}
}


/////////////////////////////////////////////////////////////////
// 用这个
#include<iostream>
using namespace std;
int n,a[1000001];

void qsort(int l,int r)//应用二分思想
{
    int mid=a[(l+r)/2];//中间数
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;//查找左半部分比中间数大的数
        while(a[j]>mid) j--;//查找右半部分比中间数小的数
        if(i<=j)//如果有一组不满足排序条件（左小右大）的数
        {
            swap(a[i],a[j]);//交换
            i++;
            j--;
        }
    }while(i<=j);//这里注意要有=
    if(l<j) qsort(l,j);//递归搜索左半部分
    if(i<r) qsort(i,r);//递归搜索右半部分
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    qsort(1,n);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}