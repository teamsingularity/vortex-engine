#include "png.hpp"
#include <spng.h>
#include <stdio.h>
#include <iostream>

image_t png_loader::load(std::string filename)
{
    image_t image{0, 0, nullptr};

    FILE* fp = fopen(filename.c_str(), "rb");
    if (!fp) {
        std::cerr << "Failed to open PNG image: " << filename << std::endl;
        return image;
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read file
    unsigned char* png_data = (unsigned char*) malloc(size);
    if (!png_data) {
        std::cerr << "Failed to allocate memory for PNG data" << std::endl;
        fclose(fp);
        return image;
    }

    fread(png_data, 1, size, fp);
    fclose(fp);
    
    // Create sPNG context
    spng_ctx* ctx = spng_ctx_new(0);
    spng_set_png_buffer(ctx, png_data, size);

    // Parse PNG info header
    struct spng_ihdr ihdr;
    if (spng_get_ihdr(ctx, &ihdr)) {
        std::cerr << "Failed to read PNG header" << std::endl;
        spng_ctx_free(ctx);
        free(png_data);
        return image;
    }

    size_t out_size;
    spng_decoded_image_size(ctx, SPNG_FMT_RGBA8, &out_size);

    unsigned char* image_data = (unsigned char*) malloc(out_size);
    if (!image_data) {
        std::cerr << "Failed to allocate memory for image data" << std::endl;
        spng_ctx_free(ctx);
        free(png_data);
        return image;
    }

    if (spng_decode_image(ctx, image_data, out_size, SPNG_FMT_RGBA8, 0)) {
        std::cerr << "Failed to decode PNG image" << std::endl;
        spng_ctx_free(ctx);
        free(png_data);
        free(image_data);
        return image;
    }

    image.width = ihdr.width;
    image.height = ihdr.height;
    image.data = image_data;

    spng_ctx_free(ctx);
    free(png_data);

    return image;
}