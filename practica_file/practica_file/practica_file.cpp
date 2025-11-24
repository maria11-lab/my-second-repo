/*
bool IsEmptyFile(std::ifstream& file) {
	return file.peek() == EOF;
}
std::vector<int32_t>ReadDataFromFile(const std::string& filename) {
	std::ifstream in(filename);
	if (!in.is_open()) {
		throw "error: could not open file";
	}
	if (IsEmptyFile(in)) {
		throw "error: file is empty";
	}
	std::vector<int32_t>num;
	int x;
	while (in >> x) {
		num.push_back(x);
	}
	return num;
}
void PrintVector(const std::vector<std::string>& vector) {
	for (int i = 0; i < vector.size(); ++i) {
		std::cout << vector[i] << "\n";
	}
}
double CalculateAvarage(const std::vector<int32_t>& num) {
	int64_t sum = std::accumulate(num.begin(), num.end(), int64_t{});
	return static_cast<double>(sum) / num.size();
}
void WriteAvgToOutputFile(const std::string& filename, double avg) {
	std::ofstream out{ filename };

	if (!out.is_open()) {
		throw "error: could not open file";
	}
	out << avg << std::endl;
}
int main() {
	const std::string input_file{ "input.txt" };
	const std::string output_file{ "output.txt" };
	try {
		std::vector<int32_t>num = ReadDataFromFile(input_file);

		double avg = CalculateAvarage(num);
		WriteAvgToOutputFile(output_file, avg);
		std::cout << "Everything is fine";
	}
	catch (const char* msg) {
		std::cerr << msg;
	}
}*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
bool IsEmpty(std::ifstream& in) {
	return in.peek() == EOF;
}
std::vector<std::string> ReadDataFromFile(const std::string& inFilename) {
	std::ifstream in (inFilename);
	if (!in.is_open()) {
		throw"Error! infile not open";
	}
	if (IsEmpty(in)) {
		throw"Error! infile is  empty";
	}
	std::vector<std::string> text;
	std::string str;
	while (std::getline(in, str)) {
		text.push_back(str);
	}
	in.close();
	return text;
}
void PrintVectorToFile(const std::string& outFilename, std::vector<std::string> text) {
	std::ofstream out(outFilename);
	if (!out.is_open()) {
		throw"Error! outfile not open";
	}
	for (size_t i = 0; i < text.size(); ++i) {
		out << text[i] << "\n";
	}
	out.close();
}
int main() {
	try {
		const std::string inFileName = "INPUT.txt";
		const std::string outFileName = "OUTPUT.txt";
		ReadDataFromFile(inFileName);
	}
	catch (const char* msg) {
		std::cout << msg;
	}
	return 0;
}
