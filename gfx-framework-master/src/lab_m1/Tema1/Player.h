#pragma once

#include "object2D.h"

namespace m1
{
	class Player
	{
	protected:
		int health;
		int stars;

	public:
		Player() {
			health = 3;
			stars = 5;
		}

		~Player() {
		}

		int getHealth() {
			return health;
		}

		void setHealth(int health) {
			this->health = health;
		}

		int getStars() {
			return stars;
		}

		void setStars(int stars) {
			this->stars = stars;
		}
	};
}