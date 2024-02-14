#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateRectangle(
	const std::string &name,
	glm::vec3 leftBottomCorner,
	float length,
	float width,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(length, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, width, 0), color),
		VertexFormat(corner + glm::vec3(0, width, 0), color)
	};

	Mesh* rectangle = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 1, 2, 3 };

	if (!fill) {
		rectangle->SetDrawMode(GL_LINE_LOOP);
	} else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	rectangle->InitFromData(vertices, indices);
	return rectangle;
}

Mesh* object2D::CreateStar(
	const std::string& name,
	int length,
	glm::vec3 leftBottomCorner,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color), // 1
		VertexFormat(corner + glm::vec3(length, length / 2 + length/6, 0), color), // 2
		VertexFormat(corner + glm::vec3(2 * length, 0, 0), color), // 3
		VertexFormat(corner + glm::vec3(length / 2, length, 0), color), // 4
		VertexFormat(corner + glm::vec3(length + length / 2, length, 0), color), // 5
		VertexFormat(corner + glm::vec3(-(length/2), length + length / 2,0), color), // 6
		VertexFormat(corner + glm::vec3(2 * length + length / 2, length + length / 2, 0), color), // 7
		VertexFormat(corner + glm::vec3(length/2 + length/8, length + length / 2, 0), color), // 8
		VertexFormat(corner + glm::vec3(length + length/4 + length/6, length + length / 2, 0), color), // 9
		VertexFormat(corner + glm::vec3(length, 2 * length + length/2, 0), color), // 10
	};

	Mesh* star = new Mesh(name);
	std::vector<unsigned int> indices = { 0, 3, 5, 7, 9, 8, 6, 4, 2, 1};

	
	if (!fill) {
		star->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// clear indices
		indices.clear();

		indices = {
			0, 1, 3,
			3, 7, 5,
			9, 7, 4,
			4, 6, 8,
			1, 2, 4,
			3, 1, 4,
			8, 3, 4,
			3, 7, 4,
		};
	}

	star->InitFromData(vertices, indices);
	return star;
}

Mesh* object2D::CreateWeapon(
	const std::string& name,
	int length,
	glm::vec3 leftBottomCorner,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color), // 0
		VertexFormat(corner + glm::vec3(length / 2, length, 0), color), // 1
		VertexFormat(corner + glm::vec3(length, 0, 0), color), // 2
		VertexFormat(corner + glm::vec3(length / 2, -length, 0), color), // 3

		VertexFormat(corner + glm::vec3(length, length / 4, 0), color), // 4
		VertexFormat(corner + glm::vec3(length, -(length / 4), 0), color), // 5
		VertexFormat(corner + glm::vec3(2 * length, length / 4, 0), color), // 6
		VertexFormat(corner + glm::vec3(2 * length, -length / 4, 0), color), // 7

	};

	Mesh* diamond = new Mesh(name);
	std::vector<unsigned int> indices = {
		0, 1, 4, 6, 7, 5, 3
	};

	if (!fill) {
		diamond->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.clear();

		indices = {
			0, 1, 4,
			3, 0, 5,
			4, 5, 6,
			7, 6, 5,
			0, 4, 5
		};
	}

	diamond->InitFromData(vertices, indices);
	return diamond;
}

Mesh* object2D::CreateHex(
	const std::string& name,
	int length,
	glm::vec3 upperCenter,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = upperCenter;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color), // 0
		VertexFormat(corner + glm::vec3(length / 2, length, 1), color), // 1
		VertexFormat(corner + glm::vec3(length, 0, 1), color), // 2
		VertexFormat(corner + glm::vec3(length / 2, -length, 1), color), // 3
		VertexFormat(corner + glm::vec3(-length / 2, -length, 1), color), // 4
		VertexFormat(corner + glm::vec3(-length, 0, 1), color), // 5
		VertexFormat(corner + glm::vec3(-length / 2, length, 1), color), // 6
	};

	Mesh* hex = new Mesh(name);
	std::vector<unsigned int> indices = {
		1, 2, 3, 4, 5, 6
	};

	if (!fill) {
		hex->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.clear();
		indices = {
			0, 1, 6,
			0, 1, 2,
			0, 2, 3,
			0, 4, 3,
			0, 4, 5,
			0, 5, 6,
		};
	}

	hex->InitFromData(vertices, indices);
	return hex;
		
}

Mesh* object2D::CreateMiniHex(
	const std::string& name,
	int length,
	glm::vec3 upperCenter,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = upperCenter;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color), // 0
		VertexFormat(corner + glm::vec3(length / 2, length, 2), color), // 1
		VertexFormat(corner + glm::vec3(length, 0, 2), color), // 2
		VertexFormat(corner + glm::vec3(length / 2, -length, 2), color), // 3
		VertexFormat(corner + glm::vec3(-length / 2, -length, 2), color), // 4
		VertexFormat(corner + glm::vec3(-length, 0, 2), color), // 5
		VertexFormat(corner + glm::vec3(-length / 2, length, 2), color), // 6
	};

	Mesh* hex = new Mesh(name);
	std::vector<unsigned int> indices = {
		1, 2, 3, 4, 5, 6
	};

	if (!fill) {
		hex->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.clear();
		indices = {
			0, 1, 6,
			0, 1, 2,
			0, 2, 3,
			0, 4, 3,
			0, 4, 5,
			0, 5, 6,
		};
	}

	hex->InitFromData(vertices, indices);
	return hex;

}

Mesh* object2D::CreateCircle(
	const std::string& name,
	glm::vec3 center,
	float radius,
	glm::vec3 color,
	bool fill,
	int numSegments)
{
	std::vector<VertexFormat> vertices;
	std::vector<unsigned int> indices;

	for (int i = 0; i < numSegments; ++i) {
		float theta = 2 * glm::pi<float>() * static_cast<float>(i) / numSegments;
		glm::vec3 vertexPosition(center.x + radius * std::cos(theta), center.y + radius * std::sin(theta), 2);
		vertices.push_back(VertexFormat(vertexPosition, color));
		indices.push_back(i);
	}

	Mesh* circle = new Mesh(name);

	if (!fill) {
		circle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw triangles to fill the circle
		for (int i = 1; i < numSegments - 1; ++i) {
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
	}

	circle->InitFromData(vertices, indices);
	return circle;
}


Mesh* object2D::CreateHeart(
	const std::string& name,
	int length,
	glm::vec3 upperCenter,
	glm::vec3 color,
	bool fill)
{
	glm::vec3 corner = upperCenter;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color), // 0
		VertexFormat(corner + glm::vec3(length / 3, length / 3, 2), color), // 1
		VertexFormat(corner + glm::vec3(2 * length / 3, length / 3, 2), color), // 2
		VertexFormat(corner + glm::vec3(length, 0, 2), color), // 3
		VertexFormat(corner + glm::vec3(length , -length / 3, 2), color), // 4

		VertexFormat(corner + glm::vec3(0, -3 * length / 2, 2), color), // 5

		VertexFormat(corner + glm::vec3(-length, -length / 3, 2), color), // 6
		VertexFormat(corner + glm::vec3(-length, 0, 2), color), // 7
		VertexFormat(corner + glm::vec3(-2 * length / 3, length / 3, 2), color), // 8
		VertexFormat(corner + glm::vec3(-length / 3, length / 3, 2), color), // 9
	};

	Mesh* hex = new Mesh(name);
	std::vector<unsigned int> indices = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	if (!fill) {
		hex->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// Draw 2 triangles. Add the remaining 2 indices
		indices.clear();
		indices = {
			0, 1, 2,
			0, 2, 3,
			0, 3, 4,
			0, 4, 5,
			0, 5, 6,
			0, 6, 7,
			0, 7, 8,
			0, 8, 9,
		};
	}

	hex->InitFromData(vertices, indices);
	return hex;

}