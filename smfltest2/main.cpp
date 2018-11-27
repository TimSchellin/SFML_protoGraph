#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 500;
const int SCALESIZE = 10;
const double _X = 1;
const double _Y = tan(_X);
//const sf::Color::
double function(double x) {
	return 7*sin(x/4);
}

int main(){
	sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "SFML works!");

	sf::Cursor cursor;
	if (cursor.loadFromSystem(sf::Cursor::Help))
		window.setMouseCursor(cursor);

	sf::VertexArray x_axis(sf::LinesStrip, 3);
	x_axis[0].position = sf::Vector2f(0, SIZE/2);
	x_axis[0].color = sf::Color::Black;
	x_axis[1].position = sf::Vector2f(SIZE/2, SIZE / 2);
	x_axis[1].color = sf::Color::White;
	x_axis[2].position = sf::Vector2f(SIZE, SIZE/2);
	x_axis[2].color = sf::Color::Black;

	sf::VertexArray y_axis(sf::LinesStrip, 3);
	y_axis[0].position = sf::Vector2f(SIZE/2, 0);
	y_axis[0].color = sf::Color::Black;
	y_axis[1].position = sf::Vector2f(SIZE / 2, SIZE/2);
	y_axis[1].color = sf::Color::White;
	y_axis[2].position = sf::Vector2f(SIZE/2, SIZE);
	y_axis[2].color = sf::Color::Black;

	sf::Color colors[6];
	colors[0] = sf::Color::Red;
	colors[1] = sf::Color::Yellow;
	colors[2] = sf::Color::Green;
	colors[3] = sf::Color::Cyan;
	colors[4] = sf::Color::Blue;
	colors[5] = sf::Color::Magenta;


	sf::VertexArray curve(sf::LineStrip, 500);

	for (int x = -1*SIZE; x < SIZE; x++) {
		curve.append(sf::Vertex(sf::Vector2f(SCALESIZE*x+SIZE/2, SIZE/2-function(x)*SCALESIZE), colors[abs(x)%6]));
	}

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(x_axis);
		window.draw(y_axis);
		window.draw(curve);
		window.display();
	}

	return 0;
}