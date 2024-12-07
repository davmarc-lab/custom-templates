#include <iostream>
#include <vector>

void printVec(const std::vector<int> &arr) {
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

// Merge Sort
void merge(std::vector<int> &arr, const int &left, const int &mid, const int &right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    std::vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, const int &left, const int &right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Bubble Sort
void bubbleSort(std::vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, then break
        if (!swapped)
            break;
    }
}

// Quick Sort
int partition(std::vector<int> &arr, const int &low, const int &high) {
    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[;ow..high] and move all smaller
    // elements on left side. Elements from low to
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int> &arr, const int &low, const int &high) {
    if (low < high) {

        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::cout << "Test\n";

    // Merge Sort
    {
        std::cout << "Merge Sort:\n";
        std::vector<int> arr = {20, 14, 55, 2, 3, 66, 77};
        printVec(arr);
        mergeSort(arr, 0, arr.size() - 1);
        printVec(arr);
    }

    // Bubble Sort
    {
        std::cout << "Bubble Sort:\n";
        std::vector<int> arr = {20, 14, 55, 2, 3, 66, 77};
        printVec(arr);
        bubbleSort(arr);
        printVec(arr);
    }

    // Quick Sort
    {
        std::cout << "Quick Sort:\n";
        std::vector<int> arr = {20, 14, 55, 2, 3, 66, 77};
        printVec(arr);
        quickSort(arr, 0, arr.size() - 1);
        printVec(arr);
    }

    return 0;
}
