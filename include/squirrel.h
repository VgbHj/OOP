#pragma once
#include "npc.h"

struct Squirrel : public NPC
{
    Squirrel(int x, int y);
    Squirrel(std::istream &is);

    void print() override;


    virtual void Accept(Visitor *visitor) const override
    {
        visitor->VisitDruid(this);
    }

    bool is_squirrel() const override;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Orc> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Squirrel &Squirrel);
};