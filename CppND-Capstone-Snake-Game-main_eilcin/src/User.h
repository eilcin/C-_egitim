#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>




using namespace std;

class User
{

public:
    User() {};
    User(string UserName, int UserScore);
    ~User(){};

    void setUserName();
    void setUserScore(int);
    
    string getUserName();
    int getUserScore();
    
    map<string, int> ReadUsersHistory();
    void DisplayGameHistory(std::map<string, int> &GameHistory);
    void WriteUsersHistory(map<string, int> History);
    
    

private:
    string UserName;
    int UserScore;

    vector<User *> UserVector;
};

#endif
