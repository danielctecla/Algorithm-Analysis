#include <FreeImage.h>

int main() {
    // Inicializar FreeImage
    FreeImage_Initialise();

    // Cargar la imagen BMP
    FIBITMAP* bmpImage = FreeImage_Load(FIF_BMP, "output.bmp", BMP_DEFAULT);

    if (!bmpImage) {
        fprintf(stderr, "Error al cargar la imagen BMP\n");
        FreeImage_DeInitialise();
        return 1;
    }

    // Guardar la imagen como JPG
    if (FreeImage_Save(FIF_JPEG, bmpImage, "output.jpg", JPEG_QUALITYGOOD)) {
        printf("Conversión exitosa\n");
    } else {
        fprintf(stderr, "Error al guardar la imagen como JPG\n");
    }

    // Liberar la memoria
    FreeImage_Unload(bmpImage);
    FreeImage_DeInitialise();

    return 0;
}
