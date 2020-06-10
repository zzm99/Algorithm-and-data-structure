// 1、首先封装一个队列类Queue用链表形式实现，包括队列的插入元素、删除元素以及判断是否为空；这样就实现了一个队列

// 2、接着实现基数排序的算法流程；

// 3、建立数组队列用来保存基数为0~9的元素值（每个数从右向左取每一位）；

// 4、计算每个元素个位上是值，然后将该元素值放入个位数对应的队列中；

// 5、依次计算十位、百位...........；等并放入相应的队列中；

// 6、最后从队列queue（0）开始，依次把每个队列中的元素存在原始数组中，得到最后的排序；

#include <iostream>
#include <list>
using namespace std;

template <class T>
class Queue{
public:
    bool isEmpty() const{
        return lst.empty();
    }
    T dequeue(){
        T el = lst.front();
        lst.pop_front();
        return el;
    }
    void enqueue(const T& el){
        lst.push_back(el);
    }
private:
    list<T> lst;
};

int getMaxbit(int arr[], int n){
	int mx = arr[0];
	for(int i=1; i<n; i++)
		if(arr[i] > mx)
			mx = arr[i];
    int ret = 0;
    while(mx){
        mx /= 10;
        ret++;
    }
	return ret;
}

int radixsort(int data[], int n){
    int radix = 10;
    int digits = getMaxbit(data, n);
    int i, j, k, factor;
    Queue<int> queue1[radix];
    for(i = 0, factor = 1; i < digits; factor *= radix, i++){
        for(j = 0; j < n; j++)
            queue1[(data[j]/factor)%radix].enqueue(data[j]);
        for(j = k = 0; j < radix; j++)
            while(!queue1[j].isEmpty())
                data[k++] = queue1[j].dequeue();
    }
    return *data;

}

int main(){
    int data[] = {10, 1234, 9, 7234, 67, 9181, 733, 197, 7, 3, 0};
    int n = sizeof(data)/sizeof(data[0]);
    radixsort(data, n);
    for(int m = 0; m < n; m++)
        cout << data[m] << " ";
    return 0;
}
