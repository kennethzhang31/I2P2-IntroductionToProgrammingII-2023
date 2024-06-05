#ifndef TURRET_HPP
#define TURRET_HPP
#include <allegro5/base.h>
#include <list>
#include <string>
#include "Bullet.hpp"
#include "Sprite.hpp"

class Enemy;
class PlayScene;
class Bullet;
class Turret: public Engine::Sprite {
protected:
    int price;
    int id;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgBase;
    std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;

public:
    bool Enabled = true;
    bool Preview = false;
    int flag = 0;

    Enemy* Target = nullptr;
    Turret(std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown, int id);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice() const;
    int GetId() const;
    void DeleteTurret();
};
#endif // TURRET_HPP
