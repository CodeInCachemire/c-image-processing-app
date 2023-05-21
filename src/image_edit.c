#include "image_edit.h"

#include <stdlib.h>

#include "structures.h"
#include "util.h"

void rotate_counterclockwise(image_t *img) 
{
    // Calculate dimensions of new image after rotation
    image_t new_image;
    int width=img->w;
    int height=img->h;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
    /*if(new_image.img==NULL)
    {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
    }*/

    
    for (int i = 0; i <width; i++) 
    {
        for (int j = 0; j<height ; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula after deriving it
            int rotX=j;
            int rotY=width-1-i;

            new_image.img[rotY*height+rotX] = img->img[j*img->w+i];
        }
    }

    free(img->img);
    img->w=height;
    img->h=width;
    img->img=new_image.img;
    
}
void rotate_clockwise(image_t *img) {
    // Calculate dimensions of new image after rotation
    image_t new_image;
    int width=img->w;
    int height=img->h;
    new_image.img= malloc(width * height * sizeof(pixel_t)); //NEW ARRAY
   
    for (int i = 0; i <height; i++) 
    {
        for (int j = 0; j< width; j++) 
        {
            //we want the pixel from our pixel array, and we have the formula after deriving it
            int rotX=height-i-1;
            int rotY=j;
            new_image.img[rotY*height+rotX] = img->img[i*img->w+j];
        }
    }

    free(img->img);
    img->w=height;
    img->h=width;
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
            int rotX=width-1-j;
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
    /*int width=img->w;
    int height=img->h;*/
    //CASE 2 to reduce size
    new_image.img= malloc(new_width * new_height * sizeof(pixel_t)); //NEW ARRAY
    int i;
    //BLACK IS INPUTTED IN WHOLE NEW BUFFER
    for (i = 0; i < new_height*new_width; i++) 
    {
        new_image.img[i].r = 0;
        new_image.img[i].g =0;
        new_image.img[i].b= 0;
    }
    int copy_width = (new_width < img->w) ? new_width : img->w;
    int copy_height = (new_height < img->h) ? new_height : img->h;
    ///LOOP WHICH COPIES OLD IMAGE TO NEW
    for (int i = 0; i <copy_height; i++) 
    {
        for (int j = 0; j<copy_width; j++) 
        {         
        //We use code from vertical but get rid of the rotX/Y because we don't rotate just resize        
        new_image.img[i*new_width+j] = img->img[i*img->w+j]; 
        }
    }
    free(img->img); //code passed two tests so basically we have resized to a new 
    img->w=new_width;
    img->h=new_height;
    img->img=new_image.img;

} 
