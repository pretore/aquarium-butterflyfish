## ordered_reducible_map

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
    class removable {
        remove_item()
        remove_all_items()
    }
    <<interface>> removable
    collection *-- removable
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
    ordered *-- ordered_map
    map *-- ordered_map
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
    class ordered_reducible_map {
        keys()
        values()
    }
    <<interface>> ordered_reducible_map
    ordered_map *-- ordered_reducible_map
    reducible_map *-- ordered_reducible_map
```

[ordered_reducible_map](ordered_reducible_map.md) _is a_ 
[reducible_map](reducible_map.md) where the item order is significant.
- [ordered_reducible_set](ordered_reducible_set.md) view of keys
- [ordered_reducible_list](ordered_reducible_list.md) view of values
