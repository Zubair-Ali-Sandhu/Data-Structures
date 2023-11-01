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
				if(arr[par]>arr[index])
				{
					swap(arr[par],arr[index]);

				}
				else
				{
					return;
				}
			}
		}
		int getMini()
		{
			if(size!=0)
			{
				return arr[1];
			}
			return -1;
		}
		void print()
		{
			cout<<"\nmin heap:";
			for(int i=1;i<=size;i++)
			{
				cout<<"->"<<arr[i];
			}
		}
	void extractMin()
{
    if (size == 0)
    {
        cout << "Heap is Empty";
        return;
    }
    cout << "\nNode with data: " << arr[1] << " removed";
    arr[1] = arr[size];
    size--;
    int i = 1;
    while (2 * i <= size)
    {
        int leftInd = 2 * i;
        int rightInd = 2 * i + 1;
        int minIndex = i;

        if (leftInd <= size && arr[leftInd] < arr[i])
        {
            minIndex = leftInd;
        }
        if (rightInd <= size && arr[rightInd] < arr[minIndex])
        {
            minIndex = rightInd;
        }

        if (minIndex == i)
        {
            break;
        }

        swap(arr[i], arr[minIndex]);
        i = minIndex;
    }
}

		
		
};
int main()
{
	Heap h;
	h.insert( 44);
	h.insert( 2);
	h.insert( 23);
	h.insert( 87);
	h.insert( 12);
	h.print();
	h.extractMin();
	h.print();
	int min=h.getMini();
	cout<<min<<" returned";
}
