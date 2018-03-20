#include <iostream>
#include <memory>

using namespace std;

void QuickSort(unique_ptr<int[]>& arr, int low, int high) 
{

	if (low < high)
	{
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; ++j)
		{
			if (arr[j] <= pivot)
			{
				++i;
				swap(arr[i], arr[j]);
			}
		}

		swap(arr[i + 1], arr[high]);

		i = i + 1;

		QuickSort(arr, low, i - 1);
		QuickSort(arr, i + 1, high);


	}
}

int main()
{
	int n;
	cin >> n;

	unique_ptr<int[]> arr(new int[n]);

	for (int i = 0; i < n; ++i)
	{
		int elem;
		cin >> elem;
		arr[i] = elem;
	}

	QuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}

/*
9
1 5 7 9 6 2 4 3 8
*/