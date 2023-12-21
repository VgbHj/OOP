#pragma once
#include "npc.h"

struct Orc : public NPC
{
    Orc(int x, int y);
    Orc(std::istream &is);

    void print() override;
    void save(std::ostream &os) override;


    virtual int Accept(Visitor& visitor) const override
    {
        return visitor.visit(*this);
    }

    bool is_orc() const override;

    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    friend std::ostream &operator<<(std::ostream &os, Orc &orc);
};