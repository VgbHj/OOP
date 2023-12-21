#include "squirrel.h"
#include "druid.h"
#include "orc.h"

Orc::Orc(int x, int y) : NPC(OrcType, x, y) {}
Orc::Orc(std::istream &is) : NPC(OrcType, is) {}

void Orc::print()
{
    std::cout << *this;
}

void Orc::save(std::ostream &os)
{
    os << OrcType << std::endl;
    NPC::save(os);
}

bool Orc::is_orc() const
{
    return true;
}

bool Orc::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, true);
    return true;
}

bool Orc::fight(std::shared_ptr<Druid> other)
{
    fight_notify(other, true);
    return true;
}

bool Orc::fight(std::shared_ptr<Orc> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, Orc &orc)
{
    os << "black knight: " << *static_cast<NPC *>(&orc) << std::endl;
    return os;
}