#include <bits/stdc++.h>
using namespace std;
int arr[9] = {5, 4, 3, 7, 2, 1, 8, 9, 6};

int Partition(int front, int end, int pivot) {
    int j = front - 1;
    for (int i = front; i <= end; i++) {
        if (arr[i] < arr[pivot]) {
            j++;
            swap(arr[j], arr[i]);
            if (j == pivot)
                pivot = i;
        }
    }
    j++;
    swap(arr[pivot], arr[j]);
    return j;
}

void Qsort(int front, int end) {

    if (front < end) {
        int pivot = Partition(front, end, front);
        for (auto& i : arr) {
            cout << i << " ";
        }
        cout<<endl;
        Qsort(front, pivot - 1);
        Qsort(pivot + 1, end);
    }
    return;
}

int main(int argc, char**argv) {

    Qsort(0, 8);
    for (auto& i : arr) {
        cout << i << " ";
    }

    return 0;
}
