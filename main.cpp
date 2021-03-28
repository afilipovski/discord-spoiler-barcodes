#include<iostream>
#include<string>
#include<fstream>
std::string space(int n) {
	std::string rez;
	for (int i = 0; i < n; i++) {
		rez += " ";
	}
	return rez;
}
int main() {
	std::string path;
	std::cout << "Enter the path of the pixmap (.PPM): ";
	std::cin >> path;
	std::ifstream pixmap(path);
	std::string data;
	std::getline(pixmap, data);
	unsigned x;
	pixmap >> x;
	std::getline(pixmap, data); std::getline(pixmap, data); //ignored
	std::getline(pixmap, data);
	int num_b = 0;
	int num_w = 0;
	std::ofstream barcode_paste("barcode_paste.txt");
	for (int i = 0; i < x; ++i) {
		if ((unsigned)data[3*i] != 0) {
			++num_w;
			if (num_b != 0) {
				barcode_paste << "||" << space(num_b/2) << "||";
				num_b = 0;
			}
		}
		else {
			++num_b;
			if (num_w != 0) {
				barcode_paste << space(num_w/2);
				num_w = 0;
			}
		}
	}
	if (num_b != 0) {
		barcode_paste << "||" << space(num_b / 2) << "||";
	}
}
