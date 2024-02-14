#include "lab_m1/Tema1/Tema1.h"
#include "lab_m1/Tema1/Zombie.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init(){
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	player = new Player();


	glm::vec3 corner = glm::vec3(0, 0, 0);

	weaponSquareSideY = resolution.y;
	weaponSquareSideX = resolution.x;

	squareSide = 100;
	rectangleHeight = 400;
	rectangleWidth = 50;
	square1Side = (rectangleHeight - rectangleWidth) / 3;
	starSide = square1Side / 8;
	hexSide = square1Side / 4;
	weaponSide = square1Side / 3;

	squareSpace = rectangleWidth / 2 + square1Side;

	houseCenterX = rectangleWidth / 2 + 20;
	houseCenterY = rectangleHeight / 2 + 20;

	// hex center
	cx = corner.x + square1Side / 2;
	cy = corner.y + square1Side / 2;

	sign = 1;

	translateX = 0;
	translateY = 0;
	translateZombieX = 0;
	translateZombieY = 0;
	translateBulletX = 0;
	translateBulletY = 0;

	healthX = resolution.x - 200 - 2 * (rectangleWidth / 2 + 2 * square1Side / 3);
	healthY = resolution.y - 20 - square1Side / 3;


	scaleX = 1;
	scaleY = 1;

	angularStep = 0;

	bulletSpeed = 200;

	starInterval = 0;

	Mesh* rectangle1 = object2D::CreateRectangle("rectangle1", corner, rectangleWidth, rectangleHeight, glm::vec3(1, 0, 0), true);
	AddMeshToList(rectangle1);

	// first row
	Square* square1 = new Square("square1", glm::vec3(1,1,0), square1Side, glm::vec3(0, 1, 0), true);

	Square * square2 = new Square("square2", corner, square1Side, glm::vec3(0, 1, 0), true);

	Square* square3 = new Square("square3", corner, square1Side, glm::vec3(0, 1, 0), true);


	// second row
	Square* square4 = new Square("square4", corner, square1Side, glm::vec3(0, 1, 0), true);

	Square* square5 = new Square("square5", corner, square1Side, glm::vec3(0, 1, 0), true);

	Square* square6 = new Square("square6", corner, square1Side, glm::vec3(0, 1, 0), true);

	// third row
	Square* square7 = new Square("square7", corner, square1Side, glm::vec3(0, 1, 0), true);

	Square* square8 = new Square("square8", corner, square1Side, glm::vec3(0, 1, 0), true);

	Square* square9 = new Square("square9", corner, square1Side, glm::vec3(0, 1, 0), true);

	squares.push_back(square1);
	squares.push_back(square2);
	squares.push_back(square3);
	squares.push_back(square4);
	squares.push_back(square5);
	squares.push_back(square6);
	squares.push_back(square7);
	squares.push_back(square8);
	squares.push_back(square9);

	// weapons squares
	Square* weaponSquare1 = new Square("weaponSquare1", corner, square1Side, glm::vec3(0, 0, 0), false);

	Square* weaponSquare2 = new Square("weaponSquare2", corner, square1Side, glm::vec3(0, 0, 0), false);

	Square* weaponSquare3 = new Square("weaponSquare3", corner, square1Side, glm::vec3(0, 0, 0), false);

	Square* weaponSquare4 = new Square("weaponSquare4", corner, square1Side, glm::vec3(0, 0, 0), false);

	weaponSquares.push_back(weaponSquare1);
	weaponSquares.push_back(weaponSquare2);
	weaponSquares.push_back(weaponSquare3);
	weaponSquares.push_back(weaponSquare4);

	// weapons stars
	Mesh* star1 = object2D::CreateStar("star1", starSide, corner, glm::vec3(0.5, 0.5, 0.5), true);
	AddMeshToList(star1);

	// weapon 1
	// orange color
	Weapon* weapon1 = new Weapon("weapon1", square1Side / 3, corner, glm::vec3(1, 0.5, 0), true);

	// weapon 2
	// blue color
	Weapon* weapon2 = new Weapon("weapon2", square1Side / 3, corner, glm::vec3(0, 0, 1), true);
	

	// weapon 3
	// yellow color
	Weapon* weapon3 = new Weapon("weapon3", square1Side / 3, corner, glm::vec3(1, 1, 0), true);

	// weapon 4
	// violet color
	Weapon* weapon4 = new Weapon("weapon4", square1Side / 3, corner, glm::vec3(0.4, 0, 0.8), true);

	weapons.push_back(weapon1);
	weapons.push_back(weapon2);
	weapons.push_back(weapon3);
	weapons.push_back(weapon4);

	// health
	/*Mesh* health = object2D::CreateSquare("health", corner, square1Side, glm::vec3(1, 0, 0), true);
	AddMeshToList(health);*/
	Mesh* health = object2D::CreateHeart("health", square1Side / 2, corner, glm::vec3(1, 0, 0), true);
	AddMeshToList(health);

	// Blue zombie
	Zombie* zombie1 = new Zombie("zombie1Exterior", hexSide, corner, glm::vec3(0, 0, 1), glm::vec3(0, 0.6, 0.7), true);
	zombies.push_back(zombie1);
	
	// Yellow zombie
	Zombie* zombie2 = new Zombie("zombie2Exterior", hexSide, corner, glm::vec3(1, 1, 0), glm::vec3(0.7, 0.7, 0), true);
	zombies.push_back(zombie2);

	// Violet zombie
	Zombie* zombie3 = new Zombie("zombie3Exterior", hexSide, corner, glm::vec3(0.4, 0, 0.8), glm::vec3(0.7, 0, 0.7), true);
	zombies.push_back(zombie3);

	// Orange zombie
	Zombie* zombie4 = new Zombie("zombie4Exterior", hexSide, corner, glm::vec3(1, 0.5, 0), glm::vec3(0.7, 0.3, 0), true);
	zombies.push_back(zombie4);


	Mesh* circle = object2D::CreateCircle("circle", corner, weaponSide + weaponSide / 2, glm::vec3(0, 0, 1), false, 100);
	AddMeshToList(circle);

	radiusSum = hexSide + weaponSide / 2 + weaponSide;

	Mesh* circleZombie = object2D::CreateCircle("circleZombie", corner, hexSide, glm::vec3(0, 0, 1), false, 100);
	AddMeshToList(circleZombie);


	// star points
	Bullet* starPoint = new Bullet("starPoint", starSide, glm::vec3(0, 0, 9), glm::vec3(1, 1, 0), true);

	// Boss star
	Bullet* bossStar = new Bullet("bossStar", starSide, glm::vec3(0, 0, 9), glm::vec3(0, 1, 0), true);
	AddMeshToList(bossStar->getMesh());



	bulletCenterX = corner.x + starSide;
	bulletCenterY = corner.y + starSide;

	zombieInterval = 0;
	bulletInterval = 0;

}

void Tema1::FrameStart() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds) {
	translateX = 20;
	translateY = 20;

	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);

	zombieInterval += deltaTimeSeconds;
	starInterval += deltaTimeSeconds;

	RenderMesh2D(meshes["rectangle1"], shaders["VertexColor"], modelMatrix);

	// health squares
	float saveHealthX = healthX;
	for (int i = 0; i < player->getHealth(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(healthX, healthY);
		RenderMesh2D(meshes["health"], shaders["VertexColor"], modelMatrix);
		healthX += rectangleWidth / 2 + square1Side;
	}
	healthX = saveHealthX;

	// player stars
	for (int i = 0; i < player->getStars(); i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(healthX - square1Side / 2, healthY - square1Side - starSide);
		RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);
		healthX += rectangleWidth / 2 + starSide;
	}

	healthX = saveHealthX;



	// first row
	translateX += 3 * rectangleWidth / 2;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[0]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[0]->setRowNumber(0);
	RenderMesh2D(squares[0]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[1]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[1]->setRowNumber(0);
	RenderMesh2D(squares[1]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[2]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[2]->setRowNumber(0);
	RenderMesh2D(squares[2]->getMesh(), shaders["VertexColor"], modelMatrix);
	
	// second row
	translateX = 20 + 3 * rectangleWidth / 2;
	translateY += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[3]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[3]->setRowNumber(1);
	RenderMesh2D(squares[3]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[4]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[4]->setRowNumber(1);
	RenderMesh2D(squares[4]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[5]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[5]->setRowNumber(1);
	RenderMesh2D(squares[5]->getMesh(), shaders["VertexColor"], modelMatrix);

	// third row
	translateX = 20 + 3 * rectangleWidth / 2;
	translateY += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[6]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[6]->setRowNumber(2);
	RenderMesh2D(squares[6]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[7]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[7]->setRowNumber(2);
	RenderMesh2D(squares[7]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += squareSpace;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	squares[8]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	squares[8]->setRowNumber(2);
	RenderMesh2D(squares[8]->getMesh(), shaders["VertexColor"], modelMatrix);

	// weapons squares
	translateY = weaponSquareSideY - 20 - square1Side;
	translateX = 10 + rectangleWidth;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weaponSquares[0]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	RenderMesh2D(weaponSquares[0]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += 3 * square1Side / 2;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weaponSquares[1]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	RenderMesh2D(weaponSquares[1]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += 3 * square1Side / 2;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weaponSquares[2]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	RenderMesh2D(weaponSquares[2]->getMesh(), shaders["VertexColor"], modelMatrix);

	translateX += 3 * square1Side / 2;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weaponSquares[3]->setLeftBottomCorner(glm::vec3(translateX, translateY, 0));
	RenderMesh2D(weaponSquares[3]->getMesh(), shaders["VertexColor"], modelMatrix);

	// weapons stars
	// first weapon
	translateY = weaponSquareSideY - 20 - square1Side - squareSide / 3 - 1;
	translateX = 10 + rectangleWidth;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	// second weapon
	translateX += square1Side / 2 + square1Side;
	int saveX = translateX;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX += starSide * 3;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX = saveX;

	// third weapon
	translateX += square1Side / 2 + square1Side;
	saveX = translateX;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX += starSide * 3;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX = saveX;

	// fourth weapon
	translateX += square1Side / 2 + square1Side;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX += starSide * 3;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);

	translateX += starSide * 3;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	RenderMesh2D(meshes["star1"], shaders["VertexColor"], modelMatrix);




	// weapon 1
	translateY = weaponSquareSideY - 20 - square1Side / 2;
	translateX = 10 + rectangleWidth + square1Side / 4;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weapons[0]->setCost(1);
	RenderMesh2D(weapons[0]->getMesh(), shaders["VertexColor"], modelMatrix);

	// weapon 2
	translateX += square1Side / 2 + square1Side;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weapons[1]->setCost(2);
	RenderMesh2D(weapons[1]->getMesh(), shaders["VertexColor"], modelMatrix);

	// weapon 3
	translateX += square1Side / 2 + square1Side;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weapons[2]->setCost(2);
	RenderMesh2D(weapons[2]->getMesh(), shaders["VertexColor"], modelMatrix);

	// weapon 4
	translateX += square1Side / 2 + square1Side;
	modelMatrix = glm::mat3(1);
	modelMatrix *= transform2D::Translate(translateX, translateY);
	weapons[3]->setCost(3);
	RenderMesh2D(weapons[3]->getMesh(), shaders["VertexColor"], modelMatrix);

	
	std::random_device rd;
	std::mt19937 generator(rd());

	// spawn zombies randomly
	if (zombieInterval >= 4) {
		translateZombieX = 0;
		translateZombieY = 0;
		int lowerBound = 0;
		int upperBound = 2;

		std::uniform_int_distribution<int> rowDistribution(lowerBound, upperBound);
		int randomRow = rowDistribution(generator);
		cout << randomRow << endl;

		translateZombieX = weaponSquareSideX + hexSide / 2;
		translateZombieY = squares[randomRow * 3 + 1]->getLeftBottomCorner().y + square1Side / 2;
		
		upperBound = 3;
		std::uniform_int_distribution<int> colorDistribution(lowerBound, upperBound);
		int randomColor = colorDistribution(generator);
		if (randomColor == 0) {
			Zombie* zombie = new Zombie(zombies[0]->getName(), zombies[0]->getLength(), zombies[0]->getUpperCenter(), 
				zombies[0]->getColor(), zombies[0]->getInteriorColor(), zombies[0]->getFill());
			zombie->setRowNumber(randomRow);
			zombie->setTranslateX(translateZombieX);
			zombie->setTranslateY(translateZombieY);
			zombiesToSpawn.push_back(zombie);
		} 
		else if (randomColor == 1) {
			Zombie* zombie = new Zombie(zombies[1]->getName(), zombies[1]->getLength(), zombies[1]->getUpperCenter(),
				zombies[1]->getColor(), zombies[1]->getInteriorColor(), zombies[1]->getFill());
			zombie->setRowNumber(randomRow);
			zombie->setTranslateX(translateZombieX);
			zombie->setTranslateY(translateZombieY);
			zombiesToSpawn.push_back(zombie);
		} 
		else if (randomColor == 2) {
			Zombie* zombie = new Zombie(zombies[2]->getName(), zombies[2]->getLength(), zombies[2]->getUpperCenter(),
				zombies[2]->getColor(), zombies[2]->getInteriorColor(), zombies[2]->getFill());
			zombie->setRowNumber(randomRow);
			zombie->setTranslateX(translateZombieX);
			zombie->setTranslateY(translateZombieY);
			zombiesToSpawn.push_back(zombie);
		}
		else if (randomColor == 3) {
			Zombie* zombie = new Zombie(zombies[3]->getName(), zombies[3]->getLength(), zombies[3]->getUpperCenter(),
				zombies[3]->getColor(), zombies[3]->getInteriorColor(), zombies[3]->getFill());
			zombie->setRowNumber(randomRow);
			zombie->setTranslateX(translateZombieX);
			zombie->setTranslateY(translateZombieY);
			zombie->setHealth(5);
			zombie->boss = true;
			zombiesToSpawn.push_back(zombie);
		}
		zombieInterval = 0;
	}

	// spawn star points randomly, 3 at a time
	if (starInterval >= 7) {
		for (int i = 0; i < 3; i++) {
			int randomX = 0;
			int randomY = 0;
			std::uniform_int_distribution<int> XDistribution(100, weaponSquareSideX - 100);
			randomX = XDistribution(generator);

			std::uniform_int_distribution<int> YDistribution(100, weaponSquareSideY - 100);
			randomY = YDistribution(generator);

			Bullet* starPoint = new Bullet("starPoint", starSide * 2, glm::vec3(0, 0, 9), glm::vec3(1, 0.5, 0.8), true);
			starPoint->setTranslateX(randomX);
			starPoint->setTranslateY(randomY);
			starPoints.push_back(starPoint);
		}
		starInterval = 0;
	}

	// render star points
	for (Bullet* starPoint : starPoints) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(starPoint->getTranslateX(), starPoint->getTranslateY());
		RenderMesh2D(starPoint->getMesh(), shaders["VertexColor"], modelMatrix);
	}


	scaleX = 0.7;
	scaleY = 0.7;

	// spawn zombies + collision with house + weapon collision
	for (Zombie* zombie : zombiesToSpawn) {
		zombieCenterX = zombie->getTranslateX() + hexSide;
		zombieCenterY = zombie->getTranslateY();

		// as long as the zombie is not in front of the house, it keeps moving
		if (zombie->getTranslateX() > houseCenterX) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(zombie->getTranslateX(), zombie->getTranslateY());
			modelMatrix *= transform2D::Scale(zombie->getScaleExteriorX(), zombie->getScaleExteriorY());
			RenderMesh2D(zombie->getExteriorMesh(), shaders["VertexColor"], modelMatrix);
			modelMatrix *= transform2D::Scale(zombie->getScaleInteriorX(), zombie->getScaleInteriorY());
			RenderMesh2D(zombie->getInteriorMesh(), shaders["VertexColor"], modelMatrix);
			if (zombie->boss == true && zombie->toDelete == false) {
				// add a red star inside of zombie
				modelMatrix = glm::mat3(1);
				modelMatrix *= transform2D::Translate(zombie->getTranslateX() - starSide / 2, zombie->getTranslateY() - starSide / 2);
				modelMatrix *= transform2D::Scale(0.5, 0.5);
				RenderMesh2D(meshes["bossStar"], shaders["VertexColor"], modelMatrix);
			}
			if (zombie->toDelete == false) { // if the zombie is not dead
				zombie->setTranslateX(zombie->getTranslateX() - deltaTimeSeconds * 50);
			}
			else {
				if (zombie->getScaleExteriorX() <= 0) { // if the zombie is dead
					zombiesToSpawn.erase(std::remove(zombiesToSpawn.begin(), zombiesToSpawn.end(), zombie), zombiesToSpawn.end());
				}
				// if the zombie is dying, animate it by scaling until reaches 0
				zombie->setScaleExteriorX(zombie->getScaleExteriorX() - deltaTimeSeconds * 2);
				zombie->setScaleExteriorY(zombie->getScaleExteriorY() - deltaTimeSeconds * 2);
				zombie->setScaleInteriorX(zombie->getScaleInteriorX() - deltaTimeSeconds * 2);
				zombie->setScaleInteriorY(zombie->getScaleInteriorY() - deltaTimeSeconds * 2);
			}
		}
		else { // if the zombie is in front of the house
			player->setHealth(player->getHealth() - 1); // reduce player's health
			if (player->getHealth() == 0) { // if the player is dead
							exit(0);
						}
			zombie->setTranslateX(0);
			zombie->setTranslateY(0);
			zombiesToSpawn.erase(std::remove(zombiesToSpawn.begin(), zombiesToSpawn.end(), zombie), zombiesToSpawn.end());
		}


		// Weapon collision with zombie
		if (placedWeapons.size() != 0) {
			for (Weapon* weapon : placedWeapons) {
				weaponCenterX = weapon->getTranslateX() + weaponSide;
				weaponCenterY = weapon->getTranslateY();
				
				if (glm::distance(glm::vec2(zombieCenterX, zombieCenterY), glm::vec2(weaponCenterX, weaponCenterY)) < radiusSum)
				{
					if (weapon == copyWeapon) {
						copyWeapon = NULL;
					}
					Square* square = weapon->getSquare();
					weapon->setToDelete(true);
				}
			}
		}
	}

	// copyWeapon before placing it, the one being dragged by the mouse
	if (copyWeapon != NULL && copyWeapon->getPlaced() != true) {
		translateY = weaponSquareSideY - 20 - square1Side / 2;
		translateX = 10 + rectangleWidth + square1Side / 4;
		modelMatrix = glm::mat3(1);
		modelMatrix *= transform2D::Translate(translateX, translateY);
		RenderMesh2D(copyWeapon->getMesh(), shaders["VertexColor"], modelMatrix);
	}

	// placed weapons
	if (placedWeapons.size() != 0) {
		for (Weapon* copyWeapon : placedWeapons) {
			// render placed weapons
			modelMatrix = glm::mat3(1);
			modelMatrix *= transform2D::Translate(copyWeapon->getTranslateX(), copyWeapon->getTranslateY());
			modelMatrix *= transform2D::Translate(copyWeapon->getCenterX(), copyWeapon->getCenterY());
			modelMatrix *= transform2D::Scale(copyWeapon->getScaleX(), copyWeapon->getScaleY());
			modelMatrix *= transform2D::Translate(-copyWeapon->getCenterX(), -copyWeapon->getCenterY());
			RenderMesh2D(copyWeapon->getMesh(), shaders["VertexColor"], modelMatrix);

			if (copyWeapon->getToDelete() == true) { // if the weapon is to be deleted animate it by scaling until reaches 0
				copyWeapon->setScaleX(copyWeapon->getScaleX() - deltaTimeSeconds * 2);
				copyWeapon->setScaleY(copyWeapon->getScaleY() - deltaTimeSeconds * 2);
			}

			if (copyWeapon->getScaleX() <= 0) { // if the weapon reached 0 scale, delete it
				Square* square = copyWeapon->getSquare();
				square->setOccupied(false);
				placedWeapons.erase(std::remove(placedWeapons.begin(), placedWeapons.end(), copyWeapon), placedWeapons.end());
				delete copyWeapon;
				copyWeapon = NULL;
				continue;
			}

			weaponCenterX = copyWeapon->getTranslateX() + weaponSide / 2;
			weaponCenterY = copyWeapon->getTranslateY();
			
			for (Zombie* zombie : zombiesToSpawn) {
				if (copyWeapon->getPlaced() == true && copyWeapon->getToDelete() != true) {

					zombieCenterX = zombie->getTranslateX() + hexSide;
					zombieCenterY = zombie->getTranslateY();

					// verify if the zombie is in front of the weapon
					if (zombie->getColor() == copyWeapon->getColor() &&
						zombie->getRowNumber() == copyWeapon->getSquare()->getRowNumber()) {

						// if the weapon is not already shooting a zombie, make it shoot the current zombie
						if (copyWeapon->zombieToShoot == NULL && zombie->toDelete == false) {
							copyWeapon->zombieToShoot = zombie;
						}

						// if the weapon is not shooting the current zombie, continue
						if (copyWeapon->zombieToShoot != zombie) {
							continue;
						}


						copyWeapon->bulletInterval += deltaTimeSeconds;

						// shoot another bullet
						if (copyWeapon->bulletInterval >= 2) {
							translateBulletX = weaponCenterX + weaponSide / 2;
							translateBulletY = weaponCenterY;
							copyWeapon->bulletInterval = 0;
							Bullet* bullet = new Bullet("bullet", starSide, glm::vec3(0, 0, 4), copyWeapon->getColor(), true);
							bullet->setTranslateX(translateBulletX);
							bullet->setTranslateY(translateBulletY);
							bullet->setSpeed(bulletSpeed);
							bullet->setAngularStep(0);
							copyWeapon->bullets.push_back(bullet);
						}

						// render bullets
						for (Bullet* bullet : copyWeapon->bullets) {
							// if the bullet reached a zombie, delete it
							if (zombieCenterX != 0 && glm::distance(glm::vec2(bullet->getTranslateX() + starSide, bullet->getTranslateY() + starSide),
								glm::vec2(zombieCenterX, zombieCenterY)) < radiusSum) {
								bullet->setTranslateX(weaponCenterX);
								bullet->setTranslateY(weaponCenterY);
								copyWeapon->bullets.erase(std::remove(copyWeapon->bullets.begin(), copyWeapon->bullets.end(), bullet), copyWeapon->bullets.end());
								zombie->setHealth(zombie->getHealth() - 1); // reduce zombie's health
								if (zombie->getHealth() == 0) { // if the zombie is dead
									// remove the zombie from all weapons that were shooting it
									for (Weapon* weapon : placedWeapons) {
										if (weapon->zombieToShoot == zombie) {
											weapon->zombieToShoot = NULL;
											// save the bullets that were shot by the weapon and didnt reach the zombie
											for (Bullet* bullet : weapon->bullets) {
												bullet->remaining = true;
											}
										}
									}
									
									zombie->toDelete = true;

									copyWeapon->zombieToShoot = NULL;
									for (Bullet* bullet : copyWeapon->bullets) {
										bullet->remaining = true;
									}
								}
							}
							else if (bullet->remaining == false) {
								modelMatrix = glm::mat3(1);
								modelMatrix *= transform2D::Translate(bullet->getTranslateX(), bullet->getTranslateY() - starSide);
								modelMatrix *= transform2D::Translate(bullet->getCenterX(), bullet->getCenterY());
								modelMatrix *= transform2D::Rotate(bullet->getAngularStep());
								modelMatrix *= transform2D::Translate(-bullet->getCenterX(), -bullet->getCenterY());
								RenderMesh2D(bullet->getMesh(), shaders["VertexColor"], modelMatrix);
								bullet->setTranslateX(bullet->getTranslateX() + deltaTimeSeconds * bullet->getSpeed());
								bullet->setAngularStep(bullet->getAngularStep() - deltaTimeSeconds * 4);
							}
						}
					}
				}
			}
			int count = 0;
			// render remaining bullets
			for (Bullet* remainingBullet : copyWeapon->bullets) {
				count = 0;
				if (remainingBullet->remaining == false) {
					continue;
				}
				for (Zombie* zombie : zombies) {
					zombieCenterX = zombie->getTranslateX() + hexSide;
					zombieCenterY = zombie->getTranslateY();
					// if the bullet reached the end of the screen or a zombie, delete it
					if (remainingBullet->getTranslateX() >= weaponSquareSideX || zombieCenterX != 0 && glm::distance(glm::vec2(remainingBullet->getTranslateX() + starSide, remainingBullet->getTranslateY() + starSide),
						glm::vec2(zombieCenterX, zombieCenterY)) < radiusSum) {
						copyWeapon->bullets.erase(std::remove(copyWeapon->bullets.begin(), copyWeapon->bullets.end(), remainingBullet), copyWeapon->bullets.end());
						zombie->setHealth(zombie->getHealth() - 1);
						continue;
					}
					else if (count == 0) { //render each bullet one at a time, so it wont be rendered by each zombie
						count++;
						modelMatrix = glm::mat3(1);
						modelMatrix *= transform2D::Translate(remainingBullet->getTranslateX(), remainingBullet->getTranslateY() - starSide);
						modelMatrix *= transform2D::Translate(remainingBullet->getCenterX(), remainingBullet->getCenterY());
						modelMatrix *= transform2D::Rotate(remainingBullet->getAngularStep());
						modelMatrix *= transform2D::Translate(-remainingBullet->getCenterX(), -remainingBullet->getCenterY());
						RenderMesh2D(remainingBullet->getMesh(), shaders["VertexColor"], modelMatrix);
						remainingBullet->setTranslateX(remainingBullet->getTranslateX() + deltaTimeSeconds * remainingBullet->getSpeed());
						remainingBullet->setAngularStep(remainingBullet->getAngularStep() - deltaTimeSeconds * 4);
					}
				}
			}
		}
	}

}

void Tema1::FrameEnd() {
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{

}


void Tema1::OnKeyRelease(int key, int mods)
{
	// Add key release event
}

bool isLeftMouseButtonPressed = false;

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	if (isLeftMouseButtonPressed) { // if left mouse button is pressed, move the weapon with the cursor
		copyWeapon->setLeftBottomCorner(glm::vec3(mouseX - square1Side, -mouseY + square1Side / 2, 1));
	}
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	Square* weaponSquare1 = weaponSquares[0];
	Square* weaponSquare2 = weaponSquares[1];
	Square* weaponSquare3 = weaponSquares[2];
	Square* weaponSquare4 = weaponSquares[3];
	// if left mouse is pressed, select weapon
	if (button == 1 && player->getStars() >= weapons[0]->getCost() && mouseX >= weaponSquare1->getLeftBottomCorner().x && mouseX <= weaponSquare1->getLeftBottomCorner().x + square1Side &&
		mouseY <= 720 - weaponSquare1->getLeftBottomCorner().y && mouseY >= 720 - weaponSquare1->getLeftBottomCorner().y - square1Side) {
		// if weapon 1 is selected move weapon 1 with the cursor
		isLeftMouseButtonPressed = true;
		copyWeapon = new Weapon("copyWeapon1", square1Side / 3, weaponSquare1->getLeftBottomCorner(), glm::vec3(1, 0.5, 0), true);
		copyWeapon->setCost(weapons[0]->getCost());
	}
	else if (button == 1 && player->getStars() >= weapons[1]->getCost() && mouseX >= weaponSquare2->getLeftBottomCorner().x && mouseX <= weaponSquare2->getLeftBottomCorner().x + square1Side &&
		mouseY <= 720 - weaponSquare2->getLeftBottomCorner().y && mouseY >= 720 - weaponSquare2->getLeftBottomCorner().y - square1Side) {
		// if weapon 2 is selected move weapon 2 with the cursor
		isLeftMouseButtonPressed = true;
		copyWeapon = new Weapon("copyWeapon2", square1Side / 3, weaponSquare2->getLeftBottomCorner(), glm::vec3(0, 0, 1), true);
		copyWeapon->setCost(weapons[1]->getCost());
	}
	else if (button == 1 && player->getStars() >= weapons[2]->getCost() && mouseX >= weaponSquare3->getLeftBottomCorner().x && mouseX <= weaponSquare3->getLeftBottomCorner().x + square1Side &&
		mouseY <= 720 - weaponSquare3->getLeftBottomCorner().y && mouseY >= 720 - weaponSquare3->getLeftBottomCorner().y - square1Side) {
		// if weapon 3 is selected move weapon 3 with the cursor
		isLeftMouseButtonPressed = true;
		copyWeapon = new Weapon("copyWeapon3", square1Side / 3, weaponSquare3->getLeftBottomCorner(), glm::vec3(1, 1, 0), true);
		copyWeapon->setCost(weapons[2]->getCost());
	}
	else if (button == 1 && player->getStars() >= weapons[3]->getCost() && 
		mouseX >= weaponSquare4->getLeftBottomCorner().x && mouseX <= weaponSquare4->getLeftBottomCorner().x + square1Side &&
		mouseY <= 720 - weaponSquare4->getLeftBottomCorner().y && mouseY >= 720 - weaponSquare4->getLeftBottomCorner().y - square1Side) {
		// if weapon 4 is selected move weapon 4 with the cursor
		isLeftMouseButtonPressed = true;
		copyWeapon = new Weapon("copyWeapon4", square1Side / 3, weaponSquare4->getLeftBottomCorner(), glm::vec3(0.4, 0, 0.8), true);
		copyWeapon->setCost(weapons[3]->getCost());
	}

	// if left mouse is pressed, select star point
	if (button == 1) {
		for (Bullet* starPoint : starPoints) {
			if (mouseX >= starPoint->getTranslateX() && mouseX <= starPoint->getTranslateX() + 2 * (starSide * 2) &&
				mouseY <= 720 - starPoint->getTranslateY() && mouseY >= 720 - starPoint->getTranslateY() - 2 * (starSide * 2)) {
				player->setStars(player->getStars() + 1);
				starPoints.erase(std::remove(starPoints.begin(), starPoints.end(), starPoint), starPoints.end());
				break;
			}
		}
	}


	// if right mouse is pressed delete weapon
	if (button == 2) {
		for (Square* square : squares) {
			if (square->isOccupied() && mouseX >= square->getLeftBottomCorner().x && mouseX <= square->getLeftBottomCorner().x + square1Side &&
				mouseY <= 720 - square->getLeftBottomCorner().y && mouseY >= 720 - square->getLeftBottomCorner().y - square1Side) {
				for (Weapon* weapon : placedWeapons) {
					if (weapon->getTranslateX() >= square->getLeftBottomCorner().x && weapon->getTranslateX()
						<= square->getLeftBottomCorner().x + square1Side && weapon->getTranslateY() >= square->getLeftBottomCorner().y
						&& weapon->getTranslateY() <= square->getLeftBottomCorner().y + square1Side) {
						weapon->setToDelete(true);
						break;
					}
				}
				break;
			}
		}
	}
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (button == 1) {
		isLeftMouseButtonPressed = false;
		// verify if copyWeapon is in a square
		for (Square* square1 : squares) {
			if (copyWeapon != NULL && copyWeapon->getPlaced() != true && !square1->isOccupied() && mouseX >= square1->getLeftBottomCorner().x && mouseX <= square1->getLeftBottomCorner().x + square1Side
				&& 720 - mouseY >= square1->getLeftBottomCorner().y && 720 - mouseY <= square1->getLeftBottomCorner().y + square1Side) {
				// place the weapon in the square
				Weapon* placedWeapon = new Weapon("placedWeapon", square1Side / 3, glm::vec3(0, 0, 1), copyWeapon->getColor(), true);
				placedWeapon->setSquare(square1);
				placedWeapon->setPlaced(true);
				placedWeapon->setTranslateX(square1->getLeftBottomCorner().x + square1Side / 3);
				placedWeapon->setTranslateY(square1->getLeftBottomCorner().y + square1Side / 2);
				placedWeapons.push_back(placedWeapon);

				square1->setOccupied(true);
				player->setStars(player->getStars() - copyWeapon->getCost());

				delete copyWeapon;
				copyWeapon = NULL;
				break;
			}
		}

		// if copyWeapon is not placed in a square delete it
		if (copyWeapon != NULL && !copyWeapon->getPlaced()) {
			delete copyWeapon;
			copyWeapon = NULL;
		}
	}
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}