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
      int price ;
  public:

      //Constructer
   customer()
   {
       phone_number="Null";
       name="NULL";
       book_seat=0;
       movieId=0;
       price=0;
   }

                                //Below is Setters And Getters
   void setMovieId(int x)
   {
       movieId=x;
   }
   void setPrice(int p)
   {
       price = p;
   }
   int getPrice()
   {
       return price;
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





/** --------------------------------------------------------------------------------
-------------Booking New Seat Function ---------------------------------------------
----Inputs: Null -----------------We are taking input in this function and pass ----
------it to the booking system class using their own function : --------------------
------------------------------------------------------------------------------------
*/




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
        cout<<endl<<"Sorry,  Wrong Id Input (Movie not found) "<<endl<<"Please Enter a correct Id "<<endl;
        cout<<endl<<"Enter  1 to Enter again or 0 to exit ?        :: "<<endl;
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
            if(y=='Y')
                x=bookingSysObj[index].getSeatLeft();
            else if(=='y')
                x=bookingSysObj[index].getSeatLeft();
            else
            return ;
        }

        //book the seat for user
      cus[cus_current_place].bookSeat(x);
      int price = x * bookingSysObj[index].getMoviePrice() ;
      cout << endl << "Tickets Purchased Successfully,  "<<endl<<"Total Price is : "<<price<<endl;
      cus[cus_current_place].setPrice(price);




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







/** %%%%%%&&&&&&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
-----------------------------------------------------------------------------------------|
-------------------This Is File Handling Section-----------------------------------------|
------This Function Will first Create a TXT File ----------------------------------------|
-------------------If the File Exist it Will not create it Again-------------------------|
-----------But Save the data-------------------------------------------------------------|
-------------------This Function will save the Data in TXT File--------------------------|
-----------------------------------------------------------------------------------------|
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

*/


//Function Start here
//File Name DataFile.TXT



//Function Start here-----------------------------------
//File Name DataFile.TXT--------------------------------
void saveMovieData()
{

    //Create object of f-stream class
    fstream dataFile;

       //Create file "DataFile.TXT"------------------------Created
    dataFile.open("DataFile.txt", ios::out);

    int i = 0;

    //Save Data Until End---------------------All Objects
    // Up to Last Object's Data
    while (i < current_place )
    {

        //Writing Movie data into TXT file
        dataFile << bookingSysObj[i].getName() << endl;
        dataFile << bookingSysObj[i].getId() << endl ;

        dataFile << bookingSysObj[i].getFormat() << endl ;
        dataFile << bookingSysObj[i].getShowDate() << endl;

        dataFile << bookingSysObj[i].getShowTime() << endl ;
        dataFile << bookingSysObj[i].getPrice() << endl;

        dataFile << bookingSysObj[i].getSeat() << endl ;
        dataFile << bookingSysObj[i].getSeatLeft() << endl;



        //increment the counter
        i++;
    }

    //Saving is Done
    //Close the File
    string st="end";
    dataFile << st ;
    dataFile.close();

}//Function END








/*****************************************************************************************
***************************************  Display Function  *******************************
***************************************  Display Function  *******************************
******************************************************************************************/


//This function will display the list of present movies ::
void display_list()
{

  cout << "Displaying Movies List "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
 for(int x=0; x<20; x++)
    {
        if(bookingSysObj[x].getId()!=0)
        {
            cout<<"---------------------------------------------------"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"Movie Id        :  "<<bookingSysObj[x].getId()<<endl;
            cout<<"Movie Name      :  "<<bookingSysObj[x].getName()<<endl;
            cout<<"Movie Format    :  "<<bookingSysObj[x].getFormat()<<endl;
            cout<<"Movie Show Date :  "<<bookingSysObj[x].getShowDate()<<endl;
            cout<<"Movie Show Time :  "<<bookingSysObj[x].getShowTime()<<endl;
            cout<<"Movie Price     :  "<<bookingSysObj[x].getMoviePrice()<<endl;
            cout<<"Movie Seats     :  "<<bookingSysObj[x].getSeat()<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<"---------------------------------------------------"<<endl;
        }
    }

    cout<<"-------------------------------------------------------------------------------------------------"<<endl;


}   //END




};

int main()
{

    functions my_object;

           my_object.readCustomerData();
          my_object.readMovieData();


    //General Purpose varibales
    int choice;
    string name,ph;
    char ch;

    do{

            cout << " ****************************************************************** " <<endl;
            cout << " WellCome to the Movie Ticket Booking System  "<< endl;
            cout << " Please Select Your choice  >> " << endl <<endl ;

            cout << "***************************************************** " <<endl;
            cout << "**  1. For Add A New Movie To Menu                *** " <<endl;
            cout << "**  2. For Edit Existing Movie Data               *** " <<endl;
            cout << "**  3. For Delete A Movie From List               *** " <<endl;
            cout << "**  4. For Booking Your Tickets                   *** " <<endl;
            cout << "**  5. For Checking Your Seat/Reservation         *** " <<endl;
            cout << "**  6. For Displaying Movies List                 *** " <<endl;
            cout << "***************************************************** " <<endl;

            //User Choice
            cout << " choice   : " ;
            cin >> choice ;


                    //Here is the switch statement Section
                    //Direct User What He Wants

            switch ( choice )
            {
                //first case add new movie
            case 1 :
                my_object.addNewMovie();
                break;

                //Second Case
            case 2:
                my_object.editMovie();
                break;


             //Third Case
            case 3:
                my_object.deleteMovie();
                break;


                //Case 4
            case 4:
                my_object.BookSeat();
                break;


            case 5:

                cout << " Enter the Phone Number of customer :  "  ;
                cin >> ph;
                cout << " Enter The Name of Customer  : "  ;
                cin >> name ;
                my_object.checkForSeat(ph, name);
                break;


                //Case 4
            case 6:

                my_object.display_list();
                break;



            default :
                cout << "Invalid input : " << endl;


            } // Switch statement ENDS




        //Ask the User to Continue or To exit
        //Yes or No
        cout <<"Do you want to Continue (y/n)   :  "<<endl;
        cin >> ch ;
        if ( ch == 'n')
            {
            my_object.saveMovieData();
           my_object.saveCustomerData();
            }
    }while (ch != 'n');



    return 0;
}
