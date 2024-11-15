## settable_incremental_map

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
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
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
        values()
    }
    <<interface>> incremental_map
    addable *-- incremental_map
    map *-- incremental_map
    class settable_map {
        set_entry()
        set_key()
        set_value()
        keys()
        values()
    }
    <<interface>> settable_map
    map *-- settable_map
    settable *-- settable_map
    class settable_incremental_map {
        keys()
        values()
    }
    <<interface>> settable_incremental_map
    incremental_map *-- settable_incremental_map
    settable_map *-- settable_incremental_map
```

[settable_incremental_map](settable_incremental_map.md) _is a_ [settable_map](settable_map.md)
where the entry count may be increased.
- [settable_incremental_set](settable_incremental_set.md) view of keys
- [ordered_settable_list](ordered_settable_list.md) view of values
