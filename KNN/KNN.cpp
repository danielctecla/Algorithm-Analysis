#include <bits\stdc++.h>

using namespace std;

/*bool notExist(float nm, float nm2,vector<vector<float>> knn){
    for(int i=0;i<knn.size();i++){
        if(knn[i][0] == nm && knn[i][1] == nm2) return false;
    }
    return true;
}

float coordx(){
    float temp = static_cast<float>(rand()) / RAND_MAX;
    temp *= 100;
    return temp;
} 
float coordy(){
    float temp = static_cast<float>(rand()) / RAND_MAX;
    temp *= 60;
    return temp;
}   

float coordy2(){
    float temp = static_cast<float>(rand()) / RAND_MAX;
    temp *= 60;
    return temp+40;
}*/

float Distance(float x, float y,float x2,float y2, int *a){
    (*a)++;
    return sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
}

int classification(vector<vector <float>> & vect,float x, float y,int k,int *a){
    vector<vector<float>> dist; (*a)++;
    int min_,n;(*a)++;
    n= vect.size();(*a)++;
    float vtemp,dist_,ctemp;(*a)++;

    (*a)++;
    for (int i=0; i<n; i++) {
        (*a)++;
        vector<float> temp;(*a)++;
        dist_ = Distance(x, y, vect[i][0], vect[i][1],a);(*a)++;
        temp.push_back(dist_);(*a)++;
        temp.push_back(vect[i][2]);(*a)++;
        dist.push_back(temp);(*a)++;
        (*a)++;
    }
    (*a)++;
    //sort
    (*a)++;
    for(int i=0;i<n-1;i++){
        (*a)++;
        min_ = i;(*a)++;
        (*a)++;
        for(int j = i+1; j<n ; j++){
            (*a)++;
            (*a)++;
            if(dist[j][0]<dist[min_][0]){
                min_ = j;(*a)++;
            }
            (*a)++;
        }
        (*a)++;
        vtemp = dist[i][0];(*a)++;
        ctemp = int(dist[i][1]);(*a)++;
        dist[i][0] = dist[min_][0];(*a)++;
        dist[i][1] = dist[min_][1];(*a)++;
        dist[min_][0] = vtemp;(*a)++;
        dist[min_][1] = ctemp;(*a)++;
        (*a)++;
    }
    (*a)++;

    cout<<"Vecinos más cercanos al punto: "<<endl;
    for (int i=0;i<k;i++)
        cout<<dist[i][0] << "," << dist[i][1]<<endl;
    
    int class0 = 0, class1 = 0;(*a)++;
    (*a)++;
    for (int i = 0; i < k; ++i) {
        (*a)++;
        (*a)++;
        if (dist[i][1] == 0) {
            class0++;(*a)++;
        } else {
            class1++;(*a)++;
        }
        (*a)++;
    }
    (*a)++;

    (*a)++;
    return (class0 > class1) ? 0 : 1;
}

float nm,nm2;
int opt,k;

int main(){
    srand(time(NULL));
    vector<vector<float>> knn;
    float x,y;
    int classif,a;
    /*
    Código para que se generaran los 100 datos;
    for(int i=0;i<50;i++){
        vector<float> g1g2;
        do{
            nm = coordx();
            nm2 = coordy();
        }while(!notExist(nm,nm2,knn));
        g1g2.push_back(nm);
        g1g2.push_back(nm2);
        g1g2.push_back(0);
        knn.push_back(g1g2);
    }
    for(int i=0;i<50;i++){
        vector<float> g1g2;
        do{
            nm = coordx();
            nm2 = coordy2();
        }while(!notExist(nm,nm2,knn));
        g1g2.push_back(nm);
        g1g2.push_back(nm2);
        g1g2.push_back(1);
        knn.push_back(g1g2);
    }

    ofstream csvFile("output.csv");
    if (!csvFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    for (const auto& vec : knn) {
        cout<<vec[0] << "," << vec[1] << "," << vec[2] << endl;
        csvFile << vec[0] << "," << vec[1] << ","<< vec[2] << endl;
    }
    csvFile.close();*/
    ifstream csvFile("clase0.csv");
    string line;
    while (getline(csvFile, line)) {
        stringstream lineStream(line);
        string cell;
        vector<float> row;  // Create a new row vector for each line

        while (getline(lineStream, cell, ',')) {
            float value = stof(cell);
            row.push_back(value);
        }

        knn.push_back(row);
    }
    csvFile.close();

    ifstream csvFile2("clase1.csv");
    while (getline(csvFile2, line)) {
        stringstream lineStream(line);
        string cell;
        vector<float> row;  // Create a new row vector for each line

        while (getline(lineStream, cell, ',')) {
            float value = stof(cell);
            row.push_back(value);
        }

        knn.push_back(row);
    }
    csvFile2.close();
    
    /*for (const auto& vec : knn)
        cout<<vec[0] << "," << vec[1] << "," << vec[2] << endl;
    */
    do{
        int k = 5;
        cout<<"1.add point\n"<<"0. Exit"<<endl;
        cin>>opt;
        if(opt){
            cout<<"Ingrese la coordenada x y y separado por un espacio."<<endl;
            cin>>x>>y;
            classif = classification(knn,x,y,k,&a);
            cout<<"\n\n";
            cout<<"El punto "<<x<<" "<<y<<" es de la clase: "<<classif<<endl;
        }
    }while(opt);
}