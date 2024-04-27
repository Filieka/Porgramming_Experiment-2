#include<iostream>
using namespace std;

class Commend{
    private:
    int board[1000][1000];
    int size=0;

    public:
    Commend(){}

    void check(string input){
        if(input=="rotate right"){right();}
        else if(input=="rotate left"){left();}
        else if(input=="print"){print();}
        else if(input=="scan"){scan();}
        else if(input=="stop"){exit(0);}
        else{cout<<"unknown"<<endl;}
    }

    void right(){
        if(size!=0){
            int i,j;
            int last[size][size];
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    last[i][j]=board[i][j];
                }
            }
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    board[j][size-1-i]=last[i][j];
                }
            }
        }
        else{
            cout<<"No element in matrix can be rotated.\n";
        }
    }

    void left(){
        if(size!=0){
            int i,j;
            int last[size][size];
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    last[i][j]=board[i][j];
                }
            }
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    board[size-1-j][i]=last[i][j];
                }
            }
        }
        else{
            cout<<"No element in matrix can be rotated.\n";
        }
    }

    void print(){
        if(size!=0){
            int i,j;
            for(i=0;i<size;i++){
                for(j=0;j<size;j++){
                    cout<<board[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
        else{
            cout<<"No element in matrix can be printed.\n";
        }
    }

    void scan(){
        int i,j;
        cin>>size;
        for(i=0;i<size;i++){
            for(j=0;j<size;j++){
                cin>>board[i][j];
            }
        }
        cin>>ws;
    }

    
};

int main(){
    Commend commend;
    string in;
    while(true){
        getline(cin,in);
        commend.check(in);
    }
}