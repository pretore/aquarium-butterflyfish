## settable_reducible_map

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
    class removable {
        remove_item()
    }
    <<interface>> removable
    collection *-- removable
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
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
    class reducible_map {
        remove()
        keys()
        values()
    }
    <<interface>> reducible_map
    removable *-- reducible_map
    map *-- reducible_map
    class settable_map {
        set_key()
        set_value()
        set_entry()
        keys()
        values()
    }
    <<interface>> settable_map
    map *-- settable_map
    settable *-- settable_map
    class settable_reducible_map {
        keys()
        values()
    }
    <<interface>> settable_reducible_map
    reducible_map *-- settable_reducible_map
    settable_map *-- settable_reducible_map
```

[settable_reducible_map](settable_reducible_map.md) _is a_ [settable_map](settable_map.md) 
where the entry count may be reduced.
- [settable_reducible_set](settable_set.md) view of keys
- [ordered_settable_reducible_list](ordered_settable_list.md) view of values
