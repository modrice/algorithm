#include <iostream>
class Solution {
public:
    int dest;
    unsigned long min;
    int cnt;
    std::vector<bool> vec;
    void go(vector<vector<int>>& roads, int to, unsigned long time, std::vector<bool>& v){
        if(time > min){
            //std::cout<<"ignore: "<< time <<" > "<< min <<std::endl;
            return;
        }
        if(to == dest){
            //std::cout<<"arrived: "<< time<<std::endl;
            //vec.push_back(time);
            if(min > time){
                min = time;
                cnt = 1;
            }
            if(min == time){
                //std::cout<<"count: "<< cnt <<std::endl;
                ++cnt;
            }
            return;
        }
        // int num=0;
        // for(auto element: v){  
        //     std::cout<<num++ <<": "<<element<<" ";
        // }
        // std::cout<<std::endl;

        for(auto& item: roads){
            // if(time+item[2]> min){
            //     return;
            // }
            int tmp =time + item[2];
            //std::cout<< tmp <<", "<< min <<std::endl;
            if(item[1] == to && v[item[0]]== false &&  (tmp <= min)){// && item[2] != 0){
                //std::cout<< item[1] <<" -> "<<item[0]<<": "<<item[2]<<std::endl;
                v[item[0]]=true;
                go(roads,item[0], time+item[2], v);
                v[item[0]]=false;
            }
            else if(item[0] == to && v[item[1]]== false && (tmp <= min)){//&& item[2] != 0){
                //std::cout<< item[0] <<" ~> "<<item[1]<<": "<<item[2]<<std::endl;
                v[item[1]]=true;
                go(roads,item[1], time+item[2],v);
                v[item[1]]=false;
            }          
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        //unsigned long time =0;  

        vec.resize(n,false);
        cnt =0;
        min = 1000000000;
        dest = n-1;
        vec[0]= true;
        for(auto& item: roads){
            if(item[0]==0){
                //std::cout<<item[1]<<std::endl;
                //int tmp = item[2];
                //item[2]= 0;
                vec[item[1]] =true;
                go(roads, item[1], item[2], vec);
                vec[item[1]] =false;

                //item[2]=tmp;
            }
            else if(item[1]==0){
                // int tmp = item[2];
                // item[2]= 0;   
                vec[item[0]] =true;
                go(roads, item[0], item[2],vec);
                vec[item[0]] =false;
                //item[2]=tmp;
            }
        }
        return cnt-1;
    }
};