#include <bits/stdc++.h>

int main() {
    // Nombre del archivo que deseas leer
    std::string filename = "longest_common_subsequence.cpp";

    // Intenta abrir el archivo
    std::ifstream file(filename);

    // Verifica si el archivo se abrió correctamente
    if (file.is_open()) {
        // Lee el contenido del archivo en un stringstream
        std::stringstream buffer;
        buffer << file.rdbuf();

        // Almacena el contenido del archivo en una cadena (string)
        std::string fileContent = buffer.str();

        // Imprime el contenido del archivo
        std::cout << "Contenido del archivo:\n" << fileContent << std::endl;
        
        for(int i = 0; i < 10; i++){
            std::cout<<fileContent[i];
        }

        // Cierra el archivo después de lee rlo
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
    }
    
    // Almacena el contenido del archivo en una cadena (string)

    return 0;
}
