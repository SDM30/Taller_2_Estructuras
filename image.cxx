#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "image.h"
#include <stdexcept>
#include <algorithm>

Image::Image(const std::string& filename) {
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &n, 3); // Cargar imagen RGB
    if (!data) {
        throw std::runtime_error("No se pudo cargar la imagen: " + filename);
    }

    pixels.resize(height, std::vector<std::vector<int>>(width, std::vector<int>(3))); // 3 canales: R, G, B
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            pixels[i][j][0] = data[(i * width + j) * 3 + 0]; // Canal R
            pixels[i][j][1] = data[(i * width + j) * 3 + 1]; // Canal G
            pixels[i][j][2] = data[(i * width + j) * 3 + 2]; // Canal B
        }
    }
    stbi_image_free(data);
}

Image::~Image() {
    // No hay necesidad de liberar manualmente nada ya que `pixels` es un vector
}

std::vector<std::vector<std::vector<int>>> Image::getPixels(){
    return pixels;
}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}

void Image::setPixels(std::vector<std::vector<std::vector<int>>> newPixels){
    this->pixels = newPixels;
}

void Image::save(const std::string& filename) const {
    std::vector<unsigned char> data(height * width * 3);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int c = 0; c < 3; ++c) {
                data[(i * width + j) * 3 + c] = static_cast<unsigned char>(pixels[i][j][c]);
            }
        }
    }

    if (filename.substr(filename.find_last_of(".") + 1) == "png") {
        stbi_write_png(filename.c_str(), width, height, 3, data.data(), width * 3);
    } else if (filename.substr(filename.find_last_of(".") + 1) == "jpg") {
        stbi_write_jpg(filename.c_str(), width, height, 3, data.data(), 100);
    } else {
        throw std::runtime_error("Formato de archivo no soportado: " + filename);
    }
}

int Image::getRed(int x, int y){
    return pixels[x][y][0];
}

int Image::getGreen(int x, int y){
  return pixels[x][y][1];
}

int Image::getBlue(int x, int y){
  return pixels[x][y][2];
}
