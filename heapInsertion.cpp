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
};
int main()
{
	Heap h;
	h.insert( 50);
	h.insert( 55);
	h.insert( 53);
	h.insert( 52);
	h.insert( 52);
	h.print();
}
