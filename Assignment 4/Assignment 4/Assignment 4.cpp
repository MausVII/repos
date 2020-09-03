#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
using namespace std;

mt19937 rng;
uniform_int_distribution<int> IDDist(1000, 9999);
uniform_real_distribution<float> priceDist(1.0f, 50.0f);
uniform_int_distribution<int> nSoldDist(1, 100);

class Product {
public:
	Product() {
		ID = IDDist(rng);
		price = priceDist(rng);
		nSold = nSoldDist(rng);
	}
	int GetID() const {
		return ID;
	}
	float GetPrice() const {
		return price;
	}
	int GetNSold() const {
		return nSold;
	}
private:
	int ID;
	float price;
	int nSold;
};

void WriteOutput(Product* pProducts, int const nProducts);

int main()
{
	const int nProducts = 10;
	Product* pProducts = new Product[nProducts];

	WriteOutput(pProducts, nProducts);
}

void WriteOutput(Product* pProducts, int const nProducts) {
	ofstream output;
	output.open("output.txt");
	output << "ID\t#Sold\tPrice\n";
	for (int i = 0; i < nProducts; i++) {
		output << fixed << setprecision(2)
			<< (pProducts + i)->GetID() << "\t"
			<< (pProducts + i)->GetNSold() << "\t"
			<< (pProducts + i)->GetPrice() << "\n";
	}
	output.close();
}