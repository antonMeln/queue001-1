#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("push")
{
 queue_t<int> queue;
 queue.push(1);
 REQUIRE( queue.hvalue() == 1);
 REQUIRE( queue.tvalue() == 1);
 queue.push(2);
 REQUIRE( queue.hvalue() == 1);
 REQUIRE( queue.tvalue() == 2);
 queue.push(3);
 REQUIRE( queue.hvalue() == 1);
 REQUIRE( queue.tvalue() == 3);
}

TEST_CASE("pop")
{
 queue_t<int> queue;
 queue.push(1);
 queue.push(2);
 queue.push(3);
 REQUIRE (1 == queue.pop());
 REQUIRE (2 == queue.pop());
 REQUIRE (3 == queue.pop());
 REQUIRE_THROWS(queue.pop());
}

TEST_CASE("copy")
{
 queue_t<int> queue1;
 queue1.push(1);
 queue1.push(2);
 queue1.push(3);
 
 queue_t<int> queue2(queue1);
 REQUIRE( queue.hvalue() == 1);
 REQUIRE( queue.tvalue() == 3);
 
}

