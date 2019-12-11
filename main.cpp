/**

--------------------------------------------------------------------@@
This Program can implement a functionality of movie ticket booking
system. Different movies are added using it's methods and also any
movie can be edit.
User can book ticket for different movies avalible is the program
list.
--------------------------------------------------------------------@@

--------------------------------------------------------------------@@
Group Members: Imran Khan, Saif ullah Khan, Wisha Khurshid
--------------------------------------------------------------------@@



**/


//THIS IS CUSTOMER CLASS
//THIS CLASS CONTAIN CUSTOMER RELATED DATA
//NAME,PHONE:#,BOOK SEAT,MOVIE ID ,
//AND THEIR SETTERS AND GETTERS


#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
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
   void bookSeat(int s)
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

//Example : This class will work as a bridge

// User->Main(call)-->Functions-->Customer->data-->BookingSystem.

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




//This is booking seat function
//This will take user name , phone number , and number of seats
//user want to reserved ::::
//This will store user data in customer class


void BookSeat()         ///Booking New seat function:
{

    cout<<"Movie List is Below "<<endl<<"Please Select a Movie and Enter asked information :) "<<endl<<endl;

    display_list();          //This will display list.....


    int var,id,setseatleft;  //General variable used
    cout<<"Enter Movie Id :"<<endl;
    cin>>id;

    //check the id of entered movie
    //to check weather the movie is present or not
    if(checkId(id)==0)
        {
            //if movie is not present
            //show error message
        cout<<endl<<"Sorry,  Wrong Id Input (Movie not found) "<<endl<<"Please Enter a correct Id "<<endl;
        cout<<endl<<"Enter  1 to Enter again or 0 to exit ?        :: "<<endl;
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
                //if yes, seats are reserved
                //if not, close the function

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





/**-------------------------------------------------------------------
---------------------------Add New Movie Function---------------------------
-------This function will add a new movie ----------------------------
---------Inputs are all the attributes that is required for the movie--
----------------------------------------------------------------------
*/
//Adding new movie to the Menu
// ------------------------------------------------ //
void addNewMovie()
{                         ///This is Add new movie function:

    if(movie_limit==movie_stored)
   { cout<<endl<<"Sorry, New movie cannot be added"<<endl;
    cout<<"Movie limit is full (20) "<<endl;
    cout<<"Delete a movie, than try again .!!"<<endl<<endl; }

    ///If list is not full add new movie than
else
{
    cout<<"Dear User, You are going to add a new movies "<<endl;
    cout<<"Please Enter Information about New Movie"<<endl;
    cout<<"***********************************************"<<endl<<endl;


    //take Id of New Movie ::
    int nid;
    cout<<"Enter the Id of new movie :  ";
    cin>>nid;
     nid = checkDoubleId(nid);
    bookingSysObj[current_place].setId(nid);


    //Take name of new movie ::
    string nname;
    cout<<"Enter the Name of New movie :  ";
    cin>>nname;
    bookingSysObj[current_place].setName(nname);


    //Take format of New Movie (2D or 3D) ::
    string nfor;
    cout<<"Enter the Format of New movie (2D or 3D) :  ";
    cin>>nfor;
    bookingSysObj[current_place].setFormat(nfor);


    //Take time for the movie(show time) ::
    string ntime;
    cout<<"Enter the Time of New movie  (Without spaces):  ";
    cin>>ntime;
    bookingSysObj[current_place].setShowTime(ntime);


    //Take Date for the movie(show date) ::
    string ndate;
    cout<<"Enter the Date of New movie -->format(12/4/2000) without spaces :  " ;
    cin>> ndate;
    bookingSysObj[current_place].setShowDate(ndate);


    //Take Price for the new movie ::
    int nprice;
    cout<<"Enter the Price of New movie :  ";
    cin>>nprice;
    bookingSysObj[current_place].setMoviePrice(nprice);


    //Take Seats for the movie Entered ::
    int nseat;
    cout<<"Enter The Seats in New movie  :  ";
    cin>>nseat;
    bookingSysObj[current_place].setSeat(nseat);
    bookingSysObj[current_place].setSeatLeft(nseat);

    cout<<endl<<"Please wait ......."<<endl<<"New Movie Has been added successfully  "<<endl<<endl;

    //Increment current place variable(indexer) ::
    current_place++;
    //Increment Movie stored variable :
    movie_stored++;

}//else ENd

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
