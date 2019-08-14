//Program by Christina Ochsner
//PS#: 1166214

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>

using namespace std;
 
double bubble(int arr[], int n)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	int i, j;
	for (i = 0; i < n-1; i++) 
	{	   
		for (j = 0; j < n-i-1; j++) 
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	gettimeofday(&stop, NULL);
	double timer=stop.tv_usec-start.tv_usec;
	return timer;
}
double selection(int arr[], int n)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
		min = i;
        for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
    }
	gettimeofday(&stop, NULL);
	double timer=stop.tv_usec-start.tv_usec;
	return timer;
}
double insertion(int arr[], int n)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
	gettimeofday(&stop, NULL);
	double timer=stop.tv_usec-start.tv_usec;
	return timer;
}
//print array for testing
/*
void print(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
*/
int main()
{
	int size=1;
	cout<<"Welcome to the sort timer program!"<<endl;
	while(size!=0)
	{
		cout<<"What size do you want your array to be? Enter 0 to exit."<<endl;
		cin>>size;
		
		while(size<0)
		{
			cout<<"Invalid Input. Try again."<<endl;
			cin>>size;
		}
		if(size==0)
		{
			cout<<"Exiting..."<<endl;
			break;
		}
		
		int *arr=new int[size];
		int *arr1=new int[size];
		int *arr2=new int[size];
		
		
		//fill array
		for(int i=0; i<size;i++)
		{
			int num=rand() %size;
			arr[i]=num;
			arr1[i]=num;
			arr2[i]=num;
		}
		
		cout<<"Bubble: ";
		//print(arr,size);
		cout<<bubble(arr, size)<<" microseconds"<<endl;
		//print(arr, size);

		cout<<"Selection: ";
		//print(arr1,size);
		cout<<selection(arr1, size)<<" microseconds"<<endl;
		//print(arr1, size);
		
		cout<<"Insertion: ";
		//print(arr2,size);
		cout<<insertion(arr2, size)<<" microseconds"<<endl;
		//print(arr2, size);
		
		delete [] arr;
		delete [] arr1;
		delete [] arr2;
	}
	
	return 0;
	
}