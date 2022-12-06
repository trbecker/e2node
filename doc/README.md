# e2node

In the O-RAN ecosystem, e2nodes are nodes in the RAN that are equiped with the E2 protocol to communicate with the near-RT RIC. This project intends to develop a simulation tool for e2nodes capable of communicating with the RIC, and also a framework that can be integrated in different projects in the future.

The remainder of these documents is organized as follows. In this document, we highlight the intended goals of this project and motivations, and the current implementation status. In [architecture](architecture.md) we present a high level architecture of the system.

# Motivations
While evaluating the selection of tools to emulate the O-RAN architecture, we find very few implementations, usually specialized in a single specification; for instance, [e2sim](https://gerrit.o-ran-sc.org/r/admin/repos/sim/e2-interface) has implementations for the KPM and RC specifications, and is complex to use. Besides, looking for real implementations of the E2 interface shows that current implementations are insipient, and require the entire user plane protocol stack. All of these have no default way of injecting faults in the RAN, or testing for protocol compliance.

Simulations, on the other hand, are a bit more advanced. I would like to point out [sim-ns3-o-ran-e2](https://github.com/o-ran-sc/sim-ns3-o-ran-e2), which simulate the RAN with ns3, and provides E2 interfaces for the RIC. This project is very recent, therefore, it is not covered in this document. It's unclear if this project can help in testing orchestration algorithms.

On the hardware side, I see several small factor hardware (similar to, and more powerful than, the Raspberry PI) that can be used in Distributed Units, and certain small distributed units may even be implemented in less powerful platforms, like an ARM Cortex with a small network fabric chip for the userplane (this may be used in small indoor cells and remote rural cells).

# Goals
With this project, I intent to cover the following gaps:
- Create a framework that allows the implementation of the E2 interface on multiple projects.
- Provide a stable interface for plugging new E2 Service models.
- (Tentative) Be capable of porting these libraries to different devices, including low power platforms; in terms of software, this library needs to be small and efficient.
- Provide a simulator capable of fault injection, to test the RIC implementation resiliency to failure.
- Use this tool as a way to test the compliance of RIC implementations to the E2 specifications.

# Implementation Status and Next Steps
Currently, parts of the framework are implemented as proofs of concept. The implementation is separated in framework (`src`), simulator (`simulator`). All of the implementation is tested with unit tests using [googletest and googlemock](https://github.com/google/googletest). The tests also verify code coverage of the tests, and possible memory leaks during the tests. This guarantees a higher level of code quality.

## Next steps
- This project is a candidate for part of my masters thesis. I need to understand the competing projects, and depending on the features presented, I'll may choose to scrap this idea and use another implementation modified for the needs of my thesis.
- If the decision is to go ahead with the implementation of this project, then I plan the following next steps.
  - Detail the architecture. The compoenets need to have their interations detailed, and the [E2AP protocol](https://orandownloadsweb.azurewebsites.net/download?id=326) and [General Aspects and Principles](https://orandownloadsweb.azurewebsites.net/download?id=262) needs to be fully understood.
  - Define what is being tested.
  - Implement this architecture, reusing the prrofs of concept whereever possible.
  - Implement the KPM Service Model. This requires a review of the [KPM Service Model](https://orandownloadsweb.azurewebsites.net/download?id=324).
  - Implement the tests.

Im specially interested in the ns-3 implementation above mentioned; the question I have is if we can use it to test an self-organization framework. This would require having the ability to distribute the ns-3 across multiple containers that I can move and reconfigure whenever needed for this testing.
