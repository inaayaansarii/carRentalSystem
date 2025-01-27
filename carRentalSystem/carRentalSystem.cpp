
/*
Author: Inaaya Ansari
Porgram Description: This program adjusts rental prices based on the number of days a car is rented, 
applying daily rates, discounts for longer rentals, and additional fees like insurance or mileage.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CarRental {

	//constructor variable
	private:
		string rentalID;
		string customerName;
		string carModel;

		double rentalDays;
		double dailyRate;
		double totalCost;

	public:
		//parameter consturctor
		CarRental(string rental, string name, string car, double rentalD, double daily) {
			rentalID = rental;
			customerName = name;
			carModel = car;
			rentalDays = rentalD;
			dailyRate = daily;
			totalCost = 0.0;
		}

		//default constructor
		CarRental() {
			rentalID = " 1111";
			customerName = "John Smith";
			carModel = "Lexus";
			rentalDays = 0.0;
			dailyRate = 0.0;
			totalCost = 0.0;
		}

		//mutator function
		void setRentalDays(double rD) {
			//making sure the number is postive and if it isnt continue asking the user to enter a positive number
			while(rD <= 0) {
				cout << "Invalid input. Enter a positive number." << endl;
				cin >> rD;
			}
			//otherwise set rental days to parameter variable
			rentalDays = rD;
			
		}

		void setDailyRate(double d) {
			//making sure the number is postive and if it isnt continue asking the user to enter a positive number
			while (d <= 0) {
				cout << "Invalid input. Enter positive value." << endl;
				cin >> d;
			}
			//otherwise set rental days to parameter variable
			dailyRate = d;
		}

		void calcTotalCost() {
			double intialCost = rentalDays * dailyRate; //calculate cost without any discount by multiplying amount of days with rate

			//adding discount based on the amount of days the car is being rented

			if (rentalDays >= 4 && rentalDays <= 7) {
				totalCost = intialCost * .95; //5% discount and using .95 beccause 100- 5 = 95
			}
			else if (rentalDays > 7) {
				totalCost = intialCost * .90; //10% discount and using .95 beccause 100- 10 = 90
			}
			else {
				totalCost = intialCost; // no discount applies
			}
		}

		void display() { 
			cout << "---- Rental Details ----" << endl;
			cout << "Rental ID: " << rentalID << endl;
			cout << "Customer Name: " << customerName << endl;
			cout << "Car Model: " << carModel << endl;
			cout << "Rental Days: " << rentalDays << endl;
			cout << "Daily Rate: " << fixed << setprecision(2) << dailyRate << endl;
			cout << "Total Cost: " << fixed << setprecision(2) << totalCost << endl;
			cout << "------------------------------------" << endl;

		}

		//accesor function
		double getTotalCost() {
			return totalCost;
		}
};

int main()
{
	//creating the variables
	string rentalID;
	string customerName;
	string carModel;

	double rentalDays;
	double dailyRate;

	double totalCost = 0.0; //variable to find the final cost of rental car
	int count;

	//ask the user how many days they would like to hold the car
	cout << "Enter Number of rentals: " << endl;
	cin >> count;
	cin.ignore(); //ignore thhe new line

	//create object as an array that only consists of 50 cars
	CarRental car[50];

	//loop to accept multiple rentals and end when amount of rentals has been reached
	for (int i = 0; i < count; i++) {

		//printing number of rental
		cout << "Rental " << i + 1 << endl;

		//getting user input
		cout << "Enter Rental ID: " ;
		cin >> rentalID;
		cin.ignore(); //ignore the new line so it dosent automatically skip to the next line

		cout << "Enter Customer Name: ";
		getline(cin, customerName); // use getline to read white spaces

		cout << "Enter Car Model: ";
		getline(cin, carModel); // use getline to read white spaces

		cout << "Enter Retnal Days: ";
		cin >> rentalDays;

		cout << "Enter Daily Rate: $";
		cin >> dailyRate;

		
		car[i] = CarRental(rentalID, customerName, carModel, rentalDays, dailyRate); //the array goes through the loop and finds the information that has been entered
		car[i].calcTotalCost(); //calculates cost of the car
	
	
	}

	//loops through the car that has been entered, displays the information, and calulates the total
	for (int i = 0; i < count; i++) {
		car[i].display();
		totalCost += car[i].getTotalCost();
	}


	//total amount print statement
	cout << "Total Revenue from Rentals: $" << fixed << setprecision(2) << totalCost << endl;
	
	return 0;
}

