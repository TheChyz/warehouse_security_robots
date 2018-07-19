CXX := g++

# Can add sources here
SRCS=graph/graph.cc graph/edge.cc graph/node.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: warehouse_security_robots chinese_test

warehouse_security_robots: $(OBJS)
	$(CXX) -o warehouse_security_robots warehouse_security_robots.cc $(OBJS)

chinese_test: $(OBJS)
	$(CXX) -o chinese_postman_test chinese_postman_test.cc $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f warehouse_security_robots
	rm -f chinese_postman_test

.PHONY : all clean
