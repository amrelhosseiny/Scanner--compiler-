#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

string token;

short int state;

short int start = 1, num = 2, id = 3, assign = 4, comment = 6, special = 7, reserved = 8, error = 10;

ofstream ofile;


void done() {
	
	if (state == start ) {
		ofile << "unexpected output at token \n"<< token;
	}
	else if (state == num) {
		ofile << token << " : Number \n";
	}
	else if (state ==id ) {
		ofile << token << " : Identifier \n";
	}
	else if (state ==comment ) {
		ofile << token << " : Comment \n";
	}
	else if (state ==special ) {
		ofile << token << " : Special Symbol \n";
	}
	else if (state == reserved) {
		ofile << token << " : Reserved Word \n";
	}
	else if (state = error) {
		ofile << "ERROR, unexpected output at :" << token;
	}

}


void main() {
	
	ifstream myReadFile;
	myReadFile.open("tiny_sample_code.txt");
	string input, line;
	cout << "Welcome to Scanner assignment \n ";
	cout << "A file \"scanner_output.txt\" will be generated with the scanner output";


	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) { myReadFile >> line; input += " ";input+=line; }
	}
	else cout << "Error opening file, Please check file name and location.";
	//char* inputChar = new char[input.size()];
	//strcpy_s(inputChar, 10000,input.c_str());
	
	ofile.open("scanner_output.txt");
	ofile << "Scanner Output for file \"tiny_sample_code.txt\" : \n";
	




	char x;

	state = start;


	for (int i = 0;i < input.size();i++) {
		x = input[i];
		if (x == ' ' && state!=comment) {
			state = start;
		}
		else if (x == '{') {
			token = x;
			state = comment;
		}
		else if (state == start) {
			if (isdigit(x)) {
				state = num;
				token = "";
				token.push_back(x);
				if (!isdigit(input[i+1])) {
					done();
					state = start;
				}
			}
			else if (x == '+' || x == '-' || x == '/' || x == '*' || x == ';' || x == '=' || x == '<' || x == '>' || x == '(' || x == ')') {
				token = x;
				state = special;
				done();
				state = start;
			}
			else if (x == ':') {

				if (input[i + 1] == '='){
					token = "";
					token.push_back(x);
					token.push_back(input[i + 1]);
					state = special;
					done();
					input[i + 1] = ' ';
					state = start;
				}
				else {
					token = x;
					state = error;
					done();
					state = start;
				}
			}
			else if (isalpha(x) || x=='_') {
				token = "";
				if (x == 'i' && input[i + 1] == 'f') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					//token = x + input[i + 1];
			
					state = reserved;
					done();
					input[i + 1] = ' ';
					state = start;
				}
				else if (x == 't' && input[i + 1] == 'h' && input[i + 2] == 'e' && input[i + 3] == 'n') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					token.push_back(input[i + 3]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					state = start;
				}
				else if (x == 'e' && input[i + 1] == 'l' && input[i + 2] == 's' && input[i + 3] == 'e') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					token.push_back(input[i + 3]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					state = start;
				}
				else if (x == 'r' && input[i + 1] == 'e' && input[i + 2] == 'a' && input[i + 3] == 'd') {
				//	//token = x + input[i + 1] + input[i + 2] + input[i + 3];
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i+2]);
					token.push_back(input[i + 3]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					state = start;
				}
				else if (x == 'e' && input[i + 1] == 'n' && input[i + 2] == 'd' ) {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					state = start;
				}
				else if (x == 'r' && input[i + 1] == 'e' && input[i + 2] == 'p' && input[i + 3] == 'e' && input[i + 4] == 'a' && input[i + 5] == 't') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					token.push_back(input[i + 3]);
					token.push_back(input[i + 4]);
					token.push_back(input[i + 5]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					input[i + 4] = ' ';
					input[i + 5] = ' ';
					state = start;
				}
				else if (x == 'u' && input[i + 1] == 'n' && input[i + 2] == 't' && input[i + 3] == 'i' && input[i + 4] == 'l') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					token.push_back(input[i + 3]);
					token.push_back(input[i + 4]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					input[i + 4] = ' ';
					state = start;
				}
				else if (x == 'w' && input[i + 1] == 'r' && input[i + 2] == 'i' && input[i + 3] == 't' && input[i + 4] == 'e') {
					token.push_back(x);
					token.push_back(input[i + 1]);
					token.push_back(input[i + 2]);
					token.push_back(input[i + 3]);
					token.push_back(input[i + 4]);
					state = reserved;
					done();
					input[i + 1] = ' ';
					input[i + 2] = ' ';
					input[i + 3] = ' ';
					input[i + 4] = ' ';
					state = start;
				}
				else {
					token.push_back(x);
					if (isalnum(input[i + 1]) || input[i+1]=='_') {
						state = id;
					}
					else {
						state = id;
						done();
						state = start;
					}
				}
			}
		
			else {
				token = x;
				state = error;
				done();
				state = start;
			}
		}
		else if (state == comment) {
			if (x == '}') {
				token += x;
				done();
				state = start;
			}
			else {
				token += x;
				state = comment;
			}
		}
		else if (state == num) {
			token.push_back(x);
			if (isdigit(input[i + 1])) {
				state = num;
			}
			else {
				done();
				state = start;
			}
		}
		else if (state == id) {
			token.push_back(x);
			if (isalnum(input[i + 1]) || input[i+1]=='_') {
				state = id;
			}
			else {
				done();
				state = start;
			}
		}
	}




	myReadFile.close();
	ofile <<  "\n End of Scanner.";
	ofile.close();


}

