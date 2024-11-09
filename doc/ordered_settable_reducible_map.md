## ordered_settable_reducible_map

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
    class settable {
        set_item()
    }
    <<interface>> settable
    collection *-- settable
    class removable {
        remove_item()
        remove_all_items()
    }
    <<interface>> removable
    collection *-- removable
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
    class ordered_map {
        keys()
        values()
    }
    <<interface>> ordered_map
    map *-- ordered_map
    ordered *-- ordered_map
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
    map *-- reducible_map
    removable *-- reducible_map
    class settable_map {
        set_entry()
        set_key()
        set_value()
        keys()
        values()
    }
    <<interface>> settable_map
    settable *-- settable_map
    map *-- settable_map
    class ordered_settable_map {
        keys()
        values()
    }
    <<interface>> ordered_settable_map
    settable_map *-- ordered_settable_map
    ordered_map *-- ordered_settable_map
    class settable_reducible_map {
        keys()
        values()
    }
    <<interface>> settable_reducible_map
    settable_map *-- settable_reducible_map
    reducible_map *-- settable_reducible_map
    class ordered_reducible_map {
        keys()
        values()
    }
    <<interface>> ordered_reducible_map
    ordered_map *-- ordered_reducible_map
    reducible_map *-- ordered_reducible_map
    class ordered_settable_reducible_map {
        keys()
        values()
    }
    <<interface>> ordered_settable_reducible_map
    ordered_settable_map *-- ordered_settable_reducible_map
    settable_reducible_map *-- ordered_settable_reducible_map
    ordered_reducible_map *-- ordered_settable_reducible_map
```

[ordered_settable_reducible_map](ordered_settable_reducible_map.md) _is an_ 
[settable_reducible_map](settable_reducible_map.md) where the entry order is significant.
- [ordered_settable_reducible_set](ordered_settable_reducible_set.md) view of keys
- [ordered_settable_reducible_list](ordered_settable_reducible_list.md) view of values
