#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Delarbol mets toi au boulot !");
}

void dimension(char* filename){
 
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",filename);
    }
    else{
        printf("dimension : %d, %d\n",width,height);
        free_image_data(data);
    }
}


void first_pixel (char *source_path){
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) ==0){
        printf("Erreur avec le fichier : %s\n",source_path);
    }
    else{
        printf("%d, %d, %d\n",data[0], data[1], data[2]);
        free_image_data(data);
    }

}

void tenth_pixel(char *source_path) {
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        printf("%d, %d, %d\n", data[27], data[28], data[29]);
        free_image_data(data);
    }
}


void second_line(char *source_path) {
    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        printf("%d, %d, %d\n", data[width*3], data[(width*3)+1], data[(width*3)+2]);
        free_image_data(data);
    }
}


void print_pixel( char *filename, int x, int y ){

    unsigned char* data;
    int width, height, channel_count;
    if (read_image_data(filename, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", filename);
    }
    else {
      pixelRGB *pixel = get_pixel(data, width, height, 
        channel_count, x, y );

        if (pixel != NULL){
            printf("%d, %d, %d\n", pixel->R, pixel->G, pixel->B);
            
            free_image_data(data);


        }
        
    }
}


void max_pixel(char *source_path){
    unsigned char* data;
    int width, height, channel_count;
    int somme = 0, x_max = 0, y_max = 0,  somme_max = 0;
    int x, y;

     if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    else {
       
        for(y=0; y<height; y++){
            for(x=0; x<width; x++){
            
                 pixelRGB *pixel = get_pixel(data, width, height, 
                 channel_count, x, y );
            
                 somme = pixel->R + pixel->G + pixel->B;

                 if(somme > somme_max){
                    somme_max = somme;
                    x_max = x;
                    y_max = y;
                }
            }
        }
         pixelRGB *pixel_max = get_pixel(data, width, height, 
         channel_count, x_max, y_max );
        
        printf("(%d, %d) : %d, %d, %d\n", x_max, y_max, pixel_max->R, pixel_max->G, pixel_max->B);
    }

    
}