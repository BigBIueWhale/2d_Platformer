
#ifndef ENEMY_H
#define ENEMY_H


#include <Entity.h>


class DumbChaser : public Entity
{
protected:
    int velocity;

public:
    Enemy();
    virtual void animate() override;
    virtual void move()=0;

};

#endif // ENEMY_H
