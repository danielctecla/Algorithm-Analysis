#include <bits/stdc++.h>

using namespace std;

struct bitBMP{
    char red;
    char green;
    char blue;
};

void createMatrix (char *arreglo, streampos tam,vector<vector<bitBMP>> &matrix, int &width);
void descomponerB (char* arreglo, streampos tam);
void exportImg(vector<vector<bitBMP>> &matrix,int &width, streampos tam,char *arreglo);
void seeMatrix(vector<vector<bitBMP>> &matrix,int &width);
void rotateMatrix(vector<vector<bitBMP>> & matrix);
void rotate_divide_conquer(vector<vector<bitBMP>>& matrix, int size);

int main (){
    int width = 8, option;
    vector<vector<bitBMP>> matrix(width,vector<bitBMP>(width));
    ifstream file ("input.bmp", ios::binary );

    if (file.is_open()){
        file.seekg(0, ios::end);
        streampos tam = file.tellg();
        file.seekg(0, ios::beg);

        char* arreglo = new char[tam];

        cout << "El tamano del archivo es: " << tam << " bytes." << endl;
        file.read(arreglo, tam);
        
        createMatrix(arreglo,tam,matrix,width);
        //seeMatrix(matrix,width);
        cout<<"1. Brute Force"<<endl;
        cout<<"2. Divide and Conquer"<<endl;
        cout<<"Option: ";
        cin>>option;
        if(option == 1) rotateMatrix(matrix);
        else rotate_divide_conquer(matrix,matrix.size());
        exportImg(matrix,width,tam,arreglo);

        file.close();
        delete[] arreglo;
    }else{
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}

void createMatrix (char *arreglo, streampos tam,vector<vector<bitBMP>> &matrix, int &width){
    int ref = 54;
    for(int i = width - 1;  i >= 0 ; i--){
        for(int j = 0; j < width ; j++){
            matrix[i][j].red = arreglo[ref];
            matrix[i][j].green = arreglo[ref + 1];
            matrix[i][j].blue = arreglo[ref + 2];  // Swap red and blue
            ref += 3;
        }
    }
}

void seeMatrix (vector<vector<bitBMP>> &matrix,int &width){
    int cont = 54;
    for(int i = width - 1;  i >= 0 ; i--){
        for(int j = 0; j < width ; j++){
            cout<< cont <<" "<<matrix[i][j].red<<" "<<matrix[i][j].green<<" "<<matrix[i][j].blue<<endl;
            cont += 3;
        }
    }
}

void exportImg(vector<vector<bitBMP>> &matrix,int &width, streampos tam,char *arreglo){
    int ref = 54;
    char* new_image = new char[tam];
    for(int i = 0; i < ref ; i++) new_image[i] = arreglo[i];

    for(int i = width - 1;  i >= 0 ; i--){
        for(int j = 0; j < width ; j++){
            new_image[ref] = matrix[i][j].red;
            new_image[ref + 1] = matrix[i][j].green;
            new_image[ref + 2] = matrix[i][j].blue;
            ref += 3;
        }
    }

    //for(int i = 54 ; i < tam ; i += 3) cout<< i <<" "<<new_image[i]<<" "<<new_image[i+1]<<" "<<new_image[i+2]<<endl;
    
    ofstream outputFile("input.bmp", ios::binary);
    outputFile.write(new_image, tam);
    outputFile.close();

    delete[] new_image;
}

void rotateMatrix(vector<vector<bitBMP>> & matrix){
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            bitBMP temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = temp;
        }
    }
}

/*This a function to see how the char array works*/
void descomponerB (char* arreglo, streampos tam){
    
    char* arregloB = new char[tam];
    for(int i = 0; i < tam ; i++) arregloB[i] = arreglo[i];

    for(int i = 54 ; i < tam ; i += 3){
        cout<< i <<" "<<arregloB[i]<<" "<<arregloB[i+1]<<" "<<arregloB[i+2]<<endl;
        //arregloB[i + 2] = 0; //rojo
        arregloB[i + 1] = 0; //verde
        arregloB[i] = 0; //azul
    }

    ofstream outputFile("output_B.bmp", ios::binary);
    outputFile.write(arregloB, tam);
    outputFile.close();

    delete[] arregloB;
}

void rotate_divide_conquer(vector<vector<bitBMP>>& matrix, int size) {
    if (size <= 1) {
        return;
    }

    // Dividir la submatriz en cuatro partes
    vector<vector<bitBMP>> a(size/2, vector<bitBMP>(size/2));
    vector<vector<bitBMP>> b(size/2, vector<bitBMP>(size/2));
    vector<vector<bitBMP>> c(size/2, vector<bitBMP>(size/2));
    vector<vector<bitBMP>> d(size/2, vector<bitBMP>(size/2));

    for (int i = 0; i < size/2; ++i) {
        for (int j = 0; j < size/2; ++j) {
            a[i][j] = matrix[i][j];
            b[i][j] = matrix[i][j + size/2];
            c[i][j] = matrix[i + size/2][j];
            d[i][j] = matrix[i + size/2][j + size/2];
        }
    }

    // Rotar las submatrices recursivamente
    rotate_divide_conquer(a, size/2); //esquina superior izquierda
    rotate_divide_conquer(b, size/2); //esquina superior derecha
    rotate_divide_conquer(c, size/2); //esquina inferior izquierda
    rotate_divide_conquer(d, size/2); //esquina inferior derecha

    // Combinar las submatrices rotadas
    for (int i = 0; i < size/2; ++i) {
        for (int j = 0; j < size/2; ++j) {
            matrix[i][j] = c[i][j];
            matrix[i][j + size/2] = a[i][j];
            matrix[i + size/2][j] = d[i][j];
            matrix[i + size/2][j + size/2] = b[i][j];
        }
    }
}