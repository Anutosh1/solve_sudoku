//Code to find total valid Solution for a Incomplete Sudoku and print a Valid Sudoku
//Code is Valid 6*6 Sudoku 
//Example of valid Sudoku for 6*6
// 4 5 6 3 2 1 
// 1 2 3 5 4 6 
// 6 4 1 2 5 3
// 2 3 5 6 1 4
// 5 6 4 1 3 2
// 3 1 2 4 6 5

#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

class Sudoku{
    int n,total,mat[100][100],vis[100][100],con[100][100];
    
    //Beginning Array used to find the valid Sudoku
    int arr[6][6]={
                {4,5,6,3,2,1},
                {0,0,0,0,0,0},
                {6,4,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0}
            };

    public:

        Sudoku(int var){
            n=var;
            total=0;
        }

        void Reset(){
            total=0;
            for(int i=0;i<25;i++){
                for(int j=0;j<25;j++){
                    mat[i][j]=0;
                    vis[i][j]=0;
                    con[i][j]=0;
                }
            }
        }

        // Function to print first occurance of valid Sudoku
        bool printSudoku(int, int);

        // Function to count all valid Sudoku
        bool isValidSudoku(int, int);

        int printTotal(){
            return total;
        }
};



bool Sudoku::printSudoku(int row,int pos){
    bool res=false;
    if(pos==n+1){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        cout<<"\n";
        return true;
    }

    if(row==n){
        if(printSudoku(0,pos+1))return true;
        return false;
    }

    for(int i=0;i<n;i++){
        if(vis[pos][i]==1 || con[(row/2)*2 + i/3][pos]==1 || mat[row][i]!=0 || !(arr[row][i]==0 || arr[row][i]==pos) )continue;
        else{

            if(i==row){
                if(vis[pos][n]==1 || mat[row][i]!=0)continue;
                else vis[pos][n]=1;
            }

            if(i+row==(n-1)){
                if(vis[pos][n+1]==1)continue;
                else vis[pos][n+1]=1;
            }

            vis[pos][i]=1;
            mat[row][i]=pos;
            con[(row/2)*2 + i/3][pos]=1;
            if(printSudoku(row+1,pos))return true;
            con[(row/2)*2 + i/3][pos]=0;
            vis[pos][i]=0;
            mat[row][i]=0;

            if(i==row){
                vis[pos][n]=0;
            }

            if(i+row==(n-1)){
                vis[pos][n+1]=0;
            }

        
        }
    }
    return res;
}


bool Sudoku::isValidSudoku(int row,int pos){
    bool res=false;
    if(pos==n+1){
        total++;
        return true;
    }

    if(row==n){
        if(isValidSudoku(0,pos+1))return true;
        return false;
    }

    for(int i=0;i<n;i++){
        if( vis[pos][i]==1 || con[(row/2)*2 + i/3][pos]==1 || mat[row][i]!=0 || !(arr[row][i]==0 || arr[row][i]==pos) )continue;
        else{

            if(i==row){
                if(vis[pos][n]==1 || mat[row][i]!=0)continue;
                else vis[pos][n]=1;
            }

            if(i+row==(n-1)){
                if(vis[pos][n+1]==1)continue;
                else vis[pos][n+1]=1;
            }

            vis[pos][i]=1;
            mat[row][i]=pos;
            con[(row/2)*2 + i/3][pos]=1;
            if(isValidSudoku(row+1,pos))res= true;
            con[(row/2)*2 + i/3][pos]=0;
            vis[pos][i]=0;
            mat[row][i]=0;

            if(i==row){
                vis[pos][n]=0;
            }

            if(i+row==(n-1)){
                vis[pos][n+1]=0;
            }
        }
    }
    return res;
}

int main(){
    int n=6;
    Sudoku Obj(n);
    Obj.Reset();
    if(Obj.isValidSudoku(0,1))cout<<"\n"<<Obj.printTotal()<<" valid solution Exists";

    cout<<"\n";
    cout<<"\n";
    Obj.Reset();
    cout<<"Solution\n";
    if(!Obj.printSudoku(0,1)){
        cout<<"SUDOKU doesn't exist for this combination";
    }
    return 0;
}