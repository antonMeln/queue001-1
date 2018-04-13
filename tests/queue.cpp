#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("push")
{
 queue_t<int> queue;
    queue.push(1);
    
    queue.push(2);
    queue.push(3);
}
