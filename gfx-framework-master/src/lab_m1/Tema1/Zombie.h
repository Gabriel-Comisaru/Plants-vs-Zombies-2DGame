#pragma once

#include "object2D.h"

namespace m1
{
	class Zombie
	{
	protected:
		Mesh* interiorMesh;
		Mesh* exteriorMesh;
		std::string name;
		int length;
		glm::vec3 upperCenter;
		glm::vec3 exteriorColor;
		glm::vec3 interiorColor;
		bool fill;
		int health;
		int rowNumber;
		float translateX;
		float translateY;
		float scaleExteriorX, scaleExteriorY;
		float scaleInteriorX, scaleInteriorY;

	public:
		bool toDelete;
		Zombie(const std::string& name, int length, glm::vec3 upperCenter, glm::vec3 exteriorColor, glm::vec3 interiorColor, bool fill) {
			this->exteriorMesh = object2D::CreateHex(name, length, upperCenter, exteriorColor, fill);
			this->interiorMesh = object2D::CreateMiniHex(name, length, upperCenter, interiorColor, fill);
			this->name = name;
			this->length = length;
			this->upperCenter = upperCenter;
			this->fill = fill;
			this->health = 3;
			this->interiorColor = interiorColor;
			this->exteriorColor = exteriorColor;
			toDelete = false;
			scaleExteriorX = 1;
			scaleExteriorY = 1;
			scaleInteriorX = 0.7;
			scaleInteriorY = 0.7;
		}

		~Zombie() {
			delete this->exteriorMesh;
			delete this->interiorMesh;
		}

		void recreateMesh() {
			this->exteriorMesh = object2D::CreateHex(name, length, upperCenter, exteriorColor, fill);
			this->interiorMesh = object2D::CreateMiniHex(name, length, upperCenter, interiorColor, fill);
		}

		Mesh* getExteriorMesh() {
			return this->exteriorMesh;
		}

		Mesh* getInteriorMesh() {
			return this->interiorMesh;
		}

		std::string getName() {
			return this->name;
		}

		int getLength() {
			return this->length;
		}

		glm::vec3 getUpperCenter() {
			return this->upperCenter;
		}

		glm::vec3 getColor() {
			return this->exteriorColor;
		}

		glm::vec3 getInteriorColor() {
			return this->interiorColor;
		}

		bool getFill() {
			return this->fill;
		}

		int getHealth() {
			return this->health;
		}

		void setHealth(int health) {
			this->health = health;
		}

		void setUpperCenter(glm::vec3 upperCenter) {
			this->upperCenter = upperCenter;
			recreateMesh();
		}

		void setRowNumber(int rowNumber) {
			this->rowNumber = rowNumber;
		}

		int getRowNumber() {
			return this->rowNumber;
		}

		void setTranslateX(float translateX) {
			this->translateX = translateX;
		}

		float getTranslateX() {
			return this->translateX;
		}

		void setTranslateY(float translateY) {
			this->translateY = translateY;
		}

		float getTranslateY() {
			return this->translateY;
		}

		void setScaleExteriorX(float scaleExteriorX) {
			this->scaleExteriorX = scaleExteriorX;
		}

		float getScaleExteriorX() {
			return this->scaleExteriorX;
		}

		void setScaleExteriorY(float scaleExteriorY) {
			this->scaleExteriorY = scaleExteriorY;
		}

		float getScaleExteriorY() {
			return this->scaleExteriorY;
		}

		void setScaleInteriorX(float scaleInteriorX) {
			this->scaleInteriorX = scaleInteriorX;
		}

		float getScaleInteriorX() {
			return this->scaleInteriorX;
		}

		void setScaleInteriorY(float scaleInteriorY) {
			this->scaleInteriorY = scaleInteriorY;
		}

		float getScaleInteriorY() {
			return this->scaleInteriorY;
		}

	};
}