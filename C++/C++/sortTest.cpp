//
//  sortTest.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/20.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[10] = {5, 87, 13, 25, 7, 55, 64, 100, 4, 6};

void printArr() {
    for(int i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort() {
    int temp;
    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArr();
}

void selectionSort() {
    int index, temp;
    for(int i = 0; i < 10; i++) {
        index = i;
        for(int j = i + 1; j < 10; j++) {
            if(arr[index] > arr[j]) index = j;
        }
        
        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
    printArr();
}

void insertionSort() {
    int temp;
    for(int i = 1; i < 10; i++) {
        temp = arr[i];
        int prev = i - 1;
        
        while(prev >= 0 && arr[prev] > temp) { // 뽑은거 이전을 비교. 제 위치를 찾아준다.
            arr[prev + 1] = arr[prev];
            prev--;
        }
        
        arr[prev + 1] = temp;
    }
    printArr();
}

int partition(int arr[10], int left, int right) {
    int mid = (left + right) / 2;
    int temp = arr[left];
    arr[left] = arr[mid];
    arr[mid] = temp;
    
    int pivot = arr[left];
    int i = left, j = right;
    
    while(i < j) {
        while(pivot < arr[j]) j--;
        while(i < j && pivot >= arr[i]) i++;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    arr[left] = arr[i];
    arr[i] = pivot;
    return i;
}

void quickSort(int arr[10], int left, int right) {
    if(left >= right) return;
    
    int pi = partition(arr, left, right);
    quickSort(arr, left, pi - 1);
    quickSort(arr, pi + 1, right);
}

int main() {
    bubbleSort();
    selectionSort();
    insertionSort();
    
    int quickArr[10] = {5, 87, 13, 25, 7, 55, 64, 100, 4, 6};
    quickSort(quickArr, 0, 9);
    for(int i = 0; i < 10; i++) cout << quickArr[i] << " " ;
    cout << endl;
    
    
    
    return 0;
}
