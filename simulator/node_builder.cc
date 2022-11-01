#include "node_builder.h"
#include "sim_values.h"
#include <iostream>

namespace E2NodeSimulator {
E2NodeConstructor::E2NodeConstructor(std::string filename) :
	config(YAML::LoadFile(filename)) { }

void E2NodeConstructor::getValues(std::list<std::shared_ptr<E2Node::Value> >& values)
{
	std::string scalar;

	YAML::Node values_node = this->config["node"]["values"];

	for (YAML::Node::const_iterator node = values_node.begin();
			node != values_node.end(); node++) {
		std::string value_name = node->first.as<std::string>();
		YAML::Node value_conf = node->second;
		if (value_conf["uniform_distribution"]) {
			int range_start = value_conf["uniform_distribution"]["range_start"].as<int>();
			int range_end = value_conf["uniform_distribution"]["range_end"].as<int>();

			E2Node::Value *v = new RandomValue(value_name, range_start, range_end);
			values.push_back(std::shared_ptr<E2Node::Value>(v));
		}

		if (value_conf["normal_distribution"]) {
			double mean = value_conf["normal_distribution"]["mean"].as<double>();
			double standard_deviation = value_conf["normal_distribution"]["standard_deviation"].as<double>();

			E2Node::Value *v = new NormalValue(value_name, mean, standard_deviation);
			values.push_back(std::shared_ptr<E2Node::Value>(v));

		}

		if (value_conf["constant"]) {
			int value = value_conf["constant"]["value"].as<int>();
			E2Node::Value *v = new ConstantValue(value_name, value);
			values.push_back(std::shared_ptr<E2Node::Value>(v));
		}
	}
}


} /* namespace E2NodeSimulator */
