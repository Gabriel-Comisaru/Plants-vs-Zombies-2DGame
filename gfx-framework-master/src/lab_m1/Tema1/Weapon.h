#pragma once

#include "object2D.h"
#include "Square.h"
#include "Bullet.h"
#include "Zombie.h"

namespace m1
{
	class Weapon
	{
	protected:
		Mesh* mesh;
		std::string name;
		int length;
		glm::vec3 leftBottomCorner;
		glm::vec3 color;
		bool fill;
		bool placed;
		Square *square;
		int cost;
		int translateX;
		int translateY;
		float scaleX, scaleY;
		bool toDelete;
	public:
		std::vector<Bullet*> bullets;
		float bulletInterval;
		Zombie* zombieToShoot;
		Weapon(const std::string& name, int length, glm::vec3 leftBottomCorner, glm::vec3 color, bool fill) {
			this->mesh = object2D::CreateWeapon(name, length, leftBottomCorner, color, fill);
			this->leftBottomCorner = leftBottomCorner;
			this->length = length;
			this->color = color;
			this->fill = fill;
			this->name = name;
			placed = false;
			bulletInterval = 2;
			zombieToShoot = NULL;
			translateX = 0;
			translateY = 0;
			scaleX = 1;
			scaleY = 1;
			toDelete = false;
			placed = false;
		}

		~Weapon() {
			if (mesh)
				delete mesh;
		}

		void placeWeapon(glm::vec3 leftBottomCorner) {
			this->leftBottomCorner = leftBottomCorner;
			placed = true;
			recreateMesh();
		}

		void recreateMesh() {
			this->mesh = object2D::CreateWeapon(name, length, leftBottomCorner, color, fill);
		}

		Mesh* getMesh() {
			return mesh;
		}

		std::string getName() {
			return name;
		}

		int getLength() {
			return length;
		}

		glm::vec3 getLeftBottomCorner() {
			return leftBottomCorner;
		}

		glm::vec3 getColor() {
			return color;
		}

		bool getFill() {
			return fill;
		}

		int getCost() {
			return cost;
		}

		void setLeftBottomCorner(glm::vec3 leftBottomCorner) {
			this->leftBottomCorner = leftBottomCorner;
			recreateMesh();
		}

		void setLength(int length) {
			this->length = length;
			recreateMesh();
		}

		void setColor(glm::vec3 color) {
			this->color = color;
			recreateMesh();
		}

		void setFill(bool fill) {
			this->fill = fill;
			recreateMesh();
		}

		void setName(std::string name) {
			this->name = name;
			recreateMesh();
		}

		void setPlaced(bool placed) {
			this->placed = placed;
		}

		void setCost(int cost) {
			this->cost = cost;
		}

		bool getPlaced() {
			return placed;
		}	
		
		Square* getSquare() {
			return square;
		}

		void setSquare(Square* square) {
			this->square = square;
		}

		int getTranslateX() {
			return translateX;
		}

		void setTranslateX(int translateX) {
			this->translateX = translateX;
		}

		int getTranslateY() {
			return translateY;
		}

		void setTranslateY(int translateY) {
			this->translateY = translateY;
		}

		float getScaleX() {
			return scaleX;
		}

		void setScaleX(float scaleX) {
			this->scaleX = scaleX;
		}

		float getScaleY() {
			return scaleY;
		}

		void setScaleY(float scaleY) {
			this->scaleY = scaleY;
		}

		bool getToDelete() {
			return toDelete;
		}

		void setToDelete(bool toDelete) {
			this->toDelete = toDelete;
		}

		int getCenterX() {
			return leftBottomCorner.x + length / 2;
		}

		int getCenterY() {
			return leftBottomCorner.y;
		}
	};
}