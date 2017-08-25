using namespace std;

class coin					// coin: USED TO BUY STUFF FROM VENDING MACHINES
{
private:
	double value;			// value of the coin

public:
	coin(double value);		// constructor
	double getValue();		// gets the value of a coin
};
