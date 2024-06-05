#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowGunBullet.hpp"
#include "Group.hpp"
#include "CircleTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"

const int CircleTurret::Price = 55;
CircleTurret::CircleTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/CircleTurret.png", x, y, 350, Price, 2, 3) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    sfx = false;
}
void CircleTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    Engine::Point pos, pos2;
    pos.x = Position.x + CollisionRadius * cos(0.0152481);
    pos.y = Position.y + CollisionRadius * sin(0.0152481);
    pos2.x = Position.x - pos.x + Position.x;
    pos2.y = Position.y;

    Bullet* bullet = new CircleBullet(Position + normalized * 36, diff, rotation, this, 0);
    arr[0] = bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet = new CircleBullet(Position + normalized * 36, diff, rotation, this, 1);
    bullet->angle = ALLEGRO_PI;
    arr[1] = bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet = new CircleBullet(Position + normalized * 36, diff, rotation, this, 2);
    bullet->angle = ALLEGRO_PI / 2;
    arr[2] = bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);
    bullet = new CircleBullet(Position + normalized * 36, diff, rotation, this, 3);
    bullet->angle = 3 * (ALLEGRO_PI / 2);
    arr[3] = bullet;
    getPlayScene()->BulletGroup->AddNewObject(bullet);

    getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect2((Position + normalized * 50).x, (Position + normalized * 50).y));
}
