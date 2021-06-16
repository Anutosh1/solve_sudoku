#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int total=0,mat[100][100],vis[100][100];
int arr[6][6]={{6,5,4,3,2,1},{5,0,0,0,0,0},{4,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};

bool printSudoku(int n,int row,int pos){
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
        if(printSudoku(n,0,pos+1))return true;
        return false;
    }

    for(int i=0;i<n;i++){
        if(vis[pos][i]==1 || mat[row][i]!=0 || !(arr[row][i]==0 || arr[row][i]==pos) )continue;
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
            if(printSudoku(n,row+1,pos))return true;
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

bool isValidSudoku(int n,int row,int pos){
    bool res=false;
    if(pos==n+1){
        total++;
        return true;
    }

    if(row==n){
        if(isValidSudoku(n,0,pos+1))return true;
        return false;
    }

    for(int i=0;i<n;i++){
        if(vis[pos][i]==1 || mat[row][i]!=0 || !(arr[row][i]==0 || arr[row][i]==pos) )continue;
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
            if(isValidSudoku(n,row+1,pos))res= true;
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

    total=0;
    if(isValidSudoku(6,0,1))cout<<"\n"<<total<<" valid solution Exists";

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mat[i][j]=0;
            vis[i][j]=0;
        }
    }
    cout<<"\n";
    cout<<"\n";

    cout<<"Solution\n";
    if(!printSudoku(6,0,1)){
        cout<<"SUDOKU doesn't exist for this combination";
    }
    return 0;
}