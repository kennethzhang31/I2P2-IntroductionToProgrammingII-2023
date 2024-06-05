#ifndef SLOWGUNTURRET_HPP
#define SLOWGUNTURRET_HPP
#include "Turret.hpp"

class SlowGunTurret : public Turret {
public:
    static const int Price;
    SlowGunTurret(float x, float y);
    void CreateBullet() override;
};
#endif //SLOWGUNTURRET_HPP
