#include "the2.h"
#include <cmath>
// You may write your own helper functions here

/*void initiliaze_array(int* arr,int arraySize){
    for(int i=0;i<arraySize;i++){
        arr[i]=0;
    }
    
}*/

/*void countingSort(int* arr,int arraySize,int dec){
    int *c_array= new int[10];
    int *b_array= new int[arraySize];
    initiliaze_array(c_array,arraySize); //loop1 - k
    
    for(int j=0;j<arraySize;j++){//loop2 - n
        c_array[(arr[j] / dec) % (10)]++;
    }
    for (int i=1;i<10;i++){ //loop 3 -k
        c_array[i]+=c_array[i-1];
    }
    
    for (int i=arraySize-1;i>=0;i--){//loop4 -n
        b_array[c_array[(arr[i]/dec) %(10)]-1]=arr[i];
        c_array[(arr[i]/dec) %(10)]--;
    }
    
    for (int i=0;i<arraySize;i++){
        arr[i]=b_array[i];
    }
}
*/

long countingSortByGroupSize(int* arr,int arraySize,int groupSize,int dec){
    int group_multiplier=10;
    long iteration=0;
    group_multiplier=pow(double(10),double(groupSize));
    
    int *c_array= new int[group_multiplier];
    int *b_array= new int[arraySize];
    
        

    
    //initiliaze_array(c_array,arraySize); //loop1 - k
    c_array[group_multiplier]={0};
    
    for(int j=0;j<arraySize;j++){//loop2 - n
        c_array[(arr[j] / dec) % (group_multiplier)]++;
        iteration++;
    }
    for (int i=1;i<group_multiplier;i++){ //loop 3 -k
        c_array[i]+=c_array[i-1];
        iteration++;
    }
    
    
    for (int i=arraySize-1;i>=0;i--){//loop4 -n
        b_array[c_array[(arr[i]/dec) %(group_multiplier)]-1]=arr[i];
        c_array[(arr[i]/dec) %(group_multiplier)]--;
        iteration++;
        if(i==0){
            for (int j=0;j<arraySize;j++){
                arr[j]=b_array[j];
                iteration++;
                }
        }
    }
    return iteration;
    
    
}

long multiDigitRadixSort(int* arr, bool ascending, int arraySize, int groupSize, int maxDigitLength){
    long numberOfIterations = 0;
    int divider=1;

    int temp;
    
    while(maxDigitLength!=0){
        if (groupSize>maxDigitLength){
            groupSize=maxDigitLength;
            maxDigitLength=0;
        }
        else{
            maxDigitLength-=groupSize;
        }
        
        numberOfIterations+=countingSortByGroupSize(arr,arraySize,groupSize,divider);
        divider*=pow(double(10),double(groupSize));
        
    }
    
    if (!ascending){
        for (int i = 0, j = arraySize - 1; i < arraySize/2; i++, j--)  { // reverse array    
            temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;
            }  
        }
        else{
            //do nothing
        }
    
    
    return numberOfIterations;
    
    
}