# ft_containers

Curriculum (42.fr) reimplementation of some STL containers (vector, map, stack, set and their iterators, const_iterators, reverse_iterators) [C++98]

A container is a holder object that stores a collection of other objects (its elements).
They are implemented as class templates, which allows a great flexibility in the types supported as elements.

The container manages the space to store its elements and provides member functions to access them either directly or through iterators.

Iterators are reference objects with properties similar to pointers. One professor defined iterators: "If something looks like an iterator, runs like an iterator, screams like an iterator, then it's an iterator." :))

Implemented the following containers:
- vector - continuous dynamic array;
- map - Red-black binary self-balancing search tree (Red-black tree) key-value pairs, sorted by unique keys;
- stack - adapter, adapts some types of containers to provide a stack (LIFO - Last In First Out);
- set - Red-black tree of sorted unique keys.

Used tests:

https://github.com/nenieiri-42Yerevan/42_Ft_containers_Crash_test
https://github.com/mli42/containers_test

Many thanks to the authors of the tests. The tests helped debug the code as it was being written. But they also helped to better understand the behavior of the objects under study. I realized for myself that having tests before starting work on a project is a good programming practice.

The study task contains the file docs/en.subject.pdf

Tips for this project:

- It is very convenient to use cppreference.com as a reference and work plan.

- Use tests at the stage of writing and debugging individual functions: copy the code of individual test cases into your main.cpp, comparing the output and operation of the corresponding STL container with your own.

- Before writing a project, take some C++ course or study a textbook with examples. For Russian-speaking students I recommend: youtube.com/@mesyarik.

- I started the project by writing a red-black tree using the algorithm: en.wikipedia.org/wiki/Red-black_tree. First, I wrote the code in C, debugged and studied the operation of the algorithm. Then I rewrote it in C++ as a separate RBTree class. After that, I started writing map and set and iterators for them.
