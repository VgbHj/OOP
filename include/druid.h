#pragma once
#include "npc.h"

struct Druid : public NPC
{
    Druid(int x, int y);
    Druid(std::istream &is);
    void print() override;
    void save(std::ostream &os) override;


    virtual int Accept(Visitor& visitor) const override
    {
        return visitor.visit(*this);
    }

    bool is_druid() const override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<Druid> other) override;
    bool fight(std::shared_ptr<Orc> other) override;
    friend std::ostream &operator<<(std::ostream &os, Druid &druid);
};