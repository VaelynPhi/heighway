#include<iostream>
#include<bitset>

using namespace std;

int main()
{
  enum Colour {red, orange, yellow, green, blue, indigo, violet, numOfColours};

  bitset<numOfColours> usedColours;

  usedColours.set(red);
  usedColours.set(blue);

  //Lets see the output
  cout << "bitfield of used colours: " << usedColours << endl;
  cout << "number of used colors: " << usedColours.count() << endl;
  cout << "bitfield of unused colors: " << ~usedColours << endl;

  //If any colour is used
  if (usedColours.any())
  {
    // loop over all colors
    for (int c = 0; c < numOfColours; ++c)
      if (usedColours[(Colour)c])
        cout << Colour(c)<< " used "<<endl; //No way to print enum names directly
  }

  return 0;
}
