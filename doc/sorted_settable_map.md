## sorted_settable_map

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
    class sorted_settable_map {
        keys()
        values()
    }
    <<interface>> sorted_settable_map
    sorted_map *-- sorted_settable_map
    settable_map *-- sorted_settable_map
```

[sorted_settable_map](sorted_settable_map.md) _is a_ [settable_map](settable_map.md) where the keys are sorted.
- [sorted_settable_set](sorted_settable_set.md) view of keys
- [ordered_settable_list](ordered_settable_list.md) view of values
