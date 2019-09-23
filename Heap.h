#ifndef HEAP_DW
#define HEAP_DW
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Heap{
private:
    T left(T parent);
    T right(T parent);
    T parent(T child);
    void siftDown(int i , vector<T> list);
    bool isLeaf(int i);
    void swap(T data , T data2);
    //
public:
    T priority;
    vector<T> heap;
    Heap();
    Heap(std::vector<T>);
    void addElement(T element);
    T getPriority();
    bool empty();
    unsigned long size();
    vector<T> getArray();
};

template <class T>
Heap<T>::Heap(){
    priority=NULL;
}

template <class T>
Heap<T>::Heap(vector<T> vec){
    for(int i = (heap.size()-2)/2 ; i>=0 ; i++){
        siftDown(i,heap);
    }
}

template <class T>
void Heap<T>::siftDown(int i, vector<T> heap){
    while(!isLeaf(i)){
        T n = left(heap.at(i));
        if(n < right(heap.at(i))){
            n = right(heap.at(i));
        }
        if(heap.at(i) > heap.at(n)){
            return;
        }
        else{
            swap(heap.at(i),heap.at(n));
        }
        i = n;
    }
}

template <class T>
bool Heap<T>::isLeaf(int i){
    if(2*i+1>=heap.size()){
        return true;
    }
    return false;
}

template <class T>
void Heap<T>::swap(T data , T data2){
    int index1=0;
    int index2=0;
    for(int i = 0 ; i < heap.size() ; i++){
        if(heap.at(i)==data){
            index1 = i;
        }
        if(heap.at(i)==data2){
            index2=i;
        }
    }
    heap.at(index2)=data;
    heap.at(index1)=data2;
}

template <class T>
void Heap<T>::addElement(T element){
    heap.push_back(element);
    vector<T> heap2 = heap;
    Heap(heap);
}

template <class T>
bool Heap<T>::empty(){
    if(heap.size()==0){
        return true;
    }
    return false;
}

template <class T>
unsigned long Heap<T>::size(){
    return (unsigned long)heap.size();
}

template <class T>
vector<T> Heap<T>::getArray(){
    return heap;
}

template <class T>
T Heap<T>::getPriority(){
    return heap.at(0);
}

template <class T>
T Heap<T>::left(T parent){
    int index = 0;
    for(int i = 0; i < heap.size() ; i++){
        if(heap.at(i)==parent){
            index = i;
        }
    }
    if(index=0){
        return NULL;
    }
    if(2*index+1<heap.size()){
        return heap.at(2*index+1);
    }
    return NULL;
}

template <class T>
T Heap<T>::right(T parent){
    int index = 0;
    for(int i = 0; i < heap.size() ; i++){
        if(heap.at(i)==parent){
            index = i;
        }
    }
    if(index=0){
        return NULL;
    }
    if(2*index+2<heap.size()){
        return heap.at(2*index+2);
    }
    return NULL;
}

template <class T>
T Heap<T>::parent(T child){
    int index = 0;
    for(int i = 0; i < heap.size() ; i++){
        if(heap.at(i)==parent){
            index = i;
        }
    }
    if(index=0){
        return NULL;
    }
    if((index-1)/2<heap.size()){
        return heap.at((index-1)/2);
    }
    return NULL;
}

#endif
