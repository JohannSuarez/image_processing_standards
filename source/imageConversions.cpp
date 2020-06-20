#include "ImageType.hpp"

/*

Needs attention: 

makeAscii

Scale



*/



/* 
 * PUT YOUR HEADER INFO HERE
 */

void makeAscii(const ImageType &image, string outfile) {

	ImageType ascii = image;

	int rows = image.getHeight();
	int cols = image.getWidth();
	int **asciipixels = ascii.getPixels();


	for(int r = 0; r < rows; r++) {
		for(int c = 0; c < cols; c++){
			//convert each to pixel to ascii value switch statement

		}
		std::cout << std::endl;
	}


}

ImageType invert(const ImageType &image) {
	// make a copy of the original
	ImageType inverted = image;

	// make changes to this image

	// make local copies of everything you need
	int rows = inverted.getHeight();
	int cols = inverted.getWidth();
	int gs = inverted.getGrayscale();
	int ** pixels  = inverted.getPixels(); 


	for(int r = 0; r < rows; r++) {
		for(int c=0; c < cols; c++) {
			pixels[r][c] = gs - pixels[r][c]; //To build other functions, you REALLY need to know how this works.

		}


	}



	return inverted;
}

ImageType verticalFlip(const ImageType &image) {

	ImageType vflipped = image;

	int rows = vflipped.getHeight();
	int cols = vflipped.getWidth();
	int temp[rows][cols];
	int ** pixels = vflipped.getPixels();

	for(int r = 0; r < rows; r++) {
		for(int c= 0; c < cols; c++) {
			temp[r][c] = pixels[rows - r - 1][c]; //why minus one?
			}
	}

	for(int r = 0; r < rows; r++) {
		for(int c= 0; c < cols; c++) {
			pixels[r][c] = temp[r][c];
			}
	}	



	return vflipped;
}

ImageType horizontalFlip(const ImageType &image) {

	ImageType hflipped = image;


	int rows = hflipped.getHeight();
	int cols = hflipped.getWidth();
	int temp[rows][cols];
	int ** pixels = hflipped.getPixels();

	for(int r = 0; r < rows; r++) {						//Loading the pixels to temporary
		for(int c= 0; c < cols; c++) {
			temp[r][c] = pixels[r][cols - c - 1];
			}
	}

	for(int r = 0; r < rows; r++) {						//Returning the sorted pixels to image
		for(int c= 0; c < cols; c++) {
			pixels[r][c] = temp[r][c];
			}
	}	

	return hflipped;
}

ImageType rotate(const ImageType &image) {

	//ImageType imagesource = image;
	ImageType rotated_image(image.getWidth(), image.getHeight(), image.getGrayscale()); //creates rotated images from information of images, but starts completely blank



	int rows = rotated_image.getHeight();
	int cols = rotated_image.getWidth();
	int **grid = rotated_image.getPixels();				//pointers to rotated image arrays

	for(int r = 0; r<rows; r++)	{
		for(int c = 0; c<cols; c++)	{
		grid[r][c] = image.getPixelVal(cols -1 -c,r);		//loads pixels from original image to pointers.

		}
	}

	



	return rotated_image;

}


ImageType scale(const ImageType &image, double scalefactor) {
	// Create a new image that is the required new size

	// change this statement: it currently creates a useless image object.
	ImageType scaled(0,0,0);

	return scaled;
}
		
			
int main(int argc, char* argv[]) {	//argc = argument count	//char* argv[]

/********************************************/
// THiS PART IS ALL DONE FOR YOU:
	if (argc < 4) {
		cout << "Invalid program execution, please use:\n";
		cout << "./go <inputfile> <outputfile> <operation>\n";
		return(0);
	}

	string infile = argv[1];
	string outfile = argv[2];
	string task = argv[3];

	// Create an image object from a file
	ImageType image(infile);

//FOR DEBUG PURPOSES:
//image.print();

/****************** END ***************nvert********/

// YOU WILL NEED TO ADD STATEMENTS TO THE CODE THAT FOLLOWS
// THE SET UP FOR TASK invert HAS BEEN SET UP FOR YOU.
// SIMILAR PROCEDURES ARE REQUIRED FOR THE REMAINING TASKS

	// Depending on the task, do what is necessary with the image,
	// by calling the appropriate function.
	if (task == "verticalflip") {
		ImageType vflipped= verticalFlip(image);
		vflipped.writeToFile(outfile);
	} else if (task == "horizontalflip") {
		ImageType hflipped= horizontalFlip(image);
		hflipped.writeToFile(outfile);
	} else if (task == "invert") {
		ImageType inverted = invert(image);
		inverted.writeToFile(outfile);
	} else if (task == "rotate") {
		ImageType rtated = rotate(image);
		rtated.writeToFile(outfile);
	} else {
		cout << "Error in the task: Do not know what " << task << " means.\n";
		return 0;
	}


	
	

	cout << "All done\n";
	return 0;
}
