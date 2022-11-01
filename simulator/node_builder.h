#ifndef __e2node_simulator_constructor__
#define __e2node_simulator_constructor__
#include <value.h>
#include <string>
#include <list>
#include <yaml-cpp/yaml.h>


namespace E2NodeSimulator {
class E2NodeConstructor {
public:
	E2NodeConstructor(std::string filename);

	void getValues(std::list<E2Node::Value *>& values);
private:
	YAML::Node config;
}; /* class E2NodeContructor */

} /* namespace E2NodeSimulator */
#endif /* __e2node_simulator_constructor__ */
