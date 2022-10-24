#include "Mngr.h"
#include <map>
#include <string>


using namespace std;
bool Mngr::endGameFlag = false;

int Mngr::GameInit()
{
  
  int pressedkey;
  cout << " ### SNAKE GAME Start ###" << endl;
  cout << "   " << std::endl;
  cout << " 1. Start New Game" << endl;
  cout << " 2. History" << endl;
  cout << " 3. QUIT" << endl;
  cout << " your choice --> ";

    while (!(cin >> pressedkey))
    {
      //Clear buffer
      cin.clear();
      // Check on Entre
      while (cin.get() != '\n')
      {
        continue;
      }
      
      // Ask user to try again:
      cout << "FAILED.Please enter correct number -->  ";
    }

    if ((pressedkey >= 1) || (pressedkey <= 3))
    {
      return pressedkey;
      endGameFlag = false;
    }

  
    if ((pressedkey < 1) || (pressedkey > 3))
    {
      cout << "FAILED. Please enter correct number!"<< endl;
      endGameFlag = true;
    }
    
}

void Mngr::GameHandler(int &State , User * Usr)
{
  std::map<string, int> History;
	switch (State)
    {
        case 1:
        NewPlayer(Usr);
        endGameFlag = false;
        break;
        
    	case 2:
        endGameFlag = false;
        //Retrive Data
        History = usr.ReadUsersHistory();
        usr.DisplayGameHistory(History);
        NewPlayer(Usr);
        
        break;
        
    	case 3:
        cout << "end the game" <<endl;
        endGameFlag = true;
        break;
    }

}

void Mngr::NewPlayer(User *Usr)
{

    Usr->setUserName();
}



