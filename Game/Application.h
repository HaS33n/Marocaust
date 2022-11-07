#pragma once
#include <SFML/Graphics.hpp>

/*
todo:

renderujemy wszystko na RenderTexture, kt�r� nak�adamy potem na Spirte "window". Mo�na u�y� jakie� unorderedmap zawieraj�cej
wskazniki na klasy dziedziczace po sf::Drawable i wtedy metoda Display() nie b�dzie musia�a by� przys�aniana.
*/


//30px bar
class Application : public sf::Drawable
{
public:
	Application(std::string title);
	virtual ~Application(){}
	virtual void display(sf::RenderWindow& tW);
	virtual sf::Sprite& getSprite();
	virtual void moveWindow(sf::Vector2f position);
	virtual void moveWindow(float x, float y);
	virtual sf::RenderTexture& getSpriteTexture();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RenderTexture tx;
	sf::RenderTexture baseTX;
	sf::Sprite sprt;
	std::string name; //check it

};

