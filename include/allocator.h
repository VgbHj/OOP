#pragma once

#include <vector>
#include <type_traits>

template<class T, int BLOCKS_COUNT = 100>
class Allocator
{
private:
    void *_allocatorMemory;
    std::vector<T *> _freeBlocks;
    size_t _freeCount;
public:
		using pointer = T *;
        using const_pointer = const T *;
        using void_pointer = void *;
        using const_void_pointer = const void *;

        using value_type = T;
        using reference_type = T &;
        using const_reference_type = const T &;

        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        template <typename U>
        struct rebind {
            using other = Allocator<U>;
        };

        Allocator() {
            _allocatorMemory = malloc(sizeof(T) * BLOCKS_COUNT);

            for (int i = 0; i < BLOCKS_COUNT; ++i) {
                _freeBlocks.push_back(
                    static_cast<T *>(_allocatorMemory + i * sizeof(T)));
            }

            _freeCount = BLOCKS_COUNT;
        }
        ~Allocator(){
            if (_freeCount < BLOCKS_COUNT) {
                std::cerr << "allocator: Memory leak"
                        "allocator's dectructor was called"
                        << std::endl;
            }

            free(_allocatorMemory);
        }

        T* allocate(size_t n) {
            T* result = nullptr;
            if (_freeCount > 0) {
                auto lastFree = --std::end(_freeBlocks);

                result = *lastFree;

                _freeBlocks.erase(lastFree);
                --freeCount;
            } else {
                throw std::bad_alloc();
            }

            return result;
        }

        void deallocate(T* p, size_T) noexcept {
            freeBlocks.push_back(p);
            ++freeCount;
        }

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args) {
            if (not(p >= allocatorMemory and
                    p < allocatorMemory + BLOCKS_COUNT * sizeof(T))) {
                throw std::invalid_argument(
                    "Allocator::construct error: given pointer must point on "
                    "allocator memory");
            }

            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p) { p->~T(); }
};
