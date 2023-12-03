#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Mira.h";


 Crosshair::Crosshair() {

	cross_texture.loadFromFile("crosshair.png");
	cross.setTexture(cross_texture);
	cross.setScale(0.8f, 0.8f);

	Vector2u size = cross_texture.getSize();
	cross.setOrigin(size.x / 2.f, size.y / 2.f);

}

 void Crosshair:: Dibujar(RenderWindow* App){
 
	 App->draw(cross);
 
 }

 void Crosshair::Posicion(float x, float y) {

	 cross.setPosition(x, y);
 
 }

 Vector2f Crosshair::PosicionActual() {
 
	 return cross.getPosition();
 
 }
