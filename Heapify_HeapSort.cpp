#include<iostream>
using namespace std;
class Heap{
	public:
		int arr[100];
		int size;
		Heap()
		{
			arr[0]=-1;
			size=0;
		}
		void insert(int val)
		{
			size++;
			int index=size;
			arr[index]=val;
			while(index>1)
			{
				int par=index/2;
				if(arr[par]<arr[index])
				{
					swap(arr[par],arr[index]);
				}
				else
				{
					return;
				}
			}
		}
		void print()
		{
			for(int i=1;i<=size;i++)
			{
				cout<<"->"<<arr[i];
			}
		}
		void deleteRoot()
		{
			if(size==0)
			{
				cout<<"Heap is Empty";
				return;
			}
			arr[1]=arr[size];
			size--;
			int i=1;
			while(i<size)
			{
				int rightInd=(2*i)+1;
				int leftInd=2*i;
				if(rightInd<size&&arr[i]<arr[rightInd])
				{
					swap(arr[i],arr[rightInd]);
					i=leftInd;
				}
				else if(leftInd<size&&arr[i]<arr[leftInd])
				{
					swap(arr[i],arr[leftInd]);
				}
				else
				{
					return;
				}
			}
		}
		void heapify(int arr[],int n,int i)
		{
			int largest=i;
			int left=2*i;
			int right=(2*i)+1;
			if(left<n&&arr[largest]<arr[left])
			{
				largest=left;
			}
			if(right<n&&arr[largest]<arr[right])
			{
				largest =right;
			}
			if(largest!=i)
			{
				swap(arr[largest],arr[i]);
				{
					heapify(arr,n,largest);
				}
			}
			
		}
		void makeHeap(int arr[],int size)
		{
			for(int i=size/2;i>0;i--)
			{
				heapify(arr,size,i);
			}
		}
		void heapSort(int arr[],int n)
		{
			int size=n;
			while(size>1)
			{
				swap(arr[size],arr[1]);
				heapify(arr,size,1);
			}
		}
};
int main()
{
	Heap h;
	h.insert( 50);
	h.insert( 55);
	h.insert( 53);
	h.insert( 52);
	h.insert( 51);
	h.print();
	int arr[6]={-1,54,53,55,52,50};
	h.makeHeap(arr,6);
	cout<<endl;
	for(int i=1;i<6;i++)
	{
		cout<<"->"<<arr[i];
	}
}
