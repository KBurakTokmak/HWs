#ifndef THE1_H
#define THE1_H

int quickSort(unsigned short* arr, long& swap, double& avg_dist, double& max_dist, bool hoare, bool median_of_3, int size);
void quickSortRec(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist, bool hoare, bool median_of_3, int& n_calls);
int medianOfThreeIndex(unsigned short* arr, int a, int b, int c);
void medianOfThree(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist, bool hoare);
int hoarePartition(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist);
int lomutoPartition(unsigned short* arr, int low, int high, long& swap, double& avg_dist, double& max_dist);
void mySwap(unsigned short& a, unsigned short& b, long& swap, double& avg_dist, double& max_dist, int i, int j);
int intAbs(int value);

#endif