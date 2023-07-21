int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && arr[i] < pivot) {
            i++;
        }

        while ( i<=j && arr[j] > pivot) {
            j--;
        }

        if (i >= j) {
            break;
        }

        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSortHelper(arr, low, pivotIndex - 1);
        quickSortHelper(arr, pivotIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    int size = arr.size();
    if (size <= 1) {
        return arr;
    }

    quickSortHelper(arr, 0, size - 1);
    return arr;
}