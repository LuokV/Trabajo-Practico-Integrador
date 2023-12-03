#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace sf;

class Textos {

	Text VIDA;
	Text Enemigos_abatidos;
	Text FINAL;
	Text GameOver;

	Font fuente;

public:

	Textos() {

		fuente.loadFromFile("Slackey-Regular.ttf");

		VIDA.setString("Vidas:");
		VIDA.setCharacterSize(40);
		VIDA.setFillColor(Color::White);
		VIDA.setFont(fuente);
		VIDA.setPosition(480, 500);


		Enemigos_abatidos.setString("Enemigos Abatidos:");
		Enemigos_abatidos.setCharacterSize(35);
		Enemigos_abatidos.setFillColor(Color::White);
		Enemigos_abatidos.setFont(fuente);
		Enemigos_abatidos.setPosition(20, 500);


		FINAL.setString("Puntaje Final:");
		FINAL.setCharacterSize(55);
		FINAL.setFillColor(Color::White);
		FINAL.setFont(fuente);
		FINAL.setPosition(70, 505);


		GameOver.setString("GAME OVER");
		GameOver.setCharacterSize(110);
		GameOver.setFont(fuente);
		GameOver.setOrigin(GameOver.getGlobalBounds().width / 2, GameOver.getGlobalBounds().height / 2);
		GameOver.setPosition(400,250);
		GameOver.setFillColor(Color::Red);

	}

	void Vidas(RenderWindow* App) {

		App->draw(VIDA);
	
	}

	void Enemigos_Abatidos(RenderWindow* App) {

		App->draw(Enemigos_abatidos);

	}

	void Puntaje_Final(RenderWindow* App) {
	
		App->draw(FINAL);
	
	}

	void GAMEOVER(RenderWindow* App) {

		App->draw(GameOver);

	}







};
