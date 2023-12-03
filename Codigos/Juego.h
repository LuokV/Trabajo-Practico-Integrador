#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Mira.h"
#include "Vaquero.h"
#include "Civil.h"
#include "Escenario.h"
#include "Textos.h"


using namespace sf;


class Juego {

	RenderWindow* App;

	Crosshair* jugador;
	
	Enemigo* vaquero;

	Inocente* civil;

	Background* fondo;

	Textos* texto;

	Text puntaje;
	Text vidas;
	Text Final_Puntaje;
	
	Font fuente;

	Clock reloj;
	float timeON;
	float timeOFF;
	
	int puntos;
	int vida_Jugador;
	int inocente_caidos;
	int puntaje_final;
	
	void ActualizarPuntos() {

		char pts[100];
		_itoa_s(puntos, pts, 10);
		puntaje.setString(pts);

		char vidas_restantes[100];
		_itoa_s(vida_Jugador, vidas_restantes, 10);
		vidas.setString(vidas_restantes);

		char Final[100];
		_itoa_s(puntaje_final,Final,10);
		Final_Puntaje.setString(Final);

	}

	

public:


	Juego() {

		App = new RenderWindow(VideoMode(800, 600, 32), "West");
		App->setMouseCursorVisible(false);
		App->setFramerateLimit(60);


		jugador = new Crosshair;

		vaquero = new Enemigo;

		civil = new Inocente;

		fondo = new Background;

		texto = new Textos;

		fuente.loadFromFile("Slackey-Regular.ttf");


		timeON = 1.5f;
		timeOFF = 0.9f;


		puntaje.setPosition(170, 530);
		puntaje.setCharacterSize(40);
		puntaje.setFillColor(Color::White);
		puntaje.setFont(fuente);

		vidas.setPosition(650, 500);
		vidas.setCharacterSize(40);
		vidas.setFillColor(Color::White);
		vidas.setFont(fuente);

		Final_Puntaje.setPosition(520, 505);
		Final_Puntaje.setCharacterSize(55);
		Final_Puntaje.setFillColor(Color::White);
		Final_Puntaje.setFont(fuente);

		puntos = 0;
		vida_Jugador = 3;
		inocente_caidos = 0;


		ActualizarPuntos();


	}


	void Loop() {
	
		while (App->isOpen()) {
			
			Eventos();
			Actualizar();
			Dibujar();

		}
	}


	void Eventos() {
	
		Event evt;

		while (App->pollEvent(evt)) {

			switch (evt.type) {

			case Event::Closed:
				App->close();
				break;


			case Event::MouseMoved:
				jugador->Posicion((float)evt.mouseMove.x, (float)evt.mouseMove.y);
				break;


			case Event::MouseButtonPressed:
				if (evt.mouseButton.button == Mouse::Button::Left) {

					Disparo();

				};
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape)) { App->close(); };

		}
	}


	void Disparo() { //Disparo al Vaquero/Civil

		Vector2f jugador_posicion = jugador->PosicionActual();


		if (vaquero->EnPantalla()) {

			if (vaquero->Encima(jugador_posicion.x, jugador_posicion.y)) {

				vaquero->Derrotar();
				puntos++;

			}
		}


		if (civil->EnPantalla()) {

			if (civil->Encima(jugador_posicion.x, jugador_posicion.y)) {

				civil->Derribado();
				vida_Jugador--;
				inocente_caidos++;

			}
		}

		vaquero->Revivir();
		civil->Revivir();

	}


	void Actualizar() {

		ActualizarPuntos();

		Apariciones();	

		PuntajeFinal();
		
	}


	void Apariciones() {
	
		if (!vaquero->EnPantalla() && !civil->EnPantalla()) {

			if (reloj.getElapsedTime().asSeconds() > timeOFF) {

				reloj.restart();

				civil->Visible();
				civil->PosicionAzar();

				vaquero->Visible();
				vaquero->PosicionAzar();


				int azar = rand() % 2;

				switch (azar)
				{
				case 0:

					civil->EnPantalla();

					vaquero->Invisible();

					break;

				case 1:

					vaquero->EnPantalla();

					civil->Invisible();


					break;
				}

			}
		}

		else {
			if (reloj.getElapsedTime().asSeconds() > timeON) {

				civil->Invisible();
				vaquero->Invisible();

				reloj.restart();
			}
		}

	}


	void PuntajeFinal() {

		puntaje_final = puntos - (inocente_caidos * 10);

		//if (puntaje_final < 0) { puntaje_final = 0; }

	}
	
	
	void Dibujar() {

		App->clear();


		if (vaquero->EnPantalla()) {

			vaquero->Dibujar(App);
		
		}
		
		if (civil->EnPantalla()) {
		
			civil->Dibujar(App);
		
		}


		fondo->DibujoFondo(App); 


		if (vaquero->EnPantalla() && (reloj.getElapsedTime().asSeconds() > (timeON-0.2f))) {

			vaquero->Disparo_Bang(App);

			if (reloj.getElapsedTime().asSeconds() > (timeON - 0.016f)) { vida_Jugador--; }

		}
		

		texto->Enemigos_Abatidos(App);
		App->draw(puntaje);

		texto->Vidas(App);
		App->draw(vidas);


		jugador->Dibujar(App);


		if (vida_Jugador == 0) {

			App->clear();

			fondo->DibujoFondo(App);

			texto->GAMEOVER(App);

			vaquero->Derrotar();
			civil->Derribado();

			texto->Puntaje_Final(App);
			App->draw(Final_Puntaje);

		}

		App->display();
	
	}

	
	~Juego() {

		delete vaquero;
		delete jugador;
		delete civil;
		delete fondo;
		delete texto;
		delete App;

	}


};
