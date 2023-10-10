#include <bits/stdc++.h>



using namespace std;

int Perfecto(int n,int *a){
    /*int mitad;(*a)++;
    mitad = n/2;(*a)++;*/
    int isP; (*a)++;
    isP = 0;(*a)++;
    (*a)++;
    for(int i=1;i<n;i++){
        (*a)++;
        (*a)++;
        if(n%i == 0){
            isP += i;(*a)++;
        }
        (*a)++;
    }

    (*a)++;
    if(isP==n){
        (*a)++;
        return 1;
    }
    
    (*a)++;
    return 0;
}

void MostrarPerfectos(int n, int *a){
    int numP = 0;(*a)++;
    (*a)++;
    for(int i = 2;numP!=n;i++){
        (*a)++;
        (*a)++;
        if(Perfecto(i,a)){
            cout <<i<<endl;(*a)++;
            numP++;(*a)++;
        }
        (*a)++;
    }
    (*a)++;
}

void only_perfect(){
    int n,a;
    char excel[]="muestra.csv";
    FILE *pSalida = fopen(excel,"w");
    for(int i=2;i<250;i++){
        a = 0;
        if(Perfecto(i,&a))
            cout<<"["<<i<<"]->"<<" Yes"<<endl;
        else
            cout<<"["<<i<<"]->"<<" No"<<endl;
            

        fprintf(pSalida,"%d,%d\n",i,a);
        cout<<"\n";
    }

    pSalida = fopen(excel,"r");
    fclose(pSalida);
}

void all_perfects(){
    int n,a;
    char excel[]="showP.csv";
    FILE *pSalida = fopen(excel,"w");
    cin >> n;
    
    for(int i=1;i<=n;i++){
        a = 0;
        MostrarPerfectos(i,&a);
        fprintf(pSalida,"%d,%d\n",i,a);
        cout<<"\n";
    }

    pSalida = fopen(excel,"r");
    fclose(pSalida);
}

int main(){
    //only_perfect();
    all_perfects();
}