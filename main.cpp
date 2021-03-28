#include<iostream>
#include<string>
#include<fstream>
std::string prazni_mesta(int n) {
	std::string rez;
	for (int i = 0; i < n; i++) {
		rez += " ";
	}
	return rez;
}
int main() {
	std::ofstream barkod_paste("barkod_paste.txt");
	std::ifstream slika("barkod.ppm");
	std::string pikseli;
	std::getline(slika, pikseli); //se ignorira
	unsigned x;
	slika >> x;
	std::getline(slika, pikseli); //se ignorira
	std::getline(slika, pikseli); //se ignorira
	std::getline(slika, pikseli);
	int broj_b = 0;
	int broj_w = 0;
	for (int i = 0; i < x; ++i) {
		if ((unsigned)pikseli[3*i] != 0) {
			++broj_w;
			if (broj_b != 0) {
				barkod_paste << "||" << prazni_mesta(broj_b/2) << "||";
				broj_b = 0;
			}
		}
		else {
			++broj_b;
			if (broj_w != 0) {
				barkod_paste << prazni_mesta(broj_w/2);
				broj_w = 0;
			}
		}
	}
	if (broj_b != 0) {
		barkod_paste << "||" << prazni_mesta(broj_b / 2) << "||";
	}
}