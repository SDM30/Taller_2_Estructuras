#include "blur_filter.h"

BlurFilter::BlurFilter() {
    kernel = {
        {{1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}},  // Kernel para canal R
        {{1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}},  // Kernel para canal G
        {{1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1}}   // Kernel para canal B
    };
}

void BlurFilter::apply(Image& image) {
    int height = image.getHeight(); // 2
    int width = image.getWidth();   // 2
    std::vector<std::vector<std::vector<int>>> newPixels
    (height, std::vector<std::vector<int>>(width, std::vector<int>(3, 0))); // (n*m)
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels(); // Obtener los píxeles de la imagen  // 2
    //-----------------------------------------------------------------------
    // TODO #4: Implementar el filtro de desenfoque (BLUR).
    int kernelSize = 7; // 1
    int offset = kernelSize / 2;    // 2
     
    for(int i = 0; i < height; ++i) { // 1 + n + 1 + n
        for(int j = 0; j < width; ++j) { // n * (1 + m + 1 + m)
            std::vector<int> sum(3, 0); // Suma de colores RGB  // 3(n*m)
            int conta = 0;  // n*m
            // Aplicar el kernel al píxel (i, j)
            for(int k = -offset; k <= offset; ++k) {    // (n*m)*[1 + (7/2) + 1 + (7/2)]
                for(int l = -offset; l <= offset; ++l) {//[n*m*(7/2)]*[1 + (7/2) + 1 + (7/2)]
                    int ni = i + k; //[n*m*(7/2)]
                    int nj = j + l; //[n*m*(7/2)]
                    // Verificar si (ni, nj) está dentro de los límites de la imagen
                    if(ni >= 0 && ni < height && nj >= 0 && nj < width) {               //[n*m*(7/2)]
                        for(int c = 0; c < 3; ++c) { // Para cada canal de color (RGB)  //[n*m*(7/2)]*(1 + 4 + 3)
                            int weight = kernel[c][k + offset][l + offset]; // Tomar el peso del kernel // [n*m*(7/2)*3]*6
                                                                            //correspondiente al canal 
                            sum[c] += pixels[ni][nj][c] * weight;   //[n*m*(7/2)*3]*7
                        }
                        conta += kernel[0][k + offset][l + offset]; // Usar el peso del     //[n*m*(7/2)*3]*7
                                                                    //canal R para la cuenta 
                    }
                }
            }
            // Normalizar el valor y asignar al nuevo píxel
            if (conta != 0) {   //n*m
                for(int c = 0; c < 3; ++c) {    //8(n*m)
                    newPixels[i][j][c] = sum[c] / conta; //15(n*m) 
                }
            } else {
                newPixels[i][j] = pixels[i][j]; // Mantener el pixel    //  5(n*m)
                                                //original si conta es 0
            }
        }
    }

    image.setPixels(newPixels); //2
    //-----------------------------------------------------------------------
}

