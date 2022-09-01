/*
Name : JOHAN ZAFRI BIN JOHAR
Student ID: 2020463882
Group : CS1101F
Implementation of a program for Rotan Tunggal Fabric Folding Service.
*/

#include <iostream> //to handle output (cout) and input (cin) statements
#include <ctype.h>  //to handle several functions that are useful for testing and mapping characters
#include <iomanip>  //to manipulate and make the output of the program neater and presentable

using namespace std; // to tell the compiler where to look for names in the libraries

void inputData(long &, char &, double &, char &); // function prototype for InputData()
double calcBasicCharge(double);                   // function prototype for calcBasicCharge()
void calcAddService(char, double &);              // function prototype for calcAddService()
void displayReceipt(long, double, char, double);  // function prototype for displayReceipt()

int main() // main function
{
    // declare input variables - place a space to store value in computer memory
    long customer_id;
    char customer_status;
    double weight_fabric;
    char additional_service;
    char more_customer = 'y'; // initial value for more_customer

    // declare output variables - place a space to store value in computer memory
    double total_charge = 0;
    int count_customer = 0;
    double total_weight = 0;
    double total_collection = 0;

    // declare processing items for calculations
    double additional_charge = 0;
    double basic_charge = 0;
    double add_service = 0;

    // to display at the program's screen console
    cout << "\t\t\t *** Welcome to Rotan Tunggal Fabric Folding Service *** " << endl;

    // while loop to check and tolower if more_customer is equal to 'y'
    while (tolower(more_customer) == 'y')
    {
        // function call for inputData()
        inputData(customer_id, customer_status, weight_fabric, additional_service);

        // function call for calcBasicCharge()
        calcBasicCharge(weight_fabric);

        // function call for calcAddService()
        calcAddService(additional_service, additional_charge);

        // to assign value for basic_charge from value that returned in calcBasicCharge()
        basic_charge = calcBasicCharge(weight_fabric);

        // to assign value for add_service from value (additional_charge) passed by reference parameter in calcAddService()
        add_service = additional_charge;

        // calculate total_charge - in CPU and memory
        total_charge = basic_charge + add_service;

        // checks if toupper(customer_status) is equal to 'R'
        if (toupper(customer_status) == 'R')

            // calculate total_charge for regular customers - in CPU and memory
            total_charge = total_charge - 1.00;

        // function call displayReceipt()
        displayReceipt(customer_id, weight_fabric, additional_service, total_charge);

        // calculate count_customer++ and to update number of customers - in CPU and memory
        count_customer++;

        // calculate total_weight - in CPU and memory
        total_weight += weight_fabric;

        // calculate total_collection - in CPU and memory
        total_collection += total_charge;

        cout << "\n More customer? (y-yes,n-no): "; // prompt user to enter a character for more_customer

        cin >> more_customer; // read value from keyboard and store in more_customer

    } // end of while loop

    // to display output (count_customer, total_weight, total_collection) at the screen console (monitor)
    cout << "\n Count of Customer: " << count_customer << endl;
    cout << " Total weight of fabric from all customer: " << fixed << setprecision(2) << total_weight << " kilograms " << endl;
    cout << " Total collection from all customer: RM " << fixed << setprecision(2) << total_collection << endl;

    // to display and tell that the program has ended at the screen console
    cout << "\n\t\t\t *** End Of Program *** " << endl;

    return 0;
} // end of main()

// function definition for inputData()
void inputData(long &pass_id, char &pass_status, double &pass_weight, char &pass_add)
{
    cout << "\n Enter Customer ID:"; // prompt user to enter number for customer ID

    cin >> pass_id; // read value from keyboard, store in pass_id and pass it through reference parameter

    cout << " Enter Customer Status (R-regular,W-new):"; // prompt user to enter a character for customer status

    cin >> pass_status; // read value from keyboard, store in pass_status and pass it through reference parameter

    cout << " Enter Weight of Fabric:"; // prompt user to enter value for weight of fabric

    cin >> pass_weight; // read value from keyboard, store in pass_weight and pass it through reference parameter

    // to display at the screen console about additional service that has been provided by Rotan Tunggal Fabric Folding Service
    cout << "\n Additional Service: " << endl;
    cout << " a)\t No additional service " << endl;
    cout << " b)\t Fabric collection service only - extra charge RM 3.00 " << endl;
    cout << " c)\t Fabric delivery service only - extra charge RM 3.00 " << endl;
    cout << " d)\t Fabric collection and delivery service - extra charge RM 6.00 " << endl;
    cout << " Additional Service No? "; // prompt user to enter a charater for additional service
    cin >> pass_add;                    // read value from keyboard, store in pass_add and pass it through reference parameter
} // end of inputData()

double calcBasicCharge(double kg) // function definition for calcBasicCharge()
{
    // declare processing item to be returned after process has been done
    double pass_basiccharge;

    // checks if kg is less or equal to 4
    if (kg <= 4)

        // calculate pass_basiccharge - in CPU and memory
        pass_basiccharge = kg * 2.00;

    // checks if kg is greater than 4
    else
    {
        // calculate pass_basiccharge - in CPU and memory
        pass_basiccharge = (kg - 4) * 1.50;
        pass_basiccharge += 8.00;
    }

    return pass_basiccharge; // return pass_basiccharge value
} // end of calcBasicCharge()

// function definition for calcAddService()
void calcAddService(char service, double &pass_addcharge)
{
    // checks if tolower(service) is equal to 'a'
    if (tolower(service) == 'a')

        // assign value to pass_addcharge and pass it through parameter
        pass_addcharge = 0.00;

    // checks if tolower(service) is equal to 'b' or 'c'
    if (tolower(service) == 'b' || tolower(service) == 'c')

        // assign value to pass_addcharge and pass it through parameter
        pass_addcharge = 3.00;

    // checks if (tolower(service) is equal to 'd'
    if (tolower(service) == 'd')

        // assign value to pass_addcharge and pass it through parameter
        pass_addcharge = 6.00;
} // calcAddService()

// function definition for displayReceipt()
void displayReceipt(long id, double kg, char service_no, double total)
{
    // to display the name of the business, receipt and to create indentation
    cout << "\n Rotan Tunggal Fabric Folding Service " << endl;
    cout << " --------------------------------------- " << endl;

    // to display (customer_id, weight_fabric, additional_service, total_charge) that has been passed through reference parameter
    cout << "\n Customer ID: " << id << endl;
    cout << " Fabric weight:" << fixed << setprecision(2) << kg << " kg " << endl;
    cout << " Additional Service :" << service_no << endl;
    cout << " Total Payment:RM " << fixed << setprecision(2) << total << endl;
    // to display at the screen console and to create indentation
    cout << "\n ***THANK YOU*** " << endl;
    cout << " --------------------------------------- " << endl;
} // end of displayReceipt()