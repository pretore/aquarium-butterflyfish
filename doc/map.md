## map

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
```

[map](map.md) _is a_ [set](set.md) where values are looked up by unique key.
- contains key
- contains value
- get value for key
- get entry for key
- [set](set.md) view of keys
- [ordered_list](ordered_list.md) view of values
