#include <bits/stdc++.h>

using namespace std;

void fill_vect(vector<int> &bt){
    int k = bt.size();
    bt.push_back(bt[k-1]+2);
}

void showVect(vector<int> &bt) {
    cout << "[";
    for (int i = 0; i < bt.size(); i++) {
        cout << bt[i];
        if (i < bt.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}


int iterativo_Arr(vector<int> &bt,int k,int *a){
    int low = 0,high = bt.size(),i,j;
    (*a)++;
    (*a)++;
    (*a)++;
    (*a)++;

    high -= 1;(*a)++;

    while(low <= high){
        (*a)++;
        i = low+(high-low)/3;(*a)++;
        j = low+(2*(high-low))/3;(*a)++;
        
        (*a)++;
        if (bt[j]<k){
            low = j+1;
        }else if(bt[i]>k){
            (*a)++;
            high = i-1;(*a)++;
        }else if(bt[i]<k && bt[j]>k){
            (*a)++;
            (*a)++;
            (*a)++;
            (*a)++;
            low = i+1;(*a)++;
            high = j-1;(*a)++;
        }else if(bt[i] == k){
            (*a)++;
            (*a)++;(*a)++;
            (*a)++;
            (*a)++;
            return i;
        }else if(bt[j] == k){
            (*a)++;
            (*a)++;(*a)++;
            (*a)++;
            (*a)++;
            (*a)++;
            return j;
        }
    }
    //False, the value doesn't exist
    (*a)++;
    return -1;
}

int recursivo_Arr(vector<int> &bt,int low,int high, int k,int *a){
    (*a)++;
    if(low<=high){
        int i = low + (high-low)/3;(*a)++;
        int j = low + (2*(high-low))/3;(*a)++;

        (*a)++;
        if(bt[j]<k){
            (*a)++;
            return recursivo_Arr(bt,j+1,high,k,a);
        }else if(bt[i]>k){
            (*a)++;
            (*a)++;
            return recursivo_Arr(bt,low,i-1,k,a);
        }else if(bt[i]<k && bt[j]>k){
            (*a)++;
            (*a)++;
            (*a)++;
            (*a)++;
            (*a)++;
            return recursivo_Arr(bt,i+1,j-1,k,a);
        }else if(bt[i] == k){
            (*a)++;
            (*a)++;(*a)++;
            (*a)++;
            (*a)++;
            return i;
        }else if(bt[j] == k){
            (*a)++;
            (*a)++;(*a)++;
            (*a)++;
            (*a)++;
            (*a)++;
            return j;
        }
        (*a)++;
    }
    (*a)++;
    (*a)++;
    return -1;
    
    
}

int main(){
    
    vector<int> btArreglo = {2};
    //
    int index,value,a;

    char csv[]="bigOIterativo.csv";
    FILE *pOutput = fopen(csv,"w");
    
    cout<<"Iterativo"<<"\n\n";
    for(int i = 0;i<7;i++){
        //cout<<"\n";
        a = 0;
        fill_vect(btArreglo);

        if(i<50)
            showVect(btArreglo);

        value = btArreglo.size();
        value = btArreglo[value-1];
        index = iterativo_Arr(btArreglo,value,&a);
        if(index != -1)
            cout<<"El valor "<<value<<" se encuentra en el index ["<<index<<"]"<<endl;
        else
            cout<<"El valor no se encuentra en el arreglo"<<endl;
            
        fprintf(pOutput,"%d,%d\n",btArreglo.size(),a);

    }
    
    pOutput = fopen(csv,"r");
    fclose(pOutput);

    char Excel[]="bigORecursivo.csv";
    FILE *pOutput_ = fopen(Excel,"w");
    btArreglo = {2};
    cout<<"\n\n";
    cout<<"Recursivo"<<"\n\n";
    for(int i=0;i<7;i++){
        //cout<<"\n";
        a = 0;
        fill_vect(btArreglo);
        if(i<50)
            showVect(btArreglo);

        value = btArreglo.size();
        value = btArreglo[value-1];
        index = recursivo_Arr(btArreglo,0,btArreglo.size()-1,value/2,&a);
        if(index != -1)
            cout<<"El valor "<<value/2<<" se encuentra en el index ["<<index<<"]"<<endl;
        else
            cout<<"El valor no se encuentra en el arreglo"<<endl;
        fprintf(pOutput_,"%d,%d\n",btArreglo.size(),a);

    }
    pOutput_ = fopen(Excel,"r");
    fclose(pOutput_);
    
}