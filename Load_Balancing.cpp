#include<iostream>
using namespace std;
int main(){
        int req_id[5],N,serv_id[5];
        char ch;
        cout<<"Anushka Kulkarni B24CE1102\n";
        cout<<"Enter no.of servers: ";
        cin>>N;
    do {
        cout<<"\nEnter request ID:\n";
        for (int i=0;i<5;i++){
            cin>>req_id[i];
        }
        for(int i=0;i<5;i++){
            serv_id[i]=req_id[i]%N;
        }
        cout<<"___________________\n";
        cout <<"Request - Server\n";
        cout<<"___________________\n";
        for (int i=0;i<5;i++){
            cout<<"  "<<req_id[i]<<"   -   "<<serv_id[i]<<endl;
        }
        cout<<"___________________";
        cout<<"\nDo you want to check more?(y/n): ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}
