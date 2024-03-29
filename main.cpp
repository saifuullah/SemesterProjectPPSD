//Below is header Files
//Used in This program


#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>


/**

Project   : PPSD
Instructor :  Sir Bacha Rehman


This is a cpp code
we used OOP in inmpelementing
this functionality


--------------------------------------------------------------------@@
This Program can implement a functionality of movie ticket booking
system. Different movies are added using it's methods and also any
movie can be edit.
User can book ticket for different movies avalible is the program
list.
--------------------------------------------------------------------@@

--------------------------------------------------------------------@@
Group Members:
Imran Khan RN 1802035
 Saif ullah Khan 1802012
 Wisha Khurshid 1802007
--------------------------------------------------------------------@@



**/


//THIS IS CUSTOMER CLASS
//THIS CLASS CONTAIN CUSTOMER RELATED DATA
//NAME,PHONE:#,BOOK SEAT,MOVIE ID ,
//AND THEIR SETTERS AND GETTERS
//setters and gettters will recivea and\
retutn vallues from where it called






using namespace std;

//Start of customer class

class customer
{
  private:

      //private Data
      //Phone number of customer
      string phone_number;

      //Name of customer
      string name;

      //Seats reserved by customer
      int book_seat;

      //Movie id Booked by customer
      int movieId;

      //Movie Price
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

        //It Set movie Id
   void setMovieId(int x)
   {
       movieId=x;
   }
         //is set the movie price
   void setPrice(int p)
   {
       price = p;
   }
        //it return the movie price
   int getPrice()
   {
       return price;
   }
       //it return the movie id
   int getMovieId()
   {
       return movieId;
   }
   //it set the Phone Number
   void setPhone(string ph)
   {  phone_number=ph; }

   //it Set the name of customer
   void setName(string n)
   {  name=n; }
        //It set the booking sets number
   void setBookSeat(int s)
   { book_seat=s; }


   //it return the phone number
  string getPhone()
  {  return phone_number; }
     //it return nooked seats
  int getBookSeat()
  {  return book_seat; }

  //it returns the Name
  string getName()
  {  return name; }


};






/**   ===============================================================@@
**    ===============================================================@@
**      This is Movie Class
**      This Class contain Data About movies
**      Like Movie id,name,price,seats etc
**      More ever this class contain Setters and getters for these
**      attributes so that their values are set and get where it needed.
**    ===============================================================@@
**    ===============================================================@@
*/

class BookingSystem
{
  private:  //Private Data

        int id_number;
        int total_price;
        int movie_price;      ///These are data types
        int seats;            ///that will be used to store
        int seat_left;
        string name;          ///related data
        string show_date;
        string show_time;
        string format;




public:
    //this is unperameteirzed constructer

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
{seat_left=x; }


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
  { return movie_price; }

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



//====================================================================================@@
//====================================================================================@@
//This is Function Class
//This Class contain all the methods that will be used for different operations
//We will make 1000 objects of customer class , it mean maximmum users will be 1200
//We will make 20 objects of Class Movies so that Maximumm numbers of movies will be stored is 20
//There is also some varibles used in this class
//These Variables are defined at the start of the class in private section
//These functions are called from the main function and it will take data from user and send it to the other function
//         in other classes

//=========================================================================================@@
//==========================================================================================@@
//Example : This class will work as a bridge

// User->Main(call)-->Functions-->Customer->data-->BookingSystem.

class functions{
public:
    //Max of 1000 customers
customer cus[1200];

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




//This is booking seat function
//This will take user name , phone number , and number of seats
//user want to reserved ::::
//This will store user data in customer class


void BookSeat()         ///Booking New seat function:
{

    cout<<"             Movie List is Below "<<endl<<"              Please Select a Movie and Enter asked information :) "<<endl<<endl;

    display_list();          //This will display list.....


    int var,id,setseatleft;  //General variable used
    cout<<"             Enter Movie Id : " ;
    cin>>id;

    //check the id of entered movie
    //to check weather the movie is present or not
    if(checkId(id)==0)
        {
            //if movie is not present
            //show error message
        cout<<endl<<"               Sorry,  Wrong Id Input (Movie not found) "<<endl<<"             Please Enter a correct Id "<<endl;
        cout<<endl<<"               Enter  1 to Enter again or 0 to exit ?        :: "<<endl;
        cin>>var;
        if(var==1)
            BookSeat();
        else
                 return ;
        }            //This will direct the user what to do ;

        //If the movie is present Jump their
    else
    {
        string st;
        int x;     //Variables used for general purpose


         //Take name of user
      cout<<"               Enter Customer Name  :  " ;
      cin>>st;
      cus[cus_current_place].setName(st);

       //Take customer Phone number
      cout<<"               Enter Customer Phone Number " ;
      cin>>st;
      cus[cus_current_place].setPhone(st);

      //Take seats to be booked
      cout<<"               Enter Number of Seats you want to reserved " ;
      cin>>x;

      if(x==0)
      {
           //If user enter 0 seats to be booked
           //Close program
        cout<<"         0 seats cannot be reserved ..!!!! "<<endl;
         return ;
      }

              //Else do the following work



            //general Purpose variables
        int problem,index;
        index=getObjectNum(id);





                //if the User want to reserved seats that is out of range of avalible seats (avillible < wanted )
                //We give choice to the user to reserved the remaining Seats or not
                //if yes, seats are reserved
                //if not, close the function

        if((bookingSysObj[index].getSeatLeft()-x)<0)
    {
            cout<<"             Sorry, You can only Reserve  "<<bookingSysObj[index].getSeatLeft()<<" Seats "<<endl;
            cout<<"            "<< bookingSysObj[index].getSeatLeft()<<"   Seats Left "<<endl;
            cout <<endl<<"              Do you Want to Reserved "<<bookingSysObj[index].getSeatLeft() <<" :  (y/n) ? :  " ;
            char y;
            cin>>y;
            if(y=='Y')
                x=bookingSysObj[index].getSeatLeft();
            else if(y=='y')
                x=bookingSysObj[index].getSeatLeft();
            else
            return ;
        }

        //book the seat for user
      cus[cus_current_place].setBookSeat(x);
      int price = x * bookingSysObj[index].getMoviePrice() ;
      cout << endl << "             Tickets Purchased Successfully,  "<<endl<<"             Total Price is : "<<price<<endl;
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

        //In first iteration it will write the data
        //stored in first object

        //In next it will stored the data
        //stored in the second object
        //This way all the objects data will be stored ion the data
        //File and at the End the File
        //will closed



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

  cout << "             Displaying Movies List "<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
 for(int x=0; x<20; x++)
    {
        if(bookingSysObj[x].getId()!=0)
        {
            // Here this condition will check if
            //the object has no data about the current
            //movie it will not print its data

            //because the null object will
            //contain no data



            cout<<"             ---------------------------------------------------"<<endl;
            cout<<"             ---------------------------------------------------"<<endl;
            cout<<"             Movie Id        :  "<<bookingSysObj[x].getId()<<endl;
            cout<<"             Movie Name      :  "<<bookingSysObj[x].getName()<<endl;
            cout<<"             Movie Format    :  "<<bookingSysObj[x].getFormat()<<endl;
            cout<<"             Movie Show Date :  "<<bookingSysObj[x].getShowDate()<<endl;
            cout<<"             Movie Show Time :  "<<bookingSysObj[x].getShowTime()<<endl;
            cout<<"             Movie Price     :  "<<bookingSysObj[x].getMoviePrice()<<endl;
            cout<<"             Movie Seats     :  "<<bookingSysObj[x].getSeat()<<endl;
            cout<<"             ---------------------------------------------------"<<endl;
            cout<<"             ---------------------------------------------------"<<endl;
        }
    }

    cout<<"-------------------------------------------------------------------------------------------------"<<endl;


}   //END





/**-------------------------------------------------------------------
---------------------------Add New Movie Function---------------------------
-------This function will add a new movie ----------------------------
---------Inputs are all the attributes that is required for the movie--
----------------------------------------------------------------------
*/
//Adding new movie to the Menu
// ------------------------------------------------ //
//
//
//
//
//
void addNewMovie()
{                         ///This is Add new movie function:


//first check weather the list is full or not
//if the list of movie is full
//Show error message
//Movie cannot be added


    if(movie_limit==movie_stored)
   { cout<<endl<<"              Sorry, New movie cannot be added"<<endl;
    cout<<"             Movie limit is full (20) "<<endl;
    cout<<"             Delete a movie, than try again .!!"<<endl<<endl; }

    ///If list is not full add new movie than
else
{
    cout<<endl<<"             Dear User, You are going to add a new movies "<<endl;
    cout<<"             Please Enter Information about New Movie"<<endl;
    cout<<"             ***********************************************"<<endl<<endl;

// Now take the Movie information
//Name id etc


    //take Id of New Movie ::
    int nid;
    cout<<"             Enter the Id of new movie :  ";
    cin>>nid;
     nid = checkDoubleId(nid);
    bookingSysObj[current_place].setId(nid);


    //Take name of new movie ::
    string nname;
    cout<<"             Enter the Name of New movie :  ";
    cin>>nname;
    bookingSysObj[current_place].setName(nname);


    //Take format of New Movie (2D or 3D) ::
    string nfor;
    cout<<"             Enter the Format of New movie (2D or 3D) :  ";
    cin>>nfor;
    bookingSysObj[current_place].setFormat(nfor);


    //Take time for the movie(show time) ::
    string ntime;
    cout<<"             Enter the Time of New movie-->format(12:00Pm) (Without spaces):  ";
    cin>>ntime;
    bookingSysObj[current_place].setShowTime(ntime);


    //Take Date for the movie(show date) ::
    string ndate;
    cout<<"             Enter the Date of New movie -->format(12/4/2000) (without spaces) :  " ;
    cin>> ndate;
    bookingSysObj[current_place].setShowDate(ndate);


    //Take Price for the new movie ::
    int nprice;
    cout<<"             Enter the Price of New movie :  ";
    cin>>nprice;
    bookingSysObj[current_place].setMoviePrice(nprice);


    //Take Seats for the movie Entered ::
    int nseat;
    cout<<"             Enter The Seats in New movie  :  ";
    cin>>nseat;
    bookingSysObj[current_place].setSeat(nseat);
    bookingSysObj[current_place].setSeatLeft(nseat);

    cout<<endl<<"               Please wait ......."<<endl<<"               New Movie Has been added successfully  "<<endl<<endl;

    //Increment current place variable(indexer) ::
    current_place++;
    //Increment Movie stored variable :
    movie_stored++;

}//else ENd
// at the end display the new movie list



               display_list();
}//End








//****************************************************************************************//
//This function will Read the Data from the File and will save into the Objects at Runtime
//Because when the program will restart it will have no data,  so this will restore data
//****************************************************************************************//


/**                 New Function Starts           **/





//****************************************************************************************
//This is Read Movie data function . This will read the data from the TXT file and save
// Memory at runtime for different operations
//****************************************************************************************

void readMovieData()
{
     // F-stream object --------- :
     fstream file;

     //General Purpose variables (Local Variables) ::
    string st;
     int x = 0;
       int i = 0;

       // This is counter for attributes                      --------
       //There are 8 different attributes for a single movie ---------
       //If counter == 8 , it mean one movie data has been read from
       //the file    -------------------------------------------------
       // Now switch to other movie data
       int counter = 0;

       //Open the file for reading ------ ::
    file.open("DataFile.txt");
    while(file.eof()==0)
    {
        /** Reset the counter */
            if(counter==8)
            {
                counter=0;
                current_place++;
                movie_stored++;
                i++;
            }


       // Here we set different "if" conditions ------------------------
       // Because we know the program will read the data in same format
       // as we save them in TXT File so it will jump on required "if"
       // condition to store correct data  -----------------------------

                    if(counter==0)
                    {
                        file >> st;
                        if(st == "end")
                            break;
                        bookingSysObj[i].setName(st);
                    }

                    else if(counter==1)
                    {
                        file >> x;
                        bookingSysObj[i].setId(x);
                    }

                    else if(counter==2)
                    {
                        file >> st ;
                        bookingSysObj[i].setFormat(st);
                    }

                    else if(counter==3)
                    {
                        file >> st ;
                        bookingSysObj[i].setShowDate(st);
                    }

                    else if(counter==4)
                    {
                        file >> st ;
                        bookingSysObj[i].setShowTime(st);
                    }

                    else if(counter==5)
                    {
                        file >> x ;
                        bookingSysObj[i].setMoviePrice(x);
                    }

                    else if(counter==6)
                    {
                        file >> x;
                        bookingSysObj[i].setSeat(x);
                    }

                    else if(counter==7)
                    {
                        file >> x ;
                        bookingSysObj[i].setSeatLeft(x);
                    }
                        counter++;


    }
} //END OF FUNCTION -------------(......)








   //***********************************************************
   // Definition of function openFileIn. Accepts a reference   *
   // to an f-stream object as its argument. The file is opened*
   // for input. The function returns true upon success, false *
   // upon failure. *
   //***********************************************************

   bool openFileIn(fstream &file, char *name)
   {
       file.open(name, ios::in);
        if (file.fail())
            return false;
        else
            return true;

   } //END HERE








   /**
-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------
------This is Delete Movie Function -------------------------------------------------
------When the Function Delete a Movie , --------------------------------------------
------The customer that have booked sets for this movie , data will not be deleted --
-------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------
*/

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void deleteMovie()
{

int nid;

    cout<<"             Dear User, You are Going to delete a movie ..!! "<<endl;
    cout<<"             Enter the Id of Movie to be delete "<<endl;
    cin >> nid;
    int delIndex = getObjectNum(nid);

        //If getObjNumber returns -1
        // it mean the Id of entered movie does not match any Data
        //If at match it will return a valid Index of Movie
        //for Movies object array

    if(delIndex == -1)
    {
        cout <<"                Sorry, The Entered Movie Id if not Found " <<endl<<endl;
        return ;

    }
    int y= 20 - delIndex ;
    int i = 0;
    //Now shift the Movie Data backwards
    while(i < y)
    {

           //This will shift the movies data because when a movie
           // is deleted from middle the vacant place should be filled
           // in order to keep a track for addition
           //i.e.    1,2,3,4,5,6,7,8,9 is the data stored in array
           //if 4 data is deleted it will be Like   1,2,3, ,5,6,7,8,9
           //So it should be Like 1,2,3,5,6,7,8,9
       bookingSysObj[delIndex]  = bookingSysObj[delIndex+1] ;
        i++;
    }

           //Now decrease The counter ::::
    current_place--;
          //Decrease the Movies stored ::::
    movie_stored--;

}


//This function
//will delete data
//of a single movie
//and after it will decrease
//the indexer of
//movie counter
//
//Data is shifted back to
//fill the vacant place







/** --------------------------------------------------------------------------------
-------------Booking New Seat Function ---------------------------------------------
----Inputs: Null -----------------We are taking input in this function and pass ----
------it to the booking system class using their own function : --------------------
------------------------------------------------------------------------------------
*/




void BookSeatNew()         ///Booking New seat function:
{

    cout<<"             Movie List is Below "<<endl<<"              Please Select a Movie and Enter asked information :) "<<endl<<endl;

    display_list();          //This will display list.....


    int var,id,setseatleft;  //General variable used
    cout<<"             Enter Movie Id :"<<endl;
    cin>>id;

    //this utility function will check
    //weather the user entered movie is present
    // or not
    // if not show error message

    if(checkId(id)==0)
        {
        cout<<"             Sorry,  Wrong Id Input (Movie not found) "<<endl<<"             Please Enter a correct Id "<<endl;
        cout<<"             Enter 1 to Enter again or 0 to exit "<<endl;
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


//now it is confirmed that the movie
//is present and Now take the customer data
// Save it to the customer class
// and close


         //Take name of user
      cout<<"               Enter Customer Name  :  " ;
      cin>>st;
      cus[cus_current_place].setName(st);


       //Take customer Phone number
      cout<<"               Enter Customer Phone Number " ;
      cin>>st;
      cus[cus_current_place].setPhone(st);

      //Take seats to be booked
      cout<<"               Enter Number of Seats you want to reserved " ;
      cin>>x;

      if(x==0)
      {
           //If user enter 0 seats to be booked
           //Close program
        cout<<"             0 seats cannot be reserved ..!!!! "<<endl;
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
            cout<<"             Sorry, You can only Reserve  "<<bookingSysObj[index].getSeatLeft()<<" Seats "<<endl;
            cout<<"             "<<bookingSysObj[index].getSeatLeft()<<" Seats Left ..!!!!!!!!!"<<endl;
            cout <<endl<<"              Do you Want to Reserved "<<bookingSysObj[index].getSeatLeft() <<" :  (y/n) ? :  " ;
            char y;
            cin>>y;
            if(y=='Y')
                x=bookingSysObj[index].getSeatLeft();
            else if( y == 'y')
                x = bookingSysObj[index].getSeatLeft();
            else
            return ;
        }

        //book the seat for user
      cus[cus_current_place].setBookSeat(x);




         //Now Decrease the seats avilible
       setseatleft=bookingSysObj[index].getSeatLeft()-x;
      bookingSysObj[index].setSeatLeft(setseatleft);

      //Set Id of movie in customer class
      cus[cus_current_place].setMovieId(id);


      //Increase the indexing variable for customer array(array of object );
      cus_current_place++;


    }



}//END




 //this is utility function
   //this will chech weather
   //the file is open or not
   //if the file is open
   //it will return true
   //if not it will return
   // False

    bool isFileOpen(fstream &file, char *name)
   {
       //File class object
       //


       file.open(name, ios::in);
       //open in ios::in mode

       //check weather it is openinable

       //if fails return false
       //else ]
       //true


        if (file.fail())
            return false;
        else
            return true;

   } //END HERE






//This is helper function for Add new movie function
//if user entered a value that is already present
//it will ask user to enter another Id
int checkDoubleId(int id)
{
int i = 0;
while(i < 20)
{
    if(bookingSysObj[i].getId() == id)
    {
        cout << "               Sorry, Id exist Please Enter another id   :" ;
        cin >> id ;
        i = -1;
    }
    i++;
}
return id;
}


   /**
-----------------------------------------------------------------------------------------------------|
-------------------------------------This is Search for Seat function--------------------------------|
-------------------------------------When user want to see if the seat is booked or not--------------|
-------------------------------------He can use the this function.-----------------------------------|
------------ Inputs are two :::  1---->User_Phone_Number     2--->User_Name--------------------------|
-------------------------We are taking two inputs because if the User have same names or same--------|
-------------------------Phone Numbers they can be identified very easily ---------------------------|
-----------------------------------------------------------------------------------------------------|
**/


//Here the function starts
//This input is coming from main function
//It is Good programing to take input in main :)
void checkForSeat(string ph, string name)
{

    //Index variable used for searching data in Customer class objects Array
    int ind = 0;

    while (ind < 1200)
    {
            //if the required information matched with the Entered Data
            //Condition true
        if(cus[ind].getPhone()==ph && cus[ind].getName()==name)
        {
               // Data shown for the customer
               // Include Customer data and movie data

            cout << "               Dear customer, Seat are Booked :"<<endl<<endl;
            cout << "               Customer Information ...  " <<endl;
            cout << "               Customer Name          : " <<cus[ind].getName()<<endl;
            cout << "               Customer Phone Number  : " <<cus[ind].getPhone()<<endl;
            cout << "               Seats Reserved         : " <<cus[ind].getBookSeat()<<endl;
            int x = getObjectNum(cus[ind].getMovieId());
            cout<<  "               Movie ID               : " <<bookingSysObj[x].getId()<<endl;
            cout << "               Movie Name             : " <<bookingSysObj[x].getName()<<endl;
            cout << "               Show time              : " <<bookingSysObj[x].getShowTime()<<endl;
            cout << "               Show Date              : " <<bookingSysObj[x].getShowDate()<<endl;
            cout << "               Total Price            : " <<(cus[ind].getBookSeat() * bookingSysObj[x].getPrice()) <<endl;
            return ;

        } //If End Braces



       // increment counter
        ind++;
    }//While loop End


    //Now if the loop Ends , it mean it searches all the data in array and does not found any match
    //Data entered is Wrong
    cout <<endl<<endl<<"             Sorry, No match Found with user Entered Data ..." <<endl;
    cout << "             Please try again    !!! "<<endl<<endl;
}//END OF FUNCTION checkForSeat





/**---------------------------------------------------------------------------------|
------------------------Here is the Edit Movie Function ----------------------------|
---------------When User wants to Edit the existing movie information --------------|
----------Like Name, Seats, Price, Seats , Date  and Time --------------------------|
------------------------------------------------------------------------------------|
*/


       //Function Edit Movie Start Here
       //Function Edit Movie Start Here


       //The Movie informatioj stored in the movie
       // class wil be edited acoording to the
       // desire of User
       // and the new information will be updated


void editMovie()
{
    int nid;


    cout<<"             ###################################################"<<endl;
    cout<<"             Dear User your going to Edit a Movie  .... "<<endl<<endl;
    cout<<"             Please Enter the Movie Id  : " ;
    cin >> nid;


    //Check weather the Movie(ID) is present Or Not @@@@@@@@@@@@
    // If flag == 1
    //Movie is present
    //Else not

    //Variables used for temporiry use

    string name,date,time;
    int id,price,seats;
    //
    //
    int ind = getObjectNum(nid); //Object Number
    int flag = checkId(nid);
    if( flag == 1 )
    {
        //now the sign flag is true
        //THe movie is present
        //Take the New Information from the user



        cout << "               Movie Found    :) "<<endl;
        cout << "               Please Enter The New information   " <<endl;
        cout << "               Enter new name  : " ;
        cin >> name;
        cout <<"                Enter Id   "  ;

        cin >> id;
        id = checkDoubleId(id);

        cout<< "                Enter New Date " ;
        cin >>date;

        cout << "               Enter New Time "  ;
        cin >>time;

        bookingSysObj[ind].setShowTime(time);


        cout <<"                Enter New movie Format " ;
        cin >> time ;
        bookingSysObj[ind].setFormat(time);

        cout << "               Enter Price : " ;
        cin >>price;
        cout <<"                Enter seats : " ;
        cin >> seats ;


        //now the Information is entered by the user
        //send itto the objects using
        // setters and geters


        bookingSysObj[ind].setName(name);
        bookingSysObj[ind].setId(id);

        bookingSysObj[ind].setShowDate(date);
        bookingSysObj[ind].setMoviePrice(price);
        bookingSysObj[ind].setSeat(seats);
        cout << "               Information Updated successfully ..!!!!!!! "<<endl<<endl;

                   // saveMovieData();
                //saveCustomerData();

    }
else


    cout <<endl<<endl<<"                Sorry, Movie information is not avilible " <<endl<< "               Please Try again " <<endl<<endl;


}





//Edit Movie Function END Here
//Task  Completed,  Information updated successfully
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////



//***********************************************************************************//
//***********************************************************************************//
//***********************************************************************************//





//************************************************************************************//
//************************************************************************************//
/**                   New Function Starts                      **/

//* This function will save the customer data into  TXT file ------Name cusDataFile.TXT

void saveCustomerData()
{

    //Create object of f-stream class
    fstream dataFile;

      // open File for Writing
      // Reading Mode ------------------- IOS::OUT
    dataFile.open("CustomerData.txt", ios::out);

    int i = 0;
    // Starts Loop
    //Counts up to last Object's
    while (i < cus_current_place )
    {

                 //Writing customer data into TXT file
              dataFile << cus[i].getName() << endl;

              dataFile << cus[i].getBookSeat() << endl;

              dataFile << cus[i].getPhone() <<endl;

              dataFile << cus[i].getMovieId() << endl;

              dataFile << cus[i].getPrice() << endl;

        //increment the counter
        i++;
    }

    // Data Saved
    // Close the File
    string st="end";
    dataFile << st;

    dataFile.close();


}//Function END



//****************************************************************************************
//This is Read Customer data function . This will read the data from the TXT file and save
// Memory at runtime for different operations
//****************************************************************************************

void readCustomerData()
{
     // F-stream object --------- :
     fstream file;

     //General Purpose variables (Local Variables) ::
    string st;
     int x = 0;
       int i = 0;       // "i" is used as an indexing variable

       // This is counter for attributes                      --------
       //There are 5 different attributes for a single movie ---------
       //If counter == 5 , it mean one movie data has been read from
       //the file    -------------------------------------------------
       // Now switch to other movie data
       int counter = 0;

       //if(!openFileIn(file, "CustomerData.txt"))
        //return ;
        //else
        //{
       //Open the file for reading ------ ::
    file.open("CustomerData.txt");
    while(file.eof()==0)
    {
        /** Reset the counter */
            if(counter==5)
            {
                counter=0;
                cus_current_place++;
                i++;
            }


       // Here we set different "if" conditions ------------------------
       // Because we know the program will read the data in same format
       // as we save them in TXT File so it will jump on required "if"
       // condition to store correct data  -----------------------------

                    if(counter==0)
                    {
                        file >> st;
                        if(st == "end")
                            break;
                        cus[i].setName(st);
                    }
                    else if(counter==1)
                    {
                        file >> x;
                        cus[i].setBookSeat(x);
                    }
                    else if(counter==2)
                    {
                        file >> st ;
                        cus[i].setPhone(st);
                    }
                    else if(counter==3)
                    {
                        file >> x ;
                        cus[i].setMovieId(x);
                    }
                    else if(counter==4)
                    {
                        file >> x ;
                        cus[i].setPrice(x);
                    }
                        counter++;
    }
       // }
}        //END OF FUNCTION


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

            cout << "      **************************************************************************** " <<endl;
            cout << "               WellCome to the Movie Ticket Booking System  "<< endl;
            cout << "               Please Select Your choice  >> " << endl <<endl ;

            cout << "               ***************************************************** " <<endl;
            cout << "               **  1)  For Add A New Movie To Menu                *** " <<endl;
            cout << "               **  2)  For Edit Existing Movie Data               *** " <<endl;
            cout << "               **  3)  For Delete A Movie From List               *** " <<endl;
            cout << "               **  4)  For Booking Your Tickets                   *** " <<endl;
            cout << "               **  5)  For Checking Your Seat/Reservation         *** " <<endl;
            cout << "               **  6)  For Displaying Movies List                 *** " <<endl;
            cout << "               ***************************************************** " <<endl;

            //User Choice
            cout << "               choice   : " ;
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

                cout << "               Enter the Phone Number of customer :  "  ;
                cin >> ph;
                cout << "               Enter The Name of Customer  : "  ;
                cin >> name ;
                my_object.checkForSeat(ph, name);
                break;


                //Case 4
            case 6:

                my_object.display_list();
                break;



            default :
                cout << "               Invalid input : " << endl;


            } // Switch statement ENDS




        //Ask the User to Continue or To exit
        //Yes or No
        cout <<endl<<"                Do you want to Continue (y/n)   :  ";
        cin >> ch ;
        cout <<endl<<endl;
        if ( ch == 'n')
            {
            my_object.saveMovieData();

           my_object.saveCustomerData();


            }




    }while (ch != 'n');



    return 0;
}

//The Program is Completed
//Every function is completelt tested
//before submitting
//the complete fucntiion is not tested
//Noe the whole program will be teseted
//in order to see all the bugs in the code









































































































//
