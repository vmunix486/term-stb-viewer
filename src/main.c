#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>

#define CHARACTER '#'
//#define CHARACTER '█'
// The full block doesn't really work because _technically_
// a string consisting of multiple characters.
//
// It's confusing. -vmunix

int main(int argc, char *argv[]){
	if (!argv[1]) {
		puts("No image specified\n");
		puts("Usage: tstbv [file.imagefileformat]");
		return 1;
	}

	int x,y,n;

	// For anyone wanting any research on how 
	// to use stb_image.h, stbi_load() ouputs 
	// an array of all the values of the pixels
	// in how many colors you set it to.
	//
	// For example, right here it loads the
	// picture into the unsigned char pointer
	// image, which ends up being an array the
	// size of (width*height)*3.
	//
	// The array itself is a little confusing
	// at first, but you figure it out pretty
	// quickly.
	// 
	// image[0] is red, from 0 to 255,
	// image[1] is green, from 0 to 255,
	// image[2] is blue, from 0 to 255.
	//
	// Now you know what it does.
	//
	// -vmunix
	unsigned char *image = stbi_load(argv[1], &x, &y, &n, 3);

	if (!image){
		puts("THERE IS AN ERROR IN LOADING THE IMAGE!!!");
		return 1;
	}

	// This is the main loop of the program.
	int scanx = 1;
	int scany = 1;

	// For people just scanning the code (badun-ch)
	// (x * y) * 3 is because of above.
	//
	// FYI:
	// (x * y) => area of the image
	// * 3 => because a[x]=r, a[x+1]=g, a[x+2]=b
	for(long scan=0;scan<((x*y)*3);scan+=3){
		int r = image[scan];
		int g = image[scan+1];
		int b = image[scan+2];

		printf(
		    "\033[38;2;%d;%d;%dm%c\033[0m",
		    r, g, b, CHARACTER);

		scanx++;

		// You can add or subtract from x to make
		// the image tilted and funny looking
		if (scanx == x+1){
			printf("\n");
			scanx=1;
			scany++;
		}
	}

	stbi_image_free(image);
	return 0;
}
