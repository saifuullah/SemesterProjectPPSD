//THIS IS CUSTOMER CLASS
//THIS CLASS CONTAIN CUSTOMER RELATED DATA
//NAME,PHONE:#,BOOK SEAT,MOVIE ID ,
//AND THEIR SETTER AND GETTER





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
