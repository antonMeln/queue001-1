#include <catch.hpp>
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
 int tmp = queue.pop();
 REQUIRE (tmp == 1);
 tmp = queue.pop();
 REQUIRE (tmp == 2);
 tmp = queue.pop();
 REQUIRE (tmp == 3);
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

