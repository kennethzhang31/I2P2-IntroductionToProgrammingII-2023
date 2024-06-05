#ifndef BULLET_HPP
#define BULLET_HPP
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;
class Turret;
namespace Engine {
struct Point;
}

class Bullet : public Engine::Sprite {
protected:
	float speed;
	float damage;
	float maxdamage;
	Turret* parent;
	PlayScene* getPlayScene();
	virtual void OnExplode(Enemy* enemy);
public:
	Enemy* Target = nullptr;
	void rage();
	explicit Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
	void Update(float deltaTime) override;
};
#endif // BULLET_HPP
