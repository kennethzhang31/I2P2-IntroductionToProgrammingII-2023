#ifndef CIRCLEBULLET_HPP
#define CIRCLEBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class CircleBullet : public Bullet {
public:
    Turret* parent;
    explicit CircleBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent, int id);
    void OnExplode(Enemy* enemy) override;

};
#endif // WOODBULLET_HPP


