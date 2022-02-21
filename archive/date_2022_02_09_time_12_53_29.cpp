#include <bits/stdc++.h>

#include "templates.h"

using namespace std;

void bubble_sort(vector<int>& arr) {
	/*
		time complexity - O(n^2)
		space complexity - O(1)
	*/

	int n = (int)arr.size();
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

void selection_sort(vector<int>& arr) {
	/*
		time complexity - O(n^2)
		space complexity - O(1)
	*/
	int n = (int)arr.size();
	int min_idx;

	for(int i = 0; i <= n - 2; i++) {
		min_idx = i;
		for(int j = i + 1; j <= n - 1; j++) {
			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		swap(arr[i], arr[min_idx]);
	}
}

void insertion_sort(vector<int>& arr) {
	/*
		time complexity - O(n^2)
		space complexity - O(1)
	*/
	int n = (int)arr.size();
	for(int i = 1; i <= n - 1; i++) {
		int j = i;
		while(arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void counting_sort(vector<int>& arr, int high) {
	/*
		time complexity - O(n + k)
		space complexity - O(n + k)
	*/
	int n			= (int)arr.size();
	int out[n]		= {0};
	int count[high] = {0};

	for(int i : arr) {
		count[i]++;
	}

	for(int i = 1; i < high; i++) {
		count[i] += count[i - 1];
	}

	for(int i : arr) {
		if(i != 0) {
			out[count[i] - 1] = i;
			count[i]--;
		}
	}

	for(int i = 0; i < n; i++) {
		arr[i] = out[i];
	}
}

namespace merge_sort {
	/*
		time complexity - O(nlog(n))
		space complexity - O(n)
	*/
	void merge(vector<int>& arr, int low, int mid, int high) {
		int l = low;
		int r = mid + 1;
		int n = high - low + 1;
		int tmp[n];

		int i = 0;
		while(l <= mid and r <= high) {
			if(arr[l] < arr[r]) {
				tmp[i] = arr[l];
				l++;
			} else {
				tmp[i] = arr[r];
				r++;
			}
			i++;
		}

		while(l <= mid) {
			tmp[i] = arr[l];
			l++;
			i++;
		}

		while(r <= high) {
			tmp[i] = arr[r];
			r++;
			i++;
		}

		for(i = low; i <= high; i++) {
			arr[i] = tmp[i - low];
		}
	}

	void sort(vector<int>& arr, int low, int high) {
		if(low >= high) return;
		int mid = low + (high - low) / 2;
		sort(arr, low, mid);
		sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}  // namespace merge_sort

namespace quick_sort {
	/*
		time complexity - O(n^2)
		space complexity - O(1) or O(n)*
	*/
	int partition(vector<int>& arr, int low, int high) {
		int i	  = low;
		int pivot = arr[high];

		for(int j = low; j <= high - 1; j++) {
			if(arr[j] < pivot) {
				swap(arr[j], arr[i]);
				i++;
			}
		}
		swap(arr[i], arr[high]);
		return i;
	}
	void sort(vector<int>& arr, int low, int high) {
		if(low < high) {
			int pi = partition(arr, low, high);
			sort(arr, low, pi - 1);
			sort(arr, pi + 1, high);
		}
	}
}  // namespace quick_sort

namespace heap_sort {
	/*
		time complexity - O(nlog(n))
		space complexity - O(1) or O(n)*
	*/
	void heapify(vector<int>& arr, int n, int i) {
		int left  = 2 * i + 1;
		int right = 2 * i + 2;
		int maxi  = i;

		if(left < n and arr[maxi] < arr[left]) {
			maxi = left;
		}

		if(right < n and arr[maxi] < arr[right]) {
			maxi = right;
		}

		if(maxi != i) {
			swap(arr[maxi], arr[i]);
			heapify(arr, n, maxi);
		}
	}

	void sort(vector<int>& arr, int n) {
		for(int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}

		for(int i = n - 1; i > 0; i--) {
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}
}  // namespace heap_sort

namespace radix_sort {
	/*
		n => size of array
		k => maximum value in the array
		d => number of digits of k
		b => base (count array size)

		time complexity - O(n*d):
			=> O(d * (n + b))
			=> O(log_10(k)(n + 10))
			=> O(10(n + 10))
			~ O(n)*

		space complexity - O(n + b)
			=> O(n + 10)
			~ O(n)*
	*/
	void counting_sort(vector<int>& arr, int n, int exp) {
		int out[n]	  = {0};
		int count[10] = {0};

		for(int i : arr) {
			count[(i / exp) % 10]++;
		}

		for(int i = 1; i <= 9; i++) {
			count[i] += count[i - 1];
		}

        //stable variant of counting sort
		for(int i = n - 1; i >= 0; i--) {
			out[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		for(int i = 0; i <= n - 1; i++) {
			arr[i] = out[i];
		}
	}

	void sort(vector<int>& arr) {
		int n	 = (int)arr.size();
		int maxi = *max_element(all(arr));
		for(int exp = 1; maxi / exp > 0; exp *= 10) {
			radix_sort::counting_sort(arr, n, exp);
		}
	}
}  // namespace radix_sort

int main() {
	int n, tmp;
	vector<int> arr;

	cin >> n;
	for(int i = 0; i <= n - 1; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	cout << arr << endl;
	radix_sort::sort(arr);
	cout << arr << endl;

	return 0;
}