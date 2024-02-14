#include <vector>
#include <iostream>

int main()
{
//te t
	std::vector<int> a{1,2,3};
	std::vector<int> b{4,5,6};	
	std::vector<int> tmp;


    tmp.insert(tmp.end(), a.begin(), a.end());
    tmp.insert(tmp.end(), b.begin(), b.end());

	for(auto& item : tmp){
		std::cout<< item <<" ";
	}
	std::cout<<std::endl;


	return 0;
}
