# aquarium-butterflyfish

![main](https://github.com/pretore/aquarium-butterflyfish/actions/workflows/cmake.yml/badge.svg?branch=main)
[![codecov](https://codecov.io/gh/pretore/aquarium-butterflyfish/branch/main/graph/badge.svg?token=TMLCO47EMI)](https://codecov.io/gh/pretore/aquarium-butterflyfish)

Collection interfaces in C.

// set, list, deque, queue, stack, map

// _, unordered, ordered, swappable, sorted

```mermaid
flowchart LR
    A["_"] --> B[/"is item order significant?"/]
    B -->|yes| C[/"are items sorted?"/]
    B -->|no| D["unordered"]
    B -->|?| Z["_"]
    C -->|yes| E["sorted"]
    C -->|no| F[/"may you swap items?"/]
    F -->|yes| G["swappable"]
    F -->|no| H["ordered"]
```

// _, mutable, settable, incremental, reducible, settable_incremental, 
settable_reducible


```mermaid
flowchart LR
    A["_"] --> B[/"require mutable collection?"/]
    B -->|yes| C[/"mutable in a specific way?"/]
    C -->|count is constant| E["fixed"]
    C -->|count may increase| F["incremental"]
    C -->|count may reduce| G["reducible"]
    C -->|no| D["mutable"]
    B -->|no| H["_"]
```

| short code | description      |       data type        |
|:----------:|:-----------------|:----------------------:|
|     ni     | native integer   |     ``uintmax_t``      |
|     p      | pointer          |       ``void *``       |
|     i      | integer          | ``sea_turtle_integer`` |
|     s      | string           | ``sea_turtle_string``  |
|     r      | strong reference | ``triggerfish_strong`` |
|     w      | weak reference   |  ``triggerfish_weak``  |
