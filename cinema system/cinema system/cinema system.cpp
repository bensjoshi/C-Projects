// cinema system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ticket {
public:                     //Class for the ticket
    string BookingName;         
    string Movie;              //object names for ticket
    string Screen;
    string SeatNum;
    string time;

};


       

string MovieSelect() {              //film selection function
    cout << "  \n";
    cout << "Please select a movie. (enter 1, 2, 3 or 4)\n";
    cout << "  \n";
    cout << "1) Star Wars  \n";
    cout << "2) Spider Man  \n";
    cout << "3) Avengers  \n";
    cout << "4) Cars  \n";
    cout << "  \n";
   
    int FilmChoice;
    cin >> FilmChoice;
    system("CLS");
    

    if (FilmChoice == 1) {
        return ("Star Wars");
    }
    else if (FilmChoice == 2){
        return ("Spider Man");
    } 
    else if (FilmChoice == 3) {
        return ("Avengers");
    }
    else if (FilmChoice == 4) {
        return ("Cars");
    }
    else {
        cout << "choice does not exist. Please enter a number from the choices.";
        MovieSelect();
    }

}

string timeselect()         //time selection function
{

    cout << "  \n";
    cout << "Please select a showing. (enter 1, 2, 3 or 4)\n";
    cout << "  \n";
    cout << "1)10.00 \n";
    cout << "2)13.00 \n";
    cout << "3)16.00 \n";
    cout << "4)19.00 \n";
    cout << "  \n";
    int ShowingChoice;
    cin >> ShowingChoice;
    system("CLS");
    if (ShowingChoice == 1) {
        return ("10.00");
    }
    else if (ShowingChoice == 2) {
        return ("13.00");
    }
    else if (ShowingChoice == 3) {
        return ("16.00");
    }
    else if (ShowingChoice == 4) {
        return ("19.00");
    }
    else {
        cout << "choice does not exist. Please enter a number from the choices.";
        timeselect();
    }
}




int main()
{
    cout << "  \n";
    cout << "       Welcome To Ben's Cinema Booking system.\n";
    cout << "  \n";
    cout << "Enter Your name to start: \n";
    string name;
    cin >> name;
    system("CLS");
    ticket MyTicket;
    MyTicket.BookingName = name;
    MyTicket.Movie = MovieSelect();         //runs functions for selections
    MyTicket.time = timeselect();

    if (MyTicket.Movie == "Star Wars") {
        MyTicket.Screen = "1";
    }
    else if (MyTicket.Movie == "Spider Man") {
        MyTicket.Screen = "2";
    }
    else if (MyTicket.Movie == "Avengers") {
        MyTicket.Screen = "3";
    }
    else  {
        MyTicket.Screen = "4";
    }


    const char FULL = 'X';			//Seat taken
    const char EMPTY = '-';		   //Seat open
    const int rows = 10;			   //Number of rows
    const int columns = 10;		   //Number of seats per row
    char grid[rows][columns];		 //Array to hold seating chart
    int RowChoice, ColumnChoice;
    string seat1, seat2;
    cout << "----------------------------\n";
    cout << "-------Screen is here-------\n";
    cout << "----------------------------\n";
    cout << "Seats 1 2 3 4 5 6 7 8 9 10\n";         //Seating plan

    for (int count = 0; count < 9; count++)         //Makes a 'grid' using for loops
    {
        cout << endl << "Row " << (count + 1);

        for (int count2 = 0; count2 < 10; count2++)
        {
            cout << " " << grid[count][count2];
        }
    }
    cout << "\n";
    cout << "Please select the row you would like to sit in: ";
    cin >> RowChoice;
    seat1 = to_string(RowChoice);
    cout << "Please select the seat you would like to sit in: ";
    cin >> ColumnChoice;
    seat2 = to_string(ColumnChoice);

    if (grid[RowChoice][ColumnChoice] == 'X')
    {
        cout << "Sorry that seat is sold-out, Please select a new seat.";
    }
    else {
        grid[RowChoice][ColumnChoice] = FULL;
    }

    system("CLS");
    cout << "----------------------------\n";
    cout << "-------Screen is here-------\n";
    cout << "----------------------------\n";
    cout << "Seats 1 2 3 4 5 6 7 8 9 10\n";
    for (int count = 0; count < 9; count++)
    {
        cout << endl << "Row " << (count + 1);

        for (int count2 = 0; count2 < 10; count2++)
        {
            cout << " " << grid[count][count2];
        }
    }
    cout << "\n";
    cout << "Press enter to confirm seat booking";
    cout << "\n";
    system("pause");
    system("CLS");
    cout << "\n";
    cout << "Your Ticket:\n";
    cout << "\n"; 
    cout << "   -------------\n";
    cout << "   |" << (MyTicket.BookingName) << "\n";
    cout << "   |" << (MyTicket.Movie) << "\n";
    cout << "   |" << (MyTicket.time) << "\n";
    cout << "   |" << "Screen " << (MyTicket.Screen) << "\n";
    MyTicket.SeatNum = seat2;
    cout << "   |" << "Row " + seat1 << "\n";
    cout << "   |" << "Seat " + MyTicket.SeatNum <<"\n";
    cout << "\n";
    cout << "\n";
    cout << "Enjoy the film!\n";
    system("pause");

    ofstream MyWriteFile("ticket.txt");         //outputs ticket text file

    // Write to the file
    MyWriteFile << MyTicket.BookingName << "\n";        
    MyWriteFile << MyTicket.Movie << "\n";
    MyWriteFile << MyTicket.time << "\n";
    MyWriteFile << "Screen " << MyTicket.Screen << "\n";
    MyWriteFile << "Row " + seat1 << "\n";
    MyWriteFile<< "Seat " + MyTicket.SeatNum << "\n";
    // Close the file
    MyWriteFile.close();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
