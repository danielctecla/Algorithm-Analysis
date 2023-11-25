#include <bits/stdc++.h>

using namespace std;

#pragma pack(push, 1) // Asegura que las estructuras se alineen en 1 byte
struct BMPHeader {
    char signature[2];
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
};

struct BITMAPINFOHEADER {
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};
#pragma pack(pop)

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
    int width, option;
    
    ifstream file ("input.bmp", ios::binary );
    BMPHeader header;
    BITMAPINFOHEADER infoHeader;
    file.read(reinterpret_cast<char*>(&header), sizeof(BMPHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
    // Leer la información de la imagen BMP
    width = static_cast<int>(infoHeader.width);
    int height = static_cast<int>(infoHeader.height);
    // Mostrar información de lSa imagen
    cout << "Ancho de la imagen: " << width << " pixels" << endl;
    cout << "Altura de la imagen: " << height << " pixels" << endl;
    vector<vector<bitBMP>> matrix(width,vector<bitBMP>(width));
    
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

void rotate_divide_conquer(vector<vector<bitBMP>>& matrix, int n) {
    if (n <= 1) return;
    vector<vector<bitBMP>> a(n/2, vector<bitBMP>(n/2));
    vector<vector<bitBMP>> b(n/2, vector<bitBMP>(n/2));
    vector<vector<bitBMP>> c(n/2, vector<bitBMP>(n/2));
    vector<vector<bitBMP>> d(n/2, vector<bitBMP>(n/2));
    
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            a[i][j] = matrix[i][j];
            b[i][j] = matrix[i][j + n/2];
            c[i][j] = matrix[i + n/2][j];
            d[i][j] = matrix[i + n/2][j + n/2];
        }
    }
    
    rotate_divide_conquer(a, n/2);
    rotate_divide_conquer(b, n/2);
    rotate_divide_conquer(c, n/2);
    rotate_divide_conquer(d, n/2);
    
    for (int i = 0; i < n/2; ++i) {
        for (int j = 0; j < n/2; ++j) {
            matrix[i][j] = c[i][j];
            matrix[i][j + n/2] = a[i][j];
            matrix[i + n/2][j] = d[i][j];
            matrix[i + n/2][j + n/2] = b[i][j];
        }
    }
}