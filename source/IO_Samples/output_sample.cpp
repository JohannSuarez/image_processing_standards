/* 
 * An example of writing to a file. 
 * Similar to the input_sample, but uses
 * an ofstream object.
 */

#include <iostream>
#include <fstream>
	using std::cout;
	using std::endl;
	using std::string;
	using std::ofstream;


int main() {
	string filename = "silly_song.txt";
	int bottles_of_beer = 2;

	// if the file does not already exist,
	// then the stream will create it.
	ofstream writer(filename);

	// note how the format is similar to using 'cout' to
	// write to the console.
	for (int i=bottles_of_beer; i>0; i--) {
		writer << i << " bottles of beer on the wall.\n";
		writer << i << " bottles of beer.\n";
		writer << "You take one down, you pass it around,\n";
		if (i != 1) {
			writer << i-1 << " bottles of beer on the wall.\n";
		} else {
			writer << "No more bottles of beer on the wall.\n";
		}
		writer << endl;
	}

	// ask the output stream to close the file.
	writer.close();
	cout << "All done!\n";
	return 0;
}
