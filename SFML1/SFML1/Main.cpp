#include <SFML/Graphics.hpp>

int main(int argc, char** argv[]) {
	sf::RenderWindow window(sf::VideoMode(640, 480), "First Window!");

	while (window.isOpen()) {
		sf::Event event;
		sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
		rectangle.setFillColor(sf::Color::Red);
		rectangle.setPosition(320, 240);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}



		window.clear(sf::Color::Black);
		window.draw(rectangle);
		window.display();
	}
}