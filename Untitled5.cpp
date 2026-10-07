#include<iostream>

using namespace std;
class sort{
	public:
	int arr[5]={6,4,11,2,13};
	
	void insertionsort(){
		for(int i=1;i<5;i++){
		
		int key=arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
		    j--;
		}
		arr[j+1]=key;
    }
    for(int i=0;i<5;i++){
    	cout<<arr[i]<<" ";
	}
	}
	void selectionsort(){
		for(int i=0;i<4;i++){
			int smallest=i;
			for(int j=i+1;j<5;j++){
				if(arr[j]<arr[smallest]){
					smallest=j;
				}	
		}
		int val=arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=val;
		}
		for(int i=0;i<5;i++){
    	cout<<arr[i]<<" ";
	}
	}
	void bubblesort(){
		for(int i=0;i<4;i++){
			
			for(int j=0;j<5-i-1;j++){
				if(arr[j]>arr[j+1]){
					int val=arr[j+1];
					arr[j+1]=arr[j];
					arr[j]=val;
				}
			}
		}
		for(int i=0;i<5;i++){
    	cout<<arr[i]<<" ";
	}}
	void shellsort(int n){
		for(int gap=n/2;gap>0;gap=gap/2){
			
			for(int i=gap;i<n;i++){
				int temp=arr[i];
				int j=i;
				while(j>=gap && arr[j-gap]>temp){
					arr[j]=arr[j-gap];
					j=j-gap;
				}
				arr[j]=temp;
			}
		}
	}
	void combsort(int n){
		bool swapped=true;
		int gap=n/1.3;
		
		while (gap!=1 && swapped ==true){
			if(gap<1){
				gap=1;
			}
			swapped =false;
			for(int i=0;i+gap>n;i++){
				if(arr[i]>arr[i+gap]){
					int val=arr[i+gap];
					arr[i+gap]=arr[i];
					arr[i]=val;
					
					swapped=true;
				}
			}
			gap=gap/1.3;
		}
	}
	int binarySearch(int size, int key) {

    int low = 0;
    int high = size - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        else if (arr[mid] < key) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return -1;
}
int interpolationSearch(int arr[], int size, int key) {

    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {

        int pos = low + ((key - arr[low]) * (high - low))
                        / (arr[high] - arr[low]);

        if (arr[pos] == key) {
            return pos;
        }

        else if (arr[pos] < key) {
            low = pos + 1;
        }

        else {
            high = pos - 1;
        }
    }

    return -1;
}
};
int main(){
	sort s;
	s.bubblesort();
}
