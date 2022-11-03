#pragma once
#include <SFML/Graphics.hpp>

/*
todo:

renderujemy wszystko na RenderTexture, któr¹ nak³adamy potem na Spirte "window". Mo¿na u¿yæ jakieœ unorderedmap zawieraj¹cej
wskazniki na klasy dziedziczace po sf::Drawable i wtedy metoda Display() nie bêdzie musia³a byæ przys³aniana.
*/


//30px bar
class Application : public sf::Drawable
{
public:
	Application(std::string title);
	virtual ~Application(){}
	virtual void display();
	virtual sf::RectangleShape& getWindow();
	virtual void moveWindow(sf::Vector2f position);
	virtual void moveWindow(float x, float y);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape window;
	sf::RenderTexture tx;
	std::string name; //check it

};

