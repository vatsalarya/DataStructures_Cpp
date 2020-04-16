#include<iostream>
using namespace std;
int main(){
    int t{},x{},y{},z{};
    cin>>t>>x>>y>>z;
    for(int i=1; i<t/x; i++){
        for(int j=1; j<t/y; j++){    
            for(int i=1; i<t/x; i++){
                if((x*i + y*j + z*k ) % t == 0){
                    cout<<"Possible to achieve exact amount"<<endl;
                    return 0;
                }
            }
        }   
    }
    cout<<"Overpaid!"<<endl;
    return 0;
}