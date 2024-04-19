#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>

int num = 6;
int INF = 1000000000;


int a[6][6]={
	{0,2,5,1, INF, INF},
	{2,0,3,2, INF, INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF, INF, 1,1,0,2},
	{INF, INF, 5, INF, 2, 0}
};
bool v[6];
int d[6];

std::priority_queue<std::pair<int,int>> q;

std::vector<std::vector<std::pair<int,int>>> vec;


void dikstra(int s)
{
	d[s] = 0;
	int min=INF;
	int idx;
	for(auto& item: vec[0]){
		d[item.first] = item.second;
		if(item.second < min){
			min = item.second;
			idx = item.first;
		}
	}
	q.push(std::make_pair(idx,-min));	

	//std::cout<< idx <<" "<< min <<std::endl;
	//q.push(std::make_pair(s,0));

	while(!q.empty()){
		int curr = q.top().first;
		int cost = -q.top().second;
		q.pop();
		//v[curr]= true;

		std::cout<<d[curr]<< " "<<cost <<std::endl;
		if(d[curr] < cost) continue;
		for(auto& item:vec[curr]){
			
			int next = item.first;
			int next_cost = item.second + cost;

			if(next_cost < d[next]){

				d[next] = next_cost;
				q.push(std::make_pair(next, -next_cost));
			}

		}

	}
}
int main(){
	vec.resize(num);

	
	for(int i= 0; i< num ; i++){
		d[i] = INF;
		for(int j=0; j< num; j++){
			if(i!=j && a[i][j] != INF){
				vec[i].push_back(std::make_pair(j,a[i][j]));
			}
		}
	}

	dikstra(0);

	for(int i=0 ; i< num; i++){

		for(auto& item: vec[i]){
		//	std::cout<< i <<" "<< "-> "<<item.first<<" : "<<item.second<<std::endl;
		}
	}


	for(int i= 0; i< 6 ; i++){

		std::cout << d[i]<<" ";
	}
	std::cout<<std::endl;
	return 0;
}