#pragma once

#include "object2D.h"

namespace m1
{
	class Square
	{
	protected:
		Mesh* mesh;
		std::string name;
		float length;
		glm::vec3 leftBottomCorner;
		bool occupied;
		int rowNumber;
	public:
		Square(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill) {
			this->mesh = object2D::CreateSquare(name, leftBottomCorner, length, color, fill);
			this->leftBottomCorner = leftBottomCorner;
			this->name = name;
			this->length = length;
			occupied = false;
		}

		~Square() {
			if (mesh != NULL)
				delete mesh;
		}

		// get mesh
		Mesh* getMesh() {
			return mesh;
		}

		std::string getName() {
			return name;
		}



		glm::vec3 getLeftBottomCorner() {
			return leftBottomCorner;
		}

		void setLeftBottomCorner(glm::vec3 leftBottomCorner) {
			this->leftBottomCorner = leftBottomCorner;
		}

		bool isOccupied() {
			return occupied;
		}

		void setOccupied(bool occupied) {
			this->occupied = occupied;
		}

		int getRowNumber() {
			return rowNumber;
		}

		void setRowNumber(int rowNumber) {
			this->rowNumber = rowNumber;
		}

	};
}