#pragma once

#include "object2D.h"

namespace m1
{
	class Bullet
	{
	protected:
		Mesh* mesh;
		float centerX;
		float centerY;
		glm::vec3 color;
		float translateX;
		float translateY;
		float speed;
		float angularStep;

	public:
		bool remaining;
		Bullet(const std::string& name, int length, glm::vec3 leftBottomCorner, glm::vec3 color, bool fill = false) {
			mesh = object2D::CreateStar(name, length, leftBottomCorner, color, fill);
			centerX = leftBottomCorner.x + length;
			centerY = leftBottomCorner.y + length;
			this->color = color;
			remaining = false;
		}

		~Bullet() {
			delete mesh;
		}

		Mesh* getMesh() {
			return mesh;
		}

		float getCenterX() {
			return centerX;
		}

		float getCenterY() {
			return centerY;
		}

		glm::vec3 getColor() {
			return color;
		}

		float getTranslateX() {
			return translateX;
		}

		float getTranslateY() {
			return translateY;
		}

		void setTranslateX(float translateX) {
			this->translateX = translateX;
		}

		void setTranslateY(float translateY) {
			this->translateY = translateY;
		}

		void setSpeed(float speed) {
			this->speed = speed;
		}

		float getSpeed() {
			return speed;
		}

		void setAngularStep(float angularStep) {
			this->angularStep = angularStep;
		}

		float getAngularStep() {
			return angularStep;
		}

	};
}