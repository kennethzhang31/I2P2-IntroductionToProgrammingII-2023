#ifndef CIRCLETURRET_HPP
#define CIRCLETURRET_HPP
#include "Turret.hpp"

class CircleTurret : public Turret {
public:
    static const int Price;
    CircleTurret(float x, float y);
    void CreateBullet() override;
    bool sfx;
};
#endif //SLOWGUNTURRET_HPP
