#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "Group.hpp"
#include "Shifter.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"

const int Shifter::Price = 0;
Shifter::Shifter(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/move.png", "play/whitemove.png", x, y, 100, Price, 2, 4) {
    Anchor.y += 4.0f / GetBitmapHeight();
}
void Shifter::CreateBullet() {
    return;
}
