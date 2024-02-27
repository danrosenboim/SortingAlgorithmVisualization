#include "Visualizer.h"

Visualizer::Visualizer() : window(sf::VideoMode(WIN_X, WIN_Y), "Sorting Visualization")
{
	srand(time(0));
	array.reserve(SIZE);
	
	for(int i = 0; i < SIZE; i++)
	{
		Item curItem;
		
		// each item will contain a random value
		curItem.value = (rand() % MAX_VALUE) + 1;
		// each item will also contain a shape, thats gonna be its "visualization part" when we draw it to the screen
		curItem.line = new sf::RectangleShape(sf::Vector2f(WIN_X / SIZE, curItem.value / (MAX_VALUE / WIN_Y)));

		curItem.line->setFillColor(COLOR);

		array[i] = curItem;
	}
	
	// drawing the initial state of the list
	draw();
}

Visualizer::~Visualizer()
{
	std::cout << "Deallocating" << std::endl;

	// deallocate memory
	for(int i = 0; i < SIZE; i++)
	{
		delete array[i].line;
	}
	array.clear();
}

void Visualizer::draw()
{
	window.clear();
	for(int i = 0; i < SIZE; i++)
	{
		// setting the position of each item depending on its position in the array
		array[i].line->setPosition(i * (WIN_X / SIZE), 0);
		
		window.draw(*(array[i].line));
	}
	window.display();
}

void Visualizer::sort(void (*sortingFunction)(std::vector<Item>&))
{
	organizer = std::thread(sortingFunction, std::ref(array));
}

void Visualizer::show()
{
	// make the drawing board
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		draw();
	}
}
