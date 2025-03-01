//This file is entirely for your test purposes. 
//This will not be evaluated, you can change it and experiment with it as you want.
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include "the1.h"

using namespace std;

void print_to_file(unsigned short* arr, int size)
{
	ofstream ofile;
	ofile.open("sorted.txt");
	ofile<<size<<endl;
	for(int i=0;i<size; i++) 
		ofile<<arr[i]<<endl;
}

void read_from_file(unsigned short*& arr, int& size)
{

	char addr[]= "in01.txt"; //You can test from in01.txt to in04.txt
	ifstream infile (addr);
	
	if (!infile.is_open())
	{
		cout << "File \'"<< addr 
			<< "\' can not be opened. Make sure that this file exists." <<endl;
		return;
	}
	infile >> size;
	arr = new unsigned short [size];
	
	for (int i=0; i<size;i++) {
		
		infile >> arr[i];
	}
	
}
	

void test(){
	int size = 1 << 8;
	int number_of_recursive_calls;
    long swap=0;
    double avg_dist=0, max_dist=0;
    bool hoare, median_of_3;
	unsigned short minval=0;
	unsigned short interval= (unsigned short)((1<<16)-1);   // unsigned short 65535 in maximum , you can try to minimize interval for data generation to make your code test more equality conditions
	                
	unsigned short values[] = {5, 23, 3, 98, 45, 1, 90};
	unsigned short* input_array = new unsigned short[sizeof(values)/sizeof(values[0])];
	for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); ++i) {
    input_array[i] = values[i];
	}
	hoare = false;
	median_of_3 = true;
	size = sizeof(values)/sizeof(values[0]);
	//Calculate duration and print output
	std::cout << "Size: " << size << std::endl <<
                 "Median of three: " << median_of_3  << std::endl <<
                 "Hoare: " << hoare << std::endl <<
                 "Array elements: {";
    for(int idx=0; idx < size - 1; idx++) std::cout << input_array[idx] << ", ";
    std::cout << input_array[size-1] << "}" << std::endl;
    number_of_recursive_calls = quickSort(input_array, swap, avg_dist, max_dist, hoare, median_of_3, size);
    std::cout << "Swap: " << swap << std::endl <<
                 "Average Distance: " << avg_dist  << std::endl <<
                 "Maximum Distance: " << max_dist << std::endl <<
                 "Number of recursive calls: " << number_of_recursive_calls << std::endl <<
                 "Sorted array: {";
    for(int idx=0; idx<size-1; idx++) std::cout << input_array[idx] << ", ";
    std::cout << input_array[size-1] << "}" << std::endl;
	delete[] input_array;
}

int main(){
	test();
	return 0;
}
	
	