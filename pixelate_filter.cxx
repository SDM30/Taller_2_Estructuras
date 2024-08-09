#include "pixelate_filter.h"

void PixelateFilter::apply(Image& image, int blockSize) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #7: Implementar el filtro pixelar (PIXELATE).

    for (int i = 0; i < image.getHeight();  i += blockSize) {
        for (int j = 0; j < image.getWidth(); j += blockSize) {

            int contador = 0;
            int avgR = 0, avgG = 0, avgB = 0;


            for(int x = 0; x < blockSize; x++){
                for(int y = 0; y < blockSize; y++){

                    int posX = (i + x) % image.getHeight();
                    int posY = (j + y) % image.getWidth();
                    avgR += pixels[posX][posY][0];
                    avgG += pixels[posX][posY][1];
                    avgB += pixels[posX][posY][2];

                    contador ++;                    
                }

            }

            if(contador != 0){
                avgR /= contador;
                avgG /= contador;
                avgB /= contador;
            }

            for(int x = 0; x < blockSize; x++){
                for(int y = 0; y < blockSize; y++){
                    
                    int posX = (i + x) % image.getHeight();
                    int posY = (j + y) % image.getWidth();
                    pixels[posX][posY][0] = avgR;
                    pixels[posX][posY][1] = avgG;
                    pixels[posX][posY][2] = avgB;

                }

            }

        }
    }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
