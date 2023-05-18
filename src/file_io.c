#include "file_io.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"
#include "util.h"

int image_read(image_t *img, FILE *fin) {

    int width=0;
    int height=0;
    char p[3];
    int max;

    /*fscanf(fin,"%2s",&p[0]);
    if (memcmp(p,"P3",3)!=0){return -1;}
    fscanf(fin,"%d %d %d",&width,&height,&max);
    if (width<1||height<1||max!=255){return -1;}*/
    
    int result=(fscanf(fin,"%2s %d %d %d", p, &width, &height, &max));  
    
    if (result != 4 || p[0] != 'P' || p[1] != '3' || width < 1 || height < 1 || max != 255) {        return -1;    }
    
    pixel_t* pixels= malloc(width * height * sizeof(pixel_t));
    img->img=pixels;
    /*HERE IS A NEWSEGMENT*/
    for (int i=0;i<width*height;++i)
    {
        fscanf(fin,"%d %d %d",&pixels[i].r, &pixels[i].g,&pixels[i].b);
        if (pixels[i].r<0||pixels[i].r>255 || pixels[i].g<0||pixels[i].g>255||pixels[i].b<0||pixels[i].b>255)
        { free(pixels);
            return -1;
        }
    }
    img->w=width;
    img->h=height;
    return 0;
   
}

void image_write(const image_t *img, FILE *fout) 
{
    int width=img->w;
    int height=img->h;
   
    fprintf(fout,"P3\n%d %d\n255\n",width, height);
    for(int i=0; i< width*height;++i)
    {
        fprintf(fout, " %d %d %d", img->img[i].r, img->img[i].g , img->img[i].b); //why is spacing important just here?
    }    

}
void image_free(image_t *img) {
    if (img->img != NULL) {
        free(img->img);
    }
    img->w = img->h = 0;
    img->img = NULL;
}
