#include "npc.h"
#include "knight.h"
#include "black_knight.h"
#include "dragon.h"
#include "observer.h"

class Factory
{
public:
    Factory();
    ~Factory();
    std::shared_ptr<NPC> create(std::istream &is);
    std::shared_ptr<NPC> create(NpcType type, int x, int y);
};


// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case DragonType:
            result = std::make_shared<Dragon>(is);
            break;
        case KnightType:
            result = std::make_shared<Knight>(is);
            break;
        case BlackKnightType:
            result = std::make_shared<BlackKnight>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case DragonType:
        result = std::make_shared<Dragon>(x, y);
        break;
    case KnightType:
        result = std::make_shared<Knight>(x, y);
        break;
    case BlackKnightType:
        result = std::make_shared<BlackKnight>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}