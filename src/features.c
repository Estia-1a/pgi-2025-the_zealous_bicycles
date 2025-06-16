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
                
                if(pixel!= NULL){
                  somme = pixel->R + pixel->G + pixel->B;

                 if(somme > somme_max){
                    somme_max = somme;
                    x_max = x;
                    y_max = y;
                 }
                }

                else{
                    printf("ERREUR");
                }
            }
        }
         pixelRGB *pixel_max = get_pixel(data, width, height, 
         channel_count, x_max, y_max );
        
        printf("(%d, %d) : %d, %d, %d\n", x_max, y_max, pixel_max->R, pixel_max->G, pixel_max->B);
    }
}

void min_pixel(char *source_path){
    unsigned char* data;
    int width, height, channel_count;
    int somme = 0, x_min = 0, y_min = 0,  somme_min = 765;
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

                 if(somme < somme_min){
                    somme_min = somme;
                    x_min = x;
                    y_min = y;
                }
            }
        }
         pixelRGB *pixel_min = get_pixel(data, width, height, 
         channel_count, x_min, y_min );
        
        printf("(%d, %d) : %d, %d, %d\n", x_min, y_min, pixel_min->R, pixel_min->G, pixel_min->B);
    }

    free_image_data(data);
}


void max_component(char *source_path, char component){

    unsigned char* data;
    int width, height, channel_count;

    int x_max = 0, y_max = 0, valeur_max = 0, valeur = 0;
    int x, y;

     if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    else {
       
        for(y=0; y<height; y++){
            for(x=0; x<width; x++){
                
                
                 pixelRGB *pixel = get_pixel(data, width, height, 
                 channel_count, x, y );

                 if(pixel != NULL){
            
                    if(component == 'R'){
                        valeur = pixel->R;
                    }

                    else if(component == 'G'){
                        valeur = pixel->G;
                    }

                    else if(component == 'B'){
                        valeur = pixel->B;
                    }

                    else{
                        printf("Entrez R, G ou B svp\n");
                        return;
                    }
                }
                else{
                    printf("ERREUR\n");
                }

                if(valeur > valeur_max){
                    valeur_max = valeur;
                    x_max = x;
                    y_max = y;
                }
            }
        }
         
        printf("(%d, %d) : %d\n", x_max, y_max, valeur_max);
        free_image_data(data);
    }
}

void min_component(char *source_path, char component){

    unsigned char* data;
    int width, height, channel_count;

    int x_min = 0, y_min = 0, valeur_min = 256, valeur = 0;
    int x, y;

     if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    else {
       
        for(y=0; y<height; y++){
            for(x=0; x<width; x++){
                
                
                 pixelRGB *pixel = get_pixel(data, width, height, 
                 channel_count, x, y );

                 if(pixel != NULL){
            
                    if(component == 'R'){
                        valeur = pixel->R;
                    }

                    else if(component == 'G'){
                        valeur = pixel->G;
                    }

                    else if(component == 'B'){
                        valeur = pixel->B;
                    }

                    else{
                        printf("Entrez R, G ou B svp\n");
                        return;
                    }
                }
                else{
                    printf("ERREUR\n");
                }

                if(valeur < valeur_min){
                    valeur_min = valeur;
                    x_min = x;
                    y_min = y;
                }
            }
        }
         
        printf("(%d, %d) : %d\n", x_min, y_min, valeur_min);
        free_image_data(data);
    }
}



void color_red(char *source_path){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
            int i,j;
            for(j=0; j<height; j++){
                for(i=0; i<width; i++){

                    pixelRGB *pixel = get_pixel(data, width, height, 
                    channel_count, i, j );

                    pixel->G = 0;
                    pixel->B = 0;
                }
            }
        
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        
    free_image_data(data);
}



void color_green(char *source_path){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
            int i,j;
            for(j=0; j<height; j++){
                for(i=0; i<width; i++){

                    pixelRGB *pixel = get_pixel(data, width, height, 
                    channel_count, i, j );

                    pixel->R = 0;
                    pixel->B = 0;
                }
            }
        
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        
    free_image_data(data);
}





void color_blue(char *source_path){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
            int i,j;
            for(j=0; j<height; j++){
                for(i=0; i<width; i++){

                    pixelRGB *pixel = get_pixel(data, width, height, 
                    channel_count, i, j );

                    pixel->R = 0;
                    pixel->G = 0;
                }
            }
        
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        
    free_image_data(data);
}



void color_gray(char *source_path){

    unsigned char* data;
    int width, height, channel_count;
    unsigned char value;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
            int i,j;
            for(j=0; j<height; j++){
                for(i=0; i<width; i++){

                    pixelRGB *pixel = get_pixel(data, width, height, 
                    channel_count, i, j );
                    
                    value = (pixel->R + pixel->G + pixel->B)/3 ;

                    pixel->R = value;
                    pixel->G = value;
                    pixel->B = value;
                    
                }
            }
        
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        
    free_image_data(data);
}

