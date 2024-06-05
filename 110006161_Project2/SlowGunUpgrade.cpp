#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowGunBullet.hpp"
#include "Group.hpp"
#include "SlowGunUpgrade.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"

const int SlowGunUpgrade::Price = 55;
SlowGunUpgrade::SlowGunUpgrade(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 350, Price, 2, 5) {
    Anchor.y += 8.0f / GetBitmapHeight();
}
void SlowGunUpgrade::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point nml = diff.Normalize();
    // Calculate the ppd direction to create side-by-side bullets.
    Engine::Point ppd = Engine::Point(-diff.y, diff.x);
    // Calculate the positions for the side-by-side bullets.
    Engine::Point fpos = Position + ppd * 6;
    Engine::Point spos = Position - ppd * 6;
    getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(fpos, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new SlowBullet(spos, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect2((Position + nml * 50).x, (Position + nml * 50).y));
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect2((Position + nml * 50).x, (Position + nml * 50).y));
}
