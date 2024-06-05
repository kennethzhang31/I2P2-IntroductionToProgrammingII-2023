#ifndef SLOWGUNUPGRADE_HPP
#define SLOWGUNUPGRADE_HPP
#include "Turret.hpp"

class SlowGunUpgrade : public Turret {
public:
    static const int Price;
    SlowGunUpgrade(float x, float y);
    void CreateBullet() override;
};
#endif //SLOWGUNUPGRADE_HPP

