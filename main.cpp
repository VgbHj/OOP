#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "black_knight.h"
#include <sstream>

#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

#include "observer.h"
#include "factory.h"
#include "fight.h"

using namespace std::chrono_literals;
std::mutex print_mutex;

// save array to file
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print();
    return os;
}

set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) &&
                attacker->is_close(defender, distance) &&
                defender->accept(attacker))
                dead_list.insert(defender);

    return dead_list;
}

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this->str();
        std::cout.flush();
    }
};

int main()
{
    set_t array; // монстры

    const int MAX_X{100};
    const int MAX_Y{100};
    const int DISTANCE{40};

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 50; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % MAX_X,
                             std::rand() % MAX_Y));

    std::cout << "Starting list:" << std::endl
              << array;

    std::thread fight_thread(std::ref(FightManager::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y, DISTANCE]()
                            {
            while (true)
            {
                // move phase
                for (std::shared_ptr<NPC> npc : array)
                {
                        if(npc->is_alive()){
                            int shift_x = std::rand() % 20 - 10;
                            int shift_y = std::rand() % 20 - 10;
                            npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                        }
                }
                // lets fight
                for (std::shared_ptr<NPC> npc : array)
                    for (std::shared_ptr<NPC> other : array)
                        if (other != npc)
                            if (npc->is_alive())
                            if (other->is_alive())
                            if (npc->is_close(other, DISTANCE))
                                FightManager::get().add_event({npc, other});

                std::this_thread::sleep_for(50ms);
            } });

    while (true)
    {
        const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        {
            std::array<char, grid * grid> fields{0};
            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc->position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc->is_alive())
                {
                    switch (npc->get_type())
                    {
                    case DragonType:
                        fields[i + grid * j] = 'D';
                        break;
                    case KnightType:
                        fields[i + grid * j] = 'K';
                        break;
                    case BlackKnightType:
                        fields[i + grid * j] = 'B';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '.';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    };

    move_thread.join();
    fight_thread.join();

    return 0;
}