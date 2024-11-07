## sorted_incremental_set

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
    class addable {
        add()
        add_all()
    }
    <<interface>> addable
    collection *-- addable
    class incremental_set
    <<interface>> incremental_set
    set *-- incremental_set
    addable *-- incremental_set
    class sorted_incremental_set
    <<interface>> sorted_incremental_set
    sorted_set *-- sorted_incremental_set
    incremental_set *-- sorted_incremental_set
```

[sorted_incremental_set](sorted_incremental_set.md) _is an_ [incremental_set](incremental_set.md) where the items are sorted.
