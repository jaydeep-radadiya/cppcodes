#include<bits/stdc++.h>
using namespace std;

void downheapify(vector<int> &heap,int idx){
	int li = 2*idx+1;
	int ri = 2*idx+2;
	if(li>=heap.size() && ri>=heap.size())
		return;
	int largestIdx = idx;
	if(li<heap.size() && heap[li]>heap[largestIdx])
		largestIdx = li;
	if(ri<heap.size() && heap[ri]>heap[largestIdx])
		largestIdx = ri;
	if(largestIdx==idx)
		return;
	swap(heap[idx],heap[largestIdx]);
	downheapify(heap,largestIdx);
}

void buildHeapOptimised(vector<int> &heap){
	for(int i=heap.size()-1;i>=0;i--){
		downheapify(heap,i);
	}
}

void downheapifyhelper(vector<int> &heap,int idx,int hs){
	int li = 2*idx+1;
	int ri = 2*idx+2;
	if(li>=hs && ri>=hs)
		return;
	int largestIdx = idx;
	if(li<hs && heap[li]>heap[largestIdx])
		largestIdx = li;
	if(ri<hs && heap[ri]>heap[largestIdx])
		largestIdx = ri;
	if(largestIdx==idx)
		return;
	swap(heap[idx],heap[largestIdx]);
	downheapifyhelper(heap,largestIdx,hs);
}

void heapsort(vector<int> &heap){
	int hs = heap.size(); // heap size
	buildHeapOptimised(heap);
	for(int i=hs-1;i>=0;i--){
		swap(heap[0],heap[i]);
		hs--;
		downheapifyhelper(heap,0,hs);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> heap(n);
	for(int i=0;i<n;i++)
		cin>>heap[i];

	heapsort(heap);
	for(int ele : heap)
		cout<<ele<<" ";

	return 0;
}