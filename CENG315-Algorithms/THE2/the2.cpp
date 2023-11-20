#include "the2.h"

// do not add extra libraries here
/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    size      : number of elements in the array
*/

int findMaxLength(const std::string* arr, int size) {
    int maxLength = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].length() > maxLength) {
            maxLength = arr[i].length();
        }
    }
    return maxLength;
}


int counting_sort(std::string *arr, int size, int pos) {
    int* count = new int[27];
    std::string* temp_result = new std::string[size];
    int iterations = 0;

    for (int i = 0; i < 27; i++) {// initialize , dont count iteration
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) { //loop2
        if (arr[i].length() <= pos){
            count[0]++;
        }
        else{
            count[(arr[i][pos]-'A'+1)]++;
        }
        iterations++;
    }

    for (int i = 1; i < 27; i++) {//loop3
        count[i] += count[i - 1];
        iterations++;
    }

    for (int i = size - 1; i >= 0; i--) {//loop4
        int index;
        if (arr[i].length() <= pos){
            index = 0;
        }
        else{
            index = (arr[i][pos]-'A'+1);
        }
        temp_result[count[index] - 1] = arr[i];
        count[index]--;
        iterations++;
    }

    for (int i = 0; i < size; i++) {//copy-back loop
        arr [i] = temp_result[i];
        iterations++;
    }

    delete[] temp_result;
    delete[] count;
    return iterations;
}


int radix_string_sort(std::string* arr, int size, bool ascending) {
    int iteration_count=0, maxLength=0;
    maxLength = findMaxLength(arr, size);
    
    for (int pos = maxLength - 1; pos >= 0; pos--) {
        iteration_count += counting_sort(arr, size, pos);
    }
    if (!ascending) {
        std::string* temp = new std::string[size];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[size - i - 1];
        }
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
    return iteration_count;
}