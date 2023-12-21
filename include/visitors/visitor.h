#include "squirrel.h"
#include "druid.h"
#include "orc.h"

class Visitor{
    public:
        virtual void VisitSquirrel(const Squirrel *elem) const = 0;
        virtual void VisitDruid(const Druid *elem) const = 0;
        virtual void VisitOrc(const Orc *elem) const = 0;
};