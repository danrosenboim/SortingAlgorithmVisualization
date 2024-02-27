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
	for(int i = 0; i < SIZE; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(SLOW));
		for(int k = i; k < SIZE; k++)
		{
			
		}
	}
}

int main()
{
	Visualizer test;
	
	// get input from user
	int selection;
	std::cin >> selection;
	
	test.sort(bubbleSort);
	test.show();
	
	return 0;
}
