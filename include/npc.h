#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

// type for npcs
struct NPC;
struct Squirrel;
struct Druid;
struct Orc;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    SquirrelType = 1,
    DruidType = 2,
    OrcType = 3
};

struct IFightObserver{
    virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};

class Visitor{
    public:
        virtual int visit(const Squirrel &elem) const = 0;
        virtual int visit(const Druid &elem) const = 0;
        virtual int visit(const Orc &elem) const = 0;
};

class SuperVisitor : public Visitor{
    public:
        int visit(const Squirrel &elem) const override{
            return 0;
        }
        int visit(const Druid &elem) const override{
            return 1;
        }
        int visit(const Orc &elem) const override{
            return 2;
        }
};

struct NPC : public std::enable_shared_from_this<NPC>
{
    NpcType type;
    int x{0};
    int y{0};
    std::vector<std::shared_ptr<IFightObserver>> observers;

    NPC(NpcType t, int _x, int _y);
    NPC(NpcType t, std::istream &is);

    void subscribe(std::shared_ptr<IFightObserver>observer );
    void fight_notify(const std::shared_ptr<NPC> defender,bool win);
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    virtual int Accept(Visitor& visitor) const = 0;

    virtual bool is_squirrel() const;
    virtual bool is_druid() const;
    virtual bool is_orc() const ;

    virtual bool fight(std::shared_ptr<Squirrel> other) = 0;
    virtual bool fight(std::shared_ptr<Druid> other) = 0;
    virtual bool fight(std::shared_ptr<Orc> other) = 0;
    virtual void print() = 0;

    virtual void save(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};