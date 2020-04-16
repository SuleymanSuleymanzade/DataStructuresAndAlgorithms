#include<iostream>
using namespace std;

int mx[6][4] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {1, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
};

void print_mx(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            cout<<mx[i][j]<<" ";
        }
        cout<<endl;
    }
}

int area = 0;

void flood_fill(int row, int col){
    if(row < 0 || col < 0 || row >= 6 || col >= 4)
        return;
    if(mx[row][col] == 1 || mx[row][col] == 2)
        return;
    
    area += 1;
    mx[row][col] = 2;
    //cout<<row<<" "<<col<<endl; 

    flood_fill(row - 1, col);
    flood_fill(row + 1, col);
    flood_fill(row, col - 1);
    flood_fill(row, col + 1);

}

int get_max(){
    int mx_temp = -1e9;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j ++){
            flood_fill(i, j);
            mx_temp = max(mx_temp, area);
            area = 0;
        }
    }
    return mx_temp;
}


int main(int argc, char* argv[]){

    cout<<get_max()<<endl;

return 0;
}
