#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_random_image(long int width, long int height) {
    int binaryPixel = 0;

	// Create PBM image file
	FILE* pFile = fopen("image.pbm", "w");

	// PBM file extension header (Portable BitMap magic identifier)
	fprintf(pFile, "P1\n");

	// Write image width & height to file
	fprintf(pFile, "%lu %lu\n", width, height);

	// Random seed initialization
	srand(time(NULL));

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
    
    if (argc == 3) {
        width = strtol(argv[1], NULL, 10);
        height = strtol(argv[2], NULL, 10);

        make_random_image(width, height);
    } else {
        fprintf(stderr, "Invalid number of arguments.");
    }
    
	return 0;
}
