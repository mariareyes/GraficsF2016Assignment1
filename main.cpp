#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TransformNode.h"

int main(int argc, char* argv)
{
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Purple");

	sf::RectangleShape body(sf::Vector2<float>(10.0f, 30.0f));
	sf::RectangleShape neck(sf::Vector2<float>(2.2f, 5.0f));
	sf::CircleShape headCirc(3, 100);
	sf::RectangleShape aspa(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa3(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa2(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa4(sf::Vector2<float>(15.0f, 4.0f));

	sf::RectangleShape body2(sf::Vector2<float>(10.0f, 30.0f));
	sf::RectangleShape neck2(sf::Vector2<float>(2.2f, 5.0f));
	sf::CircleShape headCirc2(3, 100);
	sf::RectangleShape aspa22(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa32(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa222(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa42(sf::Vector2<float>(15.0f, 4.0f));

	sf::RectangleShape body3(sf::Vector2<float>(10.0f, 30.0f));
	sf::RectangleShape neck3(sf::Vector2<float>(2.2f, 5.0f));
	sf::CircleShape headCirc3(3, 100);
	sf::RectangleShape aspa33(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa333(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa23(sf::Vector2<float>(15.0f, 4.0f));
	sf::RectangleShape aspa43(sf::Vector2<float>(15.0f, 4.0f));
	sf::Sprite elefantesSprite;

	

	sf::Texture aspasTextura;
	aspasTextura.loadFromFile("res/elefantitos.jpg");
	sf::Texture ladrillos;
	ladrillos.loadFromFile("res/ladrillos.jpg");
	sf::Texture cloudsTexture;
	cloudsTexture.loadFromFile("res/elefantesemfilas.jpg");
	cloudsTexture.setRepeated(true);

	elefantesSprite.setTexture(cloudsTexture);
	elefantesSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
	sf::IntRect backgroundRect = elefantesSprite.getTextureRect();
	float secondTimer = 0.0f; // elapsed time per second.
	float movementSpeed = 150.0f;
	
	body.setTexture(&ladrillos);
	neck.setTexture(&ladrillos);
	headCirc.setTexture(&ladrillos);
	aspa.setTexture(&aspasTextura);
	aspa3.setTexture(&aspasTextura);
	aspa2.setTexture(&aspasTextura);
	aspa4.setTexture(&aspasTextura);
	

	body2.setTexture(&ladrillos);
	neck2.setTexture(&ladrillos);
	headCirc2.setTexture(&ladrillos);
	aspa22.setTexture(&aspasTextura);
	aspa32.setTexture(&aspasTextura);
	aspa222.setTexture(&aspasTextura);
	aspa42.setTexture(&aspasTextura);

	body3.setTexture(&ladrillos);
	neck3.setTexture(&ladrillos);
	headCirc3.setTexture(&ladrillos);
	aspa33.setTexture(&aspasTextura);
	aspa333.setTexture(&aspasTextura);
	aspa23.setTexture(&aspasTextura);
	aspa43.setTexture(&aspasTextura);

	bool keyHeld = false;
	bool keyHeld2 = false;
	bool keyHeld3 = false;
	bool keyHeld4 = false;

	bool growing = true;
	float scaleFactor = 1.001;

	float growthFactor = 1.001f;
	float shrinkFactor = 0.999f;

	
	body.setOrigin(body.getLocalBounds().width / 2, body.getLocalBounds().height);
	body.setPosition(300, 500);
	body.setScale(2, 2);

	body2.setOrigin(body2.getLocalBounds().width / 2, body2.getLocalBounds().height);
	body2.setPosition(600, 500);
	body2.setScale(2, 2);

	body3.setOrigin(body3.getLocalBounds().width / 2, body3.getLocalBounds().height);
	body3.setPosition(900, 500);
	body3.setScale(2, 2);

	neck.setPosition((body.getLocalBounds().width / 4.0f), (body.getLocalBounds().height / 3.0f));
	neck.setScale(2, 2);
	neck.setOrigin(0.0f, 10.0f);

	neck2.setPosition((body2.getLocalBounds().width / 4.0f), (body2.getLocalBounds().height / 3.0f));
	neck2.setScale(2, 2);
	neck2.setOrigin(0.0f, 10.0f);

	neck3.setPosition((body3.getLocalBounds().width / 4.0f), (body3.getLocalBounds().height / 3.0f));
	neck3.setScale(2, 2);
	neck3.setOrigin(0.0f, 10.0f);

	headCirc.setOrigin(0.0f, 1.0f);
	headCirc.setPosition(-2.0f, -4.5f);

	headCirc2.setOrigin(0.0f, 1.0f);
	headCirc2.setPosition(-2.0f, -4.5f);

	headCirc3.setOrigin(0.0f, 1.0f);
	headCirc3.setPosition(-2.0f, -4.5f);

	sf::Vector2<float> armPosition(3.3f, 3.7f);
	sf::Vector2<float> armOrigin(0.0, aspa2.getLocalBounds().height/2);

	sf::Vector2<float> armPosition2(3.3f, 3.7f);
	sf::Vector2<float> armOrigin2(0.0, aspa23.getLocalBounds().height / 2);

	sf::Vector2<float> armPosition3(3.3f, 3.7f);
	sf::Vector2<float> armOrigin3(0.0, aspa23.getLocalBounds().height / 2);

	aspa3.setOrigin(armOrigin);
	aspa.setOrigin(armOrigin);
	aspa4.setOrigin(armOrigin);
	aspa2.setOrigin(armOrigin);

	aspa32.setOrigin(armOrigin);
	aspa22.setOrigin(armOrigin);
	aspa42.setOrigin(armOrigin);
	aspa222.setOrigin(armOrigin);

	aspa333.setOrigin(armOrigin);
	aspa33.setOrigin(armOrigin);
	aspa43.setOrigin(armOrigin);
	aspa23.setOrigin(armOrigin);

	aspa.setPosition(3.0f, 3.0f);
	aspa3.setPosition(3.0f, 3.0f);
	aspa2.setPosition(3.0f,3.0f);
	aspa4.setPosition(3.0f, 3.0f);

	aspa22.setPosition(3.0f, 3.0f);
	aspa32.setPosition(3.0f, 3.0f);
	aspa222.setPosition(3.0f, 3.0f);
	aspa42.setPosition(3.0f, 3.0f);

	aspa33.setPosition(3.0f, 3.0f);
	aspa333.setPosition(3.0f, 3.0f);
	aspa23.setPosition(3.0f, 3.0f);
	aspa43.setPosition(3.0f, 3.0f);
	


	TransformNode head(&headCirc);
	TransformNode neckTrans(&neck);
	TransformNode bodyTrans(&body);
	TransformNode upperArm(&aspa3);
	TransformNode lowerArm(&aspa);
	TransformNode upperArm2(&aspa4);
	TransformNode lowerArm2(&aspa2);

	TransformNode head2(&headCirc2);
	TransformNode neckTrans2(&neck2);
	TransformNode bodyTrans2(&body2);
	TransformNode upperArm22(&aspa32);
	TransformNode lowerArm22(&aspa22);
	TransformNode upperArm222(&aspa42);
	TransformNode lowerArm222(&aspa222);

	TransformNode head3(&headCirc3);
	TransformNode neckTrans3(&neck3);
	TransformNode bodyTrans3(&body3);
	TransformNode upperArm3(&aspa333);
	TransformNode lowerArm3(&aspa33);
	TransformNode upperArm23(&aspa43);
	TransformNode lowerArm23(&aspa23);

	
	head.AddChild(&lowerArm);
	head.AddChild(&lowerArm2);
	head.AddChild(&upperArm);
	head.AddChild(&upperArm2);
	neckTrans.AddChild(&head);
	bodyTrans.AddChild(&neckTrans);

	head2.AddChild(&lowerArm22);
	head2.AddChild(&lowerArm222);
	head2.AddChild(&upperArm22);
	head2.AddChild(&upperArm222);
	neckTrans2.AddChild(&head2);
	bodyTrans2.AddChild(&neckTrans2);

	head3.AddChild(&lowerArm3);
	head3.AddChild(&lowerArm23);
	head3.AddChild(&upperArm3);
	head3.AddChild(&upperArm23);
	neckTrans3.AddChild(&head3);
	bodyTrans3.AddChild(&neckTrans3);

	float elaspedTimeTotal = 0.0f;
	sf::Clock deltaTime;

	float bodyAngleCount = 0;
	float angleBodyAmount = 0;
	float fractional = 2.0f;
	double count = 1.0f;
	double remainInt = 0.0f;


	aspa.setRotation(0.0);
	aspa2.setRotation(180.0);
	aspa3.setRotation(90.0);
	aspa4.setRotation(270.0);

	aspa22.setRotation(0.0);
	aspa222.setRotation(180.0);
	aspa32.setRotation(90.0);
	aspa42.setRotation(270.0);

	aspa33.setRotation(0.0);
	aspa23.setRotation(180.0);
	aspa333.setRotation(90.0);
	aspa43.setRotation(270.0);
	float angleAmountTotal = 0.0f;
	sf::Transform transform4;
	sf::Transform transform2;
	sf::Transform transform3;

	sf::SoundBuffer buffer;
	buffer.loadFromFile("res/dog.wav");
	sf::Sound sound(buffer);
	sound.setLoop(true);
	sound.play();
	
	while (window.isOpen())
	{

		float elaspedTime = deltaTime.restart().asSeconds();
		//elaspedTimeTotal = elaspedTimeTotal + elaspedTime;
		sf::Transform transform = body.getTransform();
		

		sf::Event sfEvent;
		while (window.pollEvent(sfEvent))
		{
			if (sfEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (sfEvent.type == sf::Event::KeyPressed && (sfEvent.key.code == sf::Keyboard::Key::Num1 || sfEvent.key.code == sf::Keyboard::Key::Numpad1))
			{
				keyHeld = true;
			}
			else if (sfEvent.type == sf::Event::KeyPressed && (sfEvent.key.code == sf::Keyboard::Key::Num2 || sfEvent.key.code == sf::Keyboard::Key::Numpad2))
			{
				keyHeld2 = true;

			}
			else if (sfEvent.type == sf::Event::KeyPressed && (sfEvent.key.code == sf::Keyboard::Key::Num3 || sfEvent.key.code == sf::Keyboard::Key::Numpad3))
			{
				keyHeld3 = true;

			}
			else if (sfEvent.type == sf::Event::KeyPressed && (sfEvent.key.code == sf::Keyboard::Key::Num4 || sfEvent.key.code == sf::Keyboard::Key::Numpad4))
			{
				keyHeld4 = true;

			}
			else if (sfEvent.type == sf::Event::KeyReleased){
				keyHeld = false;
				keyHeld2 = false;
				keyHeld3 = false;
				keyHeld4 = false;
			
			}
			
		}

		float angleAmount = 90.0f;
		aspa.rotate(angleAmount * elaspedTime);
		aspa3.rotate(angleAmount * elaspedTime);
		aspa2.rotate(angleAmount * elaspedTime);
		aspa4.rotate(angleAmount * elaspedTime);

		aspa22.rotate(angleAmount * elaspedTime);
		aspa32.rotate(angleAmount * elaspedTime);
		aspa222.rotate(angleAmount * elaspedTime);
		aspa42.rotate(angleAmount * elaspedTime);

		aspa33.rotate(angleAmount * elaspedTime);
		aspa333.rotate(angleAmount * elaspedTime);
		aspa23.rotate(angleAmount * elaspedTime);
		aspa43.rotate(angleAmount * elaspedTime);
		if (keyHeld4)
		{


			
			angleBodyAmount = (angleAmount * elaspedTime);
			
			transform2.rotate(0.0, sf::Vector2<float>(body.getOrigin().x, body.getOrigin().y));
			transform3.rotate(0.0, sf::Vector2<float>(body2.getOrigin().x, body2.getOrigin().y));
			transform4.rotate(0.0, sf::Vector2<float>(body3.getOrigin().x, body3.getOrigin().y));
		
		
			
			



		}
		else if (keyHeld){

			angleBodyAmount = (angleAmount * elaspedTime);
			body.rotate(angleBodyAmount);
			transform4.rotate(angleAmount * elaspedTime, sf::Vector2<float>(body2.getPosition().x, body2.getPosition().y));
		
		}
		else if (keyHeld2){
			
			angleBodyAmount = (angleAmount * elaspedTime);
			body2.rotate(angleBodyAmount);
			transform2.rotate(angleAmount * elaspedTime, sf::Vector2<float>(body.getPosition().x, body.getPosition().y));
		
		}

		else if (keyHeld3){
			
			
			angleBodyAmount = (angleAmount * elaspedTime);

			body3.rotate(angleBodyAmount);
			transform3.rotate(angleAmount * elaspedTime, sf::Vector2<float>(body2.getPosition().x, body2.getPosition().y));


		}
		//elefantesSprite.move(10.0f * elaspedTime, 0);

		secondTimer += elaspedTime;
		sf::IntRect deltaRect = backgroundRect;
		deltaRect.left = backgroundRect.left + int(movementSpeed * secondTimer);
		elefantesSprite.setTextureRect(deltaRect);

		if (secondTimer > 1.0f)
		{
			secondTimer -= 1.0f;
			backgroundRect.left += int(movementSpeed);
			if (backgroundRect.left >= float(cloudsTexture.getSize().x)) {
				backgroundRect.left -= cloudsTexture.getSize().x;
			}
		}


		window.clear(); // draw fullscreen graphic
		window.draw(elefantesSprite);
		bodyTrans.Draw(&window,transform4);
		bodyTrans2.Draw(&window,transform2);
		bodyTrans3.Draw(&window, transform3);

		window.display();
	}

	return 0;
}