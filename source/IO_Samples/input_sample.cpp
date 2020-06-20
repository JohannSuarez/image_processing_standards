/**
 * A demonstration for opening a text file and
 * 'reading' its contents.
 * author: B.Bultena
 */

#include <iostream>
#include <fstream>
	using std::cout;
	using std::endl;
	using std::string;
	using std::ifstream;


int main() {
	// Create an istream object, called reader, that 
	// opens a file called "some_data.txt",
	// that both exists and is present in the same directory

	string line; // to hold the lines of the file

	// filename does not include the path name, so it must exist
	// in the same directory as this source file. 
	// You can use any readable file you want, including "this" file.
	string filename = "mytxt.txt"; 

	// lets the input stream try to open the file
	// If it cannot, then it will set a flag that
	// will cause the code not to enter the body of
	// the while loop
	ifstream reader(filename);

	// If there is a problem getting the line
	// or if the eof (end-of-file) has been reached
	// then the operation will make the 
	// while condition statement evaluate to false
	while (getline(reader,line)) {
		cout << line << endl;
	}
	// ask the ifstream to close the file
	reader.close();

	cout << "All done!\n";
	return 0;
}
