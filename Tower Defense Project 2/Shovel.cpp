#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "SlowGunBullet.hpp"
#include "Group.hpp"
#include "Shovel.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/bshovel.png", "play/shovel.png", x, y, 200, Price, 2, 3) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Shovel::CreateBullet() {
    return;
}
