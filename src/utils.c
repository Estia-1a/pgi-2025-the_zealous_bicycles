#include <estia-image.h>
#include <stdlib.h>
#include "utils.h"

pixelRGB * get_pixel( unsigned char* data, const unsigned int width, const unsigned int height, 
  const unsigned int n, const unsigned int x, const unsigned int y ){
    
    if  (x > width-1 || y > height-1){
        printf("Le pixel demandé n'existe pas");
        return(NULL);
    }

    if(data == NULL){
        printf("data est NULL");
        return(NULL);
    }

    else{
          return (pixelRGB *) &data[(width*y+x)*n] ;
    }
  }














/**
 * @brief Here, you have to define functions of the pixel struct : getPixel and setPixel.
 * 
 */

