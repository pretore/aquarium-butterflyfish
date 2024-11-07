## sorted_reducible_set

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
    class sorted_set
    <<interface>> sorted_set
    sorted *-- sorted_set
    set *-- sorted_set
    class removable {
        remove_item()
        remove_all_items()
    }
    <<interface>> removable
    collection *-- removable
    class reducible_set {
        remove()
        remove_all()
        retain_all()
    }
    <<interface>> reducible_set
    set *-- reducible_set
    removable *-- reducible_set
    class sorted_reducible_set
    <<interface>> sorted_reducible_set
    sorted_set *-- sorted_reducible_set
    reducible_set *-- sorted_reducible_set
```

[sorted_reducible_set](sorted_reducible_set.md) _is a_ [reducible_set](reducible_set.md) 
where the items are sorted.
