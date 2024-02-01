#include <iostream>
#include <vector>

// figure out Big(O)
// time limit exceeded

using namespace std;

std::vector<int>& qsort(std::vector<int>& arr){
	if(arr.size()==1){
		return {arr[0]};
	}
	// extract pivot value from array
	int pivot = *(arr.begin());
	arr.erase(arr.begin());

	std::vector<int> lower;
	std::vector<int> higher;
	
	//divide lower and higher vector with the pivot and remvoe reference array
	while(arr.size() != 0){
		int item = *(arr.begin());
		if( item < pivot){
			lower.push_back(item);
		}else{
			higher.push_back(item);
		}
		arr.erase(arr.begin());
	}

	//recursive call
	if(lower.size() != 0)
		lower = qsort(lower);
	if(higher.size() != 0)
		higher = qsort(higher);

	//concatenate
	lower.push_back(pivot);
	if(higher.size() != 0){
		lower.insert(lower.end(), higher.begin(), higher.end());
	}

	//return concatnated vector
	return lower;
}

int main()
{
	std::vector<int> arr{6 ,4,21, 3,1,3,5,9, 4, 3, 5, 2, 1};

	//call qsort
	std::vector<int> result = qsort(arr);

	for(auto& item : result){
		std::cout<< item <<" ";
	}
	std::cout<<std::endl;

	return 0;
}
