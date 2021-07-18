// https://drive.google.com/file/d/1a_MQs31tcOmKCJ86QnRTbZ8xbKH1yyDX/view
#include<bits/stdc++.h>
using namespace std;

// max heap
void upheapify(vector<int> &heap,int idx){
	if(idx==0) return; // base case
	int pi = (idx-1)/2; // parent index
	if(heap[pi]<heap[idx]){
		swap(heap[pi],heap[idx]);
		upheapify(heap,pi);
	}
	else{
		return;
	}
}

void downheapify(vector<int> &heap,int idx){
	int li = 2*idx+1;
	int ri = 2*idx+2;
	if(li>=heap.size() and ri>=heap.size())
		return;
	int largestIdx = idx;
	if(li<heap.size() and heap[li]>heap[largestIdx])
		largestIdx = li;
	if(ri<heap.size() and heap[ri]>heap[largestIdx])
		largestIdx = ri;
	if(largestIdx==idx) return;
	swap(heap[idx],heap[largestIdx]);
	downheapify(heap,largestIdx);
}

void deletePeek(vector<int> &heap){
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap,0);
}

void buildHeapOptimised(vector<int> &heap){
	for(int i=heap.size()-1;i>=0;i--){
		downheapify(heap,i);
	}
}

int main(){
	vector<int> heap;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		heap.push_back(x);
		upheapify(heap,i);
	}

	for(int ele : heap)
		cout<<ele<<" ";
	deletePeek(heap);
	cout<<"\n";
	for(int ele : heap)
		cout<<ele<<" ";

	// build inplace heap
	// vector<int> heap {13,7,5,19,23,31,26};
	// buildHeapOptimised(heap);
	// for(int ele : heap)
	// 	cout<<ele<<" ";

	return 0;
}