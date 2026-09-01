
#include <iostream>
using namespace std;

double reorderCost(int qty, double unitPrice) {
	return qty*unitPrice;

}
double reorderCost(double qty, double unitPrice) {
	return qty*unitPrice;

}
double reorderCost(int qty, double unitPrice,double taxRate) {

	double totalA = qty*unitPrice;
	//cout<<"Total A: " << totalA << endl;
	double taxA = totalA * (taxRate / 100.0);
	//cout << "Tax: " << taxA << endl;
	double finalA = totalA + taxA;
	//cout << "finalA-including Tax: " << finalA << endl;
	return finalA;

}

double applyDiscount(double price,double discountPercent = 10.0){

	double disA = price * (10.0 /100.0);
	//cout<<"Dis: " << disA << endl;
	double finaldisA = price - disA;
	//cout<<"final-Dis-A: " << finaldisA << endl;

	return finaldisA;
}

int main(){

	cout << "Integer quantity: " << reorderCost(5,30) <<endl;
	cout << "Fractional (by weight): " << reorderCost(5.0,30)<<endl;
	cout << "with tax: " << reorderCost(5,30,18)<<endl;
	cout << "applyDiscount: " << applyDiscount(30)<<endl;


	return 0;
}
