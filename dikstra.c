#include <stdio.h>


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

int small(){

	int min = INF;
	int idx;
	for(int i= 0; i< 6; i++){

		if(!v[i] && d[i] < min){
			min = d[i];
			idx = i;
		}
	}

	return idx;
}


void dijkstra(int s){


	v[s] = true;

	for(int i= 0 ; i< num ; i++){
		d[i] = a[s][i];
	}

	for(int i=0; i< num-2; i++){
		int curr = small();
		v[curr] = true;
		for(int j=0 ;  j< num ;j++){
			if(!v[j] && d[curr]+a[curr][j] < d[j]){
				d[j] = d[curr]+a[curr][j];
			}
		}
	}
}

int main(){

	dijkstra(0);

	for(int i=0 ; i< num; i++){

		printf("%d ", d[i]);
	}


	return 0;
}

// int getSmallIndex(){
// 	int min = INF;
// 	int index = 0;
// 	for(int i= 0; i< num; i++){
// 		if(d[i] < min && !v[i]){
// 			min = d[i];
// 			index= i;
// 		}
// 	}
// 	return index;
// }

// void dijkstra(int start){
// 	for(int i= 0; i<num; i++){
// 		d[i] = a[start][i];
// 	}
// 	v[start] = 1;
// 	for(int i= 0; i< num-2; i++){
// 		int current = getSmallIndex();
// 		v[current] = 1;
// 		for(int j= 0; j< 6; j++){
// 			if(!v[j]){
// 				if(d[current] + a[current][j] < d[j]){
// 					d[j] = d[current] + a[current][j];
// 				}
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	dijkstra(0);

// 	for(int i= 0; i<num ; i++){
// 		printf("%d ", d[i]);
// 	}

// 	return 0;
// }