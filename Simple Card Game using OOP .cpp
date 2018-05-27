#include<iostream>
#include <ctime>
#include <time.h>
#include <unistd.h>


using namespace std;
void Splash();

enum Suit { clubs, diamonds, hearts, spades };

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Card{

   private:

            int number;
            short suit;

  public:



         Card(){

           //assing random intigers to card class attributes to
           // form a randomize Card

           number = (2 + (std::rand() % (int)(13)));
           suit = (int)((std::rand() % (int)(4)));

         }



         void display();
         bool isEqual(Card);

         bool Compare(Card);

};

void Card::display(){

     if( number >= 2 && number <= 10 )
            cout << number << " of ";
     else
       switch(number){

              case jack: cout <<"Jack of "; break;
              case queen: cout << "Queen of "; break;
              case king: cout << "King of "; break;
              case ace:cout << "Ace of ";break;
    }

    switch(suit){
        case clubs:cout << "Clubs"; break;
        case diamonds: cout << "Diamonds"; break;
        case hearts:cout << "Hearts"; break;
        case spades:cout <<" Spades"; break;
}

  std::cout << "\n " << '\n';
      }

  bool Card::isEqual(Card c2){

      return ( number==c2.number && suit==c2.suit ) ? true : false;

      }

bool Card::Compare(Card c3){

     if(suit > c3.suit){

        return true;
     }else if(suit ==c3.suit){
       return  (number >c3.number)?true:false;
     }else{

       return ( (suit > c3.suit) && number > c3.number )? true :false;

     }


}



      int main(){

       float bet;
       float moneyWon=0;
       float moneyLost=0;



  Start1: srand( time( NULL ) ); // seeding srand  function with time() function


      Splash();

      for (size_t i = 0; i < 5; i++) {

      std::cout << "Beting time :" <<i+1<< '\n';
      Card c1,c2;

      std::cout << "\nYou Card :" ;
      c1.display();

      std::cout << "How much are you going to bet :"  ;
      cin>>bet;
     std::cout <<endl;

      std::cout << "Dealer's Card :";
      c2.display();

      if(!c1.isEqual(c2)){

          if(c1.Compare(c2)){

               std::cout << "You won !!!" << '\n'<<endl;
               moneyWon+=bet;

          }else{
              std::cout << "You lost <!>" << '\n'<<endl;
              moneyLost+=bet;
          }

    }else{
        std::cout << "<!> Game Draw <!>" << '\n'<<endl;

      }
  std::cout <<    "________________________________________________________" << '\n';

    }

    std::cout <<  " Final Summary |_______________________  " << '\n';
    std::cout <<  " Winning       |" << moneyWon<< " $"<<'\n';
    std::cout <<  " Loses         |" << moneyLost<<" $"<<'\n';
    std::cout <<  "-----------------------------------------" << '\n';
    std::cout <<  " Profit        |" << moneyWon-moneyLost<<"$"<<((moneyWon-moneyLost<0)?" Debt":"")<<'\n';
    std::cout <<  "________________________________________" << '\n';
    std::cout <<  "________________________________________\n\n" << '\n';


    std::cout <<  "Do you want this game again(y/n):" ;
    char in;
    std::cin >> in;
    if(in=='y'){
      goto Start1;
    }else{
      cout << endl;
      return 0;
    }


      cout << endl;
      return 0;
}


void Splash(){
  std::cout << "\n\n_____________________________________________________\n\n" << '\n';
  std::cout <<     "--------||  $$$$    CASINO ROYAL   $$$$   ||--------" << '\n';
  std::cout <<     "_____________________________________________________" << '\n';

   std::cout <<    "    This Card game is base on beting for     " << '\n';
   std::cout <<    "    highest value card between player and Dealer.    " << '\n';
   std::cout <<    "    In one Hand You have 5 chancess....$$    " << '\n';

  std::cout <<     "    Values of Suit are increase as \n    Clubs, Diamonds, Hearts, Spades    " << '\n';

  for (int i = 0; i < 2; i++) {

    std::cout << "\n" ;

  }
std::cout <<    "         $$$$$$$ Enjoy !  on  Casino Royal $$$$$$$$" << '\n';

    std::cout <<    "________________________________________________________" << '\n';
}
