// game: High House Number (Hohe Hausnummer)
// author:  Holger Arndt
// version: 09.12.2025
// framework for sheet 9, exercise 26

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// replace these strings by empty strings if not displayed correctly

// house number made up of three dice's results
class HouseNumber
{
private:
  int dice[3];  // dice[0] = left die, …, dice[2] = right die
public:
  HouseNumber() : dice{ 0, 0, 0 } {}  // 0 means not yet set
  bool setDie(char position, int value);
  int points() const { return 100 * dice[0] + 10 * dice[1] + dice[2]; }
  friend ostream& operator<<(ostream& os, const HouseNumber& hn);
};
bool HouseNumber::setDie(char position, int value)
// return value: true  if die could be set
//               false if position is either occupied or invalid character
{
  int arrayPos;
  switch (position) // convert position ('l'/'c'/'r') to index (0/1/2)
    {
      case 'l': arrayPos = 0; break;
      case 'c': arrayPos = 1; break;
      case 'r': arrayPos = 2; break;
      default: return false;
    }
  if (dice[arrayPos] == 0)
    {
      dice[arrayPos] = value;
      return true;
    }
  else
    return false;
}
ostream& operator<<(ostream& os, const HouseNumber& hn)
{
  for (int d : hn.dice)
    if (d == 0)
      os << '?'; // not yet set
    else
      os << d;
  return os;
}

//////////////////////////////////////////////////////////////////
// Add the classes Player, HumanPlayer, and ComputerPlayer here //
//////////////////////////////////////////////////////////////////

class Player
{
protected:
  string name;
  int score;
public:
  Player(string nm) : name(nm), score(0) {}
  virtual ~Player() {}
  int getScore() const { return score; }
  string getName() const { return name; }
  void addToScore(int points) { score += points; }
  virtual void choosePosition(HouseNumber& hn, int value) = 0;
};

class HumanPlayer: public Player
{
private:
public:
  HumanPlayer(string nm) : Player(nm) {}
  void choosePosition(HouseNumber& hn, int value) override;
};

void HumanPlayer::choosePosition(HouseNumber& hn, int value)
{
  char input;
  do
  {
    cout << "Enter position (l = left, c = center, or r = right): ";
    cin >> input;
  } while (!hn.setDie(input, value));
}


class ComputerPlayer: public Player
{
public:
  ComputerPlayer(string nm) : Player(nm) {}
  void choosePosition(HouseNumber& hn, int value) override;
};

void ComputerPlayer::choosePosition(HouseNumber& hn, int value)
{
  // Get current state
  int points = hn.points();
  bool positions[3] = {
    points >= 100,  // left occupied
    (points % 100) >= 10,  // center occupied
    (points % 10) > 0  // right occupied
  };
  
  int spotsLeft = 3 - (positions[0] + positions[1] + positions[2]);
  
  // Strategy: choose optimal position based on value and spots remaining
  vector<char> preference;
  
  if (value <= 2) {
    // Low values: prioritize right
    preference = {'r', 'c', 'l'};
  }
  else if (value >= 5) {
    // High values: prioritize left
    preference = {'l', 'c', 'r'};
  }
  else if (value == 3) {
    // Medium-low (3): adjust based on spots left
    if (spotsLeft == 1) {
        preference = {'r', 'c', 'l'}; // Put it right, no choice
    } else {
        preference = {'r', 'c', 'l'}; // Generally prefer right
    }
  }
  else { // value == 4
    // Medium-high (4): strategic placement based on remaining spots
    if (spotsLeft == 1) {
        preference = {'l', 'c', 'r'}; // Only one spot, maximize it
    }
    else if (spotsLeft == 2) {
        preference = {'c', 'l', 'r'}; // Put in middle, hope for 5+ next
    }
    else { // spotsLeft == 3
        preference = {'c', 'l', 'r'}; // Save left for potentially better roll
    }
  }
  
  // Try positions in order of preference
  for (char pos : preference) {
    if (hn.setDie(pos, value)) {
      // position chosen
      break;
    }
  }
}


int main()
{
  // setup players
  unsigned int numPlayers; // number of players
  cout << "number of players: ";
  cin >> numPlayers;
  Player** players{new Player*[numPlayers]};
  string dummy;
  getline(cin, dummy); // read rest of line, at least '\n'
  for (unsigned int i{0}; i < numPlayers; ++i)
    {
      cout << "Player " << i << ": human or computer (enter h/c): ";
      string type;
      getline(cin, type); // read whole line, only consider first character
      cout << "player's name: ";
      string name;
      getline(cin, name);
      if (type[0] == 'h')
        players[i] = new HumanPlayer{name};
      else
        players[i] = new ComputerPlayer{name};
    }

  // start game
  mt19937_64 rng{random_device{}()}; // initialize random number generator
  uniform_int_distribution dice{1, 6};
  char cont;
  do // loop over rounds of the game
    {
      for (unsigned int i{0}; i < numPlayers; ++i) // loop over players in round
        {
          Player* p{players[i]}; // pointer to the current player
          cout << "It's " << p->getName() << "'s turn"
               << endl;
          HouseNumber hn;
          for (int rolling{1}; rolling <= 3; ++rolling) // roll die three times
            {
              int value{dice(rng)}; // roll dice randomly
              cout << "house number so far: " << hn << ", rolled: " << value
                   << endl;
              p->choosePosition(hn, value);
            }
          p->addToScore(hn.points()); // add final result to player's score
          cout << "result: " << hn << ", score so far: "
               << p->getScore()  << endl;
        }
      cout << "SCORES:" << endl; // show total scores
      int mn{players[0]->getScore()}; // determine min and max score first
      int mx{mn};
      for (unsigned int i{1}; i < numPlayers; ++i)
        {
          Player* p{players[i]};
          mn = min(mn, p->getScore());
          mx = max(mx, p->getScore());
        }
      for (unsigned int i{0}; i < numPlayers; ++i) // show scores
        {
          Player* p{players[i]};
          cout << setw(10) << p->getName() << ": " << p->getScore()
               << endl;
        }
      cout << "continue (y/n)? ";
      cin >> cont;
    }
  while (cont == 'y' || cont == 'Y');
}