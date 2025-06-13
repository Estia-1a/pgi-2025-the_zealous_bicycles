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
    printf("Delarbol !");
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


