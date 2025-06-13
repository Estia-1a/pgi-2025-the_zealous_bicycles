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
