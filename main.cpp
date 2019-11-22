#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string theFile;

struct Players{
  string name;
  double score;
};

bool acompare(Players lhs, Players rhs) { return lhs.score > rhs.score; }

class fileManager:fstream{
public:
   static bool fileChecker() {
    fstream file;
    file.open(theFile);
    if(file.is_open()) {
        file.close();
        return true;
    }
    else {
        file.close();
        return false;
    }
  }
};

class logicMotor{
public:
  void getScores(vector<Players> &players) {
    sort(players.begin(), players.end(), acompare);

  }
};


class playersRanker{
public:
  void rankPlayers() {

    fstream inputFile;
    //inputFile.open("results.txt");
    cout << "Arrastra tu archivo: ";
    cin >> theFile;
    //archivo.pop_back();
    //archivo.erase(archivo.begin());
    //cout << archivo << "-" << endl;
    //
    inputFile.open(theFile);
    vector<Players> players;

    if(fileManager::fileChecker()) {
      while(!inputFile.eof()) {
        Players temp;

        inputFile >> temp.name;
        inputFile >> temp.score;

        players.push_back(temp);
      }
      inputFile.close();

      logicMotor lM;
      lM.getScores(players);

      int position = 1;
      for(Players counter : players) {
          cout << "Position #" << position++;
          cout << " is for " << counter.name << " ---> " << counter.score << endl;
          if(position==4) {
            break;
          }
      }
    }
    else {
      cout << "Error in the input file!" << endl;
    }
  }

};

int main() {
    playersRanker pR;
    pR.rankPlayers();
    cin.get();
    return 0;
}
