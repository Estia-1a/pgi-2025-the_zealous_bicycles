#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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
        printf("dimension: %d, %d\n",width,height);
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
        printf("first_pixel: %d, %d, %d\n",data[0], data[1], data[2]);
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
        printf("tenth_pixel: %d, %d, %d\n", data[27], data[28], data[29]);
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
        printf("second_line: %d, %d, %d\n", data[width*3], data[(width*3)+1], data[(width*3)+2]);
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
            printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
            
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
        
        printf("max_pixel (%d, %d): %d, %d, %d\n", x_max, y_max, pixel_max->R, pixel_max->G, pixel_max->B);
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
        
        printf("min_pixel (%d, %d): %d, %d, %d\n", x_min, y_min, pixel_min->R, pixel_min->G, pixel_min->B);
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
         
        printf("max_component %c (%d, %d): %d\n", component, x_max, y_max, valeur_max);
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
         
        printf("min_component %c (%d, %d): %d\n", component, x_min, y_min, valeur_min);
        free_image_data(data);
    }
}

void stat_report(char *source_path) {

    unsigned char*data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }

    FILE *file = fopen("stat_report.txt", "w");
    if (file == NULL) {
        printf("Erreur dans la création\n");
        free_image_data(data);
        return;
    }

    // Partie 1
    int somme = 0, x_max = 0, y_max = 0,  somme_max = 0;
    int x, y;
    /*pixelRGB *pixel;*/

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
    
    fprintf(file, "Max_pixel : (%d, %d) : %d, %d, %d\n\n", x_max, y_max, pixel_max->R, pixel_max->G, pixel_max->B);
    
    //PArtie 2
    int x_min = 0, y_min = 0,  somme_min = 765;

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
    
    fprintf(file, "Min_pixel(%d, %d) : %d, %d, %d\n\n", x_min, y_min, pixel_min->R, pixel_min->G, pixel_min->B);


    
//Partie 3 pour le component R
    int x_max_R = 0, y_max_R = 0, valeur_max_R = 0;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->R > valeur_max_R){
                        valeur_max_R = pixel->R;
                        x_max_R = x;
                        y_max_R = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }
        
        fprintf(file, "Max_component R : (%d, %d) : %d\n\n", x_max_R, y_max_R, valeur_max_R);        
        free_image_data(data);
    }

    //Partie 4 Pour le max component G

    int x_max_G = 0, y_max_G = 0, valeur_max_G = 0;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->G > valeur_max_G){
                        valeur_max_G = pixel->G;
                        x_max_G = x;
                        y_max_G = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }        
        fprintf(file, "Max_component G : (%d, %d) : %d\n\n", x_max_G, y_max_G, valeur_max_G);        
        free_image_data(data);
    }

    //Partie 5 pour le max component B

    int x_max_B = 0, y_max_B = 0, valeur_max_B = 0;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->B > valeur_max_B){
                        valeur_max_B = pixel->B;
                        x_max_B = x;
                        y_max_B = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }        
        fprintf(file, "Max_component B : (%d, %d) : %d\n\n", x_max_B, y_max_B, valeur_max_B);        
        free_image_data(data);
    }

    //Partie 6 pour me min component R
    int x_min_R = 0, y_min_R = 0, valeur_min_R = 256;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->R < valeur_min_R){
                        valeur_min_R = pixel->R;
                        x_min_R = x;
                        y_min_R = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }
        
        fprintf(file, "Min_component R : (%d, %d) : %d\n\n", x_min_R, y_min_R, valeur_min_R);        
        free_image_data(data);
    }

    //Partie 7 pour me min component G
    int x_min_G = 0, y_min_G = 0, valeur_min_G = 256;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->G < valeur_min_G){
                        valeur_min_G = pixel->G;
                        x_min_G = x;
                        y_min_G = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }
        
        fprintf(file, "Min_component G : (%d, %d) : %d\n\n", x_min_G, y_min_G, valeur_min_G);        
        free_image_data(data);
    }

    //Partie 8 pour me min component B
    int x_min_B = 0, y_min_B = 0, valeur_min_B = 256;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else {
        for(y = 0; y < height; y++){
            for(x = 0; x < width; x++){
                
                pixelRGB *pixel = get_pixel(data, width, height, channel_count, x, y);

                if(pixel != NULL){
                    if(pixel->B < valeur_min_B){
                        valeur_min_B = pixel->B;
                        x_min_B = x;
                        y_min_B = y;
                    }
                }
                else{
                    printf("Erreur (%d, %d)\n", x, y);
                }
            }
        }
        
        fprintf(file, "Min_component B : (%d, %d) : %d\n\n", x_min_B, y_min_B, valeur_min_B);        
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



void color_invert(char *source_path){

    unsigned char* data;
    int width, height, channel_count;
    unsigned char old_R, old_G, old_B, new_R, new_G, new_B;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
            int i,j;
            for(j=0; j<height; j++){
                for(i=0; i<width; i++){

                    pixelRGB *pixel = get_pixel(data, width, height, 
                    channel_count, i, j );

                    old_R = pixel->R;
                    old_G = pixel->G;
                    old_B = pixel->B;

                    new_R = 255 - old_R;
                    new_G = 255 - old_G;
                    new_B = 255 - old_B;

                    pixel->R = new_R;
                    pixel->G = new_G;
                    pixel->B = new_B;
                    
                }
            }
        
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        
    free_image_data(data);
}



void color_gray_luminance(char *source_path){

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
                    
                    value = 0.21*pixel->R + 0.72*pixel->G + 0.07*pixel->B ;

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



void rotate_cw(char *source_path){

    unsigned char* data;
    unsigned char* memoire_pivot;
    int width, height, channel_count, new_x, new_y, nouvelle_position;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i,j;
        int new_width = height;
        int new_height = width;
    
        memoire_pivot = malloc(new_width * new_height * channel_count);
        for(j=0; j<height; j++){
            for(i=0; i<width; i++){

                pixelRGB *pixel = get_pixel(data, width, height, 
                channel_count, i, j );

                if(pixel != NULL){
                    new_x = height-1-j;
                    new_y = i;

                    nouvelle_position = (new_y * new_width + new_x) * channel_count;

                    memoire_pivot[nouvelle_position] = pixel->R;
                    memoire_pivot[nouvelle_position + 1] = pixel->G;
                    memoire_pivot[nouvelle_position + 2] = pixel->B;
                }
                
            }
        }
        if (write_image_data("image_out.bmp", memoire_pivot, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        free(memoire_pivot);

        
    }
    
    free_image_data(data);
}



void rotate_acw(char *source_path){

    unsigned char* data;
    unsigned char* memoire_pivot;
    int width, height, channel_count, new_x, new_y, nouvelle_position;


    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i,j;
        int new_width = height;
        int new_height = width;
    
        memoire_pivot = malloc(new_width * new_height * channel_count);
        for(j=0; j<height; j++){
            for(i=0; i<width; i++){

                pixelRGB *pixel = get_pixel(data, width, height, 
                channel_count, i, j );

                if(pixel != NULL){
                    new_x = j;
                    new_y = width-1-i;

                    nouvelle_position = (new_y * new_width + new_x) * channel_count;

                    memoire_pivot[nouvelle_position] = pixel->R;
                    memoire_pivot[nouvelle_position + 1] = pixel->G;
                    memoire_pivot[nouvelle_position + 2] = pixel->B;
                }
                
            }
        }
        if (write_image_data("image_out.bmp", memoire_pivot, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        free(memoire_pivot);
        
    }
    
    free_image_data(data);
}




void mirror_horizontal(char *source_path){

    unsigned char* data;
    int width, height, channel_count;
    int x,y, x_droite;
    unsigned char R, G, B;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{

            for(y=0; y<height; y++){
                for(x=0; x<width/2; x++){

                    pixelRGB *pixel_gauche = get_pixel(data, width, height,
                    channel_count, x, y );

                    R = pixel_gauche->R;
                    G = pixel_gauche->G;
                    B = pixel_gauche->B;
                   
                    x_droite = width - 1 - x;

                    pixelRGB *pixel_droite = get_pixel(data, width, height,
                    channel_count, x_droite, y );

                    pixel_gauche->R = pixel_droite->R;
                    pixel_gauche->G = pixel_droite->G;
                    pixel_gauche->B = pixel_droite->B;

                    pixel_droite->R = R;
                    pixel_droite->G = G;
                    pixel_droite->B = B;

                                     
                }
            }
       
    }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
       
    free_image_data(data);


}



void mirror_vertical(char *source_path){

    unsigned char* data;
    int width, height, channel_count;
    int x,y, y_haut;
    unsigned char R, G, B;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{

            for(y=0; y<height/2; y++){
                for(x=0; x<width; x++){

                    pixelRGB *pixel_haut = get_pixel(data, width, height,
                    channel_count, x, y );

                    R = pixel_haut->R;
                    G = pixel_haut->G;
                    B = pixel_haut->B;
                   
                    y_haut = height - 1 - y;

                    pixelRGB *pixel_bas = get_pixel(data, width, height,
                    channel_count, x, y_haut);

                    pixel_haut->R = pixel_bas->R;
                    pixel_haut->G = pixel_bas->G;
                    pixel_haut->B = pixel_bas->B;

                    pixel_bas->R = R;
                    pixel_bas->G = G;
                    pixel_bas->B = B;

                                     
                }
            }
        }

        if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
       
    free_image_data(data);
}

void mirror_total(char *source_path){

   

    unsigned char* data;
    int width, height, channel_count;
    int x,y, x_droite, y_bas;
    unsigned char R1, G1, B1, R2, G2, B2;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        
            for(y=0; y<height; y++){
                for(x=0; x<width/2; x++){

                      pixelRGB *pixel_gauche = get_pixel(data, width, height,
                    channel_count, x, y );

                    R1 = pixel_gauche->R;
                    G1 = pixel_gauche->G;
                    B1 = pixel_gauche->B;
                   
                    x_droite = width - 1 - x;

                    pixelRGB *pixel_droite = get_pixel(data, width, height,
                    channel_count, x_droite, y );

                    pixel_gauche->R = pixel_droite->R;
                    pixel_gauche->G = pixel_droite->G;
                    pixel_gauche->B = pixel_droite->B;

                    pixel_droite->R = R1;
                    pixel_droite->G = G1;
                    pixel_droite->B = B1;
                }
            }

            for(y=0; y<height/2; y++){
                for(x=0; x<width; x++){

                    pixelRGB *pixel_haut = get_pixel(data, width, height,
                    channel_count, x, y );

                    R2 = pixel_haut->R;
                    G2 = pixel_haut->G;
                    B2 = pixel_haut->B;
                   
                    y_bas = height - 1 - y;

                    pixelRGB *pixel_bas = get_pixel(data, width, height,
                    channel_count, x, y_bas);

                    pixel_haut->R = pixel_bas->R;
                    pixel_haut->G = pixel_bas->G;
                    pixel_haut->B = pixel_bas->B;

                    pixel_bas->R = R2;
                    pixel_bas->G = G2;
                    pixel_bas->B = B2;

                                     
                }
            }
       
       
   }

    if (write_image_data("image_out.bmp", data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
       
    free_image_data(data);


}

void scale_nearest(char *source_path, float coeff){


    unsigned char* data;
    unsigned char* nouvelle_memoire;
    int width, height, channel_count, new_width, new_height;
    int x_avant, y_avant;
    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{

        new_width = (int)(width*coeff);
        new_height = (int)(height*coeff);

        nouvelle_memoire = malloc(new_width*new_height*channel_count);


        int i,j;
        for(j=0; j<new_height; j++){
            for(i=0; i<new_width; i++){

                x_avant = (int)((float)i/coeff + 0.5);
                y_avant = (int)((float)j/coeff + 0.5);

                if(x_avant < 0){
                    x_avant = 0;
                }

                if(x_avant > width-1){
                    x_avant = width -1;
                }

                if(y_avant < 0){
                    y_avant = 0;
                }

                if(y_avant > height-1){
                    y_avant = height -1;
                }

                pixelRGB *pixel_avant = get_pixel(data, width, height, 
                                        channel_count, x_avant, y_avant);
                pixelRGB *pixel_apres = get_pixel(nouvelle_memoire, new_width, new_height, 
                                        channel_count, i, j);
                
                                        pixel_apres->R = pixel_avant->R;
                                        pixel_apres->G = pixel_avant->G;
                                        pixel_apres->B = pixel_avant->B;

            }
        }
    }
     if (write_image_data("image_out.bmp", nouvelle_memoire, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
       
    free_image_data(data);
    free(nouvelle_memoire);
}







void scale_bilinear(char *source_path, float coeff){


    unsigned char* data;
    unsigned char* nouvelle_memoire;
    int width, height, channel_count, new_width, new_height;
    float x_reel, y_reel, distance_x, distance_y, R, G, B;
    int x_gauche, x_droite, y_haut, y_bas;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{

        new_width = (int)(width*coeff);
        new_height = (int)(height*coeff);

        nouvelle_memoire = malloc(new_width*new_height*channel_count);


        int i,j;
        for(j=0; j<new_height; j++){
            for(i=0; i<new_width; i++){

                x_reel = (float)i/coeff;
                y_reel = (float)j/coeff;

                x_gauche = (int)x_reel;
                y_haut = (int)y_reel;
                x_droite = x_gauche + 1;
                y_bas = y_haut + 1;

                 if(x_gauche < 0){
                    x_gauche = 0;
                }

                if(x_droite > width-1){
                    x_droite = width -1;
                }

                if(y_haut < 0){
                    y_haut = 0;
                }

                if(y_bas > height-1){
                    y_bas = height -1;
                }


                distance_x = x_reel - x_gauche;
                distance_y = y_reel - y_haut;

                /*D'après Internet la formule de l'interpolation bilinéaire nécessite les distances
                 et les 4 pixels autour de celui qu'on cherche   */

                 pixelRGB *pixel_haut_gauche = get_pixel(data, width, height, channel_count,
                                                x_gauche, y_haut);
                 pixelRGB *pixel_haut_droite = get_pixel(data, width, height, channel_count,
                                                x_droite, y_haut);
                 pixelRGB *pixel_bas_gauche = get_pixel(data, width, height, channel_count,
                                                x_gauche, y_bas);
                 pixelRGB *pixel_bas_droite = get_pixel(data, width, height, channel_count,
                                                x_droite, y_bas);

                
                R = (1 - distance_x) * (1 - distance_y) * pixel_haut_gauche->R

                + distance_x * (1 - distance_y) * pixel_haut_droite->R

                + distance_x * distance_y * pixel_bas_droite->R

                + (1 - distance_x) * distance_y * pixel_bas_gauche->R;




                  G = (1 - distance_x) * (1 - distance_y) * pixel_haut_gauche->G

                + distance_x * (1 - distance_y) * pixel_haut_droite->G

                + distance_x * distance_y * pixel_bas_droite->G
                
                + (1 - distance_x) * distance_y * pixel_bas_gauche->G;




                  B = (1 - distance_x) * (1 - distance_y) * pixel_haut_gauche->B

                + distance_x * (1 - distance_y) * pixel_haut_droite->B

                + distance_x * distance_y * pixel_bas_droite->B
                
                + (1 - distance_x) * distance_y * pixel_bas_gauche->B;



                pixelRGB *pixel_apres = get_pixel(nouvelle_memoire, new_width, new_height,
                                                channel_count, i, j);

                                                pixel_apres->R = (unsigned char)(R + 0.5);
                                                pixel_apres->G = (unsigned char)(G + 0.5);
                                                pixel_apres->B = (unsigned char)(B + 0.5);
            }
        }
    }
     if (write_image_data("image_out.bmp", nouvelle_memoire, new_width, new_height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
       
    free_image_data(data);
    free(nouvelle_memoire);
}









void scale_crop(char *source_path, int center_x, int center_y, int crop_width, int crop_height){
    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i, j;
        int base_x, base_y;
        int src_x, src_y;
        int crop_index;
        unsigned char* cropped_data = malloc(crop_width * crop_height * 3);

        base_x = center_x - crop_width /2;
        base_y = center_y - crop_width /2;

        for(j=0; j<height; j++){
            for(i=0; i<width; i++){

                pixelRGB *pixel = get_pixel(data, width, height, 
                channel_count, i, j );

                if(pixel != NULL){
                    src_x = base_x + i;
                    src_y = base_y + j;

                    crop_index = (j* crop_width +i) * 3;

                    if(src_x >=0 && src_x < width && src_y >=0 && src_y< height){
                        if(pixel != NULL){
                            cropped_data[crop_index] = pixel->R;
                            cropped_data[crop_index + 1] = pixel->G;
                            cropped_data[crop_index + 2] = pixel->B;
                        }
                        else{
                            cropped_data[crop_index] = 0;
                            cropped_data[crop_index + 1] = 0;
                            cropped_data[crop_index + 2] = 0;
                        }
                    }

                }
                
            }

        }
        if (write_image_data("image_out.bmp", cropped_data, width, height) == 0) {
            printf("Erreur 2 avec le fichier : %s\n", source_path);
        }
        free(cropped_data);
    }
    free_image_data(data);
}




void color_desaturate(char *source_path){

    unsigned char* data;
    int width, height, channel_count;

    if (read_image_data(source_path, &data, &width, &height, &channel_count) == 0) {
        printf("Erreur avec le fichier : %s\n", source_path);
    }
    else{
        int i, j;
        int min_val, max_val, new_val;

        for(j=0; j<height; j++){
            for(i=0; i<width; i++){

                pixelRGB *pixel = get_pixel(data, width, height, 
                channel_count, i, j );

                if(pixel !=NULL){

                    min_val=pixel->R;

                    if(pixel->G < min_val) min_val = pixel->G;
                    if(pixel->B < min_val) min_val = pixel->B;

                    min_val=pixel->R;
                    
                    if(pixel->G > max_val) max_val = pixel->G;
                    if(pixel->B > max_val) max_val = pixel->B;
                    new_val = (max_val + min_val) / 2;

                    pixel->R = new_val;
                    pixel->G = new_val;
                    pixel->B = new_val;
                }

            }
        }
    }
    if (write_image_data("image_out.bmp", data, width, height) == 0) {
        printf("Erreur 2 avec le fichier : %s\n", source_path);
    }
    
free_image_data(data);
}