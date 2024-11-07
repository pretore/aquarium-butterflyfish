## ordered_incremental_map

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
    class ordered
    <<interface>> ordered
    collection *-- ordered
    class set {
        contains()
        contains_all()
        get()
    }
    <<interface>> set
    collection *-- set
    class addable {
        add()
        add_all()      
    }
    <<interface>> addable
    collection *-- addable
    class map {
        contains_key()
        contains_all_keys()
        contains_value()
        contains_all_values()
        get_value()
        get_entry()
        keys()
        values()
    }
    <<interface>> map
    set *-- map
    class incremental_map {
        add_value()
        keys()
    }
    <<interface>> incremental_map
    map *-- incremental_map
    addable *-- incremental_map
    class ordered_map {
        keys()
        values()
    }
    <<interface>> ordered_map
    ordered *-- ordered_map
    map *-- ordered_map
    class ordered_incremental_map {
        keys()
        values()
    }
    <<interface>> ordered_incremental_map
    ordered_map *-- ordered_incremental_map
    incremental_map *-- ordered_incremental_map
```

[ordered_incremental_map](ordered_incremental_map.md) _is an_ [incremental_map](incremental_map.md) where the entry order is significant.
- [ordered_incremental_set](ordered_incremental_set.md) view of keys
- [ordered_list](ordered_list.md) view of values
