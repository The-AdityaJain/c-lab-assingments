#include<iostream>
using namespace std;

void adjust(int A[], int n, int i);

void Heap_sort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjust(A, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        adjust(A, i, 0);
    }
}

void adjust(int A[], int n, int i) {
    int j = 2 * i + 1;
    while (j < n) {
        if (j + 1 < n && A[j + 1] < A[j]) { //for ascending A[j + 1] > A[j]
            j++;
        }
        if (A[j] >= A[i]) { //for ascending A[j] <= A[i]
            break;
        } 
        else {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    
    for (int i = 0; i < n; i++) {
    	cout << "Enter the element: "<<i<<" ";
        cin >> a[i];
    }

    Heap_sort(a, n);
    cout<<"sorted array : ";
    for(int i=0;i<n;i++){
    	cout<<a[i] <<" ";
	}
	return 0;
}
