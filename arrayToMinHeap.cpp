#include<iostream>
using namespace std;
	void heapify(int arr[],int n,int i)
		{
			int largest=i;
			int left=2*i;
			int right=(2*i)+1;
			if(left<n&&arr[largest]>arr[left])
			{
				largest=left;
			}
			if(right<n&&arr[largest]>arr[right])
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
		void print(int arr[],int s)
		{
			cout<<endl;
			for(int i=1;i<s;i++)
			{
				cout<<"->"<<arr[i];
			}
		}
		int main()
		{
			int arr[8]={0,4,2,6,1,3,5,7};
			cout<<"\nCurrent unsorted array:";
			print(arr,8);
			makeHeap(arr,8);
			cout<<"\nMin heap array:";
			print(arr,8);
			
		}
