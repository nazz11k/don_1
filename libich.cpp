#include "libich.h"

void generator(int** tabl){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabl[i][j]=(i+1)*(j+1);
        }
    }
    outer(tabl, "Original matrix:");
}

int** mir(int** tabl){
    int** tabl_mir=new int*[10];
    for(int i=0; i<10; i++){
        tabl_mir[i]=new int[10];
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tabl_mir[i][j]=tabl[9-j][9-i];
        }
    }
    outer(tabl_mir, "Mirrored matrix:");
    return tabl_mir;
}

void sorter(int** tabl){
    int diagonal[10];
    for(int i=0; i<10;i++){
        diagonal[i]=tabl[i][9-i];
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10-i-1; j++){
            if(diagonal[j]>diagonal[j+1]){
                int tmp1=diagonal[j];
                int* tmp=tabl[j];
                diagonal[j]=diagonal[j+1];
                tabl[j]=tabl[j+1];
                diagonal[j+1]=tmp1;
                tabl[j+1]=tmp;
            }
        }
    }
    outer(tabl, "Sorted matrix:");
}

void outer(int** tabl, string name){
    cout<<endl<<name<<endl;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout<<setw(4)<<tabl[i][j];
        }
        cout<<endl;
    }
}