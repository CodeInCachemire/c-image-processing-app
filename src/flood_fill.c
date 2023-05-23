#include "flood_fill.h"

#include <stdbool.h>
#include <stdlib.h>

#include "structures.h"
#include "util.h"

void flood(image_t *img, int x, int y, pixel_t *target_color) {
    pixel_t ocolor;
    pixel_t *pix;
    if (x < 0 || y < 0 || x >= img->w || y >= img->h) return;//already done if point is outside bounds it does nothing
  
    pix=&(img->img[y*img->w+x]);

    if((pix->r == target_color->r) && (pix->g== target_color->r) && (pix->b == target_color->b))
    {return;}//Same colour is at that position
    ocolor=*pix;

    pix->r = target_color->r;
    pix->g = target_color->g;
    pix->b = target_color->b;
    
    if((x + 1)<img->w && (img->img[y*img->w+(x+1)]).r==ocolor.r && (img->img[y*img->w+(x+1)]).g==ocolor.g  && (img->img[y*img->w+(x+1)]).b==ocolor.b)
    {
        flood(img, x + 1, y, target_color);
    }
    
    if((x -1)>=0 && (img->img[y*img->w+(x-1)]).r==ocolor.r && (img->img[y*img->w+(x-1)]).g==ocolor.g  && (img->img[y*img->w+(x-1)]).b==ocolor.b)
    {
        flood(img, x - 1, y, target_color);
    }
    if((y+1)<img->h && (img->img[(y+1)*img->w+x]).r==ocolor.r && (img->img[(y+1)*img->w+x]).g==ocolor.g  &&(img->img[(y+1)*img->w+x]).b==ocolor.b)
    {
    flood(img, x, y + 1, target_color);
    }
    if((y-1)>=0 && (img->img[(y-1)*img->w+x]).r==ocolor.r && (img->img[(y-1)*img->w+x]).g==ocolor.g  && (img->img[(y-1)*img->w+x]).b==ocolor.b)
    {
        flood(img, x, y- 1, target_color);
    }
}



