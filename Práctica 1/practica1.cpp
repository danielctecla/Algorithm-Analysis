#include <bits/stdc++.h>

using namespace std;

void llenado(int *array,int n){
    srand(time(NULL));

    for(int i=0;i<n;i++)
        array[i] = rand()%(3*n+1); //Números aleatorios hasta 3n
        //array[i] = i; //Para el peor caso
        //array[i] = 1; //mejor caso
    }

void imprimir(int *array,int n){
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
}

void p1(int n,int *array,int *a){
    
    int li= n/2; (*a)++;
    int ls; (*a)++;
    (*a)++;
    for(int i=0;i<li;i++){
        (*a)++;
        (*a)++;
        for(int j=li;j<n;j++){
            (*a)++;
            if(array[i] == array[j]){
                (*a)++;
                li = i; (*a)++;
                ls = j; (*a)++;
                cout<<"\n"<<array[li]<<"->"<<"["<<li<<"]["<<ls<<"]"<<endl; (*a)++;
                (*a)++;
                return; 
            }
            (*a)++;
            (*a)++;
        }
        (*a)++;
        (*a)++;
    }
    (*a)++;
}



int main(){
    int array[50000];
    int n,a;
    cin>>n;

    char excel[]="muestra.csv";
    FILE *pSalida = fopen(excel,"w");
        

    for(int i=2;i<=n;i++){
        a = 0;
        llenado(array,i);
        imprimir(array,i); 
        p1(i,array,&a);
        fprintf(pSalida,"%d,%d\n",i,a);
        cout<<"\n";
    }
    
    pSalida = fopen(excel,"r");

    fclose(pSalida);
}