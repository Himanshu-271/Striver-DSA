#include <iostream>
using namespace std;

class Shop // use of array in class   , if nothing said so var are private but contain garbage not intilise
{
    int itmID[10];
    int price[10];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void displayPrice(void);
    void setPrice(void);
};
void Shop::setPrice(void)
{
    cout << "enter ID of item: " << counter + 1 << endl;
    cin >> itmID[counter];
    cout << "enter price :" << endl;
    cin >> price[counter];
    counter++;
}
void Shop::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "the price of item with ID " << itmID[i] << " is " << price[i] << endl;
    }
}

int main()
{
    Shop dk;
    dk.initCounter();
    for (int i = 0; i < 3; i++)
    {
        dk.setPrice();
    }
    // dk.setPrice(); // also use loop how many times need to run this fxn

    // dk.setPrice();
    // dk.setPrice();
    dk.displayPrice();

    return 0;
}