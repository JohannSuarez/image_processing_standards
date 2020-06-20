#ifndef IMAGE_TYPE_H
#define IMAGE_TYPE_H

#include <iostream>
#include <fstream>
#include <iomanip>
	using std::cout;
	using std::ifstream;
	using std::ofstream;
	using std::cin;
	using std::endl;
	using std::ios;
	using std::string;

class ImageType {
public:
	ImageType(int height, int width, int grayscale);
	ImageType(string filename);
	ImageType(const ImageType &orig);
	~ImageType() { delete [] pixelValues; }
	int getHeight() const {return height;}
	int getWidth() const {return width;}
	int getGrayscale() const {return grayscale;}
	void setHeight(int h) {if (h>=0) height = h;}
	void setWidth(int w) {if (w>=0) width = w;}
	void setGrayScale(int gs) {if (gs>=0) grayscale = gs;}
	void setPixelVal(int r, int c, int value) {pixelValues[r][c] = value;}
	int getPixelVal (int r, int c) const {return pixelValues[r][c];}
	int** getPixels() {return pixelValues;}
	void print();
	void writeToFile(string filename);

private:
	int height, width; 
	int grayscale; // range of black/white range (generally between 2 and 256)
	int **pixelValues; // the 2D array.
	void setImageInfo(int h, int w, int gs);
};

#endif
