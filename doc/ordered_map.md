## ordered_map

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
```

[ordered_map](ordered_map.md) _is a_ [map](map.md) where the entry order is significant.
- [ordered_set](set.md) view of keys
- [ordered_list](list.md) view of values
