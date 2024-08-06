#include "sepia_filter.h"

void SepiaFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #6: Implementar el filtro sepia.

    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
