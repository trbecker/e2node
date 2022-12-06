# e2node

In the O-RAN ecosystem, e2nodes are nodes in the RAN that are equiped with the E2 protocol to communicate with the near-RT RIC. This project intends to develop a simulation tool for e2nodes capable of communicating with the RIC, and also a framework that can be integrated in different projects in the future.

The remainder of these documents is organized as follows. In this document, we highlight the intended goals of this project. In [[architecture.md]] we present the architectural details of the project.

# Simulation
Having a simulation tools allows us to test different management strategies for the RAN without having to deploy an actual RAN. The E2 simulator can be configured to imitate a behavior on the nodes without having to have the protocol stacks implemented. This provides a lightweight simulation that can be used to test the ner-RT RIC and SMO capabilities without having to rely on large infrastructures.

This also allows us to have scripted tests to verify protocol compliance of multiple ner-RT RICs.

# Framework
The framework can be integrated in different software projects. In the O-RAN documentation this is usually refered as an E2 Agent, which is understood to be a separate entity. With the possibility of having E2 nodes running on unikernel, virtualized and containerized environments, as well as bare metal, this may not always be separate from the protocol stacks. In this way, the framework is implemented as a set of headers and a library that can be integrated in the protocol stack or in a different program, which allows greater flexibility.
