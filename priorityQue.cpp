#include <iostream>
using namespace std;

class Node
{
public:
    int floors;
    int id;
    Node()
	{
        floors = 0;
        id = 0;
    }
};

class Heap
{
public:
    Node* arr;
    int size;
    int cap;
    Heap(int c)
	{
        arr = new Node[c];
        cap = c;
        size = 0;
    }

    void addBuilding(int f, int i)
	{
        size++;
        int index = size;
        arr[index].floors = f;
        arr[index].id = i;
        while (index > 1)
		{
            int par = (index / 2);
            if (arr[par].floors < arr[index].floors)
			{
                swap(arr[par], arr[index]);
                index = par;
            }
			else
			{
                return;
            }
        }
    }

    void print()
	{
        if (size == 0)
		{
            cout << "\nRecord is Empty";
            return;
        }
        for (int i = 1; i <= size; i++)
		{
            cout << "-> id:" << arr[i].id;
            cout << " Floors:" << arr[i].floors;
        }
    }

    void constructBuilding()
	{
        if (size == 0)
		{
            cout << "Record is Empty";
            return;
        }
        cout<<"\nBuilding with id:"<<arr[1].id<<" has been constructed";
        arr[1] = arr[size];
        
        size--;
        int i = 1;
        while (2 * i <= size)
		{
            int leftInd = 2 * i;
            int rightInd = 2 * i + 1;
            int maxIndex = i;
            if (leftInd <= size && arr[leftInd].floors > arr[i].floors)
			{
                maxIndex = leftInd;
            }
            if (rightInd <= size && arr[rightInd].floors > arr[maxIndex].floors)
			{
                maxIndex = rightInd;
            }
            if (maxIndex == i)
			{
                break;
            }
            swap(arr[i], arr[maxIndex]);
            i = maxIndex;
        }
    }

    int getBuilding()
	{
        if (size == 0)
		{
            cout << "\nNo building available";
        }
		else
		{
            return arr[1].id;
        }
        return -1;
    }
};

int main()
{
    Heap h(7);
    int choice;
    int id;
    int floors;
    do {
        cout << "\nEnter:\n1. Add building\n2. Construct Building\n3. Get priority building\n4. Print Record\n0. Exit Program:";
        cin >> choice;
        if (choice == 1)
		{
            cout << "\nEnter building id:";
            cin >> id;
            cout << "\nEnter building floors:";
            cin >> floors;
            h.addBuilding(floors, id);
        }
		else if (choice == 2)
		{
            h.constructBuilding();
        }
		else if (choice == 3)
		{
            int getB = h.getBuilding();
            if (getB == -1)
			{
                cout << "\nEmpty Record";
            } else
			{
                cout << "\nHighest priority building's id: " << getB;
            }
        }
		else if (choice == 4)
		{
            h.print();
        }
		else if (choice == 0)
		{
            cout << "\nProgram Terminating";
        }
		else
		{
            cout << "\nInvalid input";
        }
    }
	while (choice != 0);

    return 0;
}
