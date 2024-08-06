#include "pixelate_filter.h"

void PixelateFilter::apply(Image& image, int blockSize) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #7: Implementar el filtro pixelar (PIXELATE).

    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
