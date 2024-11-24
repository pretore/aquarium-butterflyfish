# aquarium-butterflyfish

![main](https://github.com/pretore/aquarium-butterflyfish/actions/workflows/cmake.yml/badge.svg?branch=main)
[![codecov](https://codecov.io/gh/pretore/aquarium-butterflyfish/branch/main/graph/badge.svg?token=TMLCO47EMI)](https://codecov.io/gh/pretore/aquarium-butterflyfish)

Collection interfaces in C.

// _, unordered, ordered, sorted

```mermaid
flowchart LR
    A["_"] --> B[/"is order significant?"/]
    B -->|yes| C[/"are they sorted?"/]
    B -->|no| D["unordered"]
    B -->|?| Z["_"]
    C -->|yes| E["sorted"]
    C -->|no| F["ordered"]
```

// _, mutable, settable, incremental, reducible, settable_incremental, 
settable_reducible

```mermaid
flowchart LR
    A["_"] --> B[/"require mutable collection?"/]
    B -->|yes| C[/"mutable in a specific way?"/]
    C -->|count may only increase| E["incremental"]
    C -->|count may only reduce| F["reducible"]
    C -->|count is constant| G["settable"]
    C -->|count is constant or may increase| H["settable_incremental"]
    C -->|count is constant or may reduce| I["settable_reducible"]
    C -->|no| D["mutable"]
    B -->|no| Z["_"]
```

| short code | description      |      data type       |
|:----------:|:-----------------|:--------------------:|
|     ni     | native integer   |     `uintmax_t`      |
|     p      | pointer          |       `void *`       |
|     i      | integer          | `sea_turtle_integer` |
|     s      | string           | `sea_turtle_string`  |
|     r      | strong reference | `triggerfish_strong` |
|     w      | weak reference   |  `triggerfish_weak`  |
