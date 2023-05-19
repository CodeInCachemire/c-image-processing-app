#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) {
    image_t new_image;
    int width=img->h;
    int height=img->w;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula 
            /*pixel_t* srcpixel = &(img->img[i * width + j]);*/
            int rotX=i;
            int rotY=height-1-j;

            new_image.img[rotY*width+rotX] = img->img[i*img->w+j];
        }
    }
    free(img->img);
    img->w=width;
    img->h=height;
    img->img=new_image.img;

}

void rotate_clockwise(image_t *img) {
    image_t new_image;
    int width=img->h;
    int height=img->w;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula 
            /*pixel_t* srcpixel = &(img->img[i * width + j]);*/
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
    image_t new_image;
    int width=img->w;
    int height=img->h;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula 
            /*pixel_t* srcpixel = &(img->img[i * width + j]);*/
            int rotX=height-1-j;
            int rotY=i;

            new_image.img[rotY*width+rotX] = img->img[i*img->w+j];
        }
    }
    free(img->img);
    img->w=width;
    img->h=height;
    img->img=new_image.img;
}

void mirror_vertical(image_t *img) {
    image_t new_image;
    int width=img->w;
    int height=img->h;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula 
            int rotX=j;
            int rotY=height-1-i;

            new_image.img[rotY*width+rotX] = img->img[i*img->w+j];
        }
    }
    free(img->img);
    img->w=width;
    img->h=height;
    img->img=new_image.img;
}

void resize(image_t *img, int new_width, int new_height) 
{

    image_t new_image;
    int width=img->w;
    int height=img->h;
    //CASE 1:
    //CASE 2 to reduce size
    new_image.img= malloc(new_width * new_height * sizeof(pixel_t)); //NEW ARRAY
    int i, j;
    //BLACK IS INPUTTED IN WHOLE NEW BUFFER
    for (i = 0; i < new_height*new_width; i++) 
    {
        new_image.img[i].r = 0;
        new_image.img[i].g = 0;
        new_image.img[i].b= 0;
    }
    int copy_width = (new_width< img->w) ? new_width : img->w;
    int copy_height = (new_height < img->h) ? new_height : img->h;
    ///LOOP WHICH COPIES OLD IMAGE TO NEW
    for (int i = 0; i <copy_height; i++) 
    {
        for (int j = 0; j<copy_width; j++) 
        {         
        //We use code from vertical but get rid of the rotX/Y because we don't rotate just resize
        //Important note here is that two cases or maybe 4 cases        
        new_image.img[i*new_width+j] = img->img[i*img->w+j];            
        }
    }
    
    free(img->img); //code passed two tests so basically we have resized to a new 
    img->w=new_width;
    img->h=new_height;
    img->img=new_image.img;

} 
