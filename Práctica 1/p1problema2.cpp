#include <bits/stdc++.h>

using namespace std;

int euclides(int m, int n,int *a){
    int r; (*a)++;
    while(n!=0){
        (*a)++;
        r = m%n; (*a)++;
        m = n; (*a)++;
        n = r; (*a)++;
    }
    (*a)++;

    (*a)++;
    return m; 
}

int main(){
    int m,a;
    int result;
    char excel[]="prom2.csv";
    FILE *pSalida = fopen(excel,"w");

    srand(time(NULL));
    for(int i = 0;i<10000;i+=10){
        a = 0;
        m = 1+rand()%10001;
        result = euclides(m,i,&a);
        cout <<m<<" "<<i<<" mcd: "<<result<<endl;
        fprintf(pSalida,"%d,%d\n",i,a);
    }

    pSalida = fopen(excel,"r");

    fclose(pSalida);
}