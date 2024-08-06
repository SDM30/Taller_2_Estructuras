#include "negative_filter.h"

void NegativeFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #5: Implementar el filtro negativo (NEGATIVE).

    //-----------------------------------------------------------------------
    image.setPixels(pixels);
}
