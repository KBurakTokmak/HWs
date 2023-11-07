#include "the1.h"

//You may write your own helper functions here

// Manually define an abs function for integers.
int intAbs(int value) {
    return (value < 0) ? -value : value;
}

// Implement swap functionality manually.
void mySwap(unsigned short& a, unsigned short& b, long& swap, double& avg_dist, double& max_dist, int i, int j) {
    unsigned short temp = a;
    a = b;
    b = temp;
    swap++;
    int dist = intAbs(i - j);
    avg_dist += dist;
    if (dist > max_dist) {
        max_dist = dist;
    }
}

// Lomuto partition scheme.
int lomutoPartition(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist) {
    unsigned short pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
            i++;
            mySwap(arr[i], arr[j], swap, avg_dist, max_dist, i, j);
        }
    }
    mySwap(arr[i + 1], arr[high], swap, avg_dist, max_dist, i + 1, high);
    return (i + 1);
}

// Hoare partition scheme.
int hoarePartition(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist) {
    unsigned short pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] > pivot); // Change this line for descending order
        do {
            j--;
        } while (arr[j] < pivot); // Change this line for descending order

        if (i >= j)
            return j;

        mySwap(arr[i], arr[j], swap, avg_dist, max_dist, i, j);
    }
}
int medianOfThreeIndex(unsigned short* arr, int a, int b, int c) {
    unsigned short A = arr[a], B = arr[b], C = arr[c];
    if (A < B) {
        if (B < C) return b; // A < B < C
        else if (A < C) return c; // A < C <= B
        else return a; // C <= A < B
    } else {
        if (A < C) return a; // B <= A < C
        else if (B < C) return c; // B < C <= A
        else return b; // C <= B <= A
    }
}
// Median of three function.
void medianOfThree(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist, bool hoare) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThreeIndex(arr, low, mid, high);

    // If we are using Hoare partitioning, we want the median to be in the middle position
    if (hoare && medianIndex != mid) {
        mySwap(arr[medianIndex], arr[mid], swap, avg_dist, max_dist, medianIndex, mid);
    }
    // For Lomuto partitioning, the pivot needs to be in the last position
    else if (!hoare && medianIndex != high) {
        mySwap(arr[medianIndex], arr[high], swap, avg_dist, max_dist, medianIndex, high);
    }
}

// QuickSort function.
void quickSortRec(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist, bool hoare, bool median_of_3, int& n_calls) {
    if (low < high) {
        // Apply the median of three modification if required
        if (median_of_3) {
            medianOfThree(arr, low, high, swap, avg_dist, max_dist, hoare);
        }

        int pi;
        if (hoare) {
            pi = hoarePartition(arr, low, high, swap, avg_dist, max_dist);
            quickSortRec(arr, low, pi, swap, avg_dist, max_dist, hoare, median_of_3, n_calls);
            quickSortRec(arr, pi + 1, high, swap, avg_dist, max_dist, hoare, median_of_3, n_calls);
            n_calls += 2; // Incrementing the count for two recursive calls
        } else {
            pi = lomutoPartition(arr, low, high, swap, avg_dist, max_dist);
            quickSortRec(arr, low, pi - 1, swap, avg_dist, max_dist, hoare, median_of_3, n_calls);
            quickSortRec(arr, pi + 1, high, swap, avg_dist, max_dist, hoare, median_of_3, n_calls);
            n_calls += 2; // Incrementing the count for two recursive calls
        }
    }
}


int quickSort(unsigned short* arr, long& swap, double& avg_dist, double& max_dist, bool hoare, bool median_of_3, int size) {
    int n_calls = 0;
    swap = 0;
    avg_dist = 0;
    max_dist = 0;

    // Start the recursive sorting with median_of_3 consideration
    quickSortRec(arr, 0, size - 1, swap, avg_dist, max_dist, hoare, median_of_3, n_calls);

    // Calculate the average distance after all swaps
    if (swap > 0) {
        avg_dist /= swap;
    }

    return n_calls+1;
}
