#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define judge check[row+1][col]&&check[row][col+1]&&check[row-1][col]&&check[row][col-1]

class Point{
private:
    int x,y;
public:
    Point(int a,int b):x(a),y(b){}
    int getX(){return x;}
    int getY(){return y;}
};

class Board{
private:
    int row,col,baseRow,baseCol;
    vector<vector<char>> maze;
    vector<vector<bool>> check;
    vector<Point> list;

    void f(int num){
        reverse(list.begin()+num-1,list.end());
        row=list.back().getX();
        col=list.back().getY();
    }

    void u(){
        row--;
        maze[row][col*2-1]=' ';
        toList();
        pin();
    }

    void d(){
        maze[row][col*2-1]=' ';
        row++;
        toList();
        pin();
    }

    void r(){
        maze[row][col*2]=' ';
        col++;
        toList();
        pin();
    }

    void l(){
        col--;
        maze[row][col*2]=' ';
        toList();
        pin();
    }

    void toList(){
        Point point(row,col);
        list.push_back(point);
    }

    void pin(){
        check[row][col]=true;
    }

public:
    Board(int row,int col):baseRow(row),baseCol(col){
        maze.resize(row+1,vector<char>((col+1)*2));
        check.resize(row+2,vector<bool>(col+2));
        int r=0,c=0;
        while(r<row+2){
            c=0;
            while(c<col+2){
                check[r][c]=true;
                c++;
            }
            r++;
        }
        r=1;
        while(r<row+1){
            c=1;
            while(c<col*2+1){
                maze[r][c]='_';
                maze[r][c+1]='|';
                check[r][(c+1)/2]=false;
                c+=2;
            }
            r++;
        }
    }

    void start(int a,int b){
        row=baseRow-a+1;
        col=b;
        toList();
        pin(); 
    }

    bool isOk(){
        if(list.empty()){return false;}
        row=list.back().getX();
        col=list.back().getY();
        if(judge){
            list.pop_back();
            return isOk();
        }
        return true;
    }

    void judgeCom(char in){
        if(in=='F'){
            int num;
            cin>>num;
            f(num);
        }
        else if(in=='U'){
            u();
        }
        else if(in=='D'){
            d();
        }
        else if(in=='R'){
            r();
        }
        else if(in=='L'){
            l();
        }
    }

    void display(){
        int i=0,r,c;
        while(i<baseCol){
            cout<<" _";
            i++;
        }
        cout<<endl;
        r=1;
        while(r<baseRow+1){
            c=1;
            cout<<'|';
            while(c<baseCol*2+1){
                cout<<maze[r][c]<<maze[r][c+1];
                c+=2;
            }
            cout<<endl;
            r++;
        }
        cout<<endl;
    }
};

int main(){
    int times,row,col,i=0;
    char command;
    cin>>times;
    while(times!=0){
        times--;
        cin>>row>>col;
        Board board(row,col);
        cin>>row>>col;
        board.start(row,col);
        while(board.isOk()){
            cin>>command;
            board.judgeCom(command);
        }
        board.display();
    }
}