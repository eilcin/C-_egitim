#ifndef MNGR_H_
#define MNGR_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "User.h"



class Mngr
{

public:
    Mngr()
    {
    };

  int GameInit();  
  void GameHandler(int &State , User * Usr);
  void NewPlayer(User *);
  void StoreDataInFile(User * );
  void RetriveDataFromFile();
  static bool endGameFlag;

private:
    User usr;

};


#endif