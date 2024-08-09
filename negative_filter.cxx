#include "negative_filter.h"

void NegativeFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #5: Implementar el filtro negativo (NEGATIVE).
    for (int i = 0; i < image.getHeight(); ++i) {
        for (int j = 0; j < image.getWidth(); ++j) {
            pixels[i][j][0] = 255 - pixels[i][j][0];   // Canal R
            pixels[i][j][1] = 255 - pixels[i][j][1]; // Canal G
            pixels[i][j][2] = 255 - pixels[i][j][2];  // Canal B
        }
    }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
