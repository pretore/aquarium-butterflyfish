## reducible_map

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
    map *-- reducible_map
    removable *-- reducible_map
```

[reducible_map](reducible_map.md) _is a_ [map](map.md) where the entry count may be reduced.
- remove
- [reducible_set](reducible_set.md) view of keys
- [ordered_reducible_list](ordered_reducible_list.md) view of values
