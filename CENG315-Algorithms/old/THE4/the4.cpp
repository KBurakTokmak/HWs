#include "the4.h"

int find_row_elements_count(char**& arr,int row,int i){
    int count=0;
    for (int j=0;j<row;j++){
        if(arr[j][i]!='-') count++;
        else{
            //empty row
        }
    }
    return count;
}

bool check_same_elements(char**& arr1, char**& arr2, int nrow, int col1, int col2 ){
    int count=0;
    char temp_arr1[nrow]={0};
    char temp_arr2[nrow]={0};
    for(int i=0;i<nrow;i++){
        temp_arr1[i]=arr1[i][col1];
    }
    for(int i=0;i<nrow;i++){
        temp_arr2[i]=arr2[i][col2];
    }
    
    for(int i=0;i<nrow;i++){
        for(int j=0;j<nrow;j++){
            if(temp_arr1[i]==temp_arr2[j]){
                temp_arr1[i]='\0';
                temp_arr2[j]='\0';
                count++;
                break;
            }
            else{
            }
        }   
            
    }
    if(count==nrow){
        return true;
    }
    else{ 
        return false;
    }
}




int out_of_place_count(char**& arr1, char**& arr2, int nrow, int col1, int col2 ){
    int count=0;
    for(int i=0;i<nrow;i++){
        if(arr1[i][col1]!=arr2[i][col2]){
            count++;
        }
        else{
            
        }
    }
    return count;
}

int arrange_cost(char**& arr1, char**& arr2, int nrow, int col1, int col2 ){
    int count=0;
    for(int i=0;i<nrow;i++){
        if(arr1[i][col1]!=arr2[i][col2]){
            if(arr1[i][col1]!='-'&&arr2[i][col2]!='-'){
                count++;
            }
            else{
                count+=2;
            }
        }
        else{
            
        }
    }
    return count;
}

int find_min_cost(int a,int b,int c){
    if(a<=b&&a<=c) return a;
    else if(b<=a&&b<=c) return b;
    else if(c<=a&&c<=b) return c;
    return 0;
}


int find_changing_cost(char**& arr1, char**& arr2, int nrow, int i,int j,int**& mem){
    if(check_same_elements(arr1, arr2, nrow, i-1, j-1)){//elements same reorder
        std::cout<<"GÖRDÜM EŞİTLİĞİ REİS"<<std::endl;
        return out_of_place_count(arr1, arr2, nrow, i-1, j-1)+mem[i-1][j-1];//reorder cost
        
    }
    else{
        return (arrange_cost(arr1, arr2, nrow, i-1, j-1))+mem[i-1][j-1];//rearrrange cost
        
    }
}


int dp_sln(char**& arr1, char**& arr2, int nrow, int ncol1, int ncol2, int**& mem){ //dynamic programming

    //your code here
    int row_elements_count=0;
    int cols_left=ncol1;
    int temp_cost=0;
    //std::cout<<"BAŞLADIM"<<std::endl;
    mem[0][0]=0;//no columns
    for (int i=1;i<ncol2+1;i++){ //find insertion costs of box 2 columns
        row_elements_count=find_row_elements_count(arr2,nrow,i-1);
        mem[0][i]=row_elements_count+mem[0][i-1];
    }
    
    for (int i=1;i<ncol1+1;i++){//find deletion costs of box 1 columns
         row_elements_count=find_row_elements_count(arr1,nrow,i-1);
         mem[i][0]=row_elements_count+mem[i-1][0];
    }
    
    for(int i=1;i<ncol1+1;i++){
        for(int j=1;j<ncol2+1;j++){
            temp_cost=find_changing_cost(arr1,arr2,nrow,i,j,mem);
            temp_cost=find_min_cost(temp_cost,mem[i][j-1]+(mem[0][j]-mem[0][j-1]),mem[i-1][j]+(mem[i][0]-mem[i-1][0]));
            mem[i][j]=temp_cost;
        }
    }
    
    


    return mem[ncol1][ncol2]; 
}

