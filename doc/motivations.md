The motivation for this work is to provide an abstract way to implement E2 services and an interface to implement and control E2 connections for the E2 node.

The O-RAN Near-Real-Time RAN Controller Architecture & E2 General Aspects and Principlpes (O-RAN.WG3.E2GAP-v02.02) defines the following principles for E2 nodes.

- An E2 node is a node in the network that provides E2 services for the Near-RT RIC over an E2 interface.
- An E2 node is connected to only one Near-RT RIC. _(A single socket is necessary)_
- The protocols over the E2 interface are based only on Control Plane protocols. _(Must be able to select the interface)_
- The E2 node must be able to provide services on E2 and Near-RT RIC, but value-added services may suffer outages in this case. _(Failures to the E2 node must not stop the node from providing basic services)_
- The Near-RT RIC shall obtain from the E2 nodes a list of functions supporting RIC services and the correponding E2 service model. _(A function for listing the E2 services must exist. The Near-RT RIC must support multiple versions of the service models)_
- The E2 node must be able to function independently of the Near-RT RIC. _(The library is isolated, and may run in an isolated thread)_
- Services provided by the E2 Node:
	- REPORT
	- INSERT
	- CONTROL
	- POLICY



Other works.
- sd-ran has an e2simulator. Capabilities of this simulation is unknown at the time, but it seems to be monolythic. We aim at providing:
	- An infrastructure that can be used for simulation and production.
	- Simulators that can run independently.
	- Stochastic simulators in a first release, full programability later.
	- Not a full RAN simulator. This could be achieved by combining several simulators, and producinng a real RAN topology.
