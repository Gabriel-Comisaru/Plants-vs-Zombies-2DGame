#pragma once

#include <random>

#include "components/simple_scene.h"

#include "Weapon.h"
#include "Square.h"
#include "Player.h"
#include "Bullet.h"
#include "Zombie.h"

namespace m1
{
	class Tema1 : public gfxc::SimpleScene
	{
	public:
		Tema1();
		~Tema1();

		void Init() override;
	private:
		void FrameStart() override;
		void Update(float deltaTimeSeconds) override;
		void FrameEnd() override;

		void OnInputUpdate(float deltaTime, int mods) override;
		void OnKeyPress(int key, int mods) override;
		void OnKeyRelease(int key, int mods) override;
		void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
		void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
		void OnWindowResize(int width, int height) override;

		protected:
			float cx, cy;
			glm::mat3 modelMatrix;
			float translateX, translateY;
			float scaleX, scaleY;
			float angularStep;

			float squareSide, square1Side, starSide, hexSide, weaponSide;
			float rectangleHeight, rectangleWidth;
			float weaponSquareSideY, weaponSquareSideX;
			int sign;
			std::vector<Square*> squares;
			std::vector<Square*> weaponSquares;
			std::vector<Weapon*> weapons;
			std::vector<Zombie*> zombies;
			std::vector<Weapon*> placedWeapons;
			std::vector<Bullet*> bullets; // 0 - orange, 1 - blue, 2 - yellow, 3 - violet
			std::vector<Zombie*> zombiesToSpawn;
			std::vector<Bullet*> starPoints;
			Weapon* copyWeapon = NULL;
			Player* player;
			float squareSpace;
			float translateZombieX, translateZombieY;
			float translateBulletX, translateBulletY;
			float radiusSum;
			float weaponCenterX, weaponCenterY;
			float zombieCenterX, zombieCenterY;
			float rows = 3;
			float columns = 3;
			float bulletSpeed;
			float bulletCenterX, bulletCenterY;
			float houseCenterX, houseCenterY;
			float healthX, healthY;
			float zombieInterval, bulletInterval, starInterval;
	};
}