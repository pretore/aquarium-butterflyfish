## sorted_settable_reducible_map

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
    class sorted_map {
        ceiling()
        floor()
        higher()
        lower()
        keys()
        values()
    }
    <<interface>> sorted_map
    map *-- sorted_map
    sorted *-- sorted_map
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
    class sorted_settable_map {
        keys()
        values()
    }
    <<interface>> sorted_settable_map
    settable_map *-- sorted_settable_map
    sorted_map *-- sorted_settable_map
    class settable_reducible_map {
        keys()
        values()
    }
    <<interface>> settable_reducible_map
    settable_map *-- settable_reducible_map
    reducible_map *-- settable_reducible_map
    class sorted_reducible_map {
        keys()
        values()
    }
    <<interface>> sorted_reducible_map
    sorted_map *-- sorted_reducible_map
    reducible_map *-- sorted_reducible_map
    class sorted_settable_reducible_map {
        keys()
        values()
    }
    <<interface>> sorted_settable_reducible_map
    sorted_settable_map *-- sorted_settable_reducible_map
    settable_reducible_map *-- sorted_settable_reducible_map
    sorted_reducible_map *-- sorted_settable_reducible_map
```

[sorted_settable_reducible_map](sorted_settable_reducible_map.md) _is a_ 
[settable_reducible_map](settable_reducible_map.md) where the keys are sorted.
- [sorted_settable_reducible_set](sorted_settable_reducible_set.md) view of keys
- [ordered_settable_reducible_list](ordered_settable_reducible_list.md) view of values
