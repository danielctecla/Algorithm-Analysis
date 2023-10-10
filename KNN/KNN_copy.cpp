#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>

using namespace std;

float Distance(float x, float y, float x2, float y2, int *a) {
    (*a)++;
    return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
}

int classification(vector<vector<float>> &vect, float x, float y, int k, int *a, int n) {
    vector<vector<float>> dist;
    (*a)++;
    int min_;
    (*a)++;
    float vtemp, dist_, ctemp;
    (*a)++;

    (*a)++;
    for (int i = 0; i < n; i++) {
        (*a)++;
        vector<float> temp;
        (*a)++;
        dist_ = Distance(x, y, vect[i][0], vect[i][1], a);
        (*a)++;
        temp.push_back(dist_);
        (*a)++;
        temp.push_back(vect[i][2]);
        (*a)++;
        dist.push_back(temp);
        (*a)++;
        (*a)++;
    }
    (*a)++;
    //sort
    (*a)++;
    for (int i = 0; i < n - 1; i++) {
        (*a)++;
        min_ = i;
        (*a)++;
        (*a)++;
        for (int j = i + 1; j < n; j++) {
            (*a)++;
            (*a)++;
            if (dist[j][0] < dist[min_][0]) {
                min_ = j;
                (*a)++;
            }
            (*a)++;
        }
        (*a)++;
        vtemp = dist[i][0];
        (*a)++;
        ctemp = int(dist[i][1]);
        (*a)++;
        dist[i][0] = dist[min_][0];
        (*a)++;
        dist[i][1] = dist[min_][1];
        (*a)++;
        dist[min_][0] = vtemp;
        (*a)++;
        dist[min_][1] = ctemp;
        (*a)++;
        (*a)++;
    }
    (*a)++;

    cout << "Vecinos más cercanos al punto: " << endl;
    for (int i = 0; i < k; i++)
        cout << dist[i][0] << "," << dist[i][1] << endl;

    int class0 = 0, class1 = 0;
    (*a)++;
    (*a)++;
    for (int i = 0; i < k; ++i) {
        (*a)++;
        (*a)++;
        if (dist[i][1] == 0) {
            class0++;
            (*a)++;
        } else {
            class1++;
            (*a)++;
        }
        (*a)++;
    }
    (*a)++;

    (*a)++;
    return (class0 > class1) ? 0 : 1;
}

int main() {
    srand(time(NULL));
    vector<vector<float>> knn;
    int classif, a;

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

    int k = 5;

    char excel[] = "showP.csv";
    FILE *pSalida = fopen(excel, "w");
    if (pSalida == NULL) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    for (int i = 6; i <= 100; i++) {
        a = 0;
        classif = classification(knn, 50, 50, k, &a, i);
        cout << "\n\n";
        fprintf(pSalida, "%d,%d\n", i, a);
    }
    fclose(pSalida);
    return 0;
}
