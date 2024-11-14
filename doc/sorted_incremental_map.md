## sorted_incremental_map

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
    class sorted {
        ceiling()
        floor()
        higher()
        lower()
    }
    <<interface>> sorted
    collection *-- sorted
    class addable {
        add()
        add_all()
    }
    <<interface>> addable
    collection *-- addable
    class set {
        contains()
        contains_all()
        get()
    }
    <<interface>> set
    collection *-- set
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
    class sorted_map {
        ceiling()
        floor()
        higher()
        lower()
        keys()
        values()
    }
    <<interface>> sorted_map
    sorted *-- sorted_map
    map *-- sorted_map
    class incremental_map {
        add_value()
        keys()
        values()
    }
    <<interface>> incremental_map
    map *-- incremental_map
    addable *-- incremental_map
    class sorted_incremental_map {
        keys()
        values()
    }
    <<interface>> sorted_incremental_map
    sorted_map *-- sorted_incremental_map
    incremental_map *-- sorted_incremental_map
```

[sorted_incremental_map](sorted_incremental_map.md) _is an_ [incremental_map](incremental_map.md) where the keys are sorted.
- [sorted_incremental_set](sorted_incremental_set.md) view of keys
- [sorted_list](sorted_list.md) view of values
