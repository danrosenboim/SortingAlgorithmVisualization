#include "Visualizer.h"

void bubbleSort(std::vector<Item>& arr)
{
	for(int i = 0; i < SIZE; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLOW));
		for(int k = 0; k < SIZE - 1; k++)
		{
			if(arr[k].value > arr[k + 1].value)
			{
				Item temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}

void selectionSort(std::vector<Item>& arr)
{
	int k;
	int minIndex;
	for(int i = 0; i < SIZE; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLOW));
		minIndex = SIZE - 1;
		for(k = i; k < SIZE; k++)
		{
			if(arr[minIndex].value > arr[k].value)
			{
				minIndex = k;
			}
		}
		Item temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}



int main()
{
	Visualizer test;
	
	// get input from user
	int selection;
	std::cin >> selection;
	
	test.sort(selectionSort);
	test.show();
	
	return 0;
}
