# aquarium-butterflyfish

Collection interfaces in C.

- butterflyfish\_[stream](doc/Streams.md)\__x_
  - butterflyfish\_[collection](doc/Collections.md)\__x_
    - butterflyfish\_[fixed_list](doc/FixedLists.md)\__x_
      - butterflyfish\_[reducible_list](doc/ReducibleLists.md)\__x_
        - butterflyfish\_[list](doc/Lists.md)\__x_
    - butterflyfish\_[set](doc/Sets.md)\__x_
      - butterflyfish\_[ordered_set](doc/OrderedSets.md)\__x_
        - butterflyfish\_[sorted_set](doc/SortedSets.md)\__x_
        
- butterflyfish\_[stream](doc/Streams.md)\__x\_y_
  - butterflyfish\_[collection](doc/Collections.md)\__x\_y_
    - butterflyfish\_[map](doc/Maps.md)\__x\_y_
      - butterflyfish\_[ordered_map](doc/OrderedMaps.md)\__x\_y_
        - butterflyfish\_[sorted_map](doc/SortedMaps.md)\__x\_y_

Where _x_ and _y_ is one of:

| short code | description       |          data type          |
|:----------:|:------------------|:---------------------------:|
|     ni     | native integer    |        ``uintmax_t``        |
|     p      | pointer           |          ``void*``          |
|     i      | integer           |   ``sea_turtle_integer``    |
|     s      | string            |    ``sea_turtle_string``    |
|     sr     | strong reference  |   ``triggerfish_strong``    |
|     wr     | weak reference    |    ``triggerfish_weak``     |
