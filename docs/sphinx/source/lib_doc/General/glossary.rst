Glossary Terms
##############

**(To be revised and expanded)**

.. glossary::

Centralized Federated Network
  In our context, a (trusted) coordinator receives the messages sent by different agents, and make the final computation.

Contract

Decentralized Federated Network
  In our context, an agent sends its message to all the other agents connected to the server.
  Each agent makes the final computation on its own device, once all messages have been exchanged.
  The server is only present as a supporting infrastructure in order to send/receive messages.

Distributed Communication Module

Federated Learning (also known as: Collaborative Learning)
  Technique that allows the training of a machine learning algorithm
  on multiple devices holding local data, without having to share those or centralized them.

Honest user
  User following all protocols.

Honest-but-curious user
  User following all protocols - but nonetheless curious about potential leakages of data from other users.

Malicious user
  User disregarding protocols, potentially actively looking for data leakages and/or data poisoning.

Shuffler
  Anonymization technique for data.

Simulated Communication Module

Untrusted Server
  Server used for communication protocols that could have been compromised by malicious users or not.

Zero-Knowledge Proofs (ZKPs)
  Cryptographic protocols between several users (at least two)
  that can be used to prove statement on data's properties
  without having to revealing anything on the data itself.