## incremental_map

```mermaid
classDiagram
    direction LR
    class stream {
        first()
        next()
    }
    <<interface>> stream
    class collection {
        count()
        last()
        prev()
    }
    <<interface>> collection
    stream *-- collection
    class set {
        contains()
        get()
    }
    <<interface>> set
    collection *-- set
    class addable {
        add()
    }
    <<interface>> addable
    collection *-- addable
    class map {
        contains_key()
        contains_value()
        get()
        get_entry()
        keys()
        values()
    }
    <<interface>> map
    set *-- map
    class incremental_map {
        add()
        keys()
        values()
    }
    <<interface>> incremental_map
    map *-- incremental_map
    addable *-- incremental_map
```

[incremental_map](incremental_set.md) _is a_ [map](map.md) where the entry count may be increased.
- add value for key
- [incremental_set](incremental_set.md) view of keys
- [list](list.md) view of values
