//THIS IS CUSTOMER CLASS
//THIS CLASS CONTAIN CUSTOMER RELATED DATA
//NAME,PHONE:#,BOOK SEAT,MOVIE ID ,
//AND THEIR SETTER AND GETTER


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
class customer
{
  private:
      //private Data

      string phone_number;
      string name;
      int book_seat;
      int movieId;
  public:

      //Constructer
   customer()
   {
       phone_number="Null";
       name="NULL";
       book_seat=0;
       movieId=0;
   }

                                    //Below is Setters And Getters
   void setMovieId(int x)
   {
       movieId=x;
   }
   int getMovieId()
   {
       return movieId;
   }
   void setPhone(string ph)
   {  phone_number=ph; }

   void setName(string n)
   {  name=n; }

   void bookSeat(int s)
   { book_seat=s; }




  string getPhone()
  {  return phone_number; }

  int getBookSeat()
  {  return book_seat; }

  string getName()
  {  return name; }


};






/**    ##########  Class Movie
**                This Class contain Data About movies
**
**
*/

class BookingSystem
{
  private:  //Private Data

        int total_price;
        int id_number;
        int movie_price;      ///These are data types
        int seats;            ///that will be used to store
        int seat_left;
        string name;          ///related data
        string show_date;
        string format;
        string show_time;




public:
  BookingSystem()   //Constructer
  {
      total_price=0;
      id_number=0;
      movie_price=0;
      seats=0;
      seat_left=0;
      name="NULL";
      show_date="NULL";
      format="NULL";
      show_time="NULL";


  }

  //Setters and getters
  void setTotalPrice(int x)
  { total_price=x; }

  void setId(int x)
  { id_number=x; }


void setMoviePrice(int x)
{   movie_price=x; }


void setSeatLeft(int x)
{seat_left=seat_left-x; }


string setName(string x)
{name=x;}

string setFormat(string x)
{format=x;}

string setShowDate(string x)
{ show_date=x; }

string setShowTime(string x)
{ show_time=x; }





void setSeat(int x)
{
    seats=x;
    seat_left=x;
}
 int getPrice()
  { return total_price; }

  int getId()
  { return id_number; }


int getMoviePrice()
{   return movie_price; }

int getSeat()
{return seats; }


int getSeatLeft()
{return seat_left;}


string getName()
{return name;}

string getFormat()
{return format;}

string getShowDate()
{ return show_date; }

string getShowTime()
{ return show_time; }




};



/*********************************
*******************************************
***************************************************/


//This is Class Function
//This Class contain all the methods that will be used for different operations
//We will make 1000 objects of customer class , it mean maximmum users will be 1000
//We will make 20 objects of Class Movies so that Maximumm numbers of movies will be stored is 20
//There is also some varibles used in this class
//These Variables are defined at the start of the class in private section
//These functions are called from the main function and it will take data from user and send it to the other function
//         in other classes

//Example : This class will work as a bridge

// User->Main--call-->Functions-->Customer-data-->BookingSystem.

class functions{
public:
    //Max of 1000 customers
customer cus[1000];

//Indexer for movie array
int cus_current_place=0;


//object of booking system
BookingSystem  bookingSysObj[20];

//This is movie stored limit
const int movie_limit=20;

//This will stored how many movies are stored
int movie_stored=0;

//This will hold current index for the customer data to be entered ::
int current_place=0;











};

int main()
{



    return 0;
}
