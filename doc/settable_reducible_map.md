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
        contains_all()
        get()
    }
    <<interface>> set
    collection *-- set
    class removable {
        remove_item()
        remove_all_items()
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
    class reducible_map {
        remove()
        remove_all()
        retain_all()
        remove_entry()
        remove_all_entries()
        keys()
        values()
    }
    <<interface>> reducible_map
    removable *-- reducible_map
    map *-- reducible_map
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
- [settable_reducible_list](settable_list.md) view of values
