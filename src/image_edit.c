#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {

}

void rotate_clockwise(image_t *img) {
    /////CASEEEEE1;
    image_t new_image;
    int width=img->h;
    int height=img->w;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula 
            pixel_t* srcpixel = &(img->img[i * width + j]);
            int rotX=height-1-i;
            int rotY=j;

            new_image.img[rotY*width+rotX] = img->img[i*img->w+j];
        }
    }
    free(img->img);
    img->w=width;
    img->h=height;
    img->img=new_image.img;

}

void mirror_horizontal(image_t *img) {

}

void mirror_vertical(image_t *img) {
    NOT_IMPLEMENTED;
    UNUSED(img);
}

void resize(image_t *img, int new_width, int new_height) {
    NOT_IMPLEMENTED;
    UNUSED(img);
    UNUSED(new_width);
    UNUSED(new_height);
}
