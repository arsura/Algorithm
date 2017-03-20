#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

unsigned long long sumOfDivied1(vector<unsigned long long> Array)
{
    if(Array.size()==1)return Array[0];
   // if(Array.size()==2)return Array[0]+Array[1];
    else{
        vector<unsigned long long> Arr_1,Arr_2;
        for(unsigned long long i=0;i<Array.size();++i){
            if(i<Array.size()/2) Arr_1.push_back(Array[i]);
            else Arr_2.push_back(Array[i]);
        }
        return sumOfDivied1(Arr_1)+sumOfDivied1(Arr_2);
    }
}

unsigned long long sumOfDivied2(vector<unsigned long long>Array, unsigned long long left, unsigned long long right)
{
    if(right-left==0) return Array[left];
    if(right-left==1) return Array[left] + Array[right];
    else
    {
        unsigned long long mid =(right+left)/2;
        return sumOfDivied2(Array,left,mid)+sumOfDivied2(Array,mid+1,right);
    }
}

unsigned long long sumBruteForce(vector<unsigned long long> Array)
{
    unsigned long long sum=0;
    for(unsigned long long int i=0;i<Array.size();++i)
    {
        sum+=Array[i];
    }
    return sum;
}

int main()
{
    clock_t time;
    vector<unsigned long long> Array;
    for(unsigned long long i=1;i<=1000000;++i){
        Array.push_back(i);
    }

    time = clock();
    unsigned long long sum1 = sumOfDivied1(Array);
    time = clock() - time;

    cout<<"Sum 1 : "<<sum1<<endl;
    cout<<"Time : " <<float(time) / CLOCKS_PER_SEC << "s" << endl;
    cout<<"-----------------------------------"<<endl;

    time = clock();
    long int sum2 = sumOfDivied2(Array,0,Array.size()-1);
    time = clock() - time;

    cout<<"Sum 2 : "<<sum2<<endl;
    cout<<"Time : "<<float(time) / CLOCKS_PER_SEC << "s" << endl;
    cout<<"-----------------------------------"<<endl;

    time = clock();
    unsigned long long sum3 = sumBruteForce(Array);
    time = clock() - time;
    cout<<"Sum 3 Brute Force : "<<sum3<<endl;
    cout<<"Time : "<<float(time) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
