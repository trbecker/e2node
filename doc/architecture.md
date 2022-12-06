# e2node Architecture

The architecture of e2node has the following objectives:
- provide an abstraction for the E2 application protocol and for E2 service models, with a stable and well known interface
- provide anciliary interfaces to provide services, like timers and sctp protocol management
- be able to be compiled with only the c++ standard library to allow for porting to embedded devices
- provide a framework for e2node operation as a library

## Details
The following requirements are listed from the documentation.

### Service listing
The E2 Node is connected to a single near-RT RIC, and should provide a list of RIC services and the service models implemented it can handle ([1], section 4.3).

### Service independence from the e2node
The E2 Node should be able to work independetly of the RIC in case it fails. This mostly indicates that other services should work without value-added services from the RIC in case the RIC fails. This can be done by running e2node as a separate thread of execution. The RIC may request control over functions in the E2 Node, which in case of failure in the RIC or E2 Interface, need to be released to work. The documentation doesn't clarify what is considered a failure, but most detectable failures in the RIC are detected by a failure in the communication, which should happen between 10 ms and 1 second ([1], section 4.3). The following state machine applies.
![[e2interface_send_timeout_state_machine.png]]
### Triggers and events
The E2 Node needs to send information to the RIC based on triggers, either time based or event based (_this distinction seems more of a clarification_). These events may halt the continuation of an flow in the component until a corresponding message from the RIC is sent back. For instance, the E2 INSERT procedure waits for a E2 CONTROL message from the RIC.
![[E2_INSERT.png]]

Time events and system events can be handled by the same subsystem, with time being just another type of event. Initially, I choose to have time events to be based on the timerfd_create system call in linux. This may be insufficient, dependending on what can be handled by the poll family of system calls, so an abstraction of the eventing system needs to be created to handle this. I'm thinking about using a Reactor Pattern with multiple event handling threads.

### Policies
Policies are similar to triggers, which the difference that the action to be taken is predefined. This means that the RIC will not be involved in decision making, but can be notified of the change.
I believe that this can be implemented with the same infrastucture hadling events that communicate with the RIC, with the event handler reflecting the chage to the process.