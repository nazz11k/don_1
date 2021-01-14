#include "libich.h"

int main() {
    int** tabl=new int*[10];
    for(int i=0; i<10; i++){
        tabl[i]=new int[10];
    }
    generator(tabl);
    tabl=mir(tabl);
    sorter(tabl);
}
