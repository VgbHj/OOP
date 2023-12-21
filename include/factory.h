#include "npc.h"
#include "squirrel.h"
#include "druid.h"
#include "orc.h"
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
std::shared_ptr<NPC> Factory::create(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case SquirrelType:
            result = std::make_shared<Squirrel>(is);
            break;
        case DruidType:
            result = std::make_shared<Druid>(is);
            break;
        case OrcType:
            result = std::make_shared<Orc>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result)
        result->subscribe(TextObserver::get());

    return result;
}

std::shared_ptr<NPC> Factory::create(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case SquirrelType:
        result = std::make_shared<Squirrel>(x, y);
        break;
    case DruidType:
        result = std::make_shared<Druid>(x, y);
        break;
    case OrcType:
        result = std::make_shared<Orc>(x, y);
        break;
    default:
        break;
    }
    if (result)
        result->subscribe(TextObserver::get());

    return result;
}