#include "squirrel.h"
#include "druid.h"
#include "orc.h"

Squirrel::Squirrel(int x, int y) : NPC(SquirrelType, x, y) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

void Squirrel::print()
{
    std::cout << *this;
}

bool Squirrel::is_squirrel() const 
{
    return true;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) 
{
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Druid> other) 
{
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Orc> other) 
{
    fight_notify(other, false);
    return false;
}

void Squirrel::save(std::ostream &os) 
{
    os << SquirrelType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Squirrel &Squirrel)
{
    os << "Squirrel: " << *static_cast<NPC *>(&Squirrel) << std::endl;
    return os;
}