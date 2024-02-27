#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#define COLOR sf::Color(100, 250, 50)

#define MAX_VALUE 50000
#define SIZE 1500

#define WIN_X 1500
#define WIN_Y 600

#define SLOW 10

// This struct will be for the vector, and will connect between the line and the value
typedef struct Item
{
	sf::RectangleShape* line;
	int value;
} Item;

class Visualizer
{
public:
	Visualizer();
	~Visualizer();

	void draw(); // will be called everytime we want to draw something to the screen

private:
	// the array that will be sorted
	std::vector<Item> array;
	// the screen that everything will be displayed on
	sf::RenderWindow window;
};
