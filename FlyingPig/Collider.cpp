#include "Collider.h"

Collider::Collider(sf::RectangleShape body) : body(body)
{
}

std::vector<sf::Vector2f> Collider::GetPoints()
{
    sf::Vector2f topLeft(body.getPosition());
    sf::Vector2f size(body.getSize());
    sf::Vector2f onlyX(size.x, 0.0f);
    sf::Vector2f onlyY(0.0f, size.y);
    std::vector<sf::Vector2f> points(4);
    points[1] = topLeft + size;
    points[0] = topLeft + onlyY;
    points[2] = topLeft + onlyX;
    points[3] = topLeft;
    
    
    

    return points;

}

float Collider::GetArea(const sf::Vector2f& A, const sf::Vector2f& B, const sf::Vector2f& C)
{
    return abs((B.x * C.y - C.x * B.y - A.x * C.y + C.x * A.y + A.x * B.y - B.x * A.y) / 2.0f);
}

bool Collider::pointIn(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon, const float polygonArea)
{
    int i, j;
    i = 0;
    j = 1;
    float area = 0.0f;
    while (i <= 3) {
        if (i == 3) {
            j = 0;
        }
        area += GetArea(point, polygon[i], polygon[j]);
        i++;
        j++;
    }

    ///std::cout << area << " " << polygonArea << "\n";
    if (area == polygonArea) {
        return true;
    }

    return false;
    
}

bool Collider::checkCollision(Collider& other)
{
    std::vector<sf::Vector2f> points = this->GetPoints();
    std::vector<sf::Vector2f> otherPoints = other.GetPoints();
    float pointsArea = this->body.getSize().x * this->body.getSize().y;
    float otherPointsArea = other.body.getSize().x * other.body.getSize().y;
    int i = 0;
    
    while (i <= 3) {
        if (pointIn(points[i], otherPoints,otherPointsArea)) {
            return true;
        }
        i++;
    }

    i = 0;

    while (i <= 3) {
        if (pointIn(otherPoints[i], points, pointsArea)) {
            return true;
        }
        i++;
    }

    return false;
}




