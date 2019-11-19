#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_random_image(long int width, long int height, char* pFilename) {
    int binaryPixel = 0;

	// Create PBM image file
	FILE* pFile = fopen(pFilename, "w");

	// PBM file extension header (Portable BitMap magic identifier)
	fprintf(pFile, "P1\n");

	// Write image width & height to file
	fprintf(pFile, "%lu %lu\n", width, height);

	// Write image data to file
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			// Generates a random binary pixel value
			binaryPixel = rand() % 2; // [0, 1]

			fprintf(pFile, "%d ", binaryPixel);
		}

		fprintf(pFile, "\n");
	}

	// Close PBM image file
	fclose(pFile);
}

int main(int argc, char** argv) {
    long int width, height;

    // Random seed initialization
	srand(time(NULL));
    
    if (argc == 3) {
        width = strtol(argv[1], NULL, 10);
        height = strtol(argv[2], NULL, 10);

        make_random_image(width, height, "image.pbm");
    } else if (argc == 4) {
    	width = strtol(argv[1], NULL, 10);
        height = strtol(argv[2], NULL, 10);

        long int imageCount = strtol(argv[3], NULL, 10);
        char *pFilename = (char*) malloc(1024 * sizeof(char));

        for (long int i = 0; i < imageCount; i++) {
        	sprintf(pFilename, "image_%ld.pbm", i);
        	make_random_image(width, height, pFilename);
        }

        free(pFilename);
    } else {
        fprintf(stderr, "Invalid number of arguments.");
    }
    
	return 0;
}
