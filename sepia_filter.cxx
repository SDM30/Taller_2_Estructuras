#include "sepia_filter.h"

void SepiaFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #6: Implementar el filtro sepia.
    for (int i = 0; i < image.getHeight(); ++i) {
        for (int j = 0; j < image.getWidth(); ++j) {
            int red = image.getRed(i, j);
            int green = image.getGreen(i, j);
            int blue = image.getBlue(i, j);

            int sepiaRed = std::min(255, static_cast<int>(0.393 * red + 0.769 * green + 0.189 * blue));
            int sepiaGreen = std::min(255, static_cast<int>(0.349 * red + 0.686 * green + 0.168 * blue));
            int sepiaBlue = std::min(255, static_cast<int>(0.272 * red + 0.534 * green + 0.131 * blue));

            pixels[i][j][0] = sepiaRed;   // Canal R
            pixels[i][j][1] = sepiaGreen; // Canal G
            pixels[i][j][2] = sepiaBlue;  // Canal B
        }
    }
    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
