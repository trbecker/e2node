#ifndef __e2node_simulator_constructor__
#define __e2node_simulator_constructor__
#include <e2node/value.h>
#include <string>
#include <list>
#include <memory>
#include <yaml-cpp/yaml.h>

namespace e2simulator {
class E2NodeConstructor {
public:
	E2NodeConstructor(std::string filename);

	void getValues(std::list<std::shared_ptr<e2node::Value> >& values);
private:
	YAML::Node config;
}; /* class E2NodeContructor */

} /* namespace e2simulator */
#endif /* __e2node_simulator_constructor__ */
