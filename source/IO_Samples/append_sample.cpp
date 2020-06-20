/*
 * This code sample demonstrates appending to a file.
 * author B.Bultena
 */

#include<iostream>
#include<fstream>
	using std::cout;
	using std::cin;
	using std::string;
	using std::endl;
	using std::ofstream;

int main() {
	// note that if this file does not exist, it
	// will be created, and the output stream will append
	// to the beginning of the file.
	string filename = "silly_song.txt";

	// Similar to not appending, adds another parameter,
	// indicating that we want to 'app'end.
	ofstream writer(filename, ofstream::app);

	writer << "This is a silly song, indeed!\n";
	
	writer.close();

	cout << "All done.\n";
	return 0;
}
