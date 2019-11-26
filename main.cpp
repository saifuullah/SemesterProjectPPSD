/**

This is Movie ticket booking system
User can use it to book different movies avalible in list
We can also edit any movie data, and add new movie and delete movies

**/


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






//This is book seat function
//This will take user name , phone number , and number of seats
//     user want to reserved ::::



void BookSeat()         ///Booking New seat function:
{

    cout<<"Movie List is Below "<<endl<<"Please Select a Movie and Enter asked information :) "<<endl<<endl;

    display_list();          //This will display list.....


    int var,id,setseatleft;  //General variable used
    cout<<"Enter Movie Id :"<<endl;
    cin>>id;

    if(checkId(id)==0)
        {
        cout<<"Sorry,  Wrong Id Input (Movie not found) "<<endl<<"Please Enter a correct Id "<<endl;
        cout<<"Enter  1 to Enter again or 0 to exit "<<endl;
        cin>>var;
        if(var==1)
            BookSeat();
              else
                 return ;
        }            //This will direct the user what to do ;

    else
    {
        string st;
        int x;     //Variables used for general purpose


         //Take name of user
      cout<<"Enter Customer Name  :  " ;
      cin>>st;
      cus[cus_current_place].setName(st);

       //Take customer Phone number
      cout<<"Enter Customer Phone Number " ;
      cin>>st;
      cus[cus_current_place].setPhone(st);

      //Take seats to be booked
      cout<<"Enter Number of Seats you want to reserved " ;
      cin>>x;

      if(x==0)
      {
           //If user enter 0 seats to be booked
           //Close program
        cout<<" 0 seats cannot be reserved ..!!!! "<<endl;
         return ;
      }

              //Else do the following work



            //general Purpose variables
        int problem,index;
        index=getObjectNum(id);





                //if the User want to reserved seats that is out of range of avalible seats (avillible < wanted )
                //We give choice to the user to reserved the remaining Seats or not
                //if yes seats reserved
                //if not close the function

        if((bookingSysObj[index].getSeatLeft()-x)<0)
    {
            cout<<"Sorry, You can only Reserve  "<<bookingSysObj[index].getSeatLeft()<<" Seats "<<endl;
            cout<<bookingSysObj[index].getSeatLeft()<<" Seats Left "<<endl;
            cout <<endl<<"Do you Want to Reserved "<<bookingSysObj[index].getSeatLeft() <<" :  (y/n) ? :  " ;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
                x=bookingSysObj[index].getSeatLeft();
            else
            return ;
        }

        //book the seat for user
      cus[cus_current_place].bookSeat(x);




         //Now Decrease the seats avilible
       setseatleft=bookingSysObj[index].getSeatLeft()-x;
      bookingSysObj[index].setSeatLeft(setseatleft);

      //Set Id of movie in customer class
      cus[cus_current_place].setMovieId(id);


      //Increase the indexing variable for customer array(array of object );
      cus_current_place++;


    }



}//END

//This Function is completed
//
//
//
//Helper Function Section



    //These are helper functions for
    //Booking seat function



    //First return The Index of user movie
    //second return if the user entered Movie Id is present or not
            int getObjectNum(int id)
            {
                for(int y=0; y<20; y++)
                {
                    if(bookingSysObj[y].getId()==id)
                        return y;
                }
                return -1 ;
            }

            int checkId(int x)  //If movie present return 1 else return 0
            {
                for(int a=0; a<20; a++)
                {
                    if(bookingSysObj[a].getId()==x)
                        return 1;
                }
                return 0;
            }//END


//Helper Functions ENDS HERE
///////////////////////////////////////////////////////////////////////////////////////////

};

int main()
{



    return 0;
}
